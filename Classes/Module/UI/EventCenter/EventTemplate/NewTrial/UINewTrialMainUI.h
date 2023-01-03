#pragma once
#include "Include/IncludeBase.h"
#include "Module/UI/UICCSView.h"

class UINewTrailMainUI : public UIBaseView
{
  CREATE_FUNC(UINewTrailMainUI);
  CreateUIPanel(UINewTrailMainUI);
  CreateUICCSView(UINewTrailMainUI);
public:
  static UINewTrailMainUI *Create();
};