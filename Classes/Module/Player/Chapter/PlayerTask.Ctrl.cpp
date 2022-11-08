#include "PlayerTask.Ctrl.h"

PlayerTaskCtrl *PlayerTaskCtrl::Get()
{
  static PlayerTaskCtrl *s_pInstance = new PlayerTaskCtrl();
  return s_pInstance;
}

int32 PlayerTaskCtrl::GetCurChapterID()
{
  return 0;
}