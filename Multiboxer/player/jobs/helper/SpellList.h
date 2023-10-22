#pragma once
#include <vector>
#include "Spell.h"

namespace player_job
{
    class SpellList
    {
    public:
        SpellList(size_t maxSpells, player::InteractionManager& interactionManager);

        ~SpellList();

        bool isRefreshRunning() const;

        bool add(shared::SpellId id);

        bool add(shared::SpellId id, const Target& target);

        bool set(size_t index, shared::SpellId id);

        bool set(size_t index, shared::SpellId id, const Target& target);

        void startRefresh();

        void stopRefresh();

        void doRefresh();

        void refreshNext();

    private:
        const size_t mMaxSpells;
        player::InteractionManager& mInteractionManager;
        std::vector<Spell*> mList;
        std::vector<Spell*>::iterator mCurrent;
        bool mRefreshRunning;

        Spell& getCurrent() const;
    };
} // namespace player_job
