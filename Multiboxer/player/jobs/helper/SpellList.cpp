#include "SpellList.h"

using namespace player_job;

SpellList::SpellList(const size_t maxSpells, player::InteractionManager& interactionManager)
    : mMaxSpells(maxSpells)
    , mInteractionManager(interactionManager)
    , mList()
    , mCurrent(mList.end())
    , mRefreshRunning(false)
{
}

SpellList::~SpellList()
{
    for (auto it : mList)
    {
        delete it;
    }
}

bool SpellList::isRefreshRunning() const
{
    return mRefreshRunning;
}

bool SpellList::add(shared::SpellId id)
{
    if (mList.size() >= mMaxSpells)
    {
        return false;
    }

    mList.push_back(new Spell(id, mInteractionManager));
    mCurrent = mList.begin();

    return true;
}

bool SpellList::add(shared::SpellId id, const Target& target)
{
    if (mList.size() >= mMaxSpells)
    {
        return false;
    }

    mList.push_back(new Spell(id, mInteractionManager, target));
    mCurrent = mList.begin();

    return true;
}

bool SpellList::set(size_t index, shared::SpellId id)
{
    if (index >= mList.size())
    {
        return false;
    }

    delete mList[index];
    mList[index] = new Spell(id, mInteractionManager);

    return true;
}

bool SpellList::set(size_t index, shared::SpellId id, const Target& target)
{
    if (index >= mList.size())
    {
        return false;
    }

    delete mList[index];
    mList[index] = new Spell(id, mInteractionManager, target);

    return true;
}

void SpellList::startRefresh()
{
    if (mList.empty())
    {
        return;
    }

    mRefreshRunning = true;
    mCurrent        = mList.begin();
}

void SpellList::stopRefresh()
{
    mRefreshRunning = false;
}

void SpellList::doRefresh()
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

void SpellList::refreshNext()
{
    if (mList.empty())
    {
        return;
    }

    if (!getCurrent().isReady())
    {
        mInteractionManager.printError("spell not ready");
        return;
    }

    getCurrent().execute();
    mCurrent++;
    if (mCurrent == mList.end())
    {
        mCurrent = mList.begin();
    }
}

Spell& SpellList::getCurrent() const
{
    return **mCurrent;
}