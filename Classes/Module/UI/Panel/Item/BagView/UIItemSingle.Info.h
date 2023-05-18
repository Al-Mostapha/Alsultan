#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIItemSingleInfo : public UIBasePanel
{

  CREATE_FUNC(UIItemSingleInfo);
  CreateUIPanel(UIItemSingleInfo);
  CreateUICCSView(UIItemSingleInfo);
public: 
  static UIItemSingleInfo* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};