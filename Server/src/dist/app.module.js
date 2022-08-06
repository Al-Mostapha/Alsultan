"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
exports.__esModule = true;
exports.AppModule = void 0;
var common_1 = require("@nestjs/common");
var typeorm_1 = require("@nestjs/typeorm");
var app_controller_1 = require("./app.controller");
var app_service_1 = require("./app.service");
var CityArmy_model_1 = require("./Module/Army/CityArmy.model");
var City_module_1 = require("./Module/City/City.module");
var CityBuildingFixed_model_1 = require("./Module/City/CityBuilding/CityBuildingFixed.model");
var CityBuildingInner_model_1 = require("./Module/City/CityBuilding/CityBuildingInner.model");
var CityBuildingOuter_model_1 = require("./Module/City/CityBuilding/CityBuildingOuter.model");
var CityResource_model_1 = require("./Module/City/CityResource/CityResource.model");
var AppModule = /** @class */ (function () {
    function AppModule() {
    }
    AppModule = __decorate([
        common_1.Module({
            imports: [
                typeorm_1.TypeOrmModule.forRoot({
                    type: 'mysql',
                    host: 'localhost',
                    port: 3306,
                    username: 'root',
                    password: '',
                    database: 'alsultan',
                    entities: [
                        CityBuildingInner_model_1.CityBuildingInnerModel,
                        CityBuildingOuter_model_1.CityBuildingOuterModel,
                        CityBuildingFixed_model_1.CityBuildingFixedModel,
                        CityArmy_model_1.CityArmyAModel,
                        CityArmy_model_1.CityArmyBModel,
                        CityArmy_model_1.CityArmyCModel,
                        CityArmy_model_1.CityArmyDModel,
                        CityArmy_model_1.CityArmyEModel,
                        CityArmy_model_1.CityArmyFModel,
                        CityArmy_model_1.CityArmyTrapModel,
                        CityResource_model_1.CityResourceModel
                    ],
                    synchronize: true,
                    logger: "advanced-console"
                }),
                City_module_1.CityModule
            ],
            controllers: [app_controller_1.AppController],
            providers: [app_service_1.AppService]
        })
    ], AppModule);
    return AppModule;
}());
exports.AppModule = AppModule;
