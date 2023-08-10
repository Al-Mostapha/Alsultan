#pragma once
#include "Base/BaseTypeDef.h"


struct RSkillCDData{
    int32 _SkillID = 0;
    float _DefaultCD = 0;
    int32 _CDRemainTime = 0;
    bool _IsOpened = false;
};