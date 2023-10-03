#pragma once
#include "Module/City/City.Type.h"
#include "Module/Effect/Effect.Type.h"
#include "Player.Type.h"


class PlayerStatic
{
public:
    static RPlayer SultanPlayer;
    static RPlayer& getPlayer();
    static GHashMap<EEffect, TEffect>& getEffects(){
        return SultanPlayer.Effect;
    }
    static PlayerStatic *Get();
    GString GetPlayerToken();
    GHashMap<int32, RCity>& GetCities(){
        return SultanPlayer._Cities;
    }
};
