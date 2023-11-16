#pragma once

#include "Job.h"
#include "helper/AbilityList.h"
#include "helper/SpellList.h"
#include "helper/SpellPriorityList.h"

namespace player_job
{
    class RuneFencer : public Job
    {
    public:
        RuneFencer(player::InteractionManager& interactionManager);

        void poll() override;

    protected:
        void onBattleStart() override;

        void onBattleStop() override;

        bool onJobCommand(const commands::String& command) override;

    private:
        AbilityList mRuneList;
        SpellList mBuffs;
        SpellPriorityList mEnmitySpells;
        SpellPriorityList mEnmityAoeSpells;
    };
} // namespace player_job
