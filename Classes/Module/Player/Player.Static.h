#pragma once
#include "Module/City/City.DT.h"
#include "Module/Effect/Effect.Type.h"
#include "Player.Type.h"


class PlayerStatic
{
public:
    static TPlayer SultanPlayer;
    static GHashMap<EEffectType, TEffect>& getEffects(){
        return SultanPlayer.Effect;
    }
};
