#pragma once
#include "Army.Enum.h"
#include "Army.Type.h"

class ArmyLtCtrl
{
  public: 
    static ArmyLtCtrl *Get();
    ESoldierType GetSoldierType(EArmy p_ArmyId);
    bool IsWarframeArmyID(EArmy p_ArmyId) {return true;}
    RArmyInfo GetArmyInfo(EArmy p_ArmyId) {return RArmyInfo();}
};