#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

USING_NS_CC;

struct RLayInstanceData{
  float _Duration;
};

struct RGotoTilePointEvAr{
  Vec2 _TilePoint;
  int32 _KingdomID;
  bool _IsSelected = false;
  bool _IsShowHand = false;
  EWorldMapLayInstance _LayInstance;
  RLayInstanceData _LayInstanceData;
  float _Scale = 1.f;
  float _Duration = 0.0f;
  bool _Animated;
  bool _IsValid = false;
  operator bool(){
    return _IsValid;
  }
};

struct RGotoTilePointNewEvAr {
  Vec2 _ToTilePos;
  float _ToScale;
  float _MoveTime = 0.5f;
  float _ScaleTime = 0.5f;
  RGotoTilePointEvAr _OldData;
  bool _IsSelected;
  int32 _KingdomID;
  bool _NeedAction;
};

struct RLeagueManorInstanceUpdateEvAr{
  int32 _InstanceID = 0;
  int32 _LeagueID = 0;
  Vec2 _TilePoint = Vec2::ZERO;
  EWorldMapLeagueManorUpdateType _UpdateType = EWorldMapLeagueManorUpdateType::None;
  bool _ActiviyStatus = false;
  int32 _Size = 1;
  int32 _Radioation = 2;
  int32 _Sn = 0;
  float _ColorId = 0;
};