#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UICommonFramTitle : public UIBasePanel
{

  CREATE_FUNC(UICommonFramTitle);
  CreateUIPanel(UICommonFramTitle);
  CreateUICCSView(UICommonFramTitle);

  Sprite *_Bg = nullptr;
  ui::Text *_Title = nullptr;
  ui::Button *_BtnQuest = nullptr;
  ui::Button *_BtnMyHelp = nullptr;
  Node *_NodeStyleBg = nullptr;
  Node *_Node6thLace = nullptr;

public: 
  static UICommonFramTitle* Create();
  void Ctor() override;
  void InitWidget();
  void SetTitle(const GString& p_Title);
  void SetBtnHelpClickCallBack(Widget::ccWidgetTouchCallback p_Handle){}
  void InitStyle();
};