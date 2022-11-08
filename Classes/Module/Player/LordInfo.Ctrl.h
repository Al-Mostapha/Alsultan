#pragma once
#include "Include/IncludeBase.h"

class LordInfoCtrl 
{
public:
  static LordInfoCtrl *Get();
  bool GetLordUpgradePopStatus();
  bool GetUserAgreementPop();
};