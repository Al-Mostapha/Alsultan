#include "WorldMap.Cell.h"
#include "Module/World/WorldMap/IWorldMap.View.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Engine/XTiledMap/XTileLayer.h"
#include "Module/Player/Player.Top.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "WorldMap.View.h"
#include "Base/Utils/Utils3D.h"
#include "Module/UI/Panel/World/WorldMap/Floor/UIWorldMap.Tip.h"
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Instance/WorldMapTilePolygon.h"

typedef EWorldMapZOrder Z_ORDER;

WorldMapCell *WorldMapCell::Create(WorldMapView *p_MapView){
  WorldMapCell *l_Cell = WorldMapCell::create();
  l_Cell->Ctor( p_MapView );
  return l_Cell;
}

void WorldMapCell::Ctor( WorldMapView *p_MapView ){

  _MyKingdomID = PlayerTop::Get()->GetMapID();
  _MyPlayerID = PlayerTop::Get()->GetPlayerID();
  _MyPlayerName = LordInfoCtrl::Get()->GetBaseInfo()._NickName;
  _MapViewSize = p_MapView->_MapViewSize;
  _MapSize = p_MapView->_MapSize;
  _TileSize = p_MapView->_TileSize;
  _MapLayer = p_MapView->_MapLayer;
  _GroundLayer = p_MapView->_GroundLayer;
  _GroundLayerMarsh = p_MapView->_GroundLayer_marsh;
  if(_GroundLayerMarsh)
    //   self.groundLayer_marsh:setGroupID(GROU_ID.group_build_gate)
  _IsSingleMapCell = p_MapView->_IsSingleMapCell;
  _MapClassType = p_MapView->_MapClassType;
  setTouchEnabled(true);
  ignoreAnchorPointForPosition(false);
  setAnchorPoint(Vec2(0.5, 0.5));
  setContentSize(_MapViewSize);
  setSwallowTouches(false);
  addTouchEventListener(CC_CALLBACK_2(WorldMapCell::ViewOnClick, this));
  // self.cacheLeagueManorNodes = {
  //   [1] = {},
  //   [2] = {}
  // }
}

void WorldMapCell::SetMapPointIndex(int32 p_Index){
  _MapPointIndex = p_Index;
}

void WorldMapCell::SetTouchPlayerCallFunc(const ui::Widget::ccWidgetTouchCallback& p_CallFunc){
  _TouchPlayerCallFun = p_CallFunc;
}

void WorldMapCell::ViewOnClick(Ref* p_Target, ui::Widget::TouchEventType p_Event){
  GVector<Vec2> l_PointArray;
  l_PointArray.push_back(Vec2(0, _MapViewSize.height / 2));
  l_PointArray.push_back(Vec2(_MapViewSize.width / 2, _MapViewSize.height));
  l_PointArray.push_back(Vec2(_MapViewSize.width, _MapViewSize.height / 2));
  l_PointArray.push_back(Vec2(_MapViewSize.width / 2, 0));
  auto l_TouchPoint = getTouchBeganPosition();
  Vec2 l_CovertPoint;

  if(GGlobal::Get()->gEnableWorldMap3D.value()){
    auto l_CovertPointTemp = GBase::ConvertTouchToNodeSpace3D(this, l_TouchPoint);
    l_CovertPoint.x = l_CovertPointTemp.value().x;
    l_CovertPoint.y = l_CovertPointTemp.value().y;
  }else{
    l_CovertPoint = convertToNodeSpace(l_TouchPoint);
  }

  auto l_IsInTouch = GBase::DIsPointInPolygon(l_PointArray, l_CovertPoint);
  if(l_IsInTouch && _TouchPlayerCallFun){
    if(GGlobal::Get()->gEnableWorldMap3D.value() && p_Event == ui::Widget::TouchEventType::ENDED && _DrawNode){
      _DrawNode->setPosition(l_CovertPoint);
      _DrawNode->setVisible(true);
    }
    _TouchPlayerCallFun(this, p_Event);
  }else if(_IsSingleMapCell){
    GBase::DSendMessage("MESSAGE_WORLD_MAP_REMOVE_SELECTSHOWPANEL");
  }

}

void WorldMapCell::SetKingdomId(int32 p_KID, Vec2 p_KingdomPoint, int32 p_RegionId){
  _MyKingdomID = p_KID;
  _KingdomPoint = p_KingdomPoint;
  if(_KingdomPoint == Vec2::ZERO)
    // kingdomPoint = kingdomPoint or kingdomPointDefine.getKingdomPointWithID(self.kingdomID)

  // if not regionId then
  //   local nebulaActivityCtrl = SoraDGetCtrl("nebulaActivityCtrl")
  //   local rType, rId = nebulaActivityCtrl:getKingdomRegionType(kid)
  //   regionId = rId
  // end
  _RegionID = p_RegionId;
}

