#pragma once
#include "Base/BaseTypeDef.h"

class WorldMapDefine{
public: 
  static WorldMapDefine * Get();
  int32 CurrentMapKindomID = 0;
  cocos2d::Size _WorldMapViewSize;
  bool IsInWar();
  bool IsInLegendLord();
  bool IsInRemains();
  bool IsInRadiance();
  bool IsInAtlantis();
  bool InInCrossWar();
  bool IsInKingdomBattle();
  bool IsInWarForbid(bool p_NoShowTips = false, bool p_Activity = false);
  bool IsInWarForbidSoldier(bool p_NoShowTips = false, bool p_Activity = false);
  void ShowWarTips(bool p_Activity = false);
  bool IsNebulaKingdomID();
  bool IsLegendLordKingdomID();
};