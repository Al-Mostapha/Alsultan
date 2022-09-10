import { EBuildingType } from "../Building/Building.Enum";
import { TResource } from "../Resource/Resource.Type";
import { EScienceCategory, EScienceType } from "./Science.Enum";

export interface TScience{
  index : number,
  idScience : EScienceType,
  Category : EScienceCategory,
  lvl :number,
  CostResource: TResource,
  buffType : number,
  powerNum : number,
  buffNumType : number,
  maxLvl: number,
  CostTime: number,
  CostBuilding: {
    BuildingType: EBuildingType,
    buildingLvl: number
  }
  CostStarBuid: {
    BuildingType: EBuildingType,
    buildingLvl: number
  }
  CostScience : {
    ScienceType: EScienceType,
    scienceLvl: number
  }[],
  CostScienceWEs:{
    ScienceType: EScienceType,
    scienceLvl: number
  },
  CostKingdomPoint: number,
  fighting :number ,
  
  battle: number [],
  activity: number
};