#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"

USING_NS_CC;

class WorldMapMoveLine : public Sprite{
public:
  static WorldMapMoveLine* Create(Vec2 pBeginPoint, Vec2 pEndPoint);
  void UpdateMoveLineSpeed(float pSpeed){}
  void SetMoveLineColor(EMapMoveLineColor pColor){}
};