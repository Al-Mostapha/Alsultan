#pragma once
#include "WorldMapInstance.Lod.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "WorldInstance.Enum.h"

class WorldMapCell;

class IWorldMapInstance : public WorldMapInstanceLod
{
public:
  GString _LeagueName;
  int32 _PlayerID;
  EMapObjTypeDef _InstanceType;
  GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode);
  
  void SetInstanceType(EMapObjTypeDef pInstanceType);
  void SetWorldMapCell(WorldMapCell *pWorldMapCell);
  void SetKingdomID(int32 pKingdomID);
  void SetMapTypeClass(EKingdomClassType pMapClassType);
  void SetInstanceID(int32 pInstanceID);
  void SetTilesArray(GVector<Vec2> pTilesArray);
  void SetTilePoint(Vec2 pTilePoint);
  void SetHoldInstace(int32 pHoldInstace);
  
  virtual void InitInstanceData(void *pObjData){}
  virtual void InitInstanceData(EWorldInstanceClass pClass, void *pObjData, int32 pObjID = 0){}
  //angle name e, w, n, s, wn ...etc
  virtual void InitInstanceData(EWorldInstanceClass pClass, void *pObjData, GString pAngleName, bool pIsFlipX, int32 pObjID){}
};