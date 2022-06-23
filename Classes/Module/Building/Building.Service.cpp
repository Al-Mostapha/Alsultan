#include "Building.Service.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Player/Player.DT.h"

void BuildingService::getCityBuilding(int32 idCity)
{
    NetBaseModule::getJson(
        "/api/CityBuilding/getCityBuilding",
        [](GJson *json)
        {
            if (json == nullptr)
            {
                cocos2d::log("Error Null ptr From CityBuilding Fitch");
                return;
            }
            if (GString(json->GetString("state")) == "ok")
                DTPlayer::SultanPlayer.City.CityBuilding.fromJson(json->GetJsonObject("CityBuilding"));
            else
                cocos2d::log("Error Fetching CityBuilding From Server ....");
        });
}