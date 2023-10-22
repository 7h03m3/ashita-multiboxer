#pragma once

#include "shared/SpellId.h"
#include "player/InteractionManager.h"
#include "Target.h"

namespace player_job
{
    class Spell
    {
    public:
        Spell(shared::SpellId id, player::InteractionManager& interactionManager);

        Spell(uint16_t id, player::InteractionManager& interactionManager);

        Spell(shared::SpellId id, player::InteractionManager& interactionManager, const Target& target);

        Spell(uint16_t id, player::InteractionManager& interactionManager, const Target& target);

        shared::SpellId getId() const;

        const std::string& getName() const;

        time_t getCastTime() const;

        uint32_t getMpCost() const;

        bool isReady();

        bool hasEnoughMp(uint32_t currentMp) const;

        uint32_t getRecastTime();

        void execute();

        void setTarget(const Target& target);

        Target& getTarget();

    private:
        const shared::SpellId mId;
        const std::string mName;
        const time_t mCastTime;
        const uint32_t mMpCost;
        Target mTarget;
        player::InteractionManager& mInteractionManager;
        IAshitaCore& mAshita;
    };
} // namespace player_job
