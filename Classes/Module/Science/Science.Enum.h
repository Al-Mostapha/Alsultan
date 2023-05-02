#pragma once
#include "Base/BaseTypeDef.h"

enum class EScience{
  None = 0,
  SharpAxe = 21001,
  Ploughing ,
  Cellar,
  DoubleSaw,
  Granary ,
  Furnace,
  IronCart,
  Pickaxe,
  Refinery,
  Purifier,
  SharpAxeII,
  PloughingII,
  CellarII,
  DoubleSawII,
  GranaryII,
  FurnaceII,
  IronCartII,
  PickaxeII,
  RefineryII,
  PurifierII,
  SupplyCart = 22001,
  Flank,
  Heal,
  Engineering,
  Treatment,
  Herbology,
  Ration,
  FlankII,
  HealII,
  PackageII,
  EngineeringII,
  TreatmentII,
  HerbologyII,
  RationII,
  Rampart = 23001,
  Embrasure,
  Battlement ,
  Deadfall,
  Blazer ,
  CityDefense,
  Smash,
  Crush,
  Crane ,
  FirstAid,
  RampartII,
  EmbrasureII,
  BattlementII,
  FortII,
  SmashII,
  BlazerII ,
  CrushII,
  CraneII,
  Recruitment = 24001,
  Swordplay,
  Archery,
  Horsemanship,
  Driving,
  Mapping,
  Cover,
  Barde,
  Shell,
  Armoring,
  Legion,
  InfantryBoost,
  ArcherBoost,
  CavalryBoost,
  ChariotBoost,
  Leadership,
  LegionII,
  SwordplayII,
  ArcheryII,
  HorsemanshipII,
  DrivingII,
  RecruitmentII,
  CoverII,
  BardeII,
  ShellII,
  ArmoringII,
  MappingII,
  InfantryBoostII,
  ArcherBoostII,
  CavalryBoostII,
  ChariotBoostII,
  LeadershipII,
  LegionIII,
  SwordplayIII,
  ArcheryIII,
  HorsemanshipIII,
  DrivingIII,
  RecruitmentIII,
  CoverIII,
  BardeIII,
  ShellIII,
  ArmoringIII,
  MappingIII,
  InfantryBoostIII,
  ArcherBoostIII,
  CavalryBoostIII,
  ChariotBoostIII,
  LeadershipIII
};

enum class EScienceType {
  None = 0,
  Resource = 1,
  CityDevelop,
  Anchor,
  Military,
  Special,
  Soldier,
  Leader,
  Hero,
  WarTechnology = 11,
  WarBattle,
  WarMilitary,
  WarCommand,
  WarLight,
  AdvancedMilitary,
  Process,
  Nebula
};

