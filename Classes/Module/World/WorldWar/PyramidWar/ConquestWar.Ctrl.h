#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldWar/WorldWar.Enum.h"

class ConquestWarCtrl
{
public:
  static ConquestWarCtrl *Get();
  EConquestWarState GetConquestWarState();
};