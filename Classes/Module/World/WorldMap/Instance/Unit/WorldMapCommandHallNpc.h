#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/City/CityBuilding/CommandHall/CommandHall.Enum.h"

class CommandHallTaskNode;
struct RUnitCommandHallNpcInit{
  ECommandHallTaskType _TaskID = ECommandHallTaskType::None;
  uint32 _TaskIndex = 0;
  EMapObjStateTypeDef _Statue = EMapObjStateTypeDef::Free;
  bool _IsFlipX = false;
};

class WorldMapCommandHallNpc : public IWorldMapInstance
{
  public:
    EMapObjStateTypeDef _Statue = EMapObjStateTypeDef::Free;
    uint32 _FramesNumber = 16;
    float _FramesTimes = 0.06666666666666667f;
    ECommandHallTaskType _TaskID = ECommandHallTaskType::None;
    uint32 _TaskIndex = 0;
    GString _ImgNameAngle;
    GString _ImgName;
    bool _IsFlipX = false;
    bool _IsBuild = false;

    Sprite *_NpcImage = nullptr;
    CommandHallTaskNode *_TaskNode = nullptr;

    CREATE_FUNC(WorldMapCommandHallNpc);
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void OnMessageListener() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void UpdateData( const RUnitCommandHallNpcInit &pData);
    void PlayClickSound() override;
    void AddCacheBefore() override;
    void UpdateStatue();
    void DoStandingAnimation();
    void DoDieingAnimation();
    void FinishedAfterDead();
    void DoStopAllActions();
    void AddFireEffect(GTime pTimeEffect, const RUnitCommandHallNpcInit &pData);
    void BeginAttack(Vec2 pFacePoint);
    void DoFightingAnimation();
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    uint32 GetTaskIndex();
};