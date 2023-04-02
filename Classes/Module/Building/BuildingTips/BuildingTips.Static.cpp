#include "BuildingTips.Static.h"

BuildingTipsStatic *BuildingTipsStatic::Get(){
  static BuildingTipsStatic *l_Inst = new BuildingTipsStatic();
  return l_Inst;
}

RBuildingTipsBtnListData BuildingTipsStatic::GetBuildTipsBtnListData(EBuilding p_Building){
  if(m_BuildTipsBtnListData.Contains(p_Building))
    return m_BuildTipsBtnListData[p_Building];
  return RBuildingTipsBtnListData();
}

RBuildingTipConfig BuildingTipsStatic::GetBuildTipButtonCfgById(EBuildingTips p_Tip){
    if(_BuildTipsConfig.Contains(p_Tip))
    return _BuildTipsConfig[p_Tip];
  return RBuildingTipConfig();
}
