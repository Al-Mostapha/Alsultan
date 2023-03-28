#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/MVC/IController.h"

class LoginCtrl : public IController {
  public:
  static LoginCtrl *Get();
  void Ctor();

  void ConnectLogin(const GString &p_Host, int32 p_Port);
  void LoginSuccess();
};
