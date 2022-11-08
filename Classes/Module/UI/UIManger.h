#pragma once
#include "Include/IncludeBase.h"

class UIManger{
public:
  static UIManger *Get();
  void CloseAllUI(){}
};