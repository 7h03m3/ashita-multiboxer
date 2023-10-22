#include "PartyMember.h"

using namespace player;

PartyMember::PartyMember(uint32_t id, uint16_t index, const std::string& name, uint8_t partyIndex, ChatManager& chatManager)
    : PlayerBase(id, index, name, chatManager)
    , mPartyIndex(partyIndex)
{
}

uint8_t PartyMember::getPartyIndex() const
{
    return mPartyIndex;
}
