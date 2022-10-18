#pragma once
#include "Include/IncludeBase.h"
#include "IBuilding.h"
#include "Building.Enum.h"

struct ABuildingMsg{
  EBuildingIndex BuildingIndex;
  Node *BuildingNode;
  bool IsHideHammer = false;
  Vec2 PosEtUpgradeOffset;
};