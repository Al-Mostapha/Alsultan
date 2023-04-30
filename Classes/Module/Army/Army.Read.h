#pragma once
#include "Base/BaseTypeDef.h"
#include "cocos2d.h"
#include "Army.Enum.h"
#include "Module/Building/Building.Enum.h"

USING_NS_CC;

namespace spine{
  class SkeletonAnimation;
}
class ArmyRead{
public:
  struct RArmySpinData{
    char *_SpineSkel = "spine/soldiersV4/11bubing.skel";
    char *_SpineAtlas = "spine/soldiersV4/11bubing.atlas";
    spine::SkeletonAnimation *_SpineAnim;
    Vec2 _Pos;
    Vec2 _Scale = {1, 1};
  };
  static ArmyRead *Get();
  const char *GetIcon(EArmy p_Army);
  GString GetName(int32 p_IdArmy);
  GString GetName(EArmy p_IdArmy);
  GString GetTip(EArmy p_IdArmy) {return "ArmyDefaultTip";}
  EModelType GetModelType(EArmy p_Army){ return EModelType::Archer; }
  RArmySpinData GetSpecialArmyCfg(EArmy p_Army, bool p_IsSpine = false);
  GString GetPortrait(EArmy p_Army){ return "armyicon_b_5810009512.png"; }  
  GVector<EArmySkill> GetSkill(EArmy p_Army);
  EBuilding GetBuildID(EArmy p_Army){ return EBuilding::Stable;}
};