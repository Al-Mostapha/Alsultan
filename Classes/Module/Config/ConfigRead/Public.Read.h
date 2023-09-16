#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/CityResource/Resource.Enum.h"

class PublicRead
{
  public:
  static PublicRead *Get();
  GString GetIcon(int32 pResID);
  GString GetIcon(EResource pResID);
};