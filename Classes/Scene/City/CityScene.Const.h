#pragma once
#include "Include/IncludeBase.h"

namespace GCity{
  struct Const {
    int32 HuoChuang = 1999;
    int32 Gangkou = 2000;
    int32 ActivityCenter = 20001;
    int32 Wall = 20002;
    int32 CommunityCenter = 20003;
    int32 GuardSolider = 20004;
    int32 Merchant = 20005;
    int32 ConquerGate = 20006;
    int32 BulletInBoard = 20007;
    int32 PyramidBattle = 20008;
    int32 TroopFlag = 20009;
    int32 LeisureCenter = 30001;
    int32 StatuBrave = 40001;
    int32  index_Castle = 1050;
    int32  index_TurretL = 1052;
    int32  index_wall = 1053;
    int32  index_TurretR = 1054;
    int32  index_Material_WorkShop = 1151;
    int32  index_Crystal = 1152;
    int32  index_Gangkou = 2000;
    int32  index_Miracle = 1200;
    int32  index_ElitePalace = 1201;
    int32  index_MonumentRos = 1202;
    int32  index_Prison = 1203;
    int32  index_TrainHall = 1204;
    int32  index_StarBraveStatue = 1205;
    int32  index_Merchant = 20005;
    int32  index_TroopFlag = 20009;
    int32  index_LeisureCenter = 30001;
    int32  index_HuoChuang = 30002;// Sea port
    int32  index_PetCenter = 30003;
    int32  index_ResurrectionHall = 30004;
    int32  index_ServiceCenter = 30005;
    int32  index_EpicBattle  = 30006;
    int32  index_Monument    = 30007;
    int32  index_Mastery     = 30008;
    int32  index_lock_area_1 = 1220;
    int32  index_lock_area_2 = 1221;
    int32  index_lock_area_3 = 1222;
    int32  index_lock_area_4 = 1223;
    static Const *Get(){
      static Const *s_Const = new Const();
      return s_Const;
    }
  };
}