#pragma once
#include "Include/IncludeBase.h"
#include "GuildScience.Enum.h"

class AllianceScienceCtrl{
public:
  static AllianceScienceCtrl *Get();
public:
  uint32 GetSciencePower(EGuildScience p_GuildScience);
};