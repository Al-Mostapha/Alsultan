#include "Equip.Module.h"


EquipModule *EquipModule::Get(){
  static EquipModule *s_EquipModule =  new EquipModule();
  return s_EquipModule;
}

void EquipModule::Init(){
  
}

void EquipModule::StartGame(){
}