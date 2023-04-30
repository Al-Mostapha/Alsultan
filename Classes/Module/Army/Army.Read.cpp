#include "Army.Read.h"
#include "Army.LtCtrl.h"

#include "spine/spine-cocos2dx.h"

ArmyRead *ArmyRead::Get(){
  static ArmyRead *s_ArmyRead = new ArmyRead();
  return s_ArmyRead;
}

const char *ArmyRead::GetIcon(EArmy p_Army){
  return "icon_item_common.png";
}

GString ArmyRead::GetName(int32 p_IdArmy){
  return "ArmyName";
}

GString ArmyRead::GetName(EArmy p_IdArmy){
  return "ArmyName";
}

ArmyRead::RArmySpinData ArmyRead::GetSpecialArmyCfg(EArmy p_Army, bool p_IsSpine){
//  local armyLv = serviceFunctions.getArmyViewLev(armyID)
//   local armyClass = serviceFunctions.getArmyClassByArmyId(armyID)
//   local spine
ArmyRead::RArmySpinData l_Ret;
if(p_IsSpine){
  l_Ret._SpineAnim = spine::SkeletonAnimation::createWithBinaryFile(l_Ret._SpineSkel, l_Ret._SpineAtlas, 1);
  l_Ret._SpineAnim->setPosition(l_Ret._Pos);
}
//   if isSpine then
//     local spineInfo = armyDesRead.specailArmyConfig[armyClass][armyLv]
//     if spineInfo then
//       local atlasPath = string.gsub(spineInfo.spine, "%.%w+$", ".atlas")
//       spine = sp.SkeletonAnimation:create(spineInfo.spine, atlasPath, 1)
//       spine:setPosition(spineInfo.pos.x, -spineInfo.pos.y)
//     end
//   end
//   return armyDesRead.specailArmyConfig[armyClass] and armyDesRead.specailArmyConfig[armyClass][armyLv], spine
  return l_Ret;
}

GVector<EArmySkill> ArmyRead::GetSkill(EArmy p_Army){
  return ArmyLtCtrl::Get()->GetArmyInfo(p_Army).Speciality;
}