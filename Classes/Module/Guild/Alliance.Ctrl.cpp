#include "Alliance.Ctrl.h"

AllianceCtrl *AllianceCtrl::Get()
{
  static auto s_AllianceCtrl = new AllianceCtrl();
  return s_AllianceCtrl;
}

void AllianceCtrl::Req4AllianceInviteData()
{
  // ...
}