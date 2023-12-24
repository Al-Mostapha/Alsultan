#include "JsonFile.Loader.h"
#include "Base/Type/XEvent.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Building/Building.Static.h"


JsonFileLoader *JsonFileLoader::Get(){
  static JsonFileLoader *s_JsonFileLoader = new JsonFileLoader();
  return s_JsonFileLoader;
}

void JsonFileLoader::Init(){
}

void JsonFileLoader::Load(const GFunc<void()> &pCallback){
  LoadCityFiles();
}


void JsonFileLoader::SetFinishCallback(const GFunc<void()> &pCallback){
  _CallBack = pCallback;
}

void JsonFileLoader::LoadCityFiles(){
  NetModule::Get()->GetJsonFile("/Static/Json/City/City.json", [this](auto pJson, auto pReq){
    if(pJson.is_null())
      Logger::Get()->Log("City.json Not loaded");
    Logger::Get()->Log("City.json loaded");
    LoadBuildingFiles();
  });
}

void JsonFileLoader::LoadBuildingFiles(){
  NetModule::Get()->GetJsonFile("/Static/Json/Building/Building.json", [this](auto pJson, auto pReq){
    if(pJson.is_null())
      Logger::Get()->Log("CityBuilding.json Not loaded");
    Logger::Get()->Log("CityBuilding.json loaded");
    BuildingStatic::Get()->GetFromJsonFile(pJson);
    LoadBuildingTipFiles();
  });
}

void JsonFileLoader::LoadBuildingTipFiles(){
  NetModule::Get()->GetJsonFile("/Static/Json/Building/BuildingTips.json", [this](auto pJson, auto pReq){
    if(pJson.is_null())
      Logger::Get()->Log("BuildingTips.json Not loaded");
    Logger::Get()->Log("BuildingTips.json loaded");
    BuildingStatic::Get()->GetTipsFromJsonFile(pJson);
    LoadPlayerFiles();
  });
}

void JsonFileLoader::LoadPlayerFiles(){
  NetModule::Get()->GetJsonFile("/Static/Json/Player/Player.json", [this](auto pJson, auto pReq){
    if(pJson.is_null())
      Logger::Get()->Log("CityBuilding.json Not loaded");
    Logger::Get()->Log("CityBuilding.json loaded");
    XEvent::Get()->Fire(Event_OnJsonFileLoaded);
  });
}
