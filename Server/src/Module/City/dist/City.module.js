"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
exports.__esModule = true;
exports.CityModule = void 0;
var common_1 = require("@nestjs/common");
var typeorm_1 = require("@nestjs/typeorm");
var CityArmy_module_1 = require("../Army/CityArmy.module");
var Building_module_1 = require("../Building/Building.module");
var City_controller_1 = require("./City.controller");
var City_service_1 = require("./City.service");
var CityBuilding_module_1 = require("./CityBuilding/CityBuilding.module");
var CityBuilding_service_1 = require("./CityBuilding/CityBuilding.service");
var CityBuildingFixed_model_1 = require("./CityBuilding/CityBuildingFixed.model");
var CityBuildingInner_model_1 = require("./CityBuilding/CityBuildingInner.model");
var CityBuildingOuter_model_1 = require("./CityBuilding/CityBuildingOuter.model");
var CityBuilding_module_2 = require("./CityResource/CityBuilding.module");
var CityModule = /** @class */ (function () {
    function CityModule() {
    }
    CityModule = __decorate([
        common_1.Module({
            imports: [
                CityBuilding_module_1.CityBuildingModule,
                CityArmy_module_1.CityArmyModule,
                CityBuilding_module_2.CityResourceModule,
                Building_module_1.BuildingModule,
                typeorm_1.TypeOrmModule.forFeature([
                    CityBuildingInner_model_1.CityBuildingInnerModel,
                    CityBuildingOuter_model_1.CityBuildingOuterModel,
                    CityBuildingFixed_model_1.CityBuildingFixedModel
                ])
            ],
            controllers: [City_controller_1.CityController],
            providers: [
                City_service_1.CityService,
                CityBuilding_service_1.CityBuildingService,
            ]
        })
    ], CityModule);
    return CityModule;
}());
exports.CityModule = CityModule;
