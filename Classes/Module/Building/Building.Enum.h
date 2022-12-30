#pragma once
#include "Include/IncludeBase.h"

enum class EBuilding  {
  None = 0,
  Castle = 101,
  Wall = 102,
  ArrowTower = 103,
  WatchTower = 104,
  Warehouse = 105,
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
  Prison = 125,
  Farm = 201,
  LumberMill = 202,
  IronMine = 203,
  SilverMine = 204,
  MarchingTent = 205,
  FirstAidTent = 206,
  CrystalMine = 207,
  MaterialWorkShop = 210,
  Miracle = 301,
  ElitePalace = 302,
  Monument = 303,
  StarBraveStatue = 304,
  LeisureHouse = 30001,
  HIP = 30002,
  PetHouse = 30003,
  ResurrectionHall = 30004,
  ServiceCenter = 30005,
  EpicBattle = 30006
};

enum class EBuildingPlace { // inner / outter
  Inner = 0,
  Outer = 1,
  None = 2
};

enum class EBuildingIndex { 
  None = 0,
  ArrowTowerL = 1052,
  WallGate = 1053,
  ArrowTowerR = 1054,
  WatchTower = 1055,
  BehindArrowTowerR = 1065,
  BehindArrowTowerL = 1066,
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


enum class EBuildingState {
  
  None = 0, // Normal
  Building = 1,
  Upgrading = 2,
  Demolishing = 3,
  Training = 4,
  TrapBuilding = 5,
  TREATING = 6,
  Studying = 7,
  Lock = 8,
  ARMORFORG = 9,
  Idle,
  Working, 
  Harvesting
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
  LEGENDARY = 30,
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
  ICEWOLF = 54
};