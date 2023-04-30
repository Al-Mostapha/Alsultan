#pragma once
#include "Include/IncludeBase.h"
#include "Base/Containers/HashMap.h"
#include "Module/Building/Building.Type.h"
#include "Module/CityResource/Resource.Type.h"
#include "Science.Enum.h"

struct RCostScience {
  EScienceID ScienceType = EScienceID::None;
  uint32 scienceLvl = 0;
};

struct RCostScienceEnough{
  EScienceID RequiredScience = EScienceID::None;
  uint32 RequiredScienceLvl = 0;
  uint32 maxLvl = 0;
  bool isEnough = false;
};

struct RScienceLvlSpecs {
  uint32           index;
  EScienceID         idScience;
  EScienceType Category;
  uint32           lvl;
  GHashMap<EResource, uint32>       _CostResource;
  uint32           buffType;
  uint32           powerNum;
  uint32           buffNumType;
  uint32           maxLvl;
  GTime           _CostTime;
  GHashMap<EBuilding, uint32> CostBuilding;
  GHashMap<EBuilding, uint32> CostStarBuilding;
  GHashMap<EScienceID, uint32> _TechnologyPrepose; // cost in technology
  RCostScience     CostScienceWEs;
  uint32           CostKingdomPoint;
  uint32           fighting;
  GVector         <uint32> battle;
  uint32           activity;
};

struct RScience {
  EScienceID     idScience ;
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
  GHashMap<EScienceID, RScience> Tree;
};

struct RScienceDetail{
  int32 _CurrentLvl;
  int32 _MaxLvl;
  EScienceID _TechnologyID;
  GString _CurrentLvlEffect;
  GString _NextLvlEffect;
  GTime _TechnologyTime;
  ITask *_UpgradeIngTechnology;
  struct RResources {
    EResource _Bid;
    uint32 _CurrentResource;
    uint32 _ConsumeResource;
    bool _IsContentmented;
    bool _IsLuckyContentmented;
  };
  struct RBuilds {
    EBuilding _Bid;
    uint32 _CurrentLvl;
    uint32 _ConsumeLvl;
    bool _IsContentmented;
  };
  struct RTechs {
    EScienceID _Tid;
    uint32 _CurrentLvl;
    uint32 _ConsumeLvl;
    bool _IsContentmented;
  };
  struct RItems {
    int32 _Rid;
    uint32 _CurrentResource;
    uint32 _ConsumeResource;
    bool _IsContentmented;
  };

  GVector<RResources> _Resources;
  GVector<RBuilds> _Builds;
  GVector<RBuilds> _StarBuild;
  GVector<RTechs> _Tech;
  GVector<RItems> _Wartool;
  int32 _CurPower;
  int32 _NextPower;
  int32 _Cost;
};


