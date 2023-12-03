#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XEngine.h"



namespace GBase{

  bool DManagerFindTimerByTarget(const GString &p_Id);
  void DManagerRemoveTimerByTarget(const GString &p_Id);
  void DManagerAddTimer(const GString &p_Id);
  int32 DCreateDelayTimer(Node *p_Target, const std::function<void()> &p_Func, float p_Delay);
  GString DCreateTimer(Node* p_Target, ccSchedulerFunc p_SchedulerFunc, bool p_PerFrame = false, int32 p_Priority = 0);
  GString DCreateTimerEx(Node* p_Target, ccSchedulerFunc p_SchedulerFunc, uint32 p_Time = 0);
  void DManagerRemoveTimer(GString P_Timer);
};