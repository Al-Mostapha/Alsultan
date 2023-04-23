#pragma once
#include "Include/IncludeBase.h"
#include "Army.Enum.h"
#include "Module/Building/Building.Enum.h"

class ArmyCtrl { 
public: 
  static ArmyCtrl* Get(); 
  EArmy GetTrainArmy(EBuilding p_Building);
  GTime GetHostpitalPyramidWarCDQueueTime();
  void GetTrainArmyReq(EBuilding p_Building);
};