#include "WorldMap.View.Mul.h"
#include "Engine/Display.h"
#include "WorldMap.Cell.h"
#include "Module/World/WorldMap/WorldMap.Define.h"

auto l_RectZero = Rect(0, 0, 0, 0);
auto l_RectPercent = 0.75f;

void WorldMapViewMul::InitMapCell_imp(){
  _MapViewCellArray.clear();
  _MapViewPointArray.clear();
  _MapViewSwapPointArray.clear();
  // local scaleH = 3 + (display.height - 960) / 426 * 0.3
  auto l_ScaleH = 3 + (GDisplay::Get()->height - 960) / 426 * 0.3;
  // self.containerViewSize = cc.size(self.mapViewSize.width * 2, self.mapViewSize.height * scaleH)
  _ContainerViewSize = Size(_MapViewSize.width * 2, _MapViewSize.height * l_ScaleH);
  // local halfViewWidth, halfViewHeight = self.containerViewSize.width / 2, self.containerViewSize.height / 2
  auto l_HalfViewWidth = _ContainerViewSize.width / 2;
  auto l_HalfViewHeight = _ContainerViewSize.height / 2;
  // self.mapViewPointArray[1] = cc.p(halfViewWidth, halfViewHeight + self.mapViewSize.height / 2)
  _MapViewPointArray.push_back(Vec2(l_HalfViewWidth, l_HalfViewHeight + _MapViewSize.height / 2));
  // self.mapViewPointArray[2] = cc.p(halfViewWidth - self.mapViewSize.width / 2, halfViewHeight)
  _MapViewPointArray.push_back(Vec2(l_HalfViewWidth - _MapViewSize.width / 2, l_HalfViewHeight));
  // self.mapViewPointArray[3] = cc.p(halfViewWidth, halfViewHeight - self.mapViewSize.height / 2)
  _MapViewPointArray.push_back(Vec2(l_HalfViewWidth, l_HalfViewHeight - _MapViewSize.height / 2));
  // self.mapViewPointArray[4] = cc.p(halfViewWidth + self.mapViewSize.width / 2, halfViewHeight)
  _MapViewPointArray.push_back(Vec2(l_HalfViewWidth + _MapViewSize.width / 2, l_HalfViewHeight));
  // self.mapViewSwapPointArray[1] = cc.p(halfViewWidth, halfViewHeight + self.mapViewSize.height * RECT_PERCENT)
  _MapViewSwapPointArray.push_back(Vec2(l_HalfViewWidth, l_HalfViewHeight + _MapViewSize.height * l_RectPercent));
  // self.mapViewSwapPointArray[2] = cc.p(halfViewWidth - self.mapViewSize.width * RECT_PERCENT, halfViewHeight)
  _MapViewSwapPointArray.push_back(Vec2(l_HalfViewWidth - _MapViewSize.width * l_RectPercent, l_HalfViewHeight));
  // self.mapViewSwapPointArray[3] = cc.p(halfViewWidth, halfViewHeight - self.mapViewSize.height * RECT_PERCENT)
  _MapViewSwapPointArray.push_back(Vec2(l_HalfViewWidth, l_HalfViewHeight - _MapViewSize.height * l_RectPercent));
  // self.mapViewSwapPointArray[4] = cc.p(halfViewWidth + self.mapViewSize.width * RECT_PERCENT, halfViewHeight)
  _MapViewSwapPointArray.push_back(Vec2(l_HalfViewWidth + _MapViewSize.width * l_RectPercent, l_HalfViewHeight));

  for(auto i = 0; i < _MapViewPointArray.size(); i++){
    auto l_MapViewCell = CreateOneMapCell();
    l_MapViewCell->setName("mapViewCell" + std::to_string(i));
    auto l_MapViewCellPoint = _MapViewPointArray[i];
    l_MapViewCell->setPosition(l_MapViewCellPoint);
    l_MapViewCell->SetMapPointIndex(i);
    _MapViewCellArray.push_back(l_MapViewCell);
  }
  auto l_FirstMapViewCell = _MapViewCellArray[0];
  _CurrentInMapViewCell = l_FirstMapViewCell;
  _SelfInMapView = l_FirstMapViewCell;
  _ContainerView->setContentSize(_ContainerViewSize);
  InitColorLayer();
  SetLightMapcell(_CurrentInMapViewCell);
  SetMapcellKingdomID(1);
}


