#pragma once

#include <Ashita.h>
#include <ffxi/enums.h>
#include <string>
#include "player/InteractionManager.h"
#include "player/BattleTarget.h"
#include "commands/TargetHelper.h"
#include "shared/Ability.h"
#include "commands/String.h"

namespace player_job
{
    class Job
    {
    public:
        Job(Ashita::FFXI::Enums::Job jobId, const std::string& name, player::InteractionManager& interactionManager);

        Ashita::FFXI::Enums::Job getId() const;

        const std::string& getName() const;

        virtual void poll();

        virtual bool onCommand(const commands::String& command);

        void onMobDeath(uint32_t mobServerId);

        void onDisengage();

        virtual void onCorsairRoll(shared::Ability ability, uint64_t rollNumber);

    protected:
        player::InteractionManager& mInteractionManager;
        player::BattleTarget mBattleTarget;

        virtual void onBattleStart();

        virtual void onBattleStop();

        void engage(uint32_t serverId);

        void disengage();

        virtual bool onJobCommand(const commands::String& command);

        void setBattleDistance(float battleDistance);

    private:
        const Ashita::FFXI::Enums::Job mJobId;
        const std::string mName;
        float mBattleDistance;
        commands::TargetHelper mTargetHelper;
    };
} // namespace player_job
