#include "WorldMap.ViewFactory.h"
#include "Module/World/WorldMap/WorldMap.Util.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldWar/WorldWar.Def.h"

WorldMapViewFactory *WorldMapViewFactory::Get(){
  static WorldMapViewFactory *l_WorldMapViewFactory = nullptr;
  if(l_WorldMapViewFactory == nullptr){
    l_WorldMapViewFactory = new WorldMapViewFactory();
    l_WorldMapViewFactory->Init();
  }
  return l_WorldMapViewFactory;
}

WorldMapView *WorldMapViewFactory::Create(RViewOtherData p_Param){
  
  auto l_KingdomID = WorldMapDefine::Get()->CurrentMapKindomID;
  auto l_MapClassType = WorldMapWarDef::Get()->GetKingdomMapClassByKingdomId(l_KingdomID);
  RViewClass l_Config;
  if(_TbViewClass.Contains(l_MapClassType))
    l_Config = _TbViewClass[l_MapClassType];
  else
    l_Config = _TbViewClass[EKingdomClassType::Normal];
  l_Config._MapClassType = l_MapClassType;
  if(l_Config._ConfigLod){
    auto l_IsLodOpen = true;
    if(l_Config._CanSwitch)
      l_IsLodOpen = WorldMapUtil::Get()->IsLodOpen();
    l_Config._NoScaleLimit = l_IsLodOpen;
    if(l_IsLodOpen && (
      GDevice::Get()->Platform() == EPlatform::Windows ||
      GDevice::Get()->Platform() == EPlatform::Mac ||
      SDKManager::Get()->IsBeta() ||
      SDKManager::Get()->IsReportError() ||
      SDKManager::Get()->IsGameDevelop()
    )){
      l_Config._ComTable.push_back("worldMapComDebugInfo");
    }
  }
  // local worldMapView = include("worldMapView").new(config, param)
  // return worldMapView

  return WorldMapView::Create(l_Config, p_Param);
}


