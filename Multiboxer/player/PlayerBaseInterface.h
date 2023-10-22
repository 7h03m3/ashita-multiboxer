#pragma once

#include <string>
#include "PlayerStats.h"
#include "shared/BuffId.h"

namespace player
{
    class PlayerBaseInterface
    {
    public:
        virtual const PlayerStats& getStats() const = 0;

        virtual void setJobs(uint8_t mainJob, uint8_t subJob) = 0;

        virtual void setCasting(bool isCasting) = 0;

        virtual void updatePlayerInfo(uint32_t playerId, uint16_t playerIndex) = 0;

        virtual void updatePlayerInfo(uint32_t playerId, uint16_t playerIndex, const std::string& name) = 0;

        virtual void updateStats(const PlayerStats& stats) = 0;

        virtual void updateBuffs(const uint8_t* buffArray, const uint8_t* buffBits) = 0;

        virtual uint32_t getId() const = 0;

        virtual uint16_t getIndex() const = 0;

        virtual const std::string& getName() const = 0;

        virtual uint8_t getMainJob() const = 0;

        virtual uint8_t getSubJob() const = 0;

        virtual void setZone(uint16_t zone) = 0;

        virtual uint16_t getZone() const = 0;

        virtual bool isCasting() const = 0;

        virtual size_t getBuffCount(shared::BuffId buff) const = 0;
    };
} // namespace player