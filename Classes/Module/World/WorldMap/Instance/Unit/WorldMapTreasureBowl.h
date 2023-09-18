#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

struct RUnitTreasureBowlInit{
  GHashMap<int32, bool> _CollUids;
  uint32 _Level = 0;
  bool _LockStatus = false;
  uint32 _ClickCount = 0;
  GTime _CoolTime;
  EMapObjStateTypeDef _TreasureState;
  bool _IsColl;
  EMapObjTypeDef _MapType;
};

class WorldMapTreasureBowl : public IWorldMapInstance
{
  public:
    int32 _TreasureBowlClassID = 0;
    GString _TreasureImg = "";
    bool _IsColl = false;
    int32 _TreasureBowlLevel = 0;
    bool _LockStatus = false;
    int32 _CoolTime = 5;
    int32 _MaxCount = 10;
    EMapObjStateTypeDef _TreasureState = EMapObjStateTypeDef::Free;
    int32 _InstanceID = 0;
    GOpt<RUnitTreasureBowlInit> _TreeData;
    
    Sprite *_TreasureBowlImg = nullptr;
    Label *_NameLabel = nullptr;
    Sprite *_ImageLevel = nullptr;
    Label *_LevelLabel = nullptr;
    Sprite *_ImageHammer = nullptr;
    Node *_PyramidProtectNode = nullptr;
  public:
    CREATE_FUNC(WorldMapTreasureBowl);
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void UpdateData(const RUnitTreasureBowlInit &pData);
    int32 GetTreasureBowlClassID();
    void ShowHammer(bool pShow);
    void DoDieingAnimation();
    void PosuitxEffect();
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    void PlayClickSound() override;
};