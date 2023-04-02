#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Base/Containers/HashMap.h"
#include "Module/Building/Building.Enum.h"
#include "CityScene.Enum.h"
#include "CityScene.Const.h"
#include "Module/City/CityBuilding/CityBuilding.Type.h"


class MainCityCreate{
  GHashMap<ECityTargetGroupID, Vector<Node*>> m_CityGroupNode;
public:
  class MainCityView *n_MainCityView;
  //    self.isNeedFirstFight = mainCity:getIsNeedFirstFight()
  float m_MinScale = 0.6f;
  float m_MinLimitScale = 0.5f;
  float m_DefaultScale = 0.9f;
  float m_NormalScale = 0.5;
  float m_ZoomScale = 0.5;
  float m_MaxScale = 1.8f;
  float m_MaxLimitScale = 2;
  float m_Inertia = 1.4f;
  float m_InitScrollViewScale = 1.4f;
  float m_NormlScrollViewScale = 1;
  float m_ZoomScaleDuration = 0.3f;
  float m_InitZoomScaleDuration = 0.6f;
  float m_AutoMoveSpeed = 2700;
  float m_AutoMoveSpeedSlow = 800;
  float m_HUITop = 40;
  float m_HUIBottom = 115;
  float m_TipBoxCount = 1;
  float m_TipBoxMaxCount = 12;
  float m_DarkCount = 1;
  float m_SoldierBoxCount = 1;
  float m_SoldierBoxMaxCount = 12;
  float m_PetBoxCount = 1;
  float m_PetBoxMaxCount = 20;
  float m_SoldierBoxCountOffset = 8;
  bool  m_IsSoldierBoxCountOffset = true;
  float m_MerchantBoxCount = 1;
  float m_MerchantBoxMaxCount = 10;
  float m_DarkMaxCount = 10;
  float m_ConquerBoxCount = 1;
  float m_ConquerBoxMaxCount = 180;
  EBuildingCastleModel m_CastleModel = EBuildingCastleModel::Classical;
  EBuildingViewModel m_ViewModelWall = EBuildingViewModel::ViewModel_1;
  bool m_IsMoved = false;
  bool m_IsMoveOnBuild = false;
  class IBuilding *n_CurrentSelectBuild = nullptr;
  Node *n_CurrentSelectTip = nullptr;
 // Ext::ScrollView *n_ViewScrollView = nullptr;
  Node *n_ContainerView = nullptr;
  Node *n_MainCityFarCsb = nullptr;
  Node *n_MainCityMiddleCsb = nullptr;
  ui::Layout *n_Touchlayer = nullptr;
  bool m_IsNeedRecover = false;
  bool m_IsOnMoveMode = false;
  Vec2 m_PreContainerOffset = Vec2::ZERO;
  Vec2 m_PreContainerOffsetTip = Vec2::ZERO;
  uint32 m_CurrentSelectMoveModeIndex = 0;
  uint32 m_AfterSelectMoveModeIndex = 0;
  uint32 m_CurrentSelectMoveModeType = 0;
  GVector<ui::Button *> n_CurrentMoveBtnArray;
  GVector<Node *> n_CurrentTopTipArray;
  bool m_IsOnCollectMode = false;
  bool m_HasCommunityCenterMsg = false;
  bool m_HasConquerGateMsg = false;
  bool m_IsBuildBtnEnable = true;
  bool m_IsShowDark = false;
  uint32 m_CurrentDayPeriod = 0;
  GVector<class IBuilding *> n_CollectBuilds;
  bool m_IsCfgNightOn = false; //SoraDConfigGet("Game:GameOptionsView:nightSwitch~bool")
  // local factionCtrl = SoraDGetCtrl("factionCtrl")
  // local cfg = factionCtrl:getFactionMainCityCfg()
  float m_ZoomMinOffsetX ;
  float m_ZoomMinOffsetY ;
 
  Size m_ViewScrollViewSize = Size::ZERO;

