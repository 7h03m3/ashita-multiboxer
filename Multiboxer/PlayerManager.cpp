#include "PlayerManager.h"

PlayerManager::PlayerManager()
    : mPlayer()
{
}

player::Player& PlayerManager::getPlayer()
{
    return mPlayer;
}