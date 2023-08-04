#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Instance/Component/WorldMapProtectNode.h"
#include "Module/Player/Lord.Enum.h"
#include "Module/Player/Buff/Attribute.Enum.h"
#include "Module/Building/Building.Enum.h"

class UITimerLabel;
class WorldMapFireWorkEffect;

static const float IMG_PROTECT_SCALE_DEF = 0.75;
static const float IMG_PROTECT_SCALE_WAR = 0.95;
static const float IMG_PROTECT_SCALE_WAR_10 = 1;
static const float IMG_PROTECT_SCALE_SKIN = 0.9;
static const Vec2 IMG_OFFSET_DEF = Vec2(0, 70);
static const Vec2 IMG_OFFSET_WAR =Vec2(-25, 110);
static const Vec2 IMG_OFFSET_WAR_10 = Vec2(0, 70);
static const Vec2 IMG_OFFSET_SKIN = Vec2(-30, 70);
static const int32 WAR_LV_BEGIN_TYPE = 500; 

enum class ESignatureBoxType{
  None = 0,
  Normal = 1,
  War = 2
};

enum class ESkillEffectType {
  None = 0,
  RUINS_WAR_MOVE_CITY_LOCKED = 1,
  RUINS_WAR_SPEED_QUEUE_LOCKED = 2,
  APPOINT_DAMAGE_BOOST = 3,
  APPOINT_CURE_SOLDIER_SPEED_BOOST = 4
};

struct RWorldBuildingInitData{

  struct Attr{
    float _Range = 0;
  };

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
  GHashMap<EAttributeEnum, Attr> _Attr;
  GString _Signature = "";
  ESignatureBoxType _SignatureBox = ESignatureBoxType::None;
};


class WorldMapBuilding : public IWorldMapInstance
{
  public:

  bool _IsShowWarLv = false;
  bool _IsShowOffice = false;
  bool _IsShowPrision = false;
  bool _IsSafe = false;
  bool _HideBattleLev = false;
  bool _IsOnClick = false;

  float _ImgScale = IMG_PROTECT_SCALE_DEF;

  int32 _LeaguedOfficialType = 0;
  int32 _KingStarOfficialType = 0;
  int32 _HegemonOfficialType = 0;
  int32 _AtlantisOfficialType = 0;
  int32 _NebulaOfficialID = 0;
  int32 _NebulaOfficialID2 = 0;
  int32 _LeagueFlag = 1;
  int32 _WarCamp = 0;
  int32 _InMapID = 0;
  int32 _PlayerLevel = 1;
  int32 _CityLevel = 1;
  int32 _Betray = 0;
  int32 _PrisonerNum = 0;
  int32 _BulletNum = 0;
  int32 _SourceID = 0;
  int32 _SourceKingdomID = 0;
  int32 _EmojiID = 0;
  int32 _NecklaceID = 0;
  int32 _IsCityBgSkin = 0;
  int32 _StarLv = 0;
  int32 _MoveCityTime = 0;

  EMapObjStateTypeDef _BuildingState = EMapObjStateTypeDef::Free;
  EShowOfficialType _ShowOfficialType = EShowOfficialType::None;
  EShowOfficialType _OfficialType = EShowOfficialType::None;
  ESignatureBoxType _SignatureBox = ESignatureBoxType::None;
  EFactionType _FactionType = EFactionType::Normal;
  Vec2 _FacePoint = Vec2::ZERO;
  Vec2 _ImgOffset = IMG_OFFSET_DEF;
  GString _Signature = "";

  Sprite *_CityImage = nullptr;
  Sprite *_CitySkin1Image = nullptr;
  Sprite *_ImageLeagueFlag = nullptr;
  Sprite *_ImageCrown = nullptr;
  Sprite *_ImageZhencha = nullptr;
  Sprite *_ImageNameBg = nullptr;
  Sprite *_ImageLevel = nullptr;
  Sprite *_ImageNameBgSkin = nullptr;
  Sprite *_NecklaceIcon = nullptr;
  Sprite *_ImageName = nullptr;
  Sprite *_OfficalImage = nullptr;
  Sprite *_OfficalIcon = nullptr;

  Label  *_TextName = nullptr;
  Label *_TextLevel = nullptr;
  Label *_NecklaceName = nullptr;

