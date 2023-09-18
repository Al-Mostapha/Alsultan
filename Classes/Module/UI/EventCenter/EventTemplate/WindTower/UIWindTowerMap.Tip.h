#pragma once
#include "Module/UI/UICCSView.h"
#include "WindTower.Enum.h"

class UIWindTowerMapTip : public UIBaseView{
  CREATE_FUNC(UIWindTowerMapTip);
  CreateUIPanel(UIWindTowerMapTip);
  CreateUICCSView(UIWindTowerMapTip);
public: 
  static UIWindTowerMapTip* Create();
  void InitActivityTime(GTime pLeftTime, GTime pTotalTime, EWindTowerStatus pStatus, bool pIsSurveying = false);
};