#pragma once

#include <Ashita.h>
#include <string>
#include "TaskQueue/TaskQueue.h"
#include "MoveController.h"
#include "PlayerBaseInterface.h"

namespace player
{
    class InteractionManager
    {
    public:
        InteractionManager(IAshitaCore& ashita, TaskQueue& taskQueue, MoveController& moveController, PlayerBaseInterface& playerBase, ChatManager& chatManager);

        void printMessage(const std::string& message);

        void printError(const std::string& message);

        void follow(const std::string& target);

        void moveToTarget(uint32_t targetIndex, float targetDistance);

        void stopMove();

        void turnAround(bool reverse);

        bool queueHasTasks() const;

        bool isCasting() const;

        void queueCommand(const std::string& command);

        void queueCommand(const std::string& command, time_t executionTime);

        void queueSpell(const std::string& command);

        void queueSpell(const std::string& command, time_t executionTime);

        void queueAbility(const std::string& command);

        void queueAbility(const std::string& command, time_t executionTime);

        IAshitaCore& getAshita() const;

        const PlayerBaseInterface& getPlayer() const;

        bool isMaster() const;

    private:
        IAshitaCore& mAshita;
        TaskQueue& mTaskQueue;
        MoveController& mMoveController;
        PlayerBaseInterface& mPlayer;
        ChatManager& mChatManager;
    };
} // namespace player
