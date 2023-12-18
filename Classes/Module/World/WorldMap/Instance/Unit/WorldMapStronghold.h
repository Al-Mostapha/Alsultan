#pragma once
#include "Base/Containers/HashMap.h"
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/Kingdom/KingdomMap.Enum.h"
#include "Module/World/WorldMap/WorldMap.Define.h"

class UITimerLabel;

struct RStrongholdNpc{
  int32 _LeaderNpcLeftLife;
  GHashMap<int32, int32> _NormalNpcLifes;
};

struct RStrongholdOccupy{
  int32 _Uid; //PlayerID
  GString _Name; //PlayerName
  int32 _ColorID; //ColorID
  int32 _Aid; //AllianceID
  GString _Abbr; //AllianceAbbr
  GString _AName; //AllianceName
  bool _IsIn; //IsInAlliance
};

struct RUnitStrongholdInit
{
  EKingdomWarStatusType _Status;
  EKingdomWarStatusType _WarStatus;
  GTime _WarStatusEndTime = 0;
  GOpt<RStrongholdNpc> _Npc;
  GOpt<RStrongholdOccupy> _Occupy;
};

class WorldMapStronghold : public IWorldMapInstance
{
  public:
    int32 _ObjID;
    EKingdomWarStatusType _Status;
    EKingdomWarStatusType _WarStatus;
    int32 _Size;
    int32 _Radioation;
    GTime _WarStatusEndTime;
    int32 _ColorID;

    Color3B _RolygonColor;

    Sprite *_ModelImage;
    Sprite *_ImageNameBg;
    Label *_TextName;
    Sprite *_ImageZlBg;
    Label *_TextZl;
    Sprite *_ImageLvBg;
    Label *_TextLevel;
    WorldMapProtectNode *_ImageProtect;
    Sprite *_ImagePtBg;
    UITimerLabel *_TextStateTime;
    Sprite *_ImagePicon;
    Node *_HoldEffect;
    
    GOpt<RStrongholdNpc> _Npc;
    GOpt<RStrongholdOccupy> _Occupy;
  public:
    CREATE_FUNC(WorldMapStronghold);
    void Ctor() override;
    void _InitData();
    void _InitUI();
    void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;
    void SetBuildSize(int32 pSize = 2, int32 pRadioation = 4);
    void AddCacheBefore() override;
    void InitInstanceData(int32 pClass, void *pObjData, int32 pObjID = 0) override;
    void InitBuildInfo();
    void SetHoldEffect(int32 pEffect);
    int32 GetBuildClassID();
    void UpdateData(const RUnitStrongholdInit &pData);
    void SetProtectTimeVisible(bool pVisible);
    void UpdatePlayerInfo();
    GString GetFavoriteName();
    void PlayClickSound() override;
    GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
    bool IsBeOccupied();
    GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
};