#include "World.Module.h"

WorldModule *WorldModule::Get(){
  static WorldModule *s_WorldModule =  new WorldModule();
  return s_WorldModule;
}

void WorldModule::Init(){
}

void WorldModule::StartGame(){
  // Load();
}