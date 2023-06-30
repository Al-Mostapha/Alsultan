#pragma once
#include "Base/BaseTypeDef.h"
#include "Scene.Enum.h"

enum class EWorldMapLayInstance;

struct RViewOtherData{
  int32 kingdomID = 0;
  Vec2 _TilePoint = Vec2::ZERO;
  bool _IsSelected = false;
  EWorldMapLayInstance _LayInstance;
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