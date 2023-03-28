#include "Module.Mgr.h"
#include "Game/Init/Game.Top.h"
#include "Game/Init/Server.Proxy.h"
#include "Game/Init/User.h"
#include "Player/Player.Top.h"


GModuleMgr* GModuleMgr::Get() {
  static auto l_Inst = new GModuleMgr();
  return l_Inst;
}

void GModuleMgr::Init() {
  m_User = UserModule::Get();
  m_ServerProxy = ServerProxy::Get();
  m_GameTop = GameTop::Get();
  // if not gModuleMgr.getObject("timerList") then
  //   local timerlist = include("timerList").new({id = "timerList"})
  //   gModuleMgr.setObject("timerList", timerlist)
  // end
  // if not gModuleMgr.getObject("permissionCtrl") then
  //   local permissionCtrl = include("permissionCtrl").new({
  //     id = "permissionCtrl"
  //   })
  //   gModuleMgr.setObject("permissionCtrl", permissionCtrl)
  // end
}