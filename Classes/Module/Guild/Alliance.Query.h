#pragma once
#include "Base/BaseTypeDef.h"

class AllianceQuery{
  public:
    static AllianceQuery* Get();
    void ReqAllianceInfo(int32 p_KID, Guid p_AllainceID, GString p_From = ""){}
};