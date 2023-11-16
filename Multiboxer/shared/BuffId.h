#pragma once

namespace shared
{
    enum class BuffId : uint16_t
    {
        Ko                   = 0,
        Weakness             = 1,
        Sleep1               = 2,
        Poison               = 3,
        Paralysis            = 4,
        Blindness            = 5,
        Silence              = 6,
        Petrification        = 7,
        Disease              = 8,
        Curse1               = 9,
        Stun                 = 10,
        Bind                 = 11,
        Weight               = 12,
        Slow                 = 13,
        Charm1               = 14,
        Doom                 = 15,
        Amnesia              = 16,
        Charm2               = 17,
        GradualPetrification = 18,
        Sleep2               = 19,
        Curse2               = 20,
        Addle                = 21,
        Intimidate           = 22,
        Kaustra              = 23,
        Terror               = 28,
        Mute                 = 29,
        Bane                 = 30,
        Plague               = 31,
        Flee                 = 32,
        Haste                = 33,
        BlazeSpikes          = 34,
        IceSpikes            = 35,
        Blink                = 36,
        Stoneskin            = 37,
        ShockSpikes          = 38,
        Aquaveil             = 39,
        Protect              = 40,
        Shell                = 41,
        Regen                = 42,
        Refresh              = 43,
        MightyStrikes        = 44,
        Boost                = 45,
        HundredFists         = 46,
        Manafont             = 47,
        Chainspell           = 48,
        PerfectDodge         = 49,
        Invincible           = 50,
        BloodWeapon          = 51,
        SoulVoice            = 52,
        EagleEyeShot         = 53,
        MeikyoShisui         = 54,
        AstralFlow           = 55,
        Berserk              = 56,
        Defender             = 57,
        Aggressor            = 58,
        Focus                = 59,
        Dodge                = 60,
        Counterstance        = 61,
        Sentinel             = 62,
        Souleater            = 63,
        LastResort           = 64,
        SneakAttack          = 65,
        Copy1mage            = 66,
        ThirdEye             = 67,
        Warcry               = 68,
        Invisible            = 69,
        Deodorize            = 70,
        Sneak                = 71,
        Sharpshot            = 72,
        Barrage              = 73,
        HolyCircle           = 74,
        ArcaneCircle         = 75,
        Hide                 = 76,
        Camouflage           = 77,
        DivineSeal           = 78,
        ElementalSeal        = 79,
        StrBoost             = 80,
        DexBoost             = 81,
        VitBoost             = 82,
        AgiBoost             = 83,
        IntBoost             = 84,
        MndBoost             = 85,
        ChrBoost             = 86,
        TrickAttack          = 87,
        MaxHpBoost           = 88,
        MaxMpBoost           = 89,
        AccuracyBoost        = 90,
        AttackBoost          = 91,
        EvasionBoost         = 92,
        DefenseBoost         = 93,
        Enfire               = 94,
        Enblizzard           = 95,
        Enaero               = 96,
        Enstone              = 97,
        Enthunder            = 98,
        Enwater              = 99,
        Barfire              = 100,
        Barblizzard          = 101,
        Baraero              = 102,
        Barstone             = 103,
        Barthunder           = 104,
        Barwater             = 105,
        Barsleep             = 106,
        Barpoison            = 107,
        Barparalyze          = 108,
        Barblind             = 109,
        Barsilence           = 110,
        Barpetrify           = 111,
        Barvirus             = 112,
        Reraise              = 113,
        Cover                = 114,
        UnlimitedShot        = 115,
        Phalanx              = 116,
        WardingCircle        = 117,
        AncientCircle        = 118,
        StrBoost2            = 119,
        DexBoost2            = 120,
        VitBoost2            = 121,
        AgiBoost2            = 122,
        IntBoost2            = 123,
        MndBoost2            = 124,
        ChrBoost2            = 125,
        SpiritSurge          = 126,
        Costume              = 127,
        Burn                 = 128,
        Frost                = 129,
        Choke                = 130,
        Rasp                 = 131,
        Shock                = 132,
        Drown                = 133,
        Dia                  = 134,
        Bio                  = 135,
        StrDown              = 136,
        DexDown              = 137,
        VitDown              = 138,
        AgiDown              = 139,
        IntDown              = 140,
        MndDown              = 141,
        ChrDown              = 142,
        LevelRestriction     = 143,
        MaxHpDown            = 144,
        MaxMpDown            = 145,
        AccuracyDown         = 146,
        AttackDown           = 147,
        EvasionDown          = 148,
        DefenseDown          = 149,
        PhysicalShield       = 150,
        ArrowShield          = 151,
        MagicShield          = 152,
        DamageSpikes         = 153,
        ShiningRuby          = 154,
        Medicine             = 155,
        Flash                = 156,
        SjRestriction        = 157,
        Provoke              = 158,
        Penalty              = 159,
        Preparations         = 160,
        Sprint               = 161,
        Enchantment          = 162,
        AzureLore            = 163,
        ChainAffinity        = 164,
        BurstAffinity        = 165,
        Overdrive            = 166,
        MagicDefDown         = 167,
        InhibitTp            = 168,
        Potency              = 169,
        Regain               = 170,
        Pax                  = 171,
        Intension            = 172,
        DreadSpikes          = 173,
        MagicAccDown         = 174,
        MagicAtkDown         = 175,
        Quickening           = 176,
        Encumbrance2         = 177,
        Firestorm            = 178,
        Hailstorm            = 179,
        Windstorm            = 180,
        Sandstorm            = 181,
        Thunderstorm         = 182,
        Rainstorm            = 183,
        Aurorastorm          = 184,
        Voidstorm            = 185,
        Helix                = 186,
        SublimationActivated = 187,
        SublimationComplete  = 188,
        MaxTpDown            = 189,
        MagicAtkBoost        = 190,
        MagicDefBoost        = 191,
        Requiem              = 192,
        Lullaby              = 193,
        Elegy                = 194,
        Paeon                = 195,
        Ballad               = 196,
        Minne                = 197,
        Minuet               = 198,
        Madrigal             = 199,
        Prelude              = 200,
        Mambo                = 201,
        Aubade               = 202,
        Pastoral             = 203,
        Hum                  = 204,
        Fantasia             = 205,
        Operetta             = 206,
        Capriccio            = 207,
        Serenade             = 208,
        Round                = 209,
        Gavotte              = 210,
        Fugue                = 211,
        Rhapsody             = 212,
        Aria                 = 213,
        March                = 214,
        Etude                = 215,
        Carol                = 216,
        Threnody             = 217,
        Hymnus               = 218,
        Mazurka              = 219,
        Sirvente             = 220,
        Dirge                = 221,
        Scherzo              = 222,
        Nocturne             = 223,
        StoreTp              = 227,
        Embrava              = 228,
        Manawell             = 229,
        Spontaneity          = 230,
        Marcato              = 231,
        Na                   = 232,
        AutoRegen            = 233,
        AutoRefresh          = 234,
        Fishing1magery       = 235,
        Woodworking1magery   = 236,
        Smithing1magery      = 237,
        Goldsmithing1magery  = 238,
        Clothcraft1magery    = 239,
        Leathercraft1magery  = 240,
        Bonecraft1magery     = 241,
        Alchemy1magery       = 242,
        Cooking1magery       = 243,
        Imagery1             = 244,
        Imagery2             = 245,
        Imagery3             = 246,
        Imagery4             = 247,
        Imagery5             = 248,
        Dedication           = 249,
        EfBadge              = 250,
        Food                 = 251,
        Mounted              = 252,
        Signet               = 253,
        Battlefield          = 254,
        None                 = 255,
        Sanction             = 256,
        Besieged             = 257,
        Illusion             = 258,
        Encumbrance1         = 259,
        Obliviscence         = 260,
        Impairment           = 261,
        Omerta               = 262,
        Debilitation         = 263,
        Pathos               = 264,
        Flurry               = 265,
        Concentration        = 266,
        AlliedTags           = 267,
        Sigil                = 268,
        LevelSync            = 269,
        AftermathLv1         = 270,
        AftermathLv2         = 271,
        AftermathLv3         = 272,
        Aftermath            = 273,
        Enlight              = 274,
        Auspice              = 275,
        Confrontation        = 276,
        Enfire2              = 277,
        Enblizzard2          = 278,
        Enaero2              = 279,
        Enstone2             = 280,
        Enthunder2           = 281,
        Enwater2             = 282,
        PerfectDefense       = 283,
        Egg                  = 284,
        Visitant             = 285,
        Baramnesia           = 286,
        Atma                 = 287,
        Endark               = 288,
        EnmityBoost          = 289,
        SubtleBlowPlus       = 290,
        EnmityDown           = 291,
        Pennant              = 292,
        NegatePetrify        = 293,
        NegateTerror         = 294,
        NegateAmnesia        = 295,
        NegateDoom           = 296,
        NegatePoison         = 297,
        CritHitEvasionDown   = 298,
        Overload             = 299,
        FireManeuver         = 300,
        IceManeuver          = 301,
        WindManeuver         = 302,
        EarthManeuver        = 303,
        ThunderManeuver      = 304,
        WaterManeuver        = 305,
        LightManeuver        = 306,
        DarkManeuver         = 307,
        DoubleUpChance       = 308,
        Bust                 = 309,
        FightersRoll         = 310,
        MonksRoll            = 311,
        HealersRoll          = 312,
        WizardsRoll          = 313,
        WarlocksRoll         = 314,
        RoguesRoll           = 315,
        GallantsRoll         = 316,
        ChaosRoll            = 317,
        BeastRoll            = 318,
        ChoralRoll           = 319,
        HuntersRoll          = 320,
        SamuraiRoll          = 321,
        NinjaRoll            = 322,
        DrachenRoll          = 323,
        EvokersRoll          = 324,
        MagusRoll            = 325,
        CorsairsRoll         = 326,
        PuppetRoll           = 327,
        DancersRoll          = 328,
        ScholarsRoll         = 329,
        BoltersRoll          = 330,
        CastersRoll          = 331,
        CoursersRoll         = 332,
        BlitzersRoll         = 333,
        TacticiansRoll       = 334,
        AlliesRoll           = 335,
        MisersRoll           = 336,
        CompanionsRoll       = 337,
        AvengersRoll         = 338,
        NaturalistsRoll      = 339,
        WarriorSCharge       = 340,
        FormlessStrikes      = 341,
        AssassinsCharge      = 342,
        Feint                = 343,
        Fealty               = 344,
        DarkSeal             = 345,
        DiabolicEye          = 346,
        Nightingale          = 347,
        Troubadour           = 348,
        Killer1nstinct       = 349,
        StealthShot          = 350,
        FlashyShot           = 351,
        Sange                = 352,
        Hasso                = 353,
        Seigan               = 354,
        Convergence          = 355,
        Diffusion            = 356,
        SnakeEye             = 357,
        LightArts            = 358,
        DarkArts             = 359,
        Penury               = 360,
        Parsimony            = 361,
        Celerity             = 362,
        Alacrity             = 363,
        Rapture              = 364,
        Ebullience           = 365,
        Accession            = 366,
        Manifestation        = 367,
        DrainSamba           = 368,
        AspirSamba           = 369,
        HasteSamba           = 370,
        VelocityShot         = 371,
        BuildingFlourish     = 375,
        Trance               = 376,
        TabulaRasa           = 377,
        DrainDaze            = 378,
        AspirDaze            = 379,
        HasteDaze            = 380,
        FinishingMove1       = 381,
        FinishingMove2       = 382,
        FinishingMove3       = 383,
        FinishingMove4       = 384,
        FinishingMove5       = 385,
        LethargicDaze1       = 386,
        LethargicDaze2       = 387,
        LethargicDaze3       = 388,
        LethargicDaze4       = 389,
        LethargicDaze5       = 390,
        SluggishDaze1        = 391,
        SluggishDaze2        = 392,
        SluggishDaze3        = 393,
        SluggishDaze4        = 394,
        SluggishDaze5        = 395,
        WeakenedDaze1        = 396,
        WeakenedDaze2        = 397,
        WeakenedDaze3        = 398,
        WeakenedDaze4        = 399,
        WeakenedDaze5        = 400,
        AddendumWhite        = 401,
        AddendumBlack        = 402,
        Reprisal             = 403,
        MagicEvasionDown     = 404,
        Retaliation          = 405,
        Footwork             = 406,
        Klimaform            = 407,
        Sekkanoki            = 408,
        Pianissimo           = 409,
        SaberDance           = 410,
        FanDance             = 411,
        Altruism             = 412,
        Focalization         = 413,
        Tranquility          = 414,
        Equanimity           = 415,
        Enlightenment        = 416,
        AfflatusSolace       = 417,
        AfflatusMisery       = 418,
        Composure            = 419,
        Yonin                = 420,
        Innin                = 421,
        CarbuncleSFavor      = 422,
        IfritSFavor          = 423,
        ShivaSFavor          = 424,
        GarudaSFavor         = 425,
        TitanSFavor          = 426,
        RamuhSFavor          = 427,
        LeviathanSFavor      = 428,
        FenrirSFavor         = 429,
        DiabolosSFavor       = 430,
        AvatarSFavor         = 431,
        MultiStrikes         = 432,
        DoubleShot           = 433,
        Transcendency        = 434,
        Restraint            = 435,
        PerfectCounter       = 436,
        ManaWall             = 437,
        DivineEmblem         = 438,
        NetherVoid           = 439,
        Sengikori            = 440,
        Futae                = 441,
        Presto               = 442,
        ClimacticFlourish    = 443,
        Copy1mage2           = 444,
        Copy1mage3           = 445,
        Copy1mage4           = 446,
        MultiShots           = 447,
        BewilderedDaze1      = 448,
        BewilderedDaze2      = 449,
        BewilderedDaze3      = 450,
        BewilderedDaze4      = 451,
        BewilderedDaze5      = 452,
        DivineCaress1        = 453,
        Saboteur             = 454,
        Tenuto               = 455,
        Spur                 = 456,
        Efflux               = 457,
        EarthenArmor         = 458,
        DivineCaress2        = 459,
        BloodRage            = 460,
        Impetus              = 461,
        Conspirator          = 462,
        Sepulcher            = 463,
        ArcaneCrest          = 464,
        Hamanoha             = 465,
        DragonBreaker        = 466,
        TripleShot           = 467,
        StrikingFlourish     = 468,
        Perpetuance          = 469,
        Immanence            = 470,
        Migawari             = 471,
        TernaryFlourish      = 472, // dnc 93
        Muddle               = 473, // mob effect
        Prowess              = 474, // grounds of valor
        Voidwatcher          = 475, // voidwatch
        Ensphere             = 476, // atmacite
        Sacrosanctity        = 477, // whm 95
        Palisade             = 478, // pld 95
        ScarletDelirium      = 479, // drk 95
        ScarletDelirium1     = 480, // drk 95
        // none                      = 481, // none
        DecoyShot         = 482, // rng 95
        Hagakure          = 483, // sam 95
        Issekigan         = 484, // nin 95
        UnbridledLearning = 485, // blu 95
        CounterBoost      = 486, //
        Endrain           = 487, // fenrir 96
        Enaspir           = 488, // fenrir 96
        Afterglow         = 489, // ws aftereffect
        BrazenStrength    = 490,
        InnerStrength     = 491,
        Asylum            = 492,
        SubtleSorcery     = 493,
        Stymie            = 494,
        // none                       = 495,
        Intervene       = 496,
        SoulEnslavement = 497,
        Unleash         = 498,
        ClarionCall     = 499,
        Overkill        = 500,
        Yaegasumi       = 501,
        Mikage          = 502,
        FlyHigh         = 503,
        AstralConduit   = 504,
        UnbridledWisdom = 505,
        // none                      = 506,
        GrandPas          = 507,
        WidenedCompass    = 508,
        OdyllicSubterfuge = 509,
        ErgonMight        = 510,
        ReiveMark         = 511,
        Ionis             = 512,
        Bolster           = 513,
        // none                      = 514,
        LastingEmanation  = 515,
        EclipticAttrition = 516,
        CollimatedFervor  = 517,
        Dematerialize     = 518,
        TheurgicFocus     = 519,
        // none                      = 520,
        // none                      = 521,
        ElementalSforzo    = 522,
        Ignis              = 523,
        Gelus              = 524,
        Flabra             = 525,
        Tellus             = 526,
        Sulpor             = 527,
        Unda               = 528,
        Lux                = 529,
        Tenebrae           = 530,
        Vallation          = 531,
        Swordplay          = 532,
        Pflug              = 533,
        Embolden           = 534,
        Valiance           = 535,
        Gambit             = 536,
        Liement            = 537,
        OneForAll          = 538,
        Regen2             = 539,
        Poison2            = 540,
        Refresh2           = 541,
        StrBoost3          = 542,
        DexBoost3          = 543,
        VitBoost3          = 544,
        AgiBoost3          = 545,
        IntBoost3          = 546,
        MndBoost3          = 547,
        ChrBoost3          = 548,
        AttackBoost2       = 549,
        DefenseBoost2      = 550,
        MagicAtkBoost2     = 551,
        MagicDefBoost2     = 552,
        AccuracyBoost2     = 553,
        EvasionBoost2      = 554,
        MagicAccBoost2     = 555,
        MagicEvasionBoost  = 556,
        AttackDown2        = 557,
        DefenseDown2       = 558,
        MagicAtkDown2      = 559,
        MagicDefDown2      = 560,
        AccuracyDown2      = 561,
        EvasionDown2       = 562,
        MagicAccDown2      = 563,
        MagicEvasionDown2  = 564,
        Slow2              = 565,
        Paralysis2         = 566,
        Weight2            = 567,
        Foil               = 568,
        Blaze_ofGlory      = 569,
        Battuta            = 570,
        Rayke              = 571,
        AvoidanceDown      = 572,
        DelugeSpikes       = 573,
        FastCast           = 574,
        Gestation          = 575,
        Doubt              = 576, // bully: intimidation enfeeble status
        CaitSithSFavor     = 577,
        Fishy1ntuition     = 578,
        Commitment         = 579,
        Haste2             = 580,
        Flurry2            = 581,
        Apogee             = 583,
        Entrust            = 584,
        Costume2           = 585,
        CuringConduit      = 586,
        TpBonus            = 587,
        FinishingMove_6    = 588,
        Firestorm2         = 589,
        Hailstorm2         = 590,
        Windstorm2         = 591,
        Sandstorm2         = 592,
        Thunderstorm2      = 593,
        Rainstorm2         = 594,
        Aurorastorm2       = 595,
        Voidstorm2         = 596,
        Inundation         = 597,
        Cascade            = 598,
        ConsumeMana        = 599,
        RuneistsRoll       = 600,
        CrookedCards       = 601,
        Vorseal            = 602,
        Elvorseal          = 603,
        MightyGuard        = 604,
        GaleSpikes         = 605,
        ClodSpikes         = 606,
        GlintSpikes        = 607,
        NegateVirus        = 608,
        NegateCurse        = 609,
        NegateCharm        = 610,
        MagicEvasionBoost2 = 611,
        // effect icons in packet can go from 0-767, so no custom effects should go in that range.

