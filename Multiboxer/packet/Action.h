#pragma once

#include <cstdint>

namespace packet
{
#pragma pack(push, 1)
    struct Action
    {
        uint8_t _reserved[4];

        // 04
        uint8_t size;

        // 05 - 08
        uint32_t actor;

        // 09 - 0C
        uint32_t targetCount : 10;
        uint32_t category : 4;
        uint32_t param : 16;
        uint32_t _unknown2 : 2;

        // 0D
        uint8_t _unknown3;

        // 0E
        uint64_t _unknown4 : 6;
        uint64_t recast : 32;
        uint64_t _unknown5 : 26;
    };
#pragma pack(pop)
} // namespace packet