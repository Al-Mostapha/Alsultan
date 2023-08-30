#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"

class IWorldMapInstance;

class UIWorldMapBossView : public UITouchBaseView
{
  CREATE_FUNC(UIWorldMapBossView);
  CreateUIPanel(UIWorldMapBossView);
  CreateUICCSView(UIWorldMapBossView);
public: 
  static UIWorldMapBossView* Create();
  virtual void InitData(IWorldMapInstance *pMapInstance);
  void Ctor() override;
  void SetTilePoint(const Vec2 &p_TilePoint);
};