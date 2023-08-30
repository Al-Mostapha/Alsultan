#include "UIWorldMapBoss.View.h"

UIWorldMapBossView *UIWorldMapBossView::Create()
{
  return Create("UiParts/Panel/World/WorldMap/Instance/Unit/Boss/worldMapBossView.csb");
}

void UIWorldMapBossView::Ctor(){
  UITouchBaseView::Ctor();
}

void UIWorldMapBossView::InitData(IWorldMapInstance *pMapInstance){
  
}

void UIWorldMapBossView::SetTilePoint(const Vec2 &p_TilePoint) {};