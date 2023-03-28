#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeGlobal.h"
#include "Task.Enum.h"
#include "ITask.h"


class TaskCtrl{
public:
  static TaskCtrl *Get();
  void IsNeedReqHelp(ETask p_Task){}
  void SpeedUpQueueReq(ETask p_Task, ESpeedType p_SpeedType){}
  ITask *QueryQueue(ETask p_Task){return nullptr;}
};