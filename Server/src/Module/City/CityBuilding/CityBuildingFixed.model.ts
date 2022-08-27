
import { Column, Entity, Index, PrimaryColumn } from "typeorm";
import { BuildingColumnOption, IBuildingUnit } from "src/Module/Building/Building.Type";
import { EBuildingType} from "src/Module/Building/Building.Enum";


@Entity({
    name: "city_building_fixed",
})
export class CityBuildingFixedModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.Castle, buildingLvl: 0 }) })
    castle: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.ArrowTower, buildingLvl: 0 }) })
    arrowTowerL: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.Wall, buildingLvl: 0 }) })
    wall: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.ArrowTower, buildingLvl: 0 }) })
    arrowTowerR: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.WatchTower, buildingLvl: 0 }) })
    watchTower: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.Merchant, buildingLvl: 0 }) })
    merchant: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.Port, buildingLvl: 0 }) })
    harbor: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.TroopDetails, buildingLvl: 0 }) })
    troopDetail: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.LeisureHouse, buildingLvl: 0 }) })
    leisureHouse: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.Prison, buildingLvl: 0 }) })
    prison: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.TrainHall, buildingLvl: 0 }) })
    trainHall: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.Miracle, buildingLvl: 0 }) })
    miracle: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.StarBraveStatue, buildingLvl: 0 }) })
    braveStatue: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.PetHouse, buildingLvl: 0 }) })
    petCenter: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.ResurrectionHall, buildingLvl: 0 }) })
    resurrectionHall: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.ServiceCenter, buildingLvl: 0 }) })
    serviceCenter: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.EventCenter, buildingLvl: 0 }) })
    eventCenter: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.EpicBattle, buildingLvl: 0 }) })
    epicBattle: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.Monument, buildingLvl: 0 }) })
    monument: IBuildingUnit;
    @Column({ ...BuildingColumnOption, default: JSON.stringify({ buildingType: EBuildingType.ElitePalace, buildingLvl: 0 }) })
    veteransHall: IBuildingUnit;
}