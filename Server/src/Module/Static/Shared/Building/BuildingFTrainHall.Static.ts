import { IReqBuilding } from "src/Module/Building/Building.Type";
import { EBuildingType } from "src/Module/Building/Building.Enum";


export const BuildingFTrainHallStatic: {[Key: number] : IReqBuilding} = {
    1: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 7 }],
        costRes: { Grain: 0, Lumber: 0, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 0,
        exp: 0,
        kingdomPoint: 0,
        power: 6,
        trainExpBonus: 100,
        buildTime: 3600,
        baseExp: 200
    },
    2: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 7 }],
        costRes: { Grain: 700, Lumber: 700, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 50,
        exp: 3,
        kingdomPoint: 12,
        power: 17,
        trainExpBonus: 110,
        buildTime: 3600,
        baseExp: 200
    },
    3: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 7 }],
        costRes: { Grain: 1000, Lumber: 1000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 70,
        exp: 5,
        kingdomPoint: 25,
        power: 36,
        trainExpBonus: 120,
        buildTime: 3600,
        baseExp: 200
    },
    4: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 7 }],
        costRes: { Grain: 1500, Lumber: 1500, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 370,
        exp: 18,
        kingdomPoint: 94,
        power: 70,
        trainExpBonus: 130,
        buildTime: 3600,
        baseExp: 200
    },
    5: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 7 }],
        costRes: { Grain: 2500, Lumber: 2500, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 900,
        exp: 35,
        kingdomPoint: 233,
        power: 132,
        trainExpBonus: 140,
        buildTime: 3600,
        baseExp: 200
    },
    6: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 7 }],
        costRes: { Grain: 4250, Lumber: 4250, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 1800,
        exp: 69,
        kingdomPoint: 480,
        power: 240,
        trainExpBonus: 150,
        buildTime: 3600,
        baseExp: 200
    },
    7: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 7 }],
        costRes: { Grain: 8750, Lumber: 8750, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 3600,
        exp: 104,
        kingdomPoint: 986,
        power: 402,
        trainExpBonus: 160,
        buildTime: 3600,
        baseExp: 200
    },
    8: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 8 }],
        costRes: { Grain: 16250, Lumber: 16250, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 4950,
        exp: 142,
        kingdomPoint: 1393,
        power: 623,
        trainExpBonus: 170,
        buildTime: 3600,
        baseExp: 200
    },
    9: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 9 }],
        costRes: { Grain: 32250, Lumber: 32250, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 6670,
        exp: 191,
        kingdomPoint: 1928,
        power: 883,
        trainExpBonus: 180,
        buildTime: 3600,
        baseExp: 200
    },
    10: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 10 }],
        costRes: { Grain: 62500, Lumber: 62500, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 9070,
        exp: 260,
        kingdomPoint: 2688,
        power: 1190,
        trainExpBonus: 190,
        buildTime: 3600,
        baseExp: 200
    },
    11: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 11 }],
        costRes: { Grain: 100000, Lumber: 100000, Iron: 10000, Silver: 0, Crystal: 0 },
        costTime: 12300,
        exp: 352,
        kingdomPoint: 3735,
        power: 1550,
        trainExpBonus: 200,
        buildTime: 3600,
        baseExp: 200
    },
    12: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 12 }],
        costRes: { Grain: 200000, Lumber: 200000, Iron: 20000, Silver: 0, Crystal: 0 },
        costTime: 16720,
        exp: 479,
        kingdomPoint: 5203,
        power: 1991,
        trainExpBonus: 210,
        buildTime: 3600,
        baseExp: 200
    },
    13: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 13 }],
        costRes: { Grain: 382500, Lumber: 382500, Iron: 38250, Silver: 0, Crystal: 0 },
        costTime: 22500,
        exp: 644,
        kingdomPoint: 7166,
        power: 2530,
        trainExpBonus: 220,
        buildTime: 3600,
        baseExp: 200
    },
    14: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 14 }],
        costRes: { Grain: 687500, Lumber: 687500, Iron: 68750, Silver: 0, Crystal: 0 },
        costTime: 30600,
        exp: 875,
        kingdomPoint: 9973,
        power: 3188,
        trainExpBonus: 230,
        buildTime: 3600,
        baseExp: 200
    },
    15: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 15 }],
        costRes: { Grain: 1050000, Lumber: 1050000, Iron: 105000, Silver: 0, Crystal: 0 },
        costTime: 41400,
        exp: 1184,
        kingdomPoint: 13800,
        power: 3992,
        trainExpBonus: 240,
        buildTime: 3600,
        baseExp: 200
    },
    16: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 16 }],
        costRes: { Grain: 1375000, Lumber: 1375000, Iron: 137500, Silver: 8500, Crystal: 0 },
        costTime: 55800,
        exp: 1595,
        kingdomPoint: 19013,
        power: 4976,
        trainExpBonus: 250,
        buildTime: 3600,
        baseExp: 200
    },
    17: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 17 }],
        costRes: { Grain: 1925000, Lumber: 1925000, Iron: 192500, Silver: 12000, Crystal: 0 },
        costTime: 75600,
        exp: 2161,
        kingdomPoint: 26320,
        power: 6177,
        trainExpBonus: 260,
        buildTime: 3600,
        baseExp: 200
    },
    18: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 18 }],
        costRes: { Grain: 2500000, Lumber: 2500000, Iron: 250000, Silver: 15500, Crystal: 0 },
        costTime: 86400,
        exp: 2469,
        kingdomPoint: 30720,
        power: 7645,
        trainExpBonus: 270,
        buildTime: 3600,
        baseExp: 200
    },
    19: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 19 }],
        costRes: { Grain: 3250000, Lumber: 3250000, Iron: 325000, Silver: 20250, Crystal: 0 },
        costTime: 97200,
        exp: 2778,
        kingdomPoint: 35280,
        power: 9438,
        trainExpBonus: 280,
        buildTime: 3600,
        baseExp: 200
    },
    20: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 20 }],
        costRes: { Grain: 4000000, Lumber: 4000000, Iron: 400000, Silver: 25000, Crystal: 0 },
        costTime: 110700,
        exp: 3164,
        kingdomPoint: 41000,
        power: 11631,
        trainExpBonus: 300,
        buildTime: 3600,
        baseExp: 200
    },
    21: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 21 }],
        costRes: { Grain: 5000000, Lumber: 5000000, Iron: 500000, Silver: 31250, Crystal: 0 },
        costTime: 126900,
        exp: 3626,
        kingdomPoint: 47000,
        power: 14117,
        trainExpBonus: 320,
        buildTime: 3600,
        baseExp: 200
    },
    22: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 22 }],
        costRes: { Grain: 6250000, Lumber: 6250000, Iron: 625000, Silver: 39000, Crystal: 0 },
        costTime: 145800,
        exp: 4166,
        kingdomPoint: 54000,
        power: 16936,
        trainExpBonus: 340,
        buildTime: 3600,
        baseExp: 200
    },
    23: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 23 }],
        costRes: { Grain: 7500000, Lumber: 7500000, Iron: 750000, Silver: 46750, Crystal: 0 },
        costTime: 167400,
        exp: 4784,
        kingdomPoint: 62000,
        power: 20132,
        trainExpBonus: 360,
        buildTime: 3600,
        baseExp: 200
    },
    24: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 24 }],
        costRes: { Grain: 10000000, Lumber: 10000000, Iron: 1000000, Silver: 62500, Crystal: 0 },
        costTime: 192600,
        exp: 5504,
        kingdomPoint: 71333,
        power: 23758,
        trainExpBonus: 380,
        buildTime: 3600,
        baseExp: 200
    },
    25: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 25 }],
        costRes: { Grain: 13750000, Lumber: 13750000, Iron: 1375000, Silver: 85750, Crystal: 0 },
        costTime: 221400,
        exp: 6326,
        kingdomPoint: 82000,
        power: 27868,
        trainExpBonus: 400,
        buildTime: 3600,
        baseExp: 200
    },
    26: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 26 }],
        costRes: { Grain: 18750000, Lumber: 18750000, Iron: 1875000, Silver: 117000, Crystal: 0 },
        costTime: 253800,
        exp: 7252,
        kingdomPoint: 94000,
        power: 32531,
        trainExpBonus: 420,
        buildTime: 3600,
        baseExp: 200
    },
    27: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 27 }],
        costRes: { Grain: 25000000, Lumber: 25000000, Iron: 2500000, Silver: 156250, Crystal: 0 },
        costTime: 289800,
        exp: 8281,
        kingdomPoint: 107333,
        power: 37817,
        trainExpBonus: 440,
        buildTime: 3600,
        baseExp: 200
    },
    28: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 28 }],
        costRes: { Grain: 32500000, Lumber: 32500000, Iron: 3250000, Silver: 203000, Crystal: 0 },
        costTime: 329400,
        exp: 9412,
        kingdomPoint: 122000,
        power: 43812,
        trainExpBonus: 460,
        buildTime: 3600,
        baseExp: 200
    },
    29: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 29 }],
        costRes: { Grain: 42500000, Lumber: 42500000, Iron: 4250000, Silver: 265500, Crystal: 0 },
        costTime: 372600,
        exp: 10646,
        kingdomPoint: 138000,
        power: 50610,
        trainExpBonus: 480,
        buildTime: 3600,
        baseExp: 200
    },
    30: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 30 }],
        costRes: { Grain: 55000000, Lumber: 55000000, Iron: 5500000, Silver: 343750, Crystal: 0 },
        costTime: 426600,
        exp: 12189,
        kingdomPoint: 158000,
        power: 58320,
        trainExpBonus: 500,
        buildTime: 3600,
        baseExp: 200
    }
};