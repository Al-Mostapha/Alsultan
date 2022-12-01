#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/UIBasePanel.h"

class UIIphoneXBottom : public UIBasePanel
{
  CREATE_FUNC(UIIphoneXBottom);
public:
  static UIIphoneXBottom *Create();
  void Ctor() override;
  void AddSubViews() override;
};


