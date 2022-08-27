import { ColumnOptions } from "typeorm";

export enum EBuildingType {
  None = 0,
  Castle = 101,
  Wall = 102,
  ArrowTower = 103,
  WatchTower = 104,
  Warehouse = 105,
  EventCenter = 106,
  Merchant = 107,
  Port = 108,
  TroopDetails = 109,
  Bulletin = 110,
  Embassy = 111,
  Market = 112,
  Institute = 113,
  TreasurePool = 114,
  Blacksmith = 115,
  Stable = 116,
  TargetRange = 117,
  Barrack = 118,
  Workshop = 119,
  Fortress = 120,
  DrillGrounds = 121,
  HallOfWar = 122,
  HeroTrainGround = 123,
  HeroPrison = 125,
  Farm = 201,
  LumberMill = 202,
  IronMine = 203,
  SilverMine = 204,
  MarchingTent = 205,
  FirstAidTent = 206,
  CrystalMine = 207,
  MaterialWorkShop = 210,
  Miracle = 301,
  ElitePalace = 302,
  Monument = 303,
  StarBraveStatue = 304,
  LeisureHouse = 30001,
  HIP = 30002,
  PetHouse = 30003,
  ResurrectionHall = 30004,
  ServiceCenter = 30005,
  EpicBattle = 30006

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
  default: JSON.stringify({ buildingType: EBuildingType.None, buildingLvl: 0 }),
  type: "tinytext"
}


export enum EWatchTowerEffect{

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