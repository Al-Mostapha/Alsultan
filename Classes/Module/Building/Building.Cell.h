#pragma once
#include "Building.Enum.h"

struct RBuildingCellInfo {
  EBuilding IdBuilding;
  EBuildingIndex BuildingIndex;
  int32 buildingLvl;
  RBuildingCellInfo(){
    BuildingIndex = EBuildingIndex::Crystal;
    IdBuilding = EBuilding::CrystalMine;
    buildingLvl = 10;
  }
};

class BuildingCell {
  public:
  RBuildingCellInfo _Info;
  void Upgrade();
  void UpgradeStar();
  EBuildingIndex GetBuildingIndex() { return _Info.BuildingIndex; }
  EBuilding GetBuildingId() { return _Info.IdBuilding; }
};