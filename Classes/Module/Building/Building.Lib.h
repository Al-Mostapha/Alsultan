#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"


class BuildingLib
{
public:
    static GVector<EBuildingType> getCityBuilding(int32 idCity);
    static void buildCity();
    static void buildAt(const char *p_BuildingPlace);
    static TCityBuildingUnit &getBuildingAt(const char *p_BuildingPlace);
    static class CityBuildingBase *getBuildingNodeAt(const char *p_BuildingPlace);
    static class CityBuildingBase *getBuildingClassByType(EBuildingType p_BuildingType);
    static TCityBuilding &getCurentCityBuilding();
    static GVector<TCityBuildingUnit> getBuildingList(EBuildingType p_BuildingType);
    static GVector<TCityBuildingUnit> getBuildingResList();
    static GVector<TBuildingInfoUnit> getCanBuildList(EBuildingType p_BuildingType);
    static bool isCanBuild(EBuildingType p_BuildingType);
};