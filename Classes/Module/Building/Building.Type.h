#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Containers/HashMap.h"
#include "Base/Json.h"
#include "Base/Type/Json/XJson.h"
#include "Base/Reflect.h"
#include "Module/Army/Army.Enum.h"
#include "Building.Const.h"
#include "Building.Enum.h"
#include "Building.Task.h"
#include "Module/Building/BuildingLib/BuildingWatchTower.Lib.h"
#include "Module/CityResource/Resource.Type.h"
#include "Module/Science/Science.Enum.h"
#include "Module/Item/Item.Type.h"
#include "Module/City/CityBuildingUtils/CityBuildingBtnAction.h"




struct RCostBuilding {
  EBuilding TypeReq = EBuilding::None;
  uint32 lvlReq = 0;
  static RCostBuilding fromJson(GJson* json) { RCostBuilding temp; return temp; }
};

struct RCostBuildingEnough{
  EBuilding  TypeReq;
  uint32 lvlReq;
  uint32 lvlCurMax;
  int32 lvlLack;
  int32 _StarLvl;
  bool _IsReach;
};

struct RCostBuildingUpgrade{
  GVector<RCostBuildingEnough> _CostBuilding;
  GVector<RCostItemEnough> _CostItem;
  GVector<RCostItemEnough> _CostItemWEs;
  GVector<bool> _PreCond;
  GVector<RCostResourceEnough> _CostResource;
  uint32 _CostTime;
  uint32 resToGold;
  uint32 itemToGold;
  uint32 totalGold;
  uint32 WEToGold;
  uint32 timeToGold;
  int32 _ImmediatelyGold;
  struct {
    uint32 exp = 0;
    uint32 power = 0;
  } Reword;
  GVector<RBuildingTask> _BuildingTaskQueue;
  bool _Valid;
};

struct RBuildingLvlSpecs {
  GVector<RCostBuilding> CostBuilding;
  RResource CostRes;
  GVector<RCostItem> CostItems;
  GVector<RCostItem> CostWEs;
  struct {
    uint32 exp;
    uint32 power;
  } Reword;
  uint32 _CostTime = 0;
  uint32 lvl = 0;
  uint32 kingdomPoint = 0;
  uint32 atkAdd = 0;
  uint32 atkSpeedAdd = 0;
  uint32 baseAtkSpeed = 0;
  uint32 gunshot = 0;
  EArmy unlockedSoldier;
  uint32 forgeSpeed = 0;
  uint32 steelReduce = 0;
  uint32 kingdomLv = 0;
  EBuilding unlockedBuild = EBuilding::None;
  EScience unlockedTechnology = EScience::None;
  uint32 capacity = 0;
  uint32 output = 0;
  uint32 addOutputCostGold = 0;
  uint32 maxSoldier = 0;
  uint32 ElitePointLimit = 0;
  uint32 helpCount = 0;
  uint32 reduceTime = 0;
  uint32 reinforcements = 0;
  uint32 prisonNum = 0;
  uint32 attack = 0;
  uint32 defense = 0;
  uint32 life = 0;
  uint32 speed = 0;
  uint32 speedTime = 0;
  uint32 heroNum = 0;
  uint32 trainExpBonus = 0;
  uint32 buildTime = 0;
  uint32 baseExp = 0;
  uint32 taxRate = 0;
  uint32 trainSpeed = 0;
  GString unlockDescribe = "";
  uint32 defValue = 0;
  RResource resCapacity;
  EWatchTowerEffect watchTowerEffect = EWatchTowerEffect::None;
  uint32 freeTime = 0;
  static RBuildingLvlSpecs fromJson(GJson* json) { return RBuildingLvlSpecs(); }
};

struct RBuildingMoreInfoData{

  //TODO:  should be enum
  int32 _MoreInfoType;
  int32 _InfoDesType;
  GString _Title;
  GString _Value;
  GString _PlusValue;
  EBuilding _Bid;
};

