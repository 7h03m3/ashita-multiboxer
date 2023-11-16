#pragma once

#include "Job.h"
#include "helper/BardSongList.h"
#include "helper/Ability.h"
#include "helper/SpellList.h"

namespace player_job
{
    class Bard : public Job
    {
    public:
        Bard(player::InteractionManager& interactionManager);

        void poll() override;

    protected:
        void onBattleStart() override;

        void onBattleStop() override;

        bool onJobCommand(const commands::String& command) override;

    private:
        size_t mMaxSongs;
        bool mStringInstrument;
        BardSongList mSongList;
        BardSongList mPrecastSongList;
        SpellList mDebuffList;
        Ability mNightingale;
        Ability mTroubadour;
        Ability mMarcato;

        static const size_t StringSongCountThreshold = 2;

        void useNiTro();
        void useMarcato();
        void setInstrument();
        void setStringInstrument();
        void setWindInstrument();
    };
} // namespace player_job
