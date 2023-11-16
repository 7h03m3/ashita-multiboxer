#pragma once

#include "ChatManager.h"
#include "player/PartyMember.h"

#include <map>
#include <vector>

class PartyManager
{
public:
    typedef std::map<uint32_t, player::PartyMember*> PartyMemberList;

    PartyManager(IAshitaCore& ashita, ChatManager& chatManager);

    ~PartyManager();

    bool isMember(uint32_t id) const;

    player::PartyMember* add(uint32_t id, uint16_t index, const std::string& name);

    player::PartyMember* get(uint32_t id);

    PartyMemberList::const_iterator begin() const;

    PartyMemberList::const_iterator end() const;

    void update();

private:
    PartyMemberList mPartyMembers;
    ChatManager& mChatManager;
    IParty* mPartyManager;

    void updateZones();

    uint8_t getMemberIndex(uint32_t id) const;

    static bool isMember(uint32_t id, const PartyMemberList& list);
};
