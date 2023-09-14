#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"

class WorldMapChest;

class UIWorldMapChestView : public UITouchBaseView
{
  CREATE_FUNC(UIWorldMapChestView);
  CreateUIPanel(UIWorldMapChestView);
  CreateUICCSView(UIWorldMapChestView);
public: 
  static UIWorldMapChestView* Create();
  void InitData( WorldMapChest *pMapInstance);
  void Ctor() override;
  void SetTilePoint(const Vec2 &pTilePoint);
};