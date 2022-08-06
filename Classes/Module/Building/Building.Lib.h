#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/Building/CityBuildingBase.h"

class BuildingLib
{
public:
    static GVector<EBuildingType> getCityBuilding(int32 idCity);
    static void buildCity();
    static void buildAt(const char *BuildingPlace);
    static DSCityBuildingUnit &getBuildingAt(const char *BuildingPlace);
    static CityBuildingBase *getBuildingNodeAt(const char *BuildingPlace);
    static CityBuildingBase *getBuildingClassByType(EBuildingType buildingType);
    static DSCityBuilding &getCurentCityBuilding();
    static GVector<DSCityBuildingUnit> getBuildingList(EBuildingType buildingType);
    static GVector<DSCityBuildingUnit> getBuildingResList();
    static GVector<CityBuildingBase *> getCanBuildList(EBuildingType buildingType);

};