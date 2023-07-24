#pragma once 

#include "Base/BaseTypeDef.h"
#include "Base/Containers/HashMap.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Module/World/WorldMap/Instance/WorldInstance.Enum.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
  #define MAX_SHOWINSTANCE 3
  #define MAX_DELINSTANCE 4
#elif  (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
  #define MAX_SHOWINSTANCE 4
  #define MAX_DELINSTANCE 6
#else
  #define MAX_SHOWINSTANCE 10
  #define MAX_DELINSTANCE 20
#endif

struct RLodCfg
{
  GString _Component;
  GString _Name;
  struct Param{
    ELodLayer _LodLayer;
    GString _Layer;
    int _MaxInstanceShow;
    int _MaxInstanceDel;
    bool _CheckVisible;
    EWorldLodDef _Default;
    GHashMap<EWorldLodDef, bool> _Pre;
    GHashMap<EWorldLodDef, bool> _Focus;
    GHashMap<EWorldLodDef, bool> _Keep;
  } _Param;
};

struct RLodCfgScale{
  EWorldLodDef _Lod;
  float _Scale;
  float _FadeBegin;
};

struct RBorderLodScale{
  float _Scale;
  float _BorderHeight;
  float _BorderRatio;
};
struct RViewClass{
  GString _CcsFile;
  GString _TileMapTmx;
  GString _TerrainControl;
  GString _TerrainControlLod;
  GString _CreateCustomLayer;
  EKingdomClassType _MapClassType;
  float _MinScale  = 0;
  float _NormalScale  = 0;
  bool _NoScaleLimit;
  bool _ConfigLod;
  bool _CanSwitch;
  bool _IsSingleMapCell;
  GVector<GString> _ComTable;
  GVector<GString> _ComTableLod;
  GVector<RLodCfg> _LodCfg;
  GVector<RLodCfgScale> _LodCfgScale;
  GVector<RBorderLodScale> _BorderLodScale;
};

struct RAllianceMarkData{
  GString _Name;
  EWorldMapAllianceMarkType _MarkType;
  int32 _MapId;
  cocos2d::Vec2 _Position;
};

struct RRemoveTroopTipData{
  int32 _MoveLineID;
  cocos2d::Vec2 _MapMoveToTilePoint;
};

struct RMoveLineArmyData{};

