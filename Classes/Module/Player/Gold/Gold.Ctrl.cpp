#include "Gold.Ctrl.h"
#include "Module/CityResource/Resource.Type.h"
#include "Module/Item/Item.Type.h"
#include "Module/Item/Item.Ctrl.h"
#include "Base/Math/Math.Base.h"

GoldCtrl *GoldCtrl::Get(){
  GoldCtrl *l_Instance = new GoldCtrl();
  return l_Instance;
}

uint32 GoldCtrl::resourceToGold(EResource p_Resource, uint32 p_Amount){
  uint32 l_coefficient = 1;
  if(p_Resource ==  EResource::None)
    return 0;
  if(p_Resource == EResource::Food || p_Resource == EResource::Wood)
    l_coefficient = 1;
  else if(p_Resource == EResource::Iron)
    l_coefficient = 6;
  else if(p_Resource == EResource::Mithril)
    l_coefficient = 25;
  else if(p_Resource == EResource::Crystal || p_Resource == EResource::MeteorCrystal)
    l_coefficient = 100;
  double l_X = 250.0f;
  double l_Y = 610000.0f;
  double l_Compl = 1 - (double)p_Amount / ((double)p_Amount + l_Y);
  if(l_Compl <= 0.55)
    l_Compl = 0.55;
  return std::ceil((double) p_Amount / l_X * l_Compl * l_coefficient + 1);
}

uint32 GoldCtrl::resourceToGold(RCostResourceEnough p_CostResourceNeed){
  uint32 l_ResToGold = 0;
  using namespace GMath;
  l_ResToGold += GoldCtrl::Get()->resourceToGold(EResource::Food          ,Abs(Min(0, p_CostResourceNeed.GrainNeed)));
  l_ResToGold += GoldCtrl::Get()->resourceToGold(EResource::Wood          ,Abs(Min(0, p_CostResourceNeed.LumberNeed)));
  l_ResToGold += GoldCtrl::Get()->resourceToGold(EResource::Iron          ,Abs(Min(0, p_CostResourceNeed.IronNeed)));
  l_ResToGold += GoldCtrl::Get()->resourceToGold(EResource::Mithril       ,Abs(Min(0, p_CostResourceNeed.SilverNeed)));
  l_ResToGold += GoldCtrl::Get()->resourceToGold(EResource::Steel         ,Abs(Min(0, p_CostResourceNeed.MetalNeed)));
  l_ResToGold += GoldCtrl::Get()->resourceToGold(EResource::Crystal       ,Abs(Min(0, p_CostResourceNeed.CrystalNeed)));
  l_ResToGold += GoldCtrl::Get()->resourceToGold(EResource::MeteorCrystal ,Abs(Min(0, p_CostResourceNeed.MeteorCrystalNeed)));
  return l_ResToGold;
}

uint32 GoldCtrl::timeToGold(uint32 p_Time, bool p_IsArmy, bool p_IsAllianceTech ){

  float l_Time = (float) p_Time;
  if(p_Time <= 0)
    return 0;
  float l_X = 22.0f;
  float l_Y = 1750000.0f;
  float l_Compl =  1 - l_Time / (l_Time + l_Y);
  if(l_Compl <= 0.67)
    l_Compl = 0.67f;
  float l_Params = 13;
  if(p_IsArmy)
    l_Params = 0;
  float l_Gold = std::ceil(l_Time / l_X * l_Compl - l_Params);
  if(l_Gold < 1)
    l_Gold = 1;
  if(p_IsAllianceTech){
    l_Gold = std::ceil(l_Gold * 0.25);
    if(l_Gold < 1)
      l_Gold = 1;
  }
  if(!p_IsArmy && l_Gold > l_Time / 3600.0f * 150.0f )
    l_Gold = std::ceil(l_Time / 3600.0f * 150.0f);
  return l_Gold;
}

uint32 GoldCtrl::refineryTimeToGold(uint32 p_Time){
  float l_Gold = 0;
  if(p_Time <= 0)
    return l_Gold;
  float l_MinTime = std::floor(p_Time / 60);
  float l_LeftSec = p_Time - l_MinTime*60;
  if(l_LeftSec > 0 && l_LeftSec < 60)
    l_MinTime += 1;
  if((uint32)l_MinTime % 2 != 0)
    l_MinTime += 1;
  l_Gold = l_MinTime / 2;
  return l_Gold;
}

uint32 GoldCtrl::itemToGold(const GVector<RCostItemEnough>& p_CostItem){
  uint32 l_ItemGold = 0;
  for(auto l_OneCostItem : p_CostItem){
    l_ItemGold += l_OneCostItem.AmountLack * ItemCtrl::Get()->GetItemPrice(l_OneCostItem.idItem);
  }
  return l_ItemGold;
}
