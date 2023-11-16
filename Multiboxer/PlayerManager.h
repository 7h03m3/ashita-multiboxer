#pragma once

#include "player/Player.h"

#include "player/InteractionManager.h"
#include "PartyManager.h"

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
    ChatManager& mChatManager;
    IParty* mParty;
    PartyManager mPartyManager;
    player::Player mPlayer;
};
