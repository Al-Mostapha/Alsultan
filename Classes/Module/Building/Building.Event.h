#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeGlobal.h"
#include "IBuilding.h"
#include "Building.Enum.h"

struct ABuildingMsg{
  EBuildingIndex BuildingIndex;
  Node *BuildingNode;
  bool IsHideHammer = false;
  Vec2 PosEtUpgradeOffset;
};

struct ABuildingTouchMsg{
  EBuildingIndex BuildingIndex;
  Node *BuildingNode;
  Event *TouchEvent;
  ETouchEventType TouchEventType;
  Vec2 PosEtUpgradeOffset;
};