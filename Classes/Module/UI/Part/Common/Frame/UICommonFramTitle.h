#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UICommonFramTitle : public UIBasePanel
{

  CREATE_FUNC(UICommonFramTitle);
  CreateUIPanel(UICommonFramTitle);
  CreateUICCSView(UICommonFramTitle);

  
public: 
  static UICommonFramTitle* Create();
  void Ctor() override;
  void InitWidget();
  void SetTitle(const GString& p_Title){}
  void SetBtnHelpClickCallBack(Widget::ccWidgetTouchCallback p_Handle){}
};