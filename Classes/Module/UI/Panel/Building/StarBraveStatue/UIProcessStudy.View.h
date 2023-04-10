#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIProcessStudyView : public UIBasePanel
{

  CREATE_FUNC(UIProcessStudyView);
  CreateUIPanel(UIProcessStudyView);
  CreateUICCSView(UIProcessStudyView);
  
public: 
  static UIProcessStudyView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};