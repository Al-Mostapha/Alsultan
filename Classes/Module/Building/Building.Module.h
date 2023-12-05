#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/Army/Army.Module.h"
#include "Module/CityResource/Resource.Module.h"
#include "Module/Player/Player.Module.h"
#include "Module/Building/Building.Module.h"
#include "Scene/City/CityScene.Enum.h"
#include "Module/City/City.Type.h"
#include "Module/City/City.Module.h"
#include "Module/Player/Player.Static.h"

class BuildingModule
{
public:
    static BuildingModule *Get();
    void Init();
    void StartGame();
    void JsonFileLoaded();
    static void buildCity();
    //static cocos2d::Vector<DSCityBuildingUnit *> getBuildingList(EBuilding buildingType);
    //static cocos2d::Vector<DSCityBuildingUnit *> getBuildingResList();
    static RCityBuilding& getCurentCityBuilding();
};