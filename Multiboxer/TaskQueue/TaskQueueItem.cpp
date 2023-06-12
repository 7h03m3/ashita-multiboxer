#include "TaskQueueItem.h"

TaskQueueItem::TaskQueueItem(const std::string& command, std::time_t delay)

    : mDelay(delay + CooldownTime)
    , mCommand(command)
    , mTriggered(false)
    , mWaitTime(0)
{
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