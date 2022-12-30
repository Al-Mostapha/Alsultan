#pragma once
#include "Include/IncludeBase.h"
#include "Device.Enum.h"
#include "OS.h"

class GDevice{
public: 
  static GDevice *Get();
  void Init();
  EPlatform Platform();
  bool IsIphoneXMode();
  bool IsIpadMode();
  bool IsForTest(){return true;}
  bool Is64Bit(){return true;}
};
