#pragma once
#include "Include/IncludeBase.h"

class ItemRead{
public:
  static ItemRead* Get();
  GString GetName(int32 p_IdItem);
  GString GetBrief(int32 p_IdItem);
  GString GetDes(int32 p_IdItem);
  GString GetIcon(int32 p_IdItem);
};