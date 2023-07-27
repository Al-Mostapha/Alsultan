#pragma once
#include "Base/BaseTypeDef.h"
#include "KingdomMap.Enum.h"

struct RKingdomInfo{
  int32 _KId;
  GString _KName;
  GString _UName;
  int32 _KFlagId;
  int32 _PalaceModel;
  bool  _CanMoveOut;
  int32 _KingdomLevel;
};

struct RFogData{
  struct {
    float ltX = 0;
    float ltY = 0;
    float rbX = 0;
    float rbY = 0;  
  } _Rect;
};

struct ROtherKingdomInfo{
  RFogData _Fog;
  EKingdomWarStatusType _WarStatus;
};