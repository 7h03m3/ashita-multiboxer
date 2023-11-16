#pragma once

#include <vector>
#include "Ability.h"

namespace player_job
{
    class AbilityList
    {
    public:
        AbilityList(size_t maxAbilities, player::InteractionManager& interactionManager);

        ~AbilityList();

        bool isRefreshRunning() const;

        bool add(shared::AbilityId id);

        bool set(size_t index, shared::AbilityId id);

        void startRefresh();

        void stopRefresh();

        void doRefresh();

        void refreshNext();

        size_t getSize() const;

        const Ability& get(size_t index) const;

    private:
        const size_t mMaxAbilities;
        player::InteractionManager& mInteractionManager;
        std::vector<Ability*> mList;
        std::vector<Ability*>::iterator mCurrent;
        bool mRefreshRunning;

        Ability& getCurrent() const;
    };
} // namespace player_job
