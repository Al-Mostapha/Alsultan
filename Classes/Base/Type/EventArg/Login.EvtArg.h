#pragma once 
#include "Global/Global.Enum.h"
#include "Base/BaseTypeDef.h"
#include "Module/Building/Building.Enum.h"
#include "Module/Army/Army.Enum.h"
#include "Module/CityResource/Resource.Enum.h"
#include "Module/Science/Science.Enum.h"

class UIBaseView;

struct RLoginFailEvtArg
{
  ELoginFailType Type;
  GTime ServerTime;
  int32 KingdomId;
};

struct RHideMainUIEvtArg
{
  ENullBool isHideCurrentSceneView = ENullBool::Null;
  ENullBool isHideMainUI = ENullBool::Null;
};


struct RShowViewHidedEvtArg
{
  UIBaseView *View = nullptr;
  bool isVisible = false;
};

struct RServerMessageInfo{
  int32 messageID;
  struct {
    ENoticeIcon IconType = ENoticeIcon::None;
    int32 iconID;
    const char *iconName;
  } IconData;

  struct {
    EBuilding BuildID = EBuilding::None;
    int32 itemID;
    EArmy SoliderID = EArmy::None;
    EResource ResourceID = EResource::None;
    int32 TechID = 0;
    int32 equipID;
    int32 languageID;
  } Param;
};