import { Module } from "@nestjs/common";
import { TypeOrmModule } from "@nestjs/typeorm";
import { CityArmyController } from "./CityArmy.controller";
import { CityArmyAModel, CityArmyBModel, CityArmyCModel, CityArmyDModel, CityArmyEModel, CityArmyFModel, CityArmyTrapModel } from "./CityArmy.model";
import { CityArmyService } from "./CityArmy.service";


@Module({
    imports: [TypeOrmModule.forFeature([
        CityArmyAModel,
        CityArmyBModel,
        CityArmyCModel,
        CityArmyDModel,
        CityArmyEModel,
        CityArmyFModel,
        CityArmyTrapModel
    ])],
    controllers: [CityArmyController],
    providers: [CityArmyService],
})
export class CityArmyModule { }