import { Module } from "@nestjs/common";
import { TypeOrmModule } from "@nestjs/typeorm";
import { CityArmyModule } from "../Army/CityArmy.module";
import { CityController } from "./City.controller";
import { CityService } from "./City.service";
import { CityBuildingModule } from "./CityBuilding/CityBuilding.module";
import { CityBuildingService } from "./CityBuilding/CityBuilding.service";
import { CityBuildingFixedModel } from "./CityBuilding/CityBuildingFixed.model";
import { CityBuildingInnerModel } from "./CityBuilding/CityBuildingInner.model";
import { CityBuildingOuterModel } from "./CityBuilding/CityBuildingOuter.model";
import { CityResourceModule } from "./CityResource/CityBuilding.module";


@Module({
    imports: [
        CityBuildingModule,
        CityArmyModule,
        CityResourceModule,
        TypeOrmModule.forFeature([
            CityBuildingInnerModel,
            CityBuildingOuterModel,
            CityBuildingFixedModel
        ])
    ],
    controllers: [CityController],
    providers: [
        CityService,
        CityBuildingService,
    ],
})
export class CityModule { }