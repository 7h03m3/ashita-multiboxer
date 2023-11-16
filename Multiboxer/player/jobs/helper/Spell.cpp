#include "Spell.h"
#include "TaskQueue/TaskQueue.h"
#include "TargetMe.h"

using namespace player_job;

Spell::Spell(shared::SpellId id, player::InteractionManager& interactionManager)
    : mId(id)
    , mName(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->Name[2])
    , mCastTime(interactionManager.getSpellCastingTime(id))
    , mMpCost(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->ManaCost)
    , mTarget(TargetMe())
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
{}

Spell::Spell(uint16_t id, player::InteractionManager& interactionManager)
    : mId(static_cast<shared::SpellId>(id))
    , mName(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->Name[2])
    , mCastTime(interactionManager.getSpellCastingTime(static_cast<shared::SpellId>(id)))
    , mMpCost(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->ManaCost)
    , mTarget(TargetMe())
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
{
}

Spell::Spell(shared::SpellId id, player::InteractionManager& interactionManager, const Target& target)
    : mId(static_cast<shared::SpellId>(id))
    , mName(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->Name[2])
    , mCastTime(interactionManager.getSpellCastingTime(id))
    , mMpCost(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->ManaCost)
    , mTarget(target)
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
{}

Spell::Spell(uint16_t id, player::InteractionManager& interactionManager, const Target& target)
    : mId(static_cast<shared::SpellId>(id))
    , mName(interactionManager.getAshita().GetResourceManager()->GetSpellById(id)->Name[2])
    , mCastTime(interactionManager.getSpellCastingTime(static_cast<shared::SpellId>(id)))
    , mMpCost(interactionManager.getAshita().GetResourceManager()->GetSpellById(id)->ManaCost)
    , mTarget(target)
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
{
}

shared::SpellId Spell::getId() const
{
    return mId;
}

const std::string& Spell::getName() const
{
    return mName;
}

time_t Spell::getCastTime() const
{
    return mCastTime;
}

uint32_t Spell::getMpCost() const
{
    return mMpCost;
}

bool Spell::isReady()
{
    return getRecastTime() == 0;
}

bool Spell::hasEnoughMp(const uint32_t currentMp) const
{
    return (currentMp >= mMpCost);
}

uint32_t Spell::getRecastTime()
{
    return mAshita.GetMemoryManager()->GetRecast()->GetSpellTimer(static_cast<uint32_t>(mId));
}

void Spell::execute()
{
    mInteractionManager.queueSpell("/ma \"" + mName + "\" " + mTarget.get(), mCastTime + TaskQueue::SpellCooldown);
}

void Spell::setTarget(const Target& target)
{
    mTarget = target;
}

Target& Spell::getTarget()
{
    return mTarget;
}
