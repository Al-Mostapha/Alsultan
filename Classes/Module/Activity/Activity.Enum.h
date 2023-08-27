#pragma once

enum class EActivityTime{
  None = 0,
  CHEST_AWARD = 9001000,
  CELEBRATE_ACIVITY = 9001001,
  EXCHANGE_MALL = 9001003,
  GROUP_BUY = 9001005,
  BUMPER_MAP_RES = 9001010,
  BUMPER_TREVIFOUNTAIN = 9001011,
  BUMPER_CITY_RES = 9001012,
  ABC_CLUB = 9001013,
  ESCORT = 9001017,
  PYRAMIDACTIVITY = 9001018,
  GROWUPFUND = 9001019,
  SIEGE_COMBAT = 9001020,
  PERSON_LIMITED_TIME_ACTIVITY = 9001030,
  DEVELOP_ARMAMENT_ACTIVITY = 9001031,
  CASTLE_UPGRADE_ACTIVITY = 9001032,
  SALESROOM_ACTIVITY = 9001034,
  SIGN_REWARD_ACTIVITY = 9001038,
  CRAZY_GET_POINT_ACTIVITY = 9001039,
  MONSTERPALACE_ACTIVITY = 9001040,
  LIMITED_DISCOUNT_ACTIVITY = 9001041,
  KING_GROUP_BUY_ACTIVITY = 9001043,
  FLOWER_ACTIVITY_RANK = 9001044,
  TREASUREBOWL_ACTIVITY = 9001046,
  ALLIANCE_MOBILIZATION_ACTIVITY = 9001048,
  SurprisedDropActivity_0 = 9001049,
  SurprisedDropActivity_1 = 9001050,
  SurprisedDropActivity_2 = 9001051,
  SurprisedDropActivity_3 = 9001052,
  NEW_KING_RISES_ACTIVITY = 9001053,
  NEW_KING_RISES_ACTIVITY_NORMAL = 9001059,
  STRONGEST_LORD = 9001061,
  ROME_ACTIVITY = 9001062,
  HERO_TRIAL = 9001063,
  KINGDOM_BATTLE = 9001064,
  CUMU_ACTIVITY_TOTAL = 9001065,
  PYRAMID_BATTLE = 9001066,
  SURPRISED_DROP = 9001067,
  SERVER_EXP_DOUBLE_ACTIVITY = 9001068,
  RED_PACKAGE_ACTIVITY = 9001069,
  SurprisedDrop_2_Activity_0 = 9001070,
  SurprisedDrop_2_Activity_1 = 9001071,
  SurprisedDrop_2_Activity_2 = 9001072,
  SurprisedDrop_2_Activity_3 = 9001073,
  LEGEND_LORD = 9001074,
  RECHARGE_GOLD_FOR_REWARD = 9001075,
  GREAT_CHALLENGE_ACTIVITY_1 = 9001076,
  GREAT_CHALLENGE_ACTIVITY_2 = 9001077,
  GREAT_CHALLENGE_ACTIVITY_3 = 9001078,
  GREAT_CHALLENGE_ACTIVITY_4 = 9001079,
  GREAT_CHALLENGE_ACTIVITY_5 = 9001080,
  HERO_BATTLE_BOSS = 9001081,
  ARENA_ACTIVITY = 9001082,
  GAME_SETTINGINV_ITEFRIEND = 9001084,
  LegendHegemon_1 = 9001085,
  LegendHegemon_2 = 9001086,
  LegendHegemon_3 = 9001087,
  LegendHegemon_4 = 9001088,
  LegendHegemon_5 = 9001089,
  LegendHegemon_6 = 9001090,
  RUINS_WAR = 9001091,
  GREAT_CHALLENGE_ACTIVITY_6 = 9001092,
  TURNTABLE_ACTIVITY = 9001109,
  GIFT_PACKAGE_ACTIVITY = 9001111,
  FRIEND_CALLBACK = 9001113,
  FRIEND_HONORBACK = 9001114,
  FULL_DAY_SPRINT_ACTIVITY = 9001115,
  SUNSET_WELFARE_ACTIVITY = 9001119,
  CROSS_MISSION = 9001120,
  DEVIL_VALLEY_ACTIVITY = 9001121,
  CRAZY_DROP_ACTIVITY_0 = 9001122,
  CRAZY_DROP_ACTIVITY_1 = 9001123,
  CRAZY_DROP_ACTIVITY_2 = 9001124,
  CRAZY_DROP_ACTIVITY_3 = 9001125,
  KNIGHTS_CHARGE = 9001126,
  KITS_ACTIVITY = 9001127,
  LUCKY_BLESSING_ACTIVITY = 9001128,
  RIDES_EXCHANGE_MALL = 9001129,
  LOGIN_GIFT = 9001130,
  ANNIHILATION = 9001131,
  ROYAL_SUMMONS = 9001132,
  EXPEDITON = 9001133,
  PSD_RED_PACKAGE_ACTIVITY = 9001135,
  STAR_RHAPSODY = 9001140,
  PALATIAL_CEREMONY = 9001141,
  PETRA_RARE_TREASURE = 9001142,
  EXCHANGE_MALL_GREEN_GEM = 9001143,
  EXCHANGE_MALL_RED_GEM = 9001144,
  SUPER_COMMANDER = 9001145,
  HERO_SECRET_ACTIVITY = 9001146,
  CUMU_ACTIVITY_RECHARGE = 9001147,
  CUMU_ACTIVITY_CONSUME = 9001148,
  GOVERNING_COUNTRY_ACTIVITY = 9001149,
  EPIC_WAR_EXP_MULTIPLE = 9001150,
  AMAZING_FORTUNE = 9001151,
  VALUE_REBATE_ACTIVITY = 9001153,
  EXCHANGE_MALL_CRAZY_HEART = 9001154,
  SEA_MONSTER_INVADE_ACTIVITY = 9001156,
  OUTS_STANDINGS = 9001157,
  RECRUITMENT_MATERIALS = 9001158,
  KILL_SEA_MONSTER_ACTIVITY = 9001162,
  PLEAD_ACTIVITY = 9001164,
  MONSTERPALACE_ENHANCE = 9001166,
  WRATH_BEAST_ACTIVITY = 9001168,
  EXCHANGE_MALL_ICE = 9001169,
  EXCHANGE_MALL_YEAR = 9001170,
  EXCHANGE_MALL_HEART = 9001171,
  EXCHANGE_MALL_RAMADAN = 9001172,
  KINGDOM_FAVOR = 9001173,
  NEW_SALESROOM_ACTIVITY = 9001174,
  HERO_FESTIVAL = 9001175,
  EQUIPMENT_REMAKE_ACTIVITY = 9001176,
  ANNIVERSARY_TREASURE_HUNT = 9001177,
  CASTLE_PRIVILEGE_GIFT_ACTIVITY = 9001178,
  FOURTH_ANNIVERSARY_EXCHANGE = 9001179,
  EXCHANGE_MALL_SPIRITUAL_GIFT = 9001180,
  EXCHANGE_MALL_HALLOWEEN = 9001181,
  EXCHANGE_MALL_HEART_NEW = 9001183,
  EXCHANGE_MALL_RAMADAN_NEW = 9001184,
  EXCHANGE_MALL_NEW_YEAR = 9001185,
  EXCHANGE_MALL_SPRING_FESTIVAL = 9001186,
  EXCHANGE_MALL_HIGH_RAMADAN = 9001187,
  EXCHANGE_MALL_SALARY = 9001188,
  EXCHANGE_MALL_ARENA = 9001189,
  EXCHANGE_MALL_NEW_YEAR_RUBY = 9001190,
  EXCHANGE_MALL_NEW_DAY_TASK = 9001220,
  SPIRITUAL_GIFT = 9001191,
  UPGRADE_REWARD_ACTIVITY = 9001192,
  NEWKING_TRAIL = 9001193,
  MANUAL_GIFT_ACTIVITY = 9001194,
  PUMPKIN_ACTIVITY = 9001196,
  ENDLESS_TRIALS_ACTIVITY = 9001197,
  WISH_TREE_ACTIVITY = 9001198,
  TREASURE_PACKAGE = 9001199,
  COMMUNITY_CENTER = 9001200,
  ANCIENT_TREASURE_ACTIVITY = 9001201,
  CommunityCenterMainUI = 9001202,
  LUCKY_FLIP_ACTIVITY = 9001203,
  NEW_YEARS_DAY = 9001204,
  COLLECT_SALARY_ACTIVITY = 9001206,
  EXCHANGE_MALL_BARBEQUE = 9001211,
  EXCHANGE_MALL_CEREMONY = 9001212,
  EXCHANGE_MALL_9001213 = 9001213,
  EXCHANGE_MALL_SNATCH_TREASURE = 9001214,
  EXCHANGE_MALL_2020_ANNIVERSARY = 9001215,
  EXCHANGE_MALL_MES_CASTLE = 9001216,
  EXCHANGE_MALL_GF_CASTLE = 9001218,
  EXCHANGE_MALL_ICE_CRAZY = 9001219,
  EXCHANGE_ROAD_TO_GLORY = 9001221,
  EXCHANGE_FIVE_YEAR_BACK = 9001222,
  EXCHANGE_MALL_RAMADAN_2021 = 9001223,
  EXCHANGE_MALL_9001224 = 9001224,
  EXCHANGE_MALL_KIND = 9001225,
  EXCHANGE_MALL_COMMON_DRESS = 9001226,
  EXCHANGE_MALL_DRESS_ROLL = 9001227,
  EXCHANGE_MALL_DRESS_ICE_CASTLE = 9001228,
  EXCHANGE_MALL_STAR_MOON_KEY = 9001229,
  EXCHANGE_MALL_THUNDERCLOUD = 9001230,
  EXCHANGE_MALL_COFFEE_TIMES = 9001231,
  EXCHANGE_MALL_NUMBER_ONE = 9001232,
  EXCHANGE_MALL_STAR_MOON_TREASURE = 9001233,
  EXCHANGE_MALL_SIXTH_YEAR_ANNIVERSARY = 9001234,
  EXCHANGE_MALL_TROOPS_MARCHING_EFFECT = 9001235,
  EXCHANGE_MALL_PAY_DRESS_UP = 9001236,
  EXCHANGE_MALL_RED_GEM_CROSS_SERVER = 9001237,
  JADE_STONE_MALL_ACTIVITY = 9001241,
  WAR_TREASURE_ACTIVITY = 9001243,
  RADIANCE_WAR_ACTIVITY = 9001253,
  PYRAMID_BATTLE_PBL = 9001254,
  SUMMER_PRAY_ACTIVITY = 9001255,
  GLORIOUS_CONTEST = 9001256,
  SEMLUK_EXPERIENCE_BALL = 9001257,
  EQUIP_ACTIVITY = 9001258,
  GLORIOUS_STAR_LAMP_ACTIVITY = 9001259,
  GEM_GOODS_ACTIVITY = 9001261,
  RADIANCE_GUARDIAN_ACTIVITY = 9001262,
  GLORIOUS_SHINE_ACTIVITY = 9001263,
  LUXURY_REBATE_ACTIVITY = 9001264,
  CASTLE_UP_LEVEL_ACTIVITY = 9001265,
  RECHARGE_ACTIVITY_GIFT_ACTIVITY = 9001266,
  EID_TYCOON_ACTIVITY = 9001268,
  RAIDERS_LOST_ARK = 9001270,
  ANCIENT_REEL_ACTIVITY = 9001271,
  PRECIOUS_TREASURE_ACTIVITY = 9001272,
  TONGTIAN_TOWER_ACTIVITY = 9001273,
  CANYON_TREASURE_HUNT = 9001274,
  ANNIVERSARY_CROSSDECRYPTION = 9001279,
  ANNIVERSARY_CAMPFIRE_ACTIVITY = 9001281,
  FIRE_SECRET_ORDER_ACTIVITY = 9001282,
  CASTLE_POWER_ACTIVITY = 9001288,
  SULTAN_BACK_MAIN_ACTIVITY = 9001289,
  SULTAN_BACK_LOGIN_ACTIVITY = 9001290,
  SULTAN_WAR_QUEST_ACTIVITY = 9001291,
  SULTAN_BACK_RETURN_ACTIVITY = 9001292,
  PRESENT_GIFT_ACTIVITY = 9001293,
  RECHARGE_NEW_USER = 9001294,
  SultanBackWelcomeActivity = 9001295,
  SULTAN_BACK_LUXURYGIFT_ACTIVITY = 9001296,
  SULTAN_BACK_REBATE_ACTIVITY = 9001297,
  SULTAN_BACK_CALL_FRIENDS = 9001298,
  SULTAN_BACK_FRIEND_COMEBACK = 9001299,
  TRAIN_POWER_ACTIVITY = 9001300,
  LostRuinsActivity = 9001301,
  MAGICAL_DOMINO = 9001302,
  HERO_AWAKE_ACTIVTY = 9001303,
  ICE_CRAZY_NIGHT_ACTIVITY = 9001307,
  NEW_RECHARGE_GOLD_FOR_REWARD = 9001309,
  CALENDAR_WINTER_ACTIVITY = 9001311,
  LAMP_SECRET_ACTIVITY = 9001312,
  PYRAMID_TREASURE_ACTIVITY = 9001314,
  CRAZY_SEPTET_ACTIVITY = 9001315,
  SULTAN_EX_RECAHRGE_PRESENT = 9001316,
  ORIENT_PRINCE_GIFT = 9001317,
  PLAN_THOROUGH_ACTIVITY = 9001319,
  CHANGE_DAY_ACTIVITY = 9001320,
  GLORY_ROAD_ACTIVITY = 9001321,
  PREDOWNLOAD_REWARD_ACTIVITY = 9001322,
  LUCKY_FALCON = 9001323,
  MERCHANT_OF_SERICA = 9001324,
  BUBBLE_REWARD_ACTIVITY = 9001332,
  WindTowerActivity = 9001333,
  NEW_CRAZY_SEPTET_ACTIVITY = 9001335,
  PAINTED_EGG_CRAZY_ACTIVITY = 9001337,
  KOH_MIGRATE = 9001338,
  WARM_HEART_ACTIVITY = 9001339,
  DROP_BOX_ACTIVITY = 9001340,
  STAR_MOON_TREASURE_ACTIVITY = 9001341,
  CASTLE_REWARD_ACTIVITY = 9001342,
  NEW_PRINCE_GIFT_ACTIVITY = 9001345,
  NEW_SERVER_JOURNEY_ACTIVITY = 9001346,
  KING_OF_GLORY_ACTIVITY = 9001347,
  GROOM_HORSES_AND_TROOPS = 9001348,
  SINBAD_TREASURE = 9001349,
  ATLANTIS_PRIVILEGE_ACTIVITY = 9001350,
  CAVALRY_RISE_ACTIVITY = 9001351,
  COFFEE_CRAFTSMAN_ACTIVITY = 9001352,
  SHEEP_RUN_ACTIVITY = 9001353,
  SMELT_ACTIVITY = 9001354,
  IRON_BLOOD_ACTIVITY = 9001355,
  EARTH_TREASURE_ACTIVITY = 9001356,
  MERMAID_GIFT_ACTIVITY = 9001357,
  CAVE_EXPLORE_ACTIVITY = 9001358,
  CHISEL_STONE_ACTIVITY = 9001359,
  ANNIV_COLOSSUS_ACTIVITY = 9001360,
  MAGIC_HERB_ACTIVITY = 9001361,
  SIX_YEAR_ACTIVITY = 9001362,
  ARTIFACT_ARRIVE_ACTIVITY = 9001363,
  H5_6TH_ACTIVITY = 9001364,
  HERO_AWAKE_CRIT_ACTIVTY = 9001365,
  ATLANTIS_WAR_ACTIVITY = 9001366,
  GEM_EXCHANGE_MALL = 9001367,
  WISE_TUTOR_ACTIVITY = 9001368,
  BATTLEFIELD_TRAINING = 9001369,
  PREFERENTIAL_SHOP_ACTIVITY = 9001370,
  ARMY_TRANSFER_ACTIVTY = 9001371,
  GEM_EXCHANGE_ACTIVITY = 9001373,
  EXOTIC_PAVILION_ACTIVITY = 9001374,
  WASTELAND = 9001375,
  DESERT_TREASURE_ACTIVITY = 9001376,
  NEW_YEAR_CARNIVAL_2022 = 9001377,
  SNOWY_NIGHT_CARNIVAL_ACTIVITY = 9001378,
  SNOWMAN_CELEBRATION_ACTIVITY = 9001379,
  NEW_YEAR_RECAHRGE_PRESENT = 9001380,
  COMMON_NDAYS_TASKRUSH_ACTIITY = 9001381,
  SnowWolfLostActivity = 9001382,
  CUMULATIVE_RECHARGE_2021 = 9001383,
  NEW_YEAR_CARNIVAL_ACTIVITY = 9001384,
  EXCHANGE_MALL_ACTIVITY_9001385 = 9001385,
  RAMADAN_SHINING_CASTLE_4 = 9001396,
  DEADLY_HUNTING_ACTIVITY = 9001397,
  HERO_ADVANCE_SKILL_CRIT_ACTIVITY = 9001398,
  CRAZY_TRIO_ACTIVITY = 9001106,
  DAILY_DISCOUNT_GIFT_ACTIVITY = 9001108,
  GEOCENTRIC_ADVENTURE = 9001501,
  LuckyRechargeTaskActivity = 9001502,
  MOVE_CITY_ACTIVIYT = 9001503,
  UNCHARTED_ADVENTURE = 9001504,
  SLOT_MACHINE = 9001505,
  GoldPackage = 9001506,
  COST_GOLD_FOR_GIFT = 9001507,
  SEVEN_DAYS_SIGNIN = 9001508,
  NEW_KING_FUND = 9001509,
  PARTY_ACTIVITY = 9001511,
  UNCHARTED_HELP = 9001512,
  CHRISTMAS_BATTLE = 9001513,
  CHRISTMAS_TREE_PRODUCTION = 9001514,
  DECRYPTION_ACTIVITY = 9001516,
  ANNIVERSARY_CELEBRATION = 9001517,
  NEW_SERVER_RANK_MATCH = 9001518,
  EnjoyLottery = 9001519,
  WEEKLY_SPECIAL = 9001520,
  SPEND_GOLD_REBATE = 9001521,
  NEW_TOTAL_PAY_ACTIVITY = 9001522,
  CRAZY_SHOPPING_ACTIVITY = 9001523,
  NEW_CROSS_MISSION = 9001525,
  GREAT_CHALLENGE_ACTIVITY_7 = 9001526,
  GREAT_CHALLENGE_ACTIVITY_8 = 9001527
};

