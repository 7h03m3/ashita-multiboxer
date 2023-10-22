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
#include "packet/KillMessage.h"

PacketParser::PacketParser(IAshitaCore& ashita, PlayerManager& playerManager, ChatManager& chatManager, TaskQueue& taskQueue)
    : mAshita(ashita)
    , mMemoryManager(ashita.GetMemoryManager())
    , mChatManager(chatManager)
    , mPlayerManager(playerManager)
    , mTaskQueue(taskQueue)
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
        case 0x002D: // Kill message
            handleKillMessage(data);
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
            handleAction(data);
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

    mPlayerManager.getPlayer().updateBuffs(packet->buff, packet->buffBits);
    mPlayerManager.updatePartyMemberList();
}

void PacketParser::handleCharUpdate(const uint8_t* data)
{
    const packet::CharUpdate* packet = reinterpret_cast<const packet::CharUpdate*>(data);

    player::PlayerStats playerStats(packet->HP, packet->MP, packet->TP, packet->HPP, packet->MPP);
    player::Player& player = mPlayerManager.getPlayer();

    mPlayerManager.updatePartyMemberList();

    if (packet->ID == player.getId())
    {
        player.updatePlayerInfo(packet->ID, packet->index);
        player.updateStats(playerStats);

        if ((packet->mainJob != player.getMainJob()) || (packet->subJob != player.getSubJob()))
        {
            player.setJobs(packet->mainJob, packet->subJob);
        }
    }
    else if (mPlayerManager.isPartyMember(packet->ID))
    {
        mPlayerManager.getPartyMember(packet->ID)->updateStats(playerStats);
    }
}

void PacketParser::handleCharInfo(const uint8_t* data)
{
    const packet::CharInfo* packet = reinterpret_cast<const packet::CharInfo*>(data);

    std::string name(packet->name);
    player::PlayerStats playerStats(packet->HP, packet->MP, packet->TP, packet->HPP, packet->MPP);

    player::Player& player = mPlayerManager.getPlayer();

    if (packet->ID == player.getId())
    {
        player.updatePlayerInfo(packet->ID, packet->index, name);
        player.updateStats(playerStats);
    }
}

void PacketParser::handlePartyBuffUpdate(const uint8_t* data)
{
    const packet::PartyBuffUpdate* packet = reinterpret_cast<const packet::PartyBuffUpdate*>(data);

    for (size_t i = 0; i < 5; i++)
    {
        const uint32_t id = packet->partyMembers[i].ID;
        if (mPlayerManager.isPartyMember(id))
        {
            player::PartyMember* member = mPlayerManager.getPartyMember(id);
            member->updateBuffs(packet->partyMembers[i].buff, packet->partyMembers[i].buffBits);
        }
    }
}

void PacketParser::handlePartyMemberUpdate(const uint8_t* data)
{
    const packet::PartyMemberUpdate* packet = reinterpret_cast<const packet::PartyMemberUpdate*>(data);
    const std::string name(packet->name);

    if ((packet->ID == 0) || (packet->index == 0) || (name.size() == 0))
    {
        return;
    }

    player::PlayerStats playerStats(packet->HP, packet->MP, packet->TP, packet->HPP, packet->MPP);
    player::Player& player = mPlayerManager.getPlayer();

    if (packet->ID == player.getId())
    {
        //player.updatePlayerInfo(packet->ID, packet->index, name);
        player.updateStats(playerStats);
    }
    else
    {
        if (!mPlayerManager.isPartyMember(packet->ID))
        {
            mPlayerManager.addPartyMember(packet->ID, packet->index, name);
        }

        mPlayerManager.getPartyMember(packet->ID)->updateStats(playerStats);
    }
}

