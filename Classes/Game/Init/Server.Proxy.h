#pragma once
#include "Base/MVC/IModule.h"

class ServerProxy : public IModule{
  public:
    static ServerProxy *Get();
    void ConnectServer(){
      GameEnter();
    }
    void GameEnter();
};