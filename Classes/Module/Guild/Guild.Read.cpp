#include "Guild.Read.h"

GuildRead *GuildRead::Get(){
  static GuildRead *s_GuildRead = new GuildRead();
  return s_GuildRead;
}

GString GuildRead::GetScienceName(EGuildScience p_GuildScience){
  return "GuildScience";
}

GString GuildRead::GetScienceName(int32 p_GuildScience){
  return GetScienceName(static_cast<EGuildScience>(p_GuildScience));
}

bool GuildRead::IsScience(int32 p_Science){
  return false;
}

GString GuildRead::GetLanguageName(int32 p_LangName){
  return "LanguageName";
}