void PacketParser::handleAction(const uint8_t* data)
{
    const packet::Action* packet = reinterpret_cast<const packet::Action*>(data);

    if (packet->actor != mPlayerManager.getPlayer().getId())
    {
        return;
    }

    //std::stringstream stringStream;
    //stringStream << "[Action] " << (unsigned int)packet->actor << " param = " << (unsigned int)packet->param;
    //stringStream << " category = ";

    switch (packet->category)
    {
        case 8:
            if (packet->param == 28787) // Interrupted
            {
                mPlayerManager.getPlayer().setCasting(false);
            }
            else
            {
                mPlayerManager.getPlayer().setCasting(true);
            }

            break;
        case 4:
            mPlayerManager.getPlayer().setCasting(false);

            if (mTaskQueue.hasTasks() && mTaskQueue.getCurrentTask().isSpell())
            {
                mTaskQueue.getCurrentTask().setDelay(TaskQueue::SpellCooldown);
            }

            break;
        case 6:
        {
            const uint32_t abilityId = packet->param;
            mChatManager.printMessage("Ability " + std::to_string(abilityId) + " executed");
            if (mTaskQueue.hasTasks() && mTaskQueue.getCurrentTask().isSpell())
            {
                mTaskQueue.getCurrentTask().setDelay(TaskQueue::AbilityCooldown);
            }
            /* const uint32_t abilityId = packet->param;
            stringStream << "job ability " << abilityId << " ";
            uint64_t rollNumber = Ashita::BinaryData::UnpackBitsBE((uint8_t*)data, 213, 17);
            stringStream << " (roll: " << (unsigned int)rollNumber << ")";*/
            break;
        }
        default:
            //stringStream << "not used (" << std::to_string(packet->category) << ")";
            break;
    }

    //stringStream << " recast = " << (unsigned int)packet->recast;
    //mChatManager.printMessage(stringStream.str());
}

void PacketParser::handleTriggerAction(const uint8_t* data)
{
    const packet::TriggerAction* packet = reinterpret_cast<const packet::TriggerAction*>(data);

    std::stringstream stringStream;
    //stringStream << "[TriggerAction] category = " << packet->category;
    //mChatManager.printMessage(stringStream.str());

    switch (packet->category)
    {
        case 0x02:
        {
            //const std::string message = "engage " + std::to_string(mAshita.GetMemoryManager()->GetTarget()->GetServerId(0)) + " " + std::to_string(mAshita.GetMemoryManager()->GetTarget()->GetTargetIndex(0));
            //mChatManager.printMessage(message);
            break;
        }
        case 0x04:
            //mChatManager.printMessage("disengage");
            mPlayerManager.getPlayer().onDisengage();
            break;
        default:
            break;
    }
}

void PacketParser::handleJobChange(const uint8_t* data)
{
    const packet::JobChange* packet = reinterpret_cast<const packet::JobChange*>(data);

    std::stringstream stringStream;
    stringStream << "[JobChange] ";
    mChatManager.printMessage(stringStream.str());

    mPlayerManager.getPlayer().setJobs(packet->mainJob, packet->subJob);
}

void PacketParser::handleZoneUpdate(const uint8_t* data)
{
    const packet::ZoneUpdate* packet = reinterpret_cast<const packet::ZoneUpdate*>(data);

    std::stringstream stringStream;
    stringStream << "[ZoneUpdate] " << packet->playerId;
    mChatManager.printMessage(stringStream.str());

    player::Player& player = mPlayerManager.getPlayer();

    player.updatePlayerInfo(packet->playerId, packet->playerIndex);
}

void PacketParser::handleKillMessage(const uint8_t* data)
{
    const packet::KillMessage* packet = reinterpret_cast<const packet::KillMessage*>(data);

    mPlayerManager.getPlayer().onMobDeath(packet->targetId);
}

void PacketParser::printPacket(uint32_t size, const uint8_t* data)
{
    std::stringstream dataStream;

    dataStream << "packet with size = " << size << std::endl;

    for (size_t i = 0; i < size; i++)
    {
        if (i % 8 == 0)
        {
            dataStream << std::endl
                       << "[" << std::hex << std::setw(2) << std::setfill('0') << i << "] ";
        }
        dataStream << std::hex << std::setw(2) << std::setfill('0') << static_cast<unsigned int>(data[i]) << " ";
    }

    dataStream << std::endl;

    mChatManager.printMessage(dataStream.str());
}
