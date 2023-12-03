#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XEngine.h"
#include "Base/Containers/HashMap.h"

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