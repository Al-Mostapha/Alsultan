#include "UISoldiersCampView.h"

UISoldiersCampView *UISoldiersCampView::Create(){
  auto l_Panel = UISoldiersCampView::Create("UiParts/Panel/Building/Common/Train/soldiersCampView.csb");
  return l_Panel;
}

void UISoldiersCampView::Ctor(){

}

void UISoldiersCampView::InitData(EBuildingIndex p_Index, IBuilding *p_Building){

}

void UISoldiersCampView::InitWidget(){

}
