#pragma once

#include "Job.h"

namespace player_job
{
    class Samurai : public Job
    {
    public:
        Samurai(player::InteractionManager& interactionManager);

        void poll() override;

    protected:
        void onBattleStart() override;

        void onBattleStop() override;

        bool onJobCommand(const commands::String& command) override;
    };
} // namespace player_job
