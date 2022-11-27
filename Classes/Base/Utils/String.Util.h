#pragma once
#include <string>
#include "Include/IncludeBase.h"

class GStringUtils
{
  public:
    static GVector<GString> Split(GString s, GString delimiter);
    static bool Replace(std::string& str, const std::string& from, const std::string& to);
};