void WorldMapViewMul::InitColorLayer(){
  auto l_ColorLayer = LayerColor::create(Color4B(0, 0, 0, 128));
  l_ColorLayer->setContentSize(_ContainerViewSize);
  l_ColorLayer->setIgnoreAnchorPointForPosition(false);
  l_ColorLayer->setAnchorPoint(Vec2(0.5f, 0.5f));
  l_ColorLayer->setPosition(Vec2(_ContainerViewSize.width / 2, _ContainerViewSize.height / 2));
  _MapViewcliperNode = ClippingNode::create();
  _MapViewcliperNode->addChild(l_ColorLayer);
  _MapViewcliperNode->setInverted(true);
  _ContainerView->addChild(_MapViewcliperNode, static_cast<int32>(WorldMapDefine::Z_ORDER_CELL::objView));
  _MapViewcliperNode->setName("mapViewcliperNode");
  RPolygonProps l_Params;
  l_Params.FillColor = Color4F(1, 1, 1, 0.5);
  l_Params.BorderColor = Color4F(0, 1, 0, 0);
  l_Params.borderWidth = 1;
  
  GVector<Vec2> l_Points = {
    Vec2(-200, 0),
    Vec2(0, 100),
    Vec2(200, 0),
    Vec2(0, -100)
  };
  
  auto l_ShapeNode = GDisplay::Get()->NewPolygon(l_Points, l_Params);
  l_ShapeNode->setName("shapNode");
  l_ShapeNode->setScale(_MapViewSize.width / 400);
  l_ShapeNode->setIgnoreAnchorPointForPosition(false);
  l_ShapeNode->setAnchorPoint(Vec2(0.5f, 0.5f));
  _MapViewcliperNode->setStencil(l_ShapeNode);
  _ShapNode = l_ShapeNode;
  
}

void WorldMapViewMul::SetLightMapcell(WorldMapCell * p_ViewCell){
  if(_MapViewCell){
    _ShapNode->setVisible(true);
    auto l_Pos = _MapViewCell->getPosition();
    auto l_PosView = _MapViewcliperNode->getPosition();
    _ShapNode->setPosition(Vec2((l_Pos.x - l_PosView.x) * 1, (l_Pos.y - l_PosView.y) * 1));
  }else{
    _ShapNode->setVisible(false);
  }
}

void WorldMapViewMul::SetMapcellKingdomID(int32 p_CellIndex){
  // local mapCell = self.mapViewCellArray[cellIndex]
  // local cellKingdomPoint = mapCell:getKingdomPoint()
  // local cellKingdomID = mapCell:getKingdomID()
  // local cellRegionId = mapCell:getRegionId()
  // local nebulaActivityCtrl = SoraDGetCtrl("nebulaActivityCtrl")
  // local cellRegionType = nebulaActivityCtrl:getRegionTypeByRegionId(cellRegionId)
  // local config = {
  //   [1] = {
  //     [2] = cc.p(0, -1),
  //     [3] = cc.p(1, -1),
  //     [4] = cc.p(1, 0)
  //   },
  //   [2] = {
  //     [1] = cc.p(0, 1),
  //     [4] = cc.p(1, 1),
  //     [3] = cc.p(1, 0)
  //   },
  //   [3] = {
  //     [2] = cc.p(-1, 0),
  //     [1] = cc.p(-1, 1),
  //     [4] = cc.p(0, 1)
  //   },
  //   [4] = {
  //     [1] = cc.p(-1, 0),
  //     [2] = cc.p(-1, -1),
  //     [3] = cc.p(0, -1)
  //   }
  // }
  // for k, v in pairs(config[cellIndex]) do
  //   local kingdomPoint = cc.p(cellKingdomPoint.x + v.x, cellKingdomPoint.y + v.y)
  //   local kingdomID = kingdomPointDefine.getKingdomIDWithPoint(kingdomPoint, cellRegionId)
  //   self.mapViewCellArray[k]:setKingdomID(kingdomID, kingdomPoint, cellRegionId)
  // end
}

