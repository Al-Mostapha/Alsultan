#pragma once

enum class EBuilding  {
  None = 0,
  Castle = 101,
  Wall = 102,
  ArrowTower = 103,
  WatchTower = 104,
  Depot = 105,
  EventCenter = 106,
  Merchant = 107,
  Port = 108,
  TroopDetails = 109,
  Bulletin = 110,
  Embassy = 111,
  Market = 112,
  Institute = 113,
  TreasurePool = 114,
  Blacksmith = 115,
  Stable = 116,
  TargetRange = 117,
  Barrack = 118,
  ChariotPlant = 119,
  Fortress = 120,
  DrillGrounds = 121,
  HallOfWar = 122,
  TrainHall = 123,
  HeroesMonument = 124,
  Prison = 125,
  Farm = 201,
  LumberMill = 202,
  IronMine = 203,
  SilverMine   = 204,
  MarchingTent = 205,
  FirstAidTent = 206,
  CrystalMine  = 207,
  MaterialWorkShop = 210,
  Miracle = 301,
  ElitePalace = 302,
  Monument = 303,
  StarBraveStatue = 304,
  NEBULA_PALACE = 305,
  LeisureHouse = 30001,
  CargoShip = 30002, // El tager El ageeb HuoChuang
  PetHouse = 30003,
  ResurrectionHall = 30004,
  ServiceCenter = 30005,
  EpicBattle = 30006,
  Mastery = 30008,
  MagicLamp = 30010,
  AreaLock_1221 = 1221,
  AreaLock_1222 = 1222,
  AreaLock_1223 = 1223,
  AreaLock_1224 = 1224,
  
};



enum class EBuildingPlace { // inner / outter
  Inner = 0,
  Outer = 1,
  None = 2,
  Fixed = 3
};

enum class ELockedArea{
  AreaLock_1221 = 1221,
  AreaLock_1222 = 1222,
  AreaLock_1223 = 1223,
  AreaLock_1224 = 1224
};

enum class EBuildingIndex { 
  None = 0,
  Castle = 1050,
  Build_1051 = 1051,
  ArrowTowerL = 1052,
  WallGate = 1053,
  ArrowTowerR = 1054,
  WatchTower = 1055,
  Build_1056 = 1056,
  Build_1057 = 1057,
  Build_1058 = 1058,
  Build_1059 = 1059,
  Build_1060 = 1060,
  Build_1061 = 1061,
  Build_1062 = 1062,
  Build_1063 = 1063,
  Build_1064 = 1064,
  BehindArrowTowerR = 1065,
  BehindArrowTowerL = 1066,
  Build_1067 = 1067,
  Build_1100 = 1100,
  Build_1101 = 1101,
  Build_1102 = 1102,
  Build_1103 = 1103,
  Build_1104 = 1104,
  Build_1105 = 1105,
  Build_1106 = 1106,
  Build_1107 = 1107,
  Build_1108 = 1108,
  Build_1109 = 1109,
  Build_1110 = 1110,
  Build_1111 = 1111,
  Build_1112 = 1112,
  Build_1113 = 1113,
  Build_1114 = 1114,
  Build_1115 = 1115,
  Build_1116 = 1116,
  Build_1117 = 1117,
  Build_1118 = 1118,
  Build_1119 = 1119,

  Build_1120 = 1120,
  Build_1121 = 1121,
  Build_1122 = 1122,
  Build_1123 = 1123,
  Build_1124 = 1124,

  Build_1125 = 1125,
  Build_1126 = 1126,
  Build_1127 = 1127,
  Build_1128 = 1128,
  Build_1129 = 1129,

  Build_1130 = 1130,
  Build_1131 = 1131,
  Build_1132 = 1132,
  Build_1133 = 1133,
  Build_1134 = 1134,

  MaterialWorkShop = 1151,
  Crystal = 1152,

