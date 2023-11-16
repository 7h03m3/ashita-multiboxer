#include "BardSongList.h"

#include <map>

using namespace player_job;

BardSongList::BardSongList(const size_t maxSongs, player::InteractionManager& interactionManager)
    : mMaxSongs(maxSongs)
    , mInteractionManager(interactionManager)
    , mList()
    , mCurrent(mList.end())
    , mRefreshRunning(false)
{
}

BardSongList::~BardSongList()
{
    for (auto it : mList)
    {
        delete it;
    }
}

bool BardSongList::isRefreshRunning() const
{
    return mRefreshRunning;
}

bool BardSongList::isFirst() const
{
    return mCurrent == mList.begin();
}

bool BardSongList::add(shared::SpellId id)
{
    if (mList.size() >= mMaxSongs)
    {
        return false;
    }

    mList.push_back(new BardSong(id, mInteractionManager));
    mCurrent = mList.begin();

    return true;
}

bool BardSongList::add(shared::SpellId id, const Target& target)
{
    if (mList.size() >= mMaxSongs)
    {
        return false;
    }

    mList.push_back(new BardSong(id, mInteractionManager, target));
    mCurrent = mList.begin();

    return true;
}

bool BardSongList::set(size_t index, shared::SpellId id)
{
    if (index >= mList.size())
    {
        return false;
    }

    delete mList[index];
    mList[index] = new BardSong(id, mInteractionManager);

    return true;
}

bool BardSongList::set(size_t index, shared::SpellId id, const Target& target)
{
    if (index >= mList.size())
    {
        return false;
    }

    delete mList[index];
    mList[index] = new BardSong(id, mInteractionManager, target);

    return true;
}

size_t BardSongList::getSize() const
{
    return mList.size();
}

const BardSong& BardSongList::get(size_t index) const
{
    return *mList[index];
}

void BardSongList::startRefresh()
{
    if (mList.empty())
    {
        return;
    }

    mRefreshRunning = true;
    mCurrent        = mList.begin();
}

void BardSongList::stopRefresh()
{
    mRefreshRunning = false;
}

void BardSongList::doRefresh()
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

void BardSongList::refreshNext()
{
    if (mList.empty())
    {
        return;
    }

    if (!getCurrent().isReady())
    {
        mInteractionManager.printError("song not ready");
        return;
    }

    getCurrent().execute();
    mCurrent++;
    if (mCurrent == mList.end())
    {
        mCurrent = mList.begin();
    }
}

size_t BardSongList::getSongCount() const
{
    std::map<shared::BuffId, size_t> buffCount;

    for (auto song : mList)
    {
        const shared::BuffId buffId = song->getBuffId();
        auto result                 = buffCount.find(buffId);

        if (result == buffCount.end())
        {
            buffCount[song->getBuffId()] = mInteractionManager.getPlayer().getBuffCount(song->getBuffId());
        }
    }

    size_t count = 0;
    for (auto current : buffCount)
    {
        count += current.second;
    }

    return count;
}

size_t BardSongList::getMaxSongs() const
{
    return mMaxSongs;
}

BardSong& BardSongList::getCurrent() const
{
    return **mCurrent;
}