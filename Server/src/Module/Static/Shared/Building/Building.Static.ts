import { EBuildingType, EWatchTowerEffect } from "src/Module/Building/Building.Const";
import { EArmyType } from "../Army/Static.Army";
import { EScienceType } from "../Science/Static.Science";



type IReqBuilding = {
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
  costTools?: { idTool: number, amount: number }[],
  costWEs?: { idTool: number, amount: number }[],
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

export { IReqBuilding };