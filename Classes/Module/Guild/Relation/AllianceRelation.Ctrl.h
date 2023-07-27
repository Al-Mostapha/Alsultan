#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/Guild/Alliance.Enum.h"

class AllianceRelationCtrl
{
public:
  static AllianceRelationCtrl *Get();
  int32 GetAllyInviteNum();
  EMapAllianceRelationType GetRelationTypeWith(int32 p_LeagueID);
  int32 GetTerrScore(int32 p_AId);
};