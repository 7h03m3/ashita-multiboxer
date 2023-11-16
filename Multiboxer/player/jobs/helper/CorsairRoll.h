#pragma once

#include <stdint.h>
#include <string>
#include "player/InteractionManager.h"
#include "shared/AbilityId.h"
#include "shared/Ability.h"
#include "shared/BuffId.h"

namespace player_job
{
    class CorsairRoll
    {
    public:
        CorsairRoll(shared::AbilityId id, player::InteractionManager& interactionManager);

        CorsairRoll(uint16_t id, player::InteractionManager& interactionManager);

        shared::AbilityId getId() const;

        shared::BuffId getBuffId() const;

        shared::Ability getAbility() const;

        const std::string& getName() const;

        uint64_t getRoll() const;

        bool isReady();

        bool isLucky() const;

        bool isUnlucky() const;

        uint32_t getRecastTime();

        void setRoll(uint64_t roll);

        void execute();

        static bool isAbility(uint32_t abilityId);

    private:
        const shared::AbilityId mAbilityId;
        const shared::Ability mAbility;
        const shared::BuffId mBuffId;
        const std::string mName;
        const uint64_t mLucky;
        const uint64_t mUnlucky;
        player::InteractionManager& mInteractionManager;
        IAshitaCore& mAshita;
        uint64_t mRoll;

        static shared::Ability toAbility(shared::AbilityId abilityId);
        static shared::BuffId toBuff(shared::AbilityId abilityId);
        static uint64_t getLuckNumber(shared::AbilityId abilityId);
        static uint64_t getUnluckyNumber(shared::AbilityId abilityId);
    };
} // namespace player_job
