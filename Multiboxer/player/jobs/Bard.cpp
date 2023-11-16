#include "Bard.h"

#include "helper/TargetBattle.h"

using namespace player_job;

Bard::Bard(player::InteractionManager& interactionManager)
    : Job(Ashita::FFXI::Enums::Job::Bard, "Bard", interactionManager)
    , mMaxSongs(3)
    , mStringInstrument(true)
    , mSongList(4, interactionManager)
    , mPrecastSongList(4, interactionManager)
    , mDebuffList(2, interactionManager)
    , mNightingale(shared::AbilityId::Nightingale, interactionManager)
    , mTroubadour(shared::AbilityId::Troubadour, interactionManager)
    , mMarcato(shared::AbilityId::Marcato, interactionManager)
{
    mSongList.add(shared::SpellId::ValorMinuet5);
    mSongList.add(shared::SpellId::AdvancingMarch);
    mSongList.add(shared::SpellId::VictoryMarch);

    mPrecastSongList.add(shared::SpellId::FowlAubade);
    mPrecastSongList.add(shared::SpellId::HerbPastoral);
    mPrecastSongList.add(shared::SpellId::ScopsOperetta);

    mDebuffList.add(shared::SpellId::CarnageElegy, TargetBattle());
    mDebuffList.add(shared::SpellId::WindThrenody2, TargetBattle());

    setWindInstrument();
}

void Bard::poll()
{
    if (mInteractionManager.queueHasTasks())
    {
        return;
    }

    if (mPrecastSongList.isRefreshRunning())
    {
        setStringInstrument();
        mPrecastSongList.doRefresh();
        if (!mPrecastSongList.isRefreshRunning())
        {
            mInteractionManager.printMessage("precast done");
        }
    }
    else if (mSongList.isRefreshRunning())
    {
        setInstrument();

        if (mSongList.isFirst())
        {
            useMarcato();
        }

        mSongList.doRefresh();
        if (!mSongList.isRefreshRunning())
        {
            mInteractionManager.printMessage("song refresh done");
        }
    }
    else if (mDebuffList.isRefreshRunning())
    {
        setWindInstrument();
        mDebuffList.doRefresh(std::to_string(mBattleTarget.getServerId()));
        if (!mDebuffList.isRefreshRunning())
        {
            mInteractionManager.printMessage("debuf refresh done");
        }
    }
}

void Bard::onBattleStart()
{
    engage(mBattleTarget.getServerId());
}

void Bard::onBattleStop()
{
    disengage();
}

