#pragma once
#include "cocos2d.h"
USING_NS_CC;

class IController {
  public:
  EventListenerCustom* AddEventListener(const char* eventName, const std::function<void(EventCustom*)>& p_Callback) {
    return Director::getInstance()->getEventDispatcher()->addCustomEventListener(eventName, p_Callback);
  }
};
