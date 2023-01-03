#include "AllianceRelation.Ctrl.h"

AllianceRelationCtrl *AllianceRelationCtrl::Get()
{
  static AllianceRelationCtrl *s_pInstance = new AllianceRelationCtrl();
  return s_pInstance;
}

int32 AllianceRelationCtrl::GetAllyInviteNum()
{
  return 0;
}