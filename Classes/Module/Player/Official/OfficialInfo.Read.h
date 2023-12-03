#pragma once
#include "Official.Type.h"
#include "Base/Type/XOptional.h"

class OfficialInfoRead
{
  public:
  static OfficialInfoRead *Get();
  GOpt<ROfficialInfo> GetInfoByType(EShowOfficialType pType);
};