#pragma once

#include <vector>
#include "CorsairRoll.h"
#include "Ability.h"

namespace player_job
{
    class CorsairRollList
    {
    public:
        CorsairRollList(player::InteractionManager& interactionManager);

        ~CorsairRollList();

        bool isRefreshRunning() const;

        bool add(shared::AbilityId id);

        bool set(size_t index, shared::AbilityId id);

        void setRoll(shared::Ability ability, uint64_t roll);

        void startRefresh();

        void stopRefresh();

        void refreshNext();

        void doRefresh();

        void reset();

        size_t getSize() const;

        const CorsairRoll& get(size_t index) const;

    private:
        static const size_t MaxRolls = 2;
        player::InteractionManager& mInteractionManager;
        std::vector<CorsairRoll*> mList;
        std::vector<CorsairRoll*>::iterator mCurrent;
        bool mRefreshRunning;
        bool mDoAll;
        Ability mDoubleUp;
        Ability mSnakeEye;
        Ability mCrookedCards;
        bool mPendingRoll;
        bool mUseSnakeEye;
        bool mUseDoubleUp;

        CorsairRoll& getCurrent() const;

        void selectNext();
    };
} // namespace player_job
