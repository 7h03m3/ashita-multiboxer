#pragma once

#include "Job.h"

namespace player_job
{
    class Geomancer : public Job
    {
    public:
        Geomancer(player::InteractionManager& interactionManager);

        virtual void poll();

    protected:
        virtual void onBattleStart() override;

        virtual void onBattleStop() override;

        virtual bool onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2);
    };
} // namespace player_job
