#include "KingdomMap.Ctrl.h"

KingdomMapCtrl *KingdomMapCtrl::Get()
{
  static KingdomMapCtrl *pInstance = new KingdomMapCtrl();
  return pInstance;
}

int32 KingdomMapCtrl::GetHallWarCount()
{
  return 0;
}

void KingdomMapCtrl::ReLoginFinish()
{
}

EKingdomClassType KingdomMapCtrl::GetKingdomClass()
{
  return EKingdomClassType::None;
}