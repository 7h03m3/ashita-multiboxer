#pragma once

#include "Job.h"

#include "helper/Ability.h"
#include "helper/SpellList.h"

namespace player_job
{
    class WhiteMage : public Job
    {
    public:
        WhiteMage(player::InteractionManager& interactionManager);

        void poll() override;

    protected:
        void onBattleStart() override;

        void onBattleStop() override;

        bool onJobCommand(const commands::String& command) override;

    private:
        SpellList mBuffList;
        Ability mAfflatusSolace;
        bool mAutoHeal;
        uint8_t mAutoHealHppThreshold;

        void useAfflatusSolace();
    };
} // namespace player_job
