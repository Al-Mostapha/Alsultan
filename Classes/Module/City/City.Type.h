#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Json.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/Army/Army.Type.h"
#include "Module/CityResource/Resource.Type.h"

struct RCity
{
    int32 idPlayer;
    int32 idCity;
    RCityBuilding CityBuilding;
    RCityArmy CityArmy;
    RCityResource CityResource;
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

