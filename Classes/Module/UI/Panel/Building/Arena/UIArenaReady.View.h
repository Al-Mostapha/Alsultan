#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIArenaReadyView : public UIBasePanel
{

  CREATE_FUNC(UIArenaReadyView);
  CreateUIPanel(UIArenaReadyView);
  CreateUICCSView(UIArenaReadyView);

  
public: 
  static UIArenaReadyView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};