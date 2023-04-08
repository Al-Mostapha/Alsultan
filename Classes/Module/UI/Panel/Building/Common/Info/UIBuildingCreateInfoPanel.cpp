#include "UIBuildingCreateInfoPanel.h"

UIBuildingCreateInfoPanel *UIBuildingCreateInfoPanel::Create(){
  auto l_Panel = UIBuildingCreateInfoPanel::Create("UiParts/Panel/Building/Common/buildCreatePanel.csb");
  return l_Panel;
}

void UIBuildingCreateInfoPanel::Ctor(){

}

void UIBuildingCreateInfoPanel::InitUpgradeData(EBuildingIndex p_Index, IBuilding *p_Building){

}

void UIBuildingCreateInfoPanel::InitWidget(){

}
