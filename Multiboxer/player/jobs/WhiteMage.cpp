#include "WhiteMage.h"

using namespace player_job;

WhiteMage::WhiteMage(player::InteractionManager& interactionManager)
    : Job(Ashita::FFXI::Enums::Job::WhiteMage, "WhiteMage", interactionManager)
{}

void WhiteMage::poll()
{}

void WhiteMage::onBattleStart()
{}

void WhiteMage::onBattleStop()
{}

bool WhiteMage::onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2)
{
    return false;
}
