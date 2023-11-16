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

        void doRefresh(const std::string& target);

        void refreshNext();

        void refreshNext(const std::string& target);

        size_t getMaxSize() const;

        size_t getSize() const;

        const Spell& get(size_t index) const;

    private:
        const size_t mMaxSpells;
        player::InteractionManager& mInteractionManager;
        std::vector<Spell*> mList;
        std::vector<Spell*>::iterator mCurrent;
        bool mRefreshRunning;

        Spell& getCurrent() const;
    };
} // namespace player_job
