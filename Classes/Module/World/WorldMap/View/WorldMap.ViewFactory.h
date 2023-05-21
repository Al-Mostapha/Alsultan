#pragma once
#include "Include/IncludeGlobal.h"
#include "WorldMap.View.h"
#include "Module/World/WorldMap/Lod/WorldMapLodCfg.h"


class WorldMapViewFactory{
  
  public:
  static WorldMapViewFactory *Get();
  void Init();
  GHashMap<EKingdomClassType, RViewClass> _TbViewClass;
  WorldMapView *Create(RViewOtherData pOtherData);
};