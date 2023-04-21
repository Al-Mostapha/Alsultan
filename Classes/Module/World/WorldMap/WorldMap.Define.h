#pragma once
#include "Include/IncludeBase.h"

class WorldMapDefine{
public: 
  static WorldMapDefine * Get();
  int32 CurrentMapKindomID = 0;
  bool IsInWar();
  bool IsInLegendLord();
  bool IsInRemains();
  bool IsInRadiance();
  bool IsInAtlantis();
  bool InInCrossWar();
  bool IsInKingdomBattle();
  bool IsInWarForbid(bool p_NoShowTips = false, bool p_Activity = false);
  bool IsInWarForbidSoldier(bool p_NoShowTips = false, bool p_Activity = false);
};