#include "PlayerManager.h"

PlayerManager::PlayerManager(IAshitaCore& ashita, TaskQueue& taskQueue, ChatManager& chatManager)
    : mChatManager(chatManager)
    , mParty(ashita.GetMemoryManager()->GetParty())
    , mPartyManager(ashita, chatManager)
    , mPlayer(ashita, taskQueue, chatManager, mPartyManager)
{
}

PlayerManager::~PlayerManager()
{
}

player::Player& PlayerManager::getPlayer()
{
    return mPlayer;
}

player::PartyMember* PlayerManager::addPartyMember(const uint32_t id, const uint16_t index, const std::string& name)
{
    return mPartyManager.add(id, index, name);
}

player::PartyMember* PlayerManager::getPartyMember(const uint32_t id)
{
    return mPartyManager.get(id);
}

bool PlayerManager::isPartyMember(uint32_t id) const
{
    return mPartyManager.isMember(id);
}

void PlayerManager::updatePartyMemberList()
{
    mPartyManager.update();
    mPlayer.setZone(mParty->GetMemberZone(0));
}

std::vector<std::string> PlayerManager::getActivePlayerNames()
{
    std::vector<std::string> list;

    list.push_back(mPlayer.getName());
    const uint16_t playerZone = mPlayer.getZone();

    for (auto it = mPartyManager.begin(); it != mPartyManager.end(); it++)
    {
        if (playerZone == it->second->getZone())
        {
            list.push_back(it->second->getName());
        }
    }

    return list;
}