int32 WorldMapCell::GetKingdomID() const {
  return _MyKingdomID;
}

Vec2 WorldMapCell::GetKingdomPoint() const {
  return _KingdomPoint;
}

int32 WorldMapCell::GetRegionID() const {
  return _RegionID;
}

Vec2 WorldMapCell::TilePositionFromLocation(Vec2 p_Location, bool p_OutSize){ 
  Vec4 l_Pos;
  if(GGlobal::Get()->gEnableWorldMap3D.value()){
    l_Pos = GBase::ConvertTouchToNodeSpace3D(this, p_Location).value();
  }else{
    auto l_2DPos = convertToNodeSpace(p_Location);
    l_Pos.x = l_2DPos.x;
    l_Pos.y = l_2DPos.y;
  }
  
  auto l_HalfMapWidth =  _MapSize.width * 0.5;
  auto l_MapWidth = _MapSize.width;
  auto l_MapHeight = _MapSize.height;
  auto l_TileWidth = _TileSize.width;
  auto l_TileHeight = _TileSize.height;
  auto l_TilePosDiv = Vec2(l_Pos.x / l_TileWidth, l_Pos.y / l_TileHeight);
  auto l_InverseTileY = l_MapHeight - l_TilePosDiv.y;
  auto l_PosX = GMath::Floor(l_InverseTileY + l_TilePosDiv.x - l_HalfMapWidth);
  auto l_PosY = GMath::Floor(l_InverseTileY - l_TilePosDiv.x + l_HalfMapWidth);
  Vec2 l_Ret;
  if(!p_OutSize){
    if(l_PosX < 0 || l_PosX > l_MapWidth - 1 || l_PosY < 0 || l_PosY > l_MapHeight - 1){
      l_Ret = Vec2(-1, -1);
    }else{
      l_Ret = Vec2(l_PosX, l_PosY);
    }
  }else{
    if(l_PosX < 0){
      l_PosX = 0;
    }
    else if(l_PosX > l_MapWidth - 1){
      l_PosX = l_MapWidth - 1;
    }
    
    if(l_PosY < 0){
      l_PosY = 0;
    }
    else if(l_PosY > l_MapHeight - 1){
      l_PosX = l_MapHeight - 1;
    }
    l_Ret = Vec2(l_PosX, l_PosY);
  }
  return l_Ret;
}

Vec2 WorldMapCell::GetPointWithTile(Vec2 p_TilePoint, int32 p_HoldInstance){ 
  auto l_TileWidth = _TileSize.width;
  auto l_TileHeight = _TileSize.height;
  auto l_Point = _MapLayer->getPositionAt(p_TilePoint);
  l_Point.x += l_TileWidth /2;
  l_Point.y += (3 - p_HoldInstance) * l_TileHeight / 2;
  return l_Point;
}

