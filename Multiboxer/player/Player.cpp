#include "Player.h"
#include <sstream>
#include <cmath>
#include <numbers>
#include <math.h>

using namespace player;

Player::Player(IAshitaCore* ashita)
    : PlayerBase(ashita->GetMemoryManager()->GetParty()->GetMemberServerId(0), std::string(ashita->GetMemoryManager()->GetParty()->GetMemberName(0)), ashita->GetChatManager())
    , mPlayer(ashita->GetMemoryManager()->GetPlayer())
    , mEntity(ashita->GetMemoryManager()->GetEntity())
    , mTarget(ashita->GetMemoryManager()->GetTarget())
    , mFollowManager(ashita->GetMemoryManager()->GetAutoFollow())
{
}

void Player::follow(const std::string& target)
{
    if (target == getName())
    {
        return;
    }

    const std::string command = "/follow " + target;
    mChatManager->QueueCommand(static_cast<int32_t>(Ashita::CommandMode::Menu), command.c_str());
}

void Player::stopMove()
{
    mFollowManager->SetIsAutoRunning(0);
}

void Player::turnAround(bool reverse)
{
    const uint8_t isActive     = mTarget->GetIsSubTargetActive();
    const uint32_t targetIndex = mTarget->GetTargetIndex(isActive);
    const uint32_t playerIndex = getIndex();
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
