#include "Player.Top.h"

PlayerTop* PlayerTop::Get(){
  static PlayerTop* s_PlayerTop = nullptr;
  if(s_PlayerTop == nullptr){
    s_PlayerTop = new PlayerTop();
    s_PlayerTop->Ctor();
  }
  return s_PlayerTop;
}

void PlayerTop::Ctor(){
  PlayerModule::Ctor();
}

int32 PlayerTop::GetMapID(){
  return 0;
}

Guid PlayerTop::GetPlayerID(){
  return Guid();
}


void PlayerTop::LogOut(){
  
}


void PlayerTop::EnterGame(){
  // local curTime = SoraDGetSocketTime()
  // userSDKManager.timeInfo.t_gamelogin.tend = curTime
  // userSDKManager.timeInfo.t_gamedata.tbegin = curTime
  // serviceFunctions.print("PlayerTop:EnterGame module num=", #self.modules_ord)
  // msgCtrl.clean()
  // for _, modulecell in ipairs(self.modules_ord) do
  //   modulecell:removeAllEventListeners()
  // end
  // msgCtrl.register(gCmd.CMD_LOGIN_DATA_INIT, gCmd.REQ_LOGIN_DATA_INIT, handler(self, self.getLoginDataInitRsp))
  // local serverproxy = gModuleMgr.getObject("serverproxy")
  // local gate = serverproxy.gate_
  // if gate.removeEventListenersByEvent then
  //   gate:removeEventListenersByEvent(gate.GAME_MSG_RESPONSE)
  // elseif gate.removeAllEventListenersForEvent then
  //   gate:removeAllEventListenersForEvent(gate.GAME_MSG_RESPONSE)
  // end
  // gate:addEventListener(gate.GAME_MSG_RESPONSE, handler(self, self.dispatchRsp))
  // local loginDataInitCtrl = self:getModule("loginDataInitCtrl")
  // loginDataInitCtrl:getLoginDataInitReq()
  // self:startTimer()
  //TODO: Bypass 
  GetLoginDataInitRsp();
}

void PlayerTop::GetLoginDataInitRsp(){
  // self.mapID = nil
  // self:moduleLogout()
  // self:MouleEnterGame()
  ModuleEnterGame();
  // gModuleMgr.getObject("gametop"):registerServeStatus()
  // local loginDataInitCtrl = self:getModule("loginDataInitCtrl")
  // loginDataInitCtrl:getLoginDataInitRsp(...)
  
 
}


void PlayerTop::ModuleEnterGame(){
  //   for _, modulecell in ipairs(self.modules_ord) do
  //   modulecell:EnterGame()
  // end
  PlayerModule::EnterGame();
  PlayerModule::InitCtrlData();
  // local linkCtrl = self:getModule("linkCtrl")
  // linkCtrl:addEventListener(linkCtrl.EVENT_HEARTBEAT_TIMEOUT, handler(self, self.onHeartbeatTimeOut))
}