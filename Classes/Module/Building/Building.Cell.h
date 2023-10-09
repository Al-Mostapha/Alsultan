#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/Json/XJson.h"
#include "Building.Enum.h"



struct RBuildingCellInfo {
  EBuilding IdBuilding;
  EBuildingIndex BuildingIndex;
  int32 buildingLvl;
  int32 starLvl;
  EBuildingState state;
  void FromJson(const XJson &pJson);
};

class BuildingCell {
  public:
  RBuildingCellInfo _Info;
  void FromJson(const XJson &pJson);
  void Upgrade();
  void UpgradeStar();
  EBuildingIndex GetBuildingIndex() { return _Info.BuildingIndex; }
  EBuilding GetBuildingId() { return _Info.IdBuilding; }
};