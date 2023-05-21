#pragma once

class WorldMapDef{
  public:
  // local Z_ORDER = worldMapDefine.Z_ORDER
  // local MIN_TIME_DRAG = worldMapViewDef.MIN_TIME_DRAG
  // local worldLodDef = worldMapDefine.worldLodDef

  static WorldMapDef *Get();
  void DoSwitchToAnchor();
};