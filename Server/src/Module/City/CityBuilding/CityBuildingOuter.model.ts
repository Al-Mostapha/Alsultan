
import { Column, Entity, Index, PrimaryColumn } from "typeorm";
import { BuildingColumnOption, IBuildingUnit } from "src/Module/Building/Building.Type";






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
    resBuilding_1: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_2: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_3: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_4: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_5: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_6: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_7: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_8: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_9: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_10: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_11: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_12: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_13: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_14: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_15: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_16: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_17: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_18: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_19: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_20: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_21: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_22: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_23: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_24: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_25: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_26: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_27: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_28: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_29: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_30: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_31: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_32: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_33: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_34: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_35: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_36: IBuildingUnit;
    @Column(BuildingColumnOption)
    resBuilding_37: IBuildingUnit;
}