import { Module } from "@nestjs/common";
import { BuildingController } from "./Building.controller";
import { BuildingService } from "./Building.service";


@Module({
    imports: [],
    controllers: [BuildingController],
    providers: [BuildingService],
})
export class BuildingModule { }