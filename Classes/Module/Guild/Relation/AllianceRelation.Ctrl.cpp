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

EMapAllianceRelationType AllianceRelationCtrl::GetRelationTypeWith(int32 p_LeagueID){
  return EMapAllianceRelationType::None;
}

int32 AllianceRelationCtrl::GetTerrScore(int32 p_AId){
  return 0;
}