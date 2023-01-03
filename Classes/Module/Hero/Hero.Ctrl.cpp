#include "Hero.Ctrl.h"

HeroCtrl *HeroCtrl::Get()
{
  static HeroCtrl *s_HeroCtrl = new HeroCtrl();
  return s_HeroCtrl;
}

int32 HeroCtrl::GetHeroBottomPointNum()
{
  return 0;
}