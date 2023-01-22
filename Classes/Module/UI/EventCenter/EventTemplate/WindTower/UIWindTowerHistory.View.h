#pragma once
#include "Module/UI/UICCSView.h"

class UIWindTowerHistoryView : UIBaseView{
  CREATE_FUNC(UIWindTowerHistoryView);
  CreateUIPanel(UIWindTowerHistoryView);
  CreateUICCSView(UIWindTowerHistoryView);
public: 
  static UIWindTowerHistoryView* Create();
  void Show();
};