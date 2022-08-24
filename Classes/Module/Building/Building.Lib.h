#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"


class BuildingLib
{
public:
    static GVector<EBuildingType> getCityBuilding(int32 idCity);
    static void buildCity();
    static void buildAt(const char *p_BuildingPlace);
    static DSCityBuildingUnit &getBuildingAt(const char *p_BuildingPlace);
    static class CityBuildingBase *getBuildingNodeAt(const char *p_BuildingPlace);
    static class CityBuildingBase *getBuildingClassByType(EBuildingType p_BuildingType);
    static DSCityBuilding &getCurentCityBuilding();
    static GVector<DSCityBuildingUnit> getBuildingList(EBuildingType p_BuildingType);
    static GVector<DSCityBuildingUnit> getBuildingResList();
    static GVector<DSBuildingInfoUnit> getCanBuildList(EBuildingType p_BuildingType);
    static bool isCanBuild(EBuildingType p_BuildingType);
};