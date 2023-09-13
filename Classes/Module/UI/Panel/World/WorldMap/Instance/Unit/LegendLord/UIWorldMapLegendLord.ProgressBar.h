#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBaseView.h"

class UIWorldMapLegendLordProgressBar : public UIBaseView
{

  CREATE_FUNC(UIWorldMapLegendLordProgressBar);
  CreateUIPanel(UIWorldMapLegendLordProgressBar);
  CreateUICCSView(UIWorldMapLegendLordProgressBar);

  
public: 
  static UIWorldMapLegendLordProgressBar *Create();
  void Ctor() override;
  void SetBuildID(int32 pBuildID){}
  void BeginTime(GTime pTime){}
  void EndTime(){}
};