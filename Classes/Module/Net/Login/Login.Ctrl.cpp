#include "Login.h"
#include "Login.Ctrl.h"
#include "Module/Module.Mgr.h"
#include "Game/Init/Server.Proxy.h"

LoginCtrl *LoginCtrl::Get(){
  static LoginCtrl *l_Inst = nullptr;
  if(l_Inst)
    return l_Inst;

  l_Inst->Ctor();
  return l_Inst;
}

void LoginCtrl::Ctor(){
  Login::Get();
}

void LoginCtrl::ConnectLogin(const GString &p_Host, int32 p_Port){
  Login::Get()->InitSocket();
  Login::Get()->ConnectLogin();
}

void LoginCtrl::LoginSuccess(){
  GModuleMgr::Get()->GetServerProxy()->GameEnter();
}
