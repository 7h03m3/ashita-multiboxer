#pragma once

#include <vector>
#include <cstdint>
#include <Ashita.h>

#include "PlayerBaseInterface.h"

namespace player
{
    class BuffTracker
    {
    public:
        static const size_t MaxBuffCount = 32;
        static const size_t MaxBuffBits  = 8;
        static const uint16_t NoBuff     = 0xFFFF;

        BuffTracker(IChatManager* chatManager, PlayerBaseInterface& player);

        void update(const uint8_t buffArray[MaxBuffCount], const uint8_t buffBits[MaxBuffBits]);

    private:
        IChatManager* mChatManager;
        PlayerBaseInterface& mPlayer;
        std::vector<uint16_t> mBuffs;

        static bool isInVector(const std::vector<uint16_t>& vector, uint16_t value);
        static void loadBuffList(std::vector<uint16_t>& list, const uint8_t buffArray[MaxBuffCount], const uint8_t buffBits[MaxBuffBits]);
    };
} // namespace player
