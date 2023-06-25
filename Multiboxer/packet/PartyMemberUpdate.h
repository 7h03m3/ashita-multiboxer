#pragma once

#include <cstdint>

namespace packet
{
#pragma pack(push, 1)
    struct PartyMemberUpdate
    {
        uint8_t _reserved[4];
        uint32_t ID;
        uint32_t HP;
        uint32_t MP;
        uint32_t TP;
        uint16_t flags;
        uint16_t _unknown;
        uint16_t index;
        uint16_t _unknown2;
        uint8_t _unknown3;
        uint8_t HPP;
        uint8_t MPP;
        uint8_t _unknown4;
        uint16_t zone;
        uint8_t mainJob;
        uint8_t mainJobLevel;
        uint8_t subJob;
        uint8_t subJobLevel;
        uint8_t masterLevel;
        uint8_t masterBreaker : 1;
        uint8_t _reserved2 : 7;

        char name[16];
    };
#pragma pack(pop)
} // namespace packet