#include "Fabric.h"

GFabric *GFabric::Get()
{
  static GFabric *s_GFabric = new GFabric();
  return s_GFabric;
}

void GFabric::ReportDeviceInfoChange()
{
  // Do something
}