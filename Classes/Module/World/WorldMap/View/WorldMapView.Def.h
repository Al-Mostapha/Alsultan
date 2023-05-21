#pragma once
#include "Base/BaseTypeDef.h"

class WorldMapViewDef{

  public:
  static WorldMapViewDef *Get();
  float MIN_SCALE = 0.75;
  float MIN_SCALE_DEFAULT = 0.75;
  float MIN_SCALE_NO_LIMIT = 0.01;
  float MAX_SCALE = 1.35;
  float NORMAL_SCALE = 1;
  float NORMAL_SCALE_DEFAULT = 1;
  float TileBG_Offset_X = 200;
  float TileBG_Offset_Y = 200;
  float MIN_TIME_MARCH = 1.5;
  // if device.platform == "android" then
  //   worldMapViewDef.MIN_TIME_DRAG = 0.4
  // else
  //   worldMapViewDef.MIN_TIME_DRAG = 0.2
  // end
  float MIN_TIME_DRAG = 0.4;
  int32 NODEINFO_TYPE_MANORLINE = 1;
  int32 NODEINFO_TYPE_RESOURCE = 2;
  int32 NODEINFO_TYPE_ALLIANCE = 3;
};