import { Module } from "@nestjs/common";
import { TypeOrmModule } from "@nestjs/typeorm";
import { CityResourceController } from "./CityBuilding.controller";
import { CityResourceModel } from "./CityResource.model";
import { CityResourceService } from "./CityResource.service";


@Module({
    imports: [TypeOrmModule.forFeature([
        CityResourceModel
    ])],
    controllers: [CityResourceController],
    providers: [CityResourceService],
})
export class CityResourceModule { }