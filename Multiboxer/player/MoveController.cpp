#include "MoveController.h"

#include <numbers>

using namespace player;

MoveController::MoveController(IAshitaCore& ashita, PlayerBaseInterface& player)
    : mPlayer(player)
    , mEntity(ashita.GetMemoryManager()->GetEntity())
    , mFollowManager(ashita.GetMemoryManager()->GetAutoFollow())
    , mChatManager(ashita.GetChatManager())
    , mTarget(ashita.GetMemoryManager()->GetTarget())
    , mMoveTargetIndex(0)
    , mMoveTargetDistance(0)
    , mMoveTargetAway(false)
{
}

void MoveController::poll()
{
    if (mMoveTargetIndex != 0)
    {
        const float distance   = getDistance(mMoveTargetIndex);
        const bool stopMoveing = (mMoveTargetAway ? distance > mMoveTargetDistance : distance < mMoveTargetDistance);

        if (stopMoveing)
        {
            stopMove();
        }
        else
        {
            updateMoveDirection(mMoveTargetIndex, mPlayer.getIndex(), mMoveTargetAway);
        }
    }
}

void MoveController::follow(const std::string& target)
{
    if (target == mPlayer.getName())
    {
        return;
    }

    const std::string command = "/follow " + target;
    mChatManager->QueueCommand(static_cast<int32_t>(Ashita::CommandMode::Menu), command.c_str());
}

void MoveController::moveToTarget(const uint32_t targetIndex, const float targetDistance)
{
    const uint32_t playerIndex = mPlayer.getIndex();
    if ((targetIndex == 0) || (playerIndex == 0) || (playerIndex == targetIndex))
    {
        return;
    }

    const float distance = getDistance(targetIndex);
    mMoveTargetAway      = distance < targetDistance;
    if (distance)
    {
        mMoveTargetIndex    = targetIndex;
        mMoveTargetDistance = targetDistance;
        updateMoveDirection(mMoveTargetIndex, playerIndex, mMoveTargetAway);
    }
}

void MoveController::stopMove()
{
    mMoveTargetIndex = 0;
    mFollowManager->SetIsAutoRunning(0);
}

void MoveController::turnAround(bool reverse)
{
    const uint8_t isActive     = mTarget->GetIsSubTargetActive();
    const uint32_t targetIndex = mTarget->GetTargetIndex(isActive);
    const uint32_t playerIndex = mPlayer.getIndex();
    if ((playerIndex == 0) || (targetIndex == playerIndex))
    {
        return;
    }

    auto targetEntity = mEntity->GetRawEntity(targetIndex);
    auto playerEntity = mEntity->GetRawEntity(playerIndex);

    if ((targetEntity == nullptr) || (playerEntity == nullptr))
    {
        return;
    }

    const float playerX = mEntity->GetLocalPositionX(playerIndex);
    const float playerY = mEntity->GetLocalPositionY(playerIndex);
    const float targetX = mEntity->GetLocalPositionX(targetIndex);
    const float targetY = mEntity->GetLocalPositionY(targetIndex);

    float angle = (atan2((targetY - playerY), (targetX - playerX)) * 180 / std::numbers::pi_v<float>)*-1.0;

    if (reverse == false)
    {
        angle = (angle + 180);
    }

    const float radian = angle * std::numbers::pi_v<float> / 180;

    if (radian)
    {
        float* floatPtr = reinterpret_cast<float*>(playerEntity->ActorPointer + 0x48);
        floatPtr[0]     = radian;
    }
}

float MoveController::getDistance(const uint32_t targetIndex)
{
    return sqrt(mEntity->GetDistance(targetIndex));
}

void MoveController::updateMoveDirection(const uint32_t targetIndex, const uint32_t playerIndex, bool moveAway)
{
    const float playerX = mEntity->GetLocalPositionX(playerIndex);
    const float playerY = mEntity->GetLocalPositionY(playerIndex);
    const float targetX = mEntity->GetLocalPositionX(targetIndex);
    const float targetY = mEntity->GetLocalPositionY(targetIndex);
    float vectorX       = targetX - playerX;
    float vectorY       = targetY - playerY;

    if (moveAway)
    {
        vectorX = vectorX * -1;
        vectorY = vectorY * -1;
    }

    mFollowManager->SetFollowTargetServerId(0);
    mFollowManager->SetFollowTargetIndex(0);
    mFollowManager->SetFollowDeltaX(vectorX);
    mFollowManager->SetFollowDeltaY(vectorY);
    mFollowManager->SetFollowDeltaZ(0);
    mFollowManager->SetIsAutoRunning(1);
}
