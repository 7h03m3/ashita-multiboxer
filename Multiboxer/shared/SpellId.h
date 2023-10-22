#pragma once

namespace shared
{
    enum class SpellId
    {
        cure          = 1,
        Cure2         = 2,
        Cure3         = 3,
        Cure4         = 4,
        Cure5         = 5,
        Cure6         = 6,
        Curaga        = 7,
        Curaga2       = 8,
        Curaga3       = 9,
        Curaga4       = 10,
        Curaga5       = 11,
        Raise         = 12,
        Raise2        = 13,
        Poisona       = 14,
        Paralyna      = 15,
        Blindna       = 16,
        Silena        = 17,
        Stona         = 18,
        Viruna        = 19,
        Cursna        = 20,
        Holy          = 21,
        Holy2         = 22,
        Dia           = 23,
        Dia2          = 24,
        Dia3          = 25,
        Dia4          = 26,
        Dia5          = 27,
        Banish        = 28,
        Banish2       = 29,
        Banish3       = 30,
        Banish4       = 31,
        Banish5       = 32,
        Diaga         = 33,
        Diaga2        = 34,
        Diaga3        = 35,
        Diaga4        = 36,
        Diaga5        = 37,
        Banishga      = 38,
        Banishga2     = 39,
        Banishga3     = 40,
        Banishga4     = 41,
        Banishga5     = 42,
        Protect       = 43,
        Protect2      = 44,
        Protect3      = 45,
        Protect4      = 46,
        Protect5      = 47,
        Shell         = 48,
        Shell2        = 49,
        Shell3        = 50,
        Shell4        = 51,
        Shell5        = 52,
        Blink         = 53,
        Stoneskin     = 54,
        Aquaveil      = 55,
        Slow          = 56,
        Haste         = 57,
        Paralyze      = 58,
        Silence       = 59,
        Barfire       = 60,
        Barblizzard   = 61,
        Baraero       = 62,
        Barstone      = 63,
        Barthunder    = 64,
        Barwater      = 65,
        Barfira       = 66,
        Barblizzara   = 67,
        Baraera       = 68,
        Barstonra     = 69,
        Barthundra    = 70,
        Barwatera     = 71,
        Barsleep      = 72,
        Barpoison     = 73,
        Barparalyze   = 74,
        Barblind      = 75,
        Barsilence    = 76,
        Barpetrify    = 77,
        Barvirus      = 78,
        Slow2         = 79,
        Paralyze2     = 80,
        RecallJugner  = 81,
        RecallPashh   = 82,
        RecallMeriph  = 83,
        Baramnesia    = 84,
        Baramnesra    = 85,
        Barsleepra    = 86,
        Barpoisonra   = 87,
        Barparalyzra  = 88,
        Barblindra    = 89,
        Barsilencera  = 90,
        Barpetra      = 91,
        Barvira       = 92,
        Cura          = 93,
        Sacrifice     = 94,
        Esuna         = 95,
        Auspice       = 96,
        Reprisal      = 97,
        Repose        = 98,
        Sandstorm     = 99,
        Enfire        = 100,
        Enblizzard    = 101,
        Enaero        = 102,
        Enstone       = 103,
        Enthunder     = 104,
        Enwater       = 105,
        Phalanx       = 106,
        Phalanx2      = 107,
        Regen         = 108,
        Refresh       = 109,
        Regen2        = 110,
        Regen3        = 111,
        Flash         = 112,
        Rainstorm     = 113,
        Windstorm     = 114,
        Firestorm     = 115,
        Hailstorm     = 116,
        Thunderstorm  = 117,
        Voidstorm     = 118,
        Aurorastorm   = 119,
        TeleportYhoat = 120,
        TeleportAltep = 121,
        TeleportHolla = 122,
        TeleportDem   = 123,
        TeleportMea   = 124,
        Protectra     = 125,
        Protectra2    = 126,
        Protectra3    = 127,
        Protectra4    = 128,
        Protectra5    = 129,
        Shellra       = 130,
        Shellra2      = 131,
        Shellra3      = 132,
        Shellra4      = 133,
        Shellra5      = 134,
        Reraise       = 135,
        Invisible     = 136,
        Sneak         = 137,
        Deodorize     = 138,
        TeleportVahzl = 139,
        Raise3        = 140,
        Reraise2      = 141,
        Reraise3      = 142,
        Erase         = 143,
        Fire          = 144,
        Fire2         = 145,
        Fire3         = 146,
        Fire4         = 147,
        Fire5         = 148,
        Blizzard      = 149,
        Blizzard2     = 150,
        Blizzard3     = 151,
        Blizzard4     = 152,
        Blizzard5     = 153,
        Aero          = 154,
        Aero2         = 155,
        Aero3         = 156,
        Aero4         = 157,
        Aero5         = 158,
        Stone         = 159,
        Stone2        = 160,
        Stone3        = 161,
        Stone4        = 162,
        Stone5        = 163,
        Thunder       = 164,
        Thunder2      = 165,
        Thunder3      = 166,
        Thunder4      = 167,
        Thunder5      = 168,
        Water         = 169,
        Water2        = 170,
        Water3        = 171,
        Water4        = 172,
        Water5        = 173,
        Firaga        = 174,
        Firaga2       = 175,
        Firaga3       = 176,
        Firaga4       = 177,
        Firaga5       = 178,
        Blizzaga      = 179,
        Blizzaga2     = 180,
        Blizzaga3     = 181,
        Blizzaga4     = 182,
        Blizzaga5     = 183,
        Aeroga        = 184,
        Aeroga2       = 185,
        Aeroga3       = 186,
        Aeroga4       = 187,
        Aeroga5       = 188,
        Stonega       = 189,
        Stonega2      = 190,
        Stonega3      = 191,
        Stonega4      = 192,
        Stonega5      = 193,
        Thundaga      = 194,
        Thundaga2     = 195,
        Thundaga3     = 196,
        Thundaga4     = 197,
        Thundaga5     = 198,
        Waterga       = 199,
        Waterga2      = 200,
        Waterga3      = 201,
        Waterga4      = 202,
        Waterga5      = 203,
        Flare         = 204,
        Flare2        = 205,
        Freeze        = 206,
        Freeze2       = 207,
        Tornado       = 208,
        Tornado2      = 209,
        Quake         = 210,
        Quake2        = 211,
        Burst         = 212,
        Burst2        = 213,
        Flood         = 214,
        Flood2        = 215,
        Gravity       = 216,
        Gravity2      = 217,
        Meteor        = 218,
        Comet         = 219,
        Poison        = 220,
        Poison2       = 221,
        Poison3       = 222,
        Poison4       = 223,
        Poison5       = 224,
        Poisonga      = 225,
        Poisonga2     = 226,
        Poisonga3     = 227,
        Poisonga4     = 228,
        Poisonga5     = 229,
        Bio           = 230,
        Bio2          = 231,
        Bio3          = 232,
        Bio4          = 233,
        Bio5          = 234,
        Burn          = 235,
        Frost         = 236,
        Choke         = 237,
        Rasp          = 238,
        Shock         = 239,
        Drown         = 240,
        Retrace       = 241,
        AbsorbAcc     = 242,
        AbsorbAttri   = 243,
        Meteor2       = 244,
        Drain         = 245,
        Drain2        = 246,
        Aspir         = 247,
        Aspir2        = 248,
        BlazeSpikes   = 249,
        IceSpikes     = 250,
        ShockSpikes   = 251,
        Stun          = 252,
        Sleep         = 253,
        Blind         = 254,
        Break         = 255,
        Virus         = 256,
        Curse         = 257,
        Bind          = 258,
        Sleep2        = 259,
        Dispel        = 260,
        Warp          = 261,
        Warp2         = 262,
        Escape        = 263,
        Tractor       = 264,
        Tractor2      = 265,
        AbsorbStr     = 266,
        AbsorbDex     = 267,
        AbsorbVit     = 268,
        AbsorbAgi     = 269,
        AbsorbInt     = 270,
        AbsorbMnd     = 271,
        AbsorbChr     = 272,
        Sleepga       = 273,
        Sleepga2      = 274,
        AbsorbTp      = 275,
        Blind2        = 276,
        DreadSpikes   = 277,
        Geohelix      = 278,
        Hydrohelix    = 279,
        Anemohelix    = 280,
        Pyrohelix     = 281,
        Cryohelix     = 282,
        Ionohelix     = 283,
        Noctohelix    = 284,
        Luminohelix   = 285,
        Addle         = 286,
        Klimaform     = 287,
        FireSpirit    = 288,
        IceSpirit     = 289,
        AirSpirit     = 290,
        EarthSpirit   = 291,
        ThunderSpirit = 292,
        WaterSpirit   = 293,
        LightSpirit   = 294,
        DarkSpirit    = 295,
        Carbuncle     = 296,
        Fenrir        = 297,
        Ifrit         = 298,
        Titan         = 299,
        Leviathan     = 300,
        Garuda        = 301,
        Shiva         = 302,
        Ramuh         = 303,
        Diabolos      = 304,
        Odin          = 305,
        Alexander     = 306,
        CaitSith      = 307,
        AnimusAugeo   = 308,
        AnimusMinuo   = 309,
        Enlight       = 310,
        Endark        = 311,
        Enfire2       = 312,
        Enblizzard2   = 313,
        Enaero2       = 314,
        Enstone2      = 315,
        Enthunder2    = 316,
        Enwater2      = 317,
        MonomiIchi    = 318,
        AishaIchi     = 319,
        KatonIchi     = 320,
        KatonNi       = 321,
        KatonSan      = 322,
        HyotonIchi    = 323,
        HyotonNi      = 324,
        HyotonSan     = 325,
        HutonIchi     = 326,
        HutonNi       = 327,
        HutonSan      = 328,
        DotonIchi     = 329,
        DotonNi       = 330,
        DotonSan      = 331,
        RaitonIchi    = 332,
        RaitonNi      = 333,
        RaitonSan     = 334,
        SuitonIchi    = 335,
        SuitonNi      = 336,
        SuitonSan     = 337,
        UtsusemiIchi  = 338,
        UtsusemiNi    = 339,
        UtsusemiSan   = 340,
        JubakuIchi    = 341,
        JubakuNi      = 342,
        JubakuSan     = 343,
        HojoIchi      = 344,
        HojoNi        = 345,
        HojoSan       = 346,
        KurayamiIchi  = 347,
        KurayamiNi    = 348,
        KurayamiSan   = 349,
        DokumoriIchi  = 350,
        DokumoriNi    = 351,
        DokumoriSan   = 352,
        TonkoIchi     = 353,
        TonkoNi       = 354,
        Siren         = 355,
        Paralyga      = 356,
        Slowga        = 357,
        Hastega       = 358,
        Silencega     = 359,
        Dispelga      = 360,
        Blindga       = 361,
        Bindga        = 362,
        // mentioned in the dats,  but we don't implement in the db
        // sleepga = 363,
        // sleepga2 = 364,
        Breakga           = 365,
        Graviga           = 366,
        Death             = 367,
        FoeRequiem        = 368,
        FoeRequiem2       = 369,
        FoeRequiem3       = 370,
        FoeRequiem4       = 371,
        FoeRequiem5       = 372,
        FoeRequiem6       = 373,
        FoeRequiem7       = 374,
        FoeRequiem8       = 375,
        HordeLullaby      = 376,
        HordeLullaby2     = 377,
        ArmysPaeon        = 378,
        ArmysPaeon2       = 379,
        ArmysPaeon3       = 380,
        ArmysPaeon4       = 381,
        ArmysPaeon5       = 382,
        ArmysPaeon6       = 383,
        ArmysPaeon7       = 384,
        ArmysPaeon8       = 385,
        MagesBallad       = 386,
        MagesBallad2      = 387,
        MagesBallad3      = 388,
        KnightsMinne      = 389,
        KnightsMinne2     = 390,
        KnightsMinne3     = 391,
        KnightsMinne4     = 392,
        KnightsMinne5     = 393,
        ValorMinuet       = 394,
        ValorMinuet2      = 395,
        ValorMinuet3      = 396,
        ValorMinuet4      = 397,
        ValorMinuet5      = 398,
        SwordMadrigal     = 399,
        BladeMadrigal     = 400,
        HuntersPrelude    = 401,
        ArchersPrelude    = 402,
        SheepfoeMambo     = 403,
        DragonfoeMambo    = 404,
        FowlAubade        = 405,
        HerbPastoral      = 406,
        ChocoboHum        = 407,
        ShiningFantasia   = 408,
        ScopsOperetta     = 409,
        PuppetsOperetta   = 410,
        JestersOperetta   = 411,
        GoldCapriccio     = 412,
        DevoteeSerenade   = 413,
        WardingRound      = 414,
        GoblinGavotte     = 415,
        CactuarFugue      = 416,
        HonorMarch        = 417,
        ProtectedAria     = 418,
        AdvancingMarch    = 419,
        VictoryMarch      = 420,
        BattlefieldElegy  = 421,
        CarnageElegy      = 422,
        MassacreElegy     = 423,
        SinewyEtude       = 424,
        DextrousEtude     = 425,
        VivaciousEtude    = 426,
        QuickEtude        = 427,
        LearnedEtude      = 428,
        SpiritedEtude     = 429,
        EnchantingEtude   = 430,
        HerculeanEtude    = 431,
        UncannyEtude      = 432,
        VitalEtude        = 433,
        SwiftEtude        = 434,
        SageEtude         = 435,
        LogicalEtude      = 436,
        BewitchingEtude   = 437,
        FireCarol         = 438,
        IceCarol          = 439,
        WindCarol         = 440,
        EarthCarol        = 441,
        LightningCarol    = 442,
        WaterCarol        = 443,
        LightCarol        = 444,
        DarkCarol         = 445,
        FireCarol2        = 446,
        IceCarol2         = 447,
        WindCarol2        = 448,
        EarthCarol2       = 449,
        LightningCarol2   = 450,
        WaterCarol2       = 451,
        LightCarol2       = 452,
        DarkCarol2        = 453,
        FireThrenody      = 454,
        IceThrenody       = 455,
        WindThrenody      = 456,
        EarthThrenody     = 457,
        LightningThrenody = 458,
        WaterThrenody     = 459,
        LightThrenody     = 460,
        DarkThrenody      = 461,
        MagicFinale       = 462,
        FoeLullaby        = 463,
        GoddesssHymnus    = 464,
        ChocoboMazurka    = 465,
        Maidens5irelai    = 466,
        RaptorMazurka     = 467,
        FoeSirvente       = 468,
        AdventurersDirge  = 469,
        SentinelsScherzo  = 470,
        FoeLullaby2       = 471,
        PiningNocturne    = 472,
        Refresh2          = 473,
        Cura2             = 474,
        Cura3             = 475,
        Crusade           = 476,
        Regen4            = 477,
        Embrava           = 478,
        BoostStr          = 479,
        BoostDex          = 480,
        Boost5it          = 481,
        BoostAgi          = 482,
        BoostInt          = 483,
        BoostMnd          = 484,
        BoostChr          = 485,
        GainStr           = 486,
        GainDex           = 487,
        Gain5it           = 488,
        GainAgi           = 489,
        GainInt           = 490,
        GainMnd           = 491,
        GainChr           = 492,
        Temper            = 493,
        Arise             = 494,
        Adloquium         = 495,
        Firaja            = 496,
        Blizzaja          = 497,
        Aeroja            = 498,
        Stoneja           = 499,
        Thundaja          = 500,
        Waterja           = 501,
        Kaustra           = 502,
        Impact            = 503,
        Regen5            = 504,
        GekkaIchi         = 505,
        YainIchi          = 506,
        MyoshuIchi        = 507,
        YurinIchi         = 508,
        KakkaIchi         = 509,
        MigawariIchi      = 510,
        Haste2            = 511,

