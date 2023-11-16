#include "Corsair.h"

using namespace player_job;

Corsair::Corsair(player::InteractionManager& interactionManager)
    : Job(Ashita::FFXI::Enums::Job::Corsair, "Corsair", interactionManager)
    , mRollList(interactionManager)
{
    mRollList.add(shared::AbilityId::ChaosRoll);
    mRollList.add(shared::AbilityId::SamuraiRoll);
}

void Corsair::poll()
{
    if (mInteractionManager.queueHasTasks())
    {
        return;
    }

    if (mRollList.isRefreshRunning())
    {
        mRollList.doRefresh();
        if (!mRollList.isRefreshRunning())
        {
            mInteractionManager.printMessage("roll refresh done");
        }
    }
}

void Corsair::onCorsairRoll(shared::Ability ability, uint64_t rollNumber)
{
    mRollList.setRoll(ability, rollNumber);
}

void Corsair::onBattleStart()
{
    engage(mBattleTarget.getServerId());
}

void Corsair::onBattleStop()
{
    disengage();
}

bool Corsair::onJobCommand(const commands::String& command)
{
    if (command.match("show"))
    {
        const size_t rollCount = mRollList.getSize();
        for (size_t i = 0; i < rollCount; i++)
        {
            mInteractionManager.printMessage("[Roll " + std::to_string(i) + "] " + mRollList.get(i).getName());
        }
        return true;
    }
    else if (command.match("buff", "all"))
    {
        if (mRollList.isRefreshRunning())
        {
            mInteractionManager.printError("roll refresh already running");
            return true;
        }

        mRollList.startRefresh();
        mInteractionManager.printMessage("roll refresh started");

        return true;
    }
    else if (command.match("buff"))
    {
        if (mRollList.isRefreshRunning())
        {
            mInteractionManager.printError("roll refresh already running");
            return true;
        }

        mRollList.refreshNext();
        mInteractionManager.printMessage("roll started");

        return true;
    }
    else if (command.match("debuff") || command.match("debuff", "all"))
    {
        // do nothing
    }
    else if (command.match("movementSpeed"))
    {
        CorsairRoll speedUp(shared::AbilityId::BoltersRoll, mInteractionManager);

        if (!speedUp.isReady())
        {
            mInteractionManager.printError("roll not ready");
            return true;
        }

        speedUp.execute();
        return true;
    }
    else if (command.match("reset"))
    {
        mRollList.reset();
        return true;
    }
    return false;
}