#include "Kingdom.Ctrl.h"

KingdomCtrl *KingdomCtrl::Get()
{
  static KingdomCtrl *s_Instance = nullptr;
  if (s_Instance == nullptr)
  {
    s_Instance = new KingdomCtrl();
  }
  return s_Instance;
}

GOpt<RKingdomInfo> KingdomCtrl::IsFoundKingdomID(int32 p_KingdomId)
{
  return RKingdomInfo();
}