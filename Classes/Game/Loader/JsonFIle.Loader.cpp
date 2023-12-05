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

void JsonFileLoader::Load(GFunc<void()> p_Callback){
  LoadCityFiles();
}


void JsonFileLoader::SetFinishCallback(GFunc<void()> p_Callback){
  _CallBack = p_Callback;
}

void JsonFileLoader::LoadCityFiles(){
  NetModule::Get()->GetJsonFile("/City/City.json", [this](auto pJson, auto pReq){
    if(pJson.is_null())
      Logger::Get()->Log("City.json Not loaded");
    Logger::Get()->Log("City.json loaded");
    LoadBuildingFiles();
  });
}

void JsonFileLoader::LoadBuildingFiles(){
  NetModule::Get()->GetJsonFile("/Building/Building.json", [this](auto pJson, auto pReq){
    if(pJson.is_null())
      Logger::Get()->Log("CityBuilding.json Not loaded");
    Logger::Get()->Log("CityBuilding.json loaded");
    BuildingStatic::Get()->GetFromJsonFile(pJson);
    LoadPlayerFiles();
  });
}

void JsonFileLoader::LoadPlayerFiles(){
  NetModule::Get()->GetJsonFile("/Player/Player.json", [this](auto pJson, auto pReq){
    if(pJson.is_null())
      Logger::Get()->Log("CityBuilding.json Not loaded");
    Logger::Get()->Log("CityBuilding.json loaded");
    XEvent::Get()->Fire(Event_OnJsonFileLoaded);
  });
}
