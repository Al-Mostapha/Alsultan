#pragma once
#include "Base/BaseTypeDef.h"
#include "Activity.Enum.h"

struct RActivityShowData{

  struct {
    GString Url;
    int32 Show = 0; // ID ActivityShow
    int32 Type = 0; // ID ActivityType
  } Param;
};