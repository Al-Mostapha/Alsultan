#pragma once
#include "Include/IncludeBase.h"

class StuffWorkshopCtrl {
public:
  static StuffWorkshopCtrl* Get();
  uint32 GetDoneID();
  void SendGetStuff();
};