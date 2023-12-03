#pragma once
#include "Include/IncludeBase.h"
#include "Base/Type/XVector.h"
#include "Module/Hero/Hero.Enum.h"


class HeroCtrl
{
public: 
  static HeroCtrl *Get();
  int32 GetHeroBottomPointNum();
  GVector<EHeroID> GetHaveHerosListByRule(EHeroSortType){
    return GVector<EHeroID>();
  }
  GVector<EHeroID> GetNoHaveHerosListByRule(){
    return GVector<EHeroID>();
  }
};