#include "PlayerBase.h"

using namespace player;

PlayerBase::PlayerBase(uint32_t id, const std::string& name, ChatManager& chatManager)
    : mChatManager(chatManager)
    , mID(id)
    , mIndex(0)
    , mName(name)
    , mZone(0)
    , mStats()
    , mMainJob(0)
    , mSubJob(0)
    , mBuffs(chatManager, *this)
    , mIsCasting(false)
{
}

PlayerBase::PlayerBase(uint32_t id, uint16_t index, const std::string& name, ChatManager& chatManager)
    : mChatManager(chatManager)
    , mID(id)
    , mIndex(index)
    , mName(name)
    , mZone(0)
    , mStats()
    , mMainJob(0)
    , mSubJob(0)
    , mBuffs(chatManager, *this)
    , mIsCasting(false)
{
}

void PlayerBase::setId(uint32_t id)
{
    if (id == 0)
    {
        return;
    }

    mChatManager.printMessage("[" + mName + "] id changed to " + std::to_string(id));
    mID = id;
}

void PlayerBase::setCasting(const bool isCasting)
{
    mIsCasting = isCasting;
}

void PlayerBase::setIndex(uint16_t index)
{
    if (index == 0)
    {
        return;
    }

    mChatManager.printMessage("[" + mName + "] index changed to " + std::to_string(index));
    mIndex = index;
}

void PlayerBase::setName(const std::string& name)
{
    if (name.empty())
    {
        return;
    }

    mChatManager.printMessage("[" + mName + "] name changed to " + name);
    mName = name;
}

void PlayerBase::setJobs(uint8_t mainJob, uint8_t subJob)
{
    mMainJob = mainJob;
    mSubJob  = subJob;
}

uint32_t PlayerBase::getId() const
{
    return mID;
}

uint16_t PlayerBase::getIndex() const
{
    return mIndex;
}

uint8_t PlayerBase::getMainJob() const
{
    return mMainJob;
}

uint8_t PlayerBase::getSubJob() const
{
    return mSubJob;
}

const PlayerStats& PlayerBase::getStats() const
{
    return mStats;
}

const std::string& PlayerBase::getName() const
{
    return mName;
}

void PlayerBase::updateStats(const PlayerStats& stats)
{
    if (mStats == stats)
    {
        return;
    }

    mStats = stats;

    std::stringstream stringStream;
    stringStream << "[" + mName + "] ";
    stringStream << "HP=" << (unsigned int)mStats.getHP() << " (" << (unsigned int)mStats.getHPP() << ") ";
    stringStream << "MP=" << (unsigned int)mStats.getMP() << " (" << (unsigned int)mStats.getMPP() << ") ";
    stringStream << "TP=" << (unsigned int)mStats.getTP();
    mChatManager.printMessage(stringStream.str());
}

void PlayerBase::updateBuffs(const uint8_t buffArray[BuffTracker::MaxBuffCount], const uint8_t buffBits[BuffTracker::MaxBuffBits])
{
    mBuffs.update(buffArray, buffBits);
}

void PlayerBase::updatePlayerInfo(uint32_t playerId, uint16_t playerIndex)
{
    if (mID != playerId)
    {
        setId(playerId);
    }

    if (mIndex != playerIndex)
    {
        setIndex(playerIndex);
    }
}

void PlayerBase::updatePlayerInfo(uint32_t playerId, uint16_t playerIndex, const std::string& name)
{
    updatePlayerInfo(playerId, playerIndex);

    if (name != mName)
    {
        setName(name);
    }
}

void PlayerBase::setZone(uint16_t zone)
{
    if (zone == mZone)
    {
        return;
    }

    mChatManager.printMessage("[" + mName + "] zone changed to " + std::to_string(zone));
    mZone = zone;
}

uint16_t PlayerBase::getZone() const
{
    return mZone;
}

bool PlayerBase::isCasting() const
{
    return mIsCasting;
}

size_t PlayerBase::getBuffCount(const shared::BuffId buff) const
{
    return mBuffs.getBuffCount(buff);
}
