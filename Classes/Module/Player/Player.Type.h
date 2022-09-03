#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/HashMap.h"
struct TPlayer
{
    int32 idCurrentCity;
    int32 idPlayer;
    struct TCity City;
    GHashMap<enum class EEffectType, struct TEffect> Effect;
};
