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
  RLordInfo GetLordInfoByUid( Guid p_PlayerUid, int32 p_KID, const char *p_From);
  uint32 GetLordLevel();
  uint32 GetSourceKid();
  int32 GetMapSourceKid();
  EShowOfficialType GetShowOfficialTypeForLord(const RLordInfo &pLordInfo);
  
};