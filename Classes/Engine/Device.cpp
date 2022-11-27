#include "Device.h"

GDevice *GDevice::Get()
{
  static GDevice *l_Device =  new GDevice();
  cocos2d::log("GDevice::Get %p", l_Device);
  return l_Device;
}

EPlatform GDevice::Platform()
{
  return EPlatform::None;
}

bool GDevice::IsIphoneXMode()
{
  return Application::getInstance()->getTargetPlatform() == Application::Platform::OS_IPHONE;
}

bool GDevice::IsIpadMode()
{
  return Application::getInstance()->getTargetPlatform() == Application::Platform::OS_IPAD;
}

void GDevice::Init()
{

}