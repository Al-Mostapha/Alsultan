#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWorldMapLostRuinsView : public UIBasePanel{
  CREATE_FUNC(UIWorldMapLostRuinsView);
  CreateUIPanel(UIWorldMapLostRuinsView);
  CreateUICCSView(UIWorldMapLostRuinsView);
public: 
  static UIWorldMapLostRuinsView* Create();
  void InitData(uint32 pInstanceID);
  
  void SetTilePoint(Vec2 pTilePoint);
};