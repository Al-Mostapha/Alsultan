#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/Kingdom/KingdomMap.Enum.h"
#include "Module/Building/Building.Enum.h"
#include "Module/World/WorldMap/Instance/Component/WorldMapProtectNode.h"
#include "Module/Building/Building.Enum.h"

class UITimerLabel;

struct RWorldCastleInitData{
  GOpt<int32> _Model = {};
  int32 _PlayerID = 0;
  GString _PlayerName = "";
  int32 _LeagueID = 0;
  bool _IsSelfIn = false;
  int32 _SourceKid = 0;
  GString _LeagueName = "";
  GString _LeagueAbbrName = "";
  int32 _LeagueFlag = 0;
  int32 _EmojiId = 0;
  int32 _OwnerId = 0;
  GOpt<EKingdomWarStatusType> _WarStatus;
  GOpt<EKingStatus> _KingStatus;
  GOpt<bool> _ShowWarStatusTime = false;
  GOpt<GTime> _WarStatusTime = 0;
  GOpt<GTime> _WarStatusEndTime = 0;
  GOpt<EMapObjStateTypeDef> _Status;
  
};

class WorldMapCastle : public IWorldMapInstance
{
  public:

  int32 _SourceID = 0;
  int32 _LeagueFlag = 0;
  bool _IsSelfIn = false;
  EKingdomWarStatusType _WarStatus;
  EKingStatus _KingStatus;
  EMapObjStateTypeDef _CastleState;
  GTime _WarStatusTime  = 0;
  bool _ShowWarStatusTime = false;
  GString _LeagueAbbrName = "";


  Sprite *_BgImage = nullptr;
  WorldMapProtectNode *_ImageProtect;
  Sprite *_ImageState = nullptr;
  ui::Text *_TextStateTitle = nullptr;
  UITimerLabel *_TextStateTime = nullptr;
  Sprite *_ImageReady = nullptr;
  Label *_TextReady = nullptr;
  Sprite *_ImageLeagueFlag = nullptr;
  Sprite *_ImageLeagueName = nullptr;
  Label *_TextLeagueName = nullptr;
  Sprite *_ImagePlayerName = nullptr;
  Label *_TextPlayerName = nullptr;

  Node *_EffectNode_11 = nullptr;
  Node *_EffectNode_12 = nullptr;

  void Ctor() override;
  void _InitData();
  void _InitUI();
  void OnMessageListener() override;
  void AddCacheBefore() override;
  void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
  void InitInstanceData(const RWorldCastleInitData &pData);
  void UpdateData(const RWorldCastleInitData &pData);
  void UpdatePlayerInfo();
  void UpdateSafeState();
  void UpdateCastleState();
  void AddSkinEffect();
  void RemoveSkinEffect();
  void AddRamadanCeremonyEffect(int32 pModel);
  void RemoveRamadanCeremonyEffect(int32 pModel);
  GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
  void PlayClickSound() override;
  GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
};