#pragma once
#include "Include/IncludeBase.h"
#include "Module/Building/CityBuildingBase.h"
#include "Module/Building/Building.DT.h"

class BuildingLib
{
public:
    static void buildCity();
    static void buildAt(const char *BuildingPlace);
    static DSCityBuildingUnit &getBuildingAt(const char *BuildingPlace);
    static CityBuildingBase *getBuildingNodeAt(const char *BuildingPlace);
    static CityBuildingBase *getBuildingClassByType(EBuildingType buildingType);
};