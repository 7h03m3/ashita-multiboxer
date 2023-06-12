#pragma once

#include "PlayerStats.h"

namespace player
{
    class Player
    {
    public:
        Player();

        const PlayerStats& getStats() const;

        void setId(uint32_t id);

        void setIndex(uint16_t index);

        void setZone(uint16_t zone);

        void setJobs(uint8_t mainJob, uint8_t subJob);

        void updateStats(const PlayerStats& stats);

        uint32_t getId() const;

        uint16_t getIndex() const;

        uint16_t getZone() const;

        uint8_t getMainJob() const;

        uint8_t getSubJob() const;

    private:
        uint32_t mID;
        uint16_t mIndex;
        uint16_t mZone;
        uint8_t mMainJob;
        uint8_t mSubJob;
        PlayerStats mStats;
    };
} // namespace player