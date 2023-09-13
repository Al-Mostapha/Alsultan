#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

struct RKingdomLvTowerInit{
  uint32 _Level = 0;
  bool _IsUnlock = false;
};

class WorldMapKingdomLvTower : public IWorldMapInstance
{
  uint32 _Level;
  bool _IsUnlock = false;
  Sprite *_OccupyIcon;
  Sprite *_ResourceImage;
  Node *_EffectBottom;
  Node *_Effect;
  Sprite *_ImageNameLv;
  Label *_TextNameLv;
  Sprite *_SpriteLock;
  Sprite *_ImageLevel;
  Label *_ResourceLevelLabel;

  public:
    CREATE_FUNC(WorldMapKingdomLvTower);
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void OnMessageListener() override;
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pSiteClassID, void *pData, int32 pObjData) override;
    void InitInstanceData(int32 pSiteClassID, const RKingdomLvTowerInit &pBuildData, int32 pObjData);
    void UpdateData(const RKingdomLvTowerInit &pBuildData);
    void UpdateLevel();
    void PlayClickSound() override;
    void UpdateActivityState(EventCustom *pEvent = nullptr);
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
};