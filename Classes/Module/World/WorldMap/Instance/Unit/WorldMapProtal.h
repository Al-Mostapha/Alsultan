#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

class WorldMapProtal : public IWorldMapInstance
{
  public:
    Node   *_Effect;
    Sprite *_BgImage;
    Sprite *_ImageName;
    Label  *_TextName;
    int32  _BuildClassID;
  public:
    CREATE_FUNC(WorldMapProtal);
    void Ctor() override;
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    void PlayClickSound() override;
    void AddShaderEffect();;
    void AddCacheBefore() override;
};