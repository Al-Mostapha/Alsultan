#pragma once
#include "Include/IncludeBase.h"
#include "Module/Task/Task.Enum.h"

struct RGuildHelpListUnit{
  int32 uid;
};

struct RGuildHelpList{
  GVector<RGuildHelpListUnit> TotalHelpList;
  GVector<RGuildHelpListUnit> SelfHelpList;
  GVector<RGuildHelpListUnit> OtherHelpList;
};
class GuildHelp
{
public: 
  static GuildHelp *Get();
  void ReqAllianceHelp(ETask p_Task, int p_TargetID, int p_TargetLvl);
  bool IsCanHelp();
  void ReqHelpAll();
  RGuildHelpList GetHelpList();
};