#pragma once
#include "Include/IncludeBase.h"

class KingdomMapCtrl
{
public: 
  static KingdomMapCtrl *Get();
  int32 GetHallWarCount();
  void ReLoginFinish();
};