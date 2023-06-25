#pragma once

#include <Ashita.h>
#include <cstdint>
#include "PlayerManager.h"
#include "player/PlayerStats.h"

class PacketParser
{
public:
    PacketParser(IChatManager* chatManager, IMemoryManager* memoryManager, PlayerManager* playerManager);

    void onIncoming(uint16_t id, uint32_t size, const uint8_t* data);

    void onOutgoing(uint16_t id, uint32_t size, const uint8_t* data);

private:
    IChatManager* mChatManager;
    IMemoryManager* mMemoryManager;
    PlayerManager* mPlayerManager;

    void handlePlayerUpdate(const uint8_t* data);
    void handleCharUpdate(const uint8_t* data);
    void handleCharInfo(const uint8_t* data);
    void handlePartyBuffUpdate(const uint8_t* data);
    void handlePartyMemberUpdate(const uint8_t* data);
    void handleAction(const uint8_t* data);
    void handleTriggerAction(const uint8_t* data);
    void handleJobChange(const uint8_t* data);
    void handleZoneUpdate(const uint8_t* data);

    void printPacket(uint32_t size, const uint8_t* data);
};
