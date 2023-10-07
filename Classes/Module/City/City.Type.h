#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Json.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/Army/Army.Type.h"
#include "Module/CityResource/Resource.Type.h"
#include "Base/Type/Json/XJson.h"

struct RCity
{
    int32 idPlayer;
    int32 idCity;
    RCityBuilding CityBuilding;
    RCityArmy CityArmy;
    RCityResource CityResource;
    void fromJson(const XJson &pJson)
    {
        if (pJson.is_null())
          return;
        idPlayer = pJson.value("idPlayer", 0);
        idCity = pJson.value("idCity", 0);
        CityBuilding.fromJson(pJson.value("CityBuilding", XJson::object()));
        CityArmy.fromJson(pJson.value("CityArmy", XJson::object()));
        CityResource.fromJson(pJson.value("CityResource", XJson::object()));
    }
};

