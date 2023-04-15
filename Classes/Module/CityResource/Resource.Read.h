#pragma once
#include "Include/IncludeBase.h"
#include "Resource.Enum.h"

class ResourceRead{
public:
  static ResourceRead *Get();
  const char *GetIcon(EResource p_Resource);
  const char *GetIcon(int32 p_Resource);
  const char *GetIcon(const char *p_Resource);
  GString GetName(EResource p_Resource);
  GString GetName(int32 p_Resource);
  GString GetName(const char *p_Resource);
};