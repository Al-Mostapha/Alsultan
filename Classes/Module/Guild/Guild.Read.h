#pragma once
#include "Include/IncludeBase.h"
#include "Science/GuildScience.Enum.h"

class GuildRead{
public:
  static GuildRead *Get();
  bool IsScience(int32 p_Science);
  GString GetScienceName(EGuildScience p_GuildScience);
  GString GetScienceName(int32 p_GuildScience);
  GString GetLanguageName(int32  p_LangName);
};