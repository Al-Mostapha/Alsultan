#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Type.h"

class CollectMapCtrl
{
  public:
    static CollectMapCtrl *Get();
    GHashMap<int32, RAllianceMarkData> GetAllianceMarkData();
};