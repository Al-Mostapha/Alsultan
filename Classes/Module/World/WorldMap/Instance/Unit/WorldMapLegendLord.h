#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Instance/WorldInstance.Type.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/Kingdom/KingdomMap.Enum.h"




class UIWorldMapLegendLordProgressBar;

struct RLegendLordInitData{
  GOpt<RWorldInstanceOccupier> _Occupier = {};
  EKingdomWarStatusType _WarStatus = EKingdomWarStatusType::close;
  EKingStatus _KingStatus = EKingStatus::None;
  EMapObjStateTypeDef _Status = EMapObjStateTypeDef::Free;
  bool _FirstKillReward = false;
  int32 _PlayerID = 0;
  int32 _EmojiID = 0;
};


class WorldMapLegendLord : public IWorldMapInstance
{
  EKingdomWarStatusType _WarStatus = EKingdomWarStatusType::close;
  EKingStatus _KingStatus = EKingStatus::None;
  EMapObjStateTypeDef _BuildState = EMapObjStateTypeDef::Free;
  GTime _OccupyTime;
  bool _IsOccupy = false;
  int32 _SiteClassID = 0;
  int32 _SourceID = 0;
  GOpt<RWorldInstanceOccupier> _Occupier = {};
  bool _FirstKillReward = false;

  Node *_BgImage;
  Sprite *_ImageBg;
  WorldMapProtectNode *_ImageProtect;
  Sprite *_ImageLeagueFlag;
  Sprite *_ImageBuildName;
  Label *_TextBuildName;
  Sprite *_ImageLeagueName;
  Label *_TextLeagueName;
  Sprite *_ImagePlayerName;
  Label *_TextPlayerName;
  UIWorldMapLegendLordProgressBar *_ProgressBar;

  public: 
  CREATE_FUNC(WorldMapLegendLord);
  void Ctor() override;
  void _InitData();
  void _InitBuildBg();
  void _InitUI();

  int32 GetSiteClassID();
  void OnMessageListener() override;
  void AddCacheBefore() override;
  void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
  void InitInstanceData(int32 pSiteClassID, void *pBatteryData, int32 pObjData) override;
  void InitInstanceData(int32 pSiteClassID, const RLegendLordInitData &pBatteryData, int32 pObjData);
  void UpdateData(const RLegendLordInitData &pBatteryData);
  void UpdatePlayerInfo();
  void UpdateSafeState();
  void UpdateStatus();
  void UpdateProcessBar();
  void PlayClickSound() override;
  GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
  GString GetFavoriteName();
  GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
};