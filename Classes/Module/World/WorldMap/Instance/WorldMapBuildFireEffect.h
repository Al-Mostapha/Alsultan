#pragma once 
#include "Base/BaseTypeDef.h"
#include "WorldInstance.Enum.h"

class WorldMapBuildFireEffect{
  public:
  GTime _FightTime;
  void ResetFireEffect(){}
  virtual void AddFireEffect(GTime pFightTime){}
  void UpdateFireEffect(EMapObjStateTypeDef pStatus){}
  void RemoveFireEffect(GTime pFightTime){}
  void RemoveHurtDieEffect(GTime pFightTime){}
  void UpdateFightTime(GTime pFightTime){}
};