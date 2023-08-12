#pragma once
#include "Official.Type.h"

class OfficialInfoRead
{
  public:
  static OfficialInfoRead *Get();
  GOpt<ROfficialInfo> GetInfoByType(EShowOfficialType pType);
};