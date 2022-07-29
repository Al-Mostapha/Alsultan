import { CityBuildingInnerModel } from "./CityBuilding/CityBuildingInner.model";
import { CityBuildingOuterModel } from "./CityBuilding/CityBuildingOuter.model";

export interface ICity {
    idCity: number;
    idPlayer: number;
    CityBuildingInner: CityBuildingInnerModel,
    CityBuildingOuter: CityBuildingOuterModel,
}