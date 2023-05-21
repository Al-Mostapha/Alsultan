#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

class KingdomMapCtrl
{
public: 
  static KingdomMapCtrl *Get();
  int32 GetHallWarCount();
  void ReLoginFinish();
  EKingdomClassType GetKingdomClass();
};