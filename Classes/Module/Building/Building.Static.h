#pragma once
#include "Include/IncludeBase.h"
#include "Building.Const.h"
#include "Building.Type.h"
#include "Building.Enum.h"

class BuildingStatic{
public: 
  static GVector<EBuildingType> BuildableList;
  static GMap<EBuildingType, TBuildingUnitSpecs> BuildingInfo;
  static TBuildingUnitSpecs getBuildingUnitSpecs(EBuildingType p_BuildingType);
  static TBuildingLvlSpecs getBuildingLvlSpec(EBuildingType p_BuildingType, uint32 p_Lvl){
    return TBuildingLvlSpecs();
  }
};
