#include "Player.Module.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Faction/Faction.Ctrl.h"
#include "Base/Base.Lib.h"

PlayerModule *PlayerModule::Get(){
  static PlayerModule *s_PlayerModule =  new PlayerModule();
  return s_PlayerModule;
}

void PlayerModule::Init(){
}

void PlayerModule::StartGame(){
}

void PlayerModule::Ctor(){
  _CityCtrl = CityCtrl::Get();
  _FactionCtrl = FactionCtrl::Get();
}

void PlayerModule::EnterGame(){
  _CityCtrl->EnterGame();
}

void PlayerModule::InitCtrlData(){
  //   SoraDSendMessage({
  //   msg = "MESSAGE_MAINSCEN_LOGINFINSH"
  // })
  _CityCtrl->InitClientData();
  GBase::DSendMessage("MESSAGE_MAINSCEN_LOGINFINSH");
}

void PlayerModule::InitDelayCtrlData(){
  //   local playerTopModule = include("PlayerTopModule")
  // for k, v in ipairs(playerTopModule.delayInitCall) do
  //   local ctrl = SoraDGetCtrl(v.name)
  //   if ctrl and ctrl.sendReqInitDataMsg then
  //     ctrl:sendReqInitDataMsg()
  //   end
  // end
}