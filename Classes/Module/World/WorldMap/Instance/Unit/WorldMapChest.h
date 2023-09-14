#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/WorldMap.Define.h"

struct RUnitChestInit{
  GHashMap<int32, bool> _CollUids;
  uint32 _Level = 0;
  int32 _LeftCount = 0;
  int32 _ChestRewardLimit = 0;
};

class WorldMapChest : public IWorldMapInstance
{
  
  public:
    int32 _ChestClassID;
    bool _IsColl = false;
    uint32 _ChestLevel = 0;
    uint32 _LeftCount = 0;
    uint32 _DailyMaxCount = 0;
    Sprite *_ChestImg = nullptr;
    Label *_NameLabel = nullptr;
    Sprite *_ImageLevel = nullptr;
    Label *_LevelLabel = nullptr;
    Sprite *_CountLabelBg = nullptr;
    Label *_CountLabel = nullptr;
    RChestBackShow _ChestShow;
    
    CREATE_FUNC(WorldMapChest);
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void OnMessageListener() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void UpdateData(const RUnitChestInit &pChestData);
    int32 GetChestClassID();
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    void AddCacheBefore() override;
    void PlayClickSound() override;
};