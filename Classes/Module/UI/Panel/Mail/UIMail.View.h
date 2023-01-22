#pragma once
#include "Module/UI/UICCSView.h"

struct RMailInitData{

};

class UIMailView : UIBaseView{
  CREATE_FUNC(UIMailView);
  CreateUIPanel(UIMailView);
  CreateUICCSView(UIMailView);
public:
  static UIMailView* Create();
  void Show();
  void InitWithData(RMailInitData *p_InitData = nullptr);
};