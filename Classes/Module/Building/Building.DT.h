#include "Base/BaseTypeDef.h"
#include "Base/Json.h"
#include "Module/Building/Building.Const.h"

struct DSCityBuildingUnit
{
    int32 buildingLvl;
    EBuildingType buildingType;
    void fromJson(GJson *json)
    {
        if (json == nullptr)
            return;
        buildingLvl = json->GetInt("buildingLvl", 0);
        buildingType = static_cast<EBuildingType>(json->GetInt("buildingType", 0));
    }
};

struct DSCityBuilding
{
    int32 idPlayer;
    int32 idCity;
    struct
    {
        int idCity;
        int idPlayer;
        DSCityBuildingUnit castle;
        DSCityBuildingUnit wall;
        DSCityBuildingUnit arrowTower;
        DSCityBuildingUnit watchTower;
        DSCityBuildingUnit merchant;
        DSCityBuildingUnit harbor;
        DSCityBuildingUnit troopDetail;
        DSCityBuildingUnit leisureHouse;
        DSCityBuildingUnit statue;
        DSCityBuildingUnit petCenter;
        DSCityBuildingUnit eventCenter;
        DSCityBuildingUnit veteransHall;
        DSCityBuildingUnit innerBuilding_1;
        DSCityBuildingUnit innerBuilding_2;
        DSCityBuildingUnit innerBuilding_3;
        DSCityBuildingUnit innerBuilding_4;
        DSCityBuildingUnit innerBuilding_5;
        DSCityBuildingUnit innerBuilding_6;
        DSCityBuildingUnit innerBuilding_7;
        DSCityBuildingUnit innerBuilding_8;
        DSCityBuildingUnit innerBuilding_9;
        DSCityBuildingUnit innerBuilding_10;
        DSCityBuildingUnit innerBuilding_11;
        DSCityBuildingUnit innerBuilding_12;
        DSCityBuildingUnit innerBuilding_13;
        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
            idCity = json->GetInt("idCity", 0);
            idPlayer = json->GetInt("idPlayer", 0);
            castle.fromJson(json->GetJsonObject("castle"));
            wall.fromJson(json->GetJsonObject("wall"));
            arrowTower.fromJson(json->GetJsonObject("arrowTower"));
            watchTower.fromJson(json->GetJsonObject("watchTower"));
            merchant.fromJson(json->GetJsonObject("merchant"));
            harbor.fromJson(json->GetJsonObject("harbor"));
            troopDetail.fromJson(json->GetJsonObject("troopDetail"));
            leisureHouse.fromJson(json->GetJsonObject("leisureHouse"));
            statue.fromJson(json->GetJsonObject("statue"));
            petCenter.fromJson(json->GetJsonObject("petCenter"));
            eventCenter.fromJson(json->GetJsonObject("eventCenter"));
            veteransHall.fromJson(json->GetJsonObject("veteransHall"));
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
        DSCityBuildingUnit resBuilding_1;
        DSCityBuildingUnit resBuilding_2;
        DSCityBuildingUnit resBuilding_3;
        DSCityBuildingUnit resBuilding_4;
        DSCityBuildingUnit resBuilding_5;
        DSCityBuildingUnit resBuilding_6;
        DSCityBuildingUnit resBuilding_7;
        DSCityBuildingUnit resBuilding_8;
        DSCityBuildingUnit resBuilding_9;
        DSCityBuildingUnit resBuilding_10;
        DSCityBuildingUnit resBuilding_11;
        DSCityBuildingUnit resBuilding_12;
        DSCityBuildingUnit resBuilding_13;
        DSCityBuildingUnit resBuilding_14;
        DSCityBuildingUnit resBuilding_15;
        DSCityBuildingUnit resBuilding_16;
        DSCityBuildingUnit resBuilding_17;
        DSCityBuildingUnit resBuilding_18;
        DSCityBuildingUnit resBuilding_19;
        DSCityBuildingUnit resBuilding_20;
        DSCityBuildingUnit resBuilding_21;
        DSCityBuildingUnit resBuilding_22;
        DSCityBuildingUnit resBuilding_23;
        DSCityBuildingUnit resBuilding_24;
        DSCityBuildingUnit resBuilding_25;
        DSCityBuildingUnit resBuilding_26;
        DSCityBuildingUnit resBuilding_27;
        DSCityBuildingUnit resBuilding_28;
        DSCityBuildingUnit resBuilding_29;
        DSCityBuildingUnit resBuilding_30;
        DSCityBuildingUnit outerBuilding_1;
        DSCityBuildingUnit outerBuilding_2;
        DSCityBuildingUnit outerBuilding_3;
        DSCityBuildingUnit outerBuilding_4;
        DSCityBuildingUnit outerBuilding_5;
        DSCityBuildingUnit outerBuilding_6;
        DSCityBuildingUnit outerBuilding_7;
        DSCityBuildingUnit outerBuilding_8;
        DSCityBuildingUnit outerBuilding_9;
        DSCityBuildingUnit outerBuilding_10;
        DSCityBuildingUnit outerBuilding_11;
        DSCityBuildingUnit outerBuilding_12;
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
            outerBuilding_1.fromJson(json->GetJsonObject("outerBuilding_1"));
            outerBuilding_2.fromJson(json->GetJsonObject("outerBuilding_2"));
            outerBuilding_3.fromJson(json->GetJsonObject("outerBuilding_3"));
            outerBuilding_4.fromJson(json->GetJsonObject("outerBuilding_4"));
            outerBuilding_5.fromJson(json->GetJsonObject("outerBuilding_5"));
            outerBuilding_6.fromJson(json->GetJsonObject("outerBuilding_6"));
            outerBuilding_7.fromJson(json->GetJsonObject("outerBuilding_7"));
            outerBuilding_8.fromJson(json->GetJsonObject("outerBuilding_8"));
            outerBuilding_9.fromJson(json->GetJsonObject("outerBuilding_9"));
            outerBuilding_10.fromJson(json->GetJsonObject("outerBuilding_10"));
            outerBuilding_11.fromJson(json->GetJsonObject("outerBuilding_11"));
            outerBuilding_12.fromJson(json->GetJsonObject("outerBuilding_12"));
        }
    } CityBuildingOuter;

    void fromJson(GJson *json)
    {
        if (json == nullptr)
            return;
        idCity = json->GetInt("idCity", 0);
        idPlayer = json->GetInt("idPlayer", 0);
        CityBuildingInner.fromJson(json->GetJsonObject("CityBuildingInner"));
        CityBuildingOuter.fromJson(json->GetJsonObject("CityBuildingOuter"));
    }
};
