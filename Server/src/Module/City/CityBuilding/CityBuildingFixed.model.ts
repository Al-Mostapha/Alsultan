
import { Column, Entity, Index, PrimaryColumn } from "typeorm";
import { BuildingColumnOption, EBuildingType, IBuildingUnit } from "src/Module/Building/Building.Const";


@Entity({
    name: "city_building_fixed",
})
export class CityBuildingFixedModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_Castle, buildingLvl: 0 }) })
    castle: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_ArrowTower, buildingLvl: 0 }) })
    arrowTowerL: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_Wall, buildingLvl: 0 }) })
    wall: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_ArrowTower, buildingLvl: 0 }) })
    arrowTowerR: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_WatchTower, buildingLvl: 0 }) })
    watchTower: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_Merchant, buildingLvl: 0 }) })
    merchant: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_Port, buildingLvl: 0 }) })
    harbor: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_TroopDetails, buildingLvl: 0 }) })
    troopDetail: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_LeisureHouse, buildingLvl: 0 }) })
    leisureHouse: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_HeroPrison, buildingLvl: 0 }) })
    prison: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_HeroTrainGround, buildingLvl: 0 }) })
    trainHall: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_Miracle, buildingLvl: 0 }) })
    miracle: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_StarBraveStatue, buildingLvl: 0 }) })
    braveStatue: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_PetHouse, buildingLvl: 0 }) })
    petCenter: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_ResurrectionHall, buildingLvl: 0 }) })
    resurrectionHall: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_ServiceCenter, buildingLvl: 0 }) })
    serviceCenter: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_EventCenter, buildingLvl: 0 }) })
    eventCenter: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_EpicBattle, buildingLvl: 0 }) })
    epicBattle: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_Monument, buildingLvl: 0 }) })
    monument: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.CBType_ElitePalace, buildingLvl: 0 }) })
    veteransHall: IBuildingUnit;
}