#pragma once
#include "Include/IncludeBase.h"
#include "Army.Enum.h"

class ArmyRead{
public:
  static ArmyRead *Get();
  const char *GetIcon(EArmy p_Army);
  GString GetName(int32 p_IdArmy);
  GString GetName(EArmy p_IdArmy);
};