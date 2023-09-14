#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/UI/Panel/World/WorldMap/Instance/Unit/Boss/UIWorldMapBoss.ProgressBar.h"
#include "Module/World/WorldMap/Monster/Boss/Boss.Type.h"
#include "Module/World/Kingdom/KingdomMap.Enum.h"

struct RWorldMapBossInit{
  uint32 _Level = 0;
  uint32 _LeftLife = 0;
  GTime _LeftTime = 0;
  bool _IsManuPlace = false;
  GString _Effects = "";
  GOpt<uint32> _Frams;
  GString _Name = "";
  uint32 _SettingID = 0;
  EMapObjStateTypeDef _Status = EMapObjStateTypeDef::None;
  uint32 _PlaceUid = 0;
  GTime _RecoverBeginTime;
  uint32 _ObjId = 0;
  EKingdomWarStatusType _WarStatus = EKingdomWarStatusType::None;
};



struct RAddFireData{
  GOpt<float> _FightingToPointX;
  GOpt<float> _FightingToPointY;
};

class WorldMapBoss : public IWorldMapInstance
{
  public:
    EBossType _BossClassID = EBossType::None;
    GString _ImgName = "bhmt";
    int32 _LeftLife = 0;
    GTime _LeftTime = 0;
    bool _IsManuPlace = false;
    GString _ImgNameAngle = "";
    RBossShowData _BossData;
    GString _BossName = "";
    uint32 _BossLevel = 0;
    uint32 _SettingID = 0;
    uint32 _PlaceUid = 0;
    GTime _RecoverBeginTime;

    bool _IsFlipX = false;
    EMapObjStateTypeDef _BossState = EMapObjStateTypeDef::None;
    Vector<SpriteFrame *> _FightingFrames;
    GString _FightingImgNameAngle = "";
    bool _FightingIsFlipX = false;
    bool _HasHD = false;
    int32 _FramesNumber = 8;
    float _FramesTimes = 0.15;
    EGrouID _GroupID = EGrouID::None;


    Sprite *_BossImg = nullptr;
    Label *_NameLabel = nullptr;
    Sprite *_ImageLevel = nullptr;
    Label *_LevelLabel = nullptr;
    UIWorldMapBossProgressBar *_ProgressBar = nullptr;
    Node *_RefNode = nullptr;
    Label *_RefLabel = nullptr;

    void Ctor() override;
    virtual void _InitData();
    virtual void _InitUI();
    void OnMessageListener() override;
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(
      EBossType pBossClassID, const GString &pImageAngle, 
      bool pIsFlipX, const RWorldMapBossInit &pInitData
    );
    EBossType GetBossClassID() const;
    virtual void updateData(const RWorldMapBossInit &pInitData);
    void AddFireEffect(float pFightTime, const RAddFireData &pData);
    void SetScaleAndPositionY();
    void DoStopAllActions();
    void BeginAttack(Vec2 pFacePoint);
    void DoStandingAnimation();
    void DoFightingAnimation();
    void DoDieingAnimation();
    void FinishedAfterDead();
    void AddFightEffect();
    virtual GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    void PlayClickSound() override;
    void UpdateProcessBar();
    bool CheckIsEndlessTrialBoss();
    GTuple<UIBasePanel *, bool, Node*> OnClickEndlessTrialBoss(Node *pNode);
    void SetMassRef(GOpt<RMassRef> pMassRef);
    GTime GetReleaseLeftTime();
    int32 GetRefNum(const RMassRef &pMassRef);
    int32 GetPlaceUid();
    int32 GetSettingID();
};