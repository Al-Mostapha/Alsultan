#pragma once
#include "Include/IncludeBase.h"
#include "Science.Enum.h"

class ScienceRead{
public:
  static ScienceRead *Get();
  const char *GetIcon(EScience p_Science);
  GString GetName(EScience p_Science);
  GString GetName(int32 p_Science);
  bool IsScience(int32 p_Science);
};