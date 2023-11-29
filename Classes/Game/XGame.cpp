#include "XGame.h"
#include "Engine/Engine.h"
#include "Module/Module.Mgr.h"
#include "Module/Config/Config.module.h"
#include "Module/Net/NetBase.Module.h"

XGame *XGame::Get()
{
  static XGame *s_XGame =  new XGame();
  return s_XGame;
}

void XGame::Init()
{
  GEngine::Get()->Init();
  GConfigModule::init();
  GModuleMgr::Get()->Init();
  NetModule::Get()->HttpGet("/AGame/GetGameState", [](auto pJson, auto pReq){
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
}