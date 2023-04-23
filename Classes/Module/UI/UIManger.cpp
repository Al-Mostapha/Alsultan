#include "UIManger.h"
#include "Scene/CityScene.h"
#include "FairyGUI.h"


UIManger *UIManger::Get()
{
  static UIManger *s_UIManger = new UIManger();
  return s_UIManger;
}

