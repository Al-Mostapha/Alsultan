#pragma once
#include "Include/IncludeBase.h"
#include "Module/UI/UIBasePanel.h"

class UIRechargeTinyPageNode : public UIBasePanel
{
public:
  static UIRechargeTinyPageNode* Create();
  void SetMyGiftType(int32 p_Type){}
};