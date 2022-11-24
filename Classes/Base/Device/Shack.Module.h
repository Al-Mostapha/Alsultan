#pragma once
#include "Include/IncludeBase.h"

class ShackModule
{
public: 
  static ShackModule* Get();
  void Init();
  void Unload();
};