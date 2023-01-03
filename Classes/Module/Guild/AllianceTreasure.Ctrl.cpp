#include "AllianceTreasure.Ctrl.h"

AllianceTreasureCtrl *AllianceTreasureCtrl::Get()
{
  static AllianceTreasureCtrl *s_pInstance = new AllianceTreasureCtrl();
  return s_pInstance;
}

int32 AllianceTreasureCtrl::GetDigRewardCount()
{
  return 0;
}

int32 AllianceTreasureCtrl::GetHelpRewardCount()
{
  return 0;
}