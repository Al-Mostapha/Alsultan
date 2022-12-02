#pragma once
#include "Include/IncludeGlobal.h"
#include "WorldMap.View.h"

class WorldMapViewFactory{
  public:
  static WorldMapView *Create(RViewOtherData pOtherData ){
    return WorldMapView::Create();
  }
};