#pragma once 
#include "Task.Enum.h"

class ITask;

class WaitQueueCtrl{
  public: 
    static WaitQueueCtrl *Get();
    ITask *GetWaitQueueData(ETask);
};