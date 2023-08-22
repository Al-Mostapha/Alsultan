#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/CityResource/Resource.Enum.h"

struct RAllianceResourceInitData{};

class WorldMapAllianceResource : public IWorldMapInstance
{
  public:
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void OnMessageListener() override;
    void AddCacheBefore() override;
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void InitInstanceData(int32 pResourceClassID, const RAllianceResourceInitData &pData);
    void UpdateData(const RAllianceResourceInitData &pData);
    GString GetFavoriteName();
    void PlayClickSound() override;
    int32 GetBuildPoint();
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
    bool CheckIsSelfIn();
};