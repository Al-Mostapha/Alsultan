#pragma once

#include "Official.Enum.h"
#include "Base/Type/XVector.h"
#include "Base/BaseTypeDef.h"
#include "Module/Player/Buff/Buff.Enum.h"

struct ROfficialInfo
{
  int32 _Id = 0;
  EShowOfficialType _Type = EShowOfficialType::None;
  EOfficialPersonClass _Class = EOfficialPersonClass::None;
  GString _Name;
  GVector<EBuffID> _Buff;
  GString _Img;
};