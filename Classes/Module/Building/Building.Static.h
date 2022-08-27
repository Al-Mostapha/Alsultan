#pragma once
#include "Include/IncludeBase.h"
#include "Building.Const.h"
#include "Building.Type.h"
#include "Building.Enum.h"

class BuildingStatic{
public: 
  static GVector<EBuildingType> BuildableList;
  static GMap<EBuildingType, TBuildingInfoUnit> BuildingInfo;
  static TBuildingInfoUnit getBuildingInfo(EBuildingType p_BuildingType){
    if(BuildingInfo.count(p_BuildingType) == 0)
      return TBuildingInfoUnit();
    return BuildingInfo[p_BuildingType];
  }
  
};
