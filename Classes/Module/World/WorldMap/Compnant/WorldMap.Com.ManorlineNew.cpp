#include "WorldMap.Com.ManorlineNew.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldWar/WorldWar.Def.h"
#include "Module/World/Kingdom/KingdomMap.Ctrl.h"
#include "Module/World/WorldMap/WorldMap.Event.h"
#include "Module/World/WorldMap/View/WorldMap.View.h"
#include "Module/World/WorldMap/View/WorldMapView.Def.h"
#include "Base/Utils/MeshNode.h"

static const int TileBG_Size = 1024;

void WorldMapComManorLineNew::Ctor(){
  IWorldMapComponent::Ctor();
  _IsInNebula = WorldMapDefine::Get()->IsInNebula();
  auto lMapClassType = KingdomMapCtrl::Get()->GetKingdomClass();
  _MapRangMaxX = WorldMapWarDef::Get()->GetMapRangMaxX(lMapClassType);
}


void WorldMapComManorLineNew::Init(){
  IWorldMapComponent::Init();
}

void WorldMapComManorLineNew::OnMessageListener(){
  AddEventListener(WorldMapEvent::Get()->EVENT_TILE_POS, CC_CALLBACK_1(WorldMapComManorLineNew::UpdateMapPos, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_TOOGLE_3D, CC_CALLBACK_1(WorldMapComManorLineNew::Toggle3D, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_SCROLL_LOD_CHANGE, CC_CALLBACK_1(WorldMapComManorLineNew::UpdateLodLevel, this));
  AddEventListener(WorldMapEvent::Get()->EVENT_UPDATE_INFO, CC_CALLBACK_1(WorldMapComManorLineNew::UpdateInfo, this));
  
  GBase::DAddMessage(_Target, "MESSAGE_WORLD_MAP_UPDATE_LEAGUEMANOR_INSTANCE", CC_CALLBACK_1(WorldMapComManorLineNew::UpdateLeagueManorInstance, this));
  GBase::DAddMessage(_Target, "MESSAGE_WORLD_MAP_UPDATE_LEAGUEMANOR_INSTANCE_RESET", CC_CALLBACK_1(WorldMapComManorLineNew::ResetLeagueManorInstance, this));
  GBase::DAddMessage(_Target, "MESSAGE_WORLD_MAP_NODEINFO_SELECT_CHANGE", CC_CALLBACK_1(WorldMapComManorLineNew::UpdateNodeInfoSelect, this));
  
  auto lHandlerChange = CC_CALLBACK_1(WorldMapComManorLineNew::UpdateRelationChange, this);
  GBase::DAddMessage(_Target, "MESSAGE_ALLIANCE_RELATION_DATA_CHANGE", lHandlerChange);
  GBase::DAddMessage(_Target, "MESSAGE_ALLIACNE_BE_KICKED", lHandlerChange);
  GBase::DAddMessage(_Target, "MESSAGE_ALLIANCE_QUIT_SUCCESS", lHandlerChange);
  GBase::DAddMessage(_Target, "MESSAGE_ALLIANCE_JOIN_SUCCESS", lHandlerChange);
}

void WorldMapComManorLineNew::Toggle3D(EventCustom* pEvent){
  if(!_TiledBg){
    return;
  }

  if(GGlobal::Get()->gEnableWorldMap3D && GGlobal::Get()->gEnableWorldMap3D.value()){
    _TiledBg->setRotation3D(GGlobal::Get()->gWorldMapRotation3D);
  }else{
    _TiledBg->setRotation3D(GGlobal::Get()->gWorldMapRotation2D);
  }
}

void WorldMapComManorLineNew::UpdateMapPos(EventCustom* pEvent){
  if(!pEvent)
    return;
  
  auto lTilePos = *static_cast<Vec2 *>(pEvent->getUserData());
  if(lTilePos.x != _TiledBgX || lTilePos.y != _TiledBgY){
    _TiledBgX = lTilePos.x;
    _TiledBgY = lTilePos.y;
    RefreshMapPos(lTilePos);
  }
}

void WorldMapComManorLineNew::RefreshMapPos(Vec2 pTilePos){
  if(!_TiledBg)
    return;
  auto lZoomScale = _Target->_ViewScrollView->getZoomScale();
  auto lScaleX = _TiledBg->getContentSize().width / TileBG_Size / lZoomScale;
  auto lScaleY = _TiledBg->getContentSize().height / TileBG_Size / lZoomScale;

  GVector<RMeshNodeShaderCfg> lParam;
  RMeshNodeShaderCfg lParam1;
  lParam1.Attr = EUniformType::Vec4;
  lParam1.UnifromName = "_Texture_ST";
  lParam1.Vec4Value = Vec4(lScaleX, lScaleY, pTilePos.x, pTilePos.y);
  lParam.push_back(lParam1);
  GBase::DSetProgramStateParam(_Program, _State, lParam);
}

void WorldMapComManorLineNew::UpdateLodLevel(EventCustom* pEvent){

  if(!_TiledBg)
    return;
  auto lLodLevel = _Target->GetCurLod();
  auto lParam = GVector<RMeshNodeShaderCfg>();
  RMeshNodeShaderCfg lParam1;
  lParam1.Attr = EUniformType::Float;
  lParam1.UnifromName = "v_lodLevel";
  lParam1.FloatValue = static_cast<float>(lLodLevel);
  GBase::DSetProgramStateParam(_Program, _State, lParam);
  if(lLodLevel <= EWorldLodDef::LOD3){
    ShowManorline(true);
    if(WorldMapDefine::Get()->_CurSelectNodeInfo == WorldMapViewDef::Get()->NODEINFO_TYPE_ALLIANCE){
      UpdateRelationChange(nullptr);
    }
    
  }else{
    _CurSelectNodeInfo = 0;
    UpdateNodeInfoSelect(nullptr);
  }
}

void WorldMapComManorLineNew::ResetLeagueManorInstance(EventCustom* pEvent){
  // self.currentShowLeagueManorLineArrary = {}
  _LeagueIDArrary.clear();
  _IsNeedRefresh = true;
  _ColorIdArrary.clear();
}

void WorldMapComManorLineNew::UpdateLeagueManorInstance(EventCustom* pEvent){
  if(!pEvent)
    return;
  if(!pEvent->getUserData())
    return;
  auto lData = *static_cast<RLeagueManorInstanceUpdateEvAr *>(pEvent->getUserData());

  if(!_ColorIdArrary.Contains(lData._LeagueID) || lData._ColorId > 0){
    _ColorIdArrary[lData._LeagueID] = lData._ColorId;
  }
  // local manorDataArrary = self.currentShowLeagueManorLineArrary[leagueID]
  auto lManorDataArrary = _CurrentShowLeagueManorLineArrary[lData._LeagueID];
  // if updateType == worldMapLeagueManorUpdateType.leagueManorInstanceAdd then
  //   local lineData = {
  //     tonumber(tilePoint.x) - radioation,
  //     tonumber(tilePoint.y) - radioation,
  //     2 * radioation + size,
  //     2 * radioation + size
  //   }
  //   local curLineArray = self:getLineArray(lineData, sn)
  //   if not manorDataArrary then
  //     manorDataArrary = {}
  //     manorDataArrary[1] = {}
  //     manorDataArrary[2] = {}
  //   end
  //   if activiyStatus then
  //     manorDataArrary[1][instanceID] = curLineArray
  //   else
  //     manorDataArrary[2][instanceID] = curLineArray
  //   end
  //   self.isNeedRefresh = true
  // elseif updateType == worldMapLeagueManorUpdateType.leagueManorInstanceRemove then
  //   if not manorDataArrary then
  //     return
  //   end
  //   if manorDataArrary then
  //     if activiyStatus then
  //       manorDataArrary[1][instanceID] = nil
  //     else
  //       manorDataArrary[2][instanceID] = nil
  //     end
  //   end
  //   self.isNeedRefresh = true
  // elseif updateType == worldMapLeagueManorUpdateType.leagueManorInstanceActiviy then
  //   if not manorDataArrary then
  //     return
  //   end
  //   if activiyStatus then
  //     local lineData = {
  //       tonumber(tilePoint.x) - radioation,
  //       tonumber(tilePoint.y) - radioation,
  //       2 * radioation + size,
  //       2 * radioation + size
  //     }
  //     local curLineArray = self:getLineArray(lineData, sn)
  //     manorDataArrary[1][instanceID] = curLineArray
  //     manorDataArrary[2][instanceID] = nil
  //   else
  //     local manorData = manorDataArrary[1][instanceID]
  //     if manorData then
  //       manorDataArrary[2][instanceID] = manorData
  //       manorDataArrary[1][instanceID] = nil
  //     end
  //   end
  //   self.isNeedRefresh = true
  // elseif updateType == worldMapLeagueManorUpdateType.leagueManorRelationChange then
  // end
  // self.currentShowLeagueManorLineArrary[leagueID] = manorDataArrary
}

void WorldMapComManorLineNew::UpdateInfo(EventCustom* pEvent){

}




void WorldMapComManorLineNew::UpdateNodeInfoSelect(EventCustom* pEvent){

}

void WorldMapComManorLineNew::UpdateRelationChange(EventCustom* pEvent){

}

