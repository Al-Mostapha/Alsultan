#pragma once
#include "Include/IncludeBase.h"
#include "Module/CityResource/Resource.Enum.h"

class GoldCtrl {
  public:
  static GoldCtrl* Get();
  uint32 resourceToGold(EResource p_Resource, uint32 p_amount);
  uint32 resourceToGold(struct RCostResourceEnough p_CostResourceNeed);
  uint32 timeToGold(uint32 p_Time, bool p_IsArmy = false, bool p_IsAllianceTech = false);
  uint32 refineryTimeToGold(uint32 p_Time);
  uint32 itemToGold(const GVector<struct RCostItemEnough>& p_CostItem);
};