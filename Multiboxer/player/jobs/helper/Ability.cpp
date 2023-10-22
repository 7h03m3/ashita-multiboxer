#include "Ability.h"
#include "TaskQueue/TaskQueue.h"
#include "TargetMe.h"

using namespace player_job;

Ability::Ability(const shared::AbilityId id, player::InteractionManager& interactionManager)
    : mId(id)
    , mName(interactionManager.getAshita().GetResourceManager()->GetAbilityById(id)->Name[2])
    , mTarget(TargetMe())
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
{
}

Ability::Ability(const uint16_t id, player::InteractionManager& interactionManager)
    : mId(static_cast<shared::AbilityId>(id))
    , mName(interactionManager.getAshita().GetResourceManager()->GetAbilityById(id)->Name[2])
    , mTarget(TargetMe())
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
{
}

shared::AbilityId Ability::getId() const
{
    return mId;
}

const std::string& Ability::getName() const
{
    return mName;
}

bool Ability::isReady()
{
    return getRecastTime() == 0;
}

uint32_t Ability::getRecastTime()
{
    const uint32_t abilityTimerId = mAshita.GetResourceManager()->GetAbilityById(mId)->RecastTimerId;

    for (uint32_t i = 0u; i < 32u; i++)
    {
        const uint32_t timerId = mAshita.GetMemoryManager()->GetRecast()->GetAbilityTimerId(i);

        if (timerId == abilityTimerId)
        {
            return mAshita.GetMemoryManager()->GetRecast()->GetAbilityTimer(i);
        }
    }

    return 0;
}

void Ability::execute()
{
    mInteractionManager.queueAbility("/ja \"" + mName + "\" " + mTarget.get(), TaskQueue::AbilityCooldown);
}

void Ability::setTarget(const Target& target)
{
    mTarget = target;
}

Target& Ability::getTarget()
{
    return mTarget;
}