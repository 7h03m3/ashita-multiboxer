#pragma once

#include <cstdint>

namespace packet
{
#pragma pack(push, 1)
    struct JobChange
    {
        uint8_t _reserved[4];

        uint8_t mainJob;
        uint8_t subJob;
        uint8_t _unknown[2];
    };
#pragma pack(pop)
} // namespace packet