#pragma once
#include "Include/IncludeBase.h"
enum class EBuildingType : uint32
{
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

enum class EBuildingPos
{
    CBPlace_None = 0,
    CBPlace_Fixed = 1,
    CBPlace_Inner = 2,
    CBPlace_Outer = 3
};

enum class EBuildingViewModel
{
    ViewModel_1 = 1,
    ViewModel_2 = 2,
    ViewModel_3 = 3,
    ViewModel_4 = 4,
    ViewModel_5 = 5,
    ViewModel_6 = 6,
    ViewModel_7 = 7,
    ViewModel_8 = 8
};