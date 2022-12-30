#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/UICCSView.h"

class UISystemNoticeView : public UIBaseView
{
  CREATE_FUNC(UISystemNoticeView);
  CreateUIPanel(UISystemNoticeView);
  CreateUICCSView(UISystemNoticeView);

public:
  static UISystemNoticeView *Create();
  void Ctor();
  void AddSubViews();
};


