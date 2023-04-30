#include "Science.Read.h"
#include "Base/BaseTypeDef.h"

GMap<EScienceType, std::string> ETECHNOLOGY_ATTR = {
  { EScienceType::None,"none" },
  { EScienceType::Resource ,"resource" },
  { EScienceType::CityDevelop,"cityDevelop" },
  { EScienceType::Anchor,"anchor" },
  { EScienceType::Military,"military" },
  { EScienceType::Special,"special" },
  { EScienceType::Soldier,"soldier" },
  { EScienceType::Leader,"leader" },
  { EScienceType::Hero,"hero" },
  { EScienceType::WarTechnology,"wartechnology" },
  { EScienceType::WarBattle,"warbattle" },
  { EScienceType::WarMilitary,"warmilitary" },
  { EScienceType::WarCommand,"warcommand" },
  { EScienceType::WarLight,"warlight" },
  { EScienceType::AdvancedMilitary,"advancedmilitary" },
  { EScienceType::Process,"process" }
};


ScienceRead *ScienceRead::Get(){
  static ScienceRead *s_ScienceRead = new ScienceRead();
  return s_ScienceRead;
}

const char *ScienceRead::GetIcon(EScienceID p_Science){
  return "icon_item_common.png";
}

bool ScienceRead::IsScience(int32 p_Science){
  return true;
}

GString ScienceRead::GetName(EScienceID p_Science){
  return "Science";
}

GString ScienceRead::GetName(int32 p_Science){
  return GetName(static_cast<EScienceID>(p_Science));
}