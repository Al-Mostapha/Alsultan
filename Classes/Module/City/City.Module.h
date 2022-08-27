#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/Building/Building.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Army/Army.Module.h"
#include "Module/CityResource/Resource.Module.h"
#include "Module/Player/Player.Module.h"
#include "Module/Building/Building.Module.h"
#include "Module/City/City.Const.h"
#include "Module/City/City.DT.h"
#include "Module/Player/Player.DT.h"

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
    static void showCityBuilding();
    static void showCityEffect();
    static TCity& getCurrentCity(){
        return DTPlayer::SultanPlayer.City;
    }
};