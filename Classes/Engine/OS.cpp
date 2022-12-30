#include "OS.h"
#include "Base/DateTime.h"

GOS *GOS::Get()
{
  static GOS *l_Instance = new GOS();
  return l_Instance;
}

GTime GOS::GetTime()
{
  return GDateTime::Now();
}