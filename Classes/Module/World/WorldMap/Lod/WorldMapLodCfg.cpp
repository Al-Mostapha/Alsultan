#include "WorldMapLodCfg.h"
#include "Base/Math/Math.Base.h".
#include "Module/World/WorldMap/Instance/WorldInstance.Enum.h"

WorldMapLodCfg *WorldMapLodCfg::Get()
{
  static WorldMapLodCfg * s_WorldMapLodCfg = nullptr;
  if(s_WorldMapLodCfg == nullptr){
    s_WorldMapLodCfg = new WorldMapLodCfg();
    s_WorldMapLodCfg->Init();
  }
  return s_WorldMapLodCfg;
}

void WorldMapLodCfg::Init()
{
  _LodCastle._Component = "worldMapComInstanceLod";
  _LodCastle._Name = "worldMapComInstanceLodCastle";
  _LodCastle._Param._LodLayer = ELodLayer::CASTLE;
  _LodCastle._Param._Layer = "castle";
  _LodCastle._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 2;
  _LodCastle._Param._MaxInstanceDel = MAX_DELINSTANCE * 2;
  _LodCastle._Param._CheckVisible = true;
  _LodCastle._Param._Default = EWorldLodDef::LOD2;
  _LodCastle._Param._Pre[EWorldLodDef::LOD1] = true;
  _LodCastle._Param._Focus[EWorldLodDef::LOD2] = true;
  _LodCastle._Param._Focus[EWorldLodDef::LOD3] = true;
  _LodCastle._Param._Focus[EWorldLodDef::LOD4] = true;
  _LodCastle._Param._Focus[EWorldLodDef::LOD5] = true;
  _LodCastle._Param._Focus[EWorldLodDef::LOD6] = true;

  _Lod2._Component = "worldMapComInstanceLod";
  _Lod2._Name = "worldMapComInstanceLod2";
  _Lod2._Param._MaxInstanceShow = GMath::Floor(MAX_SHOWINSTANCE * 1.5);
  _Lod2._Param._MaxInstanceDel = GMath::Floor(MAX_DELINSTANCE * 1.5);
  _Lod2._Param._Default = EWorldLodDef::LOD2;
  _Lod2._Param._Pre[EWorldLodDef::LOD1] = true;
  _Lod2._Param._Focus[EWorldLodDef::LOD2] = true;
  _Lod2._Param._Keep[EWorldLodDef::LOD3] = true;
  _Lod2._Param._Keep[EWorldLodDef::LOD4] = true;

  _Lod3._Component = "worldMapComInstanceLod";
  _Lod3._Name = "worldMapComInstanceLod3";
  _Lod3._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 2;
  _Lod3._Param._MaxInstanceDel = MAX_DELINSTANCE * 2;
  _Lod3._Param._Default = EWorldLodDef::LOD3;
  _Lod3._Param._Pre[EWorldLodDef::LOD2] = true;
  _Lod3._Param._Focus[EWorldLodDef::LOD3] = true;
  _Lod3._Param._Keep[EWorldLodDef::LOD4] = true;

  _Lod456._Component = "worldMapComInstanceLod";
  _Lod456._Name = "worldMapComInstanceLod456";
  _Lod456._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 4;
  _Lod456._Param._MaxInstanceDel = MAX_DELINSTANCE * 4;
  _Lod456._Param._Default = EWorldLodDef::LOD4;
  _Lod456._Param._Pre[EWorldLodDef::LOD3] = true;
  _Lod456._Param._Focus[EWorldLodDef::LOD4] = true;
  _Lod456._Param._Focus[EWorldLodDef::LOD5] = true;
  _Lod456._Param._Focus[EWorldLodDef::LOD6] = true;
    
  _LodNpc._Component = "worldMapComInstanceLod";
  _LodNpc._Name = "worldMapComInstanceLodNpc";
  _LodNpc._Param._LodLayer = ELodLayer::NPC;
  _LodNpc._Param._Layer = "npc";
  _LodNpc._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 2;
  _LodNpc._Param._MaxInstanceDel = MAX_DELINSTANCE * 2;
  _LodNpc._Param._Default = EWorldLodDef::LOD2;
  _LodNpc._Param._CheckVisible = true;
  _LodNpc._Param._Pre[EWorldLodDef::LOD1] = true;
  _LodNpc._Param._Focus[EWorldLodDef::LOD2] = true;
  _LodNpc._Param._Focus[EWorldLodDef::LOD3] = true;
  _LodNpc._Param._Focus[EWorldLodDef::LOD4] = true;
  _LodNpc._Param._Keep[EWorldLodDef::LOD5] = true;
  _LodNpc._Param._Keep[EWorldLodDef::LOD6] = true;

  _LodMonster._Component = "worldMapComInstanceLod";
  _LodMonster._Name = "worldMapComInstanceLodMonster";
  _LodMonster._Param._LodLayer = ELodLayer::MONSTER;
  _LodMonster._Param._Layer = "monster";
  _LodMonster._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 2;
  _LodMonster._Param._MaxInstanceDel = MAX_DELINSTANCE * 2;
  _LodMonster._Param._Default = EWorldLodDef::LOD2;
  _LodMonster._Param._Pre[EWorldLodDef::LOD1] = true;
  _LodMonster._Param._Focus[EWorldLodDef::LOD2] = true;
  _LodMonster._Param._Keep[EWorldLodDef::LOD3] = true;
  _LodMonster._Param._Keep[EWorldLodDef::LOD4] = true;
  _LodMonster._Param._Keep[EWorldLodDef::LOD5] = true;
  _LodMonster._Param._Keep[EWorldLodDef::LOD6] = true;

  _LodBoss._Component = "worldMapComInstanceLod";
  _LodBoss._Name = "worldMapComInstanceLodBoss";
  _LodBoss._Param._LodLayer = ELodLayer::BOSS;
  _LodBoss._Param._Layer = "boss";
  _LodBoss._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 3;
  _LodBoss._Param._MaxInstanceDel = MAX_DELINSTANCE * 3;
  _LodBoss._Param._Default = EWorldLodDef::LOD2;
  _LodBoss._Param._Pre[EWorldLodDef::LOD1] = true;
  _LodBoss._Param._Focus[EWorldLodDef::LOD2] = true;
  _LodBoss._Param._Focus[EWorldLodDef::LOD3] = true;
  _LodBoss._Param._Focus[EWorldLodDef::LOD4] = true;
  _LodBoss._Param._Keep[EWorldLodDef::LOD5] = true;
  _LodBoss._Param._Keep[EWorldLodDef::LOD6] = true;
  
  _LodAllianceRes._Component = "worldMapComInstanceLod";
  _LodAllianceRes._Name = "worldMapComInstanceLodAllianceRes";
  _LodAllianceRes._Param._LodLayer = ELodLayer::ALLIANCERES;
  _LodAllianceRes._Param._Layer = "allianceres";
  _LodAllianceRes._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 2;
  _LodAllianceRes._Param._MaxInstanceDel = MAX_DELINSTANCE * 2;
  _LodAllianceRes._Param._Default = EWorldLodDef::LOD2;
  _LodAllianceRes._Param._Pre[EWorldLodDef::LOD1] = true;
  _LodAllianceRes._Param._Focus[EWorldLodDef::LOD2] = true;
  _LodAllianceRes._Param._Focus[EWorldLodDef::LOD3] = true;
  _LodAllianceRes._Param._Focus[EWorldLodDef::LOD4] = true;
  _LodAllianceRes._Param._Keep[EWorldLodDef::LOD5] = true;
  _LodAllianceRes._Param._Keep[EWorldLodDef::LOD6] = true;

  _LodAllianceStrong._Component = "worldMapComInstanceLod";
  _LodAllianceStrong._Name = "worldMapComInstanceLodAllianceStrong";
  _LodAllianceStrong._Param._LodLayer = ELodLayer::ALLIANCESTRONG;
  _LodAllianceStrong._Param._Layer = "alliancestrong";
  _LodAllianceStrong._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 3;
  _LodAllianceStrong._Param._MaxInstanceDel = MAX_DELINSTANCE * 3;
  _LodAllianceStrong._Param._Default = EWorldLodDef::LOD2;
  _LodAllianceStrong._Param._Pre[EWorldLodDef::LOD1] = true;
  _LodAllianceStrong._Param._Focus[EWorldLodDef::LOD2] = true;
  _LodAllianceStrong._Param._Focus[EWorldLodDef::LOD3] = true;
  _LodAllianceStrong._Param._Focus[EWorldLodDef::LOD4] = true;
  _LodAllianceStrong._Param._Focus[EWorldLodDef::LOD5] = true;
  _LodAllianceStrong._Param._Keep[EWorldLodDef::LOD6] = true;
  
  _LodAlliance._Component = "worldMapComInstanceLodAlliance";
  _LodAlliance._Name = "worldMapComInstanceLodAlliance";
  _LodAlliance._Param._LodLayer = ELodLayer::ALLIANCE;
  _LodAlliance._Param._Layer = "alliance";
  _LodAlliance._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 3;
  _LodAlliance._Param._MaxInstanceDel = MAX_DELINSTANCE * 3;
  _LodAlliance._Param._Default = EWorldLodDef::LOD4;
  _LodAlliance._Param._Pre[EWorldLodDef::LOD3] = true;
  _LodAlliance._Param._Focus[EWorldLodDef::LOD4] = true;
  _LodAlliance._Param._Focus[EWorldLodDef::LOD5] = true;
  _LodAlliance._Param._Focus[EWorldLodDef::LOD6] = true;

  _LodSelf._Component = "worldMapComInstanceLod";
  _LodSelf._Name = "worldMapComInstanceLodSelf";
  _LodSelf._Param._LodLayer = ELodLayer::SELF;
  _LodSelf._Param._Layer = "buildself";
  _LodSelf._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 3;
  _LodSelf._Param._MaxInstanceDel = MAX_DELINSTANCE * 3;
  _LodSelf._Param._Default = EWorldLodDef::LOD3;
  _LodSelf._Param._Pre[EWorldLodDef::LOD2] = true;
  _LodSelf._Param._Focus[EWorldLodDef::LOD3] = true;
  _LodSelf._Param._Focus[EWorldLodDef::LOD4] = true;
  _LodSelf._Param._Focus[EWorldLodDef::LOD5] = true;
  _LodSelf._Param._Focus[EWorldLodDef::LOD6] = true;

  _LodNebula._Component = "worldMapComInstanceLod";
  _LodNebula._Name = "worldMapComInstanceNebula";
  _LodNebula._Param._LodLayer = ELodLayer::NEBULA;
  _LodNebula._Param._Layer = "nebula";
  _LodNebula._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 2;
  _LodNebula._Param._MaxInstanceDel = MAX_DELINSTANCE * 2;
  _LodNebula._Param._Default = EWorldLodDef::LOD2;
  _LodNebula._Param._Pre[EWorldLodDef::LOD1] = true;
  _LodNebula._Param._Focus[EWorldLodDef::LOD2] = true;
  _LodNebula._Param._Focus[EWorldLodDef::LOD3] = true;
  _LodNebula._Param._Keep[EWorldLodDef::LOD4] = true;
  
  _LodNebula4._Component = "worldMapComInstanceLod";
  _LodNebula4._Name = "worldMapComInstanceNebula4";
  _LodNebula4._Param._LodLayer = ELodLayer::NEBULA_4;
  _LodNebula4._Param._Layer = "nebula4";
  _LodNebula4._Param._MaxInstanceShow = MAX_SHOWINSTANCE * 2;
  _LodNebula4._Param._MaxInstanceDel = MAX_DELINSTANCE * 2;
  _LodNebula4._Param._Default = EWorldLodDef::LOD4;
  _LodNebula4._Param._Pre[EWorldLodDef::LOD3] = true;
  _LodNebula4._Param._Focus[EWorldLodDef::LOD4] = true;

  _LodCfgNormal.push_back(_LodCastle);
  _LodCfgNormal.push_back(_Lod2);
  _LodCfgNormal.push_back(_Lod3);
  _LodCfgNormal.push_back(_Lod456);
  _LodCfgNormal.push_back(_LodNpc);
  _LodCfgNormal.push_back(_LodMonster);
  _LodCfgNormal.push_back(_LodBoss);
  _LodCfgNormal.push_back(_LodAllianceRes);
  _LodCfgNormal.push_back(_LodAllianceStrong);
  _LodCfgNormal.push_back(_LodAlliance);
  _LodCfgNormal.push_back(_LodSelf);

  _LodCfgScaleNormal.push_back({EWorldLodDef::LOD1, 1.4f, 0.0f});
  _LodCfgScaleNormal.push_back({EWorldLodDef::LOD2, 0.65f, 0.0f});
  _LodCfgScaleNormal.push_back({EWorldLodDef::LOD3, 0.45f, 0.0f});
  _LodCfgScaleNormal.push_back({EWorldLodDef::LOD4, 0.25f, 0.1f});
  _LodCfgScaleNormal.push_back({EWorldLodDef::LOD5, 0.08f, 0.0f});
  _LodCfgScaleNormal.push_back({EWorldLodDef::LOD6, 0.02f, 0.0f});

  _BorderLodScale.push_back({0.7f, 2.0f, 1.0f});
  _BorderLodScale.push_back({0.4f, 4.0f, 0.5f});
  _BorderLodScale.push_back({0.2f, 8.0f, 0.25f});
  _BorderLodScale.push_back({0.1f, 16.0f, 0.125f});
  _BorderLodScale.push_back({0.05f, 32.0f, 0.06f});
  _BorderLodScale.push_back({0.02f, 64.0f, 0.03f});
  _BorderLodScale.push_back({1.0E-7f, 128.0f, 0.015f});

}


