#pragma once
#include "Include/IncludeBase.h"
#include "Sdk.Enum.h"

class SDKManager
{
public:
  static SDKManager* Get();
  bool IsSupportReplay();
  bool IsBeta(){ return false; };
  bool IsGameService(){ return false; };
  bool IsGameDevelop(){ return true; };
  int32 GetPushNotificationState();
  void SetSDKNoticeEnable();
  void GotoSettingPushNotification();
  bool IsRecording();
  bool IsKo();
  bool ReturnAccountBindType(ESdkPlatformType p_Platform = ESdkPlatformType::None);
};