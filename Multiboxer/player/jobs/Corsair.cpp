#include "Corsair.h"

using namespace player_job;

Corsair::Corsair(player::InteractionManager& interactionManager)
    : Job(Ashita::FFXI::Enums::Job::Corsair, "Corsair", interactionManager)
{}

void Corsair::poll()
{}

void Corsair::onBattleStart()
{
    engage(mBattleTarget.getServerId());
}

void Corsair::onBattleStop()
{
    disengage();
}

bool Corsair::onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2)
{
    return false;
}