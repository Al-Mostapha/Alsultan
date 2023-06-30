#include "XScheduler.h"
#include "Base/BaseTypeDef.h"

USING_NS_CC;

XScheduler *XScheduler::Get()
{
  static XScheduler *s_Inst = nullptr;
  if (!s_Inst)
  {
    s_Inst = new XScheduler();
  }
  return s_Inst;
}

int XScheduler::PerformWithDelayGlobal(const std::function<void()> &p_Func, float p_Delay)
{
  return 0;
}