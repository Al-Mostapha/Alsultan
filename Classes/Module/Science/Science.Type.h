#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/HashMap.h"
#include "Module/Building/Building.Type.h"
#include "Module/CityResource/Resource.Type.h"
#include "Science.Enum.h"

struct RCostScience {
  EScience ScienceType = EScience::None;
  uint32 scienceLvl = 0;
};

struct RCostScienceEnough{
  EScience RequiredScience = EScience::None;
  uint32 RequiredScienceLvl = 0;
  uint32 maxLvl = 0;
  bool isEnough = false;
};

struct RScienceLvlSpecs {
  uint32           index;
  EScience         idScience;
  EScienceCategory Category;
  uint32           lvl;
  RResource        _CostResource;
  uint32           buffType;
  uint32           powerNum;
  uint32           buffNumType;
  uint32           maxLvl;
  uint32           _CostTime;
  RCostBuilding    CostBuilding;
  RCostBuilding    CostStarBuilding;
  GVector         <RCostScience> CostScience;
  RCostScience     CostScienceWEs;
  uint32           CostKingdomPoint;
  uint32           fighting;
  GVector         <uint32> battle;
  uint32           activity;
};

struct RScience {
  EScience     idScience ;
  GString      Name      ;
  GString      Des       ;
  GString      Icon      ;
  GString      Background;
  GHashMap<uint32, RScienceLvlSpecs> Lvls;
};

struct RScienceCategory {
  GString Key;
  RCostBuilding CostBuilding;
  RCostBuilding CostStarBuilding;
  GString CategoryName;
  GString Icon;
  GHashMap<EScience, RScience> Tree;
};
