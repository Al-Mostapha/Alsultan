#include "Science.Module.h"

ScienceModule *ScienceModule::Get(){
  static ScienceModule *s_ScienceModule =  new ScienceModule();
  return s_ScienceModule;
}

void ScienceModule::Init(){
}

void ScienceModule::StartGame(){
  // Load();
}