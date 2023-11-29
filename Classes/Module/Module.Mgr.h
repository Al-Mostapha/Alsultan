#pragma once
#include "Base/MVC/IModule.h"
#include "Include/IncludeEngine.h"


class GModuleMgr : public IModule {
  class UserModule *m_User;
  class ServerProxy *m_ServerProxy;
  class GameTop *m_GameTop;
  class XGame *m_XGame;
  public:
  static GModuleMgr* Get();
  UserModule *GetUser() const { return m_User ;};
  ServerProxy *GetServerProxy() const { return m_ServerProxy ;};
  GameTop *GetGameTop() const { return m_GameTop ;};
  void Init();
  void StartGame(){}
};