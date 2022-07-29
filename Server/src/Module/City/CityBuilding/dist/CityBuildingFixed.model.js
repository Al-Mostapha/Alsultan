"use strict";
var __assign = (this && this.__assign) || function () {
    __assign = Object.assign || function(t) {
        for (var s, i = 1, n = arguments.length; i < n; i++) {
            s = arguments[i];
            for (var p in s) if (Object.prototype.hasOwnProperty.call(s, p))
                t[p] = s[p];
        }
        return t;
    };
    return __assign.apply(this, arguments);
};
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
exports.__esModule = true;
exports.CityBuildingFixedModel = void 0;
var typeorm_1 = require("typeorm");
var CityBuilding_const_1 = require("./CityBuilding.const");
var CityBuildingFixedModel = /** @class */ (function () {
    function CityBuildingFixedModel() {
    }
    __decorate([
        typeorm_1.PrimaryColumn()
    ], CityBuildingFixedModel.prototype, "idCity");
    __decorate([
        typeorm_1.Index(),
        typeorm_1.Column({ type: "int" })
    ], CityBuildingFixedModel.prototype, "idPlayer");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_Castle, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "castle");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_ArrowTower, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "arrowTowerL");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_Wall, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "wall");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_ArrowTower, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "arrowTowerR");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_WatchTower, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "watchTower");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_Merchant, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "merchant");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_Port, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "harbor");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_TroopDetails, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "troopDetail");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_LeisureHouse, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "leisureHouse");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_HeroPrison, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "prison");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_HeroTrainGround, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "trainHall");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_Miracle, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "miracle");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_StarBraveStatue, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "braveStatue");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_PetHouse, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "petCenter");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_ResurrectionHall, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "resurrectionHall");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_ServiceCenter, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "serviceCenter");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_EventCenter, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "eventCenter");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_EpicBattle, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "epicBattle");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_Monument, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "monument");
    __decorate([
        typeorm_1.Column(__assign(__assign({}, CityBuilding_const_1.BuildingColumnOption), { "default": JSON.stringify({ buildingType: CityBuilding_const_1.ECityBuildingType.CBType_ElitePalace, buildingLvl: 0 }) }))
    ], CityBuildingFixedModel.prototype, "veteransHall");
    CityBuildingFixedModel = __decorate([
        typeorm_1.Entity({
            name: "city_building_fixed"
        })
    ], CityBuildingFixedModel);
    return CityBuildingFixedModel;
}());
exports.CityBuildingFixedModel = CityBuildingFixedModel;
