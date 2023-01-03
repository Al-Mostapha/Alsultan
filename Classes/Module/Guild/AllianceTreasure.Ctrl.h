#pragma once
#include "Include/IncludeBase.h"

class AllianceTreasureCtrl
{
  public:
    static AllianceTreasureCtrl *Get();
    int32 GetDigRewardCount();
    int32 GetHelpRewardCount();
};