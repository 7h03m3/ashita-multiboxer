#include "CorsairRoll.h"

using namespace player_job;

CorsairRoll::CorsairRoll(const shared::AbilityId id, player::InteractionManager& interactionManager)
    : mAbilityId(id)
    , mAbility(toAbility(id))
    , mBuffId(toBuff(id))
    , mName(interactionManager.getAshita().GetResourceManager()->GetAbilityById(static_cast<uint32_t>(id))->Name[2])
    , mLucky(getLuckNumber(id))
    , mUnlucky(getUnluckyNumber(id))
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
    , mRoll(0)
{
}

CorsairRoll::CorsairRoll(const uint16_t id, player::InteractionManager& interactionManager)
    : mAbilityId(static_cast<shared::AbilityId>(id))
    , mAbility(toAbility(static_cast<shared::AbilityId>(id)))
    , mBuffId(toBuff(static_cast<shared::AbilityId>(id)))
    , mName(interactionManager.getAshita().GetResourceManager()->GetAbilityById(static_cast<uint32_t>(id))->Name[2])
    , mLucky(getLuckNumber(static_cast<shared::AbilityId>(id)))
    , mUnlucky(getUnluckyNumber(static_cast<shared::AbilityId>(id)))
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
    , mRoll(0)
{}

shared::AbilityId CorsairRoll::getId() const
{
    return mAbilityId;
}

shared::Ability CorsairRoll::getAbility() const
{
    return mAbility;
}

shared::BuffId CorsairRoll::getBuffId() const
{
    return mBuffId;
}

const std::string& CorsairRoll::getName() const
{
    return mName;
}

uint64_t CorsairRoll::getRoll() const
{
    return mRoll;
}

bool CorsairRoll::isLucky() const
{
    return mRoll == mLucky;
}

bool CorsairRoll::isUnlucky() const
{
    return mRoll == mUnlucky;
}

bool CorsairRoll::isReady()
{
    return getRecastTime() == 0;
}

