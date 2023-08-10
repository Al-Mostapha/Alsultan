#pragma once
#include "Base/BaseTypeDef.h"

class HegemonCtrl
{
public:
  static HegemonCtrl *Get();
  bool GetIsSelfHegemon(){
    return true;
  }
};