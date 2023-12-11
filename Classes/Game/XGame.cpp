#include "XGame.h"
#include "Engine/Engine.h"
#include "Base/Type/XEvent.h"
#include "Module/Module.Mgr.h"
#include "Module/Config/Config.module.h"
#include "Module/Net/NetBase.Module.h"
#include "Module/Army/Army.Module.h"
#include "Module/Building/Building.Module.h"
#include "Module/City/City.Module.h"
#include "Module/Equip/Equip.Module.h"
#include "Module/Guild/Alliance.Module.h"
#include "Module/Hero/Hero.Module.h"
#include "Module/Item/Item.Module.h"
#include "Module/Pet/Pet.Module.h"
#include "Module/Science/Science.Module.h"
#include "Module/Task/Task.Module.h"
#include "Module/World/World.Module.h"
#include "Module/Player/Player.Module.h"
#include "Loader/JsonFile.Loader.h"

XGame *XGame::Get()
{
  static XGame *s_XGame =  new XGame();
  return s_XGame;
}

void XGame::Init()
{
  GEngine::Get()->Init();
  XEvent::Get()->Init();
  GConfigModule::init();
  GModuleMgr::Get()->Init();
  NetModule::Get()->Init();
  JsonFileLoader::Get()->Init();

  ArmyModule::Get()->Init();
  BuildingModule::Get()->Init();
  CityModule::Get()->Init();
  EquipModule::Get()->Init();
  AllianceModule::Get()->Init();
  HeroModule::Get()->Init();
  ItemModule::Get()->Init();
  PetModule::Get()->Init();
  ScienceModule::Get()->Init();
  TaskModule::Get()->Init();
  WorldModule::Get()->Init();
  PlayerModule::Get()->Init();
  
  NetModule::Get()->HttpGet("/Api/AGame/GetGameState", [](auto pJson, auto pReq){
    if(pJson.is_null())
      return;
    auto l_State = pJson["State"].get<GString>();
    if(l_State != "Ok"){
      // show error
      Logger::Get()->Log("Error: " + l_State);
      return;
    }

    auto l_GameState = pJson["GameState"].get<GString>();
    if(l_GameState == "Waiting"){
      // show waiting
      Logger::Get()->Log("Waiting");
      return;
    }
    if(l_GameState == "Started"){
      // show started
      Logger::Get()->Log("Started");
      return;
    }
    if(l_GameState == "Finished"){
      // show finished
      Logger::Get()->Log("Finished");
      return;
    }
    XGame::Get()->StartGame();
  });
}

void XGame::StartGame()
{

  GModuleMgr::Get()->StartGame();
  NetModule::Get()->StartGame();
  ArmyModule::Get()->StartGame();
  BuildingModule::Get()->StartGame();
  CityModule::Get()->StartGame();
  EquipModule::Get()->StartGame();
  AllianceModule::Get()->StartGame();
  HeroModule::Get()->StartGame();
  ItemModule::Get()->StartGame();
  PetModule::Get()->StartGame();
  ScienceModule::Get()->StartGame();
  TaskModule::Get()->StartGame();
  WorldModule::Get()->StartGame();
  PlayerModule::Get()->StartGame();

  XEvent::Get()->Fire(Event_OnGameStart);
  JsonFileLoader::Get()->Load();
}