#pragma once 
#include "Include/IncludeBase.h"

#include "Include/IncludeEngine.h"


class UITimerLabel : public Label
{

private:

public:
  CREATE_FUNC(UITimerLabel);
  UITimerLabel(){};
  ~UITimerLabel(){};
  static UITimerLabel *Create() {
    return create();
  };
  static UITimerLabel *DCreateTimerLabel(Node *pLable);
  void BeginTime(GTime){}
  void RemoveTime();
  void SetTimeLast(std::function<GString(const GString &, GTime)> pHandle){}
  void SetTimeEndListener(std::function<void()> pHandle){}
  void SetTimeUpdateListener(std::function<void(GTime pTime)> pHandle){}
};
