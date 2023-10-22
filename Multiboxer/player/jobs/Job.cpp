#include "Job.h"
#include "shared/BuffId.h"

using namespace player_job;

Job::Job(const Ashita::FFXI::Enums::Job jobId, const std::string& name, player::InteractionManager& interactionManager)
    : mInteractionManager(interactionManager)
    , mBattleTarget()
    , mJobId(jobId)
    , mName(name)
    , mBattleDistance(2)
    , mTargetHelper(mInteractionManager.getAshita())
{
}

Ashita::FFXI::Enums::Job Job::getId() const
{
    return mJobId;
}

const std::string& Job::getName() const
{
    return mName;
}

void Job::poll()
{
}

void Job::onBattleStart()
{
    engage(mBattleTarget.getServerId());
}

void Job::onBattleStop()
{
    disengage();
}

void Job::onMobDeath(uint32_t mobServerId)
{
    if (mBattleTarget.getServerId() != mobServerId)
    {
        return;
    }

    mBattleTarget.clear();
    onBattleStop();
}

void Job::onDisengage()
{
    if (!mBattleTarget.isValid())
    {
        return;
    }

    mBattleTarget.clear();
    onBattleStop();
}

bool Job::onCommand(const std::string& command, const std::string& argument1, const std::string& argument2)
{
    if ((command == "engage") && (!argument1.empty()))
    {
        const uint32_t serverId = mTargetHelper.getServerIdFromArgument(argument1);
        if (serverId == 0)
        {
            return true;
        }

        engage(serverId);
        return true;
    }
    else if ((command == "disengage") && (argument1.empty()))
    {
        disengage();
        return true;
    }
    else if ((command == "startBattle") && (!argument1.empty()))
    {
        const uint32_t serverId = mTargetHelper.getServerIdFromArgument(argument1);
        if (serverId == 0)
        {
            return true;
        }

        mBattleTarget.set(serverId);
        onBattleStart();
        return true;
    }
    else if ((command == "stopBattle") && (argument1.empty()))
    {
        if (!mBattleTarget.isValid())
        {
            return true;
        }

        mBattleTarget.clear();
        onBattleStop();
        return true;
    }
    else if ((command == "reposition") && (!argument1.empty()))
    {
        if (mBattleDistance == 0)
        {
            return true;
        }

        const uint32_t targetIndex = mTargetHelper.getTargetIndexFromArgument(argument1);
        mInteractionManager.moveToTarget(targetIndex, mBattleDistance);
        return true;
    }
    else if ((command == "setBattleDistance") && (!argument1.empty()))
    {
        mBattleDistance = std::stof(argument1);
        mInteractionManager.printMessage("battle distance set to " + std::to_string(mBattleDistance));
        return true;
    }
    else if ((command == "getBattleTarget") && (argument1.empty()))
    {
        if (mBattleTarget.isValid())
        {
            mInteractionManager.printMessage("battle target = " + std::to_string(mBattleTarget.getServerId()));
        }
        else
        {
            mInteractionManager.printError("no battle target");
        }
        return true;
    }
    else if (onJobCommand(command, argument1, argument1))
    {
        return true;
    }

    return false;
}

bool Job::onJobCommand(const std::string& /*command*/, const std::string& /*argument1*/, const std::string& /*argument2*/)
{
    return false;
}

void Job::engage(const uint32_t serverId)
{
    std::string command = "/attack " + std::to_string(serverId);
    mInteractionManager.queueCommand(command);
}

void Job::disengage()
{
    mInteractionManager.queueCommand("/attackoff");
}
