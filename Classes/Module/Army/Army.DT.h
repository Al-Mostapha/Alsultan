#pragma once
#include "Include/IncludeBase.h"

struct TCityArmy
{
    int32 idPlayer;
    int32 idCity;
    struct
    {
        int32 idPlayer;
        int32 idCity;
        int32 armyA_1;
        int32 armyA_2;
        int32 armyA_3;
        int32 armyA_4;
        int32 armyA_5;
        int32 armyA_6;
        int32 armyA_7;
        int32 armyA_8;
        int32 armyA_9;
        int32 armyA_10;
        int32 armyA_11;
        int32 armyA_12;
        int32 armyA_13;
        int32 armyA_14;
        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
            idPlayer = json->GetInt("idPlayer");
            idCity = json->GetInt("idCity");
            armyA_1 = json->GetInt("armyA_1");
            armyA_2 = json->GetInt("armyA_2");
            armyA_3 = json->GetInt("armyA_3");
            armyA_4 = json->GetInt("armyA_4");
            armyA_5 = json->GetInt("armyA_5");
            armyA_6 = json->GetInt("armyA_6");
            armyA_7 = json->GetInt("armyA_7");
            armyA_8 = json->GetInt("armyA_8");
            armyA_9 = json->GetInt("armyA_9");
            armyA_10 = json->GetInt("armyA_10");
            armyA_11 = json->GetInt("armyA_11");
            armyA_12 = json->GetInt("armyA_12");
            armyA_13 = json->GetInt("armyA_13");
            armyA_14 = json->GetInt("armyA_14");
        };
    } ArmyA;

    struct
    {
        int32 idPlayer;
        int32 idCity;
        int32 armyB_1;
        int32 armyB_2;
        int32 armyB_3;
        int32 armyB_4;
        int32 armyB_5;
        int32 armyB_6;
        int32 armyB_7;
        int32 armyB_8;
        int32 armyB_9;
        int32 armyB_10;
        int32 armyB_11;
        int32 armyB_12;
        int32 armyB_13;
        int32 armyB_14;
        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
            idPlayer = json->GetInt("idPlayer");
            idCity = json->GetInt("idCity");
            armyB_1 = json->GetInt("armyB_1");
            armyB_2 = json->GetInt("armyB_2");
            armyB_3 = json->GetInt("armyB_3");
            armyB_4 = json->GetInt("armyB_4");
            armyB_5 = json->GetInt("armyB_5");
            armyB_6 = json->GetInt("armyB_6");
            armyB_7 = json->GetInt("armyB_7");
            armyB_8 = json->GetInt("armyB_8");
            armyB_9 = json->GetInt("armyB_9");
            armyB_10 = json->GetInt("armyB_10");
            armyB_11 = json->GetInt("armyB_11");
            armyB_12 = json->GetInt("armyB_12");
            armyB_13 = json->GetInt("armyB_13");
            armyB_14 = json->GetInt("armyB_14");
        };
    } ArmyB;

    struct
    {
        int32 idPlayer;
        int32 idCity;
        int32 armyC_1;
        int32 armyC_2;
        int32 armyC_3;
        int32 armyC_4;
        int32 armyC_5;
        int32 armyC_6;
        int32 armyC_7;
        int32 armyC_8;
        int32 armyC_9;
        int32 armyC_10;
        int32 armyC_11;
        int32 armyC_12;
        int32 armyC_13;
        int32 armyC_14;
        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
            idPlayer = json->GetInt("idPlayer");
            idCity = json->GetInt("idCity");
            armyC_1 = json->GetInt("armyC_1");
            armyC_2 = json->GetInt("armyC_2");
            armyC_3 = json->GetInt("armyC_3");
            armyC_4 = json->GetInt("armyC_4");
            armyC_5 = json->GetInt("armyC_5");
            armyC_6 = json->GetInt("armyC_6");
            armyC_7 = json->GetInt("armyC_7");
            armyC_8 = json->GetInt("armyC_8");
            armyC_9 = json->GetInt("armyC_9");
            armyC_10 = json->GetInt("armyC_10");
            armyC_11 = json->GetInt("armyC_11");
            armyC_12 = json->GetInt("armyC_12");
            armyC_13 = json->GetInt("armyC_13");
            armyC_14 = json->GetInt("armyC_14");
        };
    } ArmyC;

    struct
    {
        int32 idPlayer;
        int32 idCity;
        int32 armyD_1;
        int32 armyD_2;
        int32 armyD_3;
        int32 armyD_4;
        int32 armyD_5;
        int32 armyD_6;
        int32 armyD_7;
        int32 armyD_8;
        int32 armyD_9;
        int32 armyD_10;
        int32 armyD_11;
        int32 armyD_12;
        int32 armyD_13;
        int32 armyD_14;
        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
            idPlayer = json->GetInt("idPlayer");
            idCity = json->GetInt("idCity");
            armyD_1 = json->GetInt("armyD_1");
            armyD_2 = json->GetInt("armyD_2");
            armyD_3 = json->GetInt("armyD_3");
            armyD_4 = json->GetInt("armyD_4");
            armyD_5 = json->GetInt("armyD_5");
            armyD_6 = json->GetInt("armyD_6");
            armyD_7 = json->GetInt("armyD_7");
            armyD_8 = json->GetInt("armyD_8");
            armyD_9 = json->GetInt("armyD_9");
            armyD_10 = json->GetInt("armyD_10");
            armyD_11 = json->GetInt("armyD_11");
            armyD_12 = json->GetInt("armyD_12");
            armyD_13 = json->GetInt("armyD_13");
            armyD_14 = json->GetInt("armyD_14");
        };
    } ArmyD;

    struct
    {
        int32 idPlayer;
        int32 idCity;
        int32 armyE_1;
        int32 armyE_2;
        int32 armyE_3;
        int32 armyE_4;
        int32 armyE_5;
        int32 armyE_6;
        int32 armyE_7;
        int32 armyE_8;
        int32 armyE_9;
        int32 armyE_10;
        int32 armyE_11;
        int32 armyE_12;
        int32 armyE_13;
        int32 armyE_14;
        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
            idPlayer = json->GetInt("idPlayer");
            idCity = json->GetInt("idCity");
            armyE_1 = json->GetInt("armyE_1");
            armyE_2 = json->GetInt("armyE_2");
            armyE_3 = json->GetInt("armyE_3");
            armyE_4 = json->GetInt("armyE_4");
            armyE_5 = json->GetInt("armyE_5");
            armyE_6 = json->GetInt("armyE_6");
            armyE_7 = json->GetInt("armyE_7");
            armyE_8 = json->GetInt("armyE_8");
            armyE_9 = json->GetInt("armyE_9");
            armyE_10 = json->GetInt("armyE_10");
            armyE_11 = json->GetInt("armyE_11");
            armyE_12 = json->GetInt("armyE_12");
            armyE_13 = json->GetInt("armyE_13");
            armyE_14 = json->GetInt("armyE_14");
        };
    } ArmyE;

    struct
    {
        int32 idPlayer;
        int32 idCity;
        int32 armyF_1;
        int32 armyF_2;
        int32 armyF_3;
        int32 armyF_4;
        int32 armyF_5;
        int32 armyF_6;
        int32 armyF_7;
        int32 armyF_8;
        int32 armyF_9;
        int32 armyF_10;
        int32 armyF_11;
        int32 armyF_12;
        int32 armyF_13;
        int32 armyF_14;
        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
            idPlayer = json->GetInt("idPlayer");
            idCity = json->GetInt("idCity");
            armyF_1 = json->GetInt("armyF_1");
            armyF_2 = json->GetInt("armyF_2");
            armyF_3 = json->GetInt("armyF_3");
            armyF_4 = json->GetInt("armyF_4");
            armyF_5 = json->GetInt("armyF_5");
            armyF_6 = json->GetInt("armyF_6");
            armyF_7 = json->GetInt("armyF_7");
            armyF_8 = json->GetInt("armyF_8");
            armyF_9 = json->GetInt("armyF_9");
            armyF_10 = json->GetInt("armyF_10");
            armyF_11 = json->GetInt("armyF_11");
            armyF_12 = json->GetInt("armyF_12");
            armyF_13 = json->GetInt("armyF_13");
            armyF_14 = json->GetInt("armyF_14");
        };
    } ArmyF;

    struct
    {
        int32 idPlayer;
        int32 idCity;
        int32 armyTrapA_1;
        int32 armyTrapA_2;
        int32 armyTrapA_3;
        int32 armyTrapA_4;
        int32 armyTrapA_5;
        int32 armyTrapB_1;
        int32 armyTrapB_2;
        int32 armyTrapB_3;
        int32 armyTrapB_4;
        int32 armyTrapB_5;
        int32 armyTrapC_1;
        int32 armyTrapC_2;
        int32 armyTrapC_3;
        int32 armyTrapC_4;
        int32 armyTrapC_5;
        void fromJson(GJson *json)
        {
            if (json == nullptr)
                return;
            idPlayer = json->GetInt("idPlayer");
            idCity = json->GetInt("idCity");
            armyTrapA_1 = json->GetInt("armyTrapA_1");
            armyTrapA_2 = json->GetInt("armyTrapA_2");
            armyTrapA_3 = json->GetInt("armyTrapA_3");
            armyTrapA_4 = json->GetInt("armyTrapA_4");
            armyTrapA_5 = json->GetInt("armyTrapA_5");
            armyTrapB_1 = json->GetInt("armyTrapB_1");
            armyTrapB_2 = json->GetInt("armyTrapB_2");
            armyTrapB_3 = json->GetInt("armyTrapB_3");
            armyTrapB_4 = json->GetInt("armyTrapB_4");
            armyTrapB_5 = json->GetInt("armyTrapB_5");
            armyTrapC_1 = json->GetInt("armyTrapC_1");
            armyTrapC_2 = json->GetInt("armyTrapC_2");
            armyTrapC_3 = json->GetInt("armyTrapC_3");
            armyTrapC_4 = json->GetInt("armyTrapC_4");
            armyTrapC_5 = json->GetInt("armyTrapC_5");
        };
    } ArmyTrap;

    void fromJson(GJson *json)
    {
        if (json == nullptr)
            return;
        ArmyA.fromJson(json->GetJsonObject("ArmyA"));
        ArmyB.fromJson(json->GetJsonObject("ArmyB"));
        ArmyC.fromJson(json->GetJsonObject("ArmyC"));
        ArmyD.fromJson(json->GetJsonObject("ArmyD"));
        ArmyE.fromJson(json->GetJsonObject("ArmyE"));
        ArmyF.fromJson(json->GetJsonObject("ArmyF"));
        ArmyTrap.fromJson(json->GetJsonObject("ArmyTrap"));
    }
};