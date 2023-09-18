#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/UI/EventCenter/EventTemplate/WindTower/UIWindTowerMap.Tip.h"

class WorldMapWindTower : public IWorldMapInstance
{
  public:
    int32 _CreateUID = 0;
    EWindTowerStatus _Status = EWindTowerStatus::SURVEY;
    Sprite *_LostRuins;
    UIWindTowerMapTip *_CDTipNode;
    Sprite *_SpriteBg;
    Sprite *_StatusImg;
  public:
    CREATE_FUNC(WorldMapWindTower);
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void OnMessageListener() override;
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void UpdateData(EventCustom *pEvent = nullptr);
    void PlayClickSound() override;
    GTuple<bool, GTime, GTime> IsSurveying();
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
};