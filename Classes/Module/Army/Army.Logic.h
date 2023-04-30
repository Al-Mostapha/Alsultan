#pragma once 
#include "Army.Type.h"
#include "Module/CityResource/Resource.Type.h"
#include "Base/BaseTypeDef.h"
#include "Base/Containers/Pair.h"
#include "Module/Building/Building.Enum.h"


class ArmyLogic{
  public:
    struct RMaxTrainCount{ int32 _Base; int32 _Add; int32 _Total; };
    struct RTrainResCost{ 
      GVector<RCostResourceEnough> _CostRes;
      GTime _CostTime;
      struct {
        int32 _CostElitePoint;
        int32 _CurrentElitePoint; 
        bool _Valid = false; 
      }_CostElitePointInfo;
    };
  public:
  static ArmyLogic *Get();
  GPair<GVector<RCanTrainArmy>, int32> GetCanTrainList(EBuilding p_Bid);
  int32 GetArmyLV(EArmy p_Army){ return 10;}
  bool IsStarArmy(EArmy p_Army){ return true;}
  RMaxTrainCount GetMaxTrainCount(EBuilding p_Bid){ return RMaxTrainCount();}
  int32 GetMaxTrapBuildCount(EArmy p_ArmyId){ return 10;}
  bool IsCanTrain(EBuilding, EArmy){ return  true;}
  RTrainResCost GetTrainResCost(EBuilding, EArmy){
    return RTrainResCost();
  }

  ESoldierType GetArmyTypeByID(EArmy p_Army){ return ESoldierType::TRAP_ARROW;}

};