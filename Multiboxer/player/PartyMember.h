#pragma once

#include "PlayerBase.h"

namespace player
{
    class PartyMember : public PlayerBase
    {
    public:
        PartyMember(uint32_t id, uint16_t index, const std::string& name, uint8_t partyIndex, ChatManager& chatManager);

        uint8_t getPartyIndex() const;

    private:
        uint8_t mPartyIndex;
    };
} // namespace player
