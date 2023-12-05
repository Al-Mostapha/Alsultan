#pragma once

class PlayerModule{
  public:
  class CityCtrl *_CityCtrl;
  class FactionCtrl *_FactionCtrl;
  public: 
    static PlayerModule *Get();
    void Init();
    void StartGame();
    virtual void Ctor();
    virtual void EnterGame();
    void InitCtrlData();
    void InitDelayCtrlData();
    
};