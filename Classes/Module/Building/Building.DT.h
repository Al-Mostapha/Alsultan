#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Json.h"
#include "Module/Building/Building.Const.h"

struct DSCityBuildingUnit
{

    int32 buildingLvl;
    GString NodeName;
    GString BuildingPlace;
    EBuildingType eBuildingType;
    EBuildingPos eBuildingPos;

    DSCityBuildingUnit(char *nodeName, char *buildingPlace, EBuildingPos eBP)
        : NodeName(nodeName), BuildingPlace(buildingPlace), eBuildingPos(eBP){};
    DSCityBuildingUnit(){};
    void fromJson(GJson *json);
    void buildUnit();
};

struct DSCityBuilding
{
    int32 idPlayer;
    int32 idCity;
    struct
    {
        int idCity;
        int idPlayer;
        DSCityBuildingUnit castle = DSCityBuildingUnit("build_1050", "castle", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit arrowTowerL = DSCityBuildingUnit("build_1052", "arrowTowerL", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit wall = DSCityBuildingUnit("build_1053", "wall", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit arrowTowerR = DSCityBuildingUnit("build_1054", "arrowTowerR", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit watchTower = DSCityBuildingUnit("build_1055", "watchTower", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit merchant = DSCityBuildingUnit("Img_Lvxingshanren", "merchant", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit harbor = DSCityBuildingUnit("build_30002", "harbor", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit troopDetail = DSCityBuildingUnit("Node_flag", "troopDetail", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit leisureHouse = DSCityBuildingUnit("build_30001", "leisureHouse", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit prison = DSCityBuildingUnit("build_1203", "prison", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit trainHall = DSCityBuildingUnit("build_1204", "trainHall", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit miracle = DSCityBuildingUnit("build_1200", "miracle", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit braveStatue = DSCityBuildingUnit("build_1205", "braveStatue", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit petCenter = DSCityBuildingUnit("build_30003", "petCenter", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit resurrectionHall = DSCityBuildingUnit("build_30004", "resurrectionHall", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit eventCenter = DSCityBuildingUnit("build_30005", "eventCenter", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit epicBattle = DSCityBuildingUnit("build_30006", "epicBattle", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit monument = DSCityBuildingUnit("build_30007", "Monument", EBuildingPos::CBPlace_Fixed);
        DSCityBuildingUnit veteransHall = DSCityBuildingUnit("build_1201", "veteransHall", EBuildingPos::CBPlace_Fixed);
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
        DSCityBuildingUnit innerBuilding_1 = DSCityBuildingUnit("build_1051", "innerBuilding_1", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_2 = DSCityBuildingUnit("build_1056", "innerBuilding_2", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_3 = DSCityBuildingUnit("build_1057", "innerBuilding_3", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_4 = DSCityBuildingUnit("build_1058", "innerBuilding_4", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_5 = DSCityBuildingUnit("build_1059", "innerBuilding_5", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_6 = DSCityBuildingUnit("build_1060", "innerBuilding_6", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_7 = DSCityBuildingUnit("build_1061", "innerBuilding_7", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_8 = DSCityBuildingUnit("build_1062", "innerBuilding_8", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_9 = DSCityBuildingUnit("build_1063", "innerBuilding_9", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_10 = DSCityBuildingUnit("build_1064", "innerBuilding_10", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_11 = DSCityBuildingUnit("build_1065", "innerBuilding_11", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_12 = DSCityBuildingUnit("build_1066", "innerBuilding_12", EBuildingPos::CBPlace_Inner);
        DSCityBuildingUnit innerBuilding_13 = DSCityBuildingUnit("build_1067", "innerBuilding_13", EBuildingPos::CBPlace_Inner);

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
        DSCityBuildingUnit resBuilding_1 = DSCityBuildingUnit("build_1100", "resBuilding_1", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_2 = DSCityBuildingUnit("build_1101", "resBuilding_2", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_3 = DSCityBuildingUnit("build_1102", "resBuilding_3", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_4 = DSCityBuildingUnit("build_1103", "resBuilding_4", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_5 = DSCityBuildingUnit("build_1104", "resBuilding_5", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_6 = DSCityBuildingUnit("build_1105", "resBuilding_6", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_7 = DSCityBuildingUnit("build_1106", "resBuilding_7", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_8 = DSCityBuildingUnit("build_1107", "resBuilding_8", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_9 = DSCityBuildingUnit("build_1108", "resBuilding_9", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_10 = DSCityBuildingUnit("build_1109", "resBuilding_10", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_11 = DSCityBuildingUnit("build_1110", "resBuilding_11", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_12 = DSCityBuildingUnit("build_1111", "resBuilding_12", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_13 = DSCityBuildingUnit("build_1112", "resBuilding_13", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_14 = DSCityBuildingUnit("build_1113", "resBuilding_14", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_15 = DSCityBuildingUnit("build_1114", "resBuilding_15", EBuildingPos::CBPlace_Outer);

        // First Locked Area Panel_Area_Lock_1220
        DSCityBuildingUnit resBuilding_16 = DSCityBuildingUnit("build_1115", "resBuilding_16", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_17 = DSCityBuildingUnit("build_1116", "resBuilding_17", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_18 = DSCityBuildingUnit("build_1117", "resBuilding_18", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_19 = DSCityBuildingUnit("build_1118", "resBuilding_19", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_20 = DSCityBuildingUnit("build_1119", "resBuilding_20", EBuildingPos::CBPlace_Outer);
        // secound Locked Area Panel_Area_Lock_1223
        DSCityBuildingUnit resBuilding_21 = DSCityBuildingUnit("build_1130", "resBuilding_21", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_22 = DSCityBuildingUnit("build_1131", "resBuilding_22", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_23 = DSCityBuildingUnit("build_1132", "resBuilding_23", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_24 = DSCityBuildingUnit("build_1133", "resBuilding_24", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_25 = DSCityBuildingUnit("build_1134", "resBuilding_25", EBuildingPos::CBPlace_Outer);
        // Third Locked Area Panel_Area_Lock_1222
        DSCityBuildingUnit resBuilding_26 = DSCityBuildingUnit("build_1125", "resBuilding_26", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_27 = DSCityBuildingUnit("build_1126", "resBuilding_27", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_28 = DSCityBuildingUnit("build_1127", "resBuilding_28", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_29 = DSCityBuildingUnit("build_1128", "resBuilding_29", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_30 = DSCityBuildingUnit("build_1129", "resBuilding_30", EBuildingPos::CBPlace_Outer);
        // Forth Locked Area Panel_Area_Lock_1221
        DSCityBuildingUnit resBuilding_31 = DSCityBuildingUnit("build_1120", "resBuilding_31", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_32 = DSCityBuildingUnit("build_1121", "resBuilding_32", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_33 = DSCityBuildingUnit("build_1122", "resBuilding_33", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_34 = DSCityBuildingUnit("build_1123", "resBuilding_34", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_35 = DSCityBuildingUnit("build_1124", "resBuilding_35", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_36 = DSCityBuildingUnit("build_1151", "resBuilding_36", EBuildingPos::CBPlace_Outer);
        DSCityBuildingUnit resBuilding_37 = DSCityBuildingUnit("build_1152", "resBuilding_37", EBuildingPos::CBPlace_Outer);
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