        // purchased from cruor prospector
        AbysseaStr = 768,
        AbysseaDex = 769,
        AbysseaVit = 770,
        AbysseaAgi = 771,
        Abyssea1nt = 772,
        AbysseaMnd = 773,
        AbysseaChr = 774,
        AbysseaHp  = 775,
        AbysseaMp  = 776,

        // *prowess increases not currently retail accurate.
        // gov prowess bonus effects, real effect at id 474
        ProwessCasketRate    = 777, // (unimplemented)
        ProwessSkillRate     = 778, // (unimplemented)
        ProwessCrystal_yeild = 779, // (unimplemented)
        ProwessTh            = 780, // +1 per tier
        ProwessAttackSpeed   = 781, // *flat 4% for now
        ProwessHpMp          = 782, // base 3% and another 1% per tier.
        ProwessAccRacc       = 783, // *flat 4% for now
        ProwessAttRatt       = 784, // *flat 4% for now
        ProwessMaccMatk      = 785, // *flat 4% for now
        ProwessCurePotency   = 786, // *flat 4% for now
        ProwessWsDmg         = 787, // (unimplemented) 2% per tier.
        Prowess_killer       = 788, // *flat +4 for now
        // end gov prowess fakery
        FieldSupportFood  = 789, // used by fov/gov food buff.
        Mark_ofSeed       = 790, // tracks 30 min timer in acp mission "those who lurk in shadows (ii)"
        TooHigh           = 791, // indicates a target is airborne and unable to be hit by normal melee attacks
        SuperBuff         = 792,
        NinjutsuEleDebuff = 793,
        Healing           = 794,
        Leavegame         = 795,
        HasteSambaHaste   = 796,
        Teleport          = 797,
        Chainbound        = 798,
        Skillchain        = 799,
        Dynamis           = 800,
        Meditate          = 801, // dummy effect for sam meditate ja

        NoBuff = 0xFFFF
    };
}
