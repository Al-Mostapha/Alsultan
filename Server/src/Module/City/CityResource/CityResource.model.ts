
import { Column, Entity, Index, PrimaryColumn } from "typeorm";



@Entity({
    name: "city_resource",
})
export class CityResourceModel {
    @PrimaryColumn()
    idCity: number;
    @Index()
    @Column({ type: "int" })
    idPlayer: number;
    @Column({ type: "int", default: 0, nullable: false })
    coin: number;
    @Column({ type: "int", default: 0, nullable: false })
    food: number;
    @Column({ type: "int", default: 0, nullable: false })
    wood: number;
    @Column({ type: "int", default: 0, nullable: false })
    silver: number;
    @Column({ type: "int", default: 0, nullable: false })
    iron: number;
    @Column({ type: "int", default: 0, nullable: false })
    crystal: number;
    @Column({ type: "int", default: 0, nullable: false })
    coinIn: number;
    @Column({ type: "int", default: 0, nullable: false })
    foodIn: number;
    @Column({ type: "int", default: 0, nullable: false })
    woodIn: number;
    @Column({ type: "int", default: 0, nullable: false })
    silverIn: number;
    @Column({ type: "int", default: 0, nullable: false })
    ironIn: number;
    @Column({ type: "int", default: 0, nullable: false })
    crystalIn: number;
    @Column({ type: "int", default: 0, nullable: false })
    coinOut: number;
    @Column({ type: "int", default: 0, nullable: false })
    foodOut: number;
    @Column({ type: "int", default: 0, nullable: false })
    woodOut: number;
    @Column({ type: "int", default: 0, nullable: false })
    silverOut: number;
    @Column({ type: "int", default: 0, nullable: false })
    ironOut: number;
    @Column({ type: "int", default: 0, nullable: false })
    crystalOut: number;
    @Column({ type: "int", default: 0, nullable: false })
    coinCap: number;
    @Column({ type: "int", default: 0, nullable: false })
    foodCap: number;
    @Column({ type: "int", default: 0, nullable: false })
    woodCap: number;
    @Column({ type: "int", default: 0, nullable: false })
    silverCap: number;
    @Column({ type: "int", default: 0, nullable: false })
    ironCap: number;
    @Column({ type: "int", default: 0, nullable: false })
    crystalCap: number;
}