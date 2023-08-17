#include "WorldMap.View.Object.h"
#include "Base/BaseTypeDef.h"
#include "Module/World/WorldMap/Compnant/WorldMapCom.TmxTerrianBg.h"
#include "Module/World/WorldMap/Compnant/WorldMap.Com.UI.h"

void WorldMapViewObject::AddComponents(RViewClass p_Config, WorldMapView *p_Target){
  static GVector<GString> l_ComTable = {
    "worldMapComUI",
    "worldMapComViewPiece",
    "worldMapComInstanceNormal",
    "worldMapComMoveline",
    "worldMapComButton",
    "worldMapComUtil",
    "worldMapComTransfer",
    "worldMapComForbidWar",
    "worldMapComGuide",
    "worldMapComSelect",
    "worldMapComGroup",
    "worldMapCom3D",
    "worldMapComTileEffect"
  };
  _Components.push_back(WorldMapComTmxTerrianBg::Create(p_Target));
  _Components.push_back(IWorldMapComponent::Create<WorldMapComUI>(p_Config, p_Target));
  // for _, v in ipairs(comTable) do
  //   self:addCustomComponent(v, nil, config)
  // end
  // if config.noScaleLimit then
  //   if config.lodCfg then
  //     for _, v in ipairs(config.lodCfg) do
  //       self:addCustomComponent(v.component, v.name, v.param)
  //     end
  //   end
  //   if config.comTableLod then
  //     for _, v in ipairs(config.comTableLod) do
  //       self:addCustomComponent(v, nil, config)
  //     end
  //   end
  // end
  // local other = config and config.comTable
  // if other then
  //   for _, v in ipairs(other) do
  //     self:addCustomComponent(v, nil, config)
  //   end
  // end
  // local worldMapWarDef = include("worldMapWarDef")
  // if worldMapWarDef.isInWarForbidAllianceMark() or worldMapWarDef.isInWarForbidCampMark() then
  //   self:addCustomComponent("worldMapComAllianceMark")
  // end
  // if config.noScaleLimit then
  //   self:addCustomComponent("worldMapComLod", nil, config)
  //   self:addCustomComponent("worldMapComLodUI")
  // else
  //   self:addCustomComponent("worldMapComLodDumy")
  // end
}

void WorldMapViewObject::CallComFuncInit(){
  for(auto l_Iter : _Components){
    l_Iter->Init();
  }
}

void WorldMapViewObject::CallComFuncRelogin(){
  for(auto l_Iter : _Components){
    l_Iter->Relogin();
  }
}

void WorldMapViewObject::CallComFuncOnMessageListener(){
  for(auto l_Iter : _Components){
    l_Iter->OnMessageListener();
  }
}

void WorldMapViewObject::CallComFuncDoRequest(){
  for(auto l_Iter : _Components){
    l_Iter->DoRequest();
  }
}

void WorldMapViewObject::CallComFuncDoClearData(){
  for(auto l_Iter : _Components){
    l_Iter->DClearData();
  }
}
