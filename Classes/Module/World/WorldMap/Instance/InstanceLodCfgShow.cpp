#include "InstanceLodCfgShow.h"

InstanceLodCfgShow *InstanceLodCfgShow::Get()
{
  static InstanceLodCfgShow *sInstanceLodCfgShow = nullptr;
  if (!sInstanceLodCfgShow)
    sInstanceLodCfgShow = new InstanceLodCfgShow();
  return sInstanceLodCfgShow;
}