#pragma once
#include "Include/IncludeBase.h"

struct TCityResource
{
    int32 idPlayer;
    int32 idCity;
    int32 coin;
    int32 food;
    int32 wood;
    int32 silver;
    int32 iron;
    int32 crystal;
    int32 coinIn;
    int32 foodIn;
    int32 woodIn;
    int32 silverIn;
    int32 ironIn;
    int32 crystalIn;
    int32 coinOut;
    int32 foodOut;
    int32 woodOut;
    int32 silverOut;
    int32 ironOut;
    int32 crystalOut;
    int32 coinCap;
    int32 foodCap;
    int32 woodCap;
    int32 silverCap;
    int32 ironCap;
    int32 crystalCap;
    void fromJson(GJson *json)
    {
        if (json == nullptr)
            return;
        idPlayer = json->GetInt("idPlayer", 0);
        idCity = json->GetInt("idCity", 0);
        coin = json->GetInt("coin", 0);
        food = json->GetInt("food", 0);
        wood = json->GetInt("wood", 0);
        silver = json->GetInt("silver", 0);
        iron = json->GetInt("iron", 0);
        crystal = json->GetInt("crystal", 0);
        coinIn = json->GetInt("coinIn", 0);
        foodIn = json->GetInt("foodIn", 0);
        woodIn = json->GetInt("woodIn", 0);
        silverIn = json->GetInt("silverIn", 0);
        ironIn = json->GetInt("ironIn", 0);
        crystalIn = json->GetInt("crystalIn", 0);
        coinOut = json->GetInt("coinOut", 0);
        foodOut = json->GetInt("foodOut", 0);
        woodOut = json->GetInt("woodOut", 0);
        silverOut = json->GetInt("silverOut", 0);
        ironOut = json->GetInt("ironOut", 0);
        crystalOut = json->GetInt("crystalOut", 0);
        coinCap = json->GetInt("coinCap", 0);
        foodCap = json->GetInt("foodCap", 0);
        woodCap = json->GetInt("woodCap", 0);
        silverCap = json->GetInt("silverCap", 0);
        ironCap = json->GetInt("ironCap", 0);
        crystalCap = json->GetInt("crystalCap", 0);
    }
};
