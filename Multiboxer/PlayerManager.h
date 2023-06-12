#pragma once

#include "player/Player.h"

class PlayerManager
{
public:
    PlayerManager();

    player::Player& getPlayer();

private:
    player::Player mPlayer;
};
