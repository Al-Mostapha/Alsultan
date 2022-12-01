#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/UIBasePanel.h"

class UISystemNoticeView : public UIBasePanel
{
  CREATE_FUNC(UISystemNoticeView);
public:
  static UISystemNoticeView *Create();
  void Ctor() override;
  void AddSubViews() override;
};


