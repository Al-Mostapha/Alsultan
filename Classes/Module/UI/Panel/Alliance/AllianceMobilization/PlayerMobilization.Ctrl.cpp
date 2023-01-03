#include "PlayerMobilization.Ctrl.h"

PlayerMobilizationCtrl *PlayerMobilizationCtrl::Get()
{
  static auto s_Instance = new PlayerMobilizationCtrl();
  return s_Instance;
}

int32 PlayerMobilizationCtrl::IsHaveActived()
{
  return 0;
}
