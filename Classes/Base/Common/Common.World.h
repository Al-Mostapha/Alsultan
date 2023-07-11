#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Module/World/WorldMap/View/WorldMapView.Type.h"

USING_NS_CC;

namespace GBase{
  bool DGotoWorldMapPoint(
    GOpt<Vec2> pPoint, bool pIsSelected = false, int32 pKingdomID = 0,
    EWorldMapLayInstance pLayInstance = EWorldMapLayInstance::None,
    GOpt<RLayInstanceData> pLayInstanceData = {}, 
    bool pInPyramid = false, bool pIsShowHand = false);
};