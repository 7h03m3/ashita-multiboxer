#pragma once

#include "player/Player.h"
#include "player/PartyMember.h"
#include "player/InteractionManager.h"
#include "ChatManager.h"

#include <map>
#include <vector>
#include <string>

class PlayerManager
{
public:
    static const size_t MaxPartyMemberCount = 5;

    PlayerManager(IAshitaCore& ashita, TaskQueue& taskQueue, ChatManager& chatManager);

    ~PlayerManager();

    bool isPartyMember(uint32_t id) const;

    player::PartyMember* addPartyMember(uint32_t id, uint16_t index, const std::string& name);

    player::PartyMember* getPartyMember(uint32_t id);

    std::vector<std::string> getActivePlayerNames();

    void updatePartyMemberList();

    player::Player& getPlayer();

private:
    typedef std::map<uint32_t, player::PartyMember*> PartyMemberList;
    PartyMemberList mPartyMembers;
    ChatManager& mChatManager;
    IParty* mPartyManager;
    player::Player mPlayer;

    void updateZones();

    uint8_t getPartyMemberPartyIndex(uint32_t id) const;

    static bool isPartyMember(uint32_t id, const PartyMemberList& list);
};
