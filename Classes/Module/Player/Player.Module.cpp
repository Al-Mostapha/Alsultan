#include "Player.Module.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Faction/Faction.Ctrl.h"
#include "Base/Base.Lib.h"

void PlayerTopModule::Ctor(){
  _CityCtrl = CityCtrl::Get();
  _FactionCtrl = FactionCtrl::Get();
}

void PlayerTopModule::EnterGame(){
  _CityCtrl->EnterGame();
}

void PlayerTopModule::InitCtrlData(){
  //   SoraDSendMessage({
  //   msg = "MESSAGE_MAINSCEN_LOGINFINSH"
  // })
  _CityCtrl->InitClientData();
  GBase::DSendMessage("MESSAGE_MAINSCEN_LOGINFINSH");
}

void PlayerTopModule::InitDelayCtrlData(){
  //   local playerTopModule = include("PlayerTopModule")
  // for k, v in ipairs(playerTopModule.delayInitCall) do
  //   local ctrl = SoraDGetCtrl(v.name)
  //   if ctrl and ctrl.sendReqInitDataMsg then
  //     ctrl:sendReqInitDataMsg()
  //   end
  // end
}