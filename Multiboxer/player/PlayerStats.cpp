#include "PlayerStats.h"

using namespace player;

PlayerStats::PlayerStats()
    : mHP(0u)
    , mMP(0u)
    , mTP(0u)
    , mHPP(0u)
    , mMPP(0u)
{}

PlayerStats::PlayerStats(uint32_t hp, uint32_t mp, uint32_t tp, uint8_t hpp, uint8_t mpp)
    : mHP(hp)
    , mMP(mp)
    , mTP(tp)
    , mHPP(hpp)
    , mMPP(mpp)
{}

uint32_t PlayerStats::getHP() const
{
    return mHP;
}

uint32_t PlayerStats::getMP() const
{
    return mMP;
}

uint32_t PlayerStats::getTP() const
{
    return mTP;
}

uint8_t PlayerStats::getHPP() const
{
    return mHPP;
}

uint8_t PlayerStats::getMPP() const
{
    return mMPP;
}

PlayerStats& PlayerStats::operator=(const PlayerStats& other)
{
    this->mHP  = other.mHP;
    this->mMP  = other.mMP;
    this->mTP  = other.mTP;
    this->mHPP = other.mHPP;
    this->mMPP = other.mMPP;
    return *this;
}

bool PlayerStats::operator==(const PlayerStats& b) const
{
    return ((b.mHP == this->mHP) && (b.mMP == this->mMP) && (b.mTP == this->mTP));
}

bool PlayerStats::operator!=(const PlayerStats& b) const
{
    return ((b.mHP != this->mHP) || (b.mMP != this->mMP) || (b.mTP != this->mTP));
}