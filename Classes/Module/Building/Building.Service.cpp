#include "Building.Service.h"
#include "Include/IncludeBuildingFunc.h"
#include "Module/Building/Building.Module.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Player/Player.Static.h"
#include "Scene/CityScene.h"
#include "Module/City/City.Static.h"
#include "Module/City/City.Cell.h"
#include "Module/City/CityBuilding/City.LtCtrl.h"


BuildingService *BuildingService::Get(){
  static BuildingService *instance = nullptr;
  if (instance == nullptr) {
    instance = new BuildingService();
  }
  return instance;
}
void BuildingService::Init(){

}
IRequest *BuildingService::GetBuildingList(int32 pCityId){
  return NetModule::Get()->GetJson(
    "/api/ACityBuilding/GetBuildingList",
    {
      {"CityID", pCityId}
    },
    [pCityId](auto pJson, auto pReq){
      if(pJson.is_null()){
        Logger::Get()->Log("GetBuildingList is null");
        return;
      }
      
      if(!CityStatic::Get()->GetCityList().Contains(pCityId)){
        Logger::Get()->Log("GetBuildingList City is not found");
        return;
      }

      auto lState = pJson.value("State", "");
      if(lState != "Ok"){
        Logger::Get()->Log("GetBuildingList State is not Success");
        return;
      }
      
      auto lBuildingList = pJson.value("BuildingList", XJson::array());
      for(auto lBuilding : lBuildingList){
        BuildingCell lBuildingCell;
        lBuildingCell.FromJson(lBuilding);
        CityStatic::Get()->GetCityList()[pCityId].BuildingList[lBuildingCell.GetBuildingIndex()] = lBuildingCell;
      }
    });
}

void BuildingService::fetchCityBuilding(int32 idCity) {
  // NetModule::getJson("/api/CityBuilding/fetchCityBuilding", [](GJson* json) {
  //   if (json == nullptr) {
  //     cocos2d::log("Error Null ptr From CityBuilding Fitch");
  //     return;
  //   }
  //   // if (GString(json->GetString("state")) == "ok")
  //   //   // PlayerStatic::SultanPlayer.City.CityBuilding.fromJson(json->GetJsonObject("CityBuilding"));
  //   // else
  //   //   cocos2d::log("Error Fetching CityBuilding From Server ....");
  //   // auto newScene = CityScene::createScene();
  //   // cocos2d::Director::getInstance()->popScene();
  //   // cocos2d::Director::getInstance()->pushScene(newScene);
  // });
}

void BuildingService::fetchBuildingInfo() {
  // NetModule::getJson("/api/Building/fetchBuildingInfo", [](GJson* json) {
  //   if (json == nullptr) {
  //     cocos2d::log("Error Null ptr From getBuildingInfo Fetch");
  //     return;
  //   }
  //   // cocos2d::log("Data Fetched %s", json->);
  //   if (GString(json->GetString("state")) == "ok") {
  //     GJson* BuildingInfo = json->GetJsonObject("BuildingInfo");
  //     for (auto it = BuildingInfo->MemberBegin(); it != BuildingInfo->MemberEnd(); ++it) {
  //       EBuilding l_BuildingType = EBuilding::None;
  //       if (it->name.IsInt())
  //         l_BuildingType = static_cast<EBuilding>(it->name.GetInt());
  //       else if (it->name.IsString())
  //         l_BuildingType = static_cast<EBuilding>(std::stoi(it->name.GetString()));
  //       GJson doc;
  //       GJson* jsonObject = new GJson();
  //       jsonObject->CopyFrom(it->value, jsonObject->GetAllocator());
  //       //BuildingStatic::BuildingInfo[l_BuildingType] = RBuildingSpecs::FromJson(jsonObject);
  //     }
  //     CityLtCtrl::Get()->Init();
  //   } else
  //     cocos2d::log("Error Fetching fetchBuildingInfo From Server ....");
  // });
}


