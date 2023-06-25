#pragma once

#include <cstdint>

namespace packet
{
#pragma pack(push, 1)
    struct CharInfo
    {
        uint8_t _reserved[4];
        uint32_t ID;
        uint32_t HP;
        uint32_t MP;
        uint32_t TP;
        uint32_t _unknown;
        uint16_t index;
        uint8_t _unknown2[3];
        uint8_t HPP;
        uint8_t MPP;
        uint8_t _unknown3[9];
        char name[16];
    };
#pragma pack(pop)
} // namespace packet