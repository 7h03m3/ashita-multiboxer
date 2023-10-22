#pragma once

#include <Ashita.h>
#include <ffxi/enums.h>
#include <string>
#include "player/InteractionManager.h"
#include "player/BattleTarget.h"
#include "commands/TargetHelper.h"

namespace player_job
{
    class Job
    {
    public:
        Job(Ashita::FFXI::Enums::Job jobId, const std::string& name, player::InteractionManager& interactionManager);

        Ashita::FFXI::Enums::Job getId() const;

        const std::string& getName() const;

        virtual void poll();

        virtual bool onCommand(const std::string& command, const std::string& argument1, const std::string& argument2);

        void onMobDeath(uint32_t mobServerId);

        void onDisengage();

    protected:
        player::InteractionManager& mInteractionManager;
        player::BattleTarget mBattleTarget;

        virtual void onBattleStart();

        virtual void onBattleStop();

        void engage(uint32_t serverId);

        void disengage();

        virtual bool onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2);

    private:
        const Ashita::FFXI::Enums::Job mJobId;
        const std::string mName;
        float mBattleDistance;
        commands::TargetHelper mTargetHelper;
    };
} // namespace player_job
