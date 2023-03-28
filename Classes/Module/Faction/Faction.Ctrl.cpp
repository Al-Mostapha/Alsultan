#include "Faction.Ctrl.h"
#include "Module/Building/BuildingTips/BuildingTips.Static.h"
FactionCtrl *FactionCtrl::Get(){
  static auto l_Inst = new FactionCtrl();
  return l_Inst;
}


RBuildingTipsBtnListData FactionCtrl::GetCityBuildBaseTipsCfg(EBuilding p_Building){
  return BuildingTipsStatic::Get()->GetBuildTipsBtnListData(p_Building);
}