  ParallaxNode *n_BackPnode = nullptr;
  ParallaxNode *n_FrontPnode = nullptr;
  Node *n_BatchNodeOuterTiles = nullptr;
  Node *n_BatchNodeOuterBuilds = nullptr;
  Node *n_BatchNodeOuterBuildNpc = nullptr;
  Node *n_BatchNodeOuterBuildCommon = nullptr;
  Node *n_BatchNodeKipchaks = nullptr;
  GHashMap<GString, Node *> m_TblBatchNodesOuter;
  GHashMap<GString, Node *> m_TblBatchNodesTopTip;
  
  Node *n_BatchNodeTopTip = nullptr;
  Node *n_BatchNodeCityOthers = nullptr;
  Node *n_BatchNodeCityEffect = nullptr;
  Node *n_BatchNodeSoldierGuards = nullptr;
  Node *n_BatchNodeNpc = nullptr;
  Node *n_BatchNodeXiyiNpc = nullptr;
  Node *n_BatchNodeCollect = nullptr;
  Node *n_BatchNodeFightBullet = nullptr;
  Node *n_BatchNodeFightBuilds = nullptr;
  Node *n_BatchNodeFightBuildWalls = nullptr;
  Node *n_BatchNodeFightSoldiers = nullptr;
  Node *n_EffectFightNode = nullptr;
  ui::Layout *n_ButtonMilitaryInfo  = nullptr;
  ui::Layout *n_ButtonMerchante     = nullptr;
  ui::Layout *n_ButtonActivity      = nullptr;
  ui::Layout *n_ButtonEpicBattle    = nullptr;
  ui::Layout *n_ButtonMonument      = nullptr;
  ui::Layout *n_ButtonPyramidBattle = nullptr;
  ui::Layout *n_ButtonLion          = nullptr;
  ui::Layout *n_ButtonMaTou         = nullptr;
  ui::Layout *n_ButtonConquer       = nullptr;
  ui::Layout *n_ButtonBulletInBoard = nullptr;
  ui::Layout *n_ButtonLeisureCenter = nullptr;
  ui::Layout *n_ButtonHuoChuang     = nullptr;
  ui::Layout *n_ButtonPetCenter     = nullptr;
  ui::Layout *n_ButtonResurrectionHall = nullptr;
  ui::Layout *n_ButtonServiceCenter = nullptr;
  ui::Layout *n_BtnHuoChuang    = nullptr;
  ui::Layout *n_BtnPetCenter    = nullptr;
  void Ctor();
public:
  static MainCityCreate *Create(class MainCityView *p_MainCity); 
  
  static Vec2 GetTotalPos(Node * p_Node);
  static Vec2 CaculateOffset(float p_Ratio, Vec2 p_OriPos);
  void ViewOnClick(Ref* p_Ref, ui::Widget::TouchEventType p_Type);
  void CreateBatchNodes();
  void CreateFightBatchNodes();
  void InitBufferNodeArray();
  void InitBuild();
  void InitMainCityPos();
  void AddWaterFallEffect();
  void AddPetFlyBird();
  void InitCityGroupNode();
  void InitOriginBuild();
  void InitAfterCreate();
  // MainCityView Class
  void BuildButtonCallFun(ui::Widget *p_Build, Ref * p_Ref, ui::Widget::TouchEventType p_Touch){}
  void KipchaksButtonCallFun(ui::Widget *p_Build, Ref * p_Ref, ui::Widget::TouchEventType p_Touch){}
  void KipchaksUpdate(){}
  void OtherBuildButtonCallFun(ui::Widget *p_Build, Ref * p_Ref, ui::Widget::TouchEventType p_Touch){}
private:
  void CreateGroupNode(ECityTargetGroupID p_GroupId, int32 p_ZOrder);
  void ShowFirstEnter();

  void InitWithBuildData();
  void InitWithHuoChuangData();
  void InitMatouData();
  void CreateInnerCityBuilds();
  void CreateOuterCityBuilds();
  void DelayInitWithBuildData();
  bool InitPlayerLevelOffLine();
  void CheckCastleGift();
  void CheckEndlessTreasure();
  void CheckAllianceTreasure();
  void CheckFriend();
  void CheckEpicWar();
  void CheckPromoteArmy();
  void CheckMastery();
  IBuilding *CreateBuildByCfgId(EBuilding p_Building, RBuildingCfgItem p_BuildingConf); 
};