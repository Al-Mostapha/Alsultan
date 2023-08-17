#pragma once
#include "Base/BaseTypeDef.h"
#include "WorldMap.Type.h"
class WorldMapUtil{
  public:
  GHashMap<int32, int32> _CastleModelCfg;
  static WorldMapUtil *Get();
  void Init();
  void ResetConfig();
  GString GetTileMapTmxForPlatform(const GString &p_TmxName){
    return p_TmxName + ".tmx";
  }

  RBorderLodScale GetLodByScale(float p_Scale, RBorderLodScale p_Default);
  bool IsLodOpen();
  bool IsTroopPriority();
};  