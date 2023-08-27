#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/Activity/Activity.Enum.h"


struct RAncientTreasureInitData{
  int32 _PlayerID;
  int32 _OwnerID;
  int32 _EmojiID;
  GString _PlayerName;
  int32 _BuildID;
  int32 _AID;
  GString _LeagueName;
  GString _LeagueAbbrName;
  int32 _BuildType;
  EATBuildingStatus _BuildStatus = EATBuildingStatus::None;
};

class WorldMapAncientTreasure : public IWorldMapInstance
{
  public:
    Vec2 _Pos;
    int32 _BuildID;
    int32 _BuildType;
    EATBuildingStatus _TreasureState;

    Sprite *_ImageLeagueFlag;
    Sprite *_ImageLeagueName;
    Label *_TextLeagueName;
    Sprite *_ImagePlayerName;
    Label *_TextPlayerName;
    Sprite *_TreasureImg;
    Node *_EtNode;

    void Ctor() override;
    void _InitData();
    void _InitUI();
    void OnMessageListener() override;
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(const RAncientTreasureInitData &pData);
    void UpdateData(const RAncientTreasureInitData &pData);
    void UpdatePlayerInfo();
    GString GetFavoriteName();
    void PlayClickSound() override;
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
};