#pragma once
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Module/UI/UIBasePanel.h"

class UILoginInput : public UIBasePanel
{
public:
  static UILoginInput *Create();
  void Ctor() override;
  void SetModel(int32 p_Model);
};