GTuple<int32, int32, int32> WorldMapLodCfg::GetFogMapScale(float pZoomScale){
  int32 lLevel = 1;
  int32 lScale = 1;
  int32 lScaleNext = 1;

  struct RZoomCfg{
    double _Scale;
    double _RangeMin;
    double _RangeMax;
    double _FadeEnd = 0;
  };
  static const GVector<RZoomCfg> sZoomCfg{
    { 1,  0.75,  1,    0    },
    { 2,  0.45,  0.75, 0.65 },
    { 3,  0.25,  0.45, 0.35 },
    { 5,  0.15,  0.25, 0.2  },
    { 20, 0.05,  0.15, 0.1  },
    { 50, 0.001, 0.05, 0.03 }
  };

  for(int32 iii = 1; iii <= sZoomCfg.size(); iii++){
    auto lV = sZoomCfg[iii - 1];
    if(pZoomScale > lV._RangeMin && pZoomScale <= lV._RangeMax){
      lLevel = iii;
      lScale = lV._Scale;
      lScaleNext = lV._Scale;
      if(lV._FadeEnd != 0 && pZoomScale > lV._FadeEnd){
        lLevel = lLevel - (pZoomScale - lV._FadeEnd) / (lV._RangeMax - lV._FadeEnd);
        lScale = sZoomCfg[iii - 2]._Scale;
      }
      break;
    }
  }

  return {lLevel, lScale, lScaleNext};
}