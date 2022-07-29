
import { Column, Entity, Index, PrimaryColumn } from "typeorm";
import { BuildingColumnOption, ECityBuildingType, ICityBuildingUnit } from "./CityBuilding.const";


@Entity({
    name: "city_building_fixed",
})
export class CityBuildingFixedModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_Castle, buildingLvl: 0 }) })
    castle: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_ArrowTower, buildingLvl: 0 }) })
    arrowTowerL: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_Wall, buildingLvl: 0 }) })
    wall: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_ArrowTower, buildingLvl: 0 }) })
    arrowTowerR: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_WatchTower, buildingLvl: 0 }) })
    watchTower: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_Merchant, buildingLvl: 0 }) })
    merchant: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_Port, buildingLvl: 0 }) })
    harbor: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_TroopDetails, buildingLvl: 0 }) })
    troopDetail: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_LeisureHouse, buildingLvl: 0 }) })
    leisureHouse: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_HeroPrison, buildingLvl: 0 }) })
    prison: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_HeroTrainGround, buildingLvl: 0 }) })
    trainHall: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_Miracle, buildingLvl: 0 }) })
    miracle: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_StarBraveStatue, buildingLvl: 0 }) })
    braveStatue: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_PetHouse, buildingLvl: 0 }) })
    petCenter: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_ResurrectionHall, buildingLvl: 0 }) })
    resurrectionHall: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_ServiceCenter, buildingLvl: 0 }) })
    serviceCenter: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_EventCenter, buildingLvl: 0 }) })
    eventCenter: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_EpicBattle, buildingLvl: 0 }) })
    epicBattle: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_Monument, buildingLvl: 0 }) })
    monument: ICityBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: ECityBuildingType.CBType_ElitePalace, buildingLvl: 0 }) })
    veteransHall: ICityBuildingUnit;
}