        VenomShell = 513,

        Maelstrom = 515,

        MetallicBody = 517,

        Screwdriver = 519,

        MpDrainkiss = 521,
        DeathRay    = 522,

        Sandspin = 524,

        SmiteOfRage = 527,

        Bludgeon        = 529,
        Refueling       = 530,
        IceBreak        = 531,
        Blitzstrahl     = 532,
        SelfDestruct    = 533,
        MysteriousLight = 534,
        ColdWave        = 535,
        PoisonBreath    = 536,
        StinkingGas     = 537,
        MementoMori     = 538,
        TerrorTouch     = 539,
        SpinalCleave    = 540,
        BloodSaber      = 541,
        Digest          = 542,
        MandibularBite  = 543,
        CursedSphere    = 544,
        SickleSlash     = 545,

        Cocoon         = 547,
        FilamentedHold = 548,
        Pollen         = 549,

        PowerAttack = 551,

        DeathScissors  = 554,
        MagnetiteCloud = 555,

        EyesOnMe = 557,

        FreneticRip   = 560,
        FrightfulRoar = 561,

        HecatombWave  = 563,
        BodySlam      = 564,
        RadiantBreath = 565,

        Helldive = 567,

        JetStream  = 569,
        BloodDrain = 570,

        SoundBlast     = 572,
        FeatherTickle  = 573,
        FeatherBarrier = 574,
        Jettatura      = 575,
        Yawn           = 576,
        FootKick       = 577,
        WildCarrot     = 578,
        VoraciousTrunk = 579,

