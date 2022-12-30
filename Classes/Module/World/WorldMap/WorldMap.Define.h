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
};