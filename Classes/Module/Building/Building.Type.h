#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Reflect.h"
#include "Base/Json.h"
#include "Module/Building/Building.Const.h"
#include "Module/Building/Building.Enum.h"
#include "Module/CityResource/Resource.Type.h"
#include "Module/Army/Army.Enum.h"
#include "Module/Science/Science.Enum.h"
#include "Module/Building/BuildingLib/BuildingWatchTower.Lib.h"

 struct TBuildingPreCond{
    EBuildingType buildingType = EBuildingType::None;
    uint32 buildingLvl = 0;
    bool isAchieved = false;
    static TBuildingPreCond fromJson(GJson *json){
        TBuildingPreCond temp;
        
    }
};
struct TCostItem{
    uint32 idItem = 0;
    uint32 buildingLvl = 0;
    bool isAchieved = false;
};

struct TBuildingLvlSpecs{
    GVector<TBuildingPreCond> buildingPreCond;
    TResource costRes;
    GVector<TCostItem> costItems;
    GVector<TCostItem> costWEs;
    uint32 costTime = 0;
    uint32 exp = 0;
    uint32 kingdomPoint = 0;
    uint32 power = 0;
    uint32 atkAdd = 0;
    uint32 atkSpeedAdd = 0;
    uint32 baseAtkSpeed = 0;
    uint32 gunshot = 0;
    EArmyType unlockedSoldier;
    uint32 forgeSpeed = 0;
    uint32 steelReduce = 0;
    uint32 kingdomLv = 0;
    EBuildingType unlockedBuild = EBuildingType::None;
    EScienceType unlockedTechnology = EScienceType::None;
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
    TResource resCapacity;
    EWatchTowerEffect watchTowerEffect = EWatchTowerEffect::None;
    uint32 freeTime = 0;
    static TBuildingLvlSpecs fromJson(GJson *json){}

    REFLECT()  
};

struct TCityBuildingUnit 
{

    int32 buildingLvl;
    GString NodeName;
    GString BuildingPlace;
    EBuildingType eBuildingType;
    EBuildingPos eBuildingPos;
    TCityBuildingUnit(char *nodeName, char *buildingPlace, EBuildingPos eBP)
        : NodeName(nodeName), BuildingPlace(buildingPlace), eBuildingPos(eBP){};
    TCityBuildingUnit()
        : NodeName(""), BuildingPlace(""), eBuildingPos(EBuildingPos::CBPlace_Inner){};
    void fromJson(GJson *json);
    TCityBuildingUnit& buildUnit();
    TCityBuildingUnit& addToBuildingList();
};


struct TBuildingUnitSpecs{
   
    int32 index = 0;
    int32 idBuilding = 0;
    bool isDemolish = false;
    bool isExchange = false;
    bool isBuild = false;
    bool isUpgrade = false;
    EBuildingType buildingType = EBuildingType::None;
    int32 bType = 0;
    int32 maxCount = 0;
    int32 maxLvl = 0;
    int32 initLvl = 0;
    int32 openWl = 0;
    int32 openStar = 0;
    int32 maxStarLv = 0;
    bool isCanBuild = true;
    GString BuildingName  = "";
    GString BuildingIcon  = "";
    GString BuildingBrief = "";
    GString UpgradeBrief  = "";
    GString Describe      = "";
    GString WarDescribe   = "";
    GString StarDescribe  = "";
    GMap<uint32, TBuildingLvlSpecs> BuildingLvlSpecs;

