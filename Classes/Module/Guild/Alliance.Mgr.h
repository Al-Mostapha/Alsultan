#pragma once
#include "Include/IncludeBase.h"

class AllianceManager{
public:
  static AllianceManager *Get();
  int32 IsHaveActived();
  Guid HasJoinAlliance(bool p_IsTeam = false);
  void ReqAgreeInviteJoin(Guid p_AllianceID, Guid p_PlayerId){}
};