#include "Player.h"

using namespace player;

Player::Player()
    : mID(0)
    , mIndex(0)
    , mZone(0)
    , mStats()
    , mMainJob(0)
    , mSubJob(0)
{
}

void Player::setId(uint32_t id)
{
    mID = id;
}

void Player::setIndex(uint16_t index)
{
    mIndex = index;
}

void Player::setZone(uint16_t zone)
{
    mZone = zone;
}

void Player::setJobs(uint8_t mainJob, uint8_t subJob)
{
    mMainJob = mainJob;
    mSubJob  = subJob;
}

uint32_t Player::getId() const
{
    return mID;
}

uint16_t Player::getIndex() const
{
    return mIndex;
}

uint16_t Player::getZone() const
{
    return mZone;
}

uint8_t Player::getMainJob() const
{
    return mMainJob;
}

uint8_t Player::getSubJob() const
{
    return mSubJob;
}

const PlayerStats& Player::getStats() const
{
    return mStats;
}

void Player::updateStats(const PlayerStats& stats)
{
    mStats = stats;
}