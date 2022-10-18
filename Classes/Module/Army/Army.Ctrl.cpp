#include "Army.Ctrl.h"

ArmyCtrl* ArmyCtrl::Get() {
  static ArmyCtrl* s_ArmyCtrl = new ArmyCtrl();
  return s_ArmyCtrl;
}

GTime ArmyCtrl::GetHostpitalPyramidWarCDQueueTime() {
  return 0;
}

EArmy ArmyCtrl::GetTrainedArmy(EBuilding p_Building) {
  return EArmy::None;
}

void ArmyCtrl::GetTrainArmyReq(EBuilding p_Building){
  
}