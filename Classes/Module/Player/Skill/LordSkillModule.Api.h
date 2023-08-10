#pragma once

#include "Base/BaseTypeDef.h"
#include "LordSkill.Type.h"

class LordSkillModuleAPI
{
  public:
  static LordSkillModuleAPI *Get();
  RSkillCDData GetSkillCDData(int32 pSkillID);
};