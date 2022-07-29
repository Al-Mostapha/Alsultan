
import { Column, Entity, Index, PrimaryColumn } from "typeorm";



@Entity({
    name: "city_army_a",
})
export class CityArmyAModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_1: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_2: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_3: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_4: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_5: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_6: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_7: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_8: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_9: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_10: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_11: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_12: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_13: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyA_14: number;
}


@Entity({
    name: "city_army_b",
})
export class CityArmyBModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_1: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_2: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_3: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_4: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_5: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_6: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_7: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_8: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_9: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_10: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_11: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_12: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_13: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyB_14: number;
}

@Entity({
    name: "city_army_c",
})
export class CityArmyCModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_1: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_2: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_3: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_4: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_5: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_6: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_7: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_8: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_9: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_10: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_11: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_12: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_13: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyC_14: number;
}

@Entity({
    name: "city_army_d",
})
export class CityArmyDModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_1: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_2: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_3: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_4: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_5: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_6: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_7: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_8: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_9: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_10: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_11: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_12: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_13: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyD_14: number;
}

@Entity({
    name: "city_army_e",
})
export class CityArmyEModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_1: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_2: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_3: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_4: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_5: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_6: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_7: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_8: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_9: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_10: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_11: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_12: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_13: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyE_14: number;
}

@Entity({
    name: "city_army_f",
})
export class CityArmyFModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_1: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_2: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_3: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_4: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_5: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_6: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_7: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_8: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_9: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_10: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_11: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_12: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_13: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyF_14: number;
}


@Entity({
    name: "city_army_trap",
})
export class CityArmyTrapModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapA_1: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapA_2: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapA_3: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapA_4: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapA_5: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapB_1: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapB_2: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapB_3: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapB_4: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapB_5: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapC_1: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapC_2: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapC_3: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapC_4: number;
    @Column({ type: "int", default: 0, nullable: false })
    armyTrapC_5: number;

}