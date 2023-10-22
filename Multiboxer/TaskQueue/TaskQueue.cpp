#include "TaskQueue.h"

TaskQueue::TaskQueue(IAshitaCore& ashita, ChatManager& chatManager)
    : mAshita(ashita)
    , mChatManager(chatManager)
    , mQueue()
{}

void TaskQueue::add(const std::string& command, const std::time_t executionTime, const TaskQueueItem::Type type)
{
    mQueue.push(TaskQueueItem(command, executionTime, type));
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
        mChatManager.printMessage(task.getCommand());
        mAshita.GetChatManager()->QueueCommand(0, task.getCommand().c_str());
        task.setAsTriggered();
    }
    else if (task.isDone())
    {
        mQueue.pop();
    }
}

TaskQueueItem& TaskQueue::getCurrentTask()
{
    return mQueue.front();
}
