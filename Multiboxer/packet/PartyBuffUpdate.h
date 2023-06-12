#pragma once

#include <cstdint>

namespace packet
{
#pragma pack(push, 1)
    struct PartyBuffUpdateEntry
    {
        uint32_t ID;
        uint16_t index;
        uint16_t _unknown;
        uint8_t buffBits[8];
        uint8_t buff[32];
    };

    struct PartyBuffUpdate
    {
        uint8_t reserved[4];
        PartyBuffUpdateEntry partyMembers[5];
    };
#pragma pack(pop)
} // namespace packet