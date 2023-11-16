#include "Player.h"
#include "jobs/RuneFencer.h"
#include "jobs/Bard.h"
#include "jobs/Corsair.h"
#include "jobs/WhiteMage.h"
#include "jobs/Geomancer.h"
#include "jobs/Samurai.h"

using namespace player;

Player::Player(IAshitaCore& ashita, TaskQueue& taskQueue, ChatManager& chatManager, PartyManager& partyManager)
    : PlayerBase(ashita.GetMemoryManager()->GetParty()->GetMemberServerId(0), std::string(ashita.GetMemoryManager()->GetParty()->GetMemberName(0)), chatManager)
    , mAshitaCore(ashita)
    , mMoveController(ashita, *this)
    , mInteractionManager(ashita, taskQueue, mMoveController, *this, chatManager, partyManager)
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
    if ((mainJob == 0) || ((mainJob == getMainJob()) && (subJob == getSubJob())))
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

void Player::onCommand(const commands::String& command)
{
    if (command.match("follow") && command.hasArg(1))
    {
        mInteractionManager.follow(command.getArg(1));
        return;
    }
    else if (command.match("stopMove"))
    {
        mInteractionManager.stopMove();
        return;
    }
    else if (command.match("look", "away") || command.match("look", "face"))
    {
        const bool reverse = (command.getArg(1) == "face");
        mInteractionManager.turnAround(reverse);
        return;
    }
    else if (command.match("moveTo") && command.hasArg(1))
    {
        const float distance  = std::stof(command.getArg(1));
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

    mInteractionManager.printError("player command not found");
}

void Player::onJobCommand(const commands::String& command)
{
    if (!mJob->onCommand(command))
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

void Player::onCorsairRoll(shared::Ability ability, uint64_t rollNumber)
{
    mJob->onCorsairRoll(ability, rollNumber);
}