bool Bard::onJobCommand(const commands::String& command)
{
    if (command.match("show"))
    {
        const size_t songCount = mSongList.getSize();
        for (size_t i = 0; i < songCount; i++)
        {
            mInteractionManager.printMessage("[Buff " + std::to_string(i) + "] " + mSongList.get(i).getName());
        }

        const size_t debufCount = mDebuffList.getSize();
        for (size_t i = 0; i < debufCount; i++)
        {
            mInteractionManager.printMessage("[Debuff " + std::to_string(i) + "] " + mDebuffList.get(i).getName());
        }
        return true;
    }
    else if (command.match("set", "buff") && command.hasArg(3))
    {
        const size_t songIndex = static_cast<size_t>(stoi(command.getArg(2)));
        if (songIndex >= mSongList.getMaxSongs())
        {
            mInteractionManager.printError("invalid song index");
            return true;
        }

        const ISpell* spell = mInteractionManager.getAshita().GetResourceManager()->GetSpellByName(command.getArg(3).c_str(), 2);
        if (spell == nullptr)
        {
            mInteractionManager.printError("spell \"" + command.getArg(2) + "\" not found");
            return true;
        }

        mSongList.set(songIndex, static_cast<shared::SpellId>(spell->Index));

        return true;
    }
    else if (command.match("set", "debuff") && command.hasArg(3))
    {
        const size_t songIndex = static_cast<size_t>(stoi(command.getArg(2)));
        if (songIndex >= mDebuffList.getMaxSize())
        {
            mInteractionManager.printError("invalid song index");
            return true;
        }

        const ISpell* spell = mInteractionManager.getAshita().GetResourceManager()->GetSpellByName(command.getArg(3).c_str(), 2);
        if (spell == nullptr)
        {
            mInteractionManager.printError("spell \"" + command.getArg(2) + "\" not found");
            return true;
        }

        mDebuffList.set(songIndex, static_cast<shared::SpellId>(spell->Index));

        return true;
    }
    else if (command.match("set", "buffs") && command.hasArg(2))
    {
        if (command.getArg(2) == "meeleAttack")
        {
            mSongList.set(0, shared::SpellId::ValorMinuet5);
            mSongList.set(1, shared::SpellId::AdvancingMarch);
            mSongList.set(2, shared::SpellId::VictoryMarch);
        }
        else if (command.getArg(2) == "meeleAccurracy")
        {
            mSongList.set(0, shared::SpellId::BladeMadrigal);
            mSongList.set(1, shared::SpellId::AdvancingMarch);
            mSongList.set(2, shared::SpellId::VictoryMarch);
        }
        else if (command.getArg(2) == "scherzo")
        {
            mSongList.set(0, shared::SpellId::SentinelsScherzo);
            mSongList.set(1, shared::SpellId::AdvancingMarch);
            mSongList.set(2, shared::SpellId::VictoryMarch);
        }
        else
        {
            mInteractionManager.printError("set not found");
        }

        return true;
    }
    else if (command.match("buff", "all"))
    {
        if (mSongList.isRefreshRunning() || mPrecastSongList.isRefreshRunning())
        {
            mInteractionManager.printError("song refresh is running");
        }
        else
        {
            useNiTro();

            const size_t songCount = mSongList.getSongCount();
            if (songCount != mMaxSongs)
            {
                mInteractionManager.printMessage("song precast started");
                mPrecastSongList.startRefresh();
            }

            mInteractionManager.printMessage("song refresh started");
            mSongList.startRefresh();
        }

        return true;
    }
    else if (command.match("buff"))
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

    else if (command.match("debuff", "all"))
    {
        if (!mBattleTarget.isValid())
        {
            mInteractionManager.printError("no battle target");
        }
        else if (mDebuffList.isRefreshRunning())
        {
            mInteractionManager.printError("debuff refresh is running");
        }
        else
        {
            mInteractionManager.printMessage("debuff refresh started");
            mDebuffList.startRefresh();
        }

        return true;
    }
    else if (command.match("debuff"))
    {
        if (!mBattleTarget.isValid())
        {
            mInteractionManager.printError("no battle target");
        }
        else if (mDebuffList.isRefreshRunning())
        {
            mInteractionManager.printError("debuff refresh is running");
        }
        else
        {
            mDebuffList.refreshNext(std::to_string(mBattleTarget.getServerId()));
        }

        return true;
    }
    else if (command.match("movementSpeed"))
    {
        BardSong speedUp(shared::SpellId::ChocoboMazurka, mInteractionManager);

        if (!speedUp.isReady())
        {
            mInteractionManager.printError("song not ready");
            return true;
        }

        speedUp.execute();
        return true;
    }
    else if (command.match("set", "instrument") && command.hasArg(2))
    {
        if (command.getArg(2) == "string")
        {
            setStringInstrument();
        }
        else if (command.getArg(2) == "wind")
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
    const size_t songCount = mSongList.getSongCount() + mPrecastSongList.getSongCount();
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

void Bard::useNiTro()
{
    if (!mNightingale.isReady() || !mTroubadour.isReady())
    {
        return;
    }

    mNightingale.execute();
    mTroubadour.execute();
}

void Bard::useMarcato()
{
    if (!mMarcato.isReady())
    {
        return;
    }

    mMarcato.execute();
}
