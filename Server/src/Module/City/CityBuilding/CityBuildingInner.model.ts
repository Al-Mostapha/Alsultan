
import { Column, Entity, Index, PrimaryColumn } from "typeorm";
import { BuildingColumnOption, ECityBuildingType, ICityBuildingUnit } from "./CityBuilding.const";


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
    innerBuilding_1: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_2: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_3: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_4: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_5: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_6: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_7: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_8: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_9: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_10: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_11: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_12: ICityBuildingUnit;
    @Column(BuildingColumnOption)
    innerBuilding_13: ICityBuildingUnit;
}