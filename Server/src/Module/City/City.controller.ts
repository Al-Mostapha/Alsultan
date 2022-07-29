import { Controller, Get } from "@nestjs/common";
import { ICity } from "./City.const";
import { CityBuildingService } from "./CityBuilding/CityBuilding.service";

@Controller("api/City")
export class CityController {
    constructor(private SCityBuilding: CityBuildingService) { }


}