#include "CorsairRollList.h"

using namespace player_job;

CorsairRollList::CorsairRollList(player::InteractionManager& interactionManager)
    : mInteractionManager(interactionManager)
    , mList()
    , mCurrent(mList.end())
    , mRefreshRunning(false)
    , mDoAll(false)
    , mDoubleUp(shared::AbilityId::DoubleUp, interactionManager)
    , mSnakeEye(shared::AbilityId::SnakeEye, interactionManager)
    , mCrookedCards(shared::AbilityId::CrookedCards, interactionManager)
    , mPendingRoll(false)
    , mUseSnakeEye(false)
    , mUseDoubleUp(false)
{}

CorsairRollList::~CorsairRollList()
{
    for (auto it : mList)
    {
        delete it;
    }
}

bool CorsairRollList::isRefreshRunning() const
{
    return mRefreshRunning;
}

bool CorsairRollList::add(const shared::AbilityId id)
{
    if (mList.size() >= MaxRolls)
    {
        return false;
    }

    mList.push_back(new CorsairRoll(id, mInteractionManager));
    mCurrent = mList.begin();

    return true;
}

bool CorsairRollList::set(const size_t index, const shared::AbilityId id)
{
    if (index >= mList.size())
    {
        return false;
    }

    delete mList[index];
    mList[index] = new CorsairRoll(id, mInteractionManager);

    return true;
}

void CorsairRollList::setRoll(const shared::Ability ability, const uint64_t roll)
{
    for (auto current : mList)
    {
        if (current->getAbility() == ability)
        {
            mPendingRoll = false;
            mUseDoubleUp = false;
            mUseSnakeEye = false;

            current->setRoll(roll);

            std::string message = current->getName() + " #" + std::to_string(roll);
            message += (current->isLucky() ? " (Lucky)" : current->isUnlucky() ? " (Unlucky)"
                                                                               : "");
            mInteractionManager.printMessage(message);

            if (!isRefreshRunning())
            {
                return;
            }

            if (current->isLucky())
            {
                mUseDoubleUp = false;
                mUseSnakeEye = false;
            }
            else if (roll <= 5u)
            {
                mUseDoubleUp = true;
            }
            else if ((roll == 10u) || (current->isUnlucky()))
            {
                mUseSnakeEye = mSnakeEye.isReady();
                mUseDoubleUp = mUseSnakeEye;
            }
        }
    }
}

void CorsairRollList::startRefresh()
{
    if (mList.empty())
    {
        return;
    }

    mDoAll          = true;
    mRefreshRunning = true;
    mCurrent        = mList.begin();
    mPendingRoll    = false;
}

void CorsairRollList::stopRefresh()
{
    mRefreshRunning = false;
}

void CorsairRollList::refreshNext()
{
    if (mList.empty())
    {
        return;
    }

    mDoAll          = false;
    mRefreshRunning = true;
    mPendingRoll    = false;
}

void CorsairRollList::doRefresh()
{
    if (!isRefreshRunning())
    {
        return;
    }

    if (mInteractionManager.queueHasTasks())
    {
        return;
    }

    if (mPendingRoll)
    {
        return;
    }

    CorsairRoll& current = getCurrent();

    const size_t buffUp = mInteractionManager.getPlayer().getBuffCount(current.getBuffId()) != 0;
    if (!buffUp)
    {
        if (current.isReady())
        {
            mPendingRoll = true;
            mUseSnakeEye = false;
            mUseDoubleUp = false;

            if (mCrookedCards.isReady())
            {
                mCrookedCards.execute();
            }

            current.setRoll(0);
            current.execute();
        }
    }
    else if (mUseSnakeEye)
    {
        if (mSnakeEye.isReady())
        {
            mUseSnakeEye = false;
            mSnakeEye.execute();
        }
    }
    else if (mUseDoubleUp)
    {
        if (mDoubleUp.isReady())
        {
            mPendingRoll = true;
            mUseDoubleUp = false;
            mDoubleUp.execute();
        }
    }
    else
    {
        selectNext();
    }
}

void CorsairRollList::reset()
{
    mCurrent        = mList.begin();
    mRefreshRunning = false;
    mDoAll          = false;
    mPendingRoll    = false;
    mUseSnakeEye    = false;
    mUseDoubleUp    = false;
}

CorsairRoll& CorsairRollList::getCurrent() const
{
    return **mCurrent;
}

void CorsairRollList::selectNext()
{
    mPendingRoll = false;
    mCurrent++;

    if (mCurrent == mList.end())
    {
        mRefreshRunning = false;
        mDoAll          = false;
        mCurrent        = mList.begin();
    }
    else
    {
        mRefreshRunning = mDoAll;
    }
}

size_t CorsairRollList::getSize() const
{
    return mList.size();
}

const CorsairRoll& CorsairRollList::get(size_t index) const
{
    return *mList[index];
}
