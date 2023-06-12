#pragma once

#include <ctime>
#include <string>

class TaskQueueItem
{
public:
    TaskQueueItem(const std::string& command, std::time_t delay);

    const std::string& getCommand() const;

    bool isTriggered() const;

    void setAsTriggered();

    bool isDone() const;

private:
    static const std::time_t CooldownTime = 3;

    std::time_t mDelay;
    std::string mCommand;
    bool mTriggered;
    std::time_t mWaitTime;

    static std::time_t getTime();
};
