#include "Army.Logic.h"

ArmyLogic *ArmyLogic::Get()
{
  static ArmyLogic *s_ArmyLogic = nullptr;
  if (s_ArmyLogic == nullptr)
  {
    s_ArmyLogic = new ArmyLogic();
  }
  return s_ArmyLogic;
}

GPair<GVector<RCanTrainArmy>, int32> ArmyLogic::GetCanTrainList(EBuilding p_Bid)
{
  GPair<GVector<RCanTrainArmy>, int32> ret(GVector<RCanTrainArmy>(), -1);
  return ret;
}