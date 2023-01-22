#include "LegendTeam.Util.h"

LegendTeamUtil *LegendTeamUtil::Get()
{
  static auto l_Inst = new LegendTeamUtil();
  return l_Inst;
}

void LegendTeamUtil::OpenTeamView()
{
  // TODO
}
