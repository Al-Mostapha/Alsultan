#include "LordSkillModule.Api.h"

LordSkillModuleAPI *LordSkillModuleAPI::Get(){
  static LordSkillModuleAPI *_LordSkillModuleAPI = nullptr;
  if(_LordSkillModuleAPI == nullptr){
    _LordSkillModuleAPI = new LordSkillModuleAPI();
  }
  return _LordSkillModuleAPI;
}

RSkillCDData LordSkillModuleAPI::GetSkillCDData(int32 pSkillID){
  RSkillCDData _RSkillCDData;
  return _RSkillCDData;
}
