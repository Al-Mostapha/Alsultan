#pragma once
#include "Base/BaseTypeDef.h"

struct RWasteLandBossData{
    // index = 1,
    // monsterID = 6051,
    // LV = 1,
    // bosspoint = 100,
    // npc = {
    //   3143,
    //   2,
    //   1,
    //   3143,
    //   1,
    //   1,
    //   3143,
    //   1,
    //   1,
    //   3143,
    //   1,
    //   1
    // },
    // image = "shmcclr_bust.png",
    // icon = "shmcclr_full.png",
    // effects = "shmcclr",
    // name = "npc_name_039",
    // release = 1800
    int32 _Release = 0;
};

class WasteLandCtrl{
  public:
    static WasteLandCtrl* Get();
    RWasteLandBossData GetBossConfigByLv();
};