import { Module } from "@nestjs/common";
import { TypeOrmModule } from "@nestjs/typeorm";
import { CityBuildingController } from "./CityBuilding.controller";
import { CityBuildingService } from "./CityBuilding.service";
import { CityBuildingFixedModel } from "./CityBuildingFixed.model";
import { CityBuildingInnerModel } from "./CityBuildingInner.model";
import { CityBuildingOuterModel } from "./CityBuildingOuter.model";


@Module({
    imports: [TypeOrmModule.forFeature([
        CityBuildingInnerModel,
        CityBuildingOuterModel,
        CityBuildingFixedModel
    ])],
    controllers: [CityBuildingController],
    providers: [CityBuildingService],
})
export class CityBuildingModule { }