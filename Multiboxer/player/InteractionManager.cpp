#include "InteractionManager.h"

using namespace player;

InteractionManager::InteractionManager(IAshitaCore& ashita, TaskQueue& taskQueue, MoveController& moveController, PlayerBaseInterface& player, ChatManager& chatManager)
    : mAshita(ashita)
    , mTaskQueue(taskQueue)
    , mMoveController(moveController)
    , mPlayer(player)
    , mChatManager(chatManager)
{
}

void InteractionManager::printMessage(const std::string& message)
{
    mChatManager.printMessage(message);
}

void InteractionManager::printError(const std::string& message)
{
    mChatManager.printError(message);
}

void InteractionManager::follow(const std::string& target)
{
    mMoveController.follow(target);
}

void InteractionManager::moveToTarget(uint32_t targetIndex, float targetDistance)
{
    mMoveController.moveToTarget(targetIndex, targetDistance);
}

void InteractionManager::stopMove()
{
    mMoveController.stopMove();
}

void InteractionManager::turnAround(bool reverse)
{
    mMoveController.turnAround(reverse);
}

bool InteractionManager::queueHasTasks() const
{
    return mTaskQueue.hasTasks();
}

bool InteractionManager::isCasting() const
{
    return mPlayer.isCasting();
}

void InteractionManager::queueCommand(const std::string& command)
{
    mTaskQueue.add(command, 0, TaskQueueItem::Command);
}

void InteractionManager::queueCommand(const std::string& command, time_t executionTime)
{
    mTaskQueue.add(command, executionTime, TaskQueueItem::Command);
}

void InteractionManager::queueSpell(const std::string& command)
{
    mTaskQueue.add(command, 0, TaskQueueItem::Spell);
}

void InteractionManager::queueSpell(const std::string& command, time_t executionTime)
{
    mTaskQueue.add(command, executionTime, TaskQueueItem::Spell);
}

void InteractionManager::queueAbility(const std::string& command)
{
    mTaskQueue.add(command, 0, TaskQueueItem::Ability);
}

void InteractionManager::queueAbility(const std::string& command, time_t executionTime)
{
    mTaskQueue.add(command, executionTime, TaskQueueItem::Ability);
}

IAshitaCore& InteractionManager::getAshita() const
{
    return mAshita;
}

const PlayerBaseInterface& InteractionManager::getPlayer() const
{
    return mPlayer;
}

bool InteractionManager::isMaster() const
{
    return mPlayer.getName() == "Sarfa";
}