        HealingBreeze = 581,
        ChaoticEye    = 582,

        SheepSong = 584,
        RamCharge = 585,

        ClawCyclone      = 587,
        Lowing           = 588,
        DimensionalDeath = 589,

        HeatBreath      = 591,
        BlankGaze       = 592,
        MagicFruit      = 593,
        Uppercut        = 594,
        ThousandNeedles = 595,
        PineconeBomb    = 596,
        SproutSmack     = 597,
        Soporific       = 598,
        Queasyshroom    = 599,

        WildOats  = 603,
        BadBreath = 604,
        GeistWall = 605,
        AwfulEye  = 606,

        FrostBreath = 608,

        Infrasonics    = 610,
        Disseverment   = 611,
        ActinicBurst   = 612,
        ReactorCool    = 613,
        SalineCoat     = 614,
        PlasmaCharge   = 615,
        TemporalShift  = 616,
        VerticalCleave = 617,
        Blastbomb      = 618,

        BattleDance = 620,
        Sandspray   = 621,
        GrandSlam   = 622,
        HeadButt    = 623,

        BombToss = 626,

        Frypan         = 628,
        FlyingHipPress = 629,

        HydroShot      = 631,
        Diamondhide    = 632,
        Enervation     = 633,
        LightOfPenance = 634,

