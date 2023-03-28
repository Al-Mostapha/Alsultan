#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/MVC/IModule.h"


class GameTop : public IModule {
  class ServerProxy* m_ServerProxy;
  class PlayerTop* m_PlayerTop;

  public:
  static GameTop* Get();
  void Ctor();
  void StartGame();
  void LogOut();
  void OnGameLogIn();

  void RegisterServeStatus();

  void OnGaming(Guid p_IdPlayer, int32 p_KingdomId);
  void Rejected(EventCustom* p_Event);
  void EnterGame(Guid p_IdPlayer, int32 p_KingdomId);
  void Disconnected(EventCustom* p_Event);
  void ServerMaintaince(EventCustom* p_Event);
  void BeSealed(EventCustom* p_Event);
  void VersionError(EventCustom* p_Event);
  void OnHeartbeatTimeOut(EventCustom* p_Event);
};