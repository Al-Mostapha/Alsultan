#pragma once

#include "Base/BaseTypeDef.h"
#include "Base/Type/XTuple.h"
#include "WorldInstance.Enum.h"
#include "IWorldMapInstance.h"
#include "Module/CityResource/Resource.Enum.h"
#include "Module/Player/Official/Official.Enum.h"
#include "Module/Player/Buff/Attribute.Enum.h"
#include "Base/Containers/HashMap.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Module/World/Kingdom/kingdomMap.Enum.h"
#include "Module/Guild/Pet/AlliancePet.Enum.h"
#include "Module/World/WorldMap/Monster/Boss/Boss.Type.h"



USING_NS_CC;

class IWorldInstanceBuilder;
class WorldMapCell;

struct RMonsterInitData{
  GOpt<bool> _IsCanKill;
  GOpt<EMapObjStateTypeDef> _Status;
  GOpt<int32> _LifeCount;
  int32 _BossID;
  EMapNpcFaceTypeDef _FaceTo;
};


struct RResourceInitData
{
  int32 _PlayerID = 0;
  int32 _LeagueID = 0;
  GString _PlayerName;
  GString _LeagueName;
  //Kingdom ID
  int32 _SourceID = 0;
  int32 _CurrentSourceNum = 0;
  EMapResourceLvBgColorDef _LvBgColor = EMapResourceLvBgColorDef::Normal;
  bool _IsSafe = false;
  int32 _OwnerUid = 0;
  int32 _Emoji = 0;
};


struct RWorldBuildingInitDataAttr{
  float _Range = 0;
};

struct RWorldBuildingInitData{
  int32 _PlayerID;
  int32 _PlayerLevel;
  GString _PlayerName;
  int32 _InMapID;
  int32 _HideBattleLev;
  EShowOfficialType _Official = EShowOfficialType::None;
  int32 _WorldOfficial = 0;
  int32 _LegendForSepOfficial = 0;
  int32 _HegemonOfficialType = 0;
  int32 _HegemonOfficial = 0;
  EShowOfficialType _ShowOfficialType = EShowOfficialType::None;
  int32 _AtlantisOfficialType = 0;
  int32 _NebulaOfficialID = 0;
  int32 _NebulaOfficialID2 = 0;
  EFactionType _FactionType = EFactionType::Normal;
  int32 _PrisonerNum = 0;
  int32 _Betray = 0;
  int32 _CityLevel = 0;
  int32 _StarLv = 0;
  
  int32 _LeagueID = 0;
  GString _LeagueName = "";
  int32 _LeagueFlag = 0;
  int32 _NecklaceID = 0;
  int32 _Camp = 0;
  int32 _EmojiID = 0;
  EMapObjStateTypeDef _Status = EMapObjStateTypeDef::None;
  bool _IsSafe = false;
  bool _HasScoutRecord = false;
  int32 _SourceKid = 0;
  int32 _KingdomId = 0;
  int32 _CastleSkin = 0;
  int32 _NameBox = 0;
  GTime _MoveCityCDEndTime;
  EWorldMapCastleEffectID _CastleEffect;
  EWorldMapCastleEffectID _SelfCastleEffect;
  GTime _CastleEffectStatusEndTime = -1;
  GTime _SelfCastleEffectStatusEndTime;
  GTime _CastleAppearanceEndTime;
  GTime _SysWarProtectStatusEndTime;
  bool _CastleAppearance;
  GHashMap<EAttributeEnum, RWorldBuildingInitDataAttr> _Attr;
  GString _Signature = "";
  ESignatureBoxType _SignatureBox = ESignatureBoxType::None;
};

struct RWorldAllianceBuildInitData{

  struct Beast{
    EAlliancePetState _Status;
    int32 _Type;
    float _LeftLife = 0;
  };
  struct Wall{
    float _HpMax = 0;
  };

  int32 _PlayerID;
  GString _PlayerName = "";
  int32 _LeagueID;
  GString _LeagueName = "";
  GString _LeagueAbbrName = "";
  int32 _LeagueFlag;
  EMapObjStateTypeDef _Status;
  EMapObjStateTypeDef _ModelState;
  EKingdomWarStatusType _WarStatus = EKingdomWarStatusType::None;
  EKingStatus _KingStatus = EKingStatus::None;
  int32 _ID = 0;

  GOpt<Wall> _Wall;
  GOpt<Beast> _Beast;

  int32 _ColorID;
};


struct RWorldInstanceData{
    Vec2 _TilePoint;
    EMapObjTypeDef _TileInstanceType;
    int32 _TileInstanceID;
    int32 _TileInstanceKingdomID;
    GOpt<RMassRef> _MassRef;
    int32 _SubMapType;
    EWorldInstanceClass _Class;
    int32 _ObjID;
    void *_ObjData;
};


struct RInstanceData{
  int32 _X;
  int32 _Y;
  EMapObjTypeDef _Type;
  int32 _ID;
  int32 _KID;
  int32 _DelayTime;
  int32 _SubMapType;  
  int32 _ObjID;
  int32 _SettingID;
  EWorldInstanceClass _Class;
  GOpt<RWorldInstanceData> _WorldInstanceData;
  GOpt<RMassRef> _Ref;
  void *_ObjData;
};


struct RWorldInstanceConfigLod;


struct RWorldInstanceConfigLod {
  EWorldInstanceClass _Class;
  EGrouID _BatchNode;
  bool _Cache;
  std::function<ELodLayer(EWorldLodDef, int32)> _LodLayerFun = nullptr;
  std::function<
    IWorldMapInstance *(
      IWorldInstanceBuilder *, 
      const RWorldInstanceConfigLod &, 
      WorldMapCell *, 
      RWorldInstanceData, 
      RInstanceData)
  > _CreateFun = nullptr;
  std::function<IWorldMapInstance *()> _ConstructorFun = nullptr;
  GHashMap<int32, GTuple<EWorldInstanceClass, std::function<IWorldMapInstance *()>>> _ClassTable;
  ELodLayer _LodLayer = ELodLayer::None;
};

struct RWorldInstanceConfig{

    int32 _HoldInstace = 0;
    GString _FromKey = "";
    bool _DelayTime = false;
    bool _IsHurtDie = false;
    std::function<bool(EWorldLodDef, int32, int32)> _LodShowFun = nullptr;
    GHashMap<EWorldLodDef, RWorldInstanceConfigLod> _Lod;
    GHashMap<int32, int32> _HoldInstaceTable;
};



struct RWorldInstanceOccupier{
  uint32 _PlayerID = 0;
  GString _PlayerName = "";
  int32 _LeagueID = 0;
  uint32 _SourceKid = 0;
  GString _LeagueName = "";
  GString _LeagueAbbrName = "";
  int32 _LeagueFlag = 0;
  GTime _CurrOccupyBeginTime;
  GTime _HistOccupyTotalSecs;
};

struct RLegendLordOccupierChangedEvArg{
  int32 _BuildID = 0;
  GOpt<RWorldInstanceOccupier> _Occupier;
};
