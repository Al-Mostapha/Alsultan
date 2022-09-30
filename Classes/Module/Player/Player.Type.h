#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/HashMap.h"
struct RPlayer
{
    int32 idCurrentCity;
    int32 idPlayer;
    struct RCity City;
    GHashMap<enum class EEffect, struct TEffect> Effect;
};
