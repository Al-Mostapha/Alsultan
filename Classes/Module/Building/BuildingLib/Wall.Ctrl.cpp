#include "Wall.Ctrl.h"

WallCtrl *WallCtrl::Get()
{
  static WallCtrl *s_WallCtrl =new WallCtrl();
  return s_WallCtrl;
}

bool WallCtrl::IsDestruction()
{
  return false;
}
