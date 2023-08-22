#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Containers/HashMap.h"

USING_NS_CC;

struct RWorldMapAlliancePetOffset{
  float _Scale = 1;
  Vec2 _Position;
};

class AlliancePetRead
{
  public:
    static AlliancePetRead *Get();
    static GHashMap<int32, RWorldMapAlliancePetOffset> _WorldMapPetOffset;
    GString GetWorldMapModel(int32 pPetType);
};