#pragma once
#include "Base/Containers/HashMap.h"
#include "Base/Type/XVector.h"
#include "Building.Const.h"
#include "Building.Enum.h"
#include "Building.Type.h"
#include "Include/IncludeBase.h"

class BuildingStatic {
  private:
  GHashMap<EBuilding, RBuildingSpecs> _BuildingInfo;
  GHashMap<EBuildingTips, RBuildingTipConfig> _BuildTipsConfig;
  RBuildingSpecs m_InvalidBuildingSpecs;
  RBuildingLvlSpecs m_InvalidBuildingLvlSpecs;

  public:
  static BuildingStatic *Get();
  static GVector<EBuilding> BuildableList;

  static bool isValidBuilding(EBuilding p_BuildingType);
  static bool isValidBuildingLvl(EBuilding p_BuildingType, uint32 p_Lvl);
  static RBuildingSpecs &getBuildingSpecs(EBuilding p_BuildingType);
  GHashMap<EBuilding, RBuildingSpecs> &getBuildingSpecs(){ return _BuildingInfo;}
  static RBuildingLvlSpecs &getBuildingLvlSpec(EBuilding p_BuildingType, uint32 p_Lvl);
  GHashMap<EBuildingTips, RBuildingTipConfig> &GetBuildingTips(){ return _BuildTipsConfig; }
  void GetFromJsonFile(const XJson &pJson);
  void GetTipsFromJsonFile(const XJson &pJson);
};
