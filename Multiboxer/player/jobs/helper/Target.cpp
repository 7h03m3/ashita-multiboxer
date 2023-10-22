#include "Target.h"

using namespace player_job;

Target::Target(TargetType type)
    : mType(type)
    , mTargetString()
{
}

Target::Target(TargetType type, const std::string& targetString)
    : mType(type)
    , mTargetString(targetString)
{
}

Target::Target(const Target& other)
    : mType(other.mType)
    , mTargetString(other.mTargetString)
{
}

Target& Target::operator=(const Target& other)
{
    if (this != &other)
    {
        mType         = other.mType;
        mTargetString = other.mTargetString;
    }

    return *this;
}

bool Target::isBattleTarget() const
{
    return mType == Battle;
}

bool Target::isMe() const
{
    return mType == Me;
}

bool Target::isCustom() const
{
    return mType == Custom;
}

void Target::set(const std::string& targetString)
{
    mTargetString = targetString;
}

const std::string& Target::get() const
{
    return mTargetString;
}
