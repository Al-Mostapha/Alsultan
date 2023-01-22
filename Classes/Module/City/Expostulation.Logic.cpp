#include "Expostulation.Logic.h"

ExpostulationLogic *ExpostulationLogic::Get()
{
  static auto s_ExpostulationLogic = new ExpostulationLogic();
  return s_ExpostulationLogic;
}

RJumpTaskDef ExpostulationLogic::GetExpostulation()
{
  return RJumpTaskDef();
  // ...
}
