#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/HashMap.h"
#include "Module/City/City.Type.h"
struct RPlayer
{
    int32 idCurrentCity;
    int32 idPlayer;
    RCity City;
    GHashMap<enum class EEffect, struct TEffect> Effect;
};

struct RLordBaseInfo {
  bool bHasBindAccountReward = false;
  bool bReceiveBindPhone = false;
};
