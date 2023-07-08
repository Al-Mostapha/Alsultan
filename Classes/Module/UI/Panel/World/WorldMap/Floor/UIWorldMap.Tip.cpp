#include "UIWorldMap.Tip.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"

UIWorldMapTip *UIWorldMapTip::Create(int32 p_KingdomID)
{
  return Create("UiParts/Panel/World/WorldMap/Floor/worldMapTip.csb");
}

void UIWorldMapTip::Ctor(){

}

void UIWorldMapTip::SetTilePoint(Vec2 p_TilePos){}

void UIWorldMapTip::SetWorldMapCell(WorldMapCell *p_Cell){}

void UIWorldMapTip::SetFavoriteName(const GString &p_Name){}

void UIWorldMapTip::SetIsCanZhanling(bool p_IsCanZhanling, GString p_MsgTipsKey){}

void UIWorldMapTip::InitMapData(Node *p_TileInstance){}

void UIWorldMapTip::SetPosition(Vec2 p_CoverShowPoint){}
