#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"

struct RWorldMapEscortInit{
  bool _IsSelfIn;
};

class WorldMapEscort : public IWorldMapInstance
{
  public: 
    bool _IsSelfIn = false;
    Sprite *_BgImage;
    CREATE_FUNC(WorldMapEscort);
    void Ctor() override;
    void _InitData();
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pSiteClassID, void *pBatteryData, int32 pObjData) override;
    void UpdateData(const RWorldMapEscortInit &pInitData);
    GString GetFavoriteName();
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    void PlayClickSound() override;
    void Req4Escort();
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
    void AddCacheBefore() override;
};