import { Controller, Get } from "@nestjs/common";
import { BuildingService } from "./Building.Service";
import { BuildingInfo} from "src/Module/Static/Shared/Building/Building.Info";

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