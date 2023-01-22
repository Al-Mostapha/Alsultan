#pragma once
#include "Include/IncludeBase.h"
#include "Science/GuildScience.Enum.h"
#include "Alliance.Enum.h"

class AllianceRead{
public:
  static AllianceRead *Get();
  bool IsScience(int32 p_Science);
  GString GetScienceName(EGuildScience p_GuildScience);
  GString GetScienceName(int32 p_GuildScience);
  GString GetLanguageName(int32  p_LangName);
  bool CheckRank(EAllianceRank p_Rank, bool p_ShowTip = false, const GString &p_Tip = "");
  bool GetPlayerConquestWarMigration(bool p_ShowMsg = true);
  bool GetPlayerBattleGroundMigration(bool p_ShowMsg = true);
};