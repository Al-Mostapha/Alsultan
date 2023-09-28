#include "Building.Service.h"
#include "Include/IncludeBuildingFunc.h"
#include "Module/Building/Building.Module.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Player/Player.Static.h"
#include "Scene/CityScene.h"
#include "Module/City/CityBuilding/City.LtCtrl.h"

void BuildingService::fetchCityBuilding(int32 idCity) {
  NetModule::getJson("/api/CityBuilding/fetchCityBuilding", [](GJson* json) {
    if (json == nullptr) {
      cocos2d::log("Error Null ptr From CityBuilding Fitch");
      return;
    }
    if (GString(json->GetString("state")) == "ok")
      PlayerStatic::SultanPlayer.City.CityBuilding.fromJson(json->GetJsonObject("CityBuilding"));
    else
      cocos2d::log("Error Fetching CityBuilding From Server ....");
    auto newScene = CityScene::createScene();
    // cocos2d::Director::getInstance()->popScene();
    cocos2d::Director::getInstance()->pushScene(newScene);
  });
}

void BuildingService::fetchBuildingInfo() {
  NetModule::getJson("/api/Building/fetchBuildingInfo", [](GJson* json) {
    if (json == nullptr) {
      cocos2d::log("Error Null ptr From getBuildingInfo Fetch");
      return;
    }
    // cocos2d::log("Data Fetched %s", json->);
    if (GString(json->GetString("state")) == "ok") {
      GJson* BuildingInfo = json->GetJsonObject("BuildingInfo");
      for (auto it = BuildingInfo->MemberBegin(); it != BuildingInfo->MemberEnd(); ++it) {
        EBuilding l_BuildingType = EBuilding::None;
        if (it->name.IsInt())
          l_BuildingType = static_cast<EBuilding>(it->name.GetInt());
        else if (it->name.IsString())
          l_BuildingType = static_cast<EBuilding>(std::stoi(it->name.GetString()));
        GJson doc;
        GJson* jsonObject = new GJson();
        jsonObject->CopyFrom(it->value, jsonObject->GetAllocator());
        BuildingStatic::BuildingInfo[l_BuildingType] = RBuildingSpecs::fromJson(jsonObject);
      }
      CityLtCtrl::Get()->Init();
    } else
      cocos2d::log("Error Fetching fetchBuildingInfo From Server ....");
  });
}


