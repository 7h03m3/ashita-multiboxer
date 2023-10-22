#pragma once

#include "Job.h"
#include "helper/BardSongList.h"

namespace player_job
{
    class Bard : public Job
    {
    public:
        Bard(player::InteractionManager& interactionManager);

        virtual void poll();

    protected:
        virtual void onBattleStart() override;

        virtual void onBattleStop() override;

        virtual bool onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2);

    private:
        size_t mMaxSongs;
        bool mStringInstrument;
        BardSongList mSongList;

        static const size_t StringSongCountThreshold = 2;

        void setInstrument();
        void setStringInstrument();
        void setWindInstrument();
    };
} // namespace player_job
