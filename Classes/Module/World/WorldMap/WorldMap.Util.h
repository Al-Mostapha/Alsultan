#pragma once
#include "Base/BaseTypeDef.h"
#include "WorldMap.Type.h"
class WorldMapUtil{
  public:
  static WorldMapUtil *Get();
  void ResetConfig();
  GString GetTileMapTmxForPlatform(const GString &p_TmxName){
    return p_TmxName + ".tmx";
  }

  RBorderLodScale GetLodByScale(float p_Scale, RBorderLodScale p_Default);
  bool IsLodOpen();
  bool IsTroopPriority();
};  