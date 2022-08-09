#include "Building.Service.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Player/Player.DT.h"
#include "Scene/CityScene.h"
#include "Module/Building/Building.Module.h"

void BuildingService::fetchCityBuilding(int32 idCity)
{
    NetBaseModule::getJson(
        "/api/CityBuilding/fetchCityBuilding",
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

void BuildingService::fetchBuildingInfo()
{
    NetBaseModule::getJson(
        "/api/Building/fetchBuildingInfo",
        [](GJson *json)
        {
            if (json == nullptr)
            {
                cocos2d::log("Error Null ptr From getBuildingInfo Fetch");
                return;
            }
            // cocos2d::log("Data Fetched %s", json->);
            if (GString(json->GetString("state")) == "ok")
            {
                GJson *BuildingInfo = json->GetJsonObject("BuildingInfo");
                for (auto it = BuildingInfo->MemberBegin(); it != BuildingInfo->MemberEnd(); ++it)
                {
                    EBuildingType l_BuildingType = EBuildingType::CBType_None;
                    if (it->name.IsInt())
                        l_BuildingType = static_cast<EBuildingType>(it->name.GetInt());
                    else if(it->name.IsString())
                        l_BuildingType = static_cast<EBuildingType>(std::stoi(it->name.GetString()));
                    GJson doc;

                    GJson *JsonObject = new GJson();
                    JsonObject->CopyFrom(it->value, JsonObject->GetAllocator());
                    // BuildingStatic::BuildingInfo[l_BuildingType] = DSBuildingInfoUnit::fromJson(JsonObject);
                }

                DTPlayer::SultanPlayer.City.CityBuilding.fromJson(json->GetJsonObject("CityBuilding"));
            }
            else
                cocos2d::log("Error Fetching CityBuilding From Server ....");
        });
}
