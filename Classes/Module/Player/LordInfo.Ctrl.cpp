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

RLordInfo LordInfoCtrl::GetLordInfoByUid( Guid p_PlayerUid, int32 p_KID, const char *p_From )
{
  return RLordInfo();
}

uint32 LordInfoCtrl::GetLordLevel()
{
  return 0;
}

int32 LordInfoCtrl::GetMapSourceKid()
{
  return 0;
}

EShowOfficialType LordInfoCtrl::GetShowOfficialTypeForLord(const RLordInfo &pLordInfo){
  return EShowOfficialType::KING;
}