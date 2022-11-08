#pragma once
#include "Include/IncludeBase.h"
#include "Device.Enum.h"

class GDevice{
public: 
  static GDevice *Get();
  EPlatform Platform();
};
