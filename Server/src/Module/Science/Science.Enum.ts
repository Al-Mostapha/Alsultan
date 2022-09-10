export enum EScienceType{
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
}

export enum EScienceCategory {
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
  Process
}


export enum EScienceEffect{
  None = 0,
  WoodProduction = 21001 ,
  FoodProduction ,
  IronProduction ,
  MithrilProduction , // Silver Production
  WOOD_COLLECTION ,
  FOOD_COLLECTION ,
  IRON_COLLECTION ,
  MITHRIL_COLLECTION ,
  GOLD_COLLECTION ,
  WAREHOUSE_PROTECTION ,
  FORCE_LOAD ,
  KILL_MARCH_SPEED ,
  PHYSICAL_REPLY ,
  CONSTRUCTION_SPEED ,
  WOUNDED_QUANTITY ,
  WOUNDED_REPLY ,
  FRCES_CONSUMPTION ,
  DEFENSE_ADD ,
  DEFENDERS_ATTACK ,
  DEFENDERS_DEFENSE ,
  TRAP_ATTACK ,
  TRAP_CAP ,
  CONSTRUCTION_SPEED_TRAP ,
  ROCKETS_CAVALRY_INJURY ,
  ROCKFALL_DAMAGE_INFANTRY ,
  BOWLS_ARCHER_INJURY ,
  EXPEDITION_LOSS ,
  SOLDIERS_TRAIN_SPEED ,
  INFANTRY_ATTACK ,
  CAVALRY_ATTACK ,
  ARCHER_ATTACK ,
  CHARIOTS_ATTACK ,
  INFANTRY_DEFENSE ,
  CAVALRY_DEFENSE ,
  ARCHER_DEFENSE ,
  CHARIOTS_DEFENSE ,
  INFANTRY_HEALTH ,
  CAVALRY_HEALTH ,
  ARCHER_HEALTH ,
  CHARIOTS_HEALTH ,
  MARCH_SPEED ,
  EXPEDITION_TROOPS ,
  SINGLE_TROOP_STRENGTH ,
  JUNIOR_COLLECT_PLUNDER ,
  JUNIOR_COLLECT_KO ,
  JUNIOR_COLLECT_TREATMENT ,
  JUNIOR_COLLECT_MAKEUP ,
  CURE_FOOTSOLDIER_SPEED_BOOST ,
  CURE_CAVALRY_SPEED_BOOST ,
  CURE_ARCHER_SPEED_BOOST ,
  CURE_CHARIOTS_SPEED_BOOST ,
  TRAIN_FOOTSOLDIER_SPEED_BOOST ,
  TRAIN_CAVALRY_SPEED_BOOST ,
  TRAIN_ARCHER_SPEED_BOOST ,
  TRAIN_CHARIOTS_SPEED_BOOST ,
  SIEGE_PLUNDER ,
  SIEGE_KO ,
  MEDIUM_COLLECT_KO ,
  MEDIUM_COLLECT_TREATMENT ,
  RECRUIT_HORN ,
  SOLDIER_COMPILE ,
  SOLDIER_ATTACK ,
  SOLDIER_DEFENSE ,
  SOLDIER_LIFE ,
  ENERGY_CONVERSION ,
  ENERGY_LIMIT ,
  KINGDOM_ATTACK_UP ,
  KINGDOM_DEF_UP ,
  KINGDOM_HP_UP ,
  CONQUEST_WAR_ATTACK_UP ,
  CONQUEST_WAR_DEF_UP ,
  CONQUEST_WAR_HP_UP ,
  CONQUEST_WAR_SINGLE_TROOP_STRENGTH ,
  PYRAMID_ATTACK_UP ,
  PYRAMID_DEF_UP ,
  PYRAMID_HP_UP ,
  PYRAMID_SINGLE_TROOP_STRENGTH ,
  RESOURCE_TECH_COST_REDUCE ,
  CITY_DEVELOP_TECH_COST_REDUCE ,
  MILITARY_TECH_COST_REDUCE ,
  ANCHOR_TECH_COST_REDUCE ,
  SOLDIER_TECH_COST_REDUCE ,
  LEADER_TECH_COST_REDUCE ,
  SPECIAL_TECH_COST_REDUCE ,
  BUILD_COST_REDUCE ,
  TECH_RESEARCH_SPEED_BOOST ,
  RES_PRODUCTIVITY_BOOST ,
  CRYSTAL_PRODUCTIVITY_BOOST ,
  RES_COLLECTION_SPEED_BOOST ,
  WARHALL_CAPACITY_VALUE_BOOST ,
  ELITE_SOLDIER_LIMIT_VALUE_BOOST ,
  LEGEND_HP_UP ,
  LEGEND_DEF_UP ,
  LEGEND_ATTACK_UP ,
  LEGEND_SINGLE_TROOP_STRENGTH ,
  EPIC_WAR_BUY_CHALLENGE_COUNT_ADD ,
  EPIC_WAR_ACTION_LIMIT_ADD ,
  EPIC_WAR_LEADER_POINT_ADD ,
  EPIC_WAR_RECOVERY_ACTION ,
  HERO_MARCH_POSITION_LIMIT ,
  HERO_TRAIN_POSITION_LIMIT_ADD ,
  CAPTURE_HERO_PROBABILITY_ADD ,
  TRAIN_HERO_LEADER_POINT_ADD ,
  HERO_CAPTURED_PROBABILITY_REDUCE ,
  IMPRISON_HERO_COUNT_ADD ,
  EXECUTE_HERO_WAITING_TIME_REDUCE ,
  EXECUTE_HERO_STATUS_LAST_TIME_ADD ,
  EPIC_WAR_FREE_CHALLENGE_COUNT_ADD ,
  KING_WAR_PERSON_ALL_POINT_ADD ,
  KING_WAR_PERSON_OCCUPY_FORTRESS_POINT_SPEED_ADD ,
  KING_WAR_PERSON_OCCUPY_BATTERY_POINT_SPEED_ADD ,
  KING_WAR_PERSON_FORTRESS_KILL_ARMY_POINT_ADD ,
  KING_WAR_PERSON_BATTERY_KILL_ARMY_POINT_ADD ,
  KING_WAR_PERSON_OCCUPY_PALACE_POINT_SPEED_ADD ,
  KING_WAR_PERSON_PALACE_KILL_ARMY_POINT_ADD ,
  KING_WAR_PERSON_DEFEND_PALACE_SOLDIER_ADD ,
  CONQUEST_WAR_PERSON_ALL_POINT_ADD ,
  CONQUEST_WAR_PERSON_KILL_MONSTER_POINT_ADD ,
  CONQUEST_WAR_PERSON_COLL_POINT_ADD ,
  CONQUEST_WAR_PERSON_KILL_ENEMY_POINT_ADD ,
  RUINS_WAR_KILL_RED_NPC_BUFF_TIME_ADD ,
  RUINS_WAR_KILL_BLUE_NPC_BUFF_TIME_ADD ,
  RUINS_WAR_KILL_RED_NPC_SOLDIER_ATK_BUFF_ADD ,
  RUINS_WAR_KILL_RED_NPC_SOLDIER_DEF_BUFF_ADD ,
  RUINS_WAR_KILL_BLUE_NPC_SOLDIER_HP_BUFF_ADD ,
  RUINS_WAR_KILL_BLUE_NPC_SOLDIER_CURE_BUFF_ADD ,
  RUINS_WAR_BATTLE_TEAM_POINT_ADD ,
  RUINS_WAR_CARRY_SOLDIER_NUM_ADD ,
  PYRAMID_WAR_OCCUPY_ARMORY_ALLIANCE_POINT_ADD ,
  PYRAMID_WAR_OCCUPY_GREAT_PYRAMID_ALLIANCE_POINT_ADD ,
  PYRAMID_WAR_OCCUPY_SMALL_PYRAMID_ALLIANCE_POINT_ADD ,
  PYRAMID_WAR_OCCUPY_SUPPLY_POINT_ALLIANCE_POINT_ADD ,
  PYRAMID_WAR_OCCUPY_BELL_TOWER_EFFECT_ADD ,
  PYRAMID_WAR_OCCUPY_BLESSED_TOWER_EFFECT_ADD ,
  RUINS_WAR_KILL_RED_NPC_SOLDIER_BUFF_ADD ,
  RUINS_WAR_KILL_BLUE_NPC_SOLDIER_BUFF_ADD ,
  DEFEND_JUNIOR_BEACON_TOWER_SOLDIER_ATK_ADD ,
  DEFEND_JUNIOR_BEACON_TOWER_SOLDIER_DEFEND_ADD ,
  DEFEND_JUNIOR_BEACON_TOWER_SOLDIER_HP_ADD ,
  DEFEND_MEDIUM_BEACON_TOWER_SOLDIER_ATK_ADD ,
  DEFEND_MEDIUM_BEACON_TOWER_SOLDIER_DEFEND_ADD ,
  DEFEND_MEDIUM_BEACON_TOWER_SOLDIER_HP_ADD ,
  BEACON_TOWER_OCCUPY_NEED_TIME_REDUCE ,
  DEFEND_ADVANCED_BEACON_TOWER_SOLDIER_ATK_ADD ,
  DEFEND_ADVANCED_BEACON_TOWER_SOLDIER_DEFEND_ADD ,
  CHECKPOINT_OCCUPY_NEED_TIME_REDUCE ,
  CASTLE_ATTACKED_WOUNDED_SOLDIER_RATE_REDUCE ,
  EXPLOITS_CALCULATION_RATE_ADD ,
  ALL_SOLDIER_ATTACK_ADD ,
  ALL_SOLDIER_DEFENSE_ADD ,
  ALL_SOLDIER_LIFE_ADD ,
  RADIANCE_WAR_WOUNDED_SOLDIER_RECOVERY_SPEED_ADD ,
  RADIANCE_WAR_COLLECT_WAR_BADGE_SPEED_ADD ,
  RADIANCE_WAR_COLLECT_SPEED_ITEM_SPEED_ADD ,
  RADIANCE_WAR_COLLECT_AMBER_OR_STONE_SPEED_ADD ,
  RADIANCE_WAR_COLLECT_SUPER_WAR_BADGE_SPEED_ADD ,
  RADIANCE_WAR_COLLECT_STAR_STONE_SPEED_ADD ,
  BRIGHT_STRENGTHEN_COST_REDUCE ,
  BRIGHT_STRENGTHEN_TIME_REDUCE ,
  RADIANCE_WAR_ALLIANCE_RANK_REWARD_ADD ,
  RADIANCE_WAR_COLLECT_SUPER_WAR_BADGE_NUM_ADD ,
  RADIANCE_WAR_COLLECT_AMBER_OR_STONE_BUILD_NUM_ADD ,
  RADIANCE_WAR_COLLECT_STAR_STONE_NUM_ADD ,
  DEFEND_ADVANCED_BEACON_TOWER_SOLDIER_HP_ADD ,
  RADIANCE_WAR_BADGE_BUILD_NUM_ADD ,
  RADIANCE_WAR_SHOP_BUY_STONE_NUM_ADD ,
  INFANTRY_DMG_REDUCTION ,
  ARCHER_ATTACK_SPEED ,
  CAVALRY_CHARGE_RATE ,
  INFANTRY_BASE_DEFENSE ,
  SOLDIER_BASE_ATTACK ,
  INFANTRY_BASE_HP ,
  CAVALRY_BASE_HP ,
  ARCHER_BASE_DEFENSE ,
  ARMOR_FORIGIN_TIME_REDUCE ,
  CAVALRY_BASE_DEFENSE ,
  ARMOR_FORIGIN_CRYSTAL_REDUCE ,
  ARMOR_FORIGIN_RES_REDUCE ,
  ARCHER_DMG_REDUCTION ,
  ARMOR_FORIGIN_NUM_ADD ,
  SOLDIER_ALL_ATTR ,
  ARMOR_FORIGIN_CONSUME_REDUCE ,
  INFANTRY_BASE_ATTACK ,
  ARCHER_BASE_ATTACK ,
  CAVALRY_BASE_ATTACK ,
  ARMOR_FORIGIN ,
  INFANTRY_DAMAGE_BOOST ,
  CAVALRY_DAMAGE_BOOST ,
  INFANTRY_ARMOR_FORIGIN ,
  CAVALRY_ARMOR_FORIGIN ,
  ARCHER_ARMOR_FORIGIN ,
  CHARISTS_ARMOR_FORIGIN ,
  INFANTRY_ARMOR_FORIGIN_TIME_REDUCE ,
  CAVALRY_ARMOR_FORIGIN_TIME_REDUCE ,
  ARCHER_ARMOR_FORIGIN_TIME_REDUCE ,
  CHARISTS_ARMOR_FORIGIN_TIME_REDUCE ,
  INFANTRY_ARMOR_FORIGIN_CRYSTAL_REDUCE ,
  CAVALRY_ARMOR_FORIGIN_CRYSTAL_REDUCE ,
  ARCHER_ARMOR_FORIGIN_CRYSTAL_REDUCE ,
  CHARISTS_ARMOR_FORIGIN_CRYSTAL_REDUCE ,
  INFANTRY_ARMOR_FORIGIN_RES_REDUCE ,
  CAVALRY_ARMOR_FORIGIN_RES_REDUCE ,
  ARCHER_ARMOR_FORIGIN_RES_REDUCE ,
  CHARISTS_ARMOR_FORIGIN_RES_REDUCE ,
  INFANTRY_ARMOR_FORIGIN_CONSUME_REDUCE ,
  CAVALRY_ARMOR_FORIGIN_CONSUME_REDUCE ,
  ARCHER_ARMOR_FORIGIN_CONSUME_REDUCE ,
  CHARISTS_ARMOR_FORIGIN_CONSUME_REDUCE 
}