#include "InstanceCach.Mgr.h"

InstanceCachManger *InstanceCachManger::Get()
{
  static InstanceCachManger *s_InstanceCachMgr = new InstanceCachManger();
  return s_InstanceCachMgr;
}

void InstanceCachManger::ClearCache()
{
  // Do something
}