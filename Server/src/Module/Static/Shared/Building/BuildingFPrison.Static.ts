import { IReqBuilding } from "src/Module/Building/Building.Type";
import { EBuildingType } from "src/Module/Building/Building.Enum";


export const BuildingFPrison: {[Key: number] : IReqBuilding} = {
    1: {
        preCond: [{ buildingType: EBuildingType.Castle, buildingLvl: 16 }],
        costRes: { Grain: 0, Lumber: 0, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 0,
        exp: 0,
        kingdomPoint: 0,
        power: 10,
        prisonNum: 5,
        speedTime: 900,
        heroNum: 0,
        costTools: [],
        costWEs: [],
        attack: 0,
        defense: 0,
        life: 10,
        speed: 10
    },
    2: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 8 }
        ],
        costRes: { Grain: 1120, Lumber: 560, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 84,
        exp: 5,
        kingdomPoint: 19,
        power: 28,
        prisonNum: 5,
        speedTime: 1800,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 1}],
        costWEs: [],
        attack: 0,
        defense: 10,
        life: 10,
        speed: 20
    },
    3: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 8 }
        ],
        costRes: { Grain: 1600, Lumber: 800, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 168,
        exp: 8,
        kingdomPoint: 40,
        power: 58,
        prisonNum: 5,
        speedTime: 2700,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 3}],
        costWEs: [],
        attack: 10,
        defense: 10,
        life: 10,
        speed: 30
    },
    4: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 8 }
        ],
        costRes: { Grain: 2400, Lumber: 1200, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 600,
        exp: 29,
        kingdomPoint: 150,
        power: 112,
        prisonNum: 6,
        speedTime: 3600,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 5}],
        costWEs: [],
        attack: 10,
        defense: 10,
        life: 20,
        speed: 40
    },
    5: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 8 }
        ],
        costRes: { Grain: 4000, Lumber: 2000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 1440,
        exp: 56,
        kingdomPoint: 373,
        power: 212,
        prisonNum: 6,
        speedTime: 4500,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 10}],
        costWEs: [],
        attack: 10,
        defense: 20,
        life: 20,
        speed: 50
    },
    6: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 8 }
        ],
        costRes: { Grain: 6800, Lumber: 3400, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 2880,
        exp: 111,
        kingdomPoint: 768,
        power: 384,
        prisonNum: 6,
        speedTime: 5400,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 17}],
        costWEs: [],
        attack: 20,
        defense: 20,
        life: 20,
        speed: 60
    },
    7: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 8 }
        ],
        costRes: { Grain: 14000, Lumber: 7000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 5760,
        exp: 166,
        kingdomPoint: 1578,
        power: 644,
        prisonNum: 7,
        speedTime: 6300,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 27}],
        costWEs: [],
        attack: 20,
        defense: 20,
        life: 30,
        speed: 70
    },
    8: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 8 }
        ],
        costRes: { Grain: 26000, Lumber: 13000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 7920,
        exp: 228,
        kingdomPoint: 2229,
        power: 998,
        prisonNum: 7,
        speedTime: 7200,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 40}],
        costWEs: [],
        attack: 20,
        defense: 30,
        life: 30,
        speed: 80
    },
    9: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 9 }
        ],
        costRes: { Grain: 51600, Lumber: 25800, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 10680,
        exp: 306,
        kingdomPoint: 3085,
        power: 1414,
        prisonNum: 7,
        speedTime: 8100,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 57}],
        costWEs: [],
        attack: 30,
        defense: 30,
        life: 30,
        speed: 90
    },
    10: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 10 }
        ],
        costRes: { Grain: 100000, Lumber: 50000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 14520,
        exp: 416,
        kingdomPoint: 4302,
        power: 1904,
        prisonNum: 8,
        speedTime: 9000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 75}],
        costWEs: [],
        attack: 30,
        defense: 30,
        life: 40,
        speed: 100
    },
    11: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 11 }
        ],
        costRes: { Grain: 160000, Lumber: 80000, Iron: 12000, Silver: 0, Crystal: 0 },
        costTime: 19680,
        exp: 564,
        kingdomPoint: 5976,
        power: 2480,
        prisonNum: 8,
        speedTime: 10800,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 95}],
        costWEs: [],
        attack: 30,
        defense: 40,
        life: 40,
        speed: 110
    },
    12: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 12 }
        ],
        costRes: { Grain: 320000, Lumber: 160000, Iron: 24000, Silver: 0, Crystal: 0 },
        costTime: 26760,
        exp: 766,
        kingdomPoint: 8325,
        power: 3186,
        prisonNum: 8,
        speedTime: 12600,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 116}],
        costWEs: [],
        attack: 40,
        defense: 40,
        life: 40,
        speed: 120
    },
    13: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 13 }
        ],
        costRes: { Grain: 612000, Lumber: 306000, Iron: 45900, Silver: 0, Crystal: 0 },
        costTime: 36000,
        exp: 1030,
        kingdomPoint: 11466,
        power: 4048,
        prisonNum: 9,
        speedTime: 14400,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 138}],
        costWEs: [],
        attack: 40,
        defense: 40,
        life: 50,
        speed: 130
    },
    14: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 14 }
        ],
        costRes: { Grain: 1100000, Lumber: 550000, Iron: 82500, Silver: 0, Crystal: 0 },
        costTime: 48960,
        exp: 1400,
        kingdomPoint: 15957,
        power: 5102,
        prisonNum: 9,
        speedTime: 16200,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 161}],
        costWEs: [],
        attack: 40,
        defense: 50,
        life: 50,
        speed: 140
    },
    15: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 15 }
        ],
        costRes: { Grain: 1680000, Lumber: 840000, Iron: 126000, Silver: 0, Crystal: 0 },
        costTime: 66240,
        exp: 1894,
        kingdomPoint: 22080,
        power: 6388,
        prisonNum: 9,
        speedTime: 18000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 185}],
        costWEs: [],
        attack: 50,
        defense: 50,
        life: 50,
        speed: 150
    },
    16: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 16 },
            { buildingType: 123, buildingLvl: 16 }
        ],
        costRes: { Grain: 2200000, Lumber: 1100000, Iron: 165000, Silver: 10200, Crystal: 0 },
        costTime: 89280,
        exp: 2552,
        kingdomPoint: 30421,
        power: 7962,
        prisonNum: 10,
        speedTime: 19800,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 215}],
        costWEs: [],
        attack: 50,
        defense: 50,
        life: 60,
        speed: 160
    },
    17: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 17 },
            { buildingType: 123, buildingLvl: 17 }
        ],
        costRes: { Grain: 3080000, Lumber: 1540000, Iron: 231000, Silver: 14400, Crystal: 0 },
        costTime: 120960,
        exp: 3458,
        kingdomPoint: 42112,
        power: 9884,
        prisonNum: 10,
        speedTime: 21600,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 250}],
        costWEs: [],
        attack: 50,
        defense: 60,
        life: 60,
        speed: 170
    },
    18: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 18 },
            { buildingType: 123, buildingLvl: 18 }
        ],
        costRes: { Grain: 4000000, Lumber: 2000000, Iron: 300000, Silver: 18600, Crystal: 0 },
        costTime: 138240,
        exp: 3951,
        kingdomPoint: 49152,
        power: 12232,
        prisonNum: 10,
        speedTime: 23400,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 285}],
        costWEs: [],
        attack: 60,
        defense: 60,
        life: 60,
        speed: 180
    },
    19: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 19 },
            { buildingType: 123, buildingLvl: 19 }
        ],
        costRes: { Grain: 5200000, Lumber: 2600000, Iron: 390000, Silver: 24300, Crystal: 0 },
        costTime: 155520,
        exp: 4445,
        kingdomPoint: 56448,
        power: 15102,
        prisonNum: 11,
        speedTime: 25200,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 320}],
        costWEs: [],
        attack: 60,
        defense: 60,
        life: 70,
        speed: 190
    },
    20: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 20 },
            { buildingType: 123, buildingLvl: 20 }
        ],
        costRes: { Grain: 6400000, Lumber: 3200000, Iron: 480000, Silver: 30000, Crystal: 0 },
        costTime: 177120,
        exp: 5062,
        kingdomPoint: 65600,
        power: 18610,
        prisonNum: 11,
        speedTime: 27000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 360}],
        costWEs: [],
        attack: 60,
        defense: 70,
        life: 70,
        speed: 200
    },
    21: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 21 },
            { buildingType: 123, buildingLvl: 21 }
        ],
        costRes: { Grain: 8000000, Lumber: 4000000, Iron: 600000, Silver: 37500, Crystal: 0 },
        costTime: 203040,
        exp: 5802,
        kingdomPoint: 75200,
        power: 22588,
        prisonNum: 11,
        speedTime: 29700,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 400}],
        costWEs: [],
        attack: 70,
        defense: 70,
        life: 70,
        speed: 210
    },
    22: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 22 },
            { buildingType: 123, buildingLvl: 22 }
        ],
        costRes: { Grain: 10000000, Lumber: 5000000, Iron: 750000, Silver: 46800, Crystal: 0 },
        costTime: 233280,
        exp: 6666,
        kingdomPoint: 86400,
        power: 27098,
        prisonNum: 12,
        speedTime: 32400,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 450}],
        costWEs: [],
        attack: 70,
        defense: 70,
        life: 80,
        speed: 220
    },
    23: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 23 },
            { buildingType: 123, buildingLvl: 23 }
        ],
        costRes: { Grain: 12000000, Lumber: 6000000, Iron: 900000, Silver: 56100, Crystal: 0 },
        costTime: 267840,
        exp: 7654,
        kingdomPoint: 99200,
        power: 32212,
        prisonNum: 12,
        speedTime: 35100,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 510}],
        costWEs: [],
        attack: 70,
        defense: 80,
        life: 80,
        speed: 230
    },
    24: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 24 },
            { buildingType: 123, buildingLvl: 24 }
        ],
        costRes: { Grain: 16000000, Lumber: 8000000, Iron: 1200000, Silver: 75000, Crystal: 0 },
        costTime: 308160,
        exp: 8806,
        kingdomPoint: 114133,
        power: 38014,
        prisonNum: 12,
        speedTime: 37800,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 570}],
        costWEs: [],
        attack: 80,
        defense: 80,
        life: 80,
        speed: 240
    },
    25: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 25 },
            { buildingType: 123, buildingLvl: 25 }
        ],
        costRes: { Grain: 22000000, Lumber: 11000000, Iron: 1650000, Silver: 102900, Crystal: 0 },
        costTime: 354240,
        exp: 10122,
        kingdomPoint: 131200,
        power: 44590,
        prisonNum: 13,
        speedTime: 40500,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 640}],
        costWEs: [],
        attack: 80,
        defense: 80,
        life: 90,
        speed: 250
    },
    26: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 26 },
            { buildingType: 123, buildingLvl: 26 }
        ],
        costRes: { Grain: 30000000, Lumber: 15000000, Iron: 2250000, Silver: 140400, Crystal: 0 },
        costTime: 406080,
        exp: 11604,
        kingdomPoint: 150400,
        power: 52050,
        prisonNum: 13,
        speedTime: 43200,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 720}],
        costWEs: [],
        attack: 80,
        defense: 90,
        life: 90,
        speed: 260
    },
    27: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 27 },
            { buildingType: 123, buildingLvl: 27 }
        ],
        costRes: { Grain: 40000000, Lumber: 20000000, Iron: 3000000, Silver: 187500, Crystal: 0 },
        costTime: 463680,
        exp: 13250,
        kingdomPoint: 171733,
        power: 60508,
        prisonNum: 13,
        speedTime: 45900,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 800}],
        costWEs: [],
        attack: 90,
        defense: 90,
        life: 90,
        speed: 270
    },
    28: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 28 },
            { buildingType: 123, buildingLvl: 28 }
        ],
        costRes: { Grain: 52000000, Lumber: 26000000, Iron: 3900000, Silver: 243600, Crystal: 0 },
        costTime: 527040,
        exp: 15060,
        kingdomPoint: 195200,
        power: 70100,
        prisonNum: 14,
        speedTime: 48600,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 900}],
        costWEs: [],
        attack: 90,
        defense: 90,
        life: 100,
        speed: 280
    },
    29: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 29 },
            { buildingType: 123, buildingLvl: 29 }
        ],
        costRes: { Grain: 68000000, Lumber: 34000000, Iron: 5100000, Silver: 318600, Crystal: 0 },
        costTime: 596160,
        exp: 17034,
        kingdomPoint: 220800,
        power: 80976,
        prisonNum: 14,
        speedTime: 51300,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 1010}],
        costWEs: [],
        attack: 90,
        defense: 100,
        life: 100,
        speed: 290
    },
    30: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 30 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 88000000, Lumber: 44000000, Iron: 6600000, Silver: 412500, Crystal: 0 },
        costTime: 682560,
        exp: 19503,
        kingdomPoint: 252800,
        power: 93312,
        prisonNum: 15,
        speedTime: 54000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 1140}],
        costWEs: [],
        attack: 100,
        defense: 100,
        life: 100,
        speed: 300
    },
    31: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 40 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 6000000, Lumber: 3000000, Iron: 450000, Silver: 225000, Crystal: 0 },
        costTime: 57600,
        exp: 1922,
        kingdomPoint: 21333,
        power: 94912,
        prisonNum: 15,
        speedTime: 54000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 120}],
        costWEs: [{ idItem: 301101, amount: 3 }],
        attack: 100,
        defense: 100,
        life: 100,
        speed: 300
    },
    32: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 40 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 6200000, Lumber: 3100000, Iron: 465000, Silver: 232500, Crystal: 0 },
        costTime: 61920,
        exp: 2066,
        kingdomPoint: 22933,
        power: 96513,
        prisonNum: 15,
        speedTime: 54000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 123}],
        costWEs: [{ idItem: 301101, amount: 6 }],
        attack: 100,
        defense: 100,
        life: 100,
        speed: 300
    },
    33: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 40 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 6400000, Lumber: 3200000, Iron: 480000, Silver: 240000, Crystal: 0 },
        costTime: 66240,
        exp: 2210,
        kingdomPoint: 24533,
        power: 98114,
        prisonNum: 15,
        speedTime: 54000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 126}],
        costWEs: [{ idItem: 301101, amount: 9 }],
        attack: 100,
        defense: 100,
        life: 100,
        speed: 300
    },
    34: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 40 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 6600000, Lumber: 3300000, Iron: 495000, Silver: 247500, Crystal: 0 },
        costTime: 70560,
        exp: 2354,
        kingdomPoint: 26133,
        power: 99715,
        prisonNum: 15,
        speedTime: 54000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 129}],
        costWEs: [{ idItem: 301101, amount: 12 }],
        attack: 100,
        defense: 100,
        life: 100,
        speed: 300
    },
    35: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 40 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 6800000, Lumber: 3400000, Iron: 510000, Silver: 255000, Crystal: 0 },
        costTime: 74880,
        exp: 2498,
        kingdomPoint: 27733,
        power: 101316,
        prisonNum: 15,
        speedTime: 54000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 132}],
        costWEs: [{ idItem: 301101, amount: 15 }],
        attack: 100,
        defense: 100,
        life: 100,
        speed: 300
    },
    36: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 40 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 7000000, Lumber: 3500000, Iron: 525000, Silver: 262500, Crystal: 0 },
        costTime: 79200,
        exp: 2642,
        kingdomPoint: 29333,
        power: 102916,
        prisonNum: 15,
        speedTime: 54000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 135}],
        costWEs: [{ idItem: 301101, amount: 18 }],
        attack: 100,
        defense: 100,
        life: 100,
        speed: 300
    },
    37: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 40 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 7200000, Lumber: 3600000, Iron: 540000, Silver: 270000, Crystal: 0 },
        costTime: 83520,
        exp: 2786,
        kingdomPoint: 30933,
        power: 104517,
        prisonNum: 15,
        speedTime: 54000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 138}],
        costWEs: [{ idItem: 301101, amount: 21 }],
        attack: 100,
        defense: 100,
        life: 100,
        speed: 300
    },
    38: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 40 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 7400000, Lumber: 3700000, Iron: 555000, Silver: 277500, Crystal: 0 },
        costTime: 87840,
        exp: 2930,
        kingdomPoint: 32533,
        power: 106118,
        prisonNum: 15,
        speedTime: 54000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 141}],
        costWEs: [{ idItem: 301101, amount: 24 }],
        attack: 100,
        defense: 100,
        life: 100,
        speed: 300
    },
    39: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 40 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 7600000, Lumber: 3800000, Iron: 570000, Silver: 285000, Crystal: 0 },
        costTime: 92160,
        exp: 3074,
        kingdomPoint: 34133,
        power: 107719,
        prisonNum: 15,
        speedTime: 54000,
        heroNum: 0,
        costTools: [{ idItem: 310201, amount: 144}],
        costWEs: [{ idItem: 301101, amount: 27 }],
        attack: 100,
        defense: 100,
        life: 100,
        speed: 300
    },
    40: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 40 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 7800000, Lumber: 3900000, Iron: 585000, Silver: 292500, Crystal: 0 },
        costTime: 96480,
        exp: 3218,
        kingdomPoint: 35733,
        power: 109320,
        prisonNum: 16,
        speedTime: 57600,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 147}],
        costWEs: [{ idItem: 301101, amount: 30 }],
        attack: 110,
        defense: 110,
        life: 110,
        speed: 310
    },
    41: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 50 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 8000000, Lumber: 4000000, Iron: 600000, Silver: 300000, Crystal: 0 },
        costTime: 100800,
        exp: 3362,
        kingdomPoint: 37333,
        power: 112148,
        prisonNum: 16,
        speedTime: 57600,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 150}],
        costWEs: [{ idItem: 301101, amount: 30 }],
        attack: 110,
        defense: 110,
        life: 110,
        speed: 310
    },
    42: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 50 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 8200000, Lumber: 4100000, Iron: 615000, Silver: 307500, Crystal: 0 },
        costTime: 105120,
        exp: 3506,
        kingdomPoint: 38933,
        power: 114976,
        prisonNum: 16,
        speedTime: 57600,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 153}],
        costWEs: [{ idItem: 301101, amount: 36 }],
        attack: 110,
        defense: 110,
        life: 110,
        speed: 310
    },
    43: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 50 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 8400000, Lumber: 4200000, Iron: 630000, Silver: 315000, Crystal: 0 },
        costTime: 109440,
        exp: 3650,
        kingdomPoint: 40533,
        power: 117804,
        prisonNum: 16,
        speedTime: 57600,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 156}],
        costWEs: [{ idItem: 301101, amount: 42 }],
        attack: 110,
        defense: 110,
        life: 110,
        speed: 310
    },
    44: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 50 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 8600000, Lumber: 4300000, Iron: 645000, Silver: 322500, Crystal: 0 },
        costTime: 113760,
        exp: 3794,
        kingdomPoint: 42133,
        power: 120632,
        prisonNum: 16,
        speedTime: 57600,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 159}],
        costWEs: [{ idItem: 301101, amount: 48 }],
        attack: 110,
        defense: 110,
        life: 110,
        speed: 310
    },
    45: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 50 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 8800000, Lumber: 4400000, Iron: 660000, Silver: 330000, Crystal: 0 },
        costTime: 118080,
        exp: 3938,
        kingdomPoint: 43733,
        power: 123460,
        prisonNum: 16,
        speedTime: 57600,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 162}],
        costWEs: [{ idItem: 301101, amount: 54 }],
        attack: 110,
        defense: 110,
        life: 110,
        speed: 310
    },
    46: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 50 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 9000000, Lumber: 4500000, Iron: 675000, Silver: 337500, Crystal: 0 },
        costTime: 122400,
        exp: 4082,
        kingdomPoint: 45333,
        power: 126288,
        prisonNum: 16,
        speedTime: 57600,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 165}],
        costWEs: [{ idItem: 301101, amount: 60 }],
        attack: 110,
        defense: 110,
        life: 110,
        speed: 310
    },
    47: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 50 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 9200000, Lumber: 4600000, Iron: 690000, Silver: 345000, Crystal: 0 },
        costTime: 126720,
        exp: 4226,
        kingdomPoint: 46933,
        power: 129116,
        prisonNum: 16,
        speedTime: 57600,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 168}],
        costWEs: [{ idItem: 301101, amount: 66 }],
        attack: 110,
        defense: 110,
        life: 110,
        speed: 310
    },
    48: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 50 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 9400000, Lumber: 4700000, Iron: 705000, Silver: 352500, Crystal: 0 },
        costTime: 131040,
        exp: 4370,
        kingdomPoint: 48533,
        power: 131944,
        prisonNum: 16,
        speedTime: 57600,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 171}],
        costWEs: [{ idItem: 301101, amount: 72 }],
        attack: 110,
        defense: 110,
        life: 110,
        speed: 310
    },
    49: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 50 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 9600000, Lumber: 4800000, Iron: 720000, Silver: 360000, Crystal: 0 },
        costTime: 135360,
        exp: 4514,
        kingdomPoint: 50133,
        power: 134772,
        prisonNum: 16,
        speedTime: 57600,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 174}],
        costWEs: [{ idItem: 301101, amount: 78 }],
        attack: 110,
        defense: 110,
        life: 110,
        speed: 310
    },
    50: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 50 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 9800000, Lumber: 4900000, Iron: 735000, Silver: 367500, Crystal: 0 },
        costTime: 139680,
        exp: 4658,
        kingdomPoint: 51733,
        power: 137600,
        prisonNum: 17,
        speedTime: 61200,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 177}],
        costWEs: [{ idItem: 301101, amount: 84 }],
        attack: 120,
        defense: 120,
        life: 120,
        speed: 320
    },
    51: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 60 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 10000000, Lumber: 5000000, Iron: 750000, Silver: 375000, Crystal: 0 },
        costTime: 144000,
        exp: 4802,
        kingdomPoint: 53333,
        power: 141632,
        prisonNum: 17,
        speedTime: 61200,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 180}],
        costWEs: [{ idItem: 301101, amount: 93 }],
        attack: 120,
        defense: 120,
        life: 120,
        speed: 320
    },
    52: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 60 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 10200000, Lumber: 5100000, Iron: 765000, Silver: 382500, Crystal: 0 },
        costTime: 148320,
        exp: 4946,
        kingdomPoint: 54933,
        power: 145664,
        prisonNum: 17,
        speedTime: 61200,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 184}],
        costWEs: [{ idItem: 301101, amount: 102 }],
        attack: 120,
        defense: 120,
        life: 120,
        speed: 320
    },
    53: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 60 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 10400000, Lumber: 5200000, Iron: 780000, Silver: 390000, Crystal: 0 },
        costTime: 152640,
        exp: 5090,
        kingdomPoint: 56533,
        power: 149696,
        prisonNum: 17,
        speedTime: 61200,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 188}],
        costWEs: [{ idItem: 301101, amount: 111 }],
        attack: 120,
        defense: 120,
        life: 120,
        speed: 320
    },
    54: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 60 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 10600000, Lumber: 5300000, Iron: 795000, Silver: 397500, Crystal: 0 },
        costTime: 156960,
        exp: 5234,
        kingdomPoint: 58133,
        power: 153728,
        prisonNum: 17,
        speedTime: 61200,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 192}],
        costWEs: [{ idItem: 301101, amount: 120 }],
        attack: 120,
        defense: 120,
        life: 120,
        speed: 320
    },
    55: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 60 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 10800000, Lumber: 5400000, Iron: 810000, Silver: 405000, Crystal: 0 },
        costTime: 161280,
        exp: 5378,
        kingdomPoint: 59733,
        power: 157760,
        prisonNum: 17,
        speedTime: 61200,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 196}],
        costWEs: [{ idItem: 301101, amount: 129 }],
        attack: 120,
        defense: 120,
        life: 120,
        speed: 320
    },
    56: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 60 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 11000000, Lumber: 5500000, Iron: 825000, Silver: 412500, Crystal: 0 },
        costTime: 165600,
        exp: 5522,
        kingdomPoint: 61333,
        power: 161792,
        prisonNum: 17,
        speedTime: 61200,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 200}],
        costWEs: [{ idItem: 301101, amount: 138 }],
        attack: 120,
        defense: 120,
        life: 120,
        speed: 320
    },
    57: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 60 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 11200000, Lumber: 5600000, Iron: 840000, Silver: 420000, Crystal: 0 },
        costTime: 169920,
        exp: 5666,
        kingdomPoint: 62933,
        power: 165824,
        prisonNum: 17,
        speedTime: 61200,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 204}],
        costWEs: [{ idItem: 301101, amount: 147 }],
        attack: 120,
        defense: 120,
        life: 120,
        speed: 320
    },
    58: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 60 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 11400000, Lumber: 5700000, Iron: 855000, Silver: 427500, Crystal: 0 },
        costTime: 174240,
        exp: 5810,
        kingdomPoint: 64533,
        power: 169856,
        prisonNum: 17,
        speedTime: 61200,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 208}],
        costWEs: [{ idItem: 301101, amount: 156 }],
        attack: 120,
        defense: 120,
        life: 120,
        speed: 320
    },
    59: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 60 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 11600000, Lumber: 5800000, Iron: 870000, Silver: 435000, Crystal: 0 },
        costTime: 178560,
        exp: 5954,
        kingdomPoint: 66133,
        power: 173888,
        prisonNum: 17,
        speedTime: 61200,
        heroNum: 1,
        costTools: [{ idItem: 310201, amount: 212}],
        costWEs: [{ idItem: 301101, amount: 165 }],
        attack: 120,
        defense: 120,
        life: 120,
        speed: 320
    },
    60: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 60 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 11800000, Lumber: 5900000, Iron: 885000, Silver: 442500, Crystal: 0 },
        costTime: 182880,
        exp: 6098,
        kingdomPoint: 67733,
        power: 177920,
        prisonNum: 18,
        speedTime: 64800,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 216}],
        costWEs: [{ idItem: 301101, amount: 174 }],
        attack: 130,
        defense: 130,
        life: 130,
        speed: 330
    },
    61: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 70 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 12000000, Lumber: 6000000, Iron: 900000, Silver: 450000, Crystal: 0 },
        costTime: 187200,
        exp: 6242,
        kingdomPoint: 69333,
        power: 183120,
        prisonNum: 18,
        speedTime: 64800,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 220}],
        costWEs: [{ idItem: 301101, amount: 180 }],
        attack: 130,
        defense: 130,
        life: 130,
        speed: 330
    },
    62: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 70 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 12200000, Lumber: 6100000, Iron: 915000, Silver: 457500, Crystal: 0 },
        costTime: 191520,
        exp: 6386,
        kingdomPoint: 70933,
        power: 188320,
        prisonNum: 18,
        speedTime: 64800,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 224}],
        costWEs: [{ idItem: 301101, amount: 195 }],
        attack: 130,
        defense: 130,
        life: 130,
        speed: 330
    },
    63: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 70 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 12400000, Lumber: 6200000, Iron: 930000, Silver: 465000, Crystal: 0 },
        costTime: 195840,
        exp: 6530,
        kingdomPoint: 72533,
        power: 193520,
        prisonNum: 18,
        speedTime: 64800,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 228}],
        costWEs: [{ idItem: 301101, amount: 210 }],
        attack: 130,
        defense: 130,
        life: 130,
        speed: 330
    },
    64: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 70 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 12600000, Lumber: 6300000, Iron: 945000, Silver: 472500, Crystal: 0 },
        costTime: 200160,
        exp: 6674,
        kingdomPoint: 74133,
        power: 198720,
        prisonNum: 18,
        speedTime: 64800,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 232}],
        costWEs: [{ idItem: 301101, amount: 225 }],
        attack: 130,
        defense: 130,
        life: 130,
        speed: 330
    },
    65: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 70 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 12800000, Lumber: 6400000, Iron: 960000, Silver: 480000, Crystal: 0 },
        costTime: 204480,
        exp: 6818,
        kingdomPoint: 75733,
        power: 203920,
        prisonNum: 18,
        speedTime: 64800,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 236}],
        costWEs: [{ idItem: 301101, amount: 240 }],
        attack: 130,
        defense: 130,
        life: 130,
        speed: 330
    },
    66: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 70 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 13000000, Lumber: 6500000, Iron: 975000, Silver: 487500, Crystal: 0 },
        costTime: 208800,
        exp: 6962,
        kingdomPoint: 77333,
        power: 209120,
        prisonNum: 18,
        speedTime: 64800,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 240}],
        costWEs: [{ idItem: 301101, amount: 255 }],
        attack: 130,
        defense: 130,
        life: 130,
        speed: 330
    },
    67: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 70 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 13200000, Lumber: 6600000, Iron: 990000, Silver: 495000, Crystal: 0 },
        costTime: 213120,
        exp: 7106,
        kingdomPoint: 78933,
        power: 214320,
        prisonNum: 18,
        speedTime: 64800,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 244}],
        costWEs: [{ idItem: 301101, amount: 270 }],
        attack: 130,
        defense: 130,
        life: 130,
        speed: 330
    },
    68: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 70 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 13400000, Lumber: 6700000, Iron: 1005000, Silver: 502500, Crystal: 0 },
        costTime: 217440,
        exp: 7250,
        kingdomPoint: 80533,
        power: 219520,
        prisonNum: 18,
        speedTime: 64800,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 248}],
        costWEs: [{ idItem: 301101, amount: 285 }],
        attack: 130,
        defense: 130,
        life: 130,
        speed: 330
    },
    69: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 70 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 13600000, Lumber: 6800000, Iron: 1020000, Silver: 510000, Crystal: 0 },
        costTime: 221760,
        exp: 7394,
        kingdomPoint: 82133,
        power: 224720,
        prisonNum: 18,
        speedTime: 64800,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 252}],
        costWEs: [{ idItem: 301101, amount: 300 }],
        attack: 130,
        defense: 130,
        life: 130,
        speed: 330
    },
    70: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 70 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 13800000, Lumber: 6900000, Iron: 1035000, Silver: 517500, Crystal: 0 },
        costTime: 226080,
        exp: 7538,
        kingdomPoint: 83733,
        power: 229920,
        prisonNum: 19,
        speedTime: 68400,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 256}],
        costWEs: [{ idItem: 301101, amount: 315 }],
        attack: 140,
        defense: 140,
        life: 140,
        speed: 340
    },
    71: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 80 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 14000000, Lumber: 7000000, Iron: 1050000, Silver: 525000, Crystal: 0 },
        costTime: 230400,
        exp: 7682,
        kingdomPoint: 85333,
        power: 236312,
        prisonNum: 19,
        speedTime: 68400,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 260}],
        costWEs: [{ idItem: 301101, amount: 360 }],
        attack: 140,
        defense: 140,
        life: 140,
        speed: 340
    },
    72: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 80 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 14200000, Lumber: 7100000, Iron: 1065000, Silver: 532500, Crystal: 0 },
        costTime: 234720,
        exp: 7826,
        kingdomPoint: 86933,
        power: 242704,
        prisonNum: 19,
        speedTime: 68400,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 265}],
        costWEs: [{ idItem: 301101, amount: 390 }],
        attack: 140,
        defense: 140,
        life: 140,
        speed: 340
    },
    73: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 80 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 14400000, Lumber: 7200000, Iron: 1080000, Silver: 540000, Crystal: 0 },
        costTime: 239040,
        exp: 7970,
        kingdomPoint: 88533,
        power: 249096,
        prisonNum: 19,
        speedTime: 68400,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 270}],
        costWEs: [{ idItem: 301101, amount: 420 }],
        attack: 140,
        defense: 140,
        life: 140,
        speed: 340
    },
    74: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 80 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 14600000, Lumber: 7300000, Iron: 1095000, Silver: 547500, Crystal: 0 },
        costTime: 243360,
        exp: 8114,
        kingdomPoint: 90133,
        power: 255488,
        prisonNum: 19,
        speedTime: 68400,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 275}],
        costWEs: [{ idItem: 301101, amount: 450 }],
        attack: 140,
        defense: 140,
        life: 140,
        speed: 340
    },
    75: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 80 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 14800000, Lumber: 7400000, Iron: 1110000, Silver: 555000, Crystal: 0 },
        costTime: 247680,
        exp: 8258,
        kingdomPoint: 91733,
        power: 261880,
        prisonNum: 19,
        speedTime: 68400,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 280}],
        costWEs: [{ idItem: 301101, amount: 480 }],
        attack: 140,
        defense: 140,
        life: 140,
        speed: 340
    },
    76: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 80 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 15000000, Lumber: 7500000, Iron: 1125000, Silver: 562500, Crystal: 0 },
        costTime: 252000,
        exp: 8402,
        kingdomPoint: 93333,
        power: 268272,
        prisonNum: 19,
        speedTime: 68400,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 285}],
        costWEs: [{ idItem: 301101, amount: 510 }],
        attack: 140,
        defense: 140,
        life: 140,
        speed: 340
    },
    77: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 80 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 15200000, Lumber: 7600000, Iron: 1140000, Silver: 570000, Crystal: 0 },
        costTime: 256320,
        exp: 8546,
        kingdomPoint: 94933,
        power: 274664,
        prisonNum: 19,
        speedTime: 68400,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 290}],
        costWEs: [{ idItem: 301101, amount: 540 }],
        attack: 140,
        defense: 140,
        life: 140,
        speed: 340
    },
    78: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 80 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 15400000, Lumber: 7700000, Iron: 1155000, Silver: 577500, Crystal: 0 },
        costTime: 260640,
        exp: 8690,
        kingdomPoint: 96533,
        power: 281056,
        prisonNum: 19,
        speedTime: 68400,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 295}],
        costWEs: [{ idItem: 301101, amount: 570 }],
        attack: 140,
        defense: 140,
        life: 140,
        speed: 340
    },
    79: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 80 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 15600000, Lumber: 7800000, Iron: 1170000, Silver: 585000, Crystal: 0 },
        costTime: 264960,
        exp: 8834,
        kingdomPoint: 98133,
        power: 287448,
        prisonNum: 19,
        speedTime: 68400,
        heroNum: 2,
        costTools: [{ idItem: 310201, amount: 300}],
        costWEs: [{ idItem: 301101, amount: 600 }],
        attack: 140,
        defense: 140,
        life: 140,
        speed: 340
    },
    80: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 80 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 15600000, Lumber: 7800000, Iron: 1170000, Silver: 585000, Crystal: 0 },
        costTime: 269280,
        exp: 8978,
        kingdomPoint: 99733,
        power: 293840,
        prisonNum: 20,
        speedTime: 72000,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 305}],
        costWEs: [{ idItem: 301101, amount: 630 }],
        attack: 150,
        defense: 150,
        life: 150,
        speed: 350
    },
    81: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 90 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 16000000, Lumber: 8000000, Iron: 1200000, Silver: 600000, Crystal: 3000 },
        costTime: 273600,
        exp: 9122,
        kingdomPoint: 101333,
        power: 301056,
        prisonNum: 20,
        speedTime: 72000,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 310}],
        costWEs: [{ idItem: 301901, amount: 75 }],
        attack: 150,
        defense: 150,
        life: 150,
        speed: 350
    },
    82: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 90 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 16400000, Lumber: 8200000, Iron: 1215000, Silver: 607500, Crystal: 9000 },
        costTime: 277920,
        exp: 9266,
        kingdomPoint: 102933,
        power: 308272,
        prisonNum: 20,
        speedTime: 72000,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 316}],
        costWEs: [{ idItem: 301901, amount: 90 }],
        attack: 150,
        defense: 150,
        life: 150,
        speed: 350
    },
    83: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 90 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 16800000, Lumber: 8400000, Iron: 1230000, Silver: 615000, Crystal: 15000 },
        costTime: 282240,
        exp: 9410,
        kingdomPoint: 104533,
        power: 315488,
        prisonNum: 20,
        speedTime: 72000,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 322}],
        costWEs: [{ idItem: 301901, amount: 105 }],
        attack: 150,
        defense: 150,
        life: 150,
        speed: 350
    },
    84: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 90 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 17200000, Lumber: 8600000, Iron: 1245000, Silver: 622500, Crystal: 21000 },
        costTime: 286560,
        exp: 9554,
        kingdomPoint: 106133,
        power: 322704,
        prisonNum: 20,
        speedTime: 72000,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 328}],
        costWEs: [{ idItem: 301901, amount: 120 }],
        attack: 150,
        defense: 150,
        life: 150,
        speed: 350
    },
    85: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 90 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 17600000, Lumber: 8800000, Iron: 1260000, Silver: 630000, Crystal: 27000 },
        costTime: 290880,
        exp: 9698,
        kingdomPoint: 107733,
        power: 329920,
        prisonNum: 20,
        speedTime: 72000,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 334}],
        costWEs: [{ idItem: 301901, amount: 135 }],
        attack: 150,
        defense: 150,
        life: 150,
        speed: 350
    },
    86: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 90 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 18000000, Lumber: 9000000, Iron: 1275000, Silver: 637500, Crystal: 34500 },
        costTime: 295200,
        exp: 9842,
        kingdomPoint: 109333,
        power: 337136,
        prisonNum: 20,
        speedTime: 72000,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 340}],
        costWEs: [{ idItem: 301901, amount: 150 }],
        attack: 150,
        defense: 150,
        life: 150,
        speed: 350
    },
    87: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 90 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 18400000, Lumber: 9200000, Iron: 1290000, Silver: 645000, Crystal: 40500 },
        costTime: 299520,
        exp: 9986,
        kingdomPoint: 110933,
        power: 344352,
        prisonNum: 20,
        speedTime: 72000,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 346}],
        costWEs: [{ idItem: 301901, amount: 165 }],
        attack: 150,
        defense: 150,
        life: 150,
        speed: 350
    },
    88: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 90 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 18800000, Lumber: 9400000, Iron: 1305000, Silver: 652500, Crystal: 46500 },
        costTime: 303840,
        exp: 10130,
        kingdomPoint: 112533,
        power: 351568,
        prisonNum: 20,
        speedTime: 72000,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 352}],
        costWEs: [{ idItem: 301901, amount: 180 }],
        attack: 150,
        defense: 150,
        life: 150,
        speed: 350
    },
    89: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 90 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 19200000, Lumber: 9600000, Iron: 1320000, Silver: 660000, Crystal: 54000 },
        costTime: 308160,
        exp: 10274,
        kingdomPoint: 114133,
        power: 358784,
        prisonNum: 20,
        speedTime: 72000,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 358}],
        costWEs: [{ idItem: 301901, amount: 195 }],
        attack: 150,
        defense: 150,
        life: 150,
        speed: 350
    },
    90: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 90 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 19600000, Lumber: 9800000, Iron: 1335000, Silver: 667500, Crystal: 60000 },
        costTime: 312480,
        exp: 10418,
        kingdomPoint: 115733,
        power: 366000,
        prisonNum: 21,
        speedTime: 79200,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 364}],
        costWEs: [{ idItem: 301901, amount: 210 }],
        attack: 170,
        defense: 170,
        life: 170,
        speed: 360
    },
    91: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 100 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 20000000, Lumber: 10000000, Iron: 1350000, Silver: 675000, Crystal: 67500 },
        costTime: 316800,
        exp: 10562,
        kingdomPoint: 117333,
        power: 373400,
        prisonNum: 21,
        speedTime: 79200,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 370}],
        costWEs: [{ idItem: 301901, amount: 234 }],
        attack: 170,
        defense: 170,
        life: 170,
        speed: 360
    },
    92: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 100 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 20400000, Lumber: 10200000, Iron: 1365000, Silver: 682500, Crystal: 75000 },
        costTime: 321120,
        exp: 10706,
        kingdomPoint: 118933,
        power: 380800,
        prisonNum: 21,
        speedTime: 79200,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 377}],
        costWEs: [{ idItem: 301901, amount: 258 }],
        attack: 170,
        defense: 170,
        life: 170,
        speed: 360
    },
    93: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 100 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 20800000, Lumber: 10400000, Iron: 1380000, Silver: 690000, Crystal: 82500 },
        costTime: 325440,
        exp: 10850,
        kingdomPoint: 120533,
        power: 388200,
        prisonNum: 21,
        speedTime: 79200,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 384}],
        costWEs: [{ idItem: 301901, amount: 282 }],
        attack: 170,
        defense: 170,
        life: 170,
        speed: 360
    },
    94: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 100 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 21200000, Lumber: 10600000, Iron: 1395000, Silver: 697500, Crystal: 90000 },
        costTime: 329760,
        exp: 10994,
        kingdomPoint: 122133,
        power: 395600,
        prisonNum: 21,
        speedTime: 79200,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 391}],
        costWEs: [{ idItem: 301901, amount: 306 }],
        attack: 170,
        defense: 170,
        life: 170,
        speed: 360
    },
    95: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 100 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 21600000, Lumber: 10800000, Iron: 1410000, Silver: 705000, Crystal: 97500 },
        costTime: 334080,
        exp: 11138,
        kingdomPoint: 123733,
        power: 403000,
        prisonNum: 21,
        speedTime: 79200,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 398}],
        costWEs: [{ idItem: 301901, amount: 330 }],
        attack: 170,
        defense: 170,
        life: 170,
        speed: 360
    },
    96: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 100 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 22000000, Lumber: 11000000, Iron: 1425000, Silver: 712500, Crystal: 105000 },
        costTime: 338400,
        exp: 11282,
        kingdomPoint: 125333,
        power: 410400,
        prisonNum: 21,
        speedTime: 79200,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 405}],
        costWEs: [{ idItem: 301901, amount: 354 }],
        attack: 170,
        defense: 170,
        life: 170,
        speed: 360
    },
    97: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 100 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 22400000, Lumber: 11200000, Iron: 1440000, Silver: 720000, Crystal: 112500 },
        costTime: 342720,
        exp: 11426,
        kingdomPoint: 126933,
        power: 417800,
        prisonNum: 21,
        speedTime: 79200,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 412}],
        costWEs: [{ idItem: 301901, amount: 378 }],
        attack: 170,
        defense: 170,
        life: 170,
        speed: 360
    },
    98: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 100 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 22800000, Lumber: 11400000, Iron: 1455000, Silver: 727500, Crystal: 120000 },
        costTime: 347040,
        exp: 11570,
        kingdomPoint: 128533,
        power: 425200,
        prisonNum: 21,
        speedTime: 79200,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 419}],
        costWEs: [{ idItem: 301901, amount: 402 }],
        attack: 170,
        defense: 170,
        life: 170,
        speed: 360
    },
    99: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 100 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 23200000, Lumber: 11600000, Iron: 1470000, Silver: 735000, Crystal: 129000 },
        costTime: 351360,
        exp: 11714,
        kingdomPoint: 130133,
        power: 432600,
        prisonNum: 21,
        speedTime: 79200,
        heroNum: 3,
        costTools: [{ idItem: 310201, amount: 426}],
        costWEs: [{ idItem: 301901, amount: 426 }],
        attack: 170,
        defense: 170,
        life: 170,
        speed: 360
    },
    100: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 100 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 23600000, Lumber: 11800000, Iron: 1485000, Silver: 742500, Crystal: 136500 },
        costTime: 355680,
        exp: 11858,
        kingdomPoint: 131733,
        power: 440000,
        prisonNum: 22,
        speedTime: 86400,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 433}],
        costWEs: [{ idItem: 301901, amount: 450 }],
        attack: 190,
        defense: 190,
        life: 190,
        speed: 370
    },
    101: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 110 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 24000000, Lumber: 12000000, Iron: 1500000, Silver: 750000, Crystal: 145500 },
        costTime: 360000,
        exp: 12002,
        kingdomPoint: 133333,
        power: 448200,
        prisonNum: 22,
        speedTime: 86400,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 440}],
        costWEs: [{ idItem: 301901, amount: 480 }],
        attack: 190,
        defense: 190,
        life: 190,
        speed: 370
    },
    102: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 110 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 24400000, Lumber: 12200000, Iron: 1515000, Silver: 757500, Crystal: 154500 },
        costTime: 364320,
        exp: 12146,
        kingdomPoint: 134933,
        power: 456400,
        prisonNum: 22,
        speedTime: 86400,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 448}],
        costWEs: [{ idItem: 301901, amount: 510 }],
        attack: 190,
        defense: 190,
        life: 190,
        speed: 370
    },
    103: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 110 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 24800000, Lumber: 12400000, Iron: 1530000, Silver: 765000, Crystal: 162000 },
        costTime: 368640,
        exp: 12290,
        kingdomPoint: 136533,
        power: 464600,
        prisonNum: 22,
        speedTime: 86400,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 456}],
        costWEs: [{ idItem: 301901, amount: 540 }],
        attack: 190,
        defense: 190,
        life: 190,
        speed: 370
    },
    104: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 110 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 25200000, Lumber: 12600000, Iron: 1545000, Silver: 772500, Crystal: 171000 },
        costTime: 372960,
        exp: 12434,
        kingdomPoint: 138133,
        power: 472800,
        prisonNum: 22,
        speedTime: 86400,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 464}],
        costWEs: [{ idItem: 301901, amount: 570 }],
        attack: 190,
        defense: 190,
        life: 190,
        speed: 370
    },
    105: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 110 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 25600000, Lumber: 12800000, Iron: 1560000, Silver: 780000, Crystal: 180000 },
        costTime: 377280,
        exp: 12578,
        kingdomPoint: 139733,
        power: 481000,
        prisonNum: 22,
        speedTime: 86400,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 472}],
        costWEs: [{ idItem: 301901, amount: 600 }],
        attack: 190,
        defense: 190,
        life: 190,
        speed: 370
    },
    106: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 110 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 26000000, Lumber: 13000000, Iron: 1575000, Silver: 787500, Crystal: 189000 },
        costTime: 381600,
        exp: 12722,
        kingdomPoint: 141333,
        power: 489200,
        prisonNum: 22,
        speedTime: 86400,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 480}],
        costWEs: [{ idItem: 301901, amount: 630 }],
        attack: 190,
        defense: 190,
        life: 190,
        speed: 370
    },
    107: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 110 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 26400000, Lumber: 13200000, Iron: 1590000, Silver: 795000, Crystal: 199500 },
        costTime: 385920,
        exp: 12866,
        kingdomPoint: 142933,
        power: 497400,
        prisonNum: 22,
        speedTime: 86400,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 488}],
        costWEs: [{ idItem: 301901, amount: 660 }],
        attack: 190,
        defense: 190,
        life: 190,
        speed: 370
    },
    108: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 110 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 26800000, Lumber: 13400000, Iron: 1605000, Silver: 802500, Crystal: 208500 },
        costTime: 390240,
        exp: 13010,
        kingdomPoint: 144533,
        power: 505600,
        prisonNum: 22,
        speedTime: 86400,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 496}],
        costWEs: [{ idItem: 301901, amount: 690 }],
        attack: 190,
        defense: 190,
        life: 190,
        speed: 370
    },
    109: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 110 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 27200000, Lumber: 13600000, Iron: 1620000, Silver: 810000, Crystal: 217500 },
        costTime: 394560,
        exp: 13154,
        kingdomPoint: 146133,
        power: 513800,
        prisonNum: 22,
        speedTime: 86400,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 504}],
        costWEs: [{ idItem: 301901, amount: 720 }],
        attack: 190,
        defense: 190,
        life: 190,
        speed: 370
    },
    110: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 110 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 27600000, Lumber: 13800000, Iron: 1635000, Silver: 817500, Crystal: 228000 },
        costTime: 398880,
        exp: 13298,
        kingdomPoint: 147733,
        power: 522000,
        prisonNum: 23,
        speedTime: 93600,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 512}],
        costWEs: [{ idItem: 301901, amount: 750 }],
        attack: 210,
        defense: 210,
        life: 210,
        speed: 380
    },
    111: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 120 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 28000000, Lumber: 14000000, Iron: 1650000, Silver: 825000, Crystal: 237000 },
        costTime: 403200,
        exp: 13442,
        kingdomPoint: 149333,
        power: 531000,
        prisonNum: 23,
        speedTime: 93600,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 520}],
        costWEs: [{ idItem: 301901, amount: 786 }],
        attack: 210,
        defense: 210,
        life: 210,
        speed: 380
    },
    112: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 120 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 28400000, Lumber: 14200000, Iron: 1665000, Silver: 832500, Crystal: 247500 },
        costTime: 407520,
        exp: 13586,
        kingdomPoint: 150933,
        power: 540000,
        prisonNum: 23,
        speedTime: 93600,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 530}],
        costWEs: [{ idItem: 301901, amount: 822 }],
        attack: 210,
        defense: 210,
        life: 210,
        speed: 380
    },
    113: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 120 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 28800000, Lumber: 14400000, Iron: 1680000, Silver: 840000, Crystal: 256500 },
        costTime: 411840,
        exp: 13730,
        kingdomPoint: 152533,
        power: 549000,
        prisonNum: 23,
        speedTime: 93600,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 540}],
        costWEs: [{ idItem: 301901, amount: 858 }],
        attack: 210,
        defense: 210,
        life: 210,
        speed: 380
    },
    114: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 120 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 29200000, Lumber: 14600000, Iron: 1695000, Silver: 847500, Crystal: 267000 },
        costTime: 416160,
        exp: 13874,
        kingdomPoint: 154133,
        power: 558000,
        prisonNum: 23,
        speedTime: 93600,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 550}],
        costWEs: [{ idItem: 301901, amount: 894 }],
        attack: 210,
        defense: 210,
        life: 210,
        speed: 380
    },
    115: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 120 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 29600000, Lumber: 14800000, Iron: 1710000, Silver: 855000, Crystal: 277500 },
        costTime: 420480,
        exp: 14018,
        kingdomPoint: 155733,
        power: 567000,
        prisonNum: 23,
        speedTime: 93600,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 560}],
        costWEs: [{ idItem: 301901, amount: 930 }],
        attack: 210,
        defense: 210,
        life: 210,
        speed: 380
    },
    116: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 120 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 30000000, Lumber: 15000000, Iron: 1725000, Silver: 862500, Crystal: 288000 },
        costTime: 424800,
        exp: 14162,
        kingdomPoint: 157333,
        power: 576000,
        prisonNum: 23,
        speedTime: 93600,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 570}],
        costWEs: [{ idItem: 301901, amount: 966 }],
        attack: 210,
        defense: 210,
        life: 210,
        speed: 380
    },
    117: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 120 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 30400000, Lumber: 15200000, Iron: 1740000, Silver: 870000, Crystal: 298500 },
        costTime: 429120,
        exp: 14306,
        kingdomPoint: 158933,
        power: 585000,
        prisonNum: 23,
        speedTime: 93600,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 580}],
        costWEs: [{ idItem: 301901, amount: 1002 }],
        attack: 210,
        defense: 210,
        life: 210,
        speed: 380
    },
    118: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 120 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 30800000, Lumber: 15400000, Iron: 1755000, Silver: 877500, Crystal: 309000 },
        costTime: 433440,
        exp: 14450,
        kingdomPoint: 160533,
        power: 594000,
        prisonNum: 23,
        speedTime: 93600,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 590}],
        costWEs: [{ idItem: 301901, amount: 1038 }],
        attack: 210,
        defense: 210,
        life: 210,
        speed: 380
    },
    119: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 120 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 31200000, Lumber: 15600000, Iron: 1770000, Silver: 885000, Crystal: 321000 },
        costTime: 437760,
        exp: 14594,
        kingdomPoint: 162133,
        power: 603000,
        prisonNum: 23,
        speedTime: 93600,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 600}],
        costWEs: [{ idItem: 301901, amount: 1074 }],
        attack: 210,
        defense: 210,
        life: 210,
        speed: 380
    },
    120: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 120 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 31600000, Lumber: 15800000, Iron: 1785000, Silver: 892500, Crystal: 331500 },
        costTime: 442080,
        exp: 14738,
        kingdomPoint: 163733,
        power: 612000,
        prisonNum: 24,
        speedTime: 100800,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 610}],
        costWEs: [{ idItem: 301901, amount: 1110 }],
        attack: 230,
        defense: 230,
        life: 230,
        speed: 390
    },
    121: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 130 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 32000000, Lumber: 16000000, Iron: 1800000, Silver: 900000, Crystal: 343500 },
        costTime: 446400,
        exp: 14882,
        kingdomPoint: 165333,
        power: 621800,
        prisonNum: 24,
        speedTime: 100800,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 620}],
        costWEs: [{ idItem: 301901, amount: 1149 }],
        attack: 230,
        defense: 230,
        life: 230,
        speed: 390
    },
    122: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 130 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 32400000, Lumber: 16200000, Iron: 1815000, Silver: 907500, Crystal: 425400 },
        costTime: 541760,
        exp: 15026,
        kingdomPoint: 166933,
        power: 631600,
        prisonNum: 24,
        speedTime: 100800,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 635}],
        costWEs: [{ idItem: 301901, amount: 1275 }],
        attack: 230,
        defense: 230,
        life: 230,
        speed: 390
    },
    123: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 130 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 32800000, Lumber: 16400000, Iron: 1830000, Silver: 915000, Crystal: 473100 },
        costTime: 588360,
        exp: 15170,
        kingdomPoint: 168533,
        power: 641400,
        prisonNum: 24,
        speedTime: 100800,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 650}],
        costWEs: [{ idItem: 301901, amount: 1404 }],
        attack: 230,
        defense: 230,
        life: 230,
        speed: 390
    },
    124: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 130 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 33200000, Lumber: 16600000, Iron: 1845000, Silver: 922500, Crystal: 522900 },
        costTime: 635360,
        exp: 15314,
        kingdomPoint: 170133,
        power: 651200,
        prisonNum: 24,
        speedTime: 100800,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 665}],
        costWEs: [{ idItem: 301901, amount: 1536 }],
        attack: 230,
        defense: 230,
        life: 230,
        speed: 390
    },
    125: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 130 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 33600000, Lumber: 16800000, Iron: 1860000, Silver: 930000, Crystal: 572100 },
        costTime: 682800,
        exp: 15458,
        kingdomPoint: 171733,
        power: 661000,
        prisonNum: 24,
        speedTime: 100800,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 680}],
        costWEs: [{ idItem: 301901, amount: 1671 }],
        attack: 230,
        defense: 230,
        life: 230,
        speed: 390
    },
    126: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 130 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 34000000, Lumber: 17000000, Iron: 1875000, Silver: 937500, Crystal: 625200 },
        costTime: 730720,
        exp: 15602,
        kingdomPoint: 173333,
        power: 670800,
        prisonNum: 24,
        speedTime: 100800,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 695}],
        costWEs: [{ idItem: 301901, amount: 1809 }],
        attack: 230,
        defense: 230,
        life: 230,
        speed: 390
    },
    127: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 130 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 34400000, Lumber: 17200000, Iron: 1890000, Silver: 945000, Crystal: 680400 },
        costTime: 779160,
        exp: 15746,
        kingdomPoint: 174933,
        power: 680600,
        prisonNum: 24,
        speedTime: 100800,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 710}],
        costWEs: [{ idItem: 301901, amount: 1950 }],
        attack: 230,
        defense: 230,
        life: 230,
        speed: 390
    },
    128: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 130 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 34800000, Lumber: 17400000, Iron: 1905000, Silver: 952500, Crystal: 737700 },
        costTime: 828240,
        exp: 15890,
        kingdomPoint: 176533,
        power: 690400,
        prisonNum: 24,
        speedTime: 100800,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 725}],
        costWEs: [{ idItem: 301901, amount: 2094 }],
        attack: 230,
        defense: 230,
        life: 230,
        speed: 390
    },
    129: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 130 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 35200000, Lumber: 17600000, Iron: 1920000, Silver: 960000, Crystal: 800700 },
        costTime: 879080,
        exp: 16034,
        kingdomPoint: 178133,
        power: 700200,
        prisonNum: 24,
        speedTime: 100800,
        heroNum: 4,
        costTools: [{ idItem: 310201, amount: 740}],
        costWEs: [{ idItem: 301901, amount: 2244 }],
        attack: 230,
        defense: 230,
        life: 230,
        speed: 390
    },
    130: {
        preCond: [
            { buildingType: EBuildingType.Castle, buildingLvl: 130 },
            { buildingType: 123, buildingLvl: 30 }
        ],
        costRes: { Grain: 35600000, Lumber: 17800000, Iron: 1935000, Silver: 967500, Crystal: 864000 },
        costTime: 931720,
        exp: 16178,
        kingdomPoint: 179733,
        power: 710000,
        prisonNum: 25,
        speedTime: 108000,
        heroNum: 5,
        costTools: [{ idItem: 310201, amount: 755}],
        costWEs: [{ idItem: 301901, amount: 2400 }],
        attack: 250,
        defense: 250,
        life: 250,
        speed: 400
    }
};