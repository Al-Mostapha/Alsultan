#pragma once
#include  "Base/BaseTypeDef.h"

class WorldMapCell;

class IInstanceBuilder
{
  public:
    void Init(GVector<WorldMapCell *> p_CellArray){}
};