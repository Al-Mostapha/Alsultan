"use strict";
var __decorate = (this && this.__decorate) || function (decorators, target, key, desc) {
    var c = arguments.length, r = c < 3 ? target : desc === null ? desc = Object.getOwnPropertyDescriptor(target, key) : desc, d;
    if (typeof Reflect === "object" && typeof Reflect.decorate === "function") r = Reflect.decorate(decorators, target, key, desc);
    else for (var i = decorators.length - 1; i >= 0; i--) if (d = decorators[i]) r = (c < 3 ? d(r) : c > 3 ? d(target, key, r) : d(target, key)) || r;
    return c > 3 && r && Object.defineProperty(target, key, r), r;
};
exports.__esModule = true;
exports.CityResourceModel = void 0;
var typeorm_1 = require("typeorm");
var CityResourceModel = /** @class */ (function () {
    function CityResourceModel() {
    }
    __decorate([
        typeorm_1.PrimaryColumn()
    ], CityResourceModel.prototype, "idCity");
    __decorate([
        typeorm_1.Index(),
        typeorm_1.Column({ type: "int" })
    ], CityResourceModel.prototype, "idPlayer");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "coin");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "food");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "wood");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "silver");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "iron");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "crystal");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "coinIn");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "foodIn");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "woodIn");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "silverIn");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "ironIn");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "crystalIn");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "coinOut");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "foodOut");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "woodOut");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "silverOut");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "ironOut");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "crystalOut");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "coinCap");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "foodCap");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "woodCap");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "silverCap");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "ironCap");
    __decorate([
        typeorm_1.Column({ type: "int", "default": 0, nullable: false })
    ], CityResourceModel.prototype, "crystalCap");
    CityResourceModel = __decorate([
        typeorm_1.Entity({
            name: "city_resource"
        })
    ], CityResourceModel);
    return CityResourceModel;
}());
exports.CityResourceModel = CityResourceModel;
