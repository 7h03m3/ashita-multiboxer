#pragma once

#include <cstdint>

namespace packet
{
#pragma pack(push, 1)
    struct KillMessage
    {
        uint8_t _reserved[4];

        uint32_t playerId;
        uint32_t targetId;
        uint16_t playerIndex;
        uint16_t targetIndex;
        uint32_t param1;
        uint32_t param2;
        uint16_t message;
        uint16_t flags;
    };
#pragma pack(pop)
} // namespace packet