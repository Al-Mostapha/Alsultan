#include "UIWorldMapGotoPointPanel.h"

UIWorldMapGotoPointPanel *UIWorldMapGotoPointPanel::Create(bool pHideKingIDTextField){
  auto l_Panel = Create("UiParts/Panel/World/WorldMap/worldMapGotoPointPanel.csb");
  l_Panel->_HideKingIDTextField = pHideKingIDTextField;
  return l_Panel;
}

void UIWorldMapGotoPointPanel::Ctor(){
  
}


void UIWorldMapGotoPointPanel::UpdateData(int32 pKingdomID, Vec2 pPoint){}