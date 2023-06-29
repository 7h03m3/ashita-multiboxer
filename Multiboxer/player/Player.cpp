#include "Player.h"

using namespace player;

Player::Player(IAshitaCore* ashita)
    : PlayerBase(ashita->GetMemoryManager()->GetParty()->GetMemberServerId(0), std::string(ashita->GetMemoryManager()->GetParty()->GetMemberName(0)), ashita->GetChatManager())
    , mMoveController(ashita, *this)
{
}

void Player::poll()
{
    mMoveController.poll();
}

void Player::moveToTarget(const uint32_t targetIndex, const float targetDistance)
{
    mMoveController.moveToTarget(targetIndex, targetDistance);
}

void Player::follow(const std::string& target)
{
    mMoveController.follow(target);
}

void Player::stopMove()
{
    mMoveController.stopMove();
}

void Player::turnAround(bool reverse)
{
    mMoveController.turnAround(reverse);
}
