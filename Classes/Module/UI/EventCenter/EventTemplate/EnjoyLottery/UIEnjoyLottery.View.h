#pragma once
#include "Module/UI/UICCSView.h"

class UIEnjoyLotteryView : UIBaseView{
  CREATE_FUNC(UIEnjoyLotteryView);
  CreateUIPanel(UIEnjoyLotteryView);
  CreateUICCSView(UIEnjoyLotteryView);
public: 
  static UIEnjoyLotteryView* Create();
  void Show();
};