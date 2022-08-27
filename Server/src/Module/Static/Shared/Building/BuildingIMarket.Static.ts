import { EBuildingType } from "src/Module/Building/Building.Const";
import { IReqBuilding } from "./Building.Static";

export const BuildingIMarketStatic: {[Key: number] : IReqBuilding} = {
    1: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 6 }],
        costRes: { Grain: 0, Lumber: 500, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 60,
        exp: 6,
        kingdomPoint: 13,
        power: 5,
        capacity: 20000,
        taxRate: 450
    },
    2: {
        preCond: [{ buildingType: 111, buildingLvl: 2 }],
        costRes: { Grain: 0, Lumber: 1200, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 75,
        exp: 7,
        kingdomPoint: 16,
        power: 15,
        capacity: 40000,
        taxRate: 440
    },
    3: {
        preCond: [{ buildingType: 111, buildingLvl: 3 }],
        costRes: { Grain: 0, Lumber: 1500, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 150,
        exp: 11,
        kingdomPoint: 36,
        power: 35,
        capacity: 60000,
        taxRate: 430
    },
    4: {
        preCond: [{ buildingType: 111, buildingLvl: 4 }],
        costRes: { Grain: 0, Lumber: 2000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 525,
        exp: 29,
        kingdomPoint: 131,
        power: 70,
        capacity: 80000,
        taxRate: 420
    },
    5: {
        preCond: [{ buildingType: 111, buildingLvl: 5 }],
        costRes: { Grain: 0, Lumber: 3000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 1260,
        exp: 53,
        kingdomPoint: 326,
        power: 135,
        capacity: 100000,
        taxRate: 410
    },
    6: {
        preCond: [{ buildingType: 111, buildingLvl: 6 }],
        costRes: { Grain: 0, Lumber: 4700, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 2520,
        exp: 101,
        kingdomPoint: 671,
        power: 250,
        capacity: 120000,
        taxRate: 400
    },
    7: {
        preCond: [{ buildingType: 111, buildingLvl: 7 }],
        costRes: { Grain: 0, Lumber: 9000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 5040,
        exp: 149,
        kingdomPoint: 1380,
        power: 420,
        capacity: 140000,
        taxRate: 390
    },
    8: {
        preCond: [{ buildingType: 111, buildingLvl: 8 }],
        costRes: { Grain: 0, Lumber: 16000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 6930,
        exp: 203,
        kingdomPoint: 1950,
        power: 650,
        capacity: 160000,
        taxRate: 380
    },
    9: {
        preCond: [{ buildingType: 111, buildingLvl: 9 }],
        costRes: { Grain: 0, Lumber: 32000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 9345,
        exp: 272,
        kingdomPoint: 2698,
        power: 920,
        capacity: 180000,
        taxRate: 370
    },
    10: {
        preCond: [{ buildingType: 111, buildingLvl: 10 }],
        costRes: { Grain: 0, Lumber: 63000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 12705,
        exp: 368,
        kingdomPoint: 3763,
        power: 1240,
        capacity: 200000,
        taxRate: 360
    },
    11: {
        preCond: [{ buildingType: 111, buildingLvl: 11 }],
        costRes: { Grain: 0, Lumber: 100000, Iron: 14300, Silver: 0, Crystal: 0 },
        costTime: 17220,
        exp: 497,
        kingdomPoint: 5228,
        power: 1620,
        capacity: 220000,
        taxRate: 350
    },
    12: {
        preCond: [{ buildingType: 111, buildingLvl: 12 }],
        costRes: { Grain: 0, Lumber: 200000, Iron: 28600, Silver: 0, Crystal: 0 },
        costTime: 23415,
        exp: 674,
        kingdomPoint: 7283,
        power: 2080,
        capacity: 240000,
        taxRate: 340
    },
    13: {
        preCond: [{ buildingType: 111, buildingLvl: 13 }],
        costRes: { Grain: 0, Lumber: 383000, Iron: 54700, Silver: 0, Crystal: 0 },
        costTime: 31500,
        exp: 905,
        kingdomPoint: 10033,
        power: 2640,
        capacity: 270000,
        taxRate: 330
    },
    14: {
        preCond: [{ buildingType: 111, buildingLvl: 14 }],
        costRes: { Grain: 0, Lumber: 688000, Iron: 98300, Silver: 0, Crystal: 0 },
        costTime: 42840,
        exp: 1229,
        kingdomPoint: 13961,
        power: 3330,
        capacity: 290000,
        taxRate: 320
    },
    15: {
        preCond: [{ buildingType: 111, buildingLvl: 15 }],
        costRes: { Grain: 0, Lumber: 1050000, Iron: 150100, Silver: 0, Crystal: 0 },
        costTime: 57960,
        exp: 1661,
        kingdomPoint: 19320,
        power: 4170,
        capacity: 320000,
        taxRate: 310
    },
    16: {
        preCond: [{ buildingType: 111, buildingLvl: 16 }],
        costRes: { Grain: 0, Lumber: 1375000, Iron: 196600, Silver: 9800, Crystal: 0 },
        costTime: 78120,
        exp: 2237,
        kingdomPoint: 26618,
        power: 5195,
        capacity: 340000,
        taxRate: 300
    },
    17: {
        preCond: [{ buildingType: 111, buildingLvl: 17 }],
        costRes: { Grain: 0, Lumber: 1925000, Iron: 275200, Silver: 13700, Crystal: 0 },
        costTime: 105840,
        exp: 3029,
        kingdomPoint: 36846,
        power: 6450,
        capacity: 370000,
        taxRate: 290
    },
    18: {
        preCond: [{ buildingType: 111, buildingLvl: 18 }],
        costRes: { Grain: 0, Lumber: 2500000, Iron: 357500, Silver: 17800, Crystal: 0 },
        costTime: 120960,
        exp: 3461,
        kingdomPoint: 43006,
        power: 7985,
        capacity: 390000,
        taxRate: 280
    },
    19: {
        preCond: [{ buildingType: 111, buildingLvl: 19 }],
        costRes: { Grain: 0, Lumber: 3250000, Iron: 464700, Silver: 23200, Crystal: 0 },
        costTime: 136080,
        exp: 3893,
        kingdomPoint: 49391,
        power: 9860,
        capacity: 420000,
        taxRate: 270
    },
    20: {
        preCond: [{ buildingType: 111, buildingLvl: 20 }],
        costRes: { Grain: 0, Lumber: 4000000, Iron: 572000, Silver: 28600, Crystal: 0 },
        costTime: 154980,
        exp: 4433,
        kingdomPoint: 57400,
        power: 12150,
        capacity: 440000,
        taxRate: 260
    },
    21: {
        preCond: [{ buildingType: 111, buildingLvl: 21 }],
        costRes: { Grain: 0, Lumber: 5000000, Iron: 715000, Silver: 35700, Crystal: 0 },
        costTime: 177660,
        exp: 5081,
        kingdomPoint: 65800,
        power: 14750,
        capacity: 470000,
        taxRate: 250
    },
    22: {
        preCond: [{ buildingType: 111, buildingLvl: 22 }],
        costRes: { Grain: 0, Lumber: 6250000, Iron: 893700, Silver: 44600, Crystal: 0 },
        costTime: 204120,
        exp: 5837,
        kingdomPoint: 75600,
        power: 17695,
        capacity: 490000,
        taxRate: 240
    },
    23: {
        preCond: [{ buildingType: 111, buildingLvl: 23 }],
        costRes: { Grain: 0, Lumber: 7500000, Iron: 1072500, Silver: 53600, Crystal: 0 },
        costTime: 234360,
        exp: 6701,
        kingdomPoint: 86800,
        power: 21035,
        capacity: 520000,
        taxRate: 230
    },
    24: {
        preCond: [{ buildingType: 111, buildingLvl: 24 }],
        costRes: { Grain: 0, Lumber: 10000000, Iron: 1430000, Silver: 71500, Crystal: 0 },
        costTime: 269640,
        exp: 7709,
        kingdomPoint: 99866,
        power: 24820,
        capacity: 540000,
        taxRate: 220
    },
    25: {
        preCond: [{ buildingType: 111, buildingLvl: 25 }],
        costRes: { Grain: 0, Lumber: 13750000, Iron: 1966200, Silver: 98300, Crystal: 0 },
        costTime: 309960,
        exp: 8861,
        kingdomPoint: 114800,
        power: 29115,
        capacity: 570000,
        taxRate: 210
    },
    26: {
        preCond: [{ buildingType: 111, buildingLvl: 26 }],
        costRes: { Grain: 0, Lumber: 18750000, Iron: 2681200, Silver: 134000, Crystal: 0 },
        costTime: 355320,
        exp: 10157,
        kingdomPoint: 131600,
        power: 33990,
        capacity: 590000,
        taxRate: 190
    },
    27: {
        preCond: [{ buildingType: 111, buildingLvl: 27 }],
        costRes: { Grain: 0, Lumber: 25000000, Iron: 3575000, Silver: 178700, Crystal: 0 },
        costTime: 405720,
        exp: 11597,
        kingdomPoint: 150266,
        power: 39510,
        capacity: 620000,
        taxRate: 170
    },
    28: {
        preCond: [{ buildingType: 111, buildingLvl: 28 }],
        costRes: { Grain: 0, Lumber: 32500000, Iron: 4647500, Silver: 232300, Crystal: 0 },
        costTime: 461160,
        exp: 13181,
        kingdomPoint: 170800,
        power: 45775,
        capacity: 640000,
        taxRate: 150
    },
    29: {
        preCond: [{ buildingType: 111, buildingLvl: 29 }],
        costRes: { Grain: 0, Lumber: 42500000, Iron: 6077500, Silver: 303800, Crystal: 0 },
        costTime: 521640,
        exp: 14909,
        kingdomPoint: 193200,
        power: 52880,
        capacity: 670000,
        taxRate: 130
    },
    30: {
        preCond: [{ buildingType: 111, buildingLvl: 30 }],
        costRes: { Grain: 0, Lumber: 55000000, Iron: 7865000, Silver: 393200, Crystal: 0 },
        costTime: 597240,
        exp: 17069,
        kingdomPoint: 221200,
        power: 60930,
        capacity: 690000,
        taxRate: 100
    }


};