#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Json.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/Army/Army.DT.h"
#include "Module/CityResource/CityResource.DT.h"

struct DSCity
{
    int32 idPlayer;
    int32 idCity;
    DSCityBuilding CityBuilding;
    DSCityArmy CityArmy;
    DSCityResource CityResource;
    void fromJson(GJson *json)
    {
        if (json == nullptr)
            return;
        idPlayer = json->GetInt("idPlayer", 0);
        idCity = json->GetInt("idCity", 0);
        CityBuilding.fromJson(json->GetJsonObject("CityBuilding"));
        CityArmy.fromJson(json->GetJsonObject("CityArmy"));
        CityResource.fromJson(json->GetJsonObject("CityResource"));
    }
};