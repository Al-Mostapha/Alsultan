#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Include/IncludeGlobal.h"
#include "Base/Containers/HashMap.h"
#include "Module/UI/UIBaseView.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/UI/UICCSView.h"
#include "Module/Building/Building.Enum.h"
#include "CityScene.Create.h"
#include "CityFloor.h"

class UIMain;
class UIWorldResourceMap;
class UISystemNoticeView;
class UIIphoneXTop;
class UIIphoneXBottom;
class UIWorldMapFaceToDistance;

struct RShowMainCityView{
  bool isJudgeCurScene = false;
  EScene ViewType = EScene::None;
  bool isFromLogin = false;
  bool isFactionSwitch = false;
  RViewOtherData OtherData;
};

class MainCityView : public UIBasePanel, public MainCityCreate, public CityFloor
{
  GHashMap<GString, Node *> n_BufferNodeArray;
  CREATE_FUNC(MainCityView);
  CreateUIPanel(MainCityView);
  CreateUICCSView(MainCityView);
  RViewOtherData m_Param;
  UIBasePanel *_CurrentShowView = nullptr;
  UIMain *_MainUIView;
  UIWorldResourceMap *_WorldResourceMap = nullptr;
  UISystemNoticeView *_SystemNoticeView = nullptr;
  UIIphoneXTop *_IphoneXTop = nullptr;
  UIIphoneXBottom *_IphoneXBottom = nullptr;

  bool _IsComeFromBackGroud = false;
  bool _SwitcherViewIng = false;
  Scheduler *_ForeBackGroudTimer = nullptr;
  EScene _CurrentViewType = EScene::None;
  int32 _IsHideMainUICount = 0;
  int32 _IsHideCurrentSceneViewCount = false;
  UIBasePanel *_ShareBtn = nullptr;
  UIBasePanel *_VoiceBtn = nullptr;
  GVector<ui::ImageView *> _WarnningList;
  UIWorldMapFaceToDistance *_FaceToDistanceNode = nullptr;
  UIBasePanel *_LoginView = nullptr;

public:
  static MainCityView *Create(RViewOtherData p_Data);
  bool m_IsNeedFirstFight = false;
  bool m_IsFinishInit = false;
  Ext::ScrollView *n_ViewScrollView = nullptr;
  bool _IsBuildBtnEnable = false;
  Scheduler *m_TimeHandler = nullptr;
  Scheduler *m_TimeHandlerPerFrame = nullptr;
  bool m_IsLogin = false;
  void Ctor();
  void OnMessageListener();
  void PreLoadImages();
  bool IsNeedFirstFight();
  void AddToBufferNodeArrayByName(const char *p_Name, Node *p_Node) override;

  void DelBufferNodeByName(const char *p_Name){}
  void FinishLoadImages();
  void OnMessageListener_FinishLoadImage();
  void InitAfterCreate();
  void InitCelebrateGift(){
    //effectMainCityView.initCelebrateGift(self, target, data)
  }
  void MsgUpdateLion(){
    //mainCityMsg.msgUpdateLion(self, target, data)
  }
  void AddBuild(EBuildingIndex p_Index, EBuilding p_BuildingId){
    //mainCityFunctions.addBuild(self, buildBtnId, buildCfgId)
    
  }
  void UpdatePeriod();
  void LoadFixedBuilds();
  void SetMainCityEnabled(bool p_Enabled);
  void UpdateBuildTiles();
  void AutoUpdateViewScrollViewPos(float p_Delay = 0);
  void LoadSoldiers();
  void UpdateTime(float p_Time);
  void UpdateTimePerFrame(float p_Time);
  void RefreshCastleSkin(bool p_IsInit = false);
  Vec2 GetDefaultMainCityPos() override;

  void InitVisibleArea();
  void EnableShack();
  void DelBuildTile(Node *p_BuildingBtn);
  Node *GetBufferNodeByName(const char *p_NodeName) override;
  Vec2 GetContainerOffsetWhenPosTarget(); 
  float GetZoomScale(bool p_Force = false);
  Vec2 GetContainerOffsetWhenPosTarget(Node *p_Target, Vec2 p_WinPos, bool p_IgnoreCheck, bool p_Force); 
  Vec2 GetContainerOffsetWhenPosPoint(Vec2 p_Center, Vec2 p_WinPos, bool p_IgnoreCheck, bool p_Force); 
  Vec2 GetContainerOffsetWhenPosPoint(Vec2 p_Center, Vec2 p_WinPos, bool p_IgnoreCheck, bool p_Force, float p_Zoom); 
  void SetZoomScale(float p_Zoom, bool p_Anim = false, float p_Duration = 0.0f, bool p_CustomAnim = false);
  void RunContainerViewMove(Vec2 p_MoveToPos, float p_Duration = 0);
  void DisableMoveForDuration(float p_Duration = 0.5f);

  void InitLoginSuccess();
  void ReleaseMainView();
  void CleanPanelView(){}

  void GotoForeBackGroud(EventCustom *p_Event){}
  void ShowView(EventCustom *p_Event);
  void HideCurrentSceneViewAndMainUI(EventCustom *p_Event){}
  void CreatMainView(EventCustom *p_Event);
  void LoginFinsh(EventCustom *p_Event){}
  void ServerSocketLoginFail(EventCustom *p_Event){}
  void ServerSocketLoginAgain(EventCustom *p_Event){}
  void ServerSocketLoginAgain_Quick(EventCustom *p_Event){}
  void ServerSocketKickOut(EventCustom *p_Event){}
  void ShowServerMessageInfo(EventCustom *p_Event){}
  void MsgLordLevelUpView(EventCustom *p_Event){}
  void GameGuideStart(EventCustom *p_Event){}
  void ShowIphoneX(EventCustom *p_Event){}
  void LuaWillReload(EventCustom *p_Event){}
  void UpdateShareButton(EventCustom *p_Event){}
  void UpdateVoiceButton(EventCustom *p_Event){}
  void UpdateVoiceInviteButton(EventCustom *p_Event){}
  void UpdateCommonIconTip(EventCustom *p_Event){}
  void BuildQuequeCallback(EventCustom *p_Event){}
  void ServerGuideEnd(EventCustom *p_Event){}
  void UpdatePower(EventCustom *p_Event){}
  void UpdateEXP(EventCustom *p_Event){}


  private:
  void SwitcherView(RShowMainCityView *p_Data);

};