  Gangkou = 2000,
  Miracle = 1200,
  ElitePalace = 1201,
  MonumentRos = 1202,
  Prison = 1203,
  TrainHall = 1204,
  StarBraveStatue = 1205,
  NebulaHall = 1206,
  Merchant = 20005,
  TroopFlag = 20009,
  LeisureCenter = 30001,
  HuoChuang = 30002,
  PetCenter = 30003,
  ResurrectionHall = 30004,
  ServiceCenter = 30005,
  EpicBattle = 30006,
  Monument = 30007,
  Mastery = 30008,
  CommandHall = 30009,
  MagicLamp = 30010,
  LockArea_1 = static_cast<int>(EBuilding::AreaLock_1221),
  LockArea_2 = static_cast<int>(EBuilding::AreaLock_1222),
  LockArea_3 = static_cast<int>(EBuilding::AreaLock_1223),
  LockArea_4 = static_cast<int>(EBuilding::AreaLock_1224)
};

enum class EBuildingPos { CBPlace_None = 0, CBPlace_Fixed = 1, CBPlace_Inner = 2, CBPlace_Outer = 3 };

enum class EBuildingViewModel {
  None = 0,
  ViewModel_1 = 1,
  ViewModel_2 = 2,
  ViewModel_3 = 3,
  ViewModel_4 = 4,
  ViewModel_5 = 5,
  ViewModel_6 = 6,
  ViewModel_7 = 7,
  ViewModel_8 = 8
};

enum class EBuildingStarState{
  NORMAL = 0,
  UPGRADEING = 1
};

enum class EBuildingState {
  
  None = 0, // Normal
  Normal = 0, // Normal
  Building = 1,
  Upgrading = 2,
  Demolishing = 3,
  Training = 4,
  TrapBuilding = 5,
  TREATING = 6,
  Studying = 7,
  Lock = 8,
  ArmorForg = 9,
  Idle,
  Working, 
  Harvesting
};

enum class ECityBuildingState{
  None = 0,
  Normal = 1,
  Upgrading_No_Alliance_Help = 2,
  Upgrading_With_Alliance_Help = 3,
  Cooling = 4
};

enum class EWatchTowerEffect{
  None = 0
};

enum class EHarvestState{
  None = 0,
  Some,
  Much
};

enum class EBuildingActionTag{
  None = 0, 
  Tag_delayUpdateMainCityPos = 1000,
  Tag_ContainerViewMove = 1001,
  Tag_ContainerViewScale = 1002,
  Tag_Play_Click_Default_Sound = 1003,
  TagPlayClickBuildSound = 1004
};


enum class EBuildingCastleModel{
  BYZANTINE = 0,
  Classical = 1,
  RAMADAN = 2,
  WARLV = 3,
  SUPERVIP = 4,
  SECOND = 5,
  THREE = 6,
  NEWRAMADAN = 7,
  KOH2018RAMADAN = 8,
  EGYPT = 9,
  PANTHER = 10,
  ICESNOW = 11,
  NIGHTDX = 12,
  CRAZYSTAR = 13,
  EXQUISITE = 14,
  STREAM = 15,
  OASIS = 16,
  WORLDCUP = 17,
  WATCH = 18,
  VALENTINE = 19,
  KINGCOBRA = 20,
  FORT = 21,
  CORBAN = 22,
  CHRISTMAS = 23,
  HALLOWEEN = 24,
  CHRISTMAS2018 = 25,
  HALLOWEEN2018 = 26,
  NEWYEAR = 27,
  KOH2019RAMADAN = 28,
  HEGEMON = 29,
  STARKING = 30,
  EASTER = 31,
  FOURTH = 32,
  SMAILWIND = 33,
  WARRIOR = 34,
  SCORPION = 35,
  DEGULA = 36,
  YIJICB = 37,
  REDGEM = 38,
  KINGLION = 39,
  SKYGUARD = 40,
  KOH2020RAMADAN = 41,
  CORBAN2020 = 42,
  FIFTH = 43,
  CONSTRUCTED = 44,
  GOLDENCITY = 45,
  SOARCASTLE = 46,
  ICECASTLE = 47,
  KOH2021RAMADAN = 48,
  KING = 49,
  SKYGARDEN = 50,
  THUNDERCLOUD = 51,
  CORBAN2021 = 52,
  HOURGLASS = 53,
  ICEWOLF = 54,
  KOH2022RAMADAN = 55,
  CORBAN2022 = 56,
  SEVENTH = 57,
  FOOTBALL = 58,
  KINGSTARBATTLE = 59
};

