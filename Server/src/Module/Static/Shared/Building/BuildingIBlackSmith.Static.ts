import { IReqBuilding } from "src/Module/Building/Building.Type";
import { EBuildingType } from "src/Module/Building/Building.Enum";


export const BuildingIBlackSmithStatic: {[Key: number] : IReqBuilding} = {
    1: {
        preCond: [],
        costRes: { Grain: 0, Lumber: 0, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 0,
        exp: 0,
        kingdomPoint: 0,
        power: 5,
        forgeSpeed: 50,
        steelReduce: 10
    },
    2: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 10 }],
        costRes: { Grain: 1000, Lumber: 1400, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 120,
        exp: 10,
        kingdomPoint: 28,
        power: 15,
        forgeSpeed: 100,
        steelReduce: 20
    },
    3: {
        preCond: [{ buildingType: 101, buildingLvl: 10 }],
        costRes: { Grain: 1300, Lumber: 1900, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 270,
        exp: 16,
        kingdomPoint: 65,
        power: 35,
        forgeSpeed: 150,
        steelReduce: 30
    },
    4: {
        preCond: [{ buildingType: 101, buildingLvl: 10 }],
        costRes: { Grain: 1700, Lumber: 2600, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 975,
        exp: 49,
        kingdomPoint: 245,
        power: 70,
        forgeSpeed: 200,
        steelReduce: 40
    },
    5: {
        preCond: [{ buildingType: 101, buildingLvl: 10 }],
        costRes: { Grain: 2500, Lumber: 4000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 2340,
        exp: 94,
        kingdomPoint: 606,
        power: 135,
        forgeSpeed: 250,
        steelReduce: 50
    },
    6: {
        preCond: [{ buildingType: 101, buildingLvl: 10 }],
        costRes: { Grain: 3900, Lumber: 6400, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 4680,
        exp: 183,
        kingdomPoint: 1246,
        power: 250,
        forgeSpeed: 300,
        steelReduce: 60
    },
    7: {
        preCond: [{ buildingType: 101, buildingLvl: 10 }],
        costRes: { Grain: 7000, Lumber: 12000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 9360,
        exp: 272,
        kingdomPoint: 2565,
        power: 420,
        forgeSpeed: 350,
        steelReduce: 70
    },
    8: {
        preCond: [{ buildingType: 101, buildingLvl: 10 }],
        costRes: { Grain: 13000, Lumber: 23000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 12870,
        exp: 372,
        kingdomPoint: 3621,
        power: 650,
        forgeSpeed: 400,
        steelReduce: 80
    },
    9: {
        preCond: [{ buildingType: 101, buildingLvl: 10 }],
        costRes: { Grain: 26000, Lumber: 45000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 17355,
        exp: 500,
        kingdomPoint: 5013,
        power: 920,
        forgeSpeed: 450,
        steelReduce: 90
    },
    10: {
        preCond: [{ buildingType: 101, buildingLvl: 10 }],
        costRes: { Grain: 50000, Lumber: 88000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 23595,
        exp: 679,
        kingdomPoint: 6990,
        power: 1240,
        forgeSpeed: 500,
        steelReduce: 100
    },
    11: {
        preCond: [{ buildingType: 101, buildingLvl: 11 }],
        costRes: { Grain: 80000, Lumber: 140000, Iron: 14000, Silver: 0, Crystal: 0 },
        costTime: 31980,
        exp: 918,
        kingdomPoint: 9711,
        power: 1620,
        forgeSpeed: 550,
        steelReduce: 110
    },
    12: {
        preCond: [{ buildingType: 101, buildingLvl: 12 }],
        costRes: { Grain: 160000, Lumber: 280000, Iron: 28000, Silver: 0, Crystal: 0 },
        costTime: 43485,
        exp: 1247,
        kingdomPoint: 13528,
        power: 2080,
        forgeSpeed: 600,
        steelReduce: 120
    },
    13: {
        preCond: [{ buildingType: 101, buildingLvl: 13 }],
        costRes: { Grain: 306000, Lumber: 536000, Iron: 53600, Silver: 0, Crystal: 0 },
        costTime: 58500,
        exp: 1676,
        kingdomPoint: 18633,
        power: 2640,
        forgeSpeed: 650,
        steelReduce: 130
    },
    14: {
        preCond: [{ buildingType: 101, buildingLvl: 14 }],
        costRes: { Grain: 550000, Lumber: 963000, Iron: 96300, Silver: 0, Crystal: 0 },
        costTime: 79560,
        exp: 2278,
        kingdomPoint: 25930,
        power: 3330,
        forgeSpeed: 700,
        steelReduce: 140
    },
    15: {
        preCond: [{ buildingType: 101, buildingLvl: 15 }],
        costRes: { Grain: 840000, Lumber: 1470000, Iron: 147000, Silver: 0, Crystal: 0 },
        costTime: 107640,
        exp: 3080,
        kingdomPoint: 35880,
        power: 4170,
        forgeSpeed: 750,
        steelReduce: 150
    },
    16: {
        preCond: [{ buildingType: 101, buildingLvl: 16 }],
        costRes: { Grain: 1100000, Lumber: 1925000, Iron: 192500, Silver: 9600, Crystal: 0 },
        costTime: 145080,
        exp: 4150,
        kingdomPoint: 49433,
        power: 5195,
        forgeSpeed: 800,
        steelReduce: 160
    },
    17: {
        preCond: [{ buildingType: 101, buildingLvl: 17 }],
        costRes: { Grain: 1540000, Lumber: 2695000, Iron: 269500, Silver: 13400, Crystal: 0 },
        costTime: 196560,
        exp: 5621,
        kingdomPoint: 68431,
        power: 6450,
        forgeSpeed: 850,
        steelReduce: 170
    },
    18: {
        preCond: [{ buildingType: 101, buildingLvl: 18 }],
        costRes: { Grain: 2000000, Lumber: 3500000, Iron: 350000, Silver: 17500, Crystal: 0 },
        costTime: 224640,
        exp: 6423,
        kingdomPoint: 79871,
        power: 7985,
        forgeSpeed: 900,
        steelReduce: 180
    },
    19: {
        preCond: [{ buildingType: 101, buildingLvl: 19 }],
        costRes: { Grain: 2600000, Lumber: 4550000, Iron: 455000, Silver: 22700, Crystal: 0 },
        costTime: 252720,
        exp: 7225,
        kingdomPoint: 91726,
        power: 9860,
        forgeSpeed: 950,
        steelReduce: 190
    },
    20: {
        preCond: [{ buildingType: 101, buildingLvl: 20 }],
        costRes: { Grain: 3200000, Lumber: 5600000, Iron: 560000, Silver: 28000, Crystal: 0 },
        costTime: 287820,
        exp: 8228,
        kingdomPoint: 106600,
        power: 12150,
        forgeSpeed: 1000,
        steelReduce: 200
    },
    21: {
        preCond: [{ buildingType: 101, buildingLvl: 21 }],
        costRes: { Grain: 4000000, Lumber: 7000000, Iron: 700000, Silver: 35000, Crystal: 0 },
        costTime: 329940,
        exp: 9431,
        kingdomPoint: 122200,
        power: 14750,
        forgeSpeed: 1050,
        steelReduce: 210
    },
    22: {
        preCond: [{ buildingType: 101, buildingLvl: 22 }],
        costRes: { Grain: 5000000, Lumber: 8750000, Iron: 875000, Silver: 43700, Crystal: 0 },
        costTime: 379080,
        exp: 10835,
        kingdomPoint: 140400,
        power: 17695,
        forgeSpeed: 1100,
        steelReduce: 220
    },
    23: {
        preCond: [{ buildingType: 101, buildingLvl: 23 }],
        costRes: { Grain: 6000000, Lumber: 10500000, Iron: 1050000, Silver: 52500, Crystal: 0 },
        costTime: 435240,
        exp: 12440,
        kingdomPoint: 161200,
        power: 21035,
        forgeSpeed: 1150,
        steelReduce: 230
    },
    24: {
        preCond: [{ buildingType: 101, buildingLvl: 24 }],
        costRes: { Grain: 8000000, Lumber: 14000000, Iron: 1400000, Silver: 70000, Crystal: 0 },
        costTime: 500760,
        exp: 14312,
        kingdomPoint: 185466,
        power: 24820,
        forgeSpeed: 1200,
        steelReduce: 240
    },
    25: {
        preCond: [{ buildingType: 101, buildingLvl: 25 }],
        costRes: { Grain: 11000000, Lumber: 19250000, Iron: 1925000, Silver: 96200, Crystal: 0 },
        costTime: 575640,
        exp: 16451,
        kingdomPoint: 213200,
        power: 29115,
        forgeSpeed: 1250,
        steelReduce: 250
    },
    26: {
        preCond: [{ buildingType: 101, buildingLvl: 26 }],
        costRes: { Grain: 15000000, Lumber: 26250000, Iron: 2625000, Silver: 131200, Crystal: 0 },
        costTime: 659880,
        exp: 18858,
        kingdomPoint: 244400,
        power: 33990,
        forgeSpeed: 1300,
        steelReduce: 260
    },
    27: {
        preCond: [{ buildingType: 101, buildingLvl: 27 }],
        costRes: { Grain: 20000000, Lumber: 35000000, Iron: 3500000, Silver: 175000, Crystal: 0 },
        costTime: 753480,
        exp: 21533,
        kingdomPoint: 279066,
        power: 39510,
        forgeSpeed: 1350,
        steelReduce: 270
    },
    28: {
        preCond: [{ buildingType: 101, buildingLvl: 28 }],
        costRes: { Grain: 26000000, Lumber: 45500000, Iron: 4550000, Silver: 227500, Crystal: 0 },
        costTime: 856440,
        exp: 24474,
        kingdomPoint: 317200,
        power: 45775,
        forgeSpeed: 1400,
        steelReduce: 280
    },
    29: {
        preCond: [{ buildingType: 101, buildingLvl: 29 }],
        costRes: { Grain: 34000000, Lumber: 59500000, Iron: 5950000, Silver: 297500, Crystal: 0 },
        costTime: 968760,
        exp: 27683,
        kingdomPoint: 358800,
        power: 52880,
        forgeSpeed: 1450,
        steelReduce: 290
    },
    30: {
        preCond: [{ buildingType: 101, buildingLvl: 30 }],
        costRes: { Grain: 44000000, Lumber: 77000000, Iron: 7700000, Silver: 385000, Crystal: 0 },
        costTime: 1109160,
        exp: 31695,
        kingdomPoint: 410800,
        power: 60930,
        forgeSpeed: 1500,
        steelReduce: 300
    }

};