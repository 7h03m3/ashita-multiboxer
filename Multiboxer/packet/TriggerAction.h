#pragma once

#include <cstdint>

namespace packet
{
#pragma pack(push, 1)
    struct TriggerAction
    {
        uint8_t _reserved[4];

        uint32_t target;
        uint16_t targetIndex;
        uint16_t category;
        uint16_t param;
        uint16_t _unknown1;

        float xOffset;
        float zOffset;
        float yOffset;
    };
#pragma pack(pop)
} // namespace packet