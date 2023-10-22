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

        virtual void poll();

    protected:
        virtual void onBattleStart() override;

        virtual void onBattleStop() override;

        virtual bool onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2);

    private:
        AbilityList mRuneList;
        SpellList mBuffs;
        SpellPriorityList mEnmitySpells;
        SpellPriorityList mEnmityAoeSpells;
    };
} // namespace player_job
