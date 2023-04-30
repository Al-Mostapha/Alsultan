#include "Army.LtCtrl.h"

ArmyLtCtrl *ArmyLtCtrl::Get()
{
  static ArmyLtCtrl *s_ArmyLtCtrl = nullptr;
  if (s_ArmyLtCtrl == nullptr)
  {
    s_ArmyLtCtrl = new ArmyLtCtrl();
  }
  return s_ArmyLtCtrl;
}

ESoldierType ArmyLtCtrl::GetSoldierType(EArmy p_ArmyId)
{
  //   local armyType = armyltCtrl.armyAttr(armyid, ARMY_ATTR.ARMY_TYPE)
  // if gArmyType.infantryDf == armyType or gArmyType.infantryAk == armyType then
  //   return gSoldierType.SOLDIER_TYPE_BUBING
  // elseif gArmyType.cavalry == armyType or gArmyType.cavalryArrow == armyType then
  //   return gSoldierType.SOLDIER_TYPE_QIBING
  // elseif gArmyType.archer == armyType or gArmyType.crossbow == armyType then
  //   return gSoldierType.SOLDIER_TYPE_GONGBING
  // elseif gArmyType.charists == armyType or gArmyType.siegeVehicles == armyType then
  //   return gSoldierType.SOLDIER_TYPE_CHEBING
  // elseif gArmyType.elite == armyType then
  //   return gSoldierType.SOLDIER_TYPE_ELITE
  // end
  return ESoldierType::Bubing;
}