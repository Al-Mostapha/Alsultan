#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

class UILostRuinsMapTip : public UIBaseView{
  CREATE_FUNC(UILostRuinsMapTip);
  CreateUIPanel(UILostRuinsMapTip);
  CreateUICCSView(UILostRuinsMapTip);
public: 
  static UILostRuinsMapTip* Create();
  void InitActivityTime(GTime pLeftTime, GTime pTotalTime, ELosRuinsStatus pStatus, bool pIsSurveying = false);
  void SetTimeEndCallBack(const std::function<void()> &pCallBack);
};