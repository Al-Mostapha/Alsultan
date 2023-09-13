#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/Kingdom/KingdomMap.Enum.h"
#include "Module/World/WorldMap/WorldMap.Define.h"

struct RWorldMapFortressInit{
  int32 _PlayerID;
  int32 _EmojiID;
  GString _PlayerName;
  int32 _LeagueID;
  uint32 _SourceKid;
  GString _LeagueName;
  GString _LeagueAbbrName;
  int32 _LeagueFlag;
  EMapObjStateTypeDef _Status;
  EMapObjStateTypeDef _ModelState;
  EKingdomWarStatusType _WarStatus;
  EKingStatus _KingStatus;
};

class WorldMapFortress : public IWorldMapInstance
{
  EMapObjStateTypeDef _BattleState = EMapObjStateTypeDef::Free;
  EMapObjStateTypeDef _ModelState = EMapObjStateTypeDef::Free;
  EKingdomWarStatusType _WarStatus = EKingdomWarStatusType::close;
  EKingStatus _KingStatus = EKingStatus::None;
  uint32 _SourceID = 0;
  Sprite *_ModelImage;
  WorldMapProtectNode *_ImageProtect;
  Sprite *_ImageLeagueFlag;
  Sprite *_ImageLeagueName;
  Label *_TextLeagueName;
  Sprite *_ImagePlayerName;
  Label *_TextPlayerName;

  public:
    CREATE_FUNC(WorldMapFortress);
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void OnMessageListener() override;
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pSiteClassID, void *pData, int32 pObjData) override;
    void InitInstanceData(int32 pSiteClassID, const RWorldMapFortressInit &pFortress, int32 pObjData);
    void UpdateData(const RWorldMapFortressInit &pFortress);
    void UpdatePlayerInfo();
    void UpdateSafeState();
    void UpdateBattleState();
    void UpdateModelState();
    void AddFortressEffect();
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
    void PlayClickSound() override;
    
};