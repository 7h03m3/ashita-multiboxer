#include "BuffTracker.h"

using namespace player;

BuffTracker::BuffTracker(IChatManager* chatManager, PlayerBaseInterface& player)
    : mChatManager(chatManager)
    , mPlayer(player)
    , mBuffs(MaxBuffCount, NoBuff)
{
}

void BuffTracker::update(const uint8_t buffArray[MaxBuffCount], const uint8_t buffBits[MaxBuffBits])
{
    std::vector<uint16_t> buffs(BuffTracker::MaxBuffCount, BuffTracker::NoBuff);
    loadBuffList(buffs, buffArray, buffBits);

    if (buffs == mBuffs)
    {
        return;
    }

    for (const auto buffId : buffs)
    {
        if ((buffId != NoBuff) && (!isInVector(mBuffs, buffId)))
        {
            std::string message = "[" + mPlayer.getName() + "] buff added : " + std::to_string(buffId);
            mChatManager->AddChatMessage(1, false, message.c_str());
        }
    }

    for (const auto buffId : mBuffs)
    {
        if ((buffId != NoBuff) && (!isInVector(buffs, buffId)))
        {
            std::string message = "[" + mPlayer.getName() + "] buff lost : " + std::to_string(buffId);
            mChatManager->AddChatMessage(1, false, message.c_str());
        }
    }

    mBuffs = buffs;
}

bool BuffTracker::isInVector(const std::vector<uint16_t>& vector, uint16_t value)
{
    for (const auto current : vector)
    {
        if (current == value)
        {
            return true;
        }
    }

    return false;
}

void BuffTracker::loadBuffList(std::vector<uint16_t>& list, const uint8_t buffArray[MaxBuffCount], const uint8_t buffBits[MaxBuffBits])
{
    for (size_t i = 0; i < BuffTracker::MaxBuffCount; i++)
    {
        uint16_t buffId = buffArray[i];
        if (buffId != 0xFF)
        {
            const size_t arrayIndex    = i / 4;
            const size_t bitShiftCount = (i % 4) * 2;

            const uint16_t buffIdAddition = (buffBits[arrayIndex] >> bitShiftCount) & 0x03;
            buffId                        = buffId + (buffIdAddition << 8);

            list.push_back(buffId);
        }
    }
}