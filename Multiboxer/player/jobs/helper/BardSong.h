#pragma once

#include "player/InteractionManager.h"
#include "Target.h"
#include "shared/SpellId.h"
#include "shared/BuffId.h"

namespace player_job
{
    class BardSong
    {
    public:
        BardSong(shared::SpellId id, player::InteractionManager& interactionManager);

        BardSong(uint16_t id, player::InteractionManager& interactionManager);

        BardSong(shared::SpellId id, player::InteractionManager& interactionManager, const Target& target);

        BardSong(uint16_t id, player::InteractionManager& interactionManager, const Target& target);

        shared::SpellId getSpellId() const;

        shared::BuffId getBuffId() const;

        const std::string& getName() const;

        time_t getCastTime() const;

        bool isReady();

        uint32_t getRecastTime();

        void execute();

        void setTarget(const Target& target);

        Target& getTarget();

    private:
        const shared::SpellId mSpellId;
        const shared::BuffId mBuffId;
        const std::string mName;
        const time_t mCastTime;
        Target mTarget;
        player::InteractionManager& mInteractionManager;
        IAshitaCore& mAshita;

        static shared::BuffId getBuffId(shared::SpellId spellId);
    };
} // namespace player_job
