#include "Building.Service.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Player/Player.DT.h"
#include "Scene/CityScene.h"
#include "Module/Building/Building.Module.h"

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
            auto newScene = CityScene::createScene();
            // cocos2d::Director::getInstance()->popScene();
            cocos2d::Director::getInstance()->pushScene(newScene);
        });
}