    static TBuildingUnitSpecs fromJson(GJson *json){
        TBuildingUnitSpecs  temp;
        temp.index        = json->GetInt("index");
        temp.idBuilding   = json->GetInt("idBuilding");
        temp.isDemolish   = json->GetBool("isdemolish");
        temp.isExchange   = json->GetBool("isExchange");
        temp.isBuild      = json->GetBool("isBuild");
        temp.isUpgrade    = json->GetBool("isUpgrade");
        temp.buildingType = static_cast<EBuildingType>(json->GetInt("buildingType")) ;
        temp.bType        = json->GetInt("bType");
        temp.maxCount     = json->GetInt("maxCount");
        temp.maxLvl       = json->GetInt("maxLvl");
        temp.initLvl      = json->GetInt("initLvl");
        temp.openWl       = json->GetInt("openWl");
        temp.openStar     = json->GetInt("openStar");
        temp.maxStarLv    = json->GetInt("maxStarLv");
        temp.BuildingName = json->GetInt("BuildingName");
        temp.BuildingIcon = json->GetInt("BuildingIcon");
        temp.BuildingBrief= json->GetInt("BuildingBrief");
        temp.UpgradeBrief = json->GetInt("UpgradeBrief");
        temp.Describe     = json->GetInt("Describe");
        temp.WarDescribe  = json->GetInt("WarDescribe");
        temp.StarDescribe = json->GetInt("StarDescribe");
        return temp;
    }
};

