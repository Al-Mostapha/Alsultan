#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBaseView.h"

class UIWorldMapBossProgressBar : public UIBaseView
{

  CREATE_FUNC(UIWorldMapBossProgressBar);
  CreateUIPanel(UIWorldMapBossProgressBar);
  CreateUICCSView(UIWorldMapBossProgressBar);

  
public: 
  static UIWorldMapBossProgressBar* Create();
  void Ctor() override;
  void SetPercent(float p_Percent) {};
  void SetReleaseTime(GTime p_Time) {};
};