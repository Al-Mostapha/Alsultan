#pragma once
#include "Base/BaseTypeDef.h"
#include "EndlessTrials.Type.h"
#include "Base/Containers/HashMap.h"

class EndlessTrialsCtrl{
  public:
    static EndlessTrialsCtrl *Get();
    GHashMap<uint32, REndlessTrailsSnowMountain> _MountainConfig;
    GHashMap<uint32, REndlessTrailsSnowMountain> GetMountainConfig();
    REndlessTrailsSnowMountain GetMountainConfig(uint32 pID);


};