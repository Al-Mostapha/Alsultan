import { EBuildingType } from "src/Module/Building/Building.Const";
import { EArmyType } from "../Army/Static.Army";
import { IReqBuilding } from "./Building.Static";

export const BuildingAFortressStatic: {[Key: number] : IReqBuilding} = {
    1: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 4 }],
        costRes: { Grain: 0, Lumber: 300, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 45,
        exp: 6,
        kingdomPoint: 10,
        power: 10,
        unlockedSoldier: EArmyType.Wall_FallingStones_1
    },
    2: {
        preCond: [{ buildingType: 202, buildingLvl: 2 }],
        costRes: { Grain: 0, Lumber: 800, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 75,
        exp: 7,
        kingdomPoint: 16,
        power: 30,
        unlockedSoldier: 811
    },
    3: {
        preCond: [{ buildingType: 202, buildingLvl: 3 }],
        costRes: { Grain: 0, Lumber: 1100, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 150,
        exp: 11,
        kingdomPoint: 36,
        power: 60,
        unlockedSoldier: 821
    },
    4: {
        preCond: [{ buildingType: 202, buildingLvl: 4 }],
        costRes: { Grain: 0, Lumber: 1500, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 525,
        exp: 29,
        kingdomPoint: 131,
        power: 120,
        unlockedSoldier: EArmyType.None
    },
    5: {
        preCond: [{ buildingType: 202, buildingLvl: 5 }],
        costRes: { Grain: 0, Lumber: 2000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 1260,
        exp: 53,
        kingdomPoint: 326,
        power: 230,
        unlockedSoldier: EArmyType.None
    },
    6: {
        preCond: [{ buildingType: 202, buildingLvl: 6 }],
        costRes: { Grain: 0, Lumber: 3000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 2520,
        exp: 101,
        kingdomPoint: 671,
        power: 420,
        unlockedSoldier: 802
    },
    7: {
        preCond: [{ buildingType: 202, buildingLvl: 7 }],
        costRes: { Grain: 0, Lumber: 7000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 5040,
        exp: 149,
        kingdomPoint: 1380,
        power: 705,
        unlockedSoldier: EArmyType.None
    },
    8: {
        preCond: [{ buildingType: 202, buildingLvl: 8 }],
        costRes: { Grain: 0, Lumber: 13000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 6930,
        exp: 203,
        kingdomPoint: 1950,
        power: 1090,
        unlockedSoldier: 812
    },
    9: {
        preCond: [{ buildingType: 202, buildingLvl: 9 }],
        costRes: { Grain: 0, Lumber: 26000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 9345,
        exp: 272,
        kingdomPoint: 2698,
        power: 1550,
        unlockedSoldier: EArmyType.None
    },
    10: {
        preCond: [{ buildingType: 202, buildingLvl: 10 }],
        costRes: { Grain: 0, Lumber: 50000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 12705,
        exp: 368,
        kingdomPoint: 3763,
        power: 2085,
        unlockedSoldier: 822
    },
    11: {
        preCond: [{ buildingType: 202, buildingLvl: 11 }],
        costRes: { Grain: 0, Lumber: 80000, Iron: 11300, Silver: 0, Crystal: 0 },
        costTime: 17220,
        exp: 497,
        kingdomPoint: 5228,
        power: 2715,
        unlockedSoldier: EArmyType.None
    },
    12: {
        preCond: [{ buildingType: 202, buildingLvl: 12 }],
        costRes: { Grain: 0, Lumber: 160000, Iron: 22700, Silver: 0, Crystal: 0 },
        costTime: 23415,
        exp: 674,
        kingdomPoint: 7283,
        power: 3490,
        unlockedSoldier: 803
    },
    13: {
        preCond: [{ buildingType: 202, buildingLvl: 13 }],
        costRes: { Grain: 0, Lumber: 306000, Iron: 43400, Silver: 0, Crystal: 0 },
        costTime: 31500,
        exp: 905,
        kingdomPoint: 10033,
        power: 4435,
        unlockedSoldier: EArmyType.None
    },
    14: {
        preCond: [{ buildingType: 202, buildingLvl: 14 }],
        costRes: { Grain: 0, Lumber: 550000, Iron: 78100, Silver: 0, Crystal: 0 },
        costTime: 42840,
        exp: 1229,
        kingdomPoint: 13961,
        power: 5590,
        unlockedSoldier: 813
    },
    15: {
        preCond: [{ buildingType: 202, buildingLvl: 15 }],
        costRes: { Grain: 0, Lumber: 840000, Iron: 119200, Silver: 0, Crystal: 0 },
        costTime: 57960,
        exp: 1661,
        kingdomPoint: 19320,
        power: 7000,
        unlockedSoldier: EArmyType.None
    },
    16: {
        preCond: [{ buildingType: 202, buildingLvl: 16 }],
        costRes: { Grain: 0, Lumber: 1100000, Iron: 156200, Silver: 0, Crystal: 0 },
        costTime: 78120,
        exp: 2237,
        kingdomPoint: 26618,
        power: 8725,
        unlockedSoldier: 823
    },
    17: {
        preCond: [{ buildingType: 202, buildingLvl: 17 }],
        costRes: { Grain: 0, Lumber: 1540000, Iron: 218600, Silver: 0, Crystal: 0 },
        costTime: 105840,
        exp: 3029,
        kingdomPoint: 36846,
        power: 10830,
        unlockedSoldier: EArmyType.None
    },
    18: {
        preCond: [{ buildingType: 202, buildingLvl: 18 }],
        costRes: { Grain: 0, Lumber: 2000000, Iron: 284000, Silver: 0, Crystal: 0 },
        costTime: 120960,
        exp: 3461,
        kingdomPoint: 43006,
        power: 13405,
        unlockedSoldier: 804
    },
    19: {
        preCond: [{ buildingType: 202, buildingLvl: 19 }],
        costRes: { Grain: 0, Lumber: 2600000, Iron: 369200, Silver: 0, Crystal: 0 },
        costTime: 136080,
        exp: 3893,
        kingdomPoint: 49391,
        power: 16550,
        unlockedSoldier: EArmyType.None
    },
    20: {
        preCond: [{ buildingType: 202, buildingLvl: 20 }],
        costRes: { Grain: 0, Lumber: 3200000, Iron: 454400, Silver: 0, Crystal: 0 },
        costTime: 154980,
        exp: 4433,
        kingdomPoint: 57400,
        power: 20395,
        unlockedSoldier: 814
    },
    21: {
        preCond: [{ buildingType: 202, buildingLvl: 21 }],
        costRes: { Grain: 0, Lumber: 4000000, Iron: 568000, Silver: 0, Crystal: 0 },
        costTime: 177660,
        exp: 5081,
        kingdomPoint: 65800,
        power: 24755,
        unlockedSoldier: EArmyType.None
    },
    22: {
        preCond: [{ buildingType: 202, buildingLvl: 22 }],
        costRes: { Grain: 0, Lumber: 5000000, Iron: 710000, Silver: 0, Crystal: 0 },
        costTime: 204120,
        exp: 5837,
        kingdomPoint: 75600,
        power: 29700,
        unlockedSoldier: 824
    },
    23: {
        preCond: [{ buildingType: 202, buildingLvl: 23 }],
        costRes: { Grain: 0, Lumber: 6000000, Iron: 852000, Silver: 0, Crystal: 0 },
        costTime: 234360,
        exp: 6701,
        kingdomPoint: 86800,
        power: 35305,
        unlockedSoldier: EArmyType.None
    },
    24: {
        preCond: [{ buildingType: 202, buildingLvl: 24 }],
        costRes: { Grain: 0, Lumber: 8000000, Iron: 1136000, Silver: 0, Crystal: 0 },
        costTime: 269640,
        exp: 7709,
        kingdomPoint: 99866,
        power: 41660,
        unlockedSoldier: 805
    },
    25: {
        preCond: [{ buildingType: 202, buildingLvl: 25 }],
        costRes: { Grain: 0, Lumber: 11000000, Iron: 1562000, Silver: 0, Crystal: 0 },
        costTime: 309960,
        exp: 8861,
        kingdomPoint: 114800,
        power: 48870,
        unlockedSoldier: EArmyType.None
    },
    26: {
        preCond: [{ buildingType: 202, buildingLvl: 26 }],
        costRes: { Grain: 0, Lumber: 15000000, Iron: 2130000, Silver: 0, Crystal: 0 },
        costTime: 355320,
        exp: 10157,
        kingdomPoint: 131600,
        power: 57045,
        unlockedSoldier: EArmyType.None
    },
    27: {
        preCond: [{ buildingType: 202, buildingLvl: 27 }],
        costRes: { Grain: 0, Lumber: 20000000, Iron: 2840000, Silver: 0, Crystal: 0 },
        costTime: 405720,
        exp: 11597,
        kingdomPoint: 150266,
        power: 66315,
        unlockedSoldier: 815
    },
    28: {
        preCond: [{ buildingType: 202, buildingLvl: 28 }],
        costRes: { Grain: 0, Lumber: 26000000, Iron: 3692000, Silver: 0, Crystal: 0 },
        costTime: 461160,
        exp: 13181,
        kingdomPoint: 170800,
        power: 76825,
        unlockedSoldier: EArmyType.None
    },
    29: {
        preCond: [{ buildingType: 202, buildingLvl: 29 }],
        costRes: { Grain: 0, Lumber: 34000000, Iron: 4828000, Silver: 0, Crystal: 0 },
        costTime: 521640,
        exp: 14909,
        kingdomPoint: 193200,
        power: 88750,
        unlockedSoldier: EArmyType.None
    },
    30: {
        preCond: [{ buildingType: 202, buildingLvl: 30 }],
        costRes: { Grain: 0, Lumber: 44000000, Iron: 6248000, Silver: 0, Crystal: 0 },
        costTime: 597240,
        exp: 17069,
        kingdomPoint: 221200,
        power: 102265,
        unlockedSoldier: 825
    }

};