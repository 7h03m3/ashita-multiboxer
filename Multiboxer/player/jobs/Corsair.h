#pragma once

#include "Job.h"
#include "helper/CorsairRollList.h"

namespace player_job
{
    class Corsair : public Job
    {
    public:
        Corsair(player::InteractionManager& interactionManager);

        void poll() override;

        void onCorsairRoll(shared::Ability ability, uint64_t rollNumber) override;

    protected:
        void onBattleStart() override;

        void onBattleStop() override;

        bool onJobCommand(const commands::String& command) override;

    private:
        CorsairRollList mRollList;
    };
} // namespace player_job
