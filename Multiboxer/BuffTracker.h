#pragma once

#include <vector>
#include <cstdint>
#include <Ashita.h>

class BuffTracker
{
public:
    static const size_t MaxBuffCount = 32;
    static const uint16_t NoBuff     = 0xFFFF;

    BuffTracker(IChatManager* chatManager);

    void update(const std::vector<uint16_t>& buffs);

private:
    IChatManager* mChatManager;
    std::vector<uint16_t> mBuffs;

    static bool isInVector(const std::vector<uint16_t>& vector, uint16_t value);
};
