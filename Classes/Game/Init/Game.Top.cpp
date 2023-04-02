#include "Game.Top.h"
#include "Module/Module.Mgr.h"
#include "Server.Proxy.h"
#include "Module/Player/Player.Top.h"

GameTop* GameTop::Get() {
  static GameTop* l_Inst = nullptr;
  if (l_Inst) return l_Inst;
  l_Inst = new GameTop();
  l_Inst->Ctor();
  return l_Inst;
}

void GameTop::Ctor() {
  m_ServerProxy = GModuleMgr::Get()->GetServerProxy();
//   m_ServerProxy->AddEventListener("SERVERPROXY_GAME_REJECTED_EVENT", CC_CALLBACK_1(GameTop::Rejected, this));
//   m_ServerProxy->AddEventListener("SERVERPROXY_GAME_ENTERED_EVENT", CC_CALLBACK_1(GameTop::EnterGame, this));
//   m_ServerProxy->AddEventListener("SERVERPROXY_PLAYER_KICKEDOFF_EVENT", CC_CALLBACK_1(GameTop::Disconnected, this));
//   m_ServerProxy->AddEventListener("SERVERPROXY_SERVER_MAINTAINCE_EVENT", CC_CALLBACK_1(GameTop::ServerMaintaince, this));
//   m_ServerProxy->AddEventListener("SERVERPROXY_BE_SEALED_EVENT", CC_CALLBACK_1(GameTop::BeSealed, this));
//   m_ServerProxy->AddEventListener("SERVERPROXY_VERSION_ERROR_EVENT", CC_CALLBACK_1(GameTop::VersionError, this));
}

void GameTop::StartGame(){
  OnGameLogIn();
}

void GameTop::LogOut(){
  if(_PlayerTop)
    _PlayerTop->LogOut();
}

void GameTop::OnGameLogIn(){
  m_ServerProxy->ConnectServer();
}

void GameTop::OnGaming(Guid p_IdPlayer, int32 p_IdKingdom){
  if(!_PlayerTop)
    _PlayerTop = PlayerTop::Get();
  _PlayerTop->AddEventListener("HEARTBEAT_TIMEOUT_EVENT", CC_CALLBACK_1(GameTop::OnHeartbeatTimeOut, this));
  _PlayerTop->SetPlayerID(p_IdPlayer);
  _PlayerTop->SetKingdomID(p_IdKingdom);
  _PlayerTop->EnterGame();
  RegisterServeStatus();
}

void GameTop::RegisterServeStatus(){}

void GameTop::OnHeartbeatTimeOut(EventCustom* p_Event) {

}

void GameTop::Rejected(EventCustom* p_Event) {

}

void GameTop::EnterGame(Guid p_IdPlayer, int32 p_IdKingdom) {
  OnGaming(p_IdPlayer, p_IdKingdom);
}

void GameTop::Disconnected(EventCustom* p_Event) {}

void GameTop::ServerMaintaince(EventCustom* p_Event) {}

void GameTop::BeSealed(EventCustom* p_Event) {}

void GameTop::VersionError(EventCustom* p_Event) {}