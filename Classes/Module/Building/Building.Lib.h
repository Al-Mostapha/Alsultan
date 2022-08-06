#pragma once
#include "Include/IncludeBase.h"
#include "Module/Building/CityBuildingBase.h"
#include "Module/Building/Building.DT.h"

class BuildingLib
{
public:
    static GMap<EBuildingType, DSBuildingTypeUnit> BuildingTypes;
    static GVector<EBuildingType> getCityBuilding(int32 idCity);
    static void buildCity();
    static void buildAt(const char *BuildingPlace);
    static DSCityBuildingUnit &getBuildingAt(const char *BuildingPlace);
    static CityBuildingBase *getBuildingNodeAt(const char *BuildingPlace);
    static CityBuildingBase *getBuildingClassByType(EBuildingType buildingType);
    static DSCityBuilding &getCurentCityBuilding();
    static GVector<DSCityBuildingUnit> getBuildingList(EBuildingType buildingType);
    static GVector<DSCityBuildingUnit> getBuildingResList();
    static GVector<DSBuildingTypeUnit> getCanBuildList(EBuildingType buildingType);

};