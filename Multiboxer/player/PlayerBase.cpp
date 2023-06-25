#include "PlayerBase.h"

using namespace player;

PlayerBase::PlayerBase(uint32_t id, const std::string& name, IChatManager* chatManager)
    : mChatManager(chatManager)
    , mID(id)
    , mIndex(0)
    , mName(name)
    , mZone(0)
    , mStats()
    , mMainJob(0)
    , mSubJob(0)
    , mBuffs(chatManager, *this)
{
}

PlayerBase::PlayerBase(uint32_t id, uint16_t index, const std::string& name, IChatManager* chatManager)
    : mChatManager(chatManager)
    , mID(id)
    , mIndex(index)
    , mName(name)
    , mZone(0)
    , mStats()
    , mMainJob(0)
    , mSubJob(0)
    , mBuffs(chatManager, *this)
{
}

void PlayerBase::setId(uint32_t id)
{
    if (id == 0)
    {
        return;
    }

    std::string message = "[" + mName + "] id changed to " + std::to_string(id);
    mChatManager->AddChatMessage(1, false, message.c_str());
    mID = id;
}

void PlayerBase::setIndex(uint16_t index)
{
    if (index == 0)
    {
        return;
    }

    std::string message = "[" + mName + "] index changed to " + std::to_string(index);
    mChatManager->AddChatMessage(1, false, message.c_str());
    mIndex = index;
}

void PlayerBase::setName(const std::string& name)
{
    if (name.empty())
    {
        return;
    }

    std::string message = "[" + mName + "] name changed to " + name;
    mChatManager->AddChatMessage(1, false, message.c_str());
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
    /*
    std::stringstream stringStream;
    stringStream << "[" + mName + "] ";
    stringStream << "HP=" << (unsigned int)mStats.getHP() << " (" << (unsigned int)mStats.getHPP() << ") ";
    stringStream << "MP=" << (unsigned int)mStats.getMP() << " (" << (unsigned int)mStats.getMPP() << ") ";
    stringStream << "TP=" << (unsigned int)mStats.getTP();
    mChatManager->AddChatMessage(1, false, stringStream.str().c_str());*/
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

    std::string message = "[" + mName + "] zone changed to " + std::to_string(zone);
    mChatManager->AddChatMessage(1, false, message.c_str());
    mZone = zone;
}

uint16_t PlayerBase::getZone() const
{
    return mZone;
}
