#include "Server.Proxy.h"
#include "Game.Top.h"
#include "Module/Net/Login/Login.h"
ServerProxy *ServerProxy::Get(){
  static auto l_Inst = new ServerProxy();
  return l_Inst;
}

void ServerProxy::GameEnter(){
  GameTop::Get()->EnterGame(Login::Get()->_Uid, Login::Get()->_IdKingdom);
}