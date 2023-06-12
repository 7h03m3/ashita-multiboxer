#include "TaskQueue.h"

TaskQueue::TaskQueue(IChatManager* chatManager)
    : mChatManager(chatManager)
    , mQueue()
{}

void TaskQueue::add(const std::string& command, std::time_t executionTime)
{
    mQueue.push(TaskQueueItem(command, executionTime));
}

bool TaskQueue::hasTasks() const
{
    return !mQueue.empty();
}

void TaskQueue::poll()
{
    if (mQueue.empty())
    {
        return;
    }

    TaskQueueItem& task = mQueue.front();

    if (!task.isTriggered())
    {
        mChatManager->QueueCommand(2, task.getCommand().c_str());
        task.setAsTriggered();
    }
    else if (task.isDone())
    {
        mQueue.pop();
    }
}
