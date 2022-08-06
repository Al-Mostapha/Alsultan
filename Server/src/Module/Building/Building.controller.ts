import { Controller, Get } from "@nestjs/common";
import { BuildingService } from "./Building.service";
import { BuildingInfo, IBuildingInfoUnit } from "./Config/BuildingInfo.config";

@Controller("api/Building")
export class BuildingController {
    constructor(
        private SBuilding: BuildingService
    ) { }

    @Get("fetchBuildingInfo")
    async fetchBuildingInfo() {
        return {
            state: "ok",
            BuildingInfo
        }
    }
}