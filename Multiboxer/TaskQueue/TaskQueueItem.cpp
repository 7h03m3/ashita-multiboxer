#include "TaskQueueItem.h"

TaskQueueItem::TaskQueueItem(const std::string& command, std::time_t delay, Type type)

    : mType(type)
    , mDelay(delay + CooldownTime)
    , mCommand(command)
    , mTriggered(false)
    , mWaitTime(0)
{
}

TaskQueueItem::Type TaskQueueItem::getType() const
{
    return mType;
}

bool TaskQueueItem::isCommand() const
{
    return mType == Command;
}

bool TaskQueueItem::isAbility() const
{
    return mType == Ability;
}

bool TaskQueueItem::isSpell() const
{
    return mType == Spell;
}

const std::string& TaskQueueItem::getCommand() const
{
    return mCommand;
}

bool TaskQueueItem::isTriggered() const
{
    return mTriggered;
}

void TaskQueueItem::setAsTriggered()
{
    mTriggered = true;
    mWaitTime  = getTime() + mDelay;
}

bool TaskQueueItem::isDone() const
{
    const std::time_t now = getTime();
    return (now >= mWaitTime);
}

std::time_t TaskQueueItem::getTime()
{
    return std::time(nullptr);
}

void TaskQueueItem::setDelay(time_t delay)
{
    const std::time_t now = getTime();
    mWaitTime             = now + delay;
}

std::time_t TaskQueueItem::getRemainingTime() const
{
    const std::time_t now = getTime();
    if (now > mWaitTime)
    {
        return 0;
    }

    return mWaitTime - now;
}