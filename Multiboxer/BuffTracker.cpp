#include "BuffTracker.h"

BuffTracker::BuffTracker(IChatManager* chatManager)
    : mChatManager(chatManager)
    , mBuffs(MaxBuffCount, NoBuff)
{
}

void BuffTracker::update(const std::vector<uint16_t>& buffs)
{
    if (buffs == mBuffs)
    {
        return;
    }

    for (const auto buffId : buffs)
    {
        if ((buffId != NoBuff) && (!isInVector(mBuffs, buffId)))
        {
            std::string message = "buff added : " + std::to_string(buffId);
            mChatManager->AddChatMessage(1, false, message.c_str());
        }
    }

    for (const auto buffId : mBuffs)
    {
        if ((buffId != NoBuff) && (!isInVector(buffs, buffId)))
        {
            std::string message = "buff lost : " + std::to_string(buffId);
            mChatManager->AddChatMessage(1, false, message.c_str());
        }
    }

    /*
    for (const auto buffId : buffs)
    {
        auto entry = std::find(mBuffs.begin(), mBuffs.end(), buffId);
        if (entry == mBuffs.end())
        {
            const std::string message = "new buff " + std::to_string(buffId);
            mChatManager->AddChatMessage(1, false, message.c_str());
            mChatManager->AddChatMessage(1, false, "test");
        }
    }

    try
    {
        for (const auto buffId : mBuffs)
        {
            auto entry = std::find(buffs.begin(), buffs.end(), buffId);
            if (entry == mBuffs.end())
            {
                const std::string message = "buff lost " + std::to_string(buffId);
                mChatManager->AddChatMessage(1, false, message.c_str());
            }
        }
    }
    catch (...)
    {
        mChatManager->AddChatMessage(1, false, "error");
    }*/

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