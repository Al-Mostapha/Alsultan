#pragma once
#include "Include/IncludeBase.h"
#include "GuildScience.Enum.h"

class GuildScienceCtrl{
public:
  static GuildScienceCtrl *Get();
public:
  uint32 getSciencePower(EGuildScience p_GuildScience);
};