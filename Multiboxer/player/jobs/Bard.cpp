#include "Bard.h"

using namespace player_job;

Bard::Bard(player::InteractionManager& interactionManager)
    : Job(Ashita::FFXI::Enums::Job::Bard, "Bard", interactionManager)
    , mMaxSongs(3)
    , mStringInstrument(false)
    , mSongList(4, interactionManager)
{
    mSongList.add(shared::SpellId::MagesBallad3);
    mSongList.add(shared::SpellId::MagesBallad2);
    mSongList.add(shared::SpellId::VictoryMarch);
    setWindInstrument();
}

void Bard::poll()
{}

void Bard::onBattleStart()
{
    engage(mBattleTarget.getServerId());
}

void Bard::onBattleStop()
{
    disengage();
}

bool Bard::onJobCommand(const std::string& command, const std::string& argument1, const std::string& argument2)
{
    if (command == "songCount")
    {
        const size_t songCount = mSongList.getSongCount();
        mInteractionManager.printMessage("song count = " + std::to_string(songCount));
        return true;
    }
    else if (command == "song")
    {
        if (mSongList.isRefreshRunning())
        {
            mInteractionManager.printError("song refresh is running");
        }
        else
        {
            setInstrument();
            mSongList.refreshNext();
        }

        return true;
    }
    else if ((command == "setInstrument") && (!argument1.empty()))
    {
        if (argument1 == "string")
        {
            setStringInstrument();
        }
        else if (argument1 == "wind")
        {
            setWindInstrument();
        }
        else
        {
            mInteractionManager.printError("instrument type not found");
        }

        return true;
    }
    return false;
}

void Bard::setInstrument()
{
    const size_t songCount = mSongList.getSongCount();
    if ((songCount >= StringSongCountThreshold) && (songCount != mMaxSongs))
    {
        setStringInstrument();
    }
    else
    {
        setWindInstrument();
    }
}

void Bard::setStringInstrument()
{
    if (!mStringInstrument)
    {
        mInteractionManager.queueCommand("/lac fwd additionalsong", 1);
    }
    mStringInstrument = true;
}

void Bard::setWindInstrument()
{
    if (mStringInstrument)
    {
        mInteractionManager.queueCommand("/lac fwd regularsong", 1);
    }
    mStringInstrument = false;
}
