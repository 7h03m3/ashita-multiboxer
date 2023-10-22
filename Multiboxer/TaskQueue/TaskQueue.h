#pragma once

#include <Ashita.h>
#include <queue>
#include "TaskQueueItem.h"
#include "ChatManager.h"

class TaskQueue
{
public:
    static const time_t SpellCooldown   = 4u;
    static const time_t AbilityCooldown = 3u;

    TaskQueue(IAshitaCore& ashita, ChatManager& chatManager);

    void add(const std::string& command, std::time_t executionTime, TaskQueueItem::Type type);

    void poll();

    bool hasTasks() const;

    TaskQueueItem& getCurrentTask();

private:
    IAshitaCore& mAshita;
    ChatManager& mChatManager;

    std::queue<TaskQueueItem> mQueue;
};
