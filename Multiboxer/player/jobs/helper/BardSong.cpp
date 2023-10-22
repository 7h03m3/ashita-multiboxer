#include "BardSong.h"
#include "TargetMe.h"

using namespace player_job;

BardSong::BardSong(shared::SpellId id, player::InteractionManager& interactionManager)
    : mSpellId(id)
    , mBuffId(getBuffId(mSpellId))
    , mName(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->Name[2])
    , mCastTime(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->CastTime / 4)
    , mTarget(TargetMe())
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
{
}

BardSong::BardSong(uint16_t id, player::InteractionManager& interactionManager)
    : mSpellId(static_cast<shared::SpellId>(id))
    , mBuffId(getBuffId(mSpellId))
    , mName(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->Name[2])
    , mCastTime(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->CastTime / 4)
    , mTarget(TargetMe())
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
{}

BardSong::BardSong(shared::SpellId id, player::InteractionManager& interactionManager, const Target& target)
    : mSpellId(id)
    , mBuffId(getBuffId(mSpellId))
    , mName(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->Name[2])
    , mCastTime(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->CastTime / 4)
    , mTarget(target)
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
{
}

BardSong::BardSong(uint16_t id, player::InteractionManager& interactionManager, const Target& target)
    : mSpellId(static_cast<shared::SpellId>(id))
    , mBuffId(getBuffId(mSpellId))
    , mName(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->Name[2])
    , mCastTime(interactionManager.getAshita().GetResourceManager()->GetSpellById(static_cast<uint32_t>(id))->CastTime / 4)
    , mTarget(target)
    , mInteractionManager(interactionManager)
    , mAshita(interactionManager.getAshita())
{
}

shared::SpellId BardSong::getSpellId() const
{
    return mSpellId;
}

shared::BuffId BardSong::getBuffId() const
{
    return mBuffId;
}

const std::string& BardSong::getName() const
{
    return mName;
}

time_t BardSong::getCastTime() const
{
    return mCastTime;
}

bool BardSong::isReady()
{
    return getRecastTime() == 0;
}

uint32_t BardSong::getRecastTime()
{
    return mAshita.GetMemoryManager()->GetRecast()->GetSpellTimer(static_cast<uint32_t>(mSpellId));
}

void BardSong::execute()
{
    mInteractionManager.queueSpell("/ma \"" + mName + "\" " + mTarget.get(), mCastTime + TaskQueue::SpellCooldown);
}

void BardSong::setTarget(const Target& target)
{
    mTarget = target;
}

Target& BardSong::getTarget()
{
    return mTarget;
}

shared::BuffId BardSong::getBuffId(shared::SpellId spellId)
{
    switch (spellId)
    {
        case shared::SpellId::ArmysPaeon:
        case shared::SpellId::ArmysPaeon2:
        case shared::SpellId::ArmysPaeon3:
        case shared::SpellId::ArmysPaeon4:
        case shared::SpellId::ArmysPaeon5:
        case shared::SpellId::ArmysPaeon6:
            return shared::BuffId::Paeon;

        case shared::SpellId::MagesBallad:
        case shared::SpellId::MagesBallad2:
        case shared::SpellId::MagesBallad3:
            return shared::BuffId::Ballad;

        case shared::SpellId::KnightsMinne:
        case shared::SpellId::KnightsMinne2:
        case shared::SpellId::KnightsMinne3:
        case shared::SpellId::KnightsMinne4:
        case shared::SpellId::KnightsMinne5:
            return shared::BuffId::Minne;

        case shared::SpellId::ValorMinuet:
        case shared::SpellId::ValorMinuet2:
        case shared::SpellId::ValorMinuet3:
        case shared::SpellId::ValorMinuet4:
        case shared::SpellId::ValorMinuet5:
            return shared::BuffId::Minuet;

        case shared::SpellId::SwordMadrigal:
        case shared::SpellId::BladeMadrigal:
            return shared::BuffId::Madrigal;

        case shared::SpellId::HuntersPrelude:
        case shared::SpellId::ArchersPrelude:
            return shared::BuffId::Prelude;

        case shared::SpellId::SheepfoeMambo:
        case shared::SpellId::DragonfoeMambo:
            return shared::BuffId::Mambo;

        case shared::SpellId::FowlAubade:
            return shared::BuffId::Aubade;

        case shared::SpellId::HerbPastoral:
            return shared::BuffId::Pastoral;

        case shared::SpellId::ShiningFantasia:
            return shared::BuffId::Fantasia;

        case shared::SpellId::ScopsOperetta:
        case shared::SpellId::PuppetsOperetta:
            return shared::BuffId::Operetta;

        case shared::SpellId::GoldCapriccio:
            return shared::BuffId::Capriccio;

        case shared::SpellId::WardingRound:
            return shared::BuffId::Round;

        case shared::SpellId::GoblinGavotte:
            return shared::BuffId::Gavotte;

        case shared::SpellId::AdvancingMarch:
        case shared::SpellId::VictoryMarch:
        case shared::SpellId::HonorMarch:
            return shared::BuffId::March;

        case shared::SpellId::SinewyEtude:
        case shared::SpellId::DextrousEtude:
        case shared::SpellId::VivaciousEtude:
        case shared::SpellId::QuickEtude:
        case shared::SpellId::LearnedEtude:
        case shared::SpellId::SpiritedEtude:
        case shared::SpellId::EnchantingEtude:
        case shared::SpellId::HerculeanEtude:
        case shared::SpellId::UncannyEtude:
        case shared::SpellId::VitalEtude:
        case shared::SpellId::SwiftEtude:
        case shared::SpellId::SageEtude:
        case shared::SpellId::LogicalEtude:
        case shared::SpellId::BewitchingEtude:
            return shared::BuffId::Etude;

        case shared::SpellId::FireCarol:
        case shared::SpellId::FireCarol2:
        case shared::SpellId::IceCarol:
        case shared::SpellId::IceCarol2:
        case shared::SpellId::WindCarol:
        case shared::SpellId::WindCarol2:
        case shared::SpellId::EarthCarol:
        case shared::SpellId::EarthCarol2:
        case shared::SpellId::LightningCarol:
        case shared::SpellId::LightningCarol2:
        case shared::SpellId::WaterCarol:
        case shared::SpellId::WaterCarol2:
        case shared::SpellId::LightCarol:
        case shared::SpellId::LightCarol2:
        case shared::SpellId::DarkCarol:
        case shared::SpellId::DarkCarol2:
            return shared::BuffId::Carol;

        case shared::SpellId::GoddesssHymnus:
            return shared::BuffId::Hymnus;

        case shared::SpellId::RaptorMazurka:
        case shared::SpellId::ChocoboMazurka:
            return shared::BuffId::Mazurka;

        case shared::SpellId::FoeSirvente:
            return shared::BuffId::Sirvente;

        case shared::SpellId::AdventurersDirge:
            return shared::BuffId::Dirge;

        case shared::SpellId::SentinelsScherzo:
            return shared::BuffId::Scherzo;

        default: // TODO add Aria of passion
            return shared::BuffId::Aria;
    }
}
