#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeGlobal.h"
#include "Include/IncludeBuildingBase.h"
#include "Building.Lib.h"
#include "Building.Static.h"
#include "Base/Containers/Pair.h"

class BuildingLogic{

  struct RWarLvlRet{
    bool _IsWar = false;
    int32 _WarLvl = 0;
    int32 _Progress = 0;
  };

private:
  bool IsBuildingCostAchieved(const RCostBuildingUpgrade &p_CostUpgrade);
public:
  static BuildingLogic *Get();
  GPair<bool, RCostBuildingUpgrade> IsCanUpgrade(EBuildingIndex p_BuildingType, uint32 p_CurentLvl = 0);
  GPair<bool, RCostBuildingUpgrade> IsCanBuild(EBuilding p_BuildingType);
  int32 IsWarLvl(uint32 p_BuildingLvl) { return false; }
  RWarLvlRet IsBuildIDWarLv(EBuilding p_Building, int32 p_BuildingLvl) {return RWarLvlRet();}
  bool IsShowUpgrade(EBuildingIndex p_BuildingIndex){ return true; }
  bool BuildLvIsFull(EBuilding pBuildingID, EBuildingIndex p_BuildingIndex){ return false; }
  ITask *GetQueueType(EBuildingIndex p_BuildingIndex);
  int32 TransFormBuildLvToWarLv(int32 p_BLvl){ return p_BLvl; }
  int32 GetFreeSpeedUpTime(int32 p_Lvl = 0){return 0;}
  RWarLvlRet IsBuildWarLv(int32 p_Lvl){ return RWarLvlRet(); }
  bool IsBuildingUnlock(EBuilding pBuildingID, EBuildingIndex p_BuildingIndex){ return false ;}
  GPair<ETask, GTime> GetIdleBuildQueue();
  EErrDef Build(
    EBuildingIndex p_Index, EOperateMode p_Mode, 
    const RCostBuildingUpgrade &p_Data, EBuilding p_Building){
      return EErrDef::Err_None;
    }
  EErrDef Upgrade(
    EBuildingIndex p_Index, EOperateMode p_Mode, 
    const RCostBuildingUpgrade &p_Data, bool p_IsBuild, EBuilding p_Building){
      return EErrDef::Err_None;
    }
  bool GetOutBuildIsResBuild(EBuilding p_Bid);
};