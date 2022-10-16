#pragma once
#include "Include/IncludeBase.h"
#include "Task.Enum.h"

struct ITask{
  uint32 idTask;
  ETask TaskType;
  GTime TimeEnd;
  GTime TimeStart;
  GTime TimeEndOrginal;
  int32 GetRemainTime(){
    return TimeEnd - GDateTime::Now();
  }
};
