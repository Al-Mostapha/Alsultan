#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Instance/WorldInstance.Enum.h"
#include "Module/World/Kingdom/kingdomMap.Enum.h"

class UIWorldMapAllianceBuildProgressBar;
class UIWorldMapBossProgressBar;
class UITimerLabel;

struct RWorldAllianceBuildInitData{

  struct Beast{
    EAlliancePetState _Status;
    int32 _Type;
    float _LeftLife = 0;
  };
  struct Wall{
    float _HpMax = 0;
  };

  int32 _PlayerID;
  GString _PlayerName = "";
  int32 _LeagueID;
  GString _LeagueName = "";
  GString _LeagueAbbrName = "";
  int32 _LeagueFlag;
  EMapObjStateTypeDef _Status;
  EMapObjStateTypeDef _ModelState;
  EKingdomWarStatusType _WarStatus = EKingdomWarStatusType::None;
  EKingStatus _KingStatus = EKingStatus::None;
  int32 _ID = 0;

  GOpt<Wall> _Wall;
  GOpt<Beast> _Beast;

  int32 _ColorID;
};

class WorldMapAllianceBuild : public IWorldMapInstance
{
  public:

  class PetSprite : public Sprite
  {
    public:
      CREATE_FUNC(PetSprite);
      static PetSprite *Create(const GString &pSpriteFrame);
      void InitData(int32 pPetType);
  };

  Sprite *_ModelImage;
  EMapObjStateTypeDef _BattleState;
  EMapObjStateTypeDef _ModelState;
  EMapAllianceBuildType _BuildClassID = EMapAllianceBuildType::None;
  int32 _BuildID;
  int32 _ColorID;
  int32 _Size = 1;
  float _Radioation = 1;
  EKingdomWarStatusType _WarStatus = EKingdomWarStatusType::close;
  EKingStatus _KingStatus = EKingStatus::None;
  GOpt<RWorldAllianceBuildInitData::Beast> _BeastData;
  Color3B _RolygonColor;
  Sprite *_ImageLeagueFlag = nullptr;
  Sprite *_ImageLeagueName = nullptr;
  Label *_TextLeagueName = nullptr;
  Sprite *_ImagePlayerName = nullptr;
  Label *_TextPlayerName = nullptr;
  Sprite *_ImagePtBg = nullptr;
  Label *_TextStateDesc = nullptr;
  UIWorldMapAllianceBuildProgressBar *_ProgressBar = nullptr;
  UIWorldMapBossProgressBar *_ProgressBarPet = nullptr;
  PetSprite *_PetSingle = nullptr;
  Node *_EffectNodeDown = nullptr;
  Node *_EffectNodeUp = nullptr;
  UITimerLabel *_TextStateTime = nullptr;

  void Ctor() override;
  void OnMessageListener() override;
  void AddCacheBefore() override;
  void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;

  void UpdateForbidMapObjWarSatusData(EventCustom *pEvent);
  void SetBuildSize(int32 pSize, float pRadioation);
  void InitInstanceData(EMapAllianceBuildType pBuildClassID, const RWorldAllianceBuildInitData &pData);
  EMapAllianceBuildType GetBuildClassID();
  int32 GetBuildID();
  void UpdateData(const RWorldAllianceBuildInitData &pData);
  void UpdateBeastInfo();
  PetSprite *CreatePetSingle(int32 pPetType);
  void SetBlessEffectDown();
  void SetBlessEffectUp();
  void SetTrialEffectDown();
  void SetTrialEffectUp();
  void CloseAlliancePetEffect();
  Color3B GetTerritoryColor();
  void UpdatePlayerInfo();
  void UpdateBattleState();
  void UpdateProcessBar(const RWorldAllianceBuildInitData &pData);
  void UpdateStopBattleTime(GTime pLastTime);
  GString GetFavoriteName();
  void PlayClickSound() override;
  GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
  GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
};