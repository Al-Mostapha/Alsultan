#include "WaitQueue.Ctrl.h"
#include "ITask.h"

WaitQueueCtrl *WaitQueueCtrl::Get()
{
  static WaitQueueCtrl *l_Inst = new WaitQueueCtrl();
  return l_Inst;
}

ITask *WaitQueueCtrl::GetWaitQueueData(ETask p_Task)
{
  static ITask *l_Task = new ITask();
  return l_Task;
}

bool WaitQueueCtrl::CheckIsWaiting(ETask, EScience){
  return true;
}