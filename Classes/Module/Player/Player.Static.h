#pragma once
#include "Module/City/City.Type.h"
#include "Module/Effect/Effect.Type.h"
#include "Player.Type.h"


class PlayerStatic
{
public:
    static RPlayer SultanPlayer;
    static RPlayer& getPlayer();
    static GHashMap<EEffectType, TEffect>& getEffects(){
        return SultanPlayer.Effect;
    }
};
