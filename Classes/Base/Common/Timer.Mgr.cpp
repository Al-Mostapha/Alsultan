#include "Timer.Mgr.h"

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
