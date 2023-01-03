#include "LordInfo.Ctrl.h"

LordInfoCtrl *LordInfoCtrl::Get()
{
  static LordInfoCtrl *l_LordInfoCtrl = new LordInfoCtrl();
  return l_LordInfoCtrl;
}

bool LordInfoCtrl::GetLordUpgradePopStatus()
{
  return false;
}

bool LordInfoCtrl::GetUserAgreementPop()
{
  return false;
}

RLordBaseInfo LordInfoCtrl::GetBaseInfo()
{
  return RLordBaseInfo();
}

RLordInfo LordInfoCtrl::GetLordInfo()
{
  return RLordInfo();
}