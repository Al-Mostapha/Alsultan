#pragma once
#include "Base/BaseTypeDef.h"
#include "BuildingTips.Type.h"

class BuildingTipsStatic {
  private:
  GHashMap<EBuilding, RBuildingTipsBtnListData> m_BuildTipsBtnListData;
  GHashMap<EBuildingTips, RBuildingTipConfig> _BuildTipsConfig;

  public:
  static BuildingTipsStatic *Get();
  RBuildingTipsBtnListData GetBuildTipsBtnListData(EBuilding p_Building);
  RBuildingTipConfig GetBuildTipButtonCfgById(EBuildingTips p_Tip);
};