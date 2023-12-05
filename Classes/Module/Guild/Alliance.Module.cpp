#include "Alliance.Module.h"

AllianceModule *AllianceModule::Get(){
  static AllianceModule *s_AllianceModule =  new AllianceModule();
  return s_AllianceModule;
}

void AllianceModule::Init(){
}

void AllianceModule::StartGame(){
  // Load();
}
