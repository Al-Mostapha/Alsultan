#include "UIBuildingStarUpgradePanel.h"

UIBuildingStarUpgradePanel *UIBuildingStarUpgradePanel::Create(){
  auto l_Panel = UIBuildingStarUpgradePanel::Create("UiParts/Panel/Building/Common/buildStarUpgradePanel.csb");
  return l_Panel;
}

void UIBuildingStarUpgradePanel::Ctor(){
  UIBuildingCreateInfoPanel::Ctor();
}

void UIBuildingStarUpgradePanel::InitUpgradeStarData(EBuildingIndex p_Index, IBuilding *p_Building){

}

void UIBuildingStarUpgradePanel::InitWidget(){

}
