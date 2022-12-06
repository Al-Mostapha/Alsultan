#include "Util.h"

GUtil *GUtil::Get()
{
  static GUtil *s_GUtil = new GUtil();
  return s_GUtil;
}

void GUtil::ResetCSDCatch()
{
  
}