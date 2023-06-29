#pragma once

#include "Ashita.h"
#include "PlayerBaseInterface.h"

namespace player
{
    class MoveController
    {
    public:
        MoveController(IAshitaCore* ashita, PlayerBaseInterface& player);

        void poll();

        void follow(const std::string& target);

        void moveToTarget(uint32_t targetIndex, float targetDistance);

        void stopMove();

        void turnAround(bool reverse);

    private:
        PlayerBaseInterface& mPlayer;
        IEntity* mEntity;
        IAutoFollow* mFollowManager;
        IChatManager* mChatManager;
        ITarget* mTarget;
        uint32_t mMoveTargetIndex;
        float mMoveTargetDistance;
        bool mMoveTargetAway;

        float getDistance(uint32_t targetIndex);
        void updateMoveDirection(uint32_t targetIndex, uint32_t playerIndex, bool moveAway = false);
    };
} // namespace player