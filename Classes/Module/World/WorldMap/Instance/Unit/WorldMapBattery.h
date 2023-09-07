#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Instance/WorldInstance.Type.h"

class WorldMapProtectNode;

struct RWorldBatteryInitData{
  int32 _PlayerID = 0;
  GString _PlayerName = "";
  int32 _EmojiID = 0;
  int32 _LeagueID = 0;
  int32 _SourceKid = 0;
  GString _LeagueName = "";
  GString _LeagueAbbrName = "";
  int32 _LeagueFlag = 0;
  EMapObjStateTypeDef _Status = EMapObjStateTypeDef::Free;
  EMapObjStateTypeDef _ModelState = EMapObjStateTypeDef::Free;
  int32 _Damage = 0;
  EKingdomWarStatusType _WarStatus = EKingdomWarStatusType::None;
  EKingStatus _KingStatus = EKingStatus::None;
};

class WorldMapBattery : public IWorldMapInstance
{
  int32 _BulletZOrder = 0;
  EMapObjStateTypeDef _BatteryState = EMapObjStateTypeDef::Free;
  EMapObjStateTypeDef _ModelState = EMapObjStateTypeDef::Free;
  int32 _AllHurtNum = 100;
  int32 _HurtCount = 4;
  int32 _SourceID = 0;
  EKingdomWarStatusType _WarStatus = EKingdomWarStatusType::close;
  EKingStatus _KingStatus = EKingStatus::None;
  EKWBattery _SiteClassID = EKWBattery::None;
  Vec2 _ShowTilePoint = Vec2::ZERO;
  Vec2 _WorldCenterPoint = Vec2(600, 600);

  Node *_NodeMode = nullptr;
  Sprite *_BaseImage = nullptr;
  Sprite *_ModelImage = nullptr;
  Sprite *_ModelImageMask = nullptr;
  WorldMapProtectNode *_ImageProtect = nullptr;
  Sprite *_ImageLeagueFlag = nullptr;
  Sprite *_ImageLeagueName = nullptr;
  Label *_TextLeagueName = nullptr;
  Sprite *_ImagePlayerName = nullptr;
  Label *_TextPlayerName = nullptr;

  public:
    CREATE_FUNC(WorldMapBattery);
    void Ctor() override;
    void _InitData();
    void _InitUI();

    void OnMessageListener() override;
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    EKWBattery GetSiteClassID();
    void InitInstanceData(int32 pSiteClassID, void *pBatteryData, int32 pObjData) override;
    void InitInstanceData(EKWBattery pSiteClassID, const RWorldBatteryInitData &pBatteryData, int32 pObjData);
    void UpdateData(const RWorldBatteryInitData &pBatteryData);
    void UpdatePlayerInfo();
    void UpdateSafeState();
    void UpdateBatteryState();
    void UpdateModelState();
    GString GetAnimationKey();
    void DoFreeAnimation();
    void UpdateShot(int32 pDamage);
    void DoFightingAnimation();
    void DoFightingAnimation_Imp();
    void DoHurtDieAnimation();
    Node *CreatePaojiEffect(const GString &pFightingImgNameAngle, bool pIsLeft);
    Node *CreateEffectFireStone();
    void PlayClickSound() override;
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
};