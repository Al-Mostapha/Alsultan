#pragma once
#include "Include/IncludeBase.h"
#include "Army.Enum.h"
#include "Module/Building/Building.Enum.h"

class ArmyCtrl { 
public: 
  struct RSingleAddInfo{
    int32 _ItemID = 0;
    int32 _ItemCount = 0;
    int32 _AddCount = 0;
  };
  static ArmyCtrl* Get(); 
  EArmy GetTrainArmy(EBuilding p_Building);
  GTime GetHostpitalPyramidWarCDQueueTime();
  void GetTrainArmyReq(EBuilding p_Building);
  bool IsCanWearWarframe(EArmy p_Army){ return true;}
  bool IsCanPromote(EArmy p_Army){ return true;}

  RSingleAddInfo GetSingleAddInfo(){
    RSingleAddInfo _SingleAddInfo;
    return _SingleAddInfo;
  };

  int32 GetArmyCount(EArmy p_Army, EArmyOpType p_CountType,
    EKingdomClassType p_WarType = EKingdomClassType::None){ return 100; };
  void TrainArmyReq(EBuildingIndex p_Index, EArmy p_Army, int32 p_Count, EOperateMode p_Mode){}
  GHashMap<EArmyType,  GPair<int32, EArmy>> GetWarframeInfo(EBuilding){ 
    auto l_Pair = GPair<int32, EArmy>(1, EArmy::Archer_Bowman);
    GHashMap<EArmyType,  GPair<int32, EArmy>> l_Map;
    l_Map.insert({EArmyType::archer, l_Pair});
    return l_Map; 
  }
};