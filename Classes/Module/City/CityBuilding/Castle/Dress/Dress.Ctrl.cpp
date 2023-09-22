#include "Dress.Ctrl.h"

DressCtrl* DressCtrl::Get()
{
  static DressCtrl* instance = nullptr;
  if (instance == nullptr)
  {
    instance = new DressCtrl();
  }
  return instance;
}

int32 DressCtrl::GetCurDressID(EDressType type)
{
  return 9002100;
}