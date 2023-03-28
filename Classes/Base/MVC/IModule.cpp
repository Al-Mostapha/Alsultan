#include "IModule.h"

EventDispatcher* IModule::GetEvD() { return Director::getInstance()->getEventDispatcher(); }

EventListenerCustom* IModule::AddEventListener(const char* eventName, const std::function<void(EventCustom*)>& p_Callback) {
  return GetEvD()->addCustomEventListener(eventName, p_Callback);
}