void WorldMapViewFactory::Init(){
  if(_TbViewClass.size() > 0)
    return;
  RViewClass l_Normal;
  l_Normal._CcsFile = "worldMapViewNormal";
  l_Normal._TileMapTmx = WorldMapUtil::Get()->GetTileMapTmxForPlatform("tileMaps/WorldMapNew128");
  l_Normal._IsSingleMapCell = false;
  l_Normal._TerrainControl = "tileMaps/World_png/worldTileControl.png";
  l_Normal._TerrainControlLod = "tileMaps/World_png/worldTileControl_lod5.png";
  l_Normal._NoScaleLimit = true;
  l_Normal._ConfigLod = true;
  l_Normal._CanSwitch = true;
  l_Normal._ComTable.push_back("worldMapComTmxTerrainBg");
  l_Normal._ComTable.push_back("worldMapComNormal");
  l_Normal._ComTable.push_back("worldMapComManorlineNew");
  l_Normal._ComTable.push_back("worldMapComManorData");
  l_Normal._ComTable.push_back("worldMapComWater");
  l_Normal._ComTable.push_back("worldMapComPage");
  l_Normal._ComTable.push_back("worldMapComBorder");
  l_Normal._ComTable.push_back("worldMapComNormalFog");
  l_Normal._ComTable.push_back("worldMapComCommandHallNpc");
  l_Normal._ComTableLod.push_back("worldMapComWarState");
  l_Normal._ComTableLod.push_back("worldMapComResourceBelt");
  l_Normal._ComTableLod.push_back("worldMapComLodControl");
  l_Normal._LodCfg = WorldMapLodCfg::Get()->_LodCfgNormal;
  l_Normal._LodCfgScale = WorldMapLodCfg::Get()->_LodCfgScaleNormal;
  l_Normal._BorderLodScale = WorldMapLodCfg::Get()->_BorderLodScale; 
  _TbViewClass[EKingdomClassType::Normal] = l_Normal;

  // [gKingdomClassType.pyramid] = {
  //   ccsFile = "worldMapViewPyramid",
  //   tileMapTmx = "tileMaps/PyramidBattleMap.tmx",
  //   isSingleMapCell = true,
  //   comTable = {
  //     "worldMapComTmxBg",
  //     "worldMapComPyramid",
  //     "worldMapComHospital",
  //     "worldMapComBorderWar"
  //   }
  // },
  // [gKingdomClassType.legendLord] = {
  //   ccsFile = "worldMapViewLegend",
  //   tileMapTmx = {
  //     [1] = "tileMaps/LegendBattleMap.tmx",
  //     [2] = "tileMaps/LegendBattleMap2.tmx"
  //   },
  //   isSingleMapCell = true,
  //   comTable = {
  //     "worldMapComTmxBg",
  //     "worldMapComLegend",
  //     "worldMapComHospital",
  //     "worldMapComBorderWar"
  //   }
  // },
  // [gKingdomClassType.remains] = {
  //   ccsFile = "worldMapViewRemains",
  //   tileMapTmx = "tileMaps/remainsWarMap.tmx",
  //   isSingleMapCell = true,
  //   comTable = {
  //     "worldMapComTmxBg",
  //     "worldMapComRemains",
  //     "worldMapComHospital",
  //     "worldMapComBorderWar"
  //   }
  // },
  // [gKingdomClassType.newTrial] = {
  //   ccsFile = "worldMapViewDevil",
  //   tileMapTmx = "tileMaps/NewTrialMap.tmx",
  //   isSingleMapCell = true,
  //   comTable = {
  //     "worldMapComTmxBg",
  //     "worldMapComDevil",
  //     "worldMapComBorderWar"
  //   }
  // },
  // [gKingdomClassType.radiance] = {
  //   ccsFile = "worldMapViewRadiance",
  //   tileMapTmx = "tileMaps/BrightBattlefield.tmx",
  //   isSingleMapCell = true,
  //   comTable = {
  //     "worldMapComTmxBg",
  //     "worldMapComRadiance",
  //     "worldMapComManorlineWar",
  //     "worldMapComManorlineBuild",
  //     "worldMapComHospital",
  //     "worldMapComBorderWar"
  //   }
  // },
  // [gKingdomClassType.atlantis] = {
  //   ccsFile = "worldMapViewAtlantis",
  //   tileMapTmx = getTileMapTmxForPlatform("tileMaps/atlantisMap"),
  //   isSingleMapCell = true,
  //   createCustomLayer = "atlantis",
  //   terrainControl = "tileMaps/atlantis_png/tileControl.png",
  //   minScale = 0.05,
  //   normalScale = 0.75,
  //   configLod = true,
  //   comTable = {
  //     "worldMapComTmxTerrainBg",
  //     "worldMapComTmxFog",
  //     "worldMapComAtlantis",
  //     "worldMapComHospital",
  //     "worldMapComMarshal",
  //     "worldMapComWater",
  //     "worldMapComBorderWar"
  //   },
  //   lodCfg = worldMapLodCfg.lodCfgAtlantis,
  //   lodCfgScale = worldMapLodCfg.lodCfgScaleNebula,
  //   borderLodScale = worldMapLodCfg.borderLodScale
  // },
  // [gKingdomClassType.nebula] = {
  //   ccsFile = "worldMapViewNebula",
  //   tileMapTmx = {
  //     [1] = "tileMaps/nebulaMap.tmx",
  //     [2] = "tileMaps/nebulaMap2.tmx"
  //   },
  //   isSingleMapCell = true,
  //   terrainControl = {
  //     [1] = "tileMaps/nebula_png/tileControl.png",
  //     [2] = "tileMaps/nebula_png/tileControl2.png"
  //   },
  //   minScale = 0.05,
  //   configLod = true,
  //   comTable = {
  //     "worldMapComTmxTerrainBg",
  //     "worldMapComNebula",
  //     "worldMapComManorlineNew",
  //     "worldMapComManorData",
  //     "worldMapComHospital",
  //     "worldMapComBorderWar"
  //   },
  //   lodCfg = worldMapLodCfg.lodCfgNebula,
  //   lodCfgScale = worldMapLodCfg.lodCfgScaleNebula,
  //   borderLodScale = worldMapLodCfg.borderLodScale
  // }
}