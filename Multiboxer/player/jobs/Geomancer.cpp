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

bool Geomancer::onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2)
{
    return false;
}