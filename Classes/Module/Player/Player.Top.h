#pragma once
#include "Base/MVC/IModule.h"
#include "Include/IncludeBase.h"
#include "Player.Module.h"


class PlayerTop : public IModule , public PlayerTopModule{
  Guid m_IdPlayer;
  int32 m_IdKingdom;
  public:
  static PlayerTop* Get();
  void Ctor() override;
  void LogOut();
  int32 GetMapID();
  Guid GetPlayerID();
  void SetPlayerID(Guid p_IdPlayer) { m_IdPlayer = p_IdPlayer; }
  void SetKingdomID(int32 p_IdKingdom) { m_IdKingdom = p_IdKingdom; }

  void EnterGame() override;
  void GetLoginDataInitRsp();
  void ModuleEnterGame();
};