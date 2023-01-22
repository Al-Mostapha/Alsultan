#pragma once

#include "Include/IncludeBase.h"

struct RJumpTaskDef{
  
};

class ExpostulationLogic{
public:
  static ExpostulationLogic *Get();
  RJumpTaskDef GetExpostulation();
};