#include "AbilityList.h"

using namespace player_job;

AbilityList::AbilityList(size_t maxAbilities, player::InteractionManager& interactionManager)
    : mMaxAbilities(maxAbilities)
    , mInteractionManager(interactionManager)
    , mList()
    , mCurrent(mList.end())
    , mRefreshRunning(false)
{
}

AbilityList::~AbilityList()
{
    for (auto it : mList)
    {
        delete it;
    }
}

bool AbilityList::isRefreshRunning() const
{
    return mRefreshRunning;
}

bool AbilityList::add(const shared::AbilityId id)
{
    if (mList.size() >= mMaxAbilities)
    {
        return false;
    }

    mList.push_back(new Ability(id, mInteractionManager));
    mCurrent = mList.begin();

    return true;
}

bool AbilityList::set(const size_t index, const shared::AbilityId id)
{
    if (index >= mList.size())
    {
        return false;
    }

    delete mList[index];
    mList[index] = new Ability(id, mInteractionManager);

    return true;
}

void AbilityList::startRefresh()
{
    if (mList.empty())
    {
        return;
    }

    mRefreshRunning = true;
    mCurrent        = mList.begin();
}

void AbilityList::stopRefresh()
{
    mRefreshRunning = false;
}

void AbilityList::doRefresh()
{
    if (!isRefreshRunning())
    {
        return;
    }

    if (!mInteractionManager.queueHasTasks() && getCurrent().isReady())
    {
        getCurrent().execute();
        mCurrent++;
        mRefreshRunning = mCurrent != mList.end();
        if (!mRefreshRunning)
        {
            mCurrent = mList.begin();
        }
    }
}

void AbilityList::refreshNext()
{
    if (mList.empty())
    {
        return;
    }

    if (!getCurrent().isReady())
    {
        mInteractionManager.printError("ability not ready");
        return;
    }

    getCurrent().execute();
    mCurrent++;
    if (mCurrent == mList.end())
    {
        mCurrent = mList.begin();
    }
}

Ability& AbilityList::getCurrent() const
{
    return **mCurrent;
}

size_t AbilityList::getSize() const
{
    return mList.size();
}

const Ability& AbilityList::get(size_t index) const
{
    return *mList[index];
}