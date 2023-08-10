#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Module/World/Kingdom/KingdomMap.Enum.h"
#include "Module/World/Kingdom/Kingdom.Type.h"

class KingdomMapCtrl
{
public: 
  static KingdomMapCtrl *Get();
  int32 GetHallWarCount();
  void ReLoginFinish();
  EKingdomClassType GetKingdomClass();
  void OnSwitchWorldMap(ESwitchWorldMapTypeDef, int32 p_KID){}
  bool ReqIsSafe(){
    return true;
  }

  RFogData GetNormalFogData(){
    RFogData t;
    return t;
  }
  ROtherKingdomInfo GetOtherKingdomInfo(){
    ROtherKingdomInfo t;
    return t;
  }
  bool HasMyQueue(EMapMoveLineServerType, GOpt<EMapMoveLineStatusType>, GOpt<int32>, int32){
    return true;
  }
  bool HasArmyHelpQueue2Player(int32 pPlayerId, EMapMoveLineStatusType){
    return false;
  }
};