UIWorldMapTip *WorldMapCell::OnClickMap(Node *p_TileInstance, Vec2 p_TilePos, Node *p_OnShowView ){
  auto l_IsCanZhanling = true;
  auto l_IsCanQiancheng = true;
  auto l_FavoriteName = Translate::i18n("common_text_491");
  auto l_TileGID = _MapLayer->getTileGIDAt(p_TilePos);
  auto l_GroundGID = _GroundLayer->getTileGIDAt(p_TilePos);
  auto l_SoundID = 8;
  GString l_MsgTipsKey;

  if(!WorldMapDefine::Get()->IsInNebula()){
    if(l_TileGID >= 5 && l_TileGID <= 23){
      l_FavoriteName = Translate::i18n("common_text_495");
      l_IsCanZhanling = false;
      l_SoundID = 9;
    }else if(l_TileGID >= 62 && l_TileGID <= 70){
      l_FavoriteName = Translate::i18n("common_text_514");
      l_IsCanZhanling = false;
    }else if(l_TileGID >= 71 && l_TileGID <= 79){
      l_FavoriteName = Translate::i18n("common_text_515");
      l_IsCanZhanling = false;
    }else if(l_GroundGID >= 99 && l_GroundGID <= 111){
      l_FavoriteName = Translate::i18n("common_text_493");
      l_IsCanZhanling = false;
      l_SoundID= 10;
    }else if(_GroundLayerMarsh){
      l_GroundGID = _GroundLayerMarsh->getTileGIDAt(p_TilePos);
      if(l_GroundGID > 0){
        l_FavoriteName = Translate::i18n("brightWar_build_08");
        l_IsCanZhanling = false;
        l_SoundID = 10;
      }
    }
  }

  GBase::PlaySound("worldmap", l_SoundID);
  auto l_ShowPoint = GetPointWithTile(p_TilePos);
  auto l_ScreenPoint = GBase::DConvertoScreenPos2DOr3D(this, {l_ShowPoint.x, l_ShowPoint.y, 0}).value();
  auto l_CoverShowPoint = p_OnShowView->convertToNodeSpace({l_ScreenPoint.x, l_ScreenPoint.y});
  auto l_SelectShowPanel = UIWorldMapTip::Create(_KingdomID);
  l_SelectShowPanel->SetTilePoint(p_TilePos);
  l_SelectShowPanel->SetWorldMapCell(this);
  l_SelectShowPanel->SetFavoriteName(l_FavoriteName);
  if(WorldMapDefine::Get()->IsInRemains()){
    //   local remainsWarUtil = include("remainsWarUtil")
    //   isCanZhanling = not remainsWarUtil.checkIsInForbidAreaZhanling(tilePos)
  } else if(l_IsCanZhanling && WorldMapDefine::Get()->IsInRadiance()){
    //   do
    //     local radianceWarUtil = include("radianceWarUtil")
    //     isCanZhanling = radianceWarUtil.isInSelfLeagueManor(tilePos)
    //     if not isCanZhanling then
    //       function msgTipsKey()
    //         radianceWarUtil.showGuildToBuild(tilePos)
    //       end
    //     end
    //   end
  } else if(l_IsCanZhanling && WorldMapDefine::Get()->IsInNebula()){
    //   local nebulaWarUtil = include("nebulaWarUtil")
    //   isCanZhanling, msgTipsKey = nebulaWarUtil.checkIsCanZhanling(tilePos)
  }
  if(!l_IsCanZhanling && l_MsgTipsKey.empty())
    l_MsgTipsKey = Translate::i18n("common_text_485");
  l_SelectShowPanel->SetIsCanZhanling(l_IsCanZhanling, l_MsgTipsKey);
  l_SelectShowPanel->InitMapData(p_TileInstance);
  l_SelectShowPanel->setPosition(l_CoverShowPoint);
  p_OnShowView->addChild(l_SelectShowPanel, static_cast<int32>(Z_ORDER::selectView));
  return l_SelectShowPanel;
}

GTuple<UIBaseView *, Node *, Node *>
WorldMapCell::OnClickInstance(GOpt<Vec2> p_TilePos, IWorldMapInstance *p_TileInstance, Node *p_OnShowView, Node *p_OnShowViewNode){
  if(!p_TilePos)
    return {nullptr, nullptr, nullptr};
  bool l_ShowPolygon = true;
  float l_PolygonScale = 1;
  UIBaseView *l_SelectShowPanel = nullptr;
  Node *l_SelectTilePolygon = nullptr;
  Node *l_SelectTilesPolygon = nullptr;
  Vec4 l_CoverShowPoint;
  if(!p_TileInstance){
    if(WorldMapDefine::Get()->IsInNebula())
      return {nullptr, nullptr, nullptr};
    auto l_ShowPoint = GetPointWithTile(p_TilePos.value());
    l_CoverShowPoint = GBase::DCoverToPoint2DOr3D(this, l_ShowPoint, p_OnShowView);
    l_SelectShowPanel = OnClickMap(nullptr, p_TilePos.value(), p_OnShowView);
  }else{
    auto l_ShowPoint = p_TileInstance->getPosition();
    l_CoverShowPoint = GBase::DCoverToPoint2DOr3D(this, l_ShowPoint, p_OnShowView);
    l_PolygonScale =p_TileInstance->GetHoldInstance();
    l_PolygonScale = GMath::Min(l_PolygonScale, 3.0f);
    std::tie(
      l_SelectShowPanel, 
      l_ShowPolygon, 
      l_SelectTilesPolygon) = p_TileInstance->OnClickInstance(p_OnShowViewNode);
    if(l_SelectTilesPolygon){
      l_SelectTilesPolygon->setPosition(l_CoverShowPoint.x, l_CoverShowPoint.y);
      p_OnShowView->addChild(l_SelectTilesPolygon, static_cast<int32>(Z_ORDER::selectBgView));
    }
  }
  if(l_ShowPolygon){
    auto l_TileRolygon = WorldMapTilePolygon::Create();
    l_TileRolygon->setPosition(l_CoverShowPoint.x, l_CoverShowPoint.y);
    l_TileRolygon->setScale(l_PolygonScale);
    p_OnShowView->addChild(l_TileRolygon, static_cast<int32>(Z_ORDER::selectBgView));
    l_SelectTilePolygon = l_TileRolygon;
  }
  return {
    l_SelectShowPanel, 
    l_SelectTilePolygon, // small white diamond shape under world unit
    l_SelectTilesPolygon // Big white diamond shape under world unit (Alliance Flag)
  };
}


void WorldMapCell::AddShowBonePoing(EKingdomClassType){

}


