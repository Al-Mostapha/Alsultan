#pragma once

class PlayerTopModule{
  class CityCtrl *_CityCtrl;
  public: 
    virtual void Ctor();
    virtual void EnterGame();
    void InitCtrlData();
    void InitDelayCtrlData();
};