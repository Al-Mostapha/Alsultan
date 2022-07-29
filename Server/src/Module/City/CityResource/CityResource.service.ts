import { Injectable } from "@nestjs/common";
import { InjectRepository } from "@nestjs/typeorm";
import { Repository } from "typeorm";
import { CityResourceModel } from "./CityResource.model";

@Injectable()
export class CityResourceService {

    constructor(
        @InjectRepository(CityResourceModel)
        private RCityResource: Repository<CityResourceModel>
    ) { }

    getCityResource(idPlayer: number, idCity: number): Promise<CityResourceModel> {
        return this.RCityResource.findOne({
            where: {
                idPlayer, idCity
            }
        })
    }
}