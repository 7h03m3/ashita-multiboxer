#include "PacketParser.h"

#include "shared/BuffId.h"
#include "packet/PlayerUpdate.h"
#include "packet/CharUpdate.h"
#include "packet/CharInfo.h"
#include "packet/PartyBuffUpdate.h"
#include "packet/PartyMemberUpdate.h"
#include "packet/Action.h"
#include "packet/TriggerAction.h"
#include "packet/JobChange.h"
#include "packet/ZoneUpdate.h"

PacketParser::PacketParser(IChatManager* chatManager, IMemoryManager* memoryManager, PlayerManager* playerManager)
    : mChatManager(chatManager)
    , mMemoryManager(memoryManager)
    , mPlayerManager(playerManager)
    , mBuffTracker(chatManager)
{
}

void PacketParser::onIncoming(uint16_t id, uint32_t size, const uint8_t* data)
{
    UNREFERENCED_PARAMETER(size);

    switch (id)
    {
        case 0x000A: // Zone update
            handleZoneUpdate(data);
            break;
        case 0x0037: // player update
            handlePlayerUpdate(data);
            break;
        case 0x00DF: // char update
            handleCharUpdate(data);
            break;
        case 0x00E2: // char info
            handleCharInfo(data);
            break;
        case 0x0076: // party status icon update
            handlePartyBuffUpdate(data);
            break;
        case 0x00DD: // party member update
            handlePartyMemberUpdate(data);
            break;
        case 0x0028: // Action
            handleAction(data, size);
            break;

        case 0x001B: // Job info
        case 0x0061: // char stats
        case 0x0067: // pet info
        case 0x0068: // pet status
        default:
            break;
    }
}

void PacketParser::onOutgoing(uint16_t id, uint32_t size, const uint8_t* data)
{
    UNREFERENCED_PARAMETER(size);

    switch (id)
    {
        case 0x001A: // Action
            handleTriggerAction(data);
            break;
        case 0x0100: // Job change
            handleJobChange(data);
            break;
        default:
            break;
    }
}

void PacketParser::handlePlayerUpdate(const uint8_t* data)
{
    const packet::PlayerUpdate* packet = reinterpret_cast<const packet::PlayerUpdate*>(data);

    std::vector<uint16_t> buffList(BuffTracker::MaxBuffCount, BuffTracker::NoBuff);

    for (size_t i = 0; i < BuffTracker::MaxBuffCount; i++)
    {
        uint16_t buffId = packet->buff[i];
        if (buffId != 0xFF)
        {
            const size_t arrayIndex    = i / 4;
            const size_t bitShiftCount = (i % 4) * 2;

            const uint16_t buffIdAddition = (packet->buffBits[arrayIndex] >> bitShiftCount) & 0x03;
            buffId                        = buffId + (buffIdAddition << 8);

            buffList.push_back(buffId);
        }
    }

    mBuffTracker.update(buffList);
}

void PacketParser::handleCharUpdate(const uint8_t* data)
{
    const packet::CharUpdate* packet = reinterpret_cast<const packet::CharUpdate*>(data);

    player::PlayerStats playerStats(packet->HP, packet->MP, packet->TP, packet->HPP, packet->MPP);

    if (mPlayerManager->getPlayer().getStats() != playerStats)
    {
        std::stringstream stringStream;

        stringStream << "[CharUpdate] ";
        stringStream << (unsigned int)packet->index << " (" << (unsigned int)packet->ID << ") ";
        stringStream << "HP=" << (unsigned int)playerStats.getHP() << " (" << (unsigned int)playerStats.getHPP() << ") ";
        stringStream << "MP=" << (unsigned int)playerStats.getMP() << " (" << (unsigned int)playerStats.getMPP() << ") ";
        stringStream << "TP=" << (unsigned int)playerStats.getTP();
        mChatManager->AddChatMessage(1, false, stringStream.str().c_str());
        mPlayerManager->getPlayer().updateStats(playerStats);
    }
}

void PacketParser::handleCharInfo(const uint8_t* data)
{
    const packet::CharInfo* packet = reinterpret_cast<const packet::CharInfo*>(data);

    player::Player& player = mPlayerManager->getPlayer();

    updatePlayerIds(packet->ID, packet->index);

    player::PlayerStats playerStats(packet->HP, packet->MP, packet->TP, packet->HPP, packet->MPP);

    if (player.getStats() != playerStats)
    {
        std::stringstream stringStream;

        stringStream << "[CharInfo] ";
        stringStream << (unsigned int)packet->index << " (" << (unsigned int)packet->ID << ") \"" << packet->name << "\" ";
        stringStream << "HP=" << (unsigned int)playerStats.getHP() << " (" << (unsigned int)playerStats.getHPP() << ") ";
        stringStream << "MP=" << (unsigned int)playerStats.getMP() << " (" << (unsigned int)playerStats.getMPP() << ") ";
        stringStream << "TP=" << (unsigned int)playerStats.getTP();
        mChatManager->AddChatMessage(1, false, stringStream.str().c_str());

        player.updateStats(playerStats);
    }
}