enum EScienceEffect{
  None = 0,
  WOOD_PRODUCTIVITY = 1,
  FOOD_PRODUCTIVITY = 2,
  IRON_PRODUCTIVITY = 3,
  MITHRIL_PRODUCTIVITY = 4,
  WOOD_COLLECTION = 5,
  FOOD_COLLECTION = 6,
  IRON_COLLECTION = 7,
  MITHRIL_COLLECTION = 8,
  GOLD_COLLECTION = 9,
  WAREHOUSE_PROTECTION = 10,
  FORCE_LOAD = 11,
  KILL_MARCH_SPEED = 12,
  PHYSICAL_REPLY = 13,
  CONSTRUCTION_SPEED = 14,
  WOUNDED_QUANTITY = 15,
  WOUNDED_REPLY = 16,
  FRCES_CONSUMPTION = 17,
  DEFENSE_ADD = 18,
  DEFENDERS_ATTACK = 19,
  DEFENDERS_DEFENSE = 20,
  TRAP_ATTACK = 21,
  TRAP_CAP = 22,
  CONSTRUCTION_SPEED_TRAP = 23,
  ROCKETS_CAVALRY_INJURY = 24,
  ROCKFALL_DAMAGE_INFANTRY = 25,
  BOWLS_ARCHER_INJURY = 26,
  EXPEDITION_LOSS = 27,
  SOLDIERS_TRAIN_SPEED = 28,
  INFANTRY_ATTACK = 29,
  CAVALRY_ATTACK = 30,
  ARCHER_ATTACK = 31,
  CHARIOTS_ATTACK = 32,
  INFANTRY_DEFENSE = 33,
  CAVALRY_DEFENSE = 34,
  ARCHER_DEFENSE = 35,
  CHARIOTS_DEFENSE = 36,
  INFANTRY_HEALTH = 37,
  CAVALRY_HEALTH = 38,
  ARCHER_HEALTH = 39,
  CHARIOTS_HEALTH = 40,
  MARCH_SPEED = 41,
  EXPEDITION_TROOPS = 42,
  SINGLE_TROOP_STRENGTH = 43,
  JUNIOR_COLLECT_PLUNDER = 44,
  JUNIOR_COLLECT_KO = 45,
  JUNIOR_COLLECT_TREATMENT = 46,
  JUNIOR_COLLECT_MAKEUP = 47,
  CURE_FOOTSOLDIER_SPEED_BOOST = 48,
  CURE_CAVALRY_SPEED_BOOST = 49,
  CURE_ARCHER_SPEED_BOOST = 50,
  CURE_CHARIOTS_SPEED_BOOST = 51,
  TRAIN_FOOTSOLDIER_SPEED_BOOST = 52,
  TRAIN_CAVALRY_SPEED_BOOST = 53,
  TRAIN_ARCHER_SPEED_BOOST = 54,
  TRAIN_CHARIOTS_SPEED_BOOST = 55,
  SIEGE_PLUNDER = 56,
  SIEGE_KO = 57,
  MEDIUM_COLLECT_KO = 58,
  MEDIUM_COLLECT_TREATMENT = 59,
  RECRUIT_HORN = 60,
  SOLDIER_COMPILE = 61,
  SOLDIER_ATTACK = 62,
  SOLDIER_DEFENSE = 63,
  SOLDIER_LIFE = 64,
  ENERGY_CONVERSION = 65,
  ENERGY_LIMIT = 66,
  KINGDOM_ATTACK_UP = 67,
  KINGDOM_DEF_UP = 68,
  KINGDOM_HP_UP = 69,
  CONQUEST_WAR_ATTACK_UP = 70,
  CONQUEST_WAR_DEF_UP = 71,
  CONQUEST_WAR_HP_UP = 72,
  CONQUEST_WAR_SINGLE_TROOP_STRENGTH = 73,
  PYRAMID_ATTACK_UP = 74,
  PYRAMID_DEF_UP = 75,
  PYRAMID_HP_UP = 76,
  PYRAMID_SINGLE_TROOP_STRENGTH = 77,
  RESOURCE_TECH_COST_REDUCE = 78,
  CITY_DEVELOP_TECH_COST_REDUCE = 79,
  MILITARY_TECH_COST_REDUCE = 80,
  ANCHOR_TECH_COST_REDUCE = 81,
  SOLDIER_TECH_COST_REDUCE = 82,
  LEADER_TECH_COST_REDUCE = 83,
  SPECIAL_TECH_COST_REDUCE = 84,
  BUILD_COST_REDUCE = 85,
  TECH_RESEARCH_SPEED_BOOST = 86,
  RES_PRODUCTIVITY_BOOST = 87,
  CRYSTAL_PRODUCTIVITY_BOOST = 88,
  RES_COLLECTION_SPEED_BOOST = 89,
  WARHALL_CAPACITY_VALUE_BOOST = 90,
  ELITE_SOLDIER_LIMIT_VALUE_BOOST = 91,
  LEGEND_HP_UP = 92,
  LEGEND_DEF_UP = 93,
  LEGEND_ATTACK_UP = 94,
  LEGEND_SINGLE_TROOP_STRENGTH = 95,
  EPIC_WAR_BUY_CHALLENGE_COUNT_ADD = 96,
  EPIC_WAR_ACTION_LIMIT_ADD = 97,
  EPIC_WAR_LEADER_POINT_ADD = 98,
  EPIC_WAR_RECOVERY_ACTION = 99,
  HERO_MARCH_POSITION_LIMIT = 100,
  HERO_TRAIN_POSITION_LIMIT_ADD = 101,
  CAPTURE_HERO_PROBABILITY_ADD = 102,
  TRAIN_HERO_LEADER_POINT_ADD = 103,
  HERO_CAPTURED_PROBABILITY_REDUCE = 104,
  IMPRISON_HERO_COUNT_ADD = 105,
  EXECUTE_HERO_WAITING_TIME_REDUCE = 106,
  EXECUTE_HERO_STATUS_LAST_TIME_ADD = 107,
  EPIC_WAR_FREE_CHALLENGE_COUNT_ADD = 108,
  KING_WAR_PERSON_ALL_POINT_ADD = 109,
  KING_WAR_PERSON_OCCUPY_FORTRESS_POINT_SPEED_ADD = 110,
  KING_WAR_PERSON_OCCUPY_BATTERY_POINT_SPEED_ADD = 111,
  KING_WAR_PERSON_FORTRESS_KILL_ARMY_POINT_ADD = 112,
  KING_WAR_PERSON_BATTERY_KILL_ARMY_POINT_ADD = 113,
  KING_WAR_PERSON_OCCUPY_PALACE_POINT_SPEED_ADD = 114,
  KING_WAR_PERSON_PALACE_KILL_ARMY_POINT_ADD = 115,
  KING_WAR_PERSON_DEFEND_PALACE_SOLDIER_ADD = 116,
  CONQUEST_WAR_PERSON_ALL_POINT_ADD = 117,
  CONQUEST_WAR_PERSON_KILL_MONSTER_POINT_ADD = 118,
  CONQUEST_WAR_PERSON_COLL_POINT_ADD = 119,
  CONQUEST_WAR_PERSON_KILL_ENEMY_POINT_ADD = 120,
  RUINS_WAR_KILL_RED_NPC_BUFF_TIME_ADD = 121,
  RUINS_WAR_KILL_BLUE_NPC_BUFF_TIME_ADD = 122,
  RUINS_WAR_KILL_RED_NPC_SOLDIER_ATK_BUFF_ADD = 123,
  RUINS_WAR_KILL_RED_NPC_SOLDIER_DEF_BUFF_ADD = 124,
  RUINS_WAR_KILL_BLUE_NPC_SOLDIER_HP_BUFF_ADD = 125,
  RUINS_WAR_KILL_BLUE_NPC_SOLDIER_CURE_BUFF_ADD = 126,
  RUINS_WAR_BATTLE_TEAM_POINT_ADD = 127,
  RUINS_WAR_CARRY_SOLDIER_NUM_ADD = 128,
  PYRAMID_WAR_OCCUPY_ARMORY_ALLIANCE_POINT_ADD = 129,
  PYRAMID_WAR_OCCUPY_GREAT_PYRAMID_ALLIANCE_POINT_ADD = 130,
  PYRAMID_WAR_OCCUPY_SMALL_PYRAMID_ALLIANCE_POINT_ADD = 131,
  PYRAMID_WAR_OCCUPY_SUPPLY_POINT_ALLIANCE_POINT_ADD = 132,
  PYRAMID_WAR_OCCUPY_BELL_TOWER_EFFECT_ADD = 133,
  PYRAMID_WAR_OCCUPY_BLESSED_TOWER_EFFECT_ADD = 134,
  RUINS_WAR_KILL_RED_NPC_SOLDIER_BUFF_ADD = 135,
  RUINS_WAR_KILL_BLUE_NPC_SOLDIER_BUFF_ADD = 136,
  DEFEND_JUNIOR_BEACON_TOWER_SOLDIER_ATK_ADD = 137,
  DEFEND_JUNIOR_BEACON_TOWER_SOLDIER_DEFEND_ADD = 138,
  DEFEND_JUNIOR_BEACON_TOWER_SOLDIER_HP_ADD = 139,
  DEFEND_MEDIUM_BEACON_TOWER_SOLDIER_ATK_ADD = 140,
  DEFEND_MEDIUM_BEACON_TOWER_SOLDIER_DEFEND_ADD = 141,
  DEFEND_MEDIUM_BEACON_TOWER_SOLDIER_HP_ADD = 142,
  BEACON_TOWER_OCCUPY_NEED_TIME_REDUCE = 143,
  DEFEND_ADVANCED_BEACON_TOWER_SOLDIER_ATK_ADD = 144,
  DEFEND_ADVANCED_BEACON_TOWER_SOLDIER_DEFEND_ADD = 145,
  CHECKPOINT_OCCUPY_NEED_TIME_REDUCE = 146,
  CASTLE_ATTACKED_WOUNDED_SOLDIER_RATE_REDUCE = 147,
  EXPLOITS_CALCULATION_RATE_ADD = 148,
  ALL_SOLDIER_ATTACK_ADD = 149,
  ALL_SOLDIER_DEFENSE_ADD = 150,
  ALL_SOLDIER_LIFE_ADD = 151,
  RADIANCE_WAR_WOUNDED_SOLDIER_RECOVERY_SPEED_ADD = 152,
  RADIANCE_WAR_COLLECT_WAR_BADGE_SPEED_ADD = 153,
  RADIANCE_WAR_COLLECT_SPEED_ITEM_SPEED_ADD = 154,
  RADIANCE_WAR_COLLECT_AMBER_OR_STONE_SPEED_ADD = 155,
  RADIANCE_WAR_COLLECT_SUPER_WAR_BADGE_SPEED_ADD = 156,
  RADIANCE_WAR_COLLECT_STAR_STONE_SPEED_ADD = 157,
  BRIGHT_STRENGTHEN_COST_REDUCE = 158,
  BRIGHT_STRENGTHEN_TIME_REDUCE = 159,
  RADIANCE_WAR_ALLIANCE_RANK_REWARD_ADD = 160,
  RADIANCE_WAR_COLLECT_SUPER_WAR_BADGE_NUM_ADD = 161,
  RADIANCE_WAR_COLLECT_AMBER_OR_STONE_BUILD_NUM_ADD = 162,
  RADIANCE_WAR_COLLECT_STAR_STONE_NUM_ADD = 163,
  DEFEND_ADVANCED_BEACON_TOWER_SOLDIER_HP_ADD = 164,
  RADIANCE_WAR_BADGE_BUILD_NUM_ADD = 165,
  RADIANCE_WAR_SHOP_BUY_STONE_NUM_ADD = 166,
  INFANTRY_DMG_REDUCTION = 167,
  ARCHER_ATTACK_SPEED = 168,
  CAVALRY_CHARGE_RATE = 169,
  INFANTRY_BASE_DEFENSE = 170,
  SOLDIER_BASE_ATTACK = 171,
  INFANTRY_BASE_HP = 172,
  CAVALRY_BASE_HP = 173,
  ARCHER_BASE_DEFENSE = 174,
  ARMOR_FORIGIN_TIME_REDUCE = 175,
  CAVALRY_BASE_DEFENSE = 176,
  ARMOR_FORIGIN_CRYSTAL_REDUCE = 177,
  ARMOR_FORIGIN_RES_REDUCE = 178,
  ARCHER_DMG_REDUCTION = 179,
  ARMOR_FORIGIN_NUM_ADD = 180,
  SOLDIER_ALL_ATTR = 181,
  ARMOR_FORIGIN_CONSUME_REDUCE = 182,
  INFANTRY_BASE_ATTACK = 183,
  ARCHER_BASE_ATTACK = 184,
  CAVALRY_BASE_ATTACK = 185,
  ARMOR_FORIGIN = 186,
  INFANTRY_DAMAGE_BOOST = 187,
  CAVALRY_DAMAGE_BOOST = 188,
  INFANTRY_ARMOR_FORIGIN = 189,
  CAVALRY_ARMOR_FORIGIN = 190,
  ARCHER_ARMOR_FORIGIN = 191,
  CHARISTS_ARMOR_FORIGIN = 192,
  INFANTRY_ARMOR_FORIGIN_TIME_REDUCE = 193,
  CAVALRY_ARMOR_FORIGIN_TIME_REDUCE = 194,
  ARCHER_ARMOR_FORIGIN_TIME_REDUCE = 195,
  CHARISTS_ARMOR_FORIGIN_TIME_REDUCE = 196,
  INFANTRY_ARMOR_FORIGIN_CRYSTAL_REDUCE = 197,
  CAVALRY_ARMOR_FORIGIN_CRYSTAL_REDUCE = 198,
  ARCHER_ARMOR_FORIGIN_CRYSTAL_REDUCE = 199,
  CHARISTS_ARMOR_FORIGIN_CRYSTAL_REDUCE = 200,
  INFANTRY_ARMOR_FORIGIN_RES_REDUCE = 201,
  CAVALRY_ARMOR_FORIGIN_RES_REDUCE = 202,
  ARCHER_ARMOR_FORIGIN_RES_REDUCE = 203,
  CHARISTS_ARMOR_FORIGIN_RES_REDUCE = 204,
  INFANTRY_ARMOR_FORIGIN_CONSUME_REDUCE = 205,
  CAVALRY_ARMOR_FORIGIN_CONSUME_REDUCE = 206,
  ARCHER_ARMOR_FORIGIN_CONSUME_REDUCE = 207,
  CHARISTS_ARMOR_FORIGIN_CONSUME_REDUCE = 208,
  TECH_GLORIOUS_STATUE_LEVEL_MAX = 209,
  TECH_LORD_LEVEL_MAX = 210,
  WAR_LINE_HOLE_NUM_ADD = 211,
  ARCHER_DAMAGE_BOOST = 212,
  CAVALRY_DAMAGE_REDUCE = 213,
  ARCHER_TOUGHNESS_ADD_ATTACKED_BY_AC = 214,
  CAVALRY_TOUGHNESS_ADD_ATTACKED_BY_AC = 215,
  DAILY_RECEIVE_METEORITE_LV_ADD = 216,
  DAILY_RECEIVE_CITY_BUILD_HELP_ADD = 217,
  ARCHER_BASE_HP = 218,
  INFANTRY_REDUCEDAMAGE_FROM_ARCHER = 219,
  ARCHER_REDUCEDAMAGE_FROM_CAVALRY = 220,
  CAVALRY_REDUCEDAMAGE_FROM_INFANTRY = 221,
  INFANTRY_ARCHER_INJURY = 222,
  ARCHER_CAVALRY_INJURY = 223,
  CAVALRY_INFANTRY_INJURY = 224,
  SOLDIER_RUSH_SWITCH_BUILD_REDUCE_CD = 800,
  SOLDIER_RUSH_SWITCH_BUILD_REDUCE_COST_RESOURCE = 801,
  COMMAND_HALL_MARCH_SPEED_UP = 810
};


extern GMap<EScienceType, GString> ETECHNOLOGY_ATTR;