#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/CityResource/Resource.Enum.h"

struct RAllianceResourceInitData{
  int32 _Level;
  int32 _LeagueID = 0;
  GString _LeagueName;
  GOpt<bool> _IsSelfIn;
  EMapObjStateTypeDef _Status = EMapObjStateTypeDef::None;
  int32 _LeftTime = 0;
  int32 _SurplusPoint = 0;
  int32 _BuildSpeed = 0;
  int32 _BuildSpeedTime = 0;
  int32 _TotalPoint = 0;
};

class WorldMapAllianceResource : public IWorldMapInstance
{
  public:
    int32 _ResourceClassID;
    EResourceType _ResourceType;
    int32 _ResourceLevel;
    bool _IsSelfIn = false;
    int32 _LeftTime = 0;
    int32 _BuildPoint = 0;
    EMapObjStateTypeDef _AllianceResourceState = EMapObjStateTypeDef::Free;

    Sprite *_OccupyIcon;
    Sprite *_ResourceImage;
    Sprite *_ImageName;
    Label *_TextName;

    GOpt<RAllianceResourceInitData> _SuperRes;

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