#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Type.h"
USING_NS_CC;

class WorldMapView;
class UIWorldMapTroopTip;


class IWorldMapComponent
{
  protected:
    WorldMapView *_Target;
    RViewClass _Config;
  public:
    UIWorldMapTroopTip *_CurrentTroopTip;
    template <typename T>
    static T *Create(RViewClass p_Config, WorldMapView *p_Target){
      auto l_Ret = new T();
      l_Ret->_Config = p_Config;
      l_Ret->_Target = p_Target;
      l_Ret->Ctor();
      return l_Ret;
    };
    virtual void Init(){
      ResetData();
    };
    virtual void Relogin(){};
    virtual void OnMessageListener() = 0;
    virtual void DoRequest(){};
    virtual void DClearData(){};
    virtual void ResetData(){};
    void AddEventListener(const char * p_Event, const std::function<void(cocos2d::EventCustom *)> &p_Callback){
      Director::getInstance()->getEventDispatcher()->addCustomEventListener(p_Event, p_Callback);
    }
};