#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

struct RWorldMapDrumAndVulnInit {
  uint32 _PlayerID = 0;
  GString _PlayerName;
  uint32 _LeagueID = 0;
  GString _LeagueName;
  uint32 _SourceKid = 0;
  uint32 _EmojiID = 0;
};

class WorldMapDrumAndVuln : public IWorldMapInstance
{
  public:
    bool _IsBeOccupyed = false;
    EWorldTypeServerDef _TreasureType = EWorldTypeServerDef::subMapTypeWarTreasureDrum;
    GTime _DigTime;
    uint32 _SourceID = 0;
    uint32 _ResourceClassID = 0;
    EMapObjStateTypeDef _TreasureState = EMapObjStateTypeDef::Free;
    uint32 _EmojiID = 0;
    Sprite *_TreasureImg = nullptr;
    Sprite *_OccupyIcon = nullptr;
  public:
    CREATE_FUNC(WorldMapDrumAndVuln);
    void Ctor() override;
    void _InitData();
    void OnMessageListener() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void UpdateData( const RWorldMapDrumAndVulnInit &pData);
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    void SetBeOccupyed();
    void CancelBeOccupyed();
    GString GetFavoriteName() ;
    void PlayClickSound() override;
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
    void AddCacheBefore() override;
};