struct TCityBuilding 
{
    int32 idPlayer;
    int32 idCity;
    GMap<GString, TCityBuildingUnit> BuildingList;
    struct
    {
        int idCity;
        int idPlayer;
        TCityBuildingUnit castle = TCityBuildingUnit("build_1050", "castle", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit arrowTowerL = TCityBuildingUnit("build_1052", "arrowTowerL", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit wall = TCityBuildingUnit("build_1053", "wall", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit arrowTowerR = TCityBuildingUnit("build_1054", "arrowTowerR", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit watchTower = TCityBuildingUnit("build_1055", "watchTower", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit merchant = TCityBuildingUnit("Img_Lvxingshanren", "merchant", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit harbor = TCityBuildingUnit("build_30002", "harbor", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit troopDetail = TCityBuildingUnit("Node_flag", "troopDetail", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit leisureHouse = TCityBuildingUnit("build_30001", "leisureHouse", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit prison = TCityBuildingUnit("build_1203", "prison", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit trainHall = TCityBuildingUnit("build_1204", "trainHall", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit miracle = TCityBuildingUnit("build_1200", "miracle", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit braveStatue = TCityBuildingUnit("build_1205", "braveStatue", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit petCenter = TCityBuildingUnit("build_30003", "petCenter", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit resurrectionHall = TCityBuildingUnit("build_30004", "resurrectionHall", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit serviceCenter = TCityBuildingUnit("build_30005", "serviceCenter", EBuildingPos::CBPlace_Fixed); // this is error
        TCityBuildingUnit eventCenter = TCityBuildingUnit("build_30005", "eventCenter", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit epicBattle = TCityBuildingUnit("build_30006", "epicBattle", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit monument = TCityBuildingUnit("build_30007", "Monument", EBuildingPos::CBPlace_Fixed);
        TCityBuildingUnit veteransHall = TCityBuildingUnit("build_1201", "veteransHall", EBuildingPos::CBPlace_Fixed);
        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
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

    struct
    {
        int idCity;
        int idPlayer;
        TCityBuildingUnit innerBuilding_1  = TCityBuildingUnit("build_1051", "innerBuilding_1", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_2  = TCityBuildingUnit("build_1056", "innerBuilding_2", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_3  = TCityBuildingUnit("build_1057", "innerBuilding_3", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_4  = TCityBuildingUnit("build_1058", "innerBuilding_4", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_5  = TCityBuildingUnit("build_1059", "innerBuilding_5", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_6  = TCityBuildingUnit("build_1060", "innerBuilding_6", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_7  = TCityBuildingUnit("build_1061", "innerBuilding_7", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_8  = TCityBuildingUnit("build_1062", "innerBuilding_8", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_9  = TCityBuildingUnit("build_1063", "innerBuilding_9", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_10 = TCityBuildingUnit("build_1064", "innerBuilding_10", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_11 = TCityBuildingUnit("build_1065", "innerBuilding_11", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_12 = TCityBuildingUnit("build_1066", "innerBuilding_12", EBuildingPos::CBPlace_Inner);
        TCityBuildingUnit innerBuilding_13 = TCityBuildingUnit("build_1067", "innerBuilding_13", EBuildingPos::CBPlace_Inner);

        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
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

    struct
    {
        int idCity;
        int idPlayer;
        /* Free Area*/
        TCityBuildingUnit resBuilding_1 = TCityBuildingUnit("build_1100", "resBuilding_1", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_2 = TCityBuildingUnit("build_1101", "resBuilding_2", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_3 = TCityBuildingUnit("build_1102", "resBuilding_3", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_4 = TCityBuildingUnit("build_1103", "resBuilding_4", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_5 = TCityBuildingUnit("build_1104", "resBuilding_5", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_6 = TCityBuildingUnit("build_1105", "resBuilding_6", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_7 = TCityBuildingUnit("build_1106", "resBuilding_7", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_8 = TCityBuildingUnit("build_1107", "resBuilding_8", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_9 = TCityBuildingUnit("build_1108", "resBuilding_9", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_10 = TCityBuildingUnit("build_1109", "resBuilding_10", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_11 = TCityBuildingUnit("build_1110", "resBuilding_11", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_12 = TCityBuildingUnit("build_1111", "resBuilding_12", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_13 = TCityBuildingUnit("build_1112", "resBuilding_13", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_14 = TCityBuildingUnit("build_1113", "resBuilding_14", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_15 = TCityBuildingUnit("build_1114", "resBuilding_15", EBuildingPos::CBPlace_Outer);

        // First Locked Area Panel_Area_Lock_1220
        TCityBuildingUnit resBuilding_16 = TCityBuildingUnit("build_1115", "resBuilding_16", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_17 = TCityBuildingUnit("build_1116", "resBuilding_17", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_18 = TCityBuildingUnit("build_1117", "resBuilding_18", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_19 = TCityBuildingUnit("build_1118", "resBuilding_19", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_20 = TCityBuildingUnit("build_1119", "resBuilding_20", EBuildingPos::CBPlace_Outer);
        // secound Locked Area Panel_Area_Lock_1223
        TCityBuildingUnit resBuilding_21 = TCityBuildingUnit("build_1130", "resBuilding_21", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_22 = TCityBuildingUnit("build_1131", "resBuilding_22", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_23 = TCityBuildingUnit("build_1132", "resBuilding_23", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_24 = TCityBuildingUnit("build_1133", "resBuilding_24", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_25 = TCityBuildingUnit("build_1134", "resBuilding_25", EBuildingPos::CBPlace_Outer);
        // Third Locked Area Panel_Area_Lock_1222
        TCityBuildingUnit resBuilding_26 = TCityBuildingUnit("build_1125", "resBuilding_26", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_27 = TCityBuildingUnit("build_1126", "resBuilding_27", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_28 = TCityBuildingUnit("build_1127", "resBuilding_28", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_29 = TCityBuildingUnit("build_1128", "resBuilding_29", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_30 = TCityBuildingUnit("build_1129", "resBuilding_30", EBuildingPos::CBPlace_Outer);
        // Forth Locked Area Panel_Area_Lock_1221
        TCityBuildingUnit resBuilding_31 = TCityBuildingUnit("build_1120", "resBuilding_31", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_32 = TCityBuildingUnit("build_1121", "resBuilding_32", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_33 = TCityBuildingUnit("build_1122", "resBuilding_33", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_34 = TCityBuildingUnit("build_1123", "resBuilding_34", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_35 = TCityBuildingUnit("build_1124", "resBuilding_35", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_36 = TCityBuildingUnit("build_1151", "resBuilding_36", EBuildingPos::CBPlace_Outer);
        TCityBuildingUnit resBuilding_37 = TCityBuildingUnit("build_1152", "resBuilding_37", EBuildingPos::CBPlace_Outer);
        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
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

    void fromJson(GJson *json)
    {
        if (json == nullptr)
            return;
        idCity = json->GetInt("idCity", 0);
        idPlayer = json->GetInt("idPlayer", 0);
        CityBuildingFixed.fromJson(json->GetJsonObject("CityBuildingFixed"));
        CityBuildingInner.fromJson(json->GetJsonObject("CityBuildingInner"));
        CityBuildingOuter.fromJson(json->GetJsonObject("CityBuildingOuter"));
    }
};

