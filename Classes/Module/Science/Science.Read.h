#pragma once
#include "Include/IncludeBase.h"
#include "Science.Enum.h"

class ScienceRead{
  struct RSingleData{
    GString _Title;
    GString _Icon;
    Color3B _Color;
    GString _Base;
    bool _Valid = false;
  };
public:
  static ScienceRead *Get();
  const char *GetIcon(EScience p_Science);
  const char *GetBg(EScience p_Science);
  GString GetName(EScience p_Science);
  GString GetName(int32 p_Science);
  bool IsScience(int32 p_Science);
  EScienceType GetType(EScience p_Science){ return EScienceType::Resource; }
  RSingleData GetTypeTitleIcon(EScienceType){
    RSingleData l_Data;
    l_Data._Title = "common_text_045";
    l_Data._Icon = "icon_ranking_lord_power.png";
    l_Data._Color = Color3B(160, 250, 0);
    l_Data._Base = "frame_round_tech_04.png";
    return l_Data;
  }

  uint32 GetFight(EScience p_Science, uint32 p_Lvl){return 10;}

  GVector<EScience> GetTree(EScienceType);
};