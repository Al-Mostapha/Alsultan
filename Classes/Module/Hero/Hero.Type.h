#pragma once
#include "Hero.Enum.h"
#include "Base/BaseTypeDef.h"
#include "Base/Type/XVector.h"


struct $HeroTypeInfo
{
  int32 id;
  EHeroClass HeroType;
  GString TypeName;
  GString Icon;
  GString CardIcon;
};
