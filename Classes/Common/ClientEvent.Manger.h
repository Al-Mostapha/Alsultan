#pragma once
#include "Include/IncludeBase.h"

struct REvent{
  // eventID = v,
  // eventState = state,
  // eventType = 1,
  // eventLeftTime = {timeType = "showTime", timerLast = timerLast},
  // eventName = i18n(eventInfo.name),
  // eventDes = i18n(eventInfo.des),
  // flagIcon = eventInfo.icon,
  // pageBg = eventInfo.image,
  // otherData = {timerLast = timerLast}
};
class ClientEventManger {
public:
  static ClientEventManger *Get();
  GVector<REvent> GetEventStateInfo(int32 p_IdActivity = 0);
};