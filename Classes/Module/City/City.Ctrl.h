#pragma once
#include "Include/IncludeBase.h"
#include "Module/Building/Building.Enum.h"


class CityCtrl {
public:
  static CityCtrl *Get();
  GString GetBuildStarLight(uint32 p_StarLvl) { return "" ;}
  uint32 GetBuildStarColor(uint32 p_StarLvl) { return 0 ;}
  void CollectResReq(EBuilding p_Building, EBuildingIndex p_BuildingIndex) {}
  class IBuilding *GetBuildingCell(EBuilding p_Building, EBuildingIndex p_BuildingIndex) { return nullptr ;}
  class IBuilding *GetBuildingCellByIndex(EBuildingIndex p_BuildingIndex) { return nullptr ;}
  GVector<IBuilding *> GetBuildList();
  bool GetCastleUpgradePopStatus();
};