#include "WhiteMage.h"

#include "helper/TargetCustom.h"

using namespace player_job;

WhiteMage::WhiteMage(player::InteractionManager& interactionManager)
    : Job(Ashita::FFXI::Enums::Job::WhiteMage, "WhiteMage", interactionManager)
    , mBuffList(5, interactionManager)
    , mAfflatusSolace(shared::AbilityId::AfflatusSolace, interactionManager)
    , mAutoHeal(false)
    , mAutoHealHppThreshold(80)
{
    setBattleDistance(18);

    mBuffList.add(shared::SpellId::Protectra5);
    mBuffList.add(shared::SpellId::Shellra5);
    mBuffList.add(shared::SpellId::Barparalyzra);
    mBuffList.add(shared::SpellId::Barfira);
    mBuffList.add(shared::SpellId::BoostStr);
}

void WhiteMage::poll()
{
    if (mInteractionManager.queueHasTasks())
    {
        return;
    }

    if (mBuffList.isRefreshRunning())
    {
        mBuffList.doRefresh();
        if (!mBuffList.isRefreshRunning())
        {
            mInteractionManager.printMessage("buff refresh done");
        }
    }

    if (!mAutoHeal)
    {
        return;
    }

    const player::PlayerBaseInterface* player = mInteractionManager.getPlayerLowestHp(mAutoHealHppThreshold);
    if ((player != nullptr) && (mInteractionManager.isInCastingRange(player->getIndex())))
    {
        Spell cure(shared::SpellId::Cure4, mInteractionManager, TargetCustom(player->getName()));

        if (cure.isReady())
        {
            mInteractionManager.printMessage(player->getName() + " " + std::to_string(player->getStats().getHPP()));
            useAfflatusSolace();
            cure.execute();
        }
    }
}

void WhiteMage::onBattleStart()
{}

void WhiteMage::onBattleStop()
{}

bool WhiteMage::onJobCommand(const commands::String& command)
{
    if (command.match("show"))
    {
        const size_t buffCount = mBuffList.getSize();
        for (size_t i = 0; i < buffCount; i++)
        {
            mInteractionManager.printMessage("[Buff " + std::to_string(i) + "] " + mBuffList.get(i).getName());
        }

        return true;
    }
    else if (command.match("set", "autoHeal") && command.hasArg(2))
    {
        mAutoHeal = command.getArg(2) == "true";
        mInteractionManager.printMessage("auto heal set to " + std::to_string(mAutoHeal));
        return true;
    }
    else if (command.match("set", "autoHealThreshold") && command.hasArg(2))
    {
        mAutoHealHppThreshold = static_cast<uint8_t>(stoi(command.getArg(2)));
        if (mAutoHealHppThreshold > 100)
        {
            mAutoHealHppThreshold = 100;
        }
        mInteractionManager.printMessage("auto heal threshold set to " + std::to_string(mAutoHealHppThreshold));
        return true;
    }
    else if (command.match("set", "buff") && command.hasArg(3))
    {
        const size_t songIndex = static_cast<size_t>(stoi(command.getArg(2)));
        if (songIndex >= mBuffList.getMaxSize())
        {
            mInteractionManager.printError("invalid buff index");
            return true;
        }

        const ISpell* spell = mInteractionManager.getAshita().GetResourceManager()->GetSpellByName(command.getArg(3).c_str(), 2);
        if (spell == nullptr)
        {
            mInteractionManager.printError("spell \"" + command.getArg(2) + "\" not found");
            return true;
        }

        mBuffList.set(songIndex, static_cast<shared::SpellId>(spell->Index));

        return true;
    }
    else if (command.match("buff", "all"))
    {
        if (mBuffList.isRefreshRunning())
        {
            mInteractionManager.printError("buff refresh is running");
        }
        else
        {
            mInteractionManager.printMessage("buff refresh started");
            mBuffList.startRefresh();
        }

        return true;
    }
    else if (command.match("buff"))
    {
        if (mBuffList.isRefreshRunning())
        {
            mInteractionManager.printError("buff refresh is running");
        }
        else
        {
            mBuffList.refreshNext();
        }

        return true;
    }
    else if (command.match("cure"))
    {
        const player::PlayerBaseInterface* player = mInteractionManager.getPlayerLowestHp(100u);
        if (player == nullptr)
        {
            mInteractionManager.printMessage("nothing to heal");
            return true;
        }

        if (!mInteractionManager.isInCastingRange(player->getIndex()))
        {
            mInteractionManager.printError("not in range");
            return true;
        }

        Spell cure(shared::SpellId::Cure4, mInteractionManager, TargetCustom(player->getName()));

        if (cure.isReady())
        {
            useAfflatusSolace();
            cure.execute();
        }

        return true;
    }
    else if (command.match("curaga"))
    {
        const player::PlayerBaseInterface* player = mInteractionManager.getPlayerLowestHp(100u);
        if (player == nullptr)
        {
            mInteractionManager.printMessage("nothing to heal");
            return true;
        }

        if (!mInteractionManager.isInCastingRange(player->getIndex()))
        {
            mInteractionManager.printError("not in range");
            return true;
        }

        Spell curaga(shared::SpellId::Curaga4, mInteractionManager, TargetCustom(player->getName()));

        if (curaga.isReady())
        {
            useAfflatusSolace();
            curaga.execute();
        }

        return true;
    }

    return false;
}

void WhiteMage::useAfflatusSolace()
{
    if (mInteractionManager.getPlayer().getBuffCount(shared::BuffId::AfflatusSolace) != 0)
    {
        return;
    }

    if (mAfflatusSolace.isReady())
    {
        mAfflatusSolace.execute();
    }
}
