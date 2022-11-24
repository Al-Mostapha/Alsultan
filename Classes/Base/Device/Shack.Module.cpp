#include "Shack.Module.h"

ShackModule* ShackModule::Get()
{
  static ShackModule *l_ShackModule = nullptr;
  if (l_ShackModule == nullptr)
  {
    l_ShackModule = new ShackModule();
  }
  return l_ShackModule;
}

void ShackModule::Init()
{ 
}

void ShackModule::Unload()
{
  
}