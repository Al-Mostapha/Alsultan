#include "Item.Module.h"

ItemModule *ItemModule::Get(){
  static ItemModule *s_ItemModule =  new ItemModule();
  return s_ItemModule;
}

void ItemModule::Init(){
}

void ItemModule::StartGame(){
  // Load();
}