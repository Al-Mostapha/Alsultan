#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

struct RBattelFieldSiteInit{
  GString _PlayerName;
  int32 _PlayerID = 0;
  EMapObjStateTypeDef _Status = EMapObjStateTypeDef::None;
  int32 _LeagueID = 0;
  GString _LeagueName;
  int32 _EmojiID = 0;
};

class WorldMapBattlefieldSite : public IWorldMapInstance
{
  public:
  EMapObjStateTypeDef _CampsiteState = EMapObjStateTypeDef::Free;
  int32 _EmojiID = 0;
  Sprite *_CampsiteImg;
  CREATE_FUNC(WorldMapBattlefieldSite);
  void Ctor() override;
  void _InitData();
  void _InitUI();
  void OnMessageListener() override;
  void UpdateAllianceCounter(EventCustom *pEvent);
  void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
  void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
  void UpdateData(const RBattelFieldSiteInit &pSiteData);
  void AddCacheBefore() override;
  GString GetFavoriteName();
  void PlayClickSound() override;
  GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
};