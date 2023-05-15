#include "Hero.LtCtrl.h"

HeroLtCtrl *HeroLtCtrl::Get()
{
  static auto s_HeroLtCtrl = new HeroLtCtrl();
  return s_HeroLtCtrl;
}