        WarmUp       = 636,
        Firespit     = 637,
        FeatherStorm = 638,

        TailSlap        = 640,
        HystericBarrage = 641,
        Amplification   = 642,
        Cannonball      = 643,
        MindBlast       = 644,
        Exuviation      = 645,
        MagicHammer     = 646,
        ZephyrMantle    = 647,
        Regurgitation   = 648,

        Seedspray          = 650,
        CorrosiveOoze      = 651,
        SpiralSpin         = 652,
        AsuranClaws        = 653,
        SubZeroSmash       = 654,
        TriumphantRoar     = 655,
        AcridStream        = 656,
        BlazingBound       = 657,
        PleniluneEmbrace   = 658,
        DemoralizingRoar   = 659,
        CimicineDischarge  = 660,
        AnimatingWail      = 661,
        BatteryCharge      = 662,
        Leafstorm          = 663,
        Regeneration       = 664,
        FinalSting         = 665,
        GoblinRush         = 666,
        VanityDive         = 667,
        MagicBarrier       = 668,
        WhirlOfRage        = 669,
        BenthicTyphoon     = 670,
        AuroralDrape       = 671,
        Osmosis            = 672,
        QuadraticContinuum = 673,
        Fantod             = 674,
        ThermalPulse       = 675,

        EmptyThrash      = 677,
        DreamFlower      = 678,
        Occultation      = 679,
        ChargedWhisker   = 680,
        WindsOfPromyvion = 681,
        DeltaThrust      = 682,
        EvryonesGrudge   = 683,
        ReavingWind      = 684,
        BarrierTusk      = 685,
        MortalRay        = 686,
        WaterBomb        = 687,
        HeavyStrike      = 688,
        DarkOrb          = 689,
        WhiteWind        = 690,

