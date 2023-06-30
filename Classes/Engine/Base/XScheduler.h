#pragma once
#include <functional>

class XScheduler
{
  public:
    static XScheduler *Get();
    int PerformWithDelayGlobal(const std::function<void()> &p_Func, float p_Delay);
};