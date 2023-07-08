#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class WorldMapCell;

class UIWorldMapTip : public UIBaseView
{

  CREATE_FUNC(UIWorldMapTip);
  CreateUIPanel(UIWorldMapTip);
  CreateUICCSView(UIWorldMapTip);

  
public: 
  static UIWorldMapTip* Create(int32 p_KingdomID);
  void Ctor() override;
  void SetTilePoint(Vec2 p_TilePos);
  void SetWorldMapCell(WorldMapCell *p_Cell);
  void SetFavoriteName(const GString &p_Name);
  void SetIsCanZhanling(bool p_IsCanZhanling, GString p_MsgTipsKey);
  void InitMapData(Node *p_TileInstance);
  void SetPosition(Vec2 p_CoverShowPoint);
};