enum class EBuildingOperateType {
  None = -1,
  Build = 0,
  Demolish = 1,
  Upgrade = 2,
  Exchange = 3,
  Unlock = 4,
  UpgradeStar = 5
};

enum class EOperateMode {
  Normal = 0,
  GoldReplace = 1,
  Immediately = 2,
  FREE = 3
};

enum class EBuildingUIType{
  None = 0,
  UITypeAlone = 1,
  UITypeRelyOn = 2
};


enum class EBuildingTips
{
	OpNone = 0,
	OpBoostByTool = 1001,
	OpBoost = 1002,
	OpDetails = 1003,
	OpSpeedUpByGold = 1004,
	OpSpeedUpByTool = 1005,
	OpUpgrade = 1006,
	OpTrade = 1007,
	OpAuction = 1008,
	OpResearch = 1009,
	OpBuild = 1010,
	OpTrain = 1011,
	OpHelp = 1012,
	OpReinforcements = 1013,
	OpWish = 1014,
	OpAllianceBattle = 1015,
	OpDefend = 1016,
	OpMilitaryInfo = 1017,
	OpCityInfo = 1018,
	OpCityDecorate = 1019,
	OpCityGift = 1020,
	OpAllianceTreasure = 1021,
	OpCityBuff = 1022,
	OpHeal = 1023,
	OpCollect = 1024,
	OpForging = 1025,
	OpStoragebox = 1026,
	OpPyramid = 1027,
	OpBadgeBourse = 1028,
	OpFriend = 1029,
	OpMilitaryPoint = 1030,
	OpWar = 1031,
	OpMonthGift = 1032,
	OpDailySign = 1033,
	OpResuscitate = 1034,
	OpDailyReward = 1035,
	OpPet = 1036,
	OpPetMap = 1037,
	OpPetExchange = 1038,
	OpPremiumVipMall = 1039,
	OpWarGem = 1040,
	OpWarTechnology = 1041,
	OpArena = 1042,
	OpDiscuss = 1043,
	OpSupport = 1044,
	OpSpringOfLife = 1045,
	OpFaction = 1046,
	OpInfoCenter = 1047,
	OpMonument = 1048,
	OpTrainHall = 1049,
	OpPrison = 1050,
	OpMastery = 1051,
	OpMainMastery = 1052,
	OpDrawing = 1053,
	OpArtifact = 1054,
	OpMonumentLegend = 1055,
	OpIntetior = 1056,
	OpCounterSys = 1057,
	OpExclusiveVip = 1058,
	OpStarUpgrade = 1059,
	OpStarSpeedUp = 1060,
	OpEndlessTreasure = 1061,
	OpProcessStudy = 1062,
	OpWarframeForg = 1063,
	OpWarframeStoreroom = 1064,
	OpstatueBrave = 1065,
	OpMilitaryFortress = 1066,
  OpForeignPavilion = 1067,
  OpNebulaTechnology = 1068,
  OpNebulaTechnologyReward = 1069,
  OpMeteorMagic = 1070,
  OpMagicLamp = 1071,
  OpMagicLampPray = 1072,
  OpMagicLampBreak = 1073,
  OpMagicLampStrength = 1074,
  OpMagicLampClass = 1075,
  OpCityLevelGift = 1076,
};