enum class EActivityCenter{
  STRONGEST_LORD = 8001000,
  ROME_ACTIVITY = 8001001,
  HERO_TRIAL = 8001002,
  KINGDOM_BATTLE = 8001003,
  CUMU_ACTIVITY = 8001004,
  PYRAMID_BATTLE = 8001005,
  SurprisedDrop = 8001006,
  GreatChallenge = 8001007,
  LegendHegemon = 8001008,
  CRAZY_DROP = 8001009,
  CommunityCenter_1 = 8001010,
  CommunityCenter_2 = 8001011,
  CommunityCenter_3 = 8001012,
  CommunityCenter_4 = 8001013,
  CommunityCenter_5 = 8001014,
  CommunityCenter_6 = 8001015,
  PYRAMID_BATTLE_PBL = 8001016,
  FIVE_ANNIVERSARY = 8001017,
  SultanBack = 8001018,
  ACTIVITY_CENTER_TAG_1 = 8001019,
  ACTIVITY_CENTER_TAG_2 = 8001020,
  MAIN_CITY_BILLBOARD = 8001021,
  ARMYEXCHANGE_ACTIVITY = 8001022,
  NEWSERVERBACK_ACTIVITY = 8001023
};

enum class EActivityState  {
  None =0,
  Close = 1,
  Prepare = 2,
  Open = 3,
  Calculate = 4
};

enum class EATBuildingStatus {
  None = -1,
  AT_INIT = 0,
  AT_EXPLORE = 1,
  AT_MINNING = 2
};