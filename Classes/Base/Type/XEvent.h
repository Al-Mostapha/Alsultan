#pragma once
#include "XFunction.h"

#define Event_OnLoginSuccess "OnLoginSuccess"
#define Event_OnLoginFail "OnLoginFail"
#define Event_OnLoginOut "OnLoginOut"
#define Event_OnLoginCancel "OnLoginCancel"
#define Event_OnLoginError "OnLoginError"
#define Event_OnLoginTimeout "OnLoginTimeout"
#define Event_OnLoginInvalid "OnLoginInvalid"

#define Event_OnLoadStart "OnLoadStart"
#define Event_OnLoadSuccess "OnLoadSuccess"
#define Event_OnLoadFail "OnLoadFail"
#define Event_OnLoadCancel "OnLoadCancel"
#define Event_OnLoadError "OnLoadError"
#define Event_OnLoadTimeout "OnLoadTimeout"
#define Event_OnLoadInvalid "OnLoadInvalid"

#define Event_OnGameStart "OnGameStart"
#define Event_OnGameStated "OnGameStated"


#define Event_OnJsonFileLoaded "OnJsonFileLoaded"

class XEvent {
public:
  static XEvent *Get();
  void Init();
  void Listen(const char *pEventName, const GFunc<void()> &pCallback);
  void Fire(const char *pEventName);
};