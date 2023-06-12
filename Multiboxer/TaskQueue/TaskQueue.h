#pragma once

#include <Ashita.h>
#include <queue>
#include "TaskQueueItem.h"

class TaskQueue
{
public:
    TaskQueue(IChatManager* chatManager);

    void add(const std::string& command, std::time_t executionTime);

    void poll();

private:
    IChatManager* mChatManager;
    std::queue<TaskQueueItem> mQueue;

    bool hasTasks() const;
};