void PacketParser::handlePartyBuffUpdate(const uint8_t* data)
{
    const packet::PartyBuffUpdate* packet = reinterpret_cast<const packet::PartyBuffUpdate*>(data);

    std::stringstream stringStream;
    stringStream << "[PartyBuffUpdate] ";
    mChatManager->AddChatMessage(1, false, stringStream.str().c_str());
}

void PacketParser::handlePartyMemberUpdate(const uint8_t* data)
{
    const packet::PartyMemberUpdate* packet = reinterpret_cast<const packet::PartyMemberUpdate*>(data);

    if ((packet->ID == 0) || (packet->index == 0))
    {
        return;
    }

    player::Player& player = mPlayerManager->getPlayer();

    player::PlayerStats playerStats(packet->HP, packet->MP, packet->TP, packet->HPP, packet->MPP);

    std::stringstream stringStream;
    stringStream << "[PartyMemberUpdate] ";

    stringStream << (unsigned int)packet->index << " (" << (unsigned int)packet->ID << ") zone:" << packet->zone << " flags:" << packet->flags << " ";

    if (player.getStats() != playerStats)
    {
        stringStream << "HP=" << (unsigned int)playerStats.getHP() << " (" << (unsigned int)playerStats.getHPP() << ") ";
        stringStream << "MP=" << (unsigned int)playerStats.getMP() << " (" << (unsigned int)playerStats.getMPP() << ") ";
        stringStream << "TP=" << (unsigned int)playerStats.getTP();
        mChatManager->AddChatMessage(1, false, stringStream.str().c_str());

        player.updateStats(playerStats);
    }

    mChatManager->AddChatMessage(1, false, stringStream.str().c_str());
}

void PacketParser::handleAction(const uint8_t* data, uint32_t size)
{
    const packet::Action* packet = reinterpret_cast<const packet::Action*>(data);

    if (packet->actor != mPlayerManager->getPlayer().getId())
    {
        return;
    }

    std::stringstream stringStream;
    stringStream << "[Action] " << (unsigned int)size << " ";
    stringStream << " " << (unsigned int)packet->actor;
    stringStream << " category = ";

    switch (packet->category)
    {
        case 8:
            if (packet->param == 28787)
            {
                stringStream << "casting interrupted";
            }
            else
            {
                stringStream << "casting started";
            }

            break;
        case 4:
            stringStream << "casting done";
            break;
        case 6:
        {
            stringStream << "job ability";
            uint64_t rollNumber = Ashita::BinaryData::UnpackBitsBE((uint8_t*)data, 213, 17);
            stringStream << " (roll: " << (unsigned int)rollNumber << ")";
            break;
        }
        default:
            stringStream << "not used (" << std::to_string(packet->category) << ")";
            break;
    }

    stringStream << " recast = " << (unsigned int)packet->recast;
    mChatManager->AddChatMessage(1, false, stringStream.str().c_str());
}

void PacketParser::handleTriggerAction(const uint8_t* data)
{
    const packet::TriggerAction* packet = reinterpret_cast<const packet::TriggerAction*>(data);

    switch (packet->category)
    {
        case 0x02:
            mChatManager->AddChatMessage(1, false, "engage");
            break;
        case 0x04:
            mChatManager->AddChatMessage(1, false, "disengage");
            break;
        default:
            break;
    }
}

void PacketParser::handleJobChange(const uint8_t* data)
{
    const packet::JobChange* packet = reinterpret_cast<const packet::JobChange*>(data);

    mPlayerManager->getPlayer().setJobs(packet->mainJob, packet->subJob);
}

void PacketParser::handleZoneUpdate(const uint8_t* data)
{
    const packet::ZoneUpdate* packet = reinterpret_cast<const packet::ZoneUpdate*>(data);

    player::Player& player = mPlayerManager->getPlayer();

    updatePlayerIds(packet->playerId, packet->playerIndex);

    player.setZone(packet->zone);
}

void PacketParser::updatePlayerIds(uint32_t playerId, uint16_t playerIndex)
{
    player::Player& player = mPlayerManager->getPlayer();

    if (player.getId() != playerId)
    {
        mChatManager->AddChatMessage(1, false, "player id changed");
        player.setId(playerId);
    }

    if (player.getIndex() != playerIndex)
    {
        mChatManager->AddChatMessage(1, false, "player index changed ");
        player.setIndex(playerIndex);
    }
}
