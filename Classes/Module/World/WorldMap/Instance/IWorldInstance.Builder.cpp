#include "IWorldInstance.Builder.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"

void IWorldInstanceBuilder::Init(GVector<WorldMapCell *> pCellArray){
  for(auto mapViewCell : pCellArray){
    InitMapCell(mapViewCell);
  }
  _MapViewCellArray = pCellArray;
}

void IWorldInstanceBuilder::InitMapCell(WorldMapCell *pCell){
  auto lNode = GDisplay::Get()->NewNode();
  pCell->addChild(lNode, static_cast<int32>(WorldMapDefine::Z_ORDER_CELL::objView));
  lNode->setName(_LayerName);
  pCell->operator[](_LayerName) = lNode;
}

