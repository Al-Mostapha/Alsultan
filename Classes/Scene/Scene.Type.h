#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/View/WorldMapView.Type.h"
#include "Scene.Enum.h"
#include "Module/Building/Building.Enum.h"


enum class EWorldMapLayInstance;
struct RLayInstanceData;

struct RViewOtherData{
  int32 kingdomID = 0;
  Vec2 _TilePoint = Vec2::ZERO;
  bool _IsSelected = false;
  EWorldMapLayInstance _LayInstance;
  RLayInstanceData _LayInstanceData;
  GString _View;
  EBuilding _BID;
  GString _Msg;
  operator bool() const{
    return true;
  }
};

struct RShowMainCityView{
  bool isJudgeCurScene = false;
  EScene ViewType = EScene::None;
  bool isFromLogin = false;
  bool isFactionSwitch = false;
  RViewOtherData OtherData;
};