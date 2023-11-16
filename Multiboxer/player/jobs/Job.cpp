#include "Job.h"
#include "shared/BuffId.h"

using namespace player_job;

Job::Job(const Ashita::FFXI::Enums::Job jobId, const std::string& name, player::InteractionManager& interactionManager)
    : mInteractionManager(interactionManager)
    , mBattleTarget()
    , mJobId(jobId)
    , mName(name)
    , mBattleDistance(2.5)
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

bool Job::onCommand(const commands::String& command)
{
    if (command.match("engage") && command.hasArg(1))
    {
        const uint32_t serverId = mTargetHelper.getServerIdFromArgument(command.getArg(1));
        if (serverId == 0)
        {
            return true;
        }

        engage(serverId);
        return true;
    }
    else if (command.match("disengage"))
    {
        disengage();
        return true;
    }
    else if (command.match("startBattle") && command.hasArg(1))
    {
        const uint32_t serverId = mTargetHelper.getServerIdFromArgument(command.getArg(1));
        if (serverId == 0)
        {
            return true;
        }

        mBattleTarget.set(serverId);
        onBattleStart();
        return true;
    }
    else if (command.match("stopBattle"))
    {
        if (!mBattleTarget.isValid())
        {
            return true;
        }

        mBattleTarget.clear();
        onBattleStop();
        return true;
    }
    else if (command.match("reposition") && command.hasArg(1))
    {
        if (mBattleDistance == 0)
        {
            return true;
        }

        const uint32_t targetIndex = mTargetHelper.getTargetIndexFromArgument(command.getArg(1));
        mInteractionManager.moveToTarget(targetIndex, mBattleDistance);
        return true;
    }
    else if (command.match("setBattleDistance") && command.hasArg(1))
    {
        mBattleDistance = std::stof(command.getArg(1));
        mInteractionManager.printMessage("battle distance set to " + std::to_string(mBattleDistance));
        return true;
    }
    else if (command.match("getBattleTarget"))
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
    else if (onJobCommand(command))
    {
        return true;
    }

    return false;
}

bool Job::onJobCommand(const commands::String& /*command*/)
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

void Job::onCorsairRoll(shared::Ability /*ability*/, uint64_t /*rollNumber*/)
{
}

void Job::setBattleDistance(const float battleDistance)
{
    mBattleDistance = battleDistance;
}
