#include "Samurai.h"

using namespace player_job;

Samurai::Samurai(player::InteractionManager& interactionManager)
    : Job(Ashita::FFXI::Enums::Job::Samurai, "Samurai", interactionManager)
{}

void Samurai::poll()
{}

void Samurai::onBattleStart()
{
    engage(mBattleTarget.getServerId());
}

void Samurai::onBattleStop()
{
    disengage();
}

bool Samurai::onJobCommand(const commands::String& /*command*/)
{
    return false;
}
