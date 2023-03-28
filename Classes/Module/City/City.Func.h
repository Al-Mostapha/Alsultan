#pragma once
#include "Include/IncludeBase.h"
#include "Module/Building/Building.Enum.h"

class MainCityView;
class MainCityFunctions{
public:
  static MainCityFunctions *Get();
  void UpdateLockArea(class MainCityView *p_View);
  void AddBuild(MainCityView *p_MainCity, EBuilding p_BuildingId, EBuildingIndex p_BuildingIndex);
  void ReArrangeZorder(MainCityView *p_MainCity);
};