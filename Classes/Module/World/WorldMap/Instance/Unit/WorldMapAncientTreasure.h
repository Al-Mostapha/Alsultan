#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"


struct RAncientTreasureInitData{};

class WorldMapAncientTreasure : public IWorldMapInstance
{
  public:
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void OnMessageListener() override;
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(const RAncientTreasureInitData &pData);
    void UpdateData(const RAncientTreasureInitData &pData);
    void UpdatePlayerInfo();
    GString GetFavoriteName();
    void PlayClickSound() override;
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
};