#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIAllianceJoinView : public UIBasePanel
{

  CREATE_FUNC(UIAllianceJoinView);
  CreateUIPanel(UIAllianceJoinView);
  CreateUICCSView(UIAllianceJoinView);
  
public: 
  static UIAllianceJoinView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};