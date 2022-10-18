#include "GuildHelp.h"

GuildHelp *GuildHelp::Get()
{
  static GuildHelp *s_GuildHelp = new GuildHelp();
  return s_GuildHelp;
}

void GuildHelp::ReqAllianceHelp(ETask p_Task, int p_TargetID, int p_TargetLvl)
{
  // ...
}