  Node *_BulletNode;
  Node *_WarLVNode = nullptr;
  Node *_NodeWarLvNode = nullptr;
  Node *_SignNode = nullptr;
  Node *_NecklaceNode = nullptr;
  Node *_FireNodeEx = nullptr;
  Node *_NodeMoveCityTime = nullptr;

  ui::Text *_SignText = nullptr;
  ui::ImageView *_SignImage = nullptr;
  
  UITimerLabel *_TxtMoveCityTime = nullptr;
  WorldMapFireWorkEffect *_FireWork = nullptr;

  WorldMapProtectNode *_ImageProtect = nullptr;

  void Ctor() override;
  void _InitData();
  void _InitUI();
  void OnMessageListener() override;
  void RefreshSignShow(bool pIsShow);

  void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;

  bool IsInAllianceWar();
  void AddCacheBefore() override;
  void SetSkinGroupID(EBuildingCastleModel pModel);
  void InitCityData(const RWorldBuildingInitData &pData);
  void UpdateData(const RWorldBuildingInitData &pData);
  void ShowInstance(bool pShow, int32 pDelayTime);
  void UpdateLeagueInfo();
  void UpdateBuildingImg();
  void UpdateBuildingNecklace();
  GString SetLendLordPlayerInfo(const GString &pName);
  void UpdateWarLvEffect();

  void UpdateAllianceCounter(EventCustom *pEvent);
  void UpdateOfficeIcon(EventCustom *pEvent);
  void UpdatePrisionIcon(EventCustom *pEvent);
  GString SetWarPlayerInfo(EventCustom *pEvent);
  void AddSkinEffect(EBuildingCastleModel pCastleModel);
  void RemoveSkinEffect();
  void SetSkinConfig(EBuildingCastleModel pCastleModel, int32 pWarLv);
  void UpdateBuildingState();
  void SetImgProtect();
  void UpdateSafeState();
  void AddFireEffect(GTime pFireTime ) override;
  void DoFightingAnimation();
  void CrownUpEffect(Node *pNode);
  void CrownDownEffect(Node *pNode);
  Node *CreateLvEffectNode(int32 pWarLv);
  void WarLvEffect(int32 pWarLv);
  void RemoveWarLvEffect();
  void AddEnemyCastleEffect();
  void RemoveEnemyCastleEffect();
  bool IsNeedShowAttr(EAttributeEnum pAttrType);
  void CheckAllCastleMeteorteEffect();
  void AddMeteoriteSkillEffect(EAttributeEnum pAttrType);
  void RemoveMeteoriteSkillEffect();
  void CastleLoveEffect();
  void RemoveCastleEffect();
  void CastleSnowEffect();
  void CastleSnowIceEffect(bool pIsSelf = false);
  void CastleShiningEffect();
  void CastleShining2Effect();
  void CastleShining3Effect();
  void CastleShining4Effect();
  void CastleRainbowEffect();
  void RemoveCastleFireWorkEffect();
  void AddPyramidProtectEffect();
  void RemovePyramidProtectEffect();
  GString GetFavoriteName();
  void PlayClickSound() override;
  GVector<EWorldMapTipButtonType> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
  void LazyCreateOfficalImage();
  void UpdatePrisoneIn();
  void LazyCreatePrisoneInImage();
  void UpdateOfficial();
  void UpdateTopShowIcons();
  void CreateMoveCityTimeNode();
  void CleanMoveTime();
  void UpdateMoveTime();
  void UpdateWallWarning(EventCustom *pEvent);
  int32 GetSourceKingdomID();
  void SendTileEffectMessage(EWorldMapLeagueManorUpdateType pUpdateType, float pRadius);
  GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
  GTuple<UIBasePanel *, bool, Node*> OnShowWorldMapTip(Node *pNode) override;
  void RefreshSignShow(bool pIsShow);
  void RefreshSignText();
  void SetIsOnClick(bool pIsOnClick);
  void RefreshSkillEffect(const RWorldBuildingInitData &pData);
  void CreateSkillEffect(ESkillEffectType pEffectType);
  void UpdateBuildStar(int32 pStarLv);
  void SetBuildStarEffect();
  void SetBuildStarGroupID(Node *pTarget);
  bool IsSysWarProtect();

  void Toggle3D(EventCustom *pEvent);

  
};