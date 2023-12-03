#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XOptional.h"
#include "Module/Player/Official/Official.Enum.h"

class LordOfficialRead
{
  public:
  static LordOfficialRead *Get();
  GOpt<GString> GetOfficialIcon(EShowOfficialType pType, int32 pOfficialId);
};