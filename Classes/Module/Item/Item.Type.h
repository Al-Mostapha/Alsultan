#pragma once
#include "Include/IncludeBase.h"
#include "Item.Enum.h"

struct RCostItem {
  uint32 idItem = 0;
  uint32 amount = 0;
};

struct RCostItemEnough{
  uint32 idItem     = 0;
  uint32 _CurCount  = 0;
  uint32 _ItemCount  = 0;
  uint32 AmountLack = 0;
  bool _IsReach = false;
};
struct RItemUseCondition{
  EItemUseCondType CType = EItemUseCondType::None;
  uint32 idItem =0; // lvl in case contion is vip
  uint32 count = 0; // need active in case condition is vip
  uint32 getVipLvl(){return idItem;}
  uint32 getneedActive(){return count;}
};
struct RItem{
  uint32 index = 0;
  uint32 idItem;
  EItemType ItemType = EItemType::None; // goodType
  EItemCategory BagType = EItemCategory::Other;
  EItemQuality ItemQuality = EItemQuality::None;
  EBackpackDef backpackType = EBackpackDef::None;
  uint32 uintMax = 99999;
  uint32 useMax = 99999;
  uint32 buyMax = 99999;
  uint32 castleLvl = 0;
  uint32 lordLvl = 0;
  bool isLog = true;
  bool canUse = false;
  bool canPresented = false;
  bool canPresentShow = false;
  uint32 presentLvl = 0;
  EItemEffect ItemEffect = EItemEffect::None;// resultType
  GVector<uint32> EffectList; // result
  RItemUseCondition UseCondition;
  uint32 feedEXP = 1000;
  uint32 advancedEXP = 0;
  uint32 petPoint = 0;
  uint32 skinShow = 1;
  uint32 show = 0;
  uint32 maxControl = 0;
  bool limitedTime = false;
  bool gembox = false;
};