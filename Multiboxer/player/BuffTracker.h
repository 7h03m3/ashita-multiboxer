#pragma once

#include <vector>
#include <cstdint>
#include <Ashita.h>

#include "PlayerBaseInterface.h"
#include "ChatManager.h"

namespace player
{
    class BuffTracker
    {
    public:
        static const size_t MaxBuffCount = 32;
        static const size_t MaxBuffBits  = 8;

        BuffTracker(ChatManager& chatManager, PlayerBaseInterface& player);

        void update(const uint8_t buffArray[MaxBuffCount], const uint8_t buffBits[MaxBuffBits]);

        size_t getBuffCount(shared::BuffId buff) const;

    private:
        ChatManager& mChatManager;
        PlayerBaseInterface& mPlayer;
        std::vector<shared::BuffId> mBuffs;

        static bool isInVector(const std::vector<shared::BuffId>& vector, shared::BuffId value);
        static void loadBuffList(std::vector<shared::BuffId>& list, const uint8_t buffArray[MaxBuffCount], const uint8_t buffBits[MaxBuffBits]);
    };
} // namespace player
