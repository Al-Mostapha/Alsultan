#include "Pet.Module.h"

PetModule *PetModule::Get(){
  static PetModule *s_PetModule =  new PetModule();
  return s_PetModule;
}

void PetModule::Init(){
}

void PetModule::StartGame(){
  // Load();
}