#pragma once

#include "shared/AbilityId.h"
#include "player/InteractionManager.h"
#include "Target.h"

namespace player_job
{
    class Ability
    {
    public:
        Ability(shared::AbilityId id, player::InteractionManager& interactionManager);

        Ability(uint16_t id, player::InteractionManager& interactionManager);

        shared::AbilityId getId() const;

        const std::string& getName() const;

        bool isReady();

        uint32_t getRecastTime();

        void execute();

        void setTarget(const Target& target);

        Target& getTarget();

    private:
        const shared::AbilityId mId;
        const std::string mName;
        Target mTarget;
        player::InteractionManager& mInteractionManager;
        IAshitaCore& mAshita;
    };
} // namespace player_job
