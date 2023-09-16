#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

struct RUnitPyramidGloryBuildInit
{
  uint32 _Level;
  bool _IsUnlock;

};

class WorldMapPyramidGloryBuild : public IWorldMapInstance
{
  public: 
    uint32 _Level;
    bool _IsUnlock;
    Sprite *_OccupyIcon;
    Sprite *_ResourceImage;
    Sprite *_ImageNameLv;
    Label  *_TextNameLv;

  public:
    CREATE_FUNC(WorldMapPyramidGloryBuild);
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void UpdateData(const RUnitPyramidGloryBuildInit &pData);
    void UpdateLevel();
    void PlayClickSound() override;
    void UpdateActivityState();
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
};