#pragma once 
#include "Task.Enum.h"
#include "Module/Science/Science.Enum.h"

class ITask;

class WaitQueueCtrl{
  public: 
    static WaitQueueCtrl *Get();
    ITask *GetWaitQueueData(ETask);
    bool CheckIsWaiting(ETask, EScience);
};