struct RCityBuildingUnit {
  int32 buildingLvl;
  GString NodeName;
  GString BuildingPlace;
  EBuilding eBuildingType;
  EBuildingPos eBuildingPos;
  RCityBuildingUnit(const char* nodeName, const char* buildingPlace, EBuildingPos eBP) 
  : NodeName(nodeName), BuildingPlace(buildingPlace), eBuildingPos(eBP){};
  RCityBuildingUnit() : NodeName(""), BuildingPlace(""), eBuildingPos(EBuildingPos::CBPlace_Inner){};
  void fromJson(GJson* json);
  RCityBuildingUnit& buildUnit();
  RCityBuildingUnit& addToBuildingList();
};

struct RBuildingSpecs {
  int32 index = 0;
  EBuilding BuildingID = EBuilding::None;
  bool isDemolish = false;
  bool isExchange = false;
  bool isBuild = false;
  bool isUpgrade = false;
  EBuilding buildingType = EBuilding::None;
  EBuildingPlace bType = EBuildingPlace::Inner;
  int32 maxCount = 0;
  int32 maxLvl = 0;
  int32 initLvl = 0;
  int32 openWl = 0;
  int32 openStar = 0;
  int32 maxStarLv = 0;
  int32 isCanBuild = 1; // 0, 1, 2
  const char *BuildingName = "Building Name";
  const char *BuildingIcon = "quest_building_114.png";
  const char *BuildingBrief = "";
  const char *UpgradeBrief = "";
  const char *Describe = "Describe";
  const char *WarDescribe = "";
  const char *StarDescribe = "";
  GHashMap<uint32, RBuildingLvlSpecs> Lvls;

  static RBuildingSpecs fromJson(GJson* json) ;
};

