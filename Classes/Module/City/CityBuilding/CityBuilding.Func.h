#pragma once
#include "Include/IncludeBase.h"

class CityBuildingFunc
{
  public:
  static CityBuildingFunc *Get();
  bool CheckPopUpWindow();
  bool CheckPopUnlockPrinceGift();
  bool CheckPopUpSinbadTreasure();
};