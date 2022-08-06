import { ColumnOptions } from "typeorm";

export enum EBuildingType {
  CBType_None = 0,
  CBType_Castle = 101,
  CBType_Wall = 102,
  CBType_ArrowTower = 103,
  CBType_WatchTower = 104,
  CBType_Warehouse = 105,
  CBType_EventCenter = 106,
  CBType_Merchant = 107,
  CBType_Port = 108,
  CBType_TroopDetails = 109,
  CBType_Bulletin = 110,
  CBType_Embassy = 111,
  CBType_Market = 112,
  CBType_Institute = 113,
  CBType_TreasurePool = 114,
  CBType_Blacksmith = 115,
  CBType_Stable = 116,
  CBType_TargetRange = 117,
  CBType_Barrack = 118,
  CBType_Workshop = 119,
  CBType_Fortress = 120,
  CBType_DrillGrounds = 121,
  CBType_HallOfWar = 122,
  CBType_HeroTrainGround = 123,
  CBType_HeroPrison = 125,
  CBType_Farm = 201,
  CBType_LumberMill = 202,
  CBType_IronMine = 203,
  CBType_SilverMine = 204,
  CBType_MarchingTent = 205,
  CBType_FirstAidTent = 206,

  CBType_CrystalMine = 207,
  CBType_MaterialWorkShop = 210,
  CBType_Miracle = 301,
  CBType_ElitePalace = 302,
  CBType_Monument = 303,
  CBType_StarBraveStatue = 304,

  CBType_LeisureHouse = 30001,
  CARGO_SHIP = 30002,
  CBType_PetHouse = 30003,
  CBType_ResurrectionHall = 30004,
  CBType_ServiceCenter = 30005,
  CBType_EpicBattle = 30006

}

export enum EBuildingPos {
  CBPlace_None = 0,
  CBPlace_Fixed = 1,
  CBPlace_Inner = 2,
  CBPlace_Outer = 3,
};

/**gCityWallStatus = {
  NORMAL = 1,
  DAMAGE = 2,
  DESTRUCTION = 3
} */


export interface IBuildingUnit {
  buildingType: EBuildingType;
  buildingLvl: number;
}

export const BuildingColumnOption: ColumnOptions = {
  charset: "ascii",
  transformer: {
    to: (value: IBuildingUnit) => JSON.stringify(value),
    from: (value: string) => JSON.parse(value)
  },
  default: JSON.stringify({ buildingType: EBuildingType.CBType_None, buildingLvl: 0 }),
  type: "tinytext"
}




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