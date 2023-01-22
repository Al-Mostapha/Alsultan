#pragma once
#include "Module/UI/UICCSView.h"

class UILostRuinsRecordView : UIBaseView{
  CREATE_FUNC(UILostRuinsRecordView);
  CreateUIPanel(UILostRuinsRecordView);
  CreateUICCSView(UILostRuinsRecordView);
public: 
  static UILostRuinsRecordView* Create();
  void Show();
};