        SuddenLunge          = 692,
        Quadrastrike         = 693,
        VaporSpray           = 694,
        ThunderBreath        = 695,
        OrcishCounterstance  = 696,
        AmorphicSpikes       = 697,
        WindBreath           = 698,
        BarbedCrescent       = 699,
        NaturesMeditation    = 700,
        TempestuousUpheaval  = 701,
        RendingDeluge        = 702,
        EmbalmingEarth       = 703,
        ParalyzingTriad      = 704,
        FoulWaters           = 705,
        GlutinousDart        = 706,
        RetinalGlare         = 707,
        Subduction           = 708,
        ThrashingAssault     = 709,
        ErraticFlutter       = 710,
        Restoral             = 711,
        RailCannon           = 712,
        DiffusionRay         = 713,
        SinkerDrill          = 714,
        MoltingPlumage       = 715,
        NectarousDeluge      = 716,
        SweepingGouge        = 717,
        AtramentousLibations = 718,
        SearingTempest       = 719,
        SpectralFloe         = 720,
        AnvilLightning       = 721,
        Entomb               = 722,
        SaurianSlide         = 723,
        PallingSalvo         = 724,
        BlindingFulgor       = 725,
        ScouringSpate        = 726,
        SilentStorm          = 727,
        TenebralCrush        = 728,

