#include "PartyManager.h"

PartyManager::PartyManager(IAshitaCore& ashita, ChatManager& chatManager)
    : mPartyMembers()
    , mChatManager(chatManager)
    , mPartyManager(ashita.GetMemoryManager()->GetParty())
{
}

PartyManager::~PartyManager()
{
    for (auto it = mPartyMembers.begin(); it != mPartyMembers.end(); it++)
    {
        delete it->second;
    }
}

PartyManager::PartyMemberList::const_iterator PartyManager::begin() const
{
    return mPartyMembers.begin();
}

PartyManager::PartyMemberList::const_iterator PartyManager::end() const
{
    return mPartyMembers.end();
}

bool PartyManager::isMember(const uint32_t id) const
{
    return isMember(id, mPartyMembers);
}

player::PartyMember* PartyManager::add(const uint32_t id, const uint16_t index, const std::string& name)
{
    const uint8_t partyIndex       = getMemberIndex(id);
    player::PartyMember* newMember = new player::PartyMember(id, index, name, partyIndex, mChatManager);
    mPartyMembers.insert(std::pair(id, newMember));

    mChatManager.printMessage("new party member " + name + " " + std::to_string(id) + " " + std::to_string(partyIndex));

    return newMember;
}

player::PartyMember* PartyManager::get(const uint32_t id)
{
    return mPartyMembers[id];
}

void PartyManager::update()
{
    const size_t memberCount = static_cast<size_t>(mPartyManager->GetAlliancePartyMemberCount1()) - 1;

    if (memberCount < mPartyMembers.size())
    {
        PartyMemberList members = mPartyMembers;

        for (size_t i = 0; i < memberCount; i++)
        {
            const size_t memberIndex = i + 1;
            const uint32_t id        = mPartyManager->GetMemberServerId(memberIndex);
            if (isMember(id, members))
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
            if (!isMember(id))
            {
                const uint16_t index = mPartyManager->GetMemberIndex(memberIndex);
                const std::string name(mPartyManager->GetMemberName(memberIndex));

                if ((index != 0) && (name.size() != 0))
                {
                    const uint16_t zone            = mPartyManager->GetMemberZone(memberIndex);
                    player::PartyMember* newMember = add(id, index, name);
                    newMember->setZone(zone);
                }
            }
        }
    }

    updateZones();
}

uint8_t PartyManager::getMemberIndex(const uint32_t id) const
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

void PartyManager::updateZones()
{
    for (auto it = mPartyMembers.begin(); it != mPartyMembers.end(); it++)
    {
        const uint16_t zone = mPartyManager->GetMemberZone(it->second->getPartyIndex());
        it->second->setZone(zone);
    }
}

bool PartyManager::isMember(const uint32_t id, const PartyMemberList& list)
{
    return list.count(id) != 0;
}