#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"

class BuildingLib {
  public:
  static GVector<EBuilding> getCityBuilding(int32 idCity);
  static void buildCity();
  static void buildAt(const char* p_BuildingPlace);
  static RCityBuildingUnit& getBuildingAt(const char* p_BuildingPlace);
  static class IBuilding* getBuildingNodeAt(const char* p_BuildingPlace);
  static class IBuilding* getBuildingClassByType(EBuilding p_BuildingType);
  static RCityBuilding& getCurentCityBuilding();
  static GVector<RCityBuildingUnit> getBuildingList(EBuilding p_BuildingType);
  static GVector<RCityBuildingUnit> getBuildingResList();
  static GVector<RBuildingSpecs> getCanBuildList(EBuilding p_BuildingType);
  static bool isCanBuild(EBuilding p_BuildingType);
};