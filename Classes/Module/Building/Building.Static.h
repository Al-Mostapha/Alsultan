#pragma once
#include "Include/IncludeBase.h"
#include "Building.Const.h"
#include "Building.Type.h"

class BuildingStatic{
public: 
  static GVector<EBuildingType> BuildableList;
  static GMap<EBuildingType, DSBuildingInfoUnit> BuildingInfo;
  static DSBuildingInfoUnit getBuildingInfo(EBuildingType p_BuildingType){
    if(BuildingInfo.count(p_BuildingType) == 0)
      return DSBuildingInfoUnit();
    return BuildingInfo[p_BuildingType];
  }
  
};
