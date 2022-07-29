"use strict";
exports.__esModule = true;
exports.BuildingColumnOption = exports.EBuildingPos = exports.ECityBuildingType = void 0;
var ECityBuildingType;
(function (ECityBuildingType) {
    ECityBuildingType[ECityBuildingType["CBType_None"] = 0] = "CBType_None";
    ECityBuildingType[ECityBuildingType["CBType_Castle"] = 101] = "CBType_Castle";
    ECityBuildingType[ECityBuildingType["CBType_Wall"] = 102] = "CBType_Wall";
    ECityBuildingType[ECityBuildingType["CBType_ArrowTower"] = 103] = "CBType_ArrowTower";
    ECityBuildingType[ECityBuildingType["CBType_WatchTower"] = 104] = "CBType_WatchTower";
    ECityBuildingType[ECityBuildingType["CBType_Warehouse"] = 105] = "CBType_Warehouse";
    ECityBuildingType[ECityBuildingType["CBType_EventCenter"] = 106] = "CBType_EventCenter";
    ECityBuildingType[ECityBuildingType["CBType_Merchant"] = 107] = "CBType_Merchant";
    ECityBuildingType[ECityBuildingType["CBType_Port"] = 108] = "CBType_Port";
    ECityBuildingType[ECityBuildingType["CBType_TroopDetails"] = 109] = "CBType_TroopDetails";
    ECityBuildingType[ECityBuildingType["CBType_Bulletin"] = 110] = "CBType_Bulletin";
    ECityBuildingType[ECityBuildingType["CBType_Embassy"] = 111] = "CBType_Embassy";
    ECityBuildingType[ECityBuildingType["CBType_Market"] = 112] = "CBType_Market";
    ECityBuildingType[ECityBuildingType["CBType_Institute"] = 113] = "CBType_Institute";
    ECityBuildingType[ECityBuildingType["CBType_TreasurePool"] = 114] = "CBType_TreasurePool";
    ECityBuildingType[ECityBuildingType["CBType_Blacksmith"] = 115] = "CBType_Blacksmith";
    ECityBuildingType[ECityBuildingType["CBType_Stable"] = 116] = "CBType_Stable";
    ECityBuildingType[ECityBuildingType["CBType_TargetRange"] = 117] = "CBType_TargetRange";
    ECityBuildingType[ECityBuildingType["CBType_Barrack"] = 118] = "CBType_Barrack";
    ECityBuildingType[ECityBuildingType["CBType_Workshop"] = 119] = "CBType_Workshop";
    ECityBuildingType[ECityBuildingType["CBType_Fortress"] = 120] = "CBType_Fortress";
    ECityBuildingType[ECityBuildingType["CBType_DrillGrounds"] = 121] = "CBType_DrillGrounds";
    ECityBuildingType[ECityBuildingType["CBType_HallOfWar"] = 122] = "CBType_HallOfWar";
    ECityBuildingType[ECityBuildingType["CBType_HeroTrainGround"] = 123] = "CBType_HeroTrainGround";
    ECityBuildingType[ECityBuildingType["CBType_HeroPrison"] = 125] = "CBType_HeroPrison";
    ECityBuildingType[ECityBuildingType["CBType_Farm"] = 201] = "CBType_Farm";
    ECityBuildingType[ECityBuildingType["CBType_LumberMill"] = 202] = "CBType_LumberMill";
    ECityBuildingType[ECityBuildingType["CBType_IronMine"] = 203] = "CBType_IronMine";
    ECityBuildingType[ECityBuildingType["CBType_SilverMine"] = 204] = "CBType_SilverMine";
    ECityBuildingType[ECityBuildingType["CBType_MarchingTent"] = 205] = "CBType_MarchingTent";
    ECityBuildingType[ECityBuildingType["CBType_FirstAidTent"] = 206] = "CBType_FirstAidTent";
    ECityBuildingType[ECityBuildingType["CBType_CrystalMine"] = 207] = "CBType_CrystalMine";
    ECityBuildingType[ECityBuildingType["CBType_MaterialWorkShop"] = 210] = "CBType_MaterialWorkShop";
    ECityBuildingType[ECityBuildingType["CBType_Miracle"] = 301] = "CBType_Miracle";
    ECityBuildingType[ECityBuildingType["CBType_ElitePalace"] = 302] = "CBType_ElitePalace";
    ECityBuildingType[ECityBuildingType["CBType_Monument"] = 303] = "CBType_Monument";
    ECityBuildingType[ECityBuildingType["CBType_StarBraveStatue"] = 304] = "CBType_StarBraveStatue";
    ECityBuildingType[ECityBuildingType["CBType_LeisureHouse"] = 30001] = "CBType_LeisureHouse";
    ECityBuildingType[ECityBuildingType["CARGO_SHIP"] = 30002] = "CARGO_SHIP";
    ECityBuildingType[ECityBuildingType["CBType_PetHouse"] = 30003] = "CBType_PetHouse";
    ECityBuildingType[ECityBuildingType["CBType_ResurrectionHall"] = 30004] = "CBType_ResurrectionHall";
    ECityBuildingType[ECityBuildingType["CBType_ServiceCenter"] = 30005] = "CBType_ServiceCenter";
    ECityBuildingType[ECityBuildingType["CBType_EpicBattle"] = 30006] = "CBType_EpicBattle";
})(ECityBuildingType = exports.ECityBuildingType || (exports.ECityBuildingType = {}));
var EBuildingPos;
(function (EBuildingPos) {
    EBuildingPos[EBuildingPos["CBPlace_None"] = 0] = "CBPlace_None";
    EBuildingPos[EBuildingPos["CBPlace_Fixed"] = 1] = "CBPlace_Fixed";
    EBuildingPos[EBuildingPos["CBPlace_Inner"] = 2] = "CBPlace_Inner";
    EBuildingPos[EBuildingPos["CBPlace_Outer"] = 3] = "CBPlace_Outer";
})(EBuildingPos = exports.EBuildingPos || (exports.EBuildingPos = {}));
;
exports.BuildingColumnOption = {
    charset: "ascii",
    transformer: {
        to: function (value) { return JSON.stringify(value); },
        from: function (value) { return JSON.parse(value); }
    },
    "default": JSON.stringify({ buildingType: ECityBuildingType.CBType_None, buildingLvl: 0 }),
    type: "tinytext"
};
/**
 * BUILD_ATTR = {
  BID = "bid",
  BTYPE = "btype",
  BMAXCOUNT = "bmaxcount",
  ISDEMOLISH = "isdemolish",
  ISEXCHANGE = "isexchange",
  ISBUILD = "isbuild",
  ISUPGRADE = "isupgrade",
  INITLV = "initlv",
  MAXLV = "maxlv",
  OPENWL = "openwl",
  OPENSTAR = "openstar",
  MAXSTARLV = "maxstarlv"
}
BUILD_LVINFO = {
  BID = "bid",
  BLV = "blv",
  PRECOND = "preCond",
  PRESTAR = "prestart",
  COSTRES = "costRes",
  COSTTIME = "costTime",
  EXP = "exp",
  POWER = "power",
  KINGDOM_LV_EXP = "kingdomPoint",
  KINGDOMLV = "kingdomLv",
  ATTACK = "attack",
  DEFENSE = "defense",
  LIFE = "life",
  BSPEED = "speed",
  TRAINEXPBONUS = "trainExpBonus",
  BUILDTIME = "buildTime",
  BASEEXP = "baseexp"
}
BUILD_CASTLE_MODEL = {
  CLASSICAL = 1,
  RAMADAN = 2,
  WARLV = 3,
  SUPERVIP = 4,
  SECOND = 5,
  THREE = 6,
  NEWRAMADAN = 7,
  KOH2018RAMADAN = 8,
  EGYPT = 9,
  PANTHER = 10,
  ICESNOW = 11,
  NIGHTDX = 12,
  CRAZYSTAR = 13,
  EXQUISITE = 14,
  STREAM = 15,
  OASIS = 16,
  WORLDCUP = 17,
  WATCH = 18,
  VALENTINE = 19,
  KINGCOBRA = 20,
  FORT = 21,
  CORBAN = 22,
  CHRISTMAS = 23,
  HALLOWEEN = 24,
  CHRISTMAS2018 = 25,
  HALLOWEEN2018 = 26,
  NEWYEAR = 27,
  KOH2019RAMADAN = 28,
  HEGEMON = 29,
  LEGENDARY = 30,
  EASTER = 31,
  FOURTH = 32,
  SMAILWIND = 33,
  WARRIOR = 34,
  SCORPION = 35,
  DEGULA = 36,
  YIJICB = 37,
  REDGEM = 38,
  KINGLION = 39,
  SKYGUARD = 40,
  KOH2020RAMADAN = 41,
  CORBAN2020 = 42,
  FIFTH = 43,
  CONSTRUCTED = 44,
  GOLDENCITY = 45,
  SOARCASTLE = 46,
  ICECASTLE = 47,
  KOH2021RAMADAN = 48,
  KING = 49,
  SKYGARDEN = 50,
  THUNDERCLOUD = 51,
  CORBAN2021 = 52,
  HOURGLASS = 53,
  ICEWOLF = 54
}
BUILD_CASTLE_MODEL_DEFAULT = 1
BUILD_HUOCHUAN_TYPE = {
  NONE = 0,
  SIGN = 1,
  REWARD = 2,
  MONTHLY = 3,
  PREMIUM_VIP_MALL = 4,
  EXCLUSIVE_VIP = 5
}
 */
/**BUILD_STATE = {
  NORMAL = 0,
  BUILDING = 1,
  UPGRADEING = 2,
  DEMOLISHING = 3,
  TRAINING = 4,
  TRAP_BUILDING = 5,
  TREATING = 6,
  STUDYING = 7,
  LOCK = 8,
  ARMORFORG = 9
} */
/**BUILD_STAR_STATE = {NORMAL = 0, UPGRADEING = 1}
BUILD_COOLING_TYPE = {
  BUILD_ALL = 1,
  PROMPT_ARMY = 2,
  BUILD_MASTERY = 3,
  BUILD_STAR = 4,
  DIG_TREASURE = 5,
  BUILD_STAR_SECOND = 6,
  BUILD_STATUE_BRAVE = 7
} */
/**BUILD_OPERATE_TYPE = {
  BUILD = 0,
  DEMOLISH = 1,
  UPGRADE = 2,
  EXCHANGE = 3,
  UNLOCK = 4,
  UPGRADE_STAR = 5
}
BUILD_EXCHANGE_MODE = {
  GOLD = 0,
  TOOLS = 1,
  FREE = 2
} */ 
