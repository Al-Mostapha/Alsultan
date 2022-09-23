#pragma once
#include "Base/Containers/HashMap.h"
#include "Building.Const.h"
#include "Building.Enum.h"
#include "Building.Type.h"
#include "Include/IncludeBase.h"

class BuildingStatic {
  private:
  GHashMap<EBuildingType, RBuildingUnitSpecs> m_BuildingInfo;
  RBuildingUnitSpecs m_InvalidBuildingUnitSpecs;
  RBuildingLvlSpecs m_InvalidBuildingLvlSpecs;

  public:
  static GHashMap<EBuildingType, RBuildingUnitSpecs> BuildingInfo;
  static BuildingStatic& Instance();
  static GVector<EBuildingType> BuildableList;

  static bool isValidBuilding(EBuildingType p_BuildingType);
  static bool isValidBuildingLvl(EBuildingType p_BuildingType, uint32 p_Lvl);
  static RBuildingUnitSpecs& getBuildingUnitSpecs(EBuildingType p_BuildingType);
  static RBuildingLvlSpecs& getBuildingLvlSpec(EBuildingType p_BuildingType, uint32 p_Lvl);
};
