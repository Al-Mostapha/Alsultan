#pragma once
#include "Base/BaseTypeDef.h"
class WorldMapUtil{
  public:
  static WorldMapUtil *Get();
  void ResetConfig();
  GString GetTileMapTmxForPlatform(const GString &p_TmxName){
    return p_TmxName + ".tmx";
  }

  bool IsLodOpen();
};  