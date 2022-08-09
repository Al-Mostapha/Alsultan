import { Controller, Get } from "@nestjs/common";
import { CityBuildingService } from "./CityBuilding.service";

@Controller("api/CityBuilding")
export class CityBuildingController {
    constructor(
        private SCityBuilding: CityBuildingService
    ) { }

    @Get("fetchCityBuilding")
    async fetchCityBuilding() {
        const idPlayer = 1;
        const idCity = 1;

        return {
            state: "ok",
            CityBuilding: {
                idPlayer, idCity,
                CityBuildingInner: await this.SCityBuilding.getCityBuildingInner(idPlayer, idCity),
                CityBuildingOuter: await this.SCityBuilding.getCityBuildingOuter(idPlayer, idCity),
                CityBuildingFixed: await this.SCityBuilding.getCityBuildingFixed(idPlayer, idCity)
            }
        }
    }
}