#pragma once
#include "Base/BaseTypeDef.h"

USING_NS_CC;

class WorldMapView;

class IWorldMapCompnant
{
  protected:
    WorldMapView *_Target;
  public:
    virtual void Init() = 0;
    virtual void Relogin(){};
    virtual void OnMessageListener() = 0;
    virtual void DoRequest(){};
    virtual void DClearData(){};
    void AddEventListener(const char * p_Event, const std::function<void(cocos2d::EventCustom *)> &p_Callback){
      Director::getInstance()->getEventDispatcher()->addCustomEventListener(p_Event, p_Callback);
    }
};