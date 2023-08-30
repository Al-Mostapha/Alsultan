#pragma once

#include "Base/BaseTypeDef.h"
#include "IWorldMapInstance.h"
#include "WorldInstance.Enum.h"
#include "Base/Containers/HashMap.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Module/World/WorldMap/Monster/Boss/Boss.Type.h"



USING_NS_CC;

class IWorldInstanceBuilder;
class WorldMapCell;

struct RWorldMonsterObjData{
  EMapNpcFaceTypeDef _FaceTo;
};

struct RWorldInstanceData{
    Vec2 _TilePoint;
    EMapObjTypeDef _TileInstanceType;
    int32 _TileInstanceID;
    int32 _TileInstanceKingdomID;
    GOpt<RMassRef> _MassRef;
    int32 _SubMapType;
    EWorldInstanceClass _Class;
    int32 _ObjID;
    void *_ObjData;
};


struct RInstanceData{
  int32 _X;
  int32 _Y;
  EMapObjTypeDef _Type;
  int32 _ID;
  int32 _KID;
  int32 _DelayTime;
  int32 _SubMapType;  
  int32 _ObjID;
  int32 _SettingID;
  EWorldInstanceClass _Class;
  GOpt<RWorldInstanceData> _WorldInstanceData;
  GOpt<RMassRef> _Ref;
  
};


struct RWorldInstanceConfigLod;


struct RWorldInstanceConfigLod {
  EWorldInstanceClass _Class;
  EGrouID _BatchNode;
  bool _Cache;
  std::function<ELodLayer(EWorldLodDef, int32)> _LodLayerFun = nullptr;
  std::function<
    IWorldMapInstance *(
      IWorldInstanceBuilder *, 
      const RWorldInstanceConfigLod &, 
      WorldMapCell *, 
      RWorldInstanceData, 
      RInstanceData)
  > _CreateFun = nullptr;

  GHashMap<int32, EWorldInstanceClass> _ClassTable;
  ELodLayer _LodLayer = ELodLayer::None;
};

struct RWorldInstanceConfig{

    int32 _HoldInstace = 0;
    GString _FromKey = "";
    bool _DelayTime = false;
    bool _IsHurtDie = false;
    std::function<bool(EWorldLodDef, int32, int32)> _LodShowFun = nullptr;
    GHashMap<EWorldLodDef, RWorldInstanceConfigLod> _Lod;
    GHashMap<int32, int32> _HoldInstaceTable;
};

