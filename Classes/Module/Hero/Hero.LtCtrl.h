#pragma once
#include "Hero.Enum.h"
#include "Hero.Type.h"
#include "Base/Containers/HashMap.h"

class HeroLtCtrl
{
  public:
    static HeroLtCtrl *Get();
    GHashMap<EHeroClass, $HeroTypeInfo>  _HeroClassesInfo;
    GVector<EHeroID> FilterHeroClass(EHeroClass p_Class, GVector<EHeroID>){
      return GVector<EHeroID>();
    }
};