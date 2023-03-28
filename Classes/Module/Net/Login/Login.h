#pragma once 
#include "Base/MVC/IModule.h"
#include "Base/BaseTypeDef.h"
#include "ccUTF8.h"
class Login : public IModule{
  private:
    void Ctor();


  public:
    static Login *Get();
    int32 _IdKingdom;
    GString _ServerName;
    GString _GateIp;
    GString _GatePort;
    Guid _SubId;
    Guid _Uid;
    void InitSocket();
    void ConnectLogin();
    void S2C_AUTH_TOKEN(const char *p_B64Msg);
    void LoginSuccess();
};