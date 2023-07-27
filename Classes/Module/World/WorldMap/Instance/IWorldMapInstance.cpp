#include "IWorldMapInstance.h"
#include "Module/World/WorldMap/View/WorldMap.Cell.h"

GTuple<UIBasePanel *, bool, Node*> IWorldMapInstance::OnClickInstance(Node *p_Node)
{
  return GTuple<UIBasePanel *, bool, Node*>();
}

void IWorldMapInstance::SetBatchNodeGroupID(EGrouID pBatchNodeGroupID){}
void IWorldMapInstance::SetInstanceType(EMapObjTypeDef pInstanceType){}
void IWorldMapInstance::SetWorldMapCell(WorldMapCell *pWorldMapCell){}
void IWorldMapInstance::SetKingdomID(int32 pKingdomID){}
void IWorldMapInstance::SetMapTypeClass(EKingdomClassType pMapClassType){}
void IWorldMapInstance::SetInstanceID(int32 pInstanceID){}
void IWorldMapInstance::SetTilesArray(GVector<Vec2> pTilesArray){}
void IWorldMapInstance::SetTilePoint(Vec2 pTilePoint){}
void IWorldMapInstance::SetHoldInstace(int32 pHoldInstace){}