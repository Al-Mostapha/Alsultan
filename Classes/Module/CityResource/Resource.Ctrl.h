#pragma once
#include "Include/IncludeBase.h"
#include "Resource.Type.h"
#include "Base/Containers/Pair.h"
class ResourceCtrl{
public:
  static ResourceCtrl *Get();
  GPair<bool, RCostResourceEnough> IsEnough(RResource& p_Resource);
};