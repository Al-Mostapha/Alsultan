#pragma once 

enum class EModelType {
  Infantry = 1,
  Knight = 2,
  Archer = 3,
  Catapult = 4, // منجنيق
  Wall = 5, // may Be error
  Elite = 6
};

enum class ESoldierType {
  None = 0,
  Bubing = 1,
  QIBING = 2,
  GONGBING = 3,
  CHEBING = 4,
  TRAP_STONE = 5,
  TRAP_ARROW = 6,
  TRAP_WOOD = 7,
  Elite = 8
};

enum class EArmyType {
  infantryDf = 1,
  infantryAk = 2,
  cavalry = 3,
  cavalryArrow = 4,
  archer = 5,
  crossbow = 6,
  charists = 7,
  siegeVehicles = 8,
  trap = 9,
  tower1 = 10,
  tower2 = 11,
  tower3 = 12,
  elite = 13
};

enum class EArmy {
  None = 0,
  Infantry_Militia = 401,
  Infantry_SaracenMilitia = 402,
  Infantry_Spearman = 403,
  Infantry_Swordsman = 404,
  Infantry_SeniorSpearman = 405,
  Infantry_NobleSwordsman = 406,
  Infantry_Guard = 407,
  Infantry_EliteSpearman = 408,
  Infantry_Halberdier = 409,
  Infantry_ArabianSwordsman = 410,
  Knight_CamelRider = 501,
  Knight_DesertTrooper = 502,
  Knight_ArabicTrooper = 503,
  Knight_CamelRaider = 504,
  Knight_CamelHorseArcher = 505,
  Knight_EliteCamelRider = 506,
  Knight_MamlukRaider = 507,
  Knight_MamlukTrooper = 508,
  Knight_MamlukHorseArcher = 509,
  Knight_RoyalMamlukTrooper = 510,
  Archer_PeasantArcher = 601,
  Archer_MilitiaArcher = 602,
  Archer_Bowman = 603,
  Archer_SeniorBowman = 604,
  Archer_DesertArcher = 605,
  Archer_EliteArcher = 606,
  Archer_EliteBowman = 607,
  Archer_RoyalArcher = 608,
  Archer_RoyalBowman = 609,
  Archer_Hackbuteer = 610,
  Catapult_Catapult = 701,
  Catapult_BatteringRam = 702,
  Catapult_HeavyCatapult = 703,
  Catapult_DemolishinDrill = 704,
  Catapult_StoneThrower = 705,
  Catapult_Chariot = 706,
  Catapult_Bombard = 707,
  Catapult_TallBombard = 708,
  Catapult_DemolisherTower = 709,
  Catapult_Cannon = 710,
  Wall_FallingStones_1 = 801,
  Wall_FireArrow_1 = 811,
  Wall_RollingLogs_1 = 821,
  Wall_FallingStones_2 = 802,
  Wall_FireArrow_2 = 812,
  Wall_RollingLogs_2 = 822,
  Wall_FallingStones_3 = 803,
  Wall_FireArrow_3 = 813,
  Wall_RollingLogs_3 = 823,
  Wall_FallingStones_4 = 804,
  Wall_FireArrows_4 = 814,
  Wall_RollingLogs_4 = 824,
  Wall_FallingStones_5 = 805,
  Wall_FireArrow_5 = 815,
  Wall_RollingLogs_5 = 825,
  VeteranGuard = 906,
  VeteranWarrior,
  VeteranSentinel,
  VeteranCaptain,
  VeteranCenturion
};

enum class EArmySkill {
  AntiBow = 1301,
  Vitality = 1302,
  Armor = 1303,
  Penetration = 1304,
  Critical = 1305,
  Onslaught = 1306,
  Combo = 1307,
  AntiSpear = 1308,
  Shower = 1309,
  Aim = 1310,
  Charge = 1311,
  Dodge = 1312,
  Raid = 1313,
  Ambush = 1314,
  Bash = 1315,
  AllIn = 1316,
  EagleEye = 1317,
  Shield = 1318,
  Fortress = 1319,
  Strength = 1320,
  NoMercy = 1321,
  InfantriesCurse = 1322,
  CavalriesCurse = 1323,
  ArchersCurse = 1324
};

enum class ETrainType {
  None = 0,
  Soldiers = 1, 
  Trap = 2
};

enum class EArmyOpType{
  None = 0,
  Normal = 1,
  Wounded = 2,
  All = 3
};