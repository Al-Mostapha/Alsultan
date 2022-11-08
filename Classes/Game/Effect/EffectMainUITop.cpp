#include "EffectMainUITop.h"


EffectMainUITop *EffectMainUITop::Get()
{
  static EffectMainUITop *pEffectMainUITop = nullptr;
  if (pEffectMainUITop == nullptr)
  {
    pEffectMainUITop = new EffectMainUITop();
  }
  return pEffectMainUITop;
}

void EffectMainUITop::LordSkillTransresEffect(){
  
}