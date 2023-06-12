#pragma once

#include <cstdint>

namespace packet
{
#pragma pack(push, 1)
    struct PlayerUpdate
    {
        uint8_t _reserved[4];
        uint8_t buff[32];
        uint8_t _reserved2[40];
        uint8_t buffBits[8];
    };
#pragma pack(pop)
} // namespace packet