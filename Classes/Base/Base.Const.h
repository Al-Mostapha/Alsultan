#pragma once 
#include "BaseTypeDef.h"
#include "cocos2d.h"
USING_NS_CC;

#define  RECHARGE_AD_OFFSET_Y  -78

namespace GBase{
  struct GLobalSettings{
    static bool ShowMsgTip;
  };

  struct Const{
    static Const *Get(){
      static Const *l_Instance = new Const();
      return l_Instance;
    }
    bool IsArClient = true;
    bool RamadanSwitch = false;
    int32 COMMON_CONSTANT       = 1;
    int32 BATCH_USE_MIN         = 2;
    int32 TIME_LIMITED_4_HOURS  = 4;
    int32 TIME_LIMITED_24_HOURS = 24;
    int32 TIME_LIMITED_48_HOURS = 48;
    int32 RES_MAX_IN_LOWCASTLE  = 500000;
    uint32 CastleLvl2    = 2;
    uint32 CastleLvl3    = 3;
    uint32 CastleLvl4    = 4;
    uint32 CastleLvl5    = 5;
    uint32 CastleLvl6    = 6;
    uint32 CastleLvl7    = 7;
    uint32 CastleLvl8    = 8;
    uint32 CastleLvl9    = 9;
    uint32 CastleLvl10   = 10;
    uint32 CastleLvl12   = 12;
    uint32 CastleLvl13   = 13;
    uint32 CastleLvl14   = 14;
    uint32 CastleLvl15   = 15;
    uint32 CastleLvl16   = 16;
    uint32 CastleLvl19   = 19;
    uint32 CastleLvl22   = 22;
    uint32 CastleLvl25   = 25;
    uint32 CastleLvl26   = 26;
    uint32 CastleLvl27   = 27;
    uint32 CastleLvl30   = 30;
    uint32 CastleLvl40   = 40;
    uint32 CastleLvl50   = 50;
    int32 CASTLE_LV60_LIMITED   = 60;
    int32 CASTLE_LV80_LIMITED   = 80;
    int32 CASTLE_LV90_LIMITED   = 90;
    int32 CASTLE_MAXLV_NOWAR    = 30;
    int32 CASTLE_MINLV_WAR      = 31;
    int32 CASTLE_MAXLV_WAR      = 80;
    int32 CastleMinWarLvl                = 1;
    int32 CASTLE_MAX_WARLV                = 5;
    int32 CASTLE_NEX_MAX_WARLV            = 10;
    int32 CASTLE_MAXLV_NEW_WAR            = 130;
    int32 CASTLE_STARLV56_LIMITED         = 56;
    int32 WATCH_TOWER_SCOUT_MIN_LV        = 2;
    int32 WATCH_TOWER_VIEW_ARRIVEPOS_LV   = 3;
    int32 WATCH_TOWER_VIEW_ARRIVETIME_LV  = 5;
    int32 WATCH_TOWER_VIEW_ARMYTOTALCOUNT = 7;
    int32 WATCH_TOWER_VIEW_ARMYCLASS      = 11;
    int32 WATCH_TOWER_VIEW_LORD_LV        = 13;
    int32 WATCH_TOWER_VIEW_SCIENCE        = 26;
    int32 WATCH_TOWER_VIEW_TALENT         = 29;
    int32 WALL_ADD_DEFEND_COST_TIME       = 30;
    int32 WALL_FIRE_TIME                  = 30;
    int32 WALL_DEFEND_MOVE_VALUE          = 0;
    int32 WALL_PUT_OUT_FIRE_GOLD          = 50;
    int32 MERCHANTE_REFRESH_MIN_GOLD      = 5;
    int32 PET_FEED_COUNT_ONCE             = 20;
    int32 MAX_MARCH_TROOP                 = 6;
    int32 VIP_MARCH_ADD                   = 2;
    int32 SCIENCE_MARCH_ADD               = 3;
    int32 ALLIANCE_CHANGE_RANK_MIN  = 3;
    int32 ALLIANCE_CHANGE_RANK_MAX  = 10;
    int32 ALLIANCE_NAME_MIN         = 3;
    int32 ALLIANCE_NAME_MAX         = 20;
    int32 ALLIANCE_DES_MAX          = 200;
    int32 ALLIANCE_MIN_RANK         = 1;
    int32 ALLIANCE_MAX_RANK         = 5;
    int32 ALLIANCE_BE_NEW_LORD_GOLD = 1000;
    int32 MAX_QUALITY               = 5;
    int32 MIN_QUALITY               = 1;
    int32 BG_MAX_QUALITY            = 6;
    int32 BG_MIN_QUALITY            = 1;
    int32 MAX_ARMY_LV               = 11;
    int32 BUILDER_WORK_TIME = 2;
    int32 MIN_VIP_LV_EFFECT = 4;
    int32 VIP_LV4_LIMITED   = 4;
    int32 VIP_LV5_LIMITED   = 5;
    int32 VIP_LV6_LIMITED   = 6;
    int32 VIP_LV7_LIMITED   = 7;
    int32 VIP_LV8_LIMITED   = 8;
    int32 VIP_LV9_LIMITED   = 9;
    int32 VIP_LV10_LIMITED  = 10;
    int32 VIP_LV13_LIMITED  = 13;
    int32 VIP_LV8_EFFECT    = 8;
    int32 VIP_LV9_EFFECT    = 9;
    int32 VIP_LV10_EFFECT   = 10;
    int32 VIP_LV15_EFFECT   = 15;
    int32 SVIP_LV1_EFFECT   = 16;
    int32 SVIP_LV4_EFFECT   = 19;
    int32 SVIP_LV7_EFFECT   = 22;
    int32 SVIP_LV10_LIMITED = 25;
    int32 VIP_MAX_LV        = 26;
    int32 VIP_SVIP_LV       = 15;
    int32 VIP_MIN_LV        = 1;
    int32 LORD_SKILL_QIANRU = 13032;
    int32 COMMON_PASSWORD_MIN_LEN = 6;
    int32 MIN_NICKNAME_LEN = 3;
    int32 MAX_NICKNAME_LEN = 15;
    int32 MAP_COLLECTNAME_MAX = 30;
    int32 MIN_KINGDOM_NAME_LEN = 1;
    int32 MAX_KINGDOM_NAME_LEN = 10;
    int32 MIN_FLAGTEAM_NAME_LEN = 1;
    int32 RANK_TOP_SPECIAL = 3;
    int32 RANK_ALLIANCE_MAX_SHOW = 100;
    int32 RANK_MAX_SHOW = 150;
    int32 RANK_MILITARY_MAX_SHOW = 200;
    int32 COMMON_WEEK_DAYS = 7;
    int32 TREASUREHUNT_ADD_TIMES = 101;
    int32 TREASUREHUNT_COST_GOLD_MAX = 100;
    int32 TREASUREHUNT_MIN_GOLD_COST = 2;
    int32 TREASUREHUNT_CRITICAL_MAX = 10;
    int32 MAIL_WARMING_MAX_COUNT = 80;
    int32 HP_SKILL_ADD = 30;
    int32 HP_MONSTER = -5;
    int32 HP_BOSS = -20;
    int32 HP_MIN_MONSTER_CHEST = 5;
    int32 HP_MIN_CHRISTMAS_TREE = 10;
    int32 HP_MIN_BOSS = 20;
    int32 MAX_COLLECT_NUM = 100;
    int32 MIN_CAR_LV = 1;
    int32 MAX_CAR_LV = 5;
    int32 GOLD_CAR_COST = 2500;
    int32 PYRAMID_SHOW_MIN_FLOOR = 5;
    int32 PYRAMIDBATTLE_MAX_SHOW = 2000;
    int32 DEFENDVIEW_DOWNFIRE_GOLD = 50;
    int32 KING_GIFT_RANK = 1;
    int32 ALLIANCE_GIFT_MAX_RANK = 2;
    int32 ALLIANCE_GIFT_MIN_RANK = 8;
    int32 SEARCH_MIN_LEN = 3;
    int32 MEDAL_MIN_STAR_SHOW = 3;
    int32 MEDAL_MAX_STAR_SHOW = 5;
    int32 MEDAL_TOTAL_STAR = 371;
    int32 MILITARY_MAX_LV = 13;
    int32 REDBAG_GOLD_MIN = 50;
    int32 REDBAG_GOLD_MAX = 5000;
    int32 REDBAG_GOLD_SEND_MIN = 10;
    int32 REDBAG_GOLD_SEND_MAX = 50;
    int32 GROWUPFUND_AWARD_GOLD = 52000;
    int32 VALUE_REBATE_AWARD_GOLD = 78993;
    int32 HEROTRIAL_COST_POINTS = 1;
    int32 HEROTRIAL_TOTAL_COUNT = 6;
    int32 HEROTRIAL_VIP8_GET_POINTS = 2;
    int32 LUCKYDAY_TOTAL_TIMES = 3;
    int32 LUCKYDAY_EACHTIME = 60;
    int32 TOTAL_ACTIVITY_MAX_POINTS = 10000000;
    int32 RECHARGE_ACCOUNT_FIRST_GOLD = 6000;
    int32 RECHARGE_DAY_FIRST_GOLD = 2700;
    int32 RANKING_DISPLAY_NUM = 5;
    int32 LEGEND_WASHFACE_STONE = 220006;
    int32 HEROBOSS_SINGLE_SCORE = 10;
    int32 HEROBOSS_GROUP_SCORE = 100;
    int32 DEPOT_LV_ALLIANCE_TRRASURE = 6;
    int32 ALLIANCE_TREASURE_GOLD_REFRESH = 10;
    int32 ALLIANCE_TREASURE_AWARD_MAX_COUNT = 20;
    int32 MAX_PIGEON_SEND = 10;
    int32 MAX_LORD_LV_NOLIMIT = 70;
    int32 MAX_LORD_LV = 80;
    int32 MAX_VIP_LV = 25;
    int32 MAX_NORMAL_VIP_LV = 15;
    int32 VIP_TO_SVIP_POINT = 3000000;
    int32 ARENA_DRILL_LEVELLIMIT = 16;
    int32 ARENA_GROUPCHANGE_LOCAL_COUNTS = 20;
    int32 ARENA_GROUPCHANGE_GLOBAL_COUNTS = 5;
    int32 ARENA_DAY_SEND_COUNTS = 5;
    int32 BAG_GROUP_ITEM_MAXCOUNT = 999;
    int32 BAG_ONE_ITEM_MAX_COUNT = 6000000;
    int32 ITEM_BATTLEEXCLUSIVE_SPEEDUP = 310001;
    int32 ITEM_REMAINSWAR_SPEEDUP = 310701;
    int32 ITEM_ATLANTISWAR_SPEEDUP = 311501;
    int32 RECOVER_ONE_EXPLORE_POINT_TIME = 180;
    int32 AREA_BORDER_LEN = 5;
    int32 SWEEP_COST_ACTION = 24;
    int32 EPIC_WAR_MAX_ACTION = 240;
    int32 EPIC_MAX_BUY_COUNT = 10;
    int32 MONSTER_MAX_LEVEL = 40;
    int32 LUCKY_TREASURE = 50;
    int32 MULTI_AWAKE_MIN = 2;
    int32 MULTI_AWAKE_MAX = 5;
    int32 ALLIANCE_HUNT_CASTLE_LV_MIN = 4;
    int32 EXPOSTULATION_INTERVAL = 20;
    int32 HERO_FESTIVAL_TICKET = 820301;
    int32 ALLIANCE_ACTIVE_MAX_PUBLISH_NUM = 12;
    int32 ALLIANCE_ACTIVE_PERSON_DAILY_MAX_ACCEPT_NUM = 4;
    int32 ALLIANCE_ACTIVE_JOINALLIANCE_TIME = 2;
    bool IS_FIRST_TIME_COST_GOLD_BUILDING = true;
    bool IS_SELECT_LOGIN_NOTICE = true;
    bool IS_LEVEL_4_WASH_FACE_USED_CONFIRM = false;
    bool IS_TEN_WASH_FACE_USED_CONFIRM = false;
    bool IS_COMPOUND_ORANGE_MATERIALS = false;
    bool IS_BLOCK_USERS_CHAT = true;
    bool IS_BIG_DINNER_POP_REWARD = true;
    GString InvalidName = "";
  };

  struct GameDefs {
    static GameDefs *Get() {
      static GameDefs *instance = new GameDefs();
      return instance;
    }
    bool RAMADAN_SWITCH = false;
    GString GAME_VERSION = "1.0.0";
    GVector<GString> CommonArrayImagesPath = {
      "newAndRepair/newAndRepair.plist", "CommonUI/CommonUI0.plist",
      "CommonUI/CommonUI1.plist", "Resident/frameMainUI.plist",
      "Resident/switcher.plist", "NormalUI/NormalUI0.plist",
      "NormalUI/NormalUI1.plist", "NormalUI/NormalUI2.plist",
      "NormalUI/NormalUI3.plist", "NormalUI/NormalUI4.plist"
    };
  };
};