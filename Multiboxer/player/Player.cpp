#include "Player.h"
#include "jobs/RuneFencer.h"
#include "jobs/Bard.h"
#include "jobs/Corsair.h"
#include "jobs/WhiteMage.h"
#include "jobs/Geomancer.h"
#include "jobs/Samurai.h"

using namespace player;

Player::Player(IAshitaCore& ashita, TaskQueue& taskQueue, ChatManager& chatManager)
    : PlayerBase(ashita.GetMemoryManager()->GetParty()->GetMemberServerId(0), std::string(ashita.GetMemoryManager()->GetParty()->GetMemberName(0)), chatManager)
    , mAshitaCore(ashita)
    , mMoveController(ashita, *this)
    , mInteractionManager(ashita, taskQueue, mMoveController, *this, chatManager)
    , mJob(new player_job::Job(Ashita::FFXI::Enums::Job::None, "Unknown", mInteractionManager))
{
}

Player::~Player()
{
    delete mJob;
}

void Player::poll()
{
    mMoveController.poll();
    mJob->poll();
}

void Player::setJobs(uint8_t mainJob, uint8_t subJob)
{
    if ((mainJob == getMainJob()) && (subJob == getSubJob()))
    {
        return;
    }

    PlayerBase::setJobs(mainJob, subJob);

    const Ashita::FFXI::Enums::Job jobId = static_cast<Ashita::FFXI::Enums::Job>(mainJob);

    delete mJob;

    switch (jobId)
    {
        case Ashita::FFXI::Enums::Job::RuneFencer:
            mJob = new player_job::RuneFencer(mInteractionManager);
            break;
        case Ashita::FFXI::Enums::Job::WhiteMage:
            mJob = new player_job::WhiteMage(mInteractionManager);
            break;
        case Ashita::FFXI::Enums::Job::Bard:
            mJob = new player_job::Bard(mInteractionManager);
            break;
        case Ashita::FFXI::Enums::Job::Corsair:
            mJob = new player_job::Corsair(mInteractionManager);
            break;
        case Ashita::FFXI::Enums::Job::Geomancer:
            mJob = new player_job::Geomancer(mInteractionManager);
            break;
        case Ashita::FFXI::Enums::Job::Samurai:
            mJob = new player_job::Samurai(mInteractionManager);
            break;
        default:
            mJob = new player_job::Job(Ashita::FFXI::Enums::Job::None, "Unknown", mInteractionManager);
            break;
    }

    mInteractionManager.printMessage("[" + getName() + "] job changed to " + mJob->getName());
}

void Player::onCommand(const std::string& command, const std::string& argument1, const std::string& argument2)
{
    if ((command == "follow") && (!argument1.empty()))
    {
        mInteractionManager.follow(argument1);
        return;
    }
    else if (command == "stopMove")
    {
        mInteractionManager.stopMove();
        return;
    }
    else if ((command == "look") && ((argument1 == "away") || (argument1 == "face")))
    {
        const bool reverse = (argument1 == "face");
        mInteractionManager.turnAround(reverse);
        return;
    }
    else if (command == "moveTo")
    {
        if (!argument1.empty() && argument2.empty())
        {
            const float distance  = std::stof(argument1);
            const uint32_t target = mAshitaCore.GetMemoryManager()->GetTarget()->GetTargetIndex(mAshitaCore.GetMemoryManager()->GetTarget()->GetIsSubTargetActive());
            if (target == 0)
            {
                mInteractionManager.printError("target not found");
            }
            else
            {
                mInteractionManager.moveToTarget(target, distance);
            }

            return;
        }
    }

    mInteractionManager.printError("player command not found");
}

void Player::onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2)
{
    if (!mJob->onCommand(command, argument1, argument2))
    {
        mInteractionManager.printError("job command not found");
    }
}

void Player::onMobDeath(const uint32_t mobServerId)
{
    mJob->onMobDeath(mobServerId);
}

void Player::onDisengage()
{
    mJob->onDisengage();
}
