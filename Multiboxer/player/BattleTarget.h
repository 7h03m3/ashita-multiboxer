#pragma once

#include <stdint.h>

namespace player
{
    class BattleTarget
    {
    public:
        BattleTarget();

        void set(uint32_t serverId);

        void clear();

        bool isValid() const;

        uint32_t getServerId() const;

    private:
        uint32_t mServerId;
    };
} // namespace player