struct RCityBuilding {
  int32 idPlayer;
  int32 idCity;
  GMap<GString, RCityBuildingUnit> BuildingList;
  struct {
    int idCity;
    int idPlayer;
    RCityBuildingUnit castle = RCityBuildingUnit("build_1050", "castle", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit arrowTowerL = RCityBuildingUnit("build_1052", "arrowTowerL", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit wall = RCityBuildingUnit("build_1053", "wall", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit arrowTowerR = RCityBuildingUnit("build_1054", "arrowTowerR", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit watchTower = RCityBuildingUnit("build_1055", "watchTower", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit merchant = RCityBuildingUnit("Img_Lvxingshanren", "merchant", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit harbor = RCityBuildingUnit("build_30002", "harbor", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit troopDetail = RCityBuildingUnit("Node_flag", "troopDetail", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit leisureHouse = RCityBuildingUnit("build_30001", "leisureHouse", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit prison = RCityBuildingUnit("build_1203", "prison", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit trainHall = RCityBuildingUnit("build_1204", "trainHall", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit miracle = RCityBuildingUnit("build_1200", "miracle", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit braveStatue = RCityBuildingUnit("build_1205", "braveStatue", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit petCenter = RCityBuildingUnit("build_30003", "petCenter", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit resurrectionHall = RCityBuildingUnit("build_30004", "resurrectionHall", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit serviceCenter = RCityBuildingUnit("build_30005", "serviceCenter", EBuildingPos::CBPlace_Fixed);  // this is error
    RCityBuildingUnit eventCenter = RCityBuildingUnit("build_30005", "eventCenter", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit epicBattle = RCityBuildingUnit("build_30006", "epicBattle", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit monument = RCityBuildingUnit("build_30007", "Monument", EBuildingPos::CBPlace_Fixed);
    RCityBuildingUnit veteransHall = RCityBuildingUnit("build_1201", "veteransHall", EBuildingPos::CBPlace_Fixed);
    void fromJson(GJson* json) {
      if (json == nullptr) return;
      idCity = json->GetInt("idCity", 0);
      idPlayer = json->GetInt("idPlayer", 0);
      castle.fromJson(json->GetJsonObject("castle"));
      arrowTowerL.fromJson(json->GetJsonObject("arrowTowerL"));
      wall.fromJson(json->GetJsonObject("wall"));
      arrowTowerR.fromJson(json->GetJsonObject("arrowTowerR"));
      watchTower.fromJson(json->GetJsonObject("watchTower"));
      merchant.fromJson(json->GetJsonObject("merchant"));
      harbor.fromJson(json->GetJsonObject("harbor"));
      troopDetail.fromJson(json->GetJsonObject("troopDetail"));
      leisureHouse.fromJson(json->GetJsonObject("leisureHouse"));
      prison.fromJson(json->GetJsonObject("prison"));
      trainHall.fromJson(json->GetJsonObject("trainHall"));
      miracle.fromJson(json->GetJsonObject("miracle"));
      braveStatue.fromJson(json->GetJsonObject("braveStatue"));
      petCenter.fromJson(json->GetJsonObject("petCenter"));
      resurrectionHall.fromJson(json->GetJsonObject("resurrectionHall"));
      serviceCenter.fromJson(json->GetJsonObject("serviceCenter"));
      eventCenter.fromJson(json->GetJsonObject("eventCenter"));
      epicBattle.fromJson(json->GetJsonObject("epicBattle"));
      monument.fromJson(json->GetJsonObject("monument"));
      veteransHall.fromJson(json->GetJsonObject("veteransHall"));
    }
  } CityBuildingFixed;

  struct {
    int idCity;
    int idPlayer;
    RCityBuildingUnit innerBuilding_1 = RCityBuildingUnit("build_1051", "innerBuilding_1", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_2 = RCityBuildingUnit("build_1056", "innerBuilding_2", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_3 = RCityBuildingUnit("build_1057", "innerBuilding_3", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_4 = RCityBuildingUnit("build_1058", "innerBuilding_4", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_5 = RCityBuildingUnit("build_1059", "innerBuilding_5", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_6 = RCityBuildingUnit("build_1060", "innerBuilding_6", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_7 = RCityBuildingUnit("build_1061", "innerBuilding_7", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_8 = RCityBuildingUnit("build_1062", "innerBuilding_8", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_9 = RCityBuildingUnit("build_1063", "innerBuilding_9", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_10 = RCityBuildingUnit("build_1064", "innerBuilding_10", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_11 = RCityBuildingUnit("build_1065", "innerBuilding_11", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_12 = RCityBuildingUnit("build_1066", "innerBuilding_12", EBuildingPos::CBPlace_Inner);
    RCityBuildingUnit innerBuilding_13 = RCityBuildingUnit("build_1067", "innerBuilding_13", EBuildingPos::CBPlace_Inner);

    void fromJson(GJson* json) {
      if (json == nullptr) return;
      innerBuilding_1.fromJson(json->GetJsonObject("innerBuilding_1"));
      innerBuilding_2.fromJson(json->GetJsonObject("innerBuilding_2"));
      innerBuilding_3.fromJson(json->GetJsonObject("innerBuilding_3"));
      innerBuilding_4.fromJson(json->GetJsonObject("innerBuilding_4"));
      innerBuilding_5.fromJson(json->GetJsonObject("innerBuilding_5"));
      innerBuilding_6.fromJson(json->GetJsonObject("innerBuilding_6"));
      innerBuilding_7.fromJson(json->GetJsonObject("innerBuilding_7"));
      innerBuilding_8.fromJson(json->GetJsonObject("innerBuilding_8"));
      innerBuilding_9.fromJson(json->GetJsonObject("innerBuilding_9"));
      innerBuilding_10.fromJson(json->GetJsonObject("innerBuilding_10"));
      innerBuilding_11.fromJson(json->GetJsonObject("innerBuilding_11"));
      innerBuilding_12.fromJson(json->GetJsonObject("innerBuilding_12"));
      innerBuilding_13.fromJson(json->GetJsonObject("innerBuilding_13"));
    }
  } CityBuildingInner;

  struct {
    int idCity;
    int idPlayer;
    /* Free Area*/
    RCityBuildingUnit resBuilding_1 = RCityBuildingUnit("build_1100", "resBuilding_1", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_2 = RCityBuildingUnit("build_1101", "resBuilding_2", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_3 = RCityBuildingUnit("build_1102", "resBuilding_3", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_4 = RCityBuildingUnit("build_1103", "resBuilding_4", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_5 = RCityBuildingUnit("build_1104", "resBuilding_5", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_6 = RCityBuildingUnit("build_1105", "resBuilding_6", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_7 = RCityBuildingUnit("build_1106", "resBuilding_7", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_8 = RCityBuildingUnit("build_1107", "resBuilding_8", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_9 = RCityBuildingUnit("build_1108", "resBuilding_9", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_10 = RCityBuildingUnit("build_1109", "resBuilding_10", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_11 = RCityBuildingUnit("build_1110", "resBuilding_11", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_12 = RCityBuildingUnit("build_1111", "resBuilding_12", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_13 = RCityBuildingUnit("build_1112", "resBuilding_13", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_14 = RCityBuildingUnit("build_1113", "resBuilding_14", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_15 = RCityBuildingUnit("build_1114", "resBuilding_15", EBuildingPos::CBPlace_Outer);

    // First Locked Area Panel_Area_Lock_1220
    RCityBuildingUnit resBuilding_16 = RCityBuildingUnit("build_1115", "resBuilding_16", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_17 = RCityBuildingUnit("build_1116", "resBuilding_17", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_18 = RCityBuildingUnit("build_1117", "resBuilding_18", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_19 = RCityBuildingUnit("build_1118", "resBuilding_19", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_20 = RCityBuildingUnit("build_1119", "resBuilding_20", EBuildingPos::CBPlace_Outer);
    // secound Locked Area Panel_Area_Lock_1223
    RCityBuildingUnit resBuilding_21 = RCityBuildingUnit("build_1130", "resBuilding_21", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_22 = RCityBuildingUnit("build_1131", "resBuilding_22", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_23 = RCityBuildingUnit("build_1132", "resBuilding_23", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_24 = RCityBuildingUnit("build_1133", "resBuilding_24", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_25 = RCityBuildingUnit("build_1134", "resBuilding_25", EBuildingPos::CBPlace_Outer);
    // Third Locked Area Panel_Area_Lock_1222
    RCityBuildingUnit resBuilding_26 = RCityBuildingUnit("build_1125", "resBuilding_26", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_27 = RCityBuildingUnit("build_1126", "resBuilding_27", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_28 = RCityBuildingUnit("build_1127", "resBuilding_28", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_29 = RCityBuildingUnit("build_1128", "resBuilding_29", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_30 = RCityBuildingUnit("build_1129", "resBuilding_30", EBuildingPos::CBPlace_Outer);
    // Forth Locked Area Panel_Area_Lock_1221
    RCityBuildingUnit resBuilding_31 = RCityBuildingUnit("build_1120", "resBuilding_31", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_32 = RCityBuildingUnit("build_1121", "resBuilding_32", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_33 = RCityBuildingUnit("build_1122", "resBuilding_33", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_34 = RCityBuildingUnit("build_1123", "resBuilding_34", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_35 = RCityBuildingUnit("build_1124", "resBuilding_35", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_36 = RCityBuildingUnit("build_1151", "resBuilding_36", EBuildingPos::CBPlace_Outer);
    RCityBuildingUnit resBuilding_37 = RCityBuildingUnit("build_1152", "resBuilding_37", EBuildingPos::CBPlace_Outer);
    void fromJson(GJson* json) {
      if (json == nullptr) return;
      idCity = json->GetInt("idCity", 0);
      idPlayer = json->GetInt("idPlayer", 0);
      resBuilding_1.fromJson(json->GetJsonObject("resBuilding_1"));
      resBuilding_2.fromJson(json->GetJsonObject("resBuilding_2"));
      resBuilding_3.fromJson(json->GetJsonObject("resBuilding_3"));
      resBuilding_4.fromJson(json->GetJsonObject("resBuilding_4"));
      resBuilding_5.fromJson(json->GetJsonObject("resBuilding_5"));
      resBuilding_6.fromJson(json->GetJsonObject("resBuilding_6"));
      resBuilding_7.fromJson(json->GetJsonObject("resBuilding_7"));
      resBuilding_8.fromJson(json->GetJsonObject("resBuilding_8"));
      resBuilding_9.fromJson(json->GetJsonObject("resBuilding_9"));
      resBuilding_10.fromJson(json->GetJsonObject("resBuilding_10"));
      resBuilding_11.fromJson(json->GetJsonObject("resBuilding_11"));
      resBuilding_12.fromJson(json->GetJsonObject("resBuilding_12"));
      resBuilding_13.fromJson(json->GetJsonObject("resBuilding_13"));
      resBuilding_14.fromJson(json->GetJsonObject("resBuilding_14"));
      resBuilding_15.fromJson(json->GetJsonObject("resBuilding_15"));
      resBuilding_16.fromJson(json->GetJsonObject("resBuilding_16"));
      resBuilding_17.fromJson(json->GetJsonObject("resBuilding_17"));
      resBuilding_18.fromJson(json->GetJsonObject("resBuilding_18"));
      resBuilding_19.fromJson(json->GetJsonObject("resBuilding_19"));
      resBuilding_20.fromJson(json->GetJsonObject("resBuilding_20"));
      resBuilding_21.fromJson(json->GetJsonObject("resBuilding_21"));
      resBuilding_22.fromJson(json->GetJsonObject("resBuilding_22"));
      resBuilding_23.fromJson(json->GetJsonObject("resBuilding_23"));
      resBuilding_24.fromJson(json->GetJsonObject("resBuilding_24"));
      resBuilding_25.fromJson(json->GetJsonObject("resBuilding_25"));
      resBuilding_26.fromJson(json->GetJsonObject("resBuilding_26"));
      resBuilding_27.fromJson(json->GetJsonObject("resBuilding_27"));
      resBuilding_28.fromJson(json->GetJsonObject("resBuilding_28"));
      resBuilding_29.fromJson(json->GetJsonObject("resBuilding_29"));
      resBuilding_30.fromJson(json->GetJsonObject("resBuilding_30"));
      resBuilding_31.fromJson(json->GetJsonObject("resBuilding_31"));
      resBuilding_32.fromJson(json->GetJsonObject("resBuilding_32"));
      resBuilding_33.fromJson(json->GetJsonObject("resBuilding_33"));
      resBuilding_34.fromJson(json->GetJsonObject("resBuilding_34"));
      resBuilding_35.fromJson(json->GetJsonObject("resBuilding_35"));
      resBuilding_36.fromJson(json->GetJsonObject("resBuilding_36"));
      resBuilding_37.fromJson(json->GetJsonObject("resBuilding_37"));
    }
  } CityBuildingOuter;

  void fromJson(const XJson &json) {
    // if (json == nullptr) return;
    // idCity = json->GetInt("idCity", 0);
    // idPlayer = json->GetInt("idPlayer", 0);
    // CityBuildingFixed.fromJson(json->GetJsonObject("CityBuildingFixed"));
    // CityBuildingInner.fromJson(json->GetJsonObject("CityBuildingInner"));
    // CityBuildingOuter.fromJson(json->GetJsonObject("CityBuildingOuter"));
  }
};

struct RBuilding : public GStruct
{
	int idBuilding;
	GString BuildingName;
	GString BuildingIcon;
	GString BuildingImg;
	GString BuildingImg_byzt;
	GString BuildingBrief;
	GString UpgradeBrief;
	GString Desc;
	GString WarDesc;
	GString StarDesc;
	GString AliasName;
	struct
	{
		int32 x, y;
	} TipsOffset;

	bool bIsInnerBuilding;
	bool bCanBuild;
	GVector<RCityBtnAction> ActionBtnList;
	struct
	{
		int32 x, y;
	} offset;
	struct
	{
		int32 x, y;
	} offsetByzantine;
};

struct RBuildingSlot{
  struct RInfo{
    EBuildingIndex Index = EBuildingIndex::None;
    EBuilding BuildingId = EBuilding::None;
  } Info;
};

