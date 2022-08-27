import { ColumnOptions } from "typeorm";
import { EArmyType } from "src/Module/Army/Army.Enum";
import { EBuildingType, EWatchTowerEffect } from "./Building.Enum";
import { EScienceType } from "../Science/Science.Enum";


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





export type IReqBuilding = {
  preCond: {
      buildingType: EBuildingType,
      buildingLvl: number
    }[],
  costRes: { 
    Grain: number,
    Lumber: number,
    Iron: number,
    Silver: number,
    Crystal: number
  },
  costTime: number,
  exp: number,
  kingdomPoint: number,
  power: number,
  costTools?: { idItem: number, amount: number }[],
  costWEs?: { idItem: number, amount: number }[],
  atkAdd?: number,
  atkSpeedAdd?: number,
  baseAtkSpeed?: number,
  gunshot?: number,
  unlockedSoldier?: EArmyType,
  forgeSpeed?: number,
  steelReduce?: number,
  kingdomLv?: number,
  unlockedBuild?: EBuildingType,
  unlockedTechnology?:EScienceType,
  capacity?: number,
  output?:number,
  addOutputCostGold?:number,
  maxSoldier?: number,
  ElitePointLimit?: number,
  helpCount?: number,
  reduceTime?: number,
  reinforcements?: number,
  prisonNum?: number,
  attack?: number,
  defense?: number,
  life?: number,
  speed?: number,
  speedTime?: number,
  heroNum?: number,
  trainExpBonus?:number,
  buildTime?: number,
  baseExp?: number,
  taxRate?: number,
  trainSpeed?: number,
  unlockDescribe?: string,
  defValue?: number,
  resCapacity?:  { 
    Grain: number,
    Lumber: number,
    Iron: number,
    Silver: number,
    Metal: number,
    Crystal: number
  },
  watchTowerEffect?: EWatchTowerEffect,
  freeTime?: number
};


export interface IBuildingInfoUnit {
  index: number;
  idBuilding: number;
  buildingType: EBuildingType;
  bType: number;
  maxCount: number;
  isDemolish: boolean;
  isExchange: boolean;
  isBuild: boolean;
  isUpgrade: boolean;
  maxLvl: number;
  initLvl: number
  openWl: number;
  openStar: number;
  maxStarLvl: number;
  BuildingName: string,
  BuildingIcon: string,
  BuildingBrief: string,
  UpgradeBrief: string,
  Describe: string,
  WarDescribe: string,
  StarDescribe: string,
  BuildingReq: {[Key: number]: IReqBuilding}
}
