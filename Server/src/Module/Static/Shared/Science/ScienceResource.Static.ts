import { EBuildingType } from "src/Module/Building/Building.Enum";

export const ScienceResourceStaic =  {
  Key: "resource",
  CostBuilding: {
    BuildingType: EBuildingType.Institute,
    buildingLvl: 22
  },
  starbuild: {
    BuildingType: EBuildingType.None,
    buildingLvl: 0
  },
  CategoryName: "common_text_123",
  Icon: "icon_shop_01.png",
  Tree: [
    [EScienceType.]: [
      1 : {
        index : 1,
        idScience : 2100101,
        Category : 1,
        lvl : 1,
        CostResource : { 
         Coin : 0, 
          Grain: 0,
          Lumber: 0,
          Iron: 0,
          Silver: 0,
        },
        buffType : 1,
        powerNum : 20,
        buffNumType : 1,
        maxLvl : 5,
        CostTime : 180,
        CostBuilding: {
          BuildingType: 113,
          buildingLvl: 1
      },
        CostStarBuid: {
          BuildingType: EBuildingType.None,
          buildingLvl: 0
        },
             CostScience : [
    { ScienceType: 0,  scienceLvl: 0 }, 
   { ScienceType: 0, scienceLvl: 0  }, 
   { ScienceType: 0, scienceLvl: 0 },
    {  ScienceType: 0, scienceLvl: 0 }
   ],
        },
        fighting : 10,
             CostScienceWEs:{ ScienceType: EScienceType.None, scienceLvl: 0 },
        CostKingdomPoint : 15,
        battle: [ 1, 2, 3, 5,  6, 7, 8, 9, 10],
        activity : 0
      },
    ]
  ]
    // "21001",
    // "21002",
    // "21003",
    // "21004",
    // "21005",
    // "21006",
    // "21007",
    // "21008",
    // "21009",
    // "21010",
    // "21011",
    // "21012",
    // "21013",
    // "21014",
    // "21015",
    // "21016",
    // "21017",
    // "21018",
    // "21019",
    // "21020"
  
}