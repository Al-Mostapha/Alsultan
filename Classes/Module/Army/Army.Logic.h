#pragma once 
#include "Army.Type.h"
#include "Base/BaseTypeDef.h"
#include "Base/Containers/Pair.h"
#include "Module/Building/Building.Enum.h"


class ArmyLogic{
  public:
  static ArmyLogic *Get();
  GPair<GVector<RCanTrainArmy>, int32> GetCanTrainList(EBuilding p_Bid);
};