#pragma once

#include "Base/BaseTypeDef.h"
#include "Alliance.Type.h"

class AllianceCtrl{
public:
  static AllianceCtrl *Get();
  void Req4AllianceInviteData();
  void ResetAllianceInvitePopInfo(){}
  $AlliancePrifeInfo GetAllianceInvitePopInfo();
};