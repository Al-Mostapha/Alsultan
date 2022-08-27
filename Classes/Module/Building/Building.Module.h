#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/Army/Army.Module.h"
#include "Module/CityResource/Resource.Module.h"
#include "Module/Player/Player.Module.h"
#include "Module/Building/Building.Module.h"
#include "Module/City/City.Const.h"
#include "Module/City/City.DT.h"
#include "Module/City/City.Module.h"
#include "Module/Player/Player.DT.h"

class BuildingModule
{
public:
    static void init();
    static void buildCity();
    //static cocos2d::Vector<DSCityBuildingUnit *> getBuildingList(EBuildingType buildingType);
    //static cocos2d::Vector<DSCityBuildingUnit *> getBuildingResList();
    static TCityBuilding& getCurentCityBuilding();
};