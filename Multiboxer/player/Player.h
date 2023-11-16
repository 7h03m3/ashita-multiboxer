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
        Player(IAshitaCore& ashita, TaskQueue& taskQueue, ChatManager& chatManager, PartyManager& partyManager);

        ~Player();

        virtual void poll();

        virtual void setJobs(uint8_t mainJob, uint8_t subJob) override;

        virtual void onCommand(const commands::String& command);

        virtual void onJobCommand(const commands::String& command);

        virtual void onDisengage();

        virtual void onMobDeath(uint32_t mobServerId);

        virtual void onCorsairRoll(shared::Ability ability, uint64_t rollNumber);

    private:
        IAshitaCore& mAshitaCore;
        MoveController mMoveController;
        InteractionManager mInteractionManager;
        player_job::Job* mJob;
    };
} // namespace player