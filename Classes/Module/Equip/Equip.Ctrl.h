#pragma once 
#include "Include/IncludeBase.h"

class EquipCtrl {
public:
  static EquipCtrl* Get();
  bool IsCanGetEquip();
};