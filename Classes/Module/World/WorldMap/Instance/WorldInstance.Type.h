#pragma once

#include "Base/BaseTypeDef.h"
#include "IWorldMapInstance.h"
#include "IWorldInstance.Builder.h"
#include "WorldInstance.Enum.h"
#include "Base/Containers/HashMap.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"



USING_NS_CC;

class WorldMapCell;

struct RWorldMonsterObjData{
  EMapNpcFaceTypeDef _FaceTo;
};

struct RWorldInstanceData{
  Vec2 _TilePoint;
  EMapObjTypeDef _TileInstanceType;
  int32 _SubMapType;
  EWorldInstanceClass _Class;
  int32 _TileInstanceID;
  void *_ObjData;
};

struct RWorldInstanceConfig{
    typedef std::function<bool(EWorldLodDef, int32, int32)> FLodFun;
    typedef std::function<IWorldMapInstance *(IWorldInstanceBuilder *, RWorldInstanceConfig, WorldMapCell *, RWorldInstanceData)> FCreateFun;

    struct RLod {
      EWorldInstanceClass _Class;
      EGrouID _BatchNode;
      bool _Cache;
      FLodFun _LodLayerFun = nullptr;
      FCreateFun _CreateFun = nullptr;
      GHashMap<int32, EWorldInstanceClass> _ClassTable;
    };

    int32 _HoldInstace = 0;
    GString _FromKey = "";
    bool _DelayTime = false;
    FLodFun _LodShowFun = nullptr;
    GHashMap<EWorldLodDef, RLod> _Lod;
    GHashMap<int32, int32> _HoldInstaceTable;
};

