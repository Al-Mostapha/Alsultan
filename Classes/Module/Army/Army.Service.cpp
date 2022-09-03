#include "Module/Army/Army.Service.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Player/Player.Static.h"

void ArmyService::getCityArmy(int32 idCity)
{

    NetBaseModule::getJson(
        "/api/CityArmy/getCityArmy",
        [](GJson *json)
        {
            if (json == nullptr)
                return;
            if (GString(json->GetString("state")) == "ok")
            {
                PlayerStatic::SultanPlayer.City.CityArmy.fromJson(json->GetJsonObject("CityArmy"));
                cocos2d::log("Test Rest Test %d", PlayerStatic::SultanPlayer.City.CityArmy.ArmyA.idCity);
            }
            else
            {
                cocos2d::log("Errror Json Requset %s", json->GetString("state"));
            }
        });
}