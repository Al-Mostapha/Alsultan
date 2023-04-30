#pragma once
#include "Base/BaseTypeDef.h"
#include "Task.Enum.h"

class ITask{
  public: 
  uint32 idTask;
  ETask TaskType;
  GTime TimeEnd;
  GTime TimeStart;
  GTime TimeEndOrginal;
  virtual GTime GetRemainTime(){
    return TimeEnd - GDateTime::Now();
  }
  virtual GTime GetTotalTime(){
    return 0;
  }
  virtual ETask GetQueueType(){
    return TaskType;
  }

  template<class T>
  T *As();
};

template <typename T>
inline T* ITask::As()
{
  return dynamic_cast<T*>(this);
}