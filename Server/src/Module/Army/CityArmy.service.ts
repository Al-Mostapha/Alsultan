import { Injectable } from "@nestjs/common";
import { InjectRepository } from "@nestjs/typeorm";
import { Repository } from "typeorm";
import { CityArmyAModel, CityArmyBModel, CityArmyCModel, CityArmyDModel, CityArmyEModel, CityArmyFModel, CityArmyTrapModel } from "./CityArmy.model";

@Injectable()
export class CityArmyService {

    constructor(
        @InjectRepository(CityArmyAModel)
        private RCityArmyA: Repository<CityArmyAModel>,
        @InjectRepository(CityArmyBModel)
        private RCityArmyB: Repository<CityArmyBModel>,
        @InjectRepository(CityArmyCModel)
        private RCityArmyC: Repository<CityArmyCModel>,
        @InjectRepository(CityArmyDModel)
        private RCityArmyD: Repository<CityArmyDModel>,
        @InjectRepository(CityArmyEModel)
        private RCityArmyE: Repository<CityArmyEModel>,
        @InjectRepository(CityArmyFModel)
        private RCityArmyF: Repository<CityArmyFModel>,
        @InjectRepository(CityArmyTrapModel)
        private RCityArmyTrap: Repository<CityArmyTrapModel>
    ) { }

    async getCityArmy(idPlayer: number, idCity: number) {
        const Cond = {
            where: {
                idPlayer, idCity
            }
        };
        return {
            ArmyA: await this.RCityArmyA.findOne(Cond),
            ArmyB: await this.RCityArmyB.findOne(Cond),
            ArmyC: await this.RCityArmyC.findOne(Cond),
            ArmyD: await this.RCityArmyD.findOne(Cond),
            ArmyE: await this.RCityArmyE.findOne(Cond),
            ArmyF: await this.RCityArmyF.findOne(Cond),
            ArmyTrap: await this.RCityArmyTrap.findOne(Cond)
        }
    }

}