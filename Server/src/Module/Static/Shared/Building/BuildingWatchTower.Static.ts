import { EBuildingType } from "src/Module/Building/Building.Const";
import { IReqBuilding } from "./Building.Static";

export const BuildingWatchTowerStatic: { [Key: number]: IReqBuilding } = {
    1: {
        preCond: [],
        costRes: { Grain: 0, Lumber: 0, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 0,
        exp: 0,
        kingdomPoint: 0,
        power: 5,
        watchTowerEffect: 2001
    },
    2: {
        preCond: [{ buildingType: EBuildingType.Farm, buildingLvl: 2 }],
        costRes: { Grain: 0, Lumber: 500, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 60,
        exp: 7,
        kingdomPoint: 13,
        power: 10,
        watchTowerEffect: 2100
    },
    3: {
        preCond: [{ buildingType: 201, buildingLvl: 3 }],
        costRes: { Grain: 0, Lumber: 800, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 120,
        exp: 10,
        kingdomPoint: 28,
        power: 25,
        watchTowerEffect: 2002
    },
    4: {
        preCond: [{ buildingType: 201, buildingLvl: 4 }],
        costRes: { Grain: 0, Lumber: 1200, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 450,
        exp: 25,
        kingdomPoint: 113,
        power: 50,
        watchTowerEffect: 2201
    },
    5: {
        preCond: [{ buildingType: 201, buildingLvl: 5 }],
        costRes: { Grain: 0, Lumber: 2000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 1080,
        exp: 46,
        kingdomPoint: 280,
        power: 95,
        watchTowerEffect: 2003
    },
    6: {
        preCond: [{ buildingType: 201, buildingLvl: 6 }],
        costRes: { Grain: 0, Lumber: 3400, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 2160,
        exp: 87,
        kingdomPoint: 575,
        power: 175,
        watchTowerEffect: 2301
    },
    7: {
        preCond: [{ buildingType: 201, buildingLvl: 7 }],
        costRes: { Grain: 0, Lumber: 7000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 4320,
        exp: 128,
        kingdomPoint: 1183,
        power: 290,
        watchTowerEffect: 2004
    },
    8: {
        preCond: [{ buildingType: 201, buildingLvl: 8 }],
        costRes: { Grain: 0, Lumber: 13000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 5940,
        exp: 174,
        kingdomPoint: 1671,
        power: 455,
        watchTowerEffect: 2401
    },
    9: {
        preCond: [{ buildingType: 201, buildingLvl: 9 }],
        costRes: { Grain: 0, Lumber: 25800, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 8010,
        exp: 233,
        kingdomPoint: 2313,
        power: 645,
        watchTowerEffect: 2005
    },
    10: {
        preCond: [{ buildingType: 201, buildingLvl: 10 }],
        costRes: { Grain: 0, Lumber: 50000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 10890,
        exp: 316,
        kingdomPoint: 3226,
        power: 865,
        watchTowerEffect: 2202
    },
    11: {
        preCond: [{ buildingType: 201, buildingLvl: 11 }],
        costRes: { Grain: 0, Lumber: 80000, Iron: 8000, Silver: 0, Crystal: 0 },
        costTime: 14760,
        exp: 426,
        kingdomPoint: 4481,
        power: 1130,
        watchTowerEffect: 2006
    },
    12: {
        preCond: [{ buildingType: 201, buildingLvl: 12 }],
        costRes: { Grain: 0, Lumber: 160000, Iron: 16000, Silver: 0, Crystal: 0 },
        costTime: 20070,
        exp: 578,
        kingdomPoint: 6243,
        power: 1455,
        watchTowerEffect: 2302
    },
    13: {
        preCond: [{ buildingType: 201, buildingLvl: 13 }],
        costRes: { Grain: 0, Lumber: 306000, Iron: 30600, Silver: 0, Crystal: 0 },
        costTime: 27000,
        exp: 776,
        kingdomPoint: 8600,
        power: 1845,
        watchTowerEffect: 2007
    },
    14: {
        preCond: [{ buildingType: 201, buildingLvl: 14 }],
        costRes: { Grain: 0, Lumber: 550000, Iron: 55000, Silver: 0, Crystal: 0 },
        costTime: 36720,
        exp: 1054,
        kingdomPoint: 11966,
        power: 2330,
        watchTowerEffect: 2500
    },
    15: {
        preCond: [{ buildingType: 201, buildingLvl: 15 }],
        costRes: { Grain: 0, Lumber: 840000, Iron: 84000, Silver: 0, Crystal: 0 },
        costTime: 49680,
        exp: 1424,
        kingdomPoint: 16560,
        power: 2915,
        watchTowerEffect: 2011
    },
    16: {
        preCond: [{ buildingType: 201, buildingLvl: 16 }],
        costRes: { Grain: 0, Lumber: 1100000, Iron: 110000, Silver: 17000, Crystal: 0 },
        costTime: 66960,
        exp: 1918,
        kingdomPoint: 22815,
        power: 3635,
        watchTowerEffect: 2402
    },
    17: {
        preCond: [{ buildingType: 201, buildingLvl: 17 }],
        costRes: { Grain: 0, Lumber: 1540000, Iron: 154000, Silver: 24000, Crystal: 0 },
        costTime: 90720,
        exp: 2597,
        kingdomPoint: 31583,
        power: 4510,
        watchTowerEffect: 2102
    },
    18: {
        preCond: [{ buildingType: 201, buildingLvl: 18 }],
        costRes: { Grain: 0, Lumber: 2000000, Iron: 200000, Silver: 32000, Crystal: 0 },
        costTime: 103680,
        exp: 2967,
        kingdomPoint: 36863,
        power: 5585,
        watchTowerEffect: 2203
    },
    19: {
        preCond: [{ buildingType: 201, buildingLvl: 19 }],
        costRes: { Grain: 0, Lumber: 2600000, Iron: 260000, Silver: 41000, Crystal: 0 },
        costTime: 116640,
        exp: 3337,
        kingdomPoint: 42335,
        power: 6895,
        watchTowerEffect: 2012
    },
    20: {
        preCond: [{ buildingType: 201, buildingLvl: 20 }],
        costRes: { Grain: 0, Lumber: 3200000, Iron: 320000, Silver: 51000, Crystal: 0 },
        costTime: 132840,
        exp: 3800,
        kingdomPoint: 49200,
        power: 8495,
        watchTowerEffect: 2303
    },
    21: {
        preCond: [{ buildingType: 201, buildingLvl: 21 }],
        costRes: { Grain: 0, Lumber: 4000000, Iron: 400000, Silver: 64000, Crystal: 0 },
        costTime: 152280,
        exp: 4355,
        kingdomPoint: 56400,
        power: 10315,
        watchTowerEffect: 2103
    },
    22: {
        preCond: [{ buildingType: 201, buildingLvl: 22 }],
        costRes: { Grain: 0, Lumber: 5000000, Iron: 500000, Silver: 80000, Crystal: 0 },
        costTime: 174960,
        exp: 5003,
        kingdomPoint: 64800,
        power: 12375,
        watchTowerEffect: 2403
    },
    23: {
        preCond: [{ buildingType: 201, buildingLvl: 23 }],
        costRes: { Grain: 0, Lumber: 6000000, Iron: 600000, Silver: 96000, Crystal: 0 },
        costTime: 200880,
        exp: 5744,
        kingdomPoint: 74400,
        power: 14710,
        watchTowerEffect: 0
    },
    24: {
        preCond: [{ buildingType: 201, buildingLvl: 24 }],
        costRes: { Grain: 0, Lumber: 8000000, Iron: 800000, Silver: 128000, Crystal: 0 },
        costTime: 231120,
        exp: 6608,
        kingdomPoint: 85600,
        power: 17360,
        watchTowerEffect: 2600
    },
    25: {
        preCond: [{ buildingType: 201, buildingLvl: 25 }],
        costRes: { Grain: 0, Lumber: 11000000, Iron: 1100000, Silver: 176000, Crystal: 0 },
        costTime: 265680,
        exp: 7595,
        kingdomPoint: 98400,
        power: 20365,
        watchTowerEffect: 0
    },
    26: {
        preCond: [{ buildingType: 201, buildingLvl: 26 }],
        costRes: { Grain: 0, Lumber: 15000000, Iron: 1500000, Silver: 240000, Crystal: 0 },
        costTime: 304560,
        exp: 8706,
        kingdomPoint: 112800,
        power: 23770,
        watchTowerEffect: 2008
    },
    27: {
        preCond: [{ buildingType: 201, buildingLvl: 27 }],
        costRes: { Grain: 0, Lumber: 20000000, Iron: 2000000, Silver: 320000, Crystal: 0 },
        costTime: 347760,
        exp: 9941,
        kingdomPoint: 128800,
        power: 27630,
        watchTowerEffect: 2101
    },
    28: {
        preCond: [{ buildingType: 201, buildingLvl: 28 }],
        costRes: { Grain: 0, Lumber: 26000000, Iron: 2600000, Silver: 416000, Crystal: 0 },
        costTime: 395280,
        exp: 11298,
        kingdomPoint: 146400,
        power: 32015,
        watchTowerEffect: 2700
    },
    29: {
        preCond: [{ buildingType: 201, buildingLvl: 29 }],
        costRes: { Grain: 0, Lumber: 34000000, Iron: 3400000, Silver: 544000, Crystal: 0 },
        costTime: 447120,
        exp: 12779,
        kingdomPoint: 165600,
        power: 36980,
        watchTowerEffect: 2009
    },
    30: {
        preCond: [{ buildingType: 201, buildingLvl: 30 }],
        costRes: { Grain: 0, Lumber: 44000000, Iron: 4400000, Silver: 704000, Crystal: 0 },
        costTime: 511920,
        exp: 14631,
        kingdomPoint: 189600,
        power: 41615,
        watchTowerEffect: 2800
    }
};