#pragma once
#include "Base/BaseTypeDef.h"
#include "BuildingTips.Type.h"
#include "Module/Building/Building.Enum.h"

class BuildingTipsStatic {
  private:
  GHashMap<EBuilding, RBuildingTipsBtnListData> m_BuildTipsBtnListData;

  public:
  static BuildingTipsStatic *Get();
  RBuildingTipsBtnListData GetBuildTipsBtnListData(EBuilding p_Building);
};