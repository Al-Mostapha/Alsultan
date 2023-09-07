#pragma once
#include "Module/World/WorldMap/Instance/WorldInstance.Type.h"
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"




class WorldMapMonster : public IWorldMapInstance
{
  public:
  CREATE_FUNC(WorldMapMonster);
  int32 _MonsterClassID;
  GString _ImgName;
  GString _ImgNameAngle;
  bool _IsFlipX;
  EMapObjStateTypeDef _MonsterState;
  bool _IsCanKill;
  Vector<SpriteFrame *> _FightingFrames;
  GString _FightingImgNameAngle;
  int32 _FramesNumber;
  float _FramesTimes;
  bool _FightingIsFlipX;
  bool _IsWastelandMonster;
  EGrouID _GroupID;

  GString _MonsterName;
  int32 _MonsterLevel;
  int32 _LifeCount;

  Sprite *_Monster;
  Label *_MonsterNameLabel;
  Sprite *_ImageLevel;
  Label *_MonsterLevelLabel;

  RMonsterInitData _NpcData;
  
  void Ctor() override;

  void _InitUI();
  void _InitData();

  void AddCacheBefore() override;
  void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
  GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;

  void DoStopAllActions();
  void InitInstanceData(
    int32 pMonsterClassID, const GString &pImgNameAngle,
    bool pIsFlipX, void *pNpcData
  ) override;
  void UpdateData(const RMonsterInitData &pNpcData);
  void RefreshNameLabel(const RMonsterInitData &pNpcData);
  bool CheckIsWastelandMonster(int32 pMonsterClassID = 0);

  void BeginAttack(Vec2 pFacePoint);
  void DoStandingAnimation();
  void DoDieingAnimation();
  void DoFightingAnimation();
  void AddFightEffect();
  void FinishedAfterDead();
  void BottomApertureEffect();
  void PlayClickSound() override;
  int32 GetBelongInstanceID();
};