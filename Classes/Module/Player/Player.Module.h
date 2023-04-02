#pragma once

class PlayerTopModule{
  public:
  class CityCtrl *_CityCtrl;
  class FactionCtrl *_FactionCtrl;
  public: 
    virtual void Ctor();
    virtual void EnterGame();
    void InitCtrlData();
    void InitDelayCtrlData();
};