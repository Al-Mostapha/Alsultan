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

bool AllianceRead::GetPlayerConquestWarMigration(bool p_ShowMsg){
  return false;
}

bool AllianceRead::GetPlayerBattleGroundMigration(bool p_ShowMsg){
  return false;
}

GVector<float> &AllianceRead::GetManorlineColorArray(){
  static GVector<float> lRet;
  lRet = {
    0, 1, 1,      1,
    1, 0, 1,      0,
    0, 0, 0.4941, 1,
    0.98, 0.98,   0.98,
    0.65, 0.65,   0.65
  };
  // for i, v in ipairs(allianceDesRead.landcolor) do
  //   ret[#ret + 1] = v.color[1]
  //   ret[#ret + 1] = v.color[2]
  //   ret[#ret + 1] = v.color[3]
  // end
  //    allianceDesRead.manorlineColorArray = ret
  return lRet;
}

GString AllianceRead::GetFlagIcon(int32 pFid, bool pFromMemory){
  return "Allianceflag_015.png";
}

Color3B AllianceRead::GetTerritoryColor(int32 pColorId){
  // local data = allianceDesRead.landcolor[colorId]
  // if data then
  //   local color = data.color
  //   return cc.c3b(color[1] * 255, color[2] * 255, color[3] * 255)
  // end

  return Color3B(0.07*255, 0.44*255, 0.26*255);
}

GString AllianceRead::GetBuildName(EMapAllianceBuildType pBuildingClassID){
  return "BuildName";
}