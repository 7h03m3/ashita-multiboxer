#pragma once

#include "PlayerBase.h"

namespace player
{
    class Player : public PlayerBase
    {
    public:
        Player(IAshitaCore* ashita);

        void follow(const std::string& target);

        void stopMove();

        void turnAround(bool reverse);

    private:
        IPlayer* mPlayer;
        IEntity* mEntity;
        ITarget* mTarget;
        IAutoFollow* mFollowManager;
    };
} // namespace player