#include "Module/CityResource/CityResource.Service.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Player/Player.Static.h"

void CityResourceService::getCityResource(int32 idCity)
{
    NetBaseModule::getJson(
        "/api/CityResource/getCityResource",
        [](GJson *json)
        {
            if (json == nullptr)
            {
                cocos2d::log("Null Ptr From City Resource");
                return;
            }
            if (GString(json->GetString("state")) == "ok")
                PlayerStatic::SultanPlayer.City.CityResource.fromJson(json->GetJsonObject("CityResource"));
            else
                cocos2d::log("Error Fetch City Resource ...");
        });
}