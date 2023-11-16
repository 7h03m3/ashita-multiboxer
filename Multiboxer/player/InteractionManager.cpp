#include "InteractionManager.h"

using namespace player;

const float InteractionManager::CastingRange = 21.0;

InteractionManager::InteractionManager(IAshitaCore& ashita, TaskQueue& taskQueue, MoveController& moveController, PlayerBaseInterface& player, ChatManager& chatManager, PartyManager& partyManager)
    : mAshita(ashita)
    , mTaskQueue(taskQueue)
    , mMoveController(moveController)
    , mPlayer(player)
    , mChatManager(chatManager)
    , mPartyManager(partyManager)
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

time_t InteractionManager::getSpellCastingTime(shared::SpellId spellId) const
{
    uint8_t castingTime = mAshita.GetResourceManager()->GetSpellById(static_cast<uint32_t>(spellId))->CastTime;

    if ((castingTime % 4) != 0)
    {
        return (castingTime / 4) + 1;
    }
    else
    {
        return castingTime / 4;
    }
}

const PlayerBaseInterface* InteractionManager::getPlayerLowestHp(const uint8_t hppThreshold) const
{
    PlayerBaseInterface* currentPlayer = nullptr;
    uint8_t lowestHpp                  = 100u;

    for (auto it = mPartyManager.begin(); it != mPartyManager.end(); it++)
    {
        const player::PlayerStats& stats = it->second->getStats();

        if ((stats.getHPP() < hppThreshold) && ((currentPlayer == nullptr) || (lowestHpp > stats.getHPP())))
        {
            currentPlayer = it->second;
            lowestHpp     = stats.getHPP();
        }
    }

    const player::PlayerStats& stats = mPlayer.getStats();
    if ((stats.getHPP() < hppThreshold) && (lowestHpp > stats.getHPP()))
    {
        currentPlayer = &mPlayer;
    }

    return currentPlayer;
}

size_t InteractionManager::getPlayerLowestHpCount(const uint8_t hppThreshold) const
{
    size_t count = 0u;

    for (auto it = mPartyManager.begin(); it != mPartyManager.end(); it++)
    {
        const player::PlayerStats& stats = it->second->getStats();

        if (stats.getHPP() < hppThreshold)
        {
            count++;
        }
    }

    const player::PlayerStats& stats = mPlayer.getStats();
    if (stats.getHPP() < hppThreshold)
    {
        count++;
    }

    return count;
}

float InteractionManager::getDistance(const uint16_t targetIndex) const
{
    return mAshita.GetMemoryManager()->GetEntity()->GetDistance(targetIndex);
}

bool InteractionManager::isInCastingRange(const uint16_t targetIndex) const
{
    return (getDistance(targetIndex) <= CastingRange);
}