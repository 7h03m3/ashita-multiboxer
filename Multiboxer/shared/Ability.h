#pragma once

#include <stdint.h>

namespace shared
{
    enum class Ability : uint32_t
    {
        FightersRoll    = 98,
        MonksRoll       = 99,
        HealersRoll     = 100,
        WizardsRoll     = 101,
        WarlocksRoll    = 102,
        RoguesRoll      = 103,
        GallantsRoll    = 104,
        ChaosRoll       = 105,
        BeastRoll       = 106,
        ChoralRoll      = 107,
        HuntersRoll     = 108,
        SamuraiRoll     = 109,
        NinjaRoll       = 110,
        DrachenRoll     = 111,
        EvokersRoll     = 112,
        MagusRoll       = 113,
        CorsairsRoll    = 114,
        PuppetRoll      = 115,
        DancersRoll     = 116,
        ScholarsRoll    = 117,
        BoltersRoll     = 118,
        CastersRoll     = 119,
        CoursersRoll    = 120,
        BlitzersRoll    = 121,
        TacticiansRoll  = 122,
        AlliesRoll      = 302,
        MisersRoll      = 303,
        CompanionsRoll  = 304,
        AvengersRoll    = 305,
        NaturalistsRoll = 390,
        RuneistsRoll    = 391,
    };
}