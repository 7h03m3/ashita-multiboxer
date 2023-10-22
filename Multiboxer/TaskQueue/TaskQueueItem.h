#pragma once

#include <ctime>
#include <string>

class TaskQueueItem
{
public:
    enum Type
    {
        Command = 0,
        Ability = 1,
        Spell   = 2,
    };
    TaskQueueItem(const std::string& command, std::time_t delay, Type type);

    const std::string& getCommand() const;

    Type getType() const;

    bool isCommand() const;

    bool isAbility() const;

    bool isSpell() const;

    bool isTriggered() const;

    void setAsTriggered();

    bool isDone() const;

    void setDelay(time_t delay);

    std::time_t getRemainingTime() const;

private:
    static const std::time_t CooldownTime = 0;

    const Type mType;
    std::time_t mDelay;
    std::string mCommand;
    bool mTriggered;
    std::time_t mWaitTime;

    static std::time_t getTime();
};
