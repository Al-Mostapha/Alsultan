#include "Alliance.Read.h"

AllianceRead *AllianceRead::Get(){
  static AllianceRead *s_GuildRead = new AllianceRead();
  return s_GuildRead;
}

GString AllianceRead::GetScienceName(EGuildScience p_GuildScience){
  return "GuildScience";
}

GString AllianceRead::GetScienceName(int32 p_GuildScience){
  return GetScienceName(static_cast<EGuildScience>(p_GuildScience));
}

bool AllianceRead::IsScience(int32 p_Science){
  return false;
}

GString AllianceRead::GetLanguageName(int32 p_LangName){
  return "LanguageName";
}

bool AllianceRead::CheckRank(EAllianceRank p_Rank, bool p_ShowTip, const GString &p_Tip){
  return false;
}