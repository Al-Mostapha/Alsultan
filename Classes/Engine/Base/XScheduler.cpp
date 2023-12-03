#include "XScheduler.h"
#include "Base/BaseTypeDef.h"


XScheduler *XScheduler::Get()
{
  static XScheduler *s_Inst = nullptr;
  if (!s_Inst)
  {
    s_Inst = new XScheduler();
  }
  return s_Inst;
}

int XScheduler::PerformWithDelayGlobal(const std::function<void()> &p_Func, float p_Delay)
{
  return 0;
}

GString XScheduler::ScheduleUpdateGlobal(const std::function<void(float)> &p_Func, int32 p_Priority)
{
  // if priority then
  //   return sharedScheduler:scheduleScriptFuncNew(listener, 0, false, priority)
  // end
  Director::getInstance()->getScheduler()->schedule(p_Func, Director::getInstance()->getRunningScene(), 0, false, "XScheduler::ScheduleUpdateGlobal");
  // return sharedScheduler:scheduleScriptFunc(listener, 0, false)
  return "";
}

GString XScheduler::ScheduleGlobal(const std::function<void(float)> &p_Func, int32 p_Interval, int32 p_Priority){
  // if priority then
  //   return sharedScheduler:scheduleScriptFuncNew(listener, interval, false, priority)
  // end
  // return sharedScheduler:scheduleScriptFunc(listener, interval, false)
  Director::getInstance()->getScheduler()->schedule(p_Func, Director::getInstance()->getRunningScene(), p_Interval, false, "XScheduler::ScheduleUpdateGlobal");
  return "";
}