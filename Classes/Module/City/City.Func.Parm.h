#pragma once 
#include "cocos2d.h"
#include "Module/Building/Building.Enum.h"

enum class EMainCityViewOffsetType{
  None = 0,
  Building = 1,
  LockArea = 2,
  Recover = 3
};

struct RDoOffestMoveParam{
  EBuildingIndex _BuildIndex = EBuildingIndex::None;
  class IBuilding *_BuildingBtn;
  float _Scale = 0;
  bool _NoOffsetDuration = false;
  bool _NoScaleDuration = false;
  bool _Skip = false;
  bool _IgnorePreZoomScale = false;
  EMainCityViewOffsetType _OffsetType;
  cocos2d::Vec2 _Offset;
  ~RDoOffestMoveParam(){
    CCLOG("RSetOffetContainerEvAR Removed of addr: %p", this);
  }
};
