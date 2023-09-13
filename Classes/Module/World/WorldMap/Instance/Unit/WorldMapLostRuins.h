#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

class UILostRuinsMapTip;

class WorldMapLostRuins : public IWorldMapInstance
{
  int32 _CreateUID = 0;
  int32 _LeagueID = 0;
  Sprite *_LostRuins;
  Sprite *_LostRuinsEffect;
  UILostRuinsMapTip *_CDTipNode;
  Label *_CampNameLabel;
  Sprite *_SpriteBg;
  Sprite *_StatusImg;
  ELosRuinsStatus _Status;
  public:
    CREATE_FUNC(WorldMapLostRuins);
    void Ctor() override;
    void OnMessageListener() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void AddCacheBefore() override;
    void InitInstanceData(int32 pResourceClassID, void *pData, int32 pObjData) override;
    void UpdateData(EventCustom *pEvent);
    void PlayClickSound() override;
    GTuple<bool, GTime, GTime> IsSurveying();
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
};