        Thunderbolt      = 736,
        HardenShell      = 737,
        AbsoluteTerror   = 738,
        GatesOfHades     = 739,
        Tourbillion      = 740,
        PyricBulwark     = 741,
        Bilgestorm       = 742,
        Bloodrake        = 743,
        DroningWhirlwind = 744,
        Carcharian5erve  = 745,
        BlisteringRoar   = 746,
        Uproot           = 747,
        CrashingThunder  = 748,
        PolarRoar        = 749,
        MightyGuard      = 750,
        Cruel_joke       = 751,
        Cesspool         = 752,
        TearingGust      = 753,

        IndiRegen          = 768,
        IndiPoison         = 769,
        IndiRefresh        = 770,
        IndiHaste          = 771,
        IndiStr            = 772,
        IndiDex            = 773,
        Indi5it            = 774,
        IndiAgi            = 775,
        IndiInt            = 776,
        IndiMnd            = 777,
        IndiChr            = 778,
        IndiFury           = 779,
        IndiBarrier        = 780,
        IndiAcumen         = 781,
        IndiFend           = 782,
        IndiPrecision      = 783,
        Indi5oidance       = 784,
        IndiFocus          = 785,
        IndiAttunement     = 786,
        IndiWilt           = 787,
        IndiFrailty        = 788,
        IndiFade           = 789,
        IndiMalaise        = 790,
        IndiSlip           = 791,
        IndiTorpor         = 792,
        Indi5ex            = 793,
        IndiLanguor        = 794,
        IndiSlow           = 795,
        IndiParalysis      = 796,
        IndiGravity        = 797,
        GeoRegen           = 798,
        GeoPoison          = 799,
        GeoRefresh         = 800,
        GeoHaste           = 801,
        GeoStr             = 802,
        GeoDex             = 803,
        Geo5it             = 804,
        GeoAgi             = 805,
        GeoInt             = 806,
        GeoMnd             = 807,
        GeoChr             = 808,
        GeoFury            = 809,
        GeoBarrier         = 810,
        GeoAcumen          = 811,
        GeoFend            = 812,
        GeoPrecision       = 813,
        Geo5oidance        = 814,
        GeoFocus           = 815,
        GeoAttunement      = 816,
        GeoWilt            = 817,
        GeoFrailty         = 818,
        GeoFade            = 819,
        GeoMalaise         = 820,
        GeoSlip            = 821,
        GeoTorpor          = 822,
        Geo5ex             = 823,
        GeoLanguor         = 824,
        GeoSlow            = 825,
        GeoParalysis       = 826,
        GeoGravity         = 827,
        Fira               = 828,
        Fira2              = 829,
        Blizzara           = 830,
        Blizzara2          = 831,
        Aera               = 832,
        Aera2              = 833,
        Stonera            = 834,
        Stonera2           = 835,
        Thundara           = 836,
        Thundara2          = 837,
        Watera             = 838,
        Watera2            = 839,
        Foil               = 840,
        Distract           = 841,
        Distract2          = 842,
        Frazzle            = 843,
        Frazzle2           = 844,
        Flurry             = 845,
        Flurry2            = 846,
        Atomos             = 847,
        Reraise4           = 848,
        Fire5i             = 849,
        Blizzard5i         = 850,
        Aero5i             = 851,
        Stone5i            = 852,
        Thunder5i          = 853,
        Water5i            = 854,
        Enlight2           = 855,
        Endark2            = 856,
        Sandstorm2         = 857,
        Rainstorm2         = 858,
        Windstorm2         = 859,
        Firestorm2         = 860,
        Hailstorm2         = 861,
        Thunderstorm2      = 862,
        Voidstorm2         = 863,
        Aurorastorm2       = 864,
        Fira3              = 865,
        Blizzara3          = 866,
        Aera3              = 867,
        Stonera3           = 868,
        Thundara3          = 869,
        Watera3            = 870,
        FireThrenody2      = 871,
        IceThrenody2       = 872,
        WindThrenody2      = 873,
        EarthThrenody2     = 874,
        LightningThrenody2 = 875,
        WaterThrenody2     = 876,
        LightThrenody2     = 877,
        DarkThrenody2      = 878,
        Inundation         = 879,
        Drain3             = 880,
        Aspir3             = 881,
        Distract3          = 882,
        Frazzle3           = 883,
        Addle2             = 884,
        Geohelix2          = 885,
        Hydrohelix2        = 886,
        Anemohelix2        = 887,
        Pyrohelix2         = 888,
        Cryohelix2         = 889,
        Ionohelix2         = 890,
        Noctohelix2        = 891,
        Luminohelix2       = 892,
        FullCure           = 893,
        Refresh3           = 894,
        Temper2            = 895,
        Shantotto          = 896,
        Naji               = 897,
        Kupipi             = 898,
        Excenmille         = 899,
        Ayame              = 900,
        NanaaMihgo         = 901,
        Curilla            = 902,
        Volker             = 903,
        AjidoMarujido      = 904,
        Trion              = 905,
        Zeid               = 906,
        Lion               = 907,
        Tenzen             = 908,
        MihliAliapoh       = 909,
        Valaineral         = 910,
        Joachim            = 911,
        NajaSalaheem       = 912,
        Prishe             = 913,
        Ulmia              = 914,
        ShikareeZ          = 915,
        Cherukiki          = 916,
        IronEater          = 917,
        Gessho             = 918,
        Gadalar            = 919,
        Rainemard          = 920,
        Ingrid             = 921,
        LehkoHabhoka       = 922,
        Nashmeira          = 923,
        Zazarg             = 924,
        Ovjang             = 925,
        Mnejing            = 926,
        Sakura             = 927,
        Luzaf              = 928,
        Najelith           = 929,
        Aldo               = 930,
        Moogle             = 931,
        Fablinix           = 932,
        Maat               = 933,
        DominaShantotto    = 934,
        StarSibyl          = 935,
        KarahaBaruha       = 936,
        Cid                = 937,
        Gilgamesh          = 938,
        Areuhat            = 939,
        SemihLafihna       = 940,
        Elivira            = 941,
        Noillurie          = 942,
        LhuMhakaracca      = 943,
        FerreousCoffin     = 944,
        Lilisette          = 945,
        Mumor              = 946,
        UkaTotlihn         = 947,
        Klara              = 948,
        RomaaMihgo         = 949,
        KuyinHathdenna     = 950,
        Rahal              = 951,
        KoruMoru           = 952,
        PieujeUc           = 953,
        InvincibleShieldUc = 954,
        ApururuUc          = 955,
        JakohUc            = 956,
        FlaviriaUc         = 957,
        Babban             = 958,
        Abenzio            = 959,
        Rughadjeen         = 960,
        KukkiChebukki      = 961,
        Margret            = 962,
        Chacharoon         = 963,
        LheLhangavo        = 964,
        Arciela            = 965,
        Mayakov            = 966,
        Qultada            = 967,
        Adelheid           = 968,
        Amchuchu           = 969,
        Brygid             = 970,
        Mildaurion         = 971,
        Halver             = 972,
        Rongelouts         = 973,
        Leonoyne           = 974,
        Maximilian         = 975,
        KayeelPayeel       = 976,
        RobelAkbel         = 977,
        Kupofried          = 978,
        Selhteus           = 979,
        YoranOranUc        = 980,
        SylvieUc           = 981,
        Abquhbah           = 982,
        Balamor            = 983,
        August             = 984,
        Rosulatia          = 985,
        Teodor             = 986,
        Ullegore           = 987,
        MakkiChebukki      = 988,
        KingOfHearts       = 989,
        Morimar            = 990,
        Darrcuiln          = 991,
        Aahm               = 992,
        Aaev               = 993,
        Aamr               = 994,
        Aatt               = 995,
        Aagk               = 996,
        Iroha              = 997,
        Ygnas              = 998,
        Monberaux          = 999,

        ExcenmilleS = 1004,
        AyameUc     = 1005,
        MaatUc      = 1006,
        AldoUc      = 1007,
        NajaUc      = 1008,
        Lion2       = 1009,
        Zeid2       = 1010,
        Prishe2     = 1011,
        Nashmeira2  = 1012,
        Lilisette2  = 1013,
        Tenzen2     = 1014,
        Mumor2      = 1015,
        Ingrid2     = 1016,
        Arciela2    = 1017,
        Iroha2      = 1018,
        Shantotto2  = 1019,
    };
};