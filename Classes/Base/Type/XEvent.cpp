#include "XEvent.h"
#include "XEngine.h"

XEvent *XEvent::Get(){
  static XEvent *pInstance = NULL;
  if (pInstance == NULL) {
    pInstance = new XEvent();
  }
  return pInstance;
}

void XEvent::Init(){}

void XEvent::Listen(const char *pEventName, const GFunc<void()> &pCallback){
  Director::getInstance()->getEventDispatcher()->addCustomEventListener(pEventName, [pCallback](auto pEvent){
    pCallback();
  });
}

void XEvent::Fire(const char *pEventName){
  Director::getInstance()->getEventDispatcher()->dispatchCustomEvent(pEventName);
}