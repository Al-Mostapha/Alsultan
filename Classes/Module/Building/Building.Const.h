#pragma once
#include "Include/IncludeBase.h"

enum class EBuildingType
{
    CBType_None = 0,
    CBType_Castle = 101,
    CBType_Wall = 102,
    CBType_ArrowTower = 103,
    CBType_WatchTower = 104,
    CBType_Warehouse = 105,
    CBType_EventCenter = 106,
    CBType_Merchant = 107,
    CBType_Port = 108,
    CBType_TroopDetails = 109,
    CBType_Bulletin = 110,

    CBType_Embassy = 111,
    CBType_Market = 112,
    CBType_Institute = 113,
    CBType_TreasurePool = 114,
    CBType_Blacksmith = 115,
    CBType_Stable = 116,
    CBType_TargetRange = 117,
    CBType_Barrack = 118,
    CBType_Workshop = 119,
    CBType_Fortress = 120,
    CBType_DrillGrounds = 121,
    CBType_HallOfWar = 122,
    CBType_HeroTrainGround = 123,
    CBType_HeroPrison = 125,

    // Outer Building
    CBType_Farm = 201,
    CBType_LumberMill = 202,
    CBType_IronMine = 203,
    CBType_SilverMine = 204,
    CBType_MarchingTent = 205,
    CBType_FirstAidTent = 206,
    CBType_CrystalMine = 207,
    CBType_MaterialWorkShop = 210,

    // un upgradable
    CBType_Miracle = 301,
    CBType_ElitePalace = 302,
    CBType_Monument = 303,
    CBType_StarBraveStatue = 304,

    // Brebuilt fixed
    CBType_LeisureHouse = 30001,
    CARGO_SHIP = 30002,
    CBType_PetHouse = 30003,
    CBType_ResurrectionHall = 30004,
    CBType_ServiceCenter = 30005,
    CBType_EpicBattle = 30006,

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

class BuildingConst
{
public:
};