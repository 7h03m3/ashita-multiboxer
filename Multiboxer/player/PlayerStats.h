#pragma once

#include <cstdint>

namespace player
{
    class PlayerStats
    {
    public:
        PlayerStats();
        PlayerStats(uint32_t hp, uint32_t mp, uint32_t tp, uint8_t hpp, uint8_t mpp);

        uint32_t getHP() const;
        uint32_t getMP() const;
        uint32_t getTP() const;
        uint8_t getHPP() const;
        uint8_t getMPP() const;

        PlayerStats& operator=(const PlayerStats& other);
        bool operator==(const PlayerStats& b) const;
        bool operator!=(const PlayerStats& b) const;

    private:
        uint32_t mHP;
        uint32_t mMP;
        uint32_t mTP;
        uint8_t mHPP;
        uint8_t mMPP;
    };
} // namespace player
