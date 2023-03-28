#pragma once
#include "cocos2d.h"
USING_NS_CC;



class IModule{
  public: 
    EventDispatcher *GetEvD();
    EventListenerCustom* AddEventListener(const char* eventName, const std::function<void(EventCustom*)>& callback);
};