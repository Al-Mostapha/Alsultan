#pragma once 
#include "Include/IncludeBase.h"
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
  GPair<bool, RCostBuildingUpgrade> IsCanUpgrade(EBuilding p_BuildingType, uint32 p_CurentLvl);
  GPair<bool, RCostBuildingUpgrade> IsCanBuild(EBuilding p_BuildingType);
  int32 IsWarLvl(uint32 p_BuildingLvl) { return false; }
  RWarLvlRet IsBuildIDWarLv(EBuilding p_Building, int32 p_BuildingLvl) {return RWarLvlRet();}
  bool IsShowUpgrade(EBuildingIndex p_BuildingIndex){ return true; }
  bool BuildLvIsFull(EBuildingIndex p_BuildingIndex){ return false; }
  ITask *GetQueueType(EBuildingIndex p_BuildingIndex);
  int32 TransFormBuildLvToWarLv(int32 p_BLvl){ return p_BLvl; }
};