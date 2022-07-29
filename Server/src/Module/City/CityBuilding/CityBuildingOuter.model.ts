
import { Column, Entity, Index, PrimaryColumn } from "typeorm";
import { BuildingColumnOption, ICityBuildingUnit } from "./CityBuilding.const";






@Entity({
    name: "city_building_outer",
})
export class CityBuildingOuterModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;

    @Column(BuildingColumnOption)
    resBuilding_1: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_2: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_3: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_4: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_5: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_6: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_7: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_8: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_9: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_10: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_11: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_12: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_13: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_14: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_15: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_16: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_17: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_18: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_19: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_20: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_21: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_22: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_23: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_24: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_25: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_26: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_27: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_28: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_29: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_30: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_31: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_32: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_33: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_34: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_35: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_36: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_37: ICityBuildingUnit;
}