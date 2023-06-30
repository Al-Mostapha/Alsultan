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