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