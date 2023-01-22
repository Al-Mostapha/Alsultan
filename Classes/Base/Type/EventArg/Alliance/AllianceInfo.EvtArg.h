#pragma once
#include "Base/BaseTypeDef.h"
#include "Module/Guild/Alliance.Type.h"

struct RShowAllianceInfoEvtArg{
  struct {
    GString From;
  } ClientData;

  RAlliance Alliance;

};