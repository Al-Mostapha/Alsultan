#pragma once
#include <string>
#include "Include/IncludeBase.h"

class GStringUtils
{
  public:
    static GVector<GString> Split(GString s, GString delimiter);
};