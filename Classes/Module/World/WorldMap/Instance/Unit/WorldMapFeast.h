#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

struct RUnitFeastInit{
  uint32 _AllianceFlag = 1;
  GString _LeagueName;
  uint32 _FeastLv;
  GHashMap<uint32, uint32> _FeastRef;
  uint32 _Aid;
};

class WorldMapFeast : public IWorldMapInstance
{
  public:
    Sprite *_ModelImage = nullptr;
    Vec2 _TilePoint;
    uint32 _LeagueFlag = 1;
    Sprite *_OccupyIcon = nullptr;
    Sprite *_ImageLeagueFlag = nullptr;
    Sprite *_ImageName = nullptr;
    Label *_TextName = nullptr;
    uint32 _FeastClassID = 0;
    RUnitFeastInit _FeastData;
  public:
    CREATE_FUNC(WorldMapFeast);
    void Ctor() override;
    void OnMessageListener() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void SetTilePoint(Vec2 pTilePoint);
    Vec2 GetTilePoint();
    void SetInstanceID(uint32 pInstanceID);
    uint32 GetInstanceID();
    void UpdateData( const RUnitFeastInit &pData);
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    void PlayClickSound() override;
    void AddCacheBefore() override;
};