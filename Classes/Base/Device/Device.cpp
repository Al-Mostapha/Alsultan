#include "Device.h"

GDevice *GDevice::Get()
{
  static GDevice *l_Device = nullptr;
  if (l_Device == nullptr)
  {
    l_Device = new GDevice();
  }
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