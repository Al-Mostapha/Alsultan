#pragma once
#include "Base/BaseTypeDef.h"

class IWorldMapInstance;

struct RMessageServerAncientTreasureUpdate{
  bool _IsOccupy;
  IWorldMapInstance *_Instance;
};