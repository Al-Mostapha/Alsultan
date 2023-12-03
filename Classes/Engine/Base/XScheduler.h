#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XEngine.h"
#include "Base/Type/XFunction.h"


class XScheduler
{
  public:
    static XScheduler *Get();
    int PerformWithDelayGlobal(const GFunc<void()> &p_Func, float p_Delay);
    GString ScheduleUpdateGlobal(const GFunc<void(float)> &p_Func, int32 p_Priority);
    GString ScheduleGlobal(const GFunc<void(float)> &p_Func, int32 p_Interval, int32 p_Priority);
};