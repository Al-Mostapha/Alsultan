import { Module } from "@nestjs/common";
import { BuildingController } from "./Building.Controller";
import { BuildingService } from "./Building.Service";


@Module({
    imports: [],
    controllers: [BuildingController],
    providers: [BuildingService],
})
export class BuildingModule { }