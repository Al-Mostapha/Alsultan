#pragma once
#include "Include/IncludeBase.h"
#include "Task.Enum.h"

class ITask{
  public: 
  uint32 idTask;
  ETask TaskType;
  GTime TimeEnd;
  GTime TimeStart;
  GTime TimeEndOrginal;
  GTime GetRemainTime(){
    return TimeEnd - GDateTime::Now();
  }
  ETask GetQueueType(){
    return TaskType;
  }
};