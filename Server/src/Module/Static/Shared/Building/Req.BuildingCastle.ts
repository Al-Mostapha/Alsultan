const Config = require("../../Include/IncludeConfig");
const CCity = require("../CCity");

module.exports = {
    1: {
        kingdomLv: 0,
        preCond: [],
        costRes: { Grain: 0, Lumber: 0, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 0,
        exp: 0,
        kingdomPoint: 0,
        power: 25,
        unlockedBuild: 118,
        costTools: [],
        costWEs: []
    },
    2: {
        kingdomLv: 0,
        preCond: [],
        costRes: { Grain: 2800, Lumber: 2800, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 210,
        exp: 13,
        kingdomPoint: 48,
        power: 70,
        unlockedBuild: 113,
        costTools: [],
        costWEs: []
    },
    3: {
        kingdomLv: 0,
        preCond: [{ buildingType: 102, buildingLvl: 2 }],
        costRes: { Grain: 4000, Lumber: 4000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 290,
        exp: 22,
        kingdomPoint: 101,
        power: 145,
        unlockedBuild: 117,
        costTools: [],
        costWEs: []
    },
    4: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 3 },
            { buildingType: 202, buildingLvl: 3 }
        ],
        costRes: { Grain: 6000, Lumber: 6000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 1500,
        exp: 73,
        kingdomPoint: 376,
        power: 280,
        unlockedBuild: 120,
        costTools: [],
        costWEs: []
    },
    5: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 4 },
            { buildingType: 201, buildingLvl: 4 }
        ],
        costRes: { Grain: 10000, Lumber: 10000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 3600,
        exp: 142,
        kingdomPoint: 933,
        power: 530,
        unlockedBuild: 119,
        costTools: [],
        costWEs: []
    },
    6: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 5 },
            { buildingType: 105, buildingLvl: 5 }
        ],
        costRes: { Grain: 17000, Lumber: 17000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 7200,
        exp: 279,
        kingdomPoint: 1920,
        power: 960,
        unlockedBuild: 111,
        costTools: [],
        costWEs: []
    },
    7: {
        kingdomLv: 0,
        preCond: [{ buildingType: 102, buildingLvl: 6 }],
        costRes: { Grain: 35000, Lumber: 35000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 14400,
        exp: 416,
        kingdomPoint: 3946,
        power: 1610,
        unlockedBuild: 114,
        costTools: [],
        costWEs: []
    },
    8: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 7 },
            { buildingType: 113, buildingLvl: 7 }
        ],
        costRes: { Grain: 65000, Lumber: 65000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 19800,
        exp: 570,
        kingdomPoint: 5573,
        power: 2495,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    9: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 8 },
            { buildingType: 205, buildingLvl: 8 }
        ],
        costRes: { Grain: 129000, Lumber: 129000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 26700,
        exp: 767,
        kingdomPoint: 7713,
        power: 3535,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    10: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 9 },
            { buildingType: 105, buildingLvl: 9 }
        ],
        costRes: { Grain: 250000, Lumber: 250000, Iron: 0, Silver: 0, Crystal: 0 },
        costTime: 36300,
        exp: 1042,
        kingdomPoint: 10755,
        power: 4760,
        unlockedBuild: 203,
        costTools: [],
        costWEs: []
    },
    11: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 10 },
            { buildingType: 206, buildingLvl: 10 }
        ],
        costRes: { Grain: 400000, Lumber: 400000, Iron: 40000, Silver: 0, Crystal: 0 },
        costTime: 49200,
        exp: 1410,
        kingdomPoint: 14941,
        power: 6200,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    12: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 11 },
            { buildingType: 119, buildingLvl: 11 }
        ],
        costRes: { Grain: 800000, Lumber: 800000, Iron: 80000, Silver: 0, Crystal: 0 },
        costTime: 66900,
        exp: 1916,
        kingdomPoint: 20813,
        power: 7965,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    13: {
        kingdomLv: 0,
        preCond: [{ buildingType: 102, buildingLvl: 12 }],
        costRes: { Grain: 1530000, Lumber: 1530000, Iron: 153000, Silver: 0, Crystal: 0 },
        costTime: 90000,
        exp: 2576,
        kingdomPoint: 28666,
        power: 10120,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    14: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 13 },
            { buildingType: 117, buildingLvl: 13 }
        ],
        costRes: { Grain: 2750000, Lumber: 2750000, Iron: 275000, Silver: 0, Crystal: 0 },
        costTime: 122400,
        exp: 3502,
        kingdomPoint: 39893,
        power: 12755,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    15: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 14 },
            { buildingType: 120, buildingLvl: 14 }
        ],
        costRes: { Grain: 4200000, Lumber: 4200000, Iron: 420000, Silver: 0, Crystal: 0 },
        costTime: 165600,
        exp: 4736,
        kingdomPoint: 55200,
        power: 15970,
        unlockedBuild: 204,
        costTools: [],
        costWEs: []
    },
    16: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 15 },
            { buildingType: 204, buildingLvl: 15 }
        ],
        costRes: { Grain: 5500000, Lumber: 5500000, Iron: 550000, Silver: 34000, Crystal: 0 },
        costTime: 223200,
        exp: 6382,
        kingdomPoint: 76053,
        power: 19905,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    17: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 16 },
            { buildingType: 203, buildingLvl: 16 }
        ],
        costRes: { Grain: 7700000, Lumber: 7700000, Iron: 770000, Silver: 48000, Crystal: 0 },
        costTime: 302400,
        exp: 8645,
        kingdomPoint: 105280,
        power: 24710,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    18: {
        kingdomLv: 0,
        preCond: [{ buildingType: 102, buildingLvl: 17 }],
        costRes: { Grain: 10000000, Lumber: 10000000, Iron: 1000000, Silver: 62000, Crystal: 0 },
        costTime: 345600,
        exp: 9879,
        kingdomPoint: 122880,
        power: 30580,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    19: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 18 },
            { buildingType: 113, buildingLvl: 18 }
        ],
        costRes: { Grain: 13000000, Lumber: 13000000, Iron: 1300000, Silver: 81000, Crystal: 0 },
        costTime: 388800,
        exp: 11113,
        kingdomPoint: 141120,
        power: 37755,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    20: {
        kingdomLv: 0,
        preCond: [{ buildingType: 102, buildingLvl: 19 }],
        costRes: { Grain: 16000000, Lumber: 16000000, Iron: 1600000, Silver: 100000, Crystal: 0 },
        costTime: 442800,
        exp: 12656,
        kingdomPoint: 164000,
        power: 46525,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    21: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 20 },
            { buildingType: 202, buildingLvl: 20 }
        ],
        costRes: { Grain: 20000000, Lumber: 20000000, Iron: 2000000, Silver: 125000, Crystal: 0 },
        costTime: 507600,
        exp: 14507,
        kingdomPoint: 188000,
        power: 56470,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    22: {
        kingdomLv: 0,
        preCond: [{ buildingType: 102, buildingLvl: 21 }],
        costRes: { Grain: 25000000, Lumber: 25000000, Iron: 2500000, Silver: 156000, Crystal: 0 },
        costTime: 583200,
        exp: 16667,
        kingdomPoint: 216000,
        power: 67745,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    23: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 22 },
            { buildingType: 118, buildingLvl: 22 }
        ],
        costRes: { Grain: 30000000, Lumber: 30000000, Iron: 3000000, Silver: 187000, Crystal: 0 },
        costTime: 669600,
        exp: 19136,
        kingdomPoint: 248000,
        power: 80530,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    24: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 23 },
            { buildingType: 116, buildingLvl: 23 }
        ],
        costRes: { Grain: 40000000, Lumber: 40000000, Iron: 4000000, Silver: 250000, Crystal: 0 },
        costTime: 770400,
        exp: 22016,
        kingdomPoint: 285333,
        power: 95035,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    25: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 24 },
            { buildingType: 113, buildingLvl: 24 }
        ],
        costRes: { Grain: 55000000, Lumber: 55000000, Iron: 5500000, Silver: 343000, Crystal: 0 },
        costTime: 885600,
        exp: 25307,
        kingdomPoint: 328000,
        power: 111475,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    26: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 25 },
            { buildingType: 111, buildingLvl: 25 }
        ],
        costRes: { Grain: 75000000, Lumber: 75000000, Iron: 7500000, Silver: 468000, Crystal: 0 },
        costTime: 1015200,
        exp: 29010,
        kingdomPoint: 376000,
        power: 130125,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    27: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 26 },
            { buildingType: 114, buildingLvl: 26 }
        ],
        costRes: { Grain: 100000000, Lumber: 100000000, Iron: 10000000, Silver: 625000, Crystal: 0 },
        costTime: 1159200,
        exp: 33125,
        kingdomPoint: 429333,
        power: 151270,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    28: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 27 },
            { buildingType: 118, buildingLvl: 27 }
        ],
        costRes: { Grain: 130000000, Lumber: 130000000, Iron: 13000000, Silver: 812000, Crystal: 0 },
        costTime: 1317600,
        exp: 37650,
        kingdomPoint: 488000,
        power: 175250,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    29: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 28 },
            { buildingType: 119, buildingLvl: 28 }
        ],
        costRes: { Grain: 170000000, Lumber: 170000000, Iron: 17000000, Silver: 1062000, Crystal: 0 },
        costTime: 1490400,
        exp: 42587,
        kingdomPoint: 552000,
        power: 202440,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    30: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 29 },
            { buildingType: 117, buildingLvl: 29 }
        ],
        costRes: { Grain: 220000000, Lumber: 220000000, Iron: 22000000, Silver: 1375000, Crystal: 0 },
        costTime: 1706400,
        exp: 48759,
        kingdomPoint: 632000,
        power: 233280,
        unlockedBuild: 0,
        costTools: [],
        costWEs: []
    },
    31: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 30 },
            { buildingType: 301, buildingLvl: 30 }
        ],
        costRes: { Grain: 15000000, Lumber: 15000000, Iron: 1500000, Silver: 750000, Crystal: 0 },
        costTime: 144000,
        exp: 4805,
        kingdomPoint: 53333,
        power: 237282,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 10 }]
    },
    32: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 30 },
            { buildingType: 301, buildingLvl: 30 }
        ],
        costRes: { Grain: 15500000, Lumber: 15500000, Iron: 1550000, Silver: 775000, Crystal: 0 },
        costTime: 154800,
        exp: 5165,
        kingdomPoint: 57333,
        power: 241284,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 20 }]
    },
    33: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 30 },
            { buildingType: 301, buildingLvl: 30 }
        ],
        costRes: { Grain: 16000000, Lumber: 16000000, Iron: 1600000, Silver: 800000, Crystal: 0 },
        costTime: 165600,
        exp: 5525,
        kingdomPoint: 61333,
        power: 245286,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 30 }]
    },
    34: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 30 },
            { buildingType: 301, buildingLvl: 30 }
        ],
        costRes: { Grain: 16500000, Lumber: 16500000, Iron: 1650000, Silver: 825000, Crystal: 0 },
        costTime: 176400,
        exp: 5885,
        kingdomPoint: 65333,
        power: 249288,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 40 }]
    },
    35: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 30 },
            { buildingType: 301, buildingLvl: 30 }
        ],
        costRes: { Grain: 17000000, Lumber: 17000000, Iron: 1700000, Silver: 850000, Crystal: 0 },
        costTime: 187200,
        exp: 6245,
        kingdomPoint: 69333,
        power: 253290,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 50 }]
    },
    36: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 30 },
            { buildingType: 301, buildingLvl: 30 }
        ],
        costRes: { Grain: 17500000, Lumber: 17500000, Iron: 1750000, Silver: 875000, Crystal: 0 },
        costTime: 198000,
        exp: 6605,
        kingdomPoint: 73333,
        power: 257292,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 60 }]
    },
    37: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 30 },
            { buildingType: 301, buildingLvl: 30 }
        ],
        costRes: { Grain: 18000000, Lumber: 18000000, Iron: 1800000, Silver: 900000, Crystal: 0 },
        costTime: 208800,
        exp: 6965,
        kingdomPoint: 77333,
        power: 261294,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 70 }]
    },
    38: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 30 },
            { buildingType: 301, buildingLvl: 30 }
        ],
        costRes: { Grain: 18500000, Lumber: 18500000, Iron: 1850000, Silver: 925000, Crystal: 0 },
        costTime: 219600,
        exp: 7325,
        kingdomPoint: 81333,
        power: 265296,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 80 }]
    },
    39: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 30 },
            { buildingType: 301, buildingLvl: 30 }
        ],
        costRes: { Grain: 19000000, Lumber: 19000000, Iron: 1900000, Silver: 950000, Crystal: 0 },
        costTime: 230400,
        exp: 7685,
        kingdomPoint: 85333,
        power: 269298,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 90 }]
    },
    40: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 30 },
            { buildingType: 301, buildingLvl: 30 }
        ],
        costRes: { Grain: 19500000, Lumber: 19500000, Iron: 1950000, Silver: 975000, Crystal: 0 },
        costTime: 241200,
        exp: 8045,
        kingdomPoint: 89333,
        power: 273300,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 100 }]
    },
    41: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 40 },
            { buildingType: 301, buildingLvl: 40 }
        ],
        costRes: { Grain: 20000000, Lumber: 20000000, Iron: 2000000, Silver: 1000000, Crystal: 0 },
        costTime: 252000,
        exp: 8405,
        kingdomPoint: 93333,
        power: 280370,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 100 }]
    },
    42: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 40 },
            { buildingType: 301, buildingLvl: 40 }
        ],
        costRes: { Grain: 20500000, Lumber: 20500000, Iron: 2050000, Silver: 1025000, Crystal: 0 },
        costTime: 262800,
        exp: 8765,
        kingdomPoint: 97333,
        power: 287440,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 120 }]
    },
    43: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 40 },
            { buildingType: 301, buildingLvl: 40 }
        ],
        costRes: { Grain: 21000000, Lumber: 21000000, Iron: 2100000, Silver: 1050000, Crystal: 0 },
        costTime: 273600,
        exp: 9125,
        kingdomPoint: 101333,
        power: 294510,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 140 }]
    },
    44: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 40 },
            { buildingType: 301, buildingLvl: 40 }
        ],
        costRes: { Grain: 21500000, Lumber: 21500000, Iron: 2150000, Silver: 1075000, Crystal: 0 },
        costTime: 284400,
        exp: 9485,
        kingdomPoint: 105333,
        power: 301580,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 160 }]
    },
    45: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 40 },
            { buildingType: 301, buildingLvl: 40 }
        ],
        costRes: { Grain: 22000000, Lumber: 22000000, Iron: 2200000, Silver: 1100000, Crystal: 0 },
        costTime: 295200,
        exp: 9845,
        kingdomPoint: 109333,
        power: 308650,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 180 }]
    },
    46: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 40 },
            { buildingType: 301, buildingLvl: 40 }
        ],
        costRes: { Grain: 22500000, Lumber: 22500000, Iron: 2250000, Silver: 1125000, Crystal: 0 },
        costTime: 306000,
        exp: 10205,
        kingdomPoint: 113333,
        power: 315720,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 200 }]
    },
    47: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 40 },
            { buildingType: 301, buildingLvl: 40 }
        ],
        costRes: { Grain: 23000000, Lumber: 23000000, Iron: 2300000, Silver: 1150000, Crystal: 0 },
        costTime: 316800,
        exp: 10565,
        kingdomPoint: 117333,
        power: 322790,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 220 }]
    },
    48: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 40 },
            { buildingType: 301, buildingLvl: 40 }
        ],
        costRes: { Grain: 23500000, Lumber: 23500000, Iron: 2350000, Silver: 1175000, Crystal: 0 },
        costTime: 327600,
        exp: 10925,
        kingdomPoint: 121333,
        power: 329860,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 240 }]
    },
    49: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 40 },
            { buildingType: 301, buildingLvl: 40 }
        ],
        costRes: { Grain: 24000000, Lumber: 24000000, Iron: 2400000, Silver: 1200000, Crystal: 0 },
        costTime: 338400,
        exp: 11285,
        kingdomPoint: 125333,
        power: 336930,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 260 }]
    },
    50: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 40 },
            { buildingType: 301, buildingLvl: 40 }
        ],
        costRes: { Grain: 24500000, Lumber: 24500000, Iron: 2450000, Silver: 1225000, Crystal: 0 },
        costTime: 349200,
        exp: 11645,
        kingdomPoint: 129333,
        power: 344000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 280 }]
    },
    51: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 50 },
            { buildingType: 301, buildingLvl: 50 }
        ],
        costRes: { Grain: 25000000, Lumber: 25000000, Iron: 2500000, Silver: 1250000, Crystal: 0 },
        costTime: 360000,
        exp: 12005,
        kingdomPoint: 133333,
        power: 354080,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 310 }]
    },
    52: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 50 },
            { buildingType: 301, buildingLvl: 50 }
        ],
        costRes: { Grain: 25500000, Lumber: 25500000, Iron: 2550000, Silver: 1275000, Crystal: 0 },
        costTime: 370800,
        exp: 12365,
        kingdomPoint: 137333,
        power: 364160,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 340 }]
    },
    53: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 50 },
            { buildingType: 301, buildingLvl: 50 }
        ],
        costRes: { Grain: 26000000, Lumber: 26000000, Iron: 2600000, Silver: 1300000, Crystal: 0 },
        costTime: 381600,
        exp: 12725,
        kingdomPoint: 141333,
        power: 374240,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 370 }]
    },
    54: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 50 },
            { buildingType: 301, buildingLvl: 50 }
        ],
        costRes: { Grain: 26500000, Lumber: 26500000, Iron: 2650000, Silver: 1325000, Crystal: 0 },
        costTime: 392400,
        exp: 13085,
        kingdomPoint: 145333,
        power: 384320,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 400 }]
    },
    55: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 50 },
            { buildingType: 301, buildingLvl: 50 }
        ],
        costRes: { Grain: 27000000, Lumber: 27000000, Iron: 2700000, Silver: 1350000, Crystal: 0 },
        costTime: 403200,
        exp: 13445,
        kingdomPoint: 149333,
        power: 394400,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 430 }]
    },
    56: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 50 },
            { buildingType: 301, buildingLvl: 50 }
        ],
        costRes: { Grain: 27500000, Lumber: 27500000, Iron: 2750000, Silver: 1375000, Crystal: 0 },
        costTime: 414000,
        exp: 13805,
        kingdomPoint: 153333,
        power: 404480,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 460 }]
    },
    57: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 50 },
            { buildingType: 301, buildingLvl: 50 }
        ],
        costRes: { Grain: 28000000, Lumber: 28000000, Iron: 2800000, Silver: 1400000, Crystal: 0 },
        costTime: 424800,
        exp: 14165,
        kingdomPoint: 157333,
        power: 414560,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 490 }]
    },
    58: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 50 },
            { buildingType: 301, buildingLvl: 50 }
        ],
        costRes: { Grain: 28500000, Lumber: 28500000, Iron: 2850000, Silver: 1425000, Crystal: 0 },
        costTime: 435600,
        exp: 14525,
        kingdomPoint: 161333,
        power: 424640,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 520 }]
    },
    59: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 50 },
            { buildingType: 301, buildingLvl: 50 }
        ],
        costRes: { Grain: 29000000, Lumber: 29000000, Iron: 2900000, Silver: 1450000, Crystal: 0 },
        costTime: 446400,
        exp: 14885,
        kingdomPoint: 165333,
        power: 434720,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 550 }]
    },
    60: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 50 },
            { buildingType: 301, buildingLvl: 50 }
        ],
        costRes: { Grain: 29500000, Lumber: 29500000, Iron: 2950000, Silver: 1475000, Crystal: 0 },
        costTime: 457200,
        exp: 15245,
        kingdomPoint: 169333,
        power: 444800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 580 }]
    },
    61: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 60 },
            { buildingType: 301, buildingLvl: 60 }
        ],
        costRes: { Grain: 30000000, Lumber: 30000000, Iron: 3000000, Silver: 1500000, Crystal: 0 },
        costTime: 468000,
        exp: 15605,
        kingdomPoint: 173333,
        power: 457800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 600 }]
    },
    62: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 60 },
            { buildingType: 301, buildingLvl: 60 }
        ],
        costRes: { Grain: 30500000, Lumber: 30500000, Iron: 3050000, Silver: 1525000, Crystal: 0 },
        costTime: 478800,
        exp: 15965,
        kingdomPoint: 177333,
        power: 470800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 650 }]
    },
    63: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 60 },
            { buildingType: 301, buildingLvl: 60 }
        ],
        costRes: { Grain: 31000000, Lumber: 31000000, Iron: 3100000, Silver: 1550000, Crystal: 0 },
        costTime: 489600,
        exp: 16325,
        kingdomPoint: 181333,
        power: 483800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 700 }]
    },
    64: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 60 },
            { buildingType: 301, buildingLvl: 60 }
        ],
        costRes: { Grain: 31500000, Lumber: 31500000, Iron: 3150000, Silver: 1575000, Crystal: 0 },
        costTime: 500400,
        exp: 16685,
        kingdomPoint: 185333,
        power: 496800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 750 }]
    },
    65: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 60 },
            { buildingType: 301, buildingLvl: 60 }
        ],
        costRes: { Grain: 32000000, Lumber: 32000000, Iron: 3200000, Silver: 1600000, Crystal: 0 },
        costTime: 511200,
        exp: 17045,
        kingdomPoint: 189333,
        power: 509800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 800 }]
    },
    66: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 60 },
            { buildingType: 301, buildingLvl: 60 }
        ],
        costRes: { Grain: 32500000, Lumber: 32500000, Iron: 3250000, Silver: 1625000, Crystal: 0 },
        costTime: 522000,
        exp: 17405,
        kingdomPoint: 193333,
        power: 522800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 850 }]
    },
    67: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 60 },
            { buildingType: 301, buildingLvl: 60 }
        ],
        costRes: { Grain: 33000000, Lumber: 33000000, Iron: 3300000, Silver: 1650000, Crystal: 0 },
        costTime: 532800,
        exp: 17765,
        kingdomPoint: 197333,
        power: 535800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 900 }]
    },
    68: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 60 },
            { buildingType: 301, buildingLvl: 60 }
        ],
        costRes: { Grain: 33500000, Lumber: 33500000, Iron: 3350000, Silver: 1675000, Crystal: 0 },
        costTime: 543600,
        exp: 18125,
        kingdomPoint: 201333,
        power: 548800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 950 }]
    },
    69: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 60 },
            { buildingType: 301, buildingLvl: 60 }
        ],
        costRes: { Grain: 34000000, Lumber: 34000000, Iron: 3400000, Silver: 1700000, Crystal: 0 },
        costTime: 554400,
        exp: 18485,
        kingdomPoint: 205333,
        power: 561800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 1000 }]
    },
    70: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 60 },
            { buildingType: 301, buildingLvl: 60 }
        ],
        costRes: { Grain: 34500000, Lumber: 34500000, Iron: 3450000, Silver: 1725000, Crystal: 0 },
        costTime: 565200,
        exp: 18845,
        kingdomPoint: 209333,
        power: 574800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 1050 }]
    },
    71: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 70 },
            { buildingType: 301, buildingLvl: 70 }
        ],
        costRes: { Grain: 35000000, Lumber: 35000000, Iron: 3500000, Silver: 1750000, Crystal: 0 },
        costTime: 576000,
        exp: 19205,
        kingdomPoint: 213333,
        power: 590780,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 1200 }]
    },
    72: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 70 },
            { buildingType: 301, buildingLvl: 70 }
        ],
        costRes: { Grain: 35500000, Lumber: 35500000, Iron: 3550000, Silver: 1775000, Crystal: 0 },
        costTime: 586800,
        exp: 19565,
        kingdomPoint: 217333,
        power: 606760,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 1300 }]
    },
    73: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 70 },
            { buildingType: 301, buildingLvl: 70 }
        ],
        costRes: { Grain: 36000000, Lumber: 36000000, Iron: 3600000, Silver: 1800000, Crystal: 0 },
        costTime: 597600,
        exp: 19925,
        kingdomPoint: 221333,
        power: 622740,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 1400 }]
    },
    74: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 70 },
            { buildingType: 301, buildingLvl: 70 }
        ],
        costRes: { Grain: 36500000, Lumber: 36500000, Iron: 3650000, Silver: 1825000, Crystal: 0 },
        costTime: 608400,
        exp: 20285,
        kingdomPoint: 225333,
        power: 638720,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 1500 }]
    },
    75: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 70 },
            { buildingType: 301, buildingLvl: 70 }
        ],
        costRes: { Grain: 37000000, Lumber: 37000000, Iron: 3700000, Silver: 1850000, Crystal: 0 },
        costTime: 619200,
        exp: 20645,
        kingdomPoint: 229333,
        power: 654700,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 1600 }]
    },
    76: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 70 },
            { buildingType: 301, buildingLvl: 70 }
        ],
        costRes: { Grain: 37500000, Lumber: 37500000, Iron: 3750000, Silver: 1875000, Crystal: 0 },
        costTime: 630000,
        exp: 21005,
        kingdomPoint: 233333,
        power: 670680,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 1700 }]
    },
    77: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 70 },
            { buildingType: 301, buildingLvl: 70 }
        ],
        costRes: { Grain: 38000000, Lumber: 38000000, Iron: 3800000, Silver: 1900000, Crystal: 0 },
        costTime: 640800,
        exp: 21365,
        kingdomPoint: 237333,
        power: 686660,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 1800 }]
    },
    78: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 70 },
            { buildingType: 301, buildingLvl: 70 }
        ],
        costRes: { Grain: 38500000, Lumber: 38500000, Iron: 3850000, Silver: 1925000, Crystal: 0 },
        costTime: 651600,
        exp: 21725,
        kingdomPoint: 241333,
        power: 702640,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 1900 }]
    },
    79: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 70 },
            { buildingType: 301, buildingLvl: 70 }
        ],
        costRes: { Grain: 39000000, Lumber: 39000000, Iron: 3900000, Silver: 1950000, Crystal: 0 },
        costTime: 662400,
        exp: 22085,
        kingdomPoint: 245333,
        power: 718620,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 2000 }]
    },
    80: {
        kingdomLv: 0,
        preCond: [
            { buildingType: 102, buildingLvl: 70 },
            { buildingType: 301, buildingLvl: 70 }
        ],
        costRes: { Grain: 39000000, Lumber: 39000000, Iron: 3900000, Silver: 1950000, Crystal: 0 },
        costTime: 673200,
        exp: 22445,
        kingdomPoint: 249333,
        power: 734600,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301101, amount: 2100 }]
    },
    81: {
        kingdomLv: 10,
        preCond: [
            { buildingType: 102, buildingLvl: 80 },
            { buildingType: 301, buildingLvl: 80 }
        ],
        costRes: { Grain: 40000000, Lumber: 40000000, Iron: 4000000, Silver: 2000000, Crystal: 10000 },
        costTime: 684000,
        exp: 22805,
        kingdomPoint: 253333,
        power: 752640,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 250 }]
    },
    82: {
        kingdomLv: 10,
        preCond: [
            { buildingType: 102, buildingLvl: 80 },
            { buildingType: 301, buildingLvl: 80 }
        ],
        costRes: { Grain: 41000000, Lumber: 41000000, Iron: 4050000, Silver: 2025000, Crystal: 30000 },
        costTime: 694800,
        exp: 23165,
        kingdomPoint: 257333,
        power: 770680,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 300 }]
    },
    83: {
        kingdomLv: 10,
        preCond: [
            { buildingType: 102, buildingLvl: 80 },
            { buildingType: 301, buildingLvl: 80 }
        ],
        costRes: { Grain: 42000000, Lumber: 42000000, Iron: 4100000, Silver: 2050000, Crystal: 50000 },
        costTime: 705600,
        exp: 23525,
        kingdomPoint: 261333,
        power: 788720,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 350 }]
    },
    84: {
        kingdomLv: 10,
        preCond: [
            { buildingType: 102, buildingLvl: 80 },
            { buildingType: 301, buildingLvl: 80 }
        ],
        costRes: { Grain: 43000000, Lumber: 43000000, Iron: 4150000, Silver: 2075000, Crystal: 70000 },
        costTime: 716400,
        exp: 23885,
        kingdomPoint: 265333,
        power: 806760,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 400 }]
    },
    85: {
        kingdomLv: 10,
        preCond: [
            { buildingType: 102, buildingLvl: 80 },
            { buildingType: 301, buildingLvl: 80 }
        ],
        costRes: { Grain: 44000000, Lumber: 44000000, Iron: 4200000, Silver: 2100000, Crystal: 90000 },
        costTime: 727200,
        exp: 24245,
        kingdomPoint: 269333,
        power: 824800,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 450 }]
    },
    86: {
        kingdomLv: 10,
        preCond: [
            { buildingType: 102, buildingLvl: 80 },
            { buildingType: 301, buildingLvl: 80 }
        ],
        costRes: { Grain: 45000000, Lumber: 45000000, Iron: 4250000, Silver: 2125000, Crystal: 115000 },
        costTime: 738000,
        exp: 24605,
        kingdomPoint: 273333,
        power: 842840,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 500 }]
    },
    87: {
        kingdomLv: 10,
        preCond: [
            { buildingType: 102, buildingLvl: 80 },
            { buildingType: 301, buildingLvl: 80 }
        ],
        costRes: { Grain: 46000000, Lumber: 46000000, Iron: 4300000, Silver: 2150000, Crystal: 135000 },
        costTime: 748800,
        exp: 24965,
        kingdomPoint: 277333,
        power: 860880,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 550 }]
    },
    88: {
        kingdomLv: 10,
        preCond: [
            { buildingType: 102, buildingLvl: 80 },
            { buildingType: 301, buildingLvl: 80 }
        ],
        costRes: { Grain: 47000000, Lumber: 47000000, Iron: 4350000, Silver: 2175000, Crystal: 155000 },
        costTime: 759600,
        exp: 25325,
        kingdomPoint: 281333,
        power: 878920,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 600 }]
    },
    89: {
        kingdomLv: 10,
        preCond: [
            { buildingType: 102, buildingLvl: 80 },
            { buildingType: 301, buildingLvl: 80 }
        ],
        costRes: { Grain: 48000000, Lumber: 48000000, Iron: 4400000, Silver: 2200000, Crystal: 180000 },
        costTime: 770400,
        exp: 25685,
        kingdomPoint: 285333,
        power: 896960,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 650 }]
    },
    90: {
        kingdomLv: 10,
        preCond: [
            { buildingType: 102, buildingLvl: 80 },
            { buildingType: 301, buildingLvl: 80 }
        ],
        costRes: { Grain: 49000000, Lumber: 49000000, Iron: 4450000, Silver: 2225000, Crystal: 200000 },
        costTime: 781200,
        exp: 26045,
        kingdomPoint: 289333,
        power: 915000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 700 }]
    },
    91: {
        kingdomLv: 20,
        preCond: [
            { buildingType: 102, buildingLvl: 90 },
            { buildingType: 301, buildingLvl: 90 }
        ],
        costRes: { Grain: 50000000, Lumber: 50000000, Iron: 4500000, Silver: 2250000, Crystal: 225000 },
        costTime: 792000,
        exp: 26405,
        kingdomPoint: 293333,
        power: 933500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 780 }]
    },
    92: {
        kingdomLv: 20,
        preCond: [
            { buildingType: 102, buildingLvl: 90 },
            { buildingType: 301, buildingLvl: 90 }
        ],
        costRes: { Grain: 51000000, Lumber: 51000000, Iron: 4550000, Silver: 2275000, Crystal: 250000 },
        costTime: 802800,
        exp: 26765,
        kingdomPoint: 297333,
        power: 952000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 860 }]
    },
    93: {
        kingdomLv: 20,
        preCond: [
            { buildingType: 102, buildingLvl: 90 },
            { buildingType: 301, buildingLvl: 90 }
        ],
        costRes: { Grain: 52000000, Lumber: 52000000, Iron: 4600000, Silver: 2300000, Crystal: 275000 },
        costTime: 813600,
        exp: 27125,
        kingdomPoint: 301333,
        power: 970500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 940 }]
    },
    94: {
        kingdomLv: 20,
        preCond: [
            { buildingType: 102, buildingLvl: 90 },
            { buildingType: 301, buildingLvl: 90 }
        ],
        costRes: { Grain: 53000000, Lumber: 53000000, Iron: 4650000, Silver: 2325000, Crystal: 300000 },
        costTime: 824400,
        exp: 27485,
        kingdomPoint: 305333,
        power: 989000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1020 }]
    },
    95: {
        kingdomLv: 20,
        preCond: [
            { buildingType: 102, buildingLvl: 90 },
            { buildingType: 301, buildingLvl: 90 }
        ],
        costRes: { Grain: 54000000, Lumber: 54000000, Iron: 4700000, Silver: 2350000, Crystal: 325000 },
        costTime: 835200,
        exp: 27845,
        kingdomPoint: 309333,
        power: 1007500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1100 }]
    },
    96: {
        kingdomLv: 20,
        preCond: [
            { buildingType: 102, buildingLvl: 90 },
            { buildingType: 301, buildingLvl: 90 }
        ],
        costRes: { Grain: 55000000, Lumber: 55000000, Iron: 4750000, Silver: 2375000, Crystal: 350000 },
        costTime: 846000,
        exp: 28205,
        kingdomPoint: 313333,
        power: 1026000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1180 }]
    },
    97: {
        kingdomLv: 20,
        preCond: [
            { buildingType: 102, buildingLvl: 90 },
            { buildingType: 301, buildingLvl: 90 }
        ],
        costRes: { Grain: 56000000, Lumber: 56000000, Iron: 4800000, Silver: 2400000, Crystal: 375000 },
        costTime: 856800,
        exp: 28565,
        kingdomPoint: 317333,
        power: 1044500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1260 }]
    },
    98: {
        kingdomLv: 20,
        preCond: [
            { buildingType: 102, buildingLvl: 90 },
            { buildingType: 301, buildingLvl: 90 }
        ],
        costRes: { Grain: 57000000, Lumber: 57000000, Iron: 4850000, Silver: 2425000, Crystal: 400000 },
        costTime: 867600,
        exp: 28925,
        kingdomPoint: 321333,
        power: 1063000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1340 }]
    },
    99: {
        kingdomLv: 20,
        preCond: [
            { buildingType: 102, buildingLvl: 90 },
            { buildingType: 301, buildingLvl: 90 }
        ],
        costRes: { Grain: 58000000, Lumber: 58000000, Iron: 4900000, Silver: 2450000, Crystal: 430000 },
        costTime: 878400,
        exp: 29285,
        kingdomPoint: 325333,
        power: 1081500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1420 }]
    },
    100: {
        kingdomLv: 20,
        preCond: [
            { buildingType: 102, buildingLvl: 90 },
            { buildingType: 301, buildingLvl: 90 }
        ],
        costRes: { Grain: 59000000, Lumber: 59000000, Iron: 4950000, Silver: 2475000, Crystal: 455000 },
        costTime: 889200,
        exp: 29645,
        kingdomPoint: 329333,
        power: 1100000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1500 }]
    },
    101: {
        kingdomLv: 30,
        preCond: [
            { buildingType: 102, buildingLvl: 100 },
            { buildingType: 301, buildingLvl: 100 }
        ],
        costRes: { Grain: 60000000, Lumber: 60000000, Iron: 5000000, Silver: 2500000, Crystal: 485000 },
        costTime: 900000,
        exp: 30005,
        kingdomPoint: 333333,
        power: 1120500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1600 }]
    },
    102: {
        kingdomLv: 30,
        preCond: [
            { buildingType: 102, buildingLvl: 100 },
            { buildingType: 301, buildingLvl: 100 }
        ],
        costRes: { Grain: 61000000, Lumber: 61000000, Iron: 5050000, Silver: 2525000, Crystal: 515000 },
        costTime: 910800,
        exp: 30365,
        kingdomPoint: 337333,
        power: 1141000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1700 }]
    },
    103: {
        kingdomLv: 30,
        preCond: [
            { buildingType: 102, buildingLvl: 100 },
            { buildingType: 301, buildingLvl: 100 }
        ],
        costRes: { Grain: 62000000, Lumber: 62000000, Iron: 5100000, Silver: 2550000, Crystal: 540000 },
        costTime: 921600,
        exp: 30725,
        kingdomPoint: 341333,
        power: 1161500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1800 }]
    },
    104: {
        kingdomLv: 30,
        preCond: [
            { buildingType: 102, buildingLvl: 100 },
            { buildingType: 301, buildingLvl: 100 }
        ],
        costRes: { Grain: 63000000, Lumber: 63000000, Iron: 5150000, Silver: 2575000, Crystal: 570000 },
        costTime: 932400,
        exp: 31085,
        kingdomPoint: 345333,
        power: 1182000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1900 }]
    },
    105: {
        kingdomLv: 30,
        preCond: [
            { buildingType: 102, buildingLvl: 100 },
            { buildingType: 301, buildingLvl: 100 }
        ],
        costRes: { Grain: 64000000, Lumber: 64000000, Iron: 5200000, Silver: 2600000, Crystal: 600000 },
        costTime: 943200,
        exp: 31445,
        kingdomPoint: 349333,
        power: 1202500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 2000 }]
    },
    106: {
        kingdomLv: 30,
        preCond: [
            { buildingType: 102, buildingLvl: 100 },
            { buildingType: 301, buildingLvl: 100 }
        ],
        costRes: { Grain: 65000000, Lumber: 65000000, Iron: 5250000, Silver: 2625000, Crystal: 630000 },
        costTime: 954000,
        exp: 31805,
        kingdomPoint: 353333,
        power: 1223000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 2100 }]
    },
    107: {
        kingdomLv: 30,
        preCond: [
            { buildingType: 102, buildingLvl: 100 },
            { buildingType: 301, buildingLvl: 100 }
        ],
        costRes: { Grain: 66000000, Lumber: 66000000, Iron: 5300000, Silver: 2650000, Crystal: 665000 },
        costTime: 964800,
        exp: 32165,
        kingdomPoint: 357333,
        power: 1243500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 2200 }]
    },
    108: {
        kingdomLv: 30,
        preCond: [
            { buildingType: 102, buildingLvl: 100 },
            { buildingType: 301, buildingLvl: 100 }
        ],
        costRes: { Grain: 67000000, Lumber: 67000000, Iron: 5350000, Silver: 2675000, Crystal: 695000 },
        costTime: 975600,
        exp: 32525,
        kingdomPoint: 361333,
        power: 1264000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 2300 }]
    },
    109: {
        kingdomLv: 30,
        preCond: [
            { buildingType: 102, buildingLvl: 100 },
            { buildingType: 301, buildingLvl: 100 }
        ],
        costRes: { Grain: 68000000, Lumber: 68000000, Iron: 5400000, Silver: 2700000, Crystal: 725000 },
        costTime: 986400,
        exp: 32885,
        kingdomPoint: 365333,
        power: 1284500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 2400 }]
    },
    110: {
        kingdomLv: 30,
        preCond: [
            { buildingType: 102, buildingLvl: 100 },
            { buildingType: 301, buildingLvl: 100 }
        ],
        costRes: { Grain: 69000000, Lumber: 69000000, Iron: 5450000, Silver: 2725000, Crystal: 760000 },
        costTime: 997200,
        exp: 33245,
        kingdomPoint: 369333,
        power: 1305000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 2500 }]
    },
    111: {
        kingdomLv: 40,
        preCond: [
            { buildingType: 102, buildingLvl: 110 },
            { buildingType: 301, buildingLvl: 110 }
        ],
        costRes: { Grain: 70000000, Lumber: 70000000, Iron: 5500000, Silver: 2750000, Crystal: 790000 },
        costTime: 1008000,
        exp: 33605,
        kingdomPoint: 373333,
        power: 1327500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 2620 }]
    },
    112: {
        kingdomLv: 40,
        preCond: [
            { buildingType: 102, buildingLvl: 110 },
            { buildingType: 301, buildingLvl: 110 }
        ],
        costRes: { Grain: 71000000, Lumber: 71000000, Iron: 5550000, Silver: 2775000, Crystal: 825000 },
        costTime: 1018800,
        exp: 33965,
        kingdomPoint: 377333,
        power: 1350000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 2740 }]
    },
    113: {
        kingdomLv: 40,
        preCond: [
            { buildingType: 102, buildingLvl: 110 },
            { buildingType: 301, buildingLvl: 110 }
        ],
        costRes: { Grain: 72000000, Lumber: 72000000, Iron: 5600000, Silver: 2800000, Crystal: 855000 },
        costTime: 1029600,
        exp: 34325,
        kingdomPoint: 381333,
        power: 1372500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 2860 }]
    },
    114: {
        kingdomLv: 40,
        preCond: [
            { buildingType: 102, buildingLvl: 110 },
            { buildingType: 301, buildingLvl: 110 }
        ],
        costRes: { Grain: 73000000, Lumber: 73000000, Iron: 5650000, Silver: 2825000, Crystal: 890000 },
        costTime: 1040400,
        exp: 34685,
        kingdomPoint: 385333,
        power: 1395000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 2980 }]
    },
    115: {
        kingdomLv: 40,
        preCond: [
            { buildingType: 102, buildingLvl: 110 },
            { buildingType: 301, buildingLvl: 110 }
        ],
        costRes: { Grain: 74000000, Lumber: 74000000, Iron: 5700000, Silver: 2850000, Crystal: 925000 },
        costTime: 1051200,
        exp: 35045,
        kingdomPoint: 389333,
        power: 1417500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 3100 }]
    },
    116: {
        kingdomLv: 40,
        preCond: [
            { buildingType: 102, buildingLvl: 110 },
            { buildingType: 301, buildingLvl: 110 }
        ],
        costRes: { Grain: 75000000, Lumber: 75000000, Iron: 5750000, Silver: 2875000, Crystal: 960000 },
        costTime: 1062000,
        exp: 35405,
        kingdomPoint: 393333,
        power: 1440000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 3220 }]
    },
    117: {
        kingdomLv: 40,
        preCond: [
            { buildingType: 102, buildingLvl: 110 },
            { buildingType: 301, buildingLvl: 110 }
        ],
        costRes: { Grain: 76000000, Lumber: 76000000, Iron: 5800000, Silver: 2900000, Crystal: 995000 },
        costTime: 1072800,
        exp: 35765,
        kingdomPoint: 397333,
        power: 1462500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 3340 }]
    },
    118: {
        kingdomLv: 40,
        preCond: [
            { buildingType: 102, buildingLvl: 110 },
            { buildingType: 301, buildingLvl: 110 }
        ],
        costRes: { Grain: 77000000, Lumber: 77000000, Iron: 5850000, Silver: 2925000, Crystal: 1030000 },
        costTime: 1083600,
        exp: 36125,
        kingdomPoint: 401333,
        power: 1485000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 3460 }]
    },
    119: {
        kingdomLv: 40,
        preCond: [
            { buildingType: 102, buildingLvl: 110 },
            { buildingType: 301, buildingLvl: 110 }
        ],
        costRes: { Grain: 78000000, Lumber: 78000000, Iron: 5900000, Silver: 2950000, Crystal: 1070000 },
        costTime: 1094400,
        exp: 36485,
        kingdomPoint: 405333,
        power: 1507500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 3580 }]
    },
    120: {
        kingdomLv: 40,
        preCond: [
            { buildingType: 102, buildingLvl: 110 },
            { buildingType: 301, buildingLvl: 110 }
        ],
        costRes: { Grain: 79000000, Lumber: 79000000, Iron: 5950000, Silver: 2975000, Crystal: 1105000 },
        costTime: 1105200,
        exp: 36845,
        kingdomPoint: 409333,
        power: 1530000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 3700 }]
    },
    121: {
        kingdomLv: 50,
        preCond: [
            { buildingType: 102, buildingLvl: 120 },
            { buildingType: 301, buildingLvl: 120 }
        ],
        costRes: { Grain: 80000000, Lumber: 80000000, Iron: 6000000, Silver: 3000000, Crystal: 1145000 },
        costTime: 1116000,
        exp: 37205,
        kingdomPoint: 413333,
        power: 1554500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 3830 }]
    },
    122: {
        kingdomLv: 50,
        preCond: [
            { buildingType: 102, buildingLvl: 120 },
            { buildingType: 301, buildingLvl: 120 }
        ],
        costRes: { Grain: 81000000, Lumber: 81000000, Iron: 6050000, Silver: 3025000, Crystal: 1418000 },
        costTime: 1354400,
        exp: 37565,
        kingdomPoint: 417333,
        power: 1579000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 4250 }]
    },
    123: {
        kingdomLv: 50,
        preCond: [
            { buildingType: 102, buildingLvl: 120 },
            { buildingType: 301, buildingLvl: 120 }
        ],
        costRes: { Grain: 82000000, Lumber: 82000000, Iron: 6100000, Silver: 3050000, Crystal: 1577000 },
        costTime: 1470900,
        exp: 37925,
        kingdomPoint: 421333,
        power: 1603500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 4680 }]
    },
    124: {
        kingdomLv: 50,
        preCond: [
            { buildingType: 102, buildingLvl: 120 },
            { buildingType: 301, buildingLvl: 120 }
        ],
        costRes: { Grain: 83000000, Lumber: 83000000, Iron: 6150000, Silver: 3075000, Crystal: 1743000 },
        costTime: 1588400,
        exp: 38285,
        kingdomPoint: 425333,
        power: 1628000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 5120 }]
    },
    125: {
        kingdomLv: 50,
        preCond: [
            { buildingType: 102, buildingLvl: 120 },
            { buildingType: 301, buildingLvl: 120 }
        ],
        costRes: { Grain: 84000000, Lumber: 84000000, Iron: 6200000, Silver: 3100000, Crystal: 1907000 },
        costTime: 1707000,
        exp: 38645,
        kingdomPoint: 429333,
        power: 1652500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 5570 }]
    },
    126: {
        kingdomLv: 50,
        preCond: [
            { buildingType: 102, buildingLvl: 120 },
            { buildingType: 301, buildingLvl: 120 }
        ],
        costRes: { Grain: 85000000, Lumber: 85000000, Iron: 6250000, Silver: 3125000, Crystal: 2084000 },
        costTime: 1826800,
        exp: 39005,
        kingdomPoint: 433333,
        power: 1677000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 6030 }]
    },
    127: {
        kingdomLv: 50,
        preCond: [
            { buildingType: 102, buildingLvl: 120 },
            { buildingType: 301, buildingLvl: 120 }
        ],
        costRes: { Grain: 86000000, Lumber: 86000000, Iron: 6300000, Silver: 3150000, Crystal: 2268000 },
        costTime: 1947900,
        exp: 39365,
        kingdomPoint: 437333,
        power: 1701500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 6500 }]
    },
    128: {
        kingdomLv: 50,
        preCond: [
            { buildingType: 102, buildingLvl: 120 },
            { buildingType: 301, buildingLvl: 120 }
        ],
        costRes: { Grain: 87000000, Lumber: 87000000, Iron: 6350000, Silver: 3175000, Crystal: 2459000 },
        costTime: 2070600,
        exp: 39725,
        kingdomPoint: 441333,
        power: 1726000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 6980 }]
    },
    129: {
        kingdomLv: 50,
        preCond: [
            { buildingType: 102, buildingLvl: 120 },
            { buildingType: 301, buildingLvl: 120 }
        ],
        costRes: { Grain: 88000000, Lumber: 88000000, Iron: 6400000, Silver: 3200000, Crystal: 2669000 },
        costTime: 2197700,
        exp: 40085,
        kingdomPoint: 445333,
        power: 1750500,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 7480 }]
    },
    130: {
        kingdomLv: 50,
        preCond: [
            { buildingType: 102, buildingLvl: 120 },
            { buildingType: 301, buildingLvl: 120 }
        ],
        costRes: { Grain: 89000000, Lumber: 89000000, Iron: 6450000, Silver: 3225000, Crystal: 2880000 },
        costTime: 2329300,
        exp: 40445,
        kingdomPoint: 449333,
        power: 1775000,
        unlockedBuild: 0,
        costTools: [],
        costWEs: [{ idTool: 301901, amount: 1500 }]
    }
};

