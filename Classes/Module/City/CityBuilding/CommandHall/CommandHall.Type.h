#pragma once
#include "Base/BaseTypeDef.h"
#include "CommandHall.Enum.h"

struct RCommandHallTask{
    // Index = 4093,
    // type = 4,
    // quality = 3,
    // npcId = 0,
    // recommendAdd = {},
    // recommendArmy = {},
    // relevanceTask = {},
    // buff1 = {},
    // buff2 = {},
    // nextTask = 0,
    // archeryId = 0,
    // dialogueGroup = 0,
    // shellWeight = {},
    // moveTime = 0,
    // moveType = 2,
    // moveAdd = 500,
    // injuredAdd = 0,
    // proceedReward = {
    //   500601,
    //   15,
    //   1000
    // },
    // advanceReward = {},
    // taskReward = {
    //   510004,
    //   6,
    //   1000,
    //   502702,
    //   16,
    //   1000,
    //   110201,
    //   7,
    //   1000
    // },
    // consume = 5,
    // taskExp = 100,
    // rewardNpcShow = {
    //   500601,
    //   15,
    //   510004,
    //   6,
    //   502702,
    //   16,
    //   110201,
    //   7
    // },
    // order = 0
};

struct RCommandHallShow{
    uint32 _Index = 0;
    ECommandHallTaskType _Type = ECommandHallTaskType::NONE;
    GString _Name;
    GString _Text;
    GString _Icon;
    GString _Resource;
    GString _NpcName;
    GString _NpcText;
    GString _NpcPicture;
    GString _Button;
};