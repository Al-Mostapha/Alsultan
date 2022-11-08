#include "UIManger.h"

UIManger *UIManger::Get()
{
  static UIManger *s_UIManger = new UIManger();
  return s_UIManger;
}