#include "Hero.Module.h"

HeroModule *HeroModule::Get(){
  static HeroModule *s_HeroModule =  new HeroModule();
  return s_HeroModule;
}

void HeroModule::Init(){
}

void HeroModule::StartGame(){
  // Load();
}