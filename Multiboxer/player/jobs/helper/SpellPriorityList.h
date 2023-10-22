#pragma once
#include "Spell.h"
#include <vector>

namespace player_job
{
    class SpellPriorityList
    {
    public:
        SpellPriorityList(player::InteractionManager& interactionManager);

        ~SpellPriorityList();

        void add(shared::SpellId id, const Target& target);

        void clear();

        void cast(const std::string& target);

        void cast(uint32_t serverId);

    private:
        player::InteractionManager& mInteractionManager;
        std::vector<Spell*> mList;
    };
} // namespace player_job
