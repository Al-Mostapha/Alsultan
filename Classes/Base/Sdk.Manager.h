#pragma once
#include "Include/IncludeBase.h"

class SDKManager
{
public:
  static SDKManager* Get();
  bool IsSupportReplay();
};