#pragma once
#include "Include/IncludeBase.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

class WorldMapWarDef{
public: 
  static WorldMapWarDef * Get();
  GString GetKingdomClassTips(EKingdomClassType type, int32 p_IdKingdom = 0);
  EKingdomClassType GetKingdomMapClassByKingdomId(int32 p_IdKingdom = 0);
  bool IsInWarForbidBonePoing(EKingdomClassType p_MapType);
  int32 GetMapRangMaxX(EKingdomClassType p_MapType);
  bool IsInWarForbidResourceHelp(EKingdomClassType p_MapType = EKingdomClassType::Normal);
};