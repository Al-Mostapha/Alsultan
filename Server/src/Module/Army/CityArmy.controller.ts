import { Controller, Get } from "@nestjs/common";
import { CityArmyService } from "./CityArmy.service";

@Controller("api/CityArmy")
export class CityArmyController {

    constructor(private readonly SArmyCity: CityArmyService) { }

    @Get("getCityArmy")
    async getCityArmy() {
        const idPlayer = 1;
        const idCity = 1;
        return {
            state: "ok",
            CityArmy: await this.SArmyCity.getCityArmy(idPlayer, idCity)
        }
    }
}