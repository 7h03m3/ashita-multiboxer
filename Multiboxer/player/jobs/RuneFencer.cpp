#include "RuneFencer.h"
#include "helper/TargetMe.h"
#include "helper/TargetBattle.h"

#include <ffxi/enums.h>

using namespace player_job;

RuneFencer::RuneFencer(player::InteractionManager& interactionManager)
    : Job(Ashita::FFXI::Enums::Job::RuneFencer, "RuneFencer", interactionManager)
    , mRuneList(3, interactionManager)
    , mBuffs(4, interactionManager)
    , mEnmitySpells(interactionManager)
    , mEnmityAoeSpells(interactionManager)
{
    mRuneList.add(shared::Ignis);
    mRuneList.add(shared::Lux);
    mRuneList.add(shared::Flabra);

    mBuffs.add(shared::SpellId::Cocoon);
    mBuffs.add(shared::SpellId::Phalanx);
    mBuffs.add(shared::SpellId::Crusade);
    mBuffs.add(shared::SpellId::Temper);

    mEnmitySpells.add(shared::SpellId::Flash, TargetBattle());
    mEnmitySpells.add(shared::SpellId::Foil, TargetMe());
    mEnmitySpells.add(shared::SpellId::Jettatura, TargetBattle());

    mEnmityAoeSpells.add(shared::SpellId::Foil, TargetMe());
    mEnmityAoeSpells.add(shared::SpellId::SheepSong, TargetBattle());
    mEnmityAoeSpells.add(shared::SpellId::Soporific, TargetBattle());
    mEnmityAoeSpells.add(shared::SpellId::GeistWall, TargetBattle());
}

void RuneFencer::poll()
{
    if (mBuffs.isRefreshRunning())
    {
        mBuffs.doRefresh();
        if (!mBuffs.isRefreshRunning())
        {
            mInteractionManager.printMessage("buff refresh done");
        }
    }
    else if (mRuneList.isRefreshRunning())
    {
        mRuneList.doRefresh();
        if (!mRuneList.isRefreshRunning())
        {
            mInteractionManager.printMessage("rune refresh done");
        }
    }
}

void RuneFencer::onBattleStart()
{
    engage(mBattleTarget.getServerId());
}

void RuneFencer::onBattleStop()
{
    disengage();
}

bool RuneFencer::onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2)
{
    if (command == "runeRefresh")
    {
        if (mRuneList.isRefreshRunning())
        {
            mInteractionManager.printError("rune refresh already running");
        }
        else
        {
            mInteractionManager.printMessage("rune refresh started");
            mRuneList.startRefresh();
        }

        return true;
    }
    else if (command == "rune")
    {
        if (mRuneList.isRefreshRunning())
        {
            mInteractionManager.printError("rune refresh is running");
        }
        else
        {
            mRuneList.refreshNext();
        }

        return true;
    }
    else if (command == "buffRefresh")
    {
        if (mBuffs.isRefreshRunning())
        {
            mInteractionManager.printError("buff refresh already running");
        }
        else
        {
            mInteractionManager.printMessage("buff refresh started");
            mBuffs.startRefresh();
        }

        return true;
    }
    else if (command == "buff")
    {
        if (mBuffs.isRefreshRunning())
        {
            mInteractionManager.printError("buff refresh is running");
        }
        else
        {
            mBuffs.refreshNext();
        }

        return true;
    }
    else if (command == "enmity")
    {
        if (mBattleTarget.isValid())
        {
            mEnmitySpells.cast(mBattleTarget.getServerId());
        }
        else
        {
            mInteractionManager.printError("no battle target");
        }

        return true;
    }
    else if (command == "enmityAoe")
    {
        if (mBattleTarget.isValid())
        {
            mEnmityAoeSpells.cast(mBattleTarget.getServerId());
        }
        else
        {
            mInteractionManager.printError("no battle target");
        }

        return true;
    }

    return false;
}
