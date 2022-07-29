import { Injectable } from "@nestjs/common";
import { InjectRepository } from "@nestjs/typeorm";
import { Repository } from "typeorm";
import { CityBuildingFixedModel } from "./CityBuildingFixed.model";
import { CityBuildingInnerModel } from "./CityBuildingInner.model";
import { CityBuildingOuterModel } from "./CityBuildingOuter.model";

@Injectable()
export class CityBuildingService {

    constructor(
        @InjectRepository(CityBuildingInnerModel)
        private RCityBuildingInner: Repository<CityBuildingInnerModel>,
        @InjectRepository(CityBuildingOuterModel)
        private RCityBuildingOuter: Repository<CityBuildingOuterModel>,
        @InjectRepository(CityBuildingFixedModel)
        private RCityBuildingFixed: Repository<CityBuildingFixedModel>,
    ) { }

    getCityBuildingInner(idPlayer: number, idCity: number): Promise<CityBuildingInnerModel> {
        return this.RCityBuildingInner.findOne({
            where: {
                idPlayer: idPlayer,
                idCity: idCity,
            }
        });
    }
    getCityBuildingOuter(idPlayer: number, idCity: number): Promise<CityBuildingOuterModel> {
        return this.RCityBuildingOuter.findOne({
            where: {
                idPlayer: idPlayer,
                idCity: idCity,
            }
        });
    }
    getCityBuildingFixed(idPlayer: number, idCity: number): Promise<CityBuildingFixedModel> {
        return this.RCityBuildingFixed.findOne({
            where: {
                idPlayer: idPlayer,
                idCity: idCity,
            }
        });
    }
}