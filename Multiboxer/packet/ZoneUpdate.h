#pragma once

#include <cstdint>

namespace packet
{
#pragma pack(push, 1)
    struct ZoneUpdate
    {
        // 00 - 03
        uint8_t _reserved[4];

        // 04 - 07
        uint32_t playerId;

        // 08 - 09
        uint16_t playerIndex;

        // 0A
        uint8_t _padding;

        // 0B
        uint8_t heading;

        // 0C - 0F
        float X;

        // 10 - 13
        float Y;

        // 14 - 17
        float Z;

        // 18 - 19
        uint16_t runCount;

        // 1A - 1B
        uint16_t targetIndex;

        // 1C
        uint8_t movementSpeed;

        // 1D
        uint8_t animationSpeed;

        // 1E
        uint8_t HPP;

        // 1F
        uint8_t status;

        // 20 - 21
        uint8_t _unknown1[16];

        uint16_t zone;

        // TBD
    };
#pragma pack(pop)
} // namespace packet