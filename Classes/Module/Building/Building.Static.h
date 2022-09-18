#pragma once
#include "Building.Const.h"
#include "Building.Enum.h"
#include "Building.Type.h"
#include "Include/IncludeBase.h"
#include "Base/Containers/HashMap.h"


class BuildingStatic {
private:
  GHashMap<EBuildingType, RBuildingUnitSpecs> m_BuildingInfo;
  RBuildingUnitSpecs m_InvalidBuildingUnitSpecs;
  RBuildingLvlSpecs m_InvalidBuildingLvlSpecs;

  static void getReducedCostTime(RBuildingLvlSpecs &p_OriginalSpec);
  static void getReducedCostItem(RBuildingLvlSpecs &p_OriginalSpec);
  static void getReducedCostResource(RBuildingLvlSpecs &p_OriginalSpec);
  static void getReducedCostScience(RBuildingLvlSpecs &p_OriginalSpec);
  
public:
  static GHashMap<EBuildingType, RBuildingUnitSpecs> BuildingInfo;
  static BuildingStatic& Instance();
  static GVector<EBuildingType> BuildableList;
  static RBuildingUnitSpecs& getBuildingUnitSpecs(EBuildingType p_BuildingType);
  static RBuildingLvlSpecs& getBuildingLvlSpec(EBuildingType p_BuildingType, uint32 p_Lvl);
  static RBuildingLvlSpecs getReducedLvlSpec(EBuildingType p_BuildingType, uint32 p_Lvl);
  static bool isValidBuilding(EBuildingType p_BuildingType);
  static bool isValidBuildingLvl(EBuildingType p_BuildingType, uint32 p_Lvl);
};
