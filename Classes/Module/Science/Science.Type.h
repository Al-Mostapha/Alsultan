#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/HashMap.h"
#include "Module/Building/Building.Type.h"
#include "Module/CityResource/Resource.Type.h"
#include "Science.Enum.h"

struct RCostScience {
  EScienceType ScienceType = EScienceType::None;
  uint32 scienceLvl = 0;
};

struct RScienceLvlSpecs {
  uint32           index;
  EScienceType     idScience;
  EScienceCategory Category;
  uint32           lvl;
  RResource        CostResource;
  uint32           buffType;
  uint32           powerNum;
  uint32           buffNumType;
  uint32           maxLvl;
  uint32           CostTime;
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
  EScienceType idScience ;
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
  GHashMap<EScienceType, RScience> Tree;
};
