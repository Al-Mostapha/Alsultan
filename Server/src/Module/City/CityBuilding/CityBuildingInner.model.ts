
import { Column, Entity, Index, PrimaryColumn } from "typeorm";
import { BuildingColumnOption, IBuildingUnit } from "src/Module/Building/Building.Type";


@Entity({
    name: "city_building_inner",
})
export class CityBuildingInnerModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column(BuildingColumnOption)
    innerBuilding_1: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_2: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_3: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_4: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_5: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_6: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_7: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_8: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_9: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_10: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_11: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_12: IBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_13: IBuildingUnit;
}