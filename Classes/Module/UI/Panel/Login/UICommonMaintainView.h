#pragma once
#include "Module/UI/UICCSView.h"

class UICommonMaintainView : public UIBaseView
{
  CREATE_FUNC(UICommonMaintainView);
  CreateUIPanel(UICommonMaintainView);
  CreateUICCSView(UICommonMaintainView);
public:
  void InitData(GTime p_Time);
};