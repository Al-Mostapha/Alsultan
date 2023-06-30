#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/HashMap.h"
#include "Module/City/City.Type.h"
#include "Module/Effect/Effect.Enum.h"

struct RPlayer
{
    int32 idCurrentCity;
    int32 idPlayer;
    RCity City;
    GHashMap<EEffect, struct TEffect> Effect;
};

struct RLordBaseInfo {
  bool bHasBindAccountReward = false;
  bool bReceiveBindPhone = false;
    // rs.leve = leve
    // rs.physical = physical
    // rs.physicalUpper = physicalUpper
    // rs.exp = exp
    // rs.expUpper = expUpper
    // rs.imageId = imageId
    // rs.avatar = avatar
  GString _NickName ;
    // rs.totalFc = totalFc
    // rs.partition = partition
    // rs.gold = gold
    // rs.isSrcKingWarEnabled = isSrcKingWarEnabled
    // rs.isSrcKingdomWarEnabled = isSrcKingdomWarEnabled
    // rs.hasBindAccountReward = hasBindAccountReward
    // rs.receiveBindPhone = receiveBindPhone
    // rs.isReachFullExp = leve >= levelMax
};

struct RLordInfo
{
  struct {
    int32 sourceKID = 0; // Source Kingdom ID
  } Base;
};
