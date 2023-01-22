#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/Player/Player.Type.h"

struct RShowLordInfoEvtArg{
  struct {
    GString TargetName;
  } ClientData;

  RLordInfo Lord;

};