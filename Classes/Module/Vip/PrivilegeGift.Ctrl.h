#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XVector.h"

class PrivilegeGiftCtrl{
public:
    static PrivilegeGiftCtrl *Get();
    GVector<int32> GetCurCanBuyRechargeID(){
        return {};
    }
    
    GVector<int32> GetCurStarLvCanBuyRechargeID(){
        return {};
    }
    GVector<int32> GetCurWallGiftRechargeID(){
        return {};
    }
};