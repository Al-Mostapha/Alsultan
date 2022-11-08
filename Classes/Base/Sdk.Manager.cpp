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

int32 SDKManager::GetPushNotificationState()
{
  return false;
}

void SDKManager::SetSDKNoticeEnable()
{
  
}

void SDKManager::GotoSettingPushNotification()
{

}