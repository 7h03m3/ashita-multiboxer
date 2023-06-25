#pragma once

#include "player/Player.h"
#include "player/PartyMember.h"

#include <map>

class PlayerManager
{
public:
    PlayerManager(IAshitaCore* ashita);

    ~PlayerManager();

    bool isPartyMember(uint32_t id) const;

    player::PartyMember* addPartyMember(uint32_t id, uint16_t index, const std::string& name);

    player::PartyMember* getPartyMember(uint32_t id);

    void updatePartyMemberList();

    player::Player& getPlayer();

private:
    typedef std::map<uint32_t, player::PartyMember*> PartyMemberList;
    player::Player mPlayer;
    PartyMemberList mPartyMembers;
    IChatManager* mChatManager;
    IParty* mPartyManager;

    void updateZones();

    uint8_t getPartyMemberPartyIndex(uint32_t id) const;

    static bool isPartyMember(uint32_t id, const PartyMemberList& list);
};
