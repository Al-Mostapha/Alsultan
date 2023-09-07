#pragma once
#include "Module/World/WorldMap/Instance/IWorldMapInstance.h"
#include "Module/World/WorldMap/Instance/WorldInstance.Type.h"
#include "Module/World/WorldMap/Instance/Component/WorldMapProtectNode.h"
#include "Module/Player/Lord.Enum.h"
#include "Module/Player/Buff/Attribute.Enum.h"
#include "Module/Building/Building.Enum.h"
#include "Base/Containers/HashMap.h"

class UITimerLabel;
class WorldMapFireWorkEffect;
class FireTimeNode;

static const float IMG_PROTECT_SCALE_DEF = 0.75f;
static const float IMG_PROTECT_SCALE_WAR = 0.95f;
static const float IMG_PROTECT_SCALE_WAR_10 = 1.f;
static const float IMG_PROTECT_SCALE_SKIN = 0.9f;
static const Vec2 IMG_OFFSET_DEF = Vec2(0, 70);
static const Vec2 IMG_OFFSET_WAR =Vec2(-25, 110);
static const Vec2 IMG_OFFSET_WAR_10 = Vec2(0, 70);
static const Vec2 IMG_OFFSET_SKIN = Vec2(-30, 70);
static const int32 WAR_LV_BEGIN_TYPE = 500; 





class WorldMapBuilding : public IWorldMapInstance
{
  public:
  CREATE_FUNC(WorldMapBuilding);
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
  
  GTime _CastleAppearanceEndTime;
  GTime _SysWarProtectStatusEndTime;

  Sprite *_CityImage = nullptr;
  Sprite *_CitySkin1Image = nullptr;
  Sprite *_CurCityImage = nullptr;
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
  Sprite *_PrisoneInIcon = nullptr;
  Sprite *_MeteoriteEffect = nullptr;
  Sprite *_ImageMoveCityTime = nullptr;
  Sprite *_SpStarLight = nullptr;
  
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
  Node *_NodeSnowMan = nullptr;
  Node *_NodeSnowEffect = nullptr;
  Node *_EtNodeLove = nullptr;
  Node *_EtNodeRainbow = nullptr;
  Node *_EtNodeShining = nullptr;
  Node *_PyramidProtectNode = nullptr;
  Node *_BuildStarLight = nullptr;
  Node *_BuildStarLevel = nullptr;
  FireTimeNode *_FireWorkTimeNode = nullptr;

  ui::Text *_SignText = nullptr;
  ui::ImageView *_SignImage = nullptr;
  
  UITimerLabel *_TxtMoveCityTime = nullptr;
  WorldMapFireWorkEffect *_FireWork = nullptr;

  WorldMapProtectNode *_ImageProtect = nullptr;

  void Ctor() override;
  void _InitData();
  void _InitUI();
  void OnMessageListener() override;

  void SetBatchNodeGroupID(EGrouID pBatchNodeGroupID) override;

  bool IsInAllianceWar();
  void AddCacheBefore() override;
  void SetSkinGroupID(EBuildingCastleModel pModel);
  void InitCityData(void *pData);
  void UpdateData(const RWorldBuildingInitData &pData);
  void ShowInstance(bool pShow, int32 pDelayTime = 0);
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
  void CheckAllCastleMeteorteEffect(const GHashMap<EAttributeEnum, RWorldBuildingInitDataAttr> &pAttr, bool pIsRemove = false);
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
  GVector<RButtonTypeArray> GetInstanceOp(bool pIsSelfKingdom, bool pIsInWar) override;
  void LazyCreateOfficalImage();
  void UpdatePrisoneIn();
  void LazyCreatePrisoneInImage();
  void UpdateOfficial();
  void UpdateTopShowIcons();
  Node *CreateMoveCityTimeNode();
  void CleanMoveTime();
  void UpdateMoveTime();
  void UpdateWallWarning(EventCustom *pEvent);
  int32 GetSourceKingdomID();
  void SendTileEffectMessage(EWorldMapLeagueManorUpdateType pUpdateType, float pRadius = 0.f);
  GTuple<UIBasePanel *, bool, Node*> OnClickInstance(Node *pNode) override;
  GTuple<UIBasePanel *, bool, Node*> OnShowWorldMapTip(Node *pNode) override;
  void RefreshSignShow(bool pIsShow = false);
  void RefreshSignText();
  void SetIsOnClick(bool pIsOnClick);
  void RefreshSkillEffect(const RWorldBuildingInitData &pData);
  Node *CreateSkillEffect(ESkillEffectType pEffectType);
  void UpdateBuildStar(int32 pStarLv);
  void SetBuildStarEffect();
  void SetBuildStarGroupID(Node *pTarget);
  bool IsSysWarProtect();
  
  void CheckAndSetVisible(Node *pWidget, bool pIsVisible);
  
};