uint32_t CorsairRoll::getRecastTime()
{
    const uint32_t abilityTimerId = mAshita.GetResourceManager()->GetAbilityById(static_cast<uint32_t>(mAbilityId))->RecastTimerId;

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

void CorsairRoll::setRoll(const uint64_t roll)
{
    mRoll = roll;
}

void CorsairRoll::execute()
{
    mInteractionManager.queueAbility("/ja \"" + mName + "\" <me>", TaskQueue::AbilityCooldown);
}

bool CorsairRoll::isAbility(const uint32_t abilityId)
{
    const shared::Ability ability = static_cast<shared::Ability>(abilityId);
    switch (ability)
    {
        case shared::Ability::FightersRoll:
        case shared::Ability::MonksRoll:
        case shared::Ability::HealersRoll:
        case shared::Ability::WizardsRoll:
        case shared::Ability::WarlocksRoll:
        case shared::Ability::RoguesRoll:
        case shared::Ability::GallantsRoll:
        case shared::Ability::ChaosRoll:
        case shared::Ability::BeastRoll:
        case shared::Ability::ChoralRoll:
        case shared::Ability::HuntersRoll:
        case shared::Ability::SamuraiRoll:
        case shared::Ability::NinjaRoll:
        case shared::Ability::DrachenRoll:
        case shared::Ability::EvokersRoll:
        case shared::Ability::MagusRoll:
        case shared::Ability::CorsairsRoll:
        case shared::Ability::PuppetRoll:
        case shared::Ability::DancersRoll:
        case shared::Ability::ScholarsRoll:
        case shared::Ability::BoltersRoll:
        case shared::Ability::CastersRoll:
        case shared::Ability::CoursersRoll:
        case shared::Ability::BlitzersRoll:
        case shared::Ability::TacticiansRoll:
        case shared::Ability::AlliesRoll:
        case shared::Ability::MisersRoll:
        case shared::Ability::CompanionsRoll:
        case shared::Ability::AvengersRoll:
        case shared::Ability::NaturalistsRoll:
        case shared::Ability::RuneistsRoll:
            return true;

        default:
            return false;
    }
}

shared::Ability CorsairRoll::toAbility(const shared::AbilityId abilityId)
{
    switch (abilityId)
    {
        default:
        case shared::AbilityId::FightersRoll:
            return shared::Ability::FightersRoll;
        case shared::AbilityId::MonksRoll:
            return shared::Ability::MonksRoll;
        case shared::AbilityId::HealersRoll:
            return shared::Ability::HealersRoll;
        case shared::AbilityId::WizardsRoll:
            return shared::Ability::WizardsRoll;
        case shared::AbilityId::WarlocksRoll:
            return shared::Ability::WarlocksRoll;
        case shared::AbilityId::RoguesRoll:
            return shared::Ability::RoguesRoll;
        case shared::AbilityId::GallantsRoll:
            return shared::Ability::GallantsRoll;
        case shared::AbilityId::ChaosRoll:
            return shared::Ability::ChaosRoll;
        case shared::AbilityId::BeastRoll:
            return shared::Ability::BeastRoll;
        case shared::AbilityId::ChoralRoll:
            return shared::Ability::ChoralRoll;
        case shared::AbilityId::HuntersRoll:
            return shared::Ability::HuntersRoll;
        case shared::AbilityId::SamuraiRoll:
            return shared::Ability::SamuraiRoll;
        case shared::AbilityId::NinjaRoll:
            return shared::Ability::NinjaRoll;
        case shared::AbilityId::DrachenRoll:
            return shared::Ability::DrachenRoll;
        case shared::AbilityId::EvokersRoll:
            return shared::Ability::EvokersRoll;
        case shared::AbilityId::MagusRoll:
            return shared::Ability::MagusRoll;
        case shared::AbilityId::CorsairsRoll:
            return shared::Ability::CorsairsRoll;
        case shared::AbilityId::PuppetRoll:
            return shared::Ability::PuppetRoll;
        case shared::AbilityId::DancersRoll:
            return shared::Ability::DancersRoll;
        case shared::AbilityId::ScholarsRoll:
            return shared::Ability::ScholarsRoll;
        case shared::AbilityId::BoltersRoll:
            return shared::Ability::BoltersRoll;
        case shared::AbilityId::CastersRoll:
            return shared::Ability::CastersRoll;
        case shared::AbilityId::CoursersRoll:
            return shared::Ability::CoursersRoll;
        case shared::AbilityId::BlitzersRoll:
            return shared::Ability::BlitzersRoll;
        case shared::AbilityId::TacticiansRoll:
            return shared::Ability::TacticiansRoll;
        case shared::AbilityId::AlliesRoll:
            return shared::Ability::AlliesRoll;
        case shared::AbilityId::MisersRoll:
            return shared::Ability::MisersRoll;
        case shared::AbilityId::CompanionsRoll:
            return shared::Ability::CompanionsRoll;
        case shared::AbilityId::AvengersRoll:
            return shared::Ability::AvengersRoll;
        case shared::AbilityId::NaturalistsRoll:
            return shared::Ability::NaturalistsRoll;
        case shared::AbilityId::RuneistsRoll:
            return shared::Ability::RuneistsRoll;
    }
}

shared::BuffId CorsairRoll::toBuff(const shared::AbilityId abilityId)
{
    switch (abilityId)
    {
        default:
        case shared::AbilityId::FightersRoll:
            return shared::BuffId::FightersRoll;
        case shared::AbilityId::MonksRoll:
            return shared::BuffId::MonksRoll;
        case shared::AbilityId::HealersRoll:
            return shared::BuffId::HealersRoll;
        case shared::AbilityId::WizardsRoll:
            return shared::BuffId::WizardsRoll;
        case shared::AbilityId::WarlocksRoll:
            return shared::BuffId::WarlocksRoll;
        case shared::AbilityId::RoguesRoll:
            return shared::BuffId::RoguesRoll;
        case shared::AbilityId::GallantsRoll:
            return shared::BuffId::GallantsRoll;
        case shared::AbilityId::ChaosRoll:
            return shared::BuffId::ChaosRoll;
        case shared::AbilityId::BeastRoll:
            return shared::BuffId::BeastRoll;
        case shared::AbilityId::ChoralRoll:
            return shared::BuffId::ChoralRoll;
        case shared::AbilityId::HuntersRoll:
            return shared::BuffId::HuntersRoll;
        case shared::AbilityId::SamuraiRoll:
            return shared::BuffId::SamuraiRoll;
        case shared::AbilityId::NinjaRoll:
            return shared::BuffId::NinjaRoll;
        case shared::AbilityId::DrachenRoll:
            return shared::BuffId::DrachenRoll;
        case shared::AbilityId::EvokersRoll:
            return shared::BuffId::EvokersRoll;
        case shared::AbilityId::MagusRoll:
            return shared::BuffId::MagusRoll;
        case shared::AbilityId::CorsairsRoll:
            return shared::BuffId::CorsairsRoll;
        case shared::AbilityId::PuppetRoll:
            return shared::BuffId::PuppetRoll;
        case shared::AbilityId::DancersRoll:
            return shared::BuffId::DancersRoll;
        case shared::AbilityId::ScholarsRoll:
            return shared::BuffId::ScholarsRoll;
        case shared::AbilityId::BoltersRoll:
            return shared::BuffId::BoltersRoll;
        case shared::AbilityId::CastersRoll:
            return shared::BuffId::CastersRoll;
        case shared::AbilityId::CoursersRoll:
            return shared::BuffId::CoursersRoll;
        case shared::AbilityId::BlitzersRoll:
            return shared::BuffId::BlitzersRoll;
        case shared::AbilityId::TacticiansRoll:
            return shared::BuffId::TacticiansRoll;
        case shared::AbilityId::AlliesRoll:
            return shared::BuffId::AlliesRoll;
        case shared::AbilityId::MisersRoll:
            return shared::BuffId::MisersRoll;
        case shared::AbilityId::CompanionsRoll:
            return shared::BuffId::CompanionsRoll;
        case shared::AbilityId::AvengersRoll:
            return shared::BuffId::AvengersRoll;
        case shared::AbilityId::NaturalistsRoll:
            return shared::BuffId::NaturalistsRoll;
        case shared::AbilityId::RuneistsRoll:
            return shared::BuffId::RuneistsRoll;
    }
}

uint64_t CorsairRoll::getLuckNumber(shared::AbilityId abilityId)
{
    switch (abilityId)
    {
        default:
            return 0u;
        case shared::AbilityId::FightersRoll:
            return 5u;
        case shared::AbilityId::MonksRoll:
            return 3u;
        case shared::AbilityId::HealersRoll:
            return 3u;
        case shared::AbilityId::WizardsRoll:
            return 5u;
        case shared::AbilityId::WarlocksRoll:
            return 4u;
        case shared::AbilityId::RoguesRoll:
            return 5u;
        case shared::AbilityId::GallantsRoll:
            return 3u;
        case shared::AbilityId::ChaosRoll:
            return 4u;
        case shared::AbilityId::BeastRoll:
            return 4u;
        case shared::AbilityId::ChoralRoll:
            return 2u;
        case shared::AbilityId::HuntersRoll:
            return 4u;
        case shared::AbilityId::SamuraiRoll:
            return 2u;
        case shared::AbilityId::NinjaRoll:
            return 4u;
        case shared::AbilityId::DrachenRoll:
            return 4u;
        case shared::AbilityId::EvokersRoll:
            return 5u;
        case shared::AbilityId::MagusRoll:
            return 2u;
        case shared::AbilityId::CorsairsRoll:
            return 5u;
        case shared::AbilityId::PuppetRoll:
            return 3u;
        case shared::AbilityId::DancersRoll:
            return 3u;
        case shared::AbilityId::ScholarsRoll:
            return 2u;
        case shared::AbilityId::BoltersRoll:
            return 3u;
        case shared::AbilityId::CastersRoll:
            return 2u;
        case shared::AbilityId::CoursersRoll:
            return 3u;
        case shared::AbilityId::BlitzersRoll:
            return 4u;
        case shared::AbilityId::TacticiansRoll:
            return 5u;
        case shared::AbilityId::AlliesRoll:
            return 3u;
        case shared::AbilityId::MisersRoll:
            return 5u;
        case shared::AbilityId::CompanionsRoll:
            return 2u;
        case shared::AbilityId::AvengersRoll:
            return 4u;
        case shared::AbilityId::NaturalistsRoll:
            return 3u;
        case shared::AbilityId::RuneistsRoll:
            return 4u;
    }
}
uint64_t CorsairRoll::getUnluckyNumber(shared::AbilityId abilityId)
{
    switch (abilityId)
    {
        default:
            return 0u;
        case shared::AbilityId::FightersRoll:
            return 9u;
        case shared::AbilityId::MonksRoll:
            return 7u;
        case shared::AbilityId::HealersRoll:
            return 7u;
        case shared::AbilityId::WizardsRoll:
            return 9u;
        case shared::AbilityId::WarlocksRoll:
            return 8u;
        case shared::AbilityId::RoguesRoll:
            return 9u;
        case shared::AbilityId::GallantsRoll:
            return 7u;
        case shared::AbilityId::ChaosRoll:
            return 8u;
        case shared::AbilityId::BeastRoll:
            return 8u;
        case shared::AbilityId::ChoralRoll:
            return 6u;
        case shared::AbilityId::HuntersRoll:
            return 8u;
        case shared::AbilityId::SamuraiRoll:
            return 6u;
        case shared::AbilityId::NinjaRoll:
            return 8u;
        case shared::AbilityId::DrachenRoll:
            return 8u;
        case shared::AbilityId::EvokersRoll:
            return 9u;
        case shared::AbilityId::MagusRoll:
            return 6u;
        case shared::AbilityId::CorsairsRoll:
            return 9u;
        case shared::AbilityId::PuppetRoll:
            return 7u;
        case shared::AbilityId::DancersRoll:
            return 7u;
        case shared::AbilityId::ScholarsRoll:
            return 6u;
        case shared::AbilityId::BoltersRoll:
            return 9u;
        case shared::AbilityId::CastersRoll:
            return 7u;
        case shared::AbilityId::CoursersRoll:
            return 9u;
        case shared::AbilityId::BlitzersRoll:
            return 9u;
        case shared::AbilityId::TacticiansRoll:
            return 8u;
        case shared::AbilityId::AlliesRoll:
            return 10u;
        case shared::AbilityId::MisersRoll:
            return 7u;
        case shared::AbilityId::CompanionsRoll:
            return 10u;
        case shared::AbilityId::AvengersRoll:
            return 8u;
        case shared::AbilityId::NaturalistsRoll:
            return 7u;
        case shared::AbilityId::RuneistsRoll:
            return 8u;
    }
}