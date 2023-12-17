#include "BuildingTips.Static.h"
#include "Module/Building/Building.Static.h"

BuildingTipsStatic *BuildingTipsStatic::Get(){
  static BuildingTipsStatic *l_Inst = new BuildingTipsStatic();
  return l_Inst;
}

RBuildingTipsBtnListData BuildingTipsStatic::GetBuildTipsBtnListData(EBuilding p_Building){
  auto lBuilding = BuildingStatic::Get()->getBuildingSpecs(p_Building);
  return lBuilding.TipButtons;
}

RBuildingTipConfig BuildingTipsStatic::GetBuildTipButtonCfgById(EBuildingTips p_Tip){
    if(BuildingStatic::Get()->GetBuildingTips().Contains(p_Tip))
    return BuildingStatic::Get()->GetBuildingTips()[p_Tip];
  return RBuildingTipConfig();
}
