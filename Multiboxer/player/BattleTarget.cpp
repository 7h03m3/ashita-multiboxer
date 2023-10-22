#include "BattleTarget.h"

using namespace player;

BattleTarget::BattleTarget()
    : mServerId(0)
{}

void BattleTarget::set(const uint32_t serverId)
{
    mServerId = serverId;
}

void BattleTarget::clear()
{
    mServerId = 0;
}

bool BattleTarget::isValid() const
{
    return mServerId != 0;
}

uint32_t BattleTarget::getServerId() const
{
    return mServerId;
}
