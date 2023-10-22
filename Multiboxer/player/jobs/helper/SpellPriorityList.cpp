#include "SpellPriorityList.h"

using namespace player_job;

SpellPriorityList::SpellPriorityList(player::InteractionManager& interactionManager)
    : mInteractionManager(interactionManager)
    , mList()
{
}

SpellPriorityList::~SpellPriorityList()
{
    clear();
}

void SpellPriorityList::add(shared::SpellId id, const Target& target)
{
    mList.push_back(new Spell(id, mInteractionManager, target));
}

void SpellPriorityList::clear()
{
    for (auto it : mList)
    {
        delete it;
    }

    mList.clear();
}

void SpellPriorityList::cast(uint32_t serverId)
{
    cast(std::to_string(serverId));
}

void SpellPriorityList::cast(const std::string& target)
{
    for (auto it : mList)
    {
        if (it->isReady())
        {
            if (it->getTarget().isBattleTarget())
            {
                it->getTarget().set(target);
            }
            it->execute();
            return;
        }
    }

    mInteractionManager.printError("no spell is ready");
}