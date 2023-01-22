#pragma once
#include "Include/IncludeBase.h"
#include "Module/UI/UICCSView.h"
#include "Module/Player/Player.Type.h"

class UILordView : public UIBaseView
{
  CREATE_FUNC(UILordView);
  CreateUICCSView(UILordView);
  CreateUIPanel(UILordView);
public:
  static UILordView *Create();
  void InitData(const RLordInfo &p_LordInfo);
  void Show();
};