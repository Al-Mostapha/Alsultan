#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/Pair.h"
#include "Item.Type.h"

class ItemCtrl {
public:
  static bool isEnough(uint32 p_IdItem, uint32 p_Amount);
  static GPair<bool, GVector<RItemIsEnough>> isEnough(GVector<struct RCostItem>& p_CostItem){
    return GPair<bool, GVector<RItemIsEnough>>::Make(true, GVector<RItemIsEnough>());
  };
};