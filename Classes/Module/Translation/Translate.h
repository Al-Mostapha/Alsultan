
#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XMap.h"
class Translate
{
private:
  /* data */
public:
  Translate(/* args */);
  ~Translate();
  static GString i18n(const char *key, GMap<GString, GString> p_Replace = GMap<GString, GString>());
};

