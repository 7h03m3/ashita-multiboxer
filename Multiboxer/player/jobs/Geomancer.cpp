#include "Geomancer.h"

using namespace player_job;

Geomancer::Geomancer(player::InteractionManager& interactionManager)
    : Job(Ashita::FFXI::Enums::Job::Geomancer, "Geomancer", interactionManager)
{}

void Geomancer::poll()
{}

void Geomancer::onBattleStart()
{
}

void Geomancer::onBattleStop()
{
}

bool Geomancer::onJobCommand(const commands::String& /*command*/)
{
    return false;
}