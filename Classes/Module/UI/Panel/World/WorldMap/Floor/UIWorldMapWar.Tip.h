#pragma once
#include "Module/UI/UICCSView.h"
#include "Module/UI/UIBasePanel.h"

class UIWorldMapWarTip : public UIBaseView
{

  CREATE_FUNC(UIWorldMapWarTip);
  CreateUIPanel(UIWorldMapWarTip);
  CreateUICCSView(UIWorldMapWarTip);

  
public: 
  static UIWorldMapWarTip* Create();
  void Ctor() override;
};