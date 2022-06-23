#pragma once
#include "Include/IncludeBase.h"
#include "Module/Building/Building.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Army/Army.Module.h"
#include "Module/CityResource/Resource.Module.h"
#include "Module/Player/Player.Module.h"

class CityModule
{
public:
    static void GetPlayerCity(int32 idPayer)
    {
        NetBaseModule::getJson(
            "/api/City/getCity",
            [](GJson *json)
            {
                if (json == nullptr)
                    return;
                // DSCity city;
                // SultanPlayer.City.fromJson(json);
                // SultanPlayer.City.CityBuilding.fromJson(json);
                //  city.CityBuilding.fromJson(json);
            });
    }
};