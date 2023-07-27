#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Containers/HashMap.h" 
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "platform/CCPlatformConfig.h"
#include "Module/World/WorldMap/WorldMap.Type.h"




class WorldMapLodCfg{

private:
  void Init();
  RLodCfg _LodCastle;
  RLodCfg _Lod2;
  RLodCfg _Lod3;
  RLodCfg _Lod456;
  RLodCfg _LodNpc;
  RLodCfg _LodMonster;
  RLodCfg _LodBoss;
  RLodCfg _LodAllianceRes;
  RLodCfg _LodAllianceStrong;
  RLodCfg _LodAlliance;
  RLodCfg _LodSelf;
  RLodCfg _LodNebula;
  RLodCfg _LodNebula4;
public: 
  GVector<RLodCfg> _LodCfgNormal;
  GVector<RLodCfgScale> _LodCfgScaleNormal;
  GVector<RBorderLodScale> _BorderLodScale;
  static WorldMapLodCfg *Get();
  GTuple<int32, int32, int32> GetFogMapScale(float pZoomScale); 
};