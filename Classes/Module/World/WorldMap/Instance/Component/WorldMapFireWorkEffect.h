#pragma once 
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Base/Type/XEngine.h"


class WorldMapFireWorkEffect : public Node
{
  CREATE_FUNC(WorldMapFireWorkEffect);
  public:
  static WorldMapFireWorkEffect *Create(EWorldMapCastleEffectID pEffect);
  void Play();
};