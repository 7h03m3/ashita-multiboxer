#pragma once

#include "PlayerBase.h"
#include "MoveController.h"

namespace player
{
    class Player : public PlayerBase
    {
    public:
        Player(IAshitaCore* ashita);

        void poll();

        void follow(const std::string& target);

        void moveToTarget(uint32_t targetIndex, float targetDistance);

        void stopMove();

        void turnAround(bool reverse);

    private:
        MoveController mMoveController;
    };
} // namespace player