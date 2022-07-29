import { Controller, Get } from "@nestjs/common";
import { CityResourceService } from "./CityResource.service";


@Controller("api/CityResource")
export class CityResourceController {
    constructor(
        private SCityResource: CityResourceService
    ) { }

    @Get("getCityResource")
    async getCityResource() {
        const idPlayer = 1;
        const idCity = 1;

        return {
            state: "ok",
            CityResource: await this.SCityResource.getCityResource(idPlayer, idCity)
        }
    }
}