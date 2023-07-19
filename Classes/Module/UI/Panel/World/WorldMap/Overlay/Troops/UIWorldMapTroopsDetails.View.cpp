#include "UIWorldMapTroopsDetails.View.h"

UIWorldMapTroopsDetailsView *UIWorldMapTroopsDetailsView::Create()
{
  // return Create("UiParts/Panel/World/WorldMap/Floor/worldMapPyramidTip.csb");
  return create();
}

void UIWorldMapTroopsDetailsView::Ctor(){
  UITouchBaseView::Ctor();
}

void UIWorldMapTroopsDetailsView::InitData(
  GVector<RMoveLineArmyData> pArmyData, const GString &pLeagueName,
  GOpt<OtherData>){
  
}

