"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
exports.__esModule = true;
exports.CityBuildingOuterModel = void 0;
var typeorm_1 = require("typeorm");
var Building_Const_1 = require("src/Module/Building/Building.Const");
var CityBuildingOuterModel = /** @class */ (function () {
    function CityBuildingOuterModel() {
    }
    __decorate([
        typeorm_1.PrimaryColumn()
    ], CityBuildingOuterModel.prototype, "idCity");
    __decorate([
        typeorm_1.Index(),
        typeorm_1.Column({ type: "int" })
    ], CityBuildingOuterModel.prototype, "idPlayer");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_1");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_2");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_3");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_4");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_5");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_6");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_7");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_8");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_9");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_10");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_11");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_12");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_13");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_14");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_15");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_16");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_17");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_18");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_19");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_20");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_21");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_22");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_23");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_24");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_25");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_26");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_27");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_28");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_29");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_30");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_31");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_32");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_33");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_34");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_35");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_36");
    __decorate([
        typeorm_1.Column(Building_Const_1.BuildingColumnOption)
    ], CityBuildingOuterModel.prototype, "resBuilding_37");
    CityBuildingOuterModel = __decorate([
        typeorm_1.Entity({
            name: "city_building_outer"
        })
    ], CityBuildingOuterModel);
    return CityBuildingOuterModel;
}());
exports.CityBuildingOuterModel = CityBuildingOuterModel;
