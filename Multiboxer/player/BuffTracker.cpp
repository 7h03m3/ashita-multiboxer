#include "BuffTracker.h"
#include "shared/BuffId.h"

using namespace player;

BuffTracker::BuffTracker(ChatManager& chatManager, PlayerBaseInterface& player)
    : mChatManager(chatManager)
    , mPlayer(player)
    , mBuffs(MaxBuffCount, shared::BuffId::NoBuff)
{
}

void BuffTracker::update(const uint8_t buffArray[MaxBuffCount], const uint8_t buffBits[MaxBuffBits])
{
    std::vector<shared::BuffId> buffs(BuffTracker::MaxBuffCount, shared::BuffId::NoBuff);
    loadBuffList(buffs, buffArray, buffBits);

    if (buffs == mBuffs)
    {
        return;
    }

    for (const auto buffId : buffs)
    {
        if ((buffId != shared::BuffId::NoBuff) &&
            (!isInVector(mBuffs, buffId)))
        {
            mChatManager.printMessage("[" + mPlayer.getName() + "] buff added : " + std::to_string(static_cast<uint16_t>(buffId)));
        }
    }

    for (const auto buffId : mBuffs)
    {

        if ((static_cast<shared::BuffId>(buffId) != shared::BuffId::NoBuff) && (!isInVector(buffs, buffId)))
        {
            mChatManager.printMessage("[" + mPlayer.getName() + "] buff lost : " + std::to_string(static_cast<uint16_t>(buffId)));
        }
    }

    mBuffs = buffs;
}

size_t BuffTracker::getBuffCount(const shared::BuffId buff) const
{
    size_t count = 0;
    for (const auto current : mBuffs)
    {
        if (current == buff)
        {
            count++;
        }
    }

    return count;
}

bool BuffTracker::isInVector(const std::vector<shared::BuffId>& vector, shared::BuffId value)
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

void BuffTracker::loadBuffList(std::vector<shared::BuffId>& list, const uint8_t buffArray[MaxBuffCount], const uint8_t buffBits[MaxBuffBits])
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

            list.push_back(static_cast<shared::BuffId>(buffId));
        }
    }
}