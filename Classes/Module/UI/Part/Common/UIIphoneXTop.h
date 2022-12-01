#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/UIBasePanel.h"

class UIIphoneXTop : public UIBasePanel
{
  CREATE_FUNC(UIIphoneXTop);
public:
  static UIIphoneXTop *Create();
  void Ctor() override;
  void AddSubViews() override;
};


