#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UITouchBaseView.h"
#include "WindTower.Enum.h"

class UIWindTowerBuildView : public UITouchBaseView{
  CREATE_FUNC(UIWindTowerBuildView);
  CreateUIPanel(UIWindTowerBuildView);
  CreateUICCSView(UIWindTowerBuildView);
public: 
  static UIWindTowerBuildView* Create();
  void InitData(int32 pInstanceID, EWindTowerStatus pStatus);
  void SetTilePoint(Vec2 pTilePoint);
};