#pragma once
#include "Include/IncludeBase.h"
#include "Device.Enum.h"

class GDevice{
public: 
  static GDevice *Get();
  EPlatform Platform();
  bool IsIphoneXMode();
  bool IsForTest(){return true;}
  bool Is64Bit(){return true;}
};
