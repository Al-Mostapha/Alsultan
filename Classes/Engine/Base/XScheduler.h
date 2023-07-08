#pragma once
#include "Base/BaseTypeDef.h"
#include <functional>


class XScheduler
{
  public:
    static XScheduler *Get();
    int PerformWithDelayGlobal(const std::function<void()> &p_Func, float p_Delay);
    GString ScheduleUpdateGlobal(const std::function<void(float)> &p_Func, int32 p_Priority);
    GString ScheduleGlobal(const std::function<void(float)> &p_Func, int32 p_Interval, int32 p_Priority);
};