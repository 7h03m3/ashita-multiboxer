#pragma once

#include "PlayerBase.h"
#include "MoveController.h"
#include "jobs/Job.h"
#include "TaskQueue/TaskQueue.h"
#include "InteractionManager.h"

namespace player
{
    class Player : public PlayerBase
    {
    public:
        Player(IAshitaCore& ashita, TaskQueue& taskQueue, ChatManager& chatManager);

        ~Player();

        virtual void poll();

        virtual void setJobs(uint8_t mainJob, uint8_t subJob) override;

        virtual void onCommand(const std::string& command, const std::string& argument1, const std::string& argument2);

        virtual void onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2);

        virtual void onDisengage();

        virtual void onMobDeath(uint32_t mobServerId);

    private:
        IAshitaCore& mAshitaCore;
        MoveController mMoveController;
        InteractionManager mInteractionManager;
        player_job::Job* mJob;
    };
} // namespace player