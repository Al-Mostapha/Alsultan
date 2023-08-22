#pragma once
#include "Base/BaseTypeDef.h"
#include "AlliancePet.Enum.h"

class AlliancePetCtrl{
  public:
    static AlliancePetCtrl *Get();
    EAlliancePetState GetAlliancePetState();
};