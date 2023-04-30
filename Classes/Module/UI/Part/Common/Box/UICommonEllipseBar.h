#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UICommonEllipseBar : public UIBasePanel
{

  CREATE_FUNC(UICommonEllipseBar);
  CreateUIPanel(UICommonEllipseBar);
  CreateUICCSView(UICommonEllipseBar);

  
public: 
  static UICommonEllipseBar* Create();
  
  void Ctor() override {};
  void SetRadius(float p_Rad){}
  void SetFrameAnimation(
    const char *p_frame = "dh_xueyuanyjf1_00.png",
    const char *p_Format = "dh_xueyuanyjf1_%.2d.png", 
    int32 p_PIndex = 0, int32 p_EIndex = 14){}
  void SetPercent(float p_Percent){}
};