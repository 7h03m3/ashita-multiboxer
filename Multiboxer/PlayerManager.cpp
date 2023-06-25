#include "PlayerManager.h"

PlayerManager::PlayerManager(IAshitaCore* ashita)
    : mPlayer(ashita)
    , mPartyMembers()
    , mChatManager(ashita->GetChatManager())
    , mPartyManager(ashita->GetMemoryManager()->GetParty())
{
}

PlayerManager::~PlayerManager()
{
    for (auto it = mPartyMembers.begin(); it != mPartyMembers.end(); it++)
    {
        delete it->second;
    }
}

player::Player& PlayerManager::getPlayer()
{
    return mPlayer;
}

player::PartyMember* PlayerManager::addPartyMember(uint32_t id, uint16_t index, const std::string& name)
{
    const uint8_t partyIndex       = getPartyMemberPartyIndex(id);
    player::PartyMember* newMember = new player::PartyMember(id, index, name, partyIndex, mChatManager);
    mPartyMembers.insert(std::pair(id, newMember));

    std::string message = "new party member " + name + " " + std::to_string(id) + " " + std::to_string(partyIndex);
    mChatManager->AddChatMessage(1, false, message.c_str());

    return newMember;
}

player::PartyMember* PlayerManager::getPartyMember(uint32_t id)
{
    return mPartyMembers[id];
}

bool PlayerManager::isPartyMember(uint32_t id) const
{
    return isPartyMember(id, mPartyMembers);
}

bool PlayerManager::isPartyMember(uint32_t id, const PartyMemberList& list)
{
    return list.count(id) != 0;
}

void PlayerManager::updatePartyMemberList()
{
    const size_t memberCount = static_cast<size_t>(mPartyManager->GetAlliancePartyMemberCount1()) - 1;

    if (memberCount < mPartyMembers.size())
    {
        PartyMemberList members = mPartyMembers;

        for (size_t i = 0; i < memberCount; i++)
        {
            const size_t memberIndex = i + 1;
            const uint32_t id        = mPartyManager->GetMemberServerId(memberIndex);
            if (isPartyMember(id, members))
            {
                members.erase(id);
            }
        }

        for (auto it = members.begin(); it != members.end(); it++)
        {
            const uint32_t id           = it->first;
            player::PartyMember* member = mPartyMembers[id];
            mPartyMembers.erase(id);
            delete member;
        }
    }
    else if (memberCount > mPartyMembers.size())
    {
        for (size_t i = 0; i < memberCount; i++)
        {
            const size_t memberIndex = i + 1;
            const uint32_t id        = mPartyManager->GetMemberServerId(memberIndex);
            if (!isPartyMember(id))
            {
                const uint16_t index = mPartyManager->GetMemberIndex(memberIndex);
                const std::string name(mPartyManager->GetMemberName(memberIndex));
                const uint16_t zone            = mPartyManager->GetMemberZone(memberIndex);
                player::PartyMember* newMember = addPartyMember(id, index, name);
                newMember->setZone(zone);
            }
        }
    }

    updateZones();
}

void PlayerManager::updateZones()
{
    mPlayer.setZone(mPartyManager->GetMemberZone(0));

    for (auto it = mPartyMembers.begin(); it != mPartyMembers.end(); it++)
    {
        const uint16_t zone = mPartyManager->GetMemberZone(it->second->getPartyIndex());
        it->second->setZone(zone);
    }
}

uint8_t PlayerManager::getPartyMemberPartyIndex(uint32_t id) const
{
    const int8_t memberCount = mPartyManager->GetAlliancePartyMemberCount1() - 1;
    for (int8_t i = 0; i < memberCount; i++)
    {
        const int8_t partyIndex = i + 1;
        const uint32_t serverId = mPartyManager->GetMemberServerId(partyIndex);
        if (serverId == id)
        {
            return partyIndex;
        }
    }

    return 0;
}
