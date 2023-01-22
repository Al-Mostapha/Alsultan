#pragma once
#include "Include/IncludeBase.h"
#include "Player.Type.h"
class LordInfoCtrl 
{
public:
  static LordInfoCtrl *Get();
  bool GetLordUpgradePopStatus();
  bool GetUserAgreementPop();
  RLordBaseInfo GetBaseInfo();
  RLordInfo GetLordInfo();
  uint32 GetLordLevel();
};