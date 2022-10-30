#include "Sdk.Manager.h"


SDKManager* SDKManager::Get()
{
  static SDKManager* instance = new SDKManager();
  return instance;
}
bool SDKManager::IsSupportReplay()
{
  return true;
}