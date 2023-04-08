#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIAllianceWarView : public UIBasePanel
{
CREATE_FUNC(UIAllianceWarView);
CreateUIPanel(UIAllianceWarView);
CreateUICCSView(UIAllianceWarView);
public:
  static UIAllianceWarView* Create();
  void Ctor() override;
  void InitData();
  void InitWidget();
};