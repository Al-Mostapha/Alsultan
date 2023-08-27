#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldWar/WorldWar.Enum.h"

class ConquestWarCtrl
{
public:
  static ConquestWarCtrl *Get();
  EConquestWarState GetConquestWarState();
  bool IsMatchKingdom(int32 pKid1, int32 pKid2);
  bool IsConquestWarOpenningAndNotInWar(){
    return true;
  }
  bool IsPlayerConquestWarMigration(){
    return false;
  }
};