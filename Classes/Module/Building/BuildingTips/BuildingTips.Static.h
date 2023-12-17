#pragma once
#include "Base/BaseTypeDef.h"
#include "BuildingTips.Type.h"
#include "Base/Containers/HashMap.h"

class BuildingTipsStatic {
  private:

  public:
  static BuildingTipsStatic *Get();
  RBuildingTipsBtnListData GetBuildTipsBtnListData(EBuilding p_Building);
  RBuildingTipConfig GetBuildTipButtonCfgById(EBuildingTips p_Tip);
};