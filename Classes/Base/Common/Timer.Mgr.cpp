#include "Timer.Mgr.h"
#include "Engine/Base/XScheduler.h"

bool GBase::DManagerFindTimerByTarget(const GString &p_Target){
  // function SoraDManagerFindTimerByTarget(target)
  //   local ret = false
  //   local timerArray = SoraDTimerManager[target]
  //   if timerArray then
  //     ret = next(timerArray)
  //   end
  //   return ret
  // end
  return false;
}

void GBase::DManagerRemoveTimerByTarget(const Node *p_Target){
 // convert Node * to string and call 
  DManagerRemoveTimerByTarget("");
}

void GBase::DManagerRemoveTimerByTarget(const GString &p_Target){
  // local timerArray = SoraDTimerManager[target]
  // if timerArray then
  //   for k, v in pairs(timerArray) do
  //     schedulerTime.unscheduleGlobal(v)
  //     v = nil
  //   end
  // end
  // SoraDTimerManager[target] = nil
}

void GBase::DManagerAddTimer(const GString &p_Id){
  // local timerArray = SoraDTimerManager[target]
  // if timerArray == nil then
  //   timerArray = {}
  //   SoraDTimerManager[target] = timerArray
  // end
  // timerArray[#timerArray + 1] = timer
}



int32 GBase::DCreateDelayTimer(Node *p_Target, const std::function<void()> &p_Func, float p_Delay){
  // local timeHandle = schedulerTime.performWithDelayGlobal(function()
  //   timeCall()
  // end, delay)
  // SoraDManagerAddTimer(target, timeHandle)
  // return timeHandle
  return 0;
}

GString GBase::DCreateTimer(Node* p_Target, ccSchedulerFunc p_SchedulerFunc, bool p_PerFrame, int32 p_Priority){
  GString p_TimeHandle;
  if(p_PerFrame == true){
    p_TimeHandle = XScheduler::Get()->ScheduleUpdateGlobal(p_SchedulerFunc, p_Priority);
  }else{
    p_TimeHandle = XScheduler::Get()->ScheduleGlobal(p_SchedulerFunc, 1, p_Priority);
  }
  DManagerAddTimer(p_TimeHandle);
  return p_TimeHandle;
}

GString GBase::DCreateTimerEx(Node* p_Target, ccSchedulerFunc p_SchedulerFunc, uint32 p_Time){
  return "";
}


void GBase::DManagerRemoveTimer(GString P_Timer) {}