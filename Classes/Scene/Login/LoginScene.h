#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Include/IncludeUiBase.h"
#include "Include/IncludeGlobal.h"
#include "Include/IncludeCommon.h"
#include "Include/IncludeFunc.h"
#include "Module/UI/Common/UICommonItemTips.h"
#include "Scene/Main/MainScene.h"
#include "Module/UI/UIBasePanel.h"
#include "Module/World/WorldMap/WorldMap.Enum.h"
#include "Module/UI/Part/Common/UIIphoneXTop.h"
#include "Module/UI/Part/Common/UIIphoneXBottom.h"
#include "Module/UI/Part/World/WorldMap/UIWorldMapFaceToDistance.h"
#include "Module/World/WorldMap/View/UIWorldResourceMap.h"
#include "Scene/City/CityScene.View.h"
#include "Game/Guide/Guide.Ctrl.h"
#include "Base/Type/EventArg/Lord.EventArg.h"



class LoginScene : public MainScene
{
private:
  bool m_IsComeFromBackGroud = false;
  Scheduler *m_ForeBackGroudTimer = nullptr;
  EScene m_CurrentViewType = EScene::None;
  int32 m_IsHideMainUICount = 0;
  int32 m_IsHideCurrentSceneViewCount = false;
  UIIphoneXTop *n_IphoneXTop = nullptr;
  UIIphoneXBottom *n_IphoneXBottom = nullptr;
  // self.faceToDistanceNode = nil
  // self.gameGuideView = nil
  bool m_SwitcherViewIng = false;
  UIBasePanel *n_LoginView = nullptr;
  UIBaseView *n_SystemNoticeView = nullptr;
  UIPanelBase *n_ShareBtn = nullptr;
  UIBasePanel *n_VoiceBtn = nullptr;
  UIPanelBase *n_MainUIView = nullptr;
  bool m_CommonTipRA = false;
  UIBaseView *n_CurrentShowView = nullptr;
  UIWorldResourceMap *n_WorldResourceMap = nullptr;
  GVector<ui::ImageView *> n_WarnningList;
  UIWorldMapFaceToDistance *n_FaceToDistanceNode = nullptr;

  int32 m_OriPower = 0;
  CREATE_FUNC(LoginScene);
  void SwitcherView(RShowMainCityView *p_Data);
public:
  bool init() override;
  void onEnter() override;
  void onExit() override;
  static LoginScene* getCityScene();
  void StartGame();
  void InitData();
  void CreatePanelView();
  void CreateLoginView(EScene p_Type = EScene::None, EKingdomClassType p_Kingdom = EKingdomClassType::None);
  void InitGRoot();
  void CleanPanelView();
  void ReleaseMainView();
  bool RemoveLoginView();
  UIWorldResourceMap *CreateWorldResourceMap();
  void RemoveWorldResourceMap();
  void InitLoginSuccess();
  void OnMessageListener();
  UIBaseView *CurrentSceneShowView(){ return n_CurrentShowView; }
  
  static LoginScene *Create(){
    return LoginScene::create();
  }
  
  void GotoForeBackGroud(EventCustom *p_Event);
  void ShowView(EventCustom *p_Event);
  void HideCurrentSceneViewAndMainUI(EventCustom *p_Event);
  void CreatMainView(EventCustom *p_Event);
  void LoginFinsh(EventCustom *p_Event);
  void ServerSocketLoginFail(EventCustom *p_Event);
  void ServerSocketLoginAgain(EventCustom *p_Event);
  void ServerSocketLoginAgain_Quick(EventCustom *p_Event);
  void ServerSocketKickOut(EventCustom *p_Event){}
  void ShowServerMessageInfo(EventCustom *p_Event);
  void MsgLordLevelUpView(EventCustom *p_Event);
  void GameGuideStart(EventCustom *p_Event){}
  void ShowIphoneX(EventCustom *p_Event);
  void LuaWillReload(EventCustom *p_Event);
  void UpdateShareButton(EventCustom *p_Event);
  void UpdateVoiceButton(EventCustom *p_Event);
  void UpdateVoiceInviteButton(EventCustom *p_Event);
  void UpdateCommonIconTip(EventCustom *p_Event);
  void BuildQuequeCallback(EventCustom *p_Event);
  void ServerGuideEnd(EventCustom *p_Event);
  void UpdatePower(EventCustom *p_Event);
  void UpdateEXP(EventCustom *p_Event);
  void LoginSettingRun(){}
  UIBaseView *CurrentMainUI();
  GVector<UIBaseView *> GetCheckViewList();
  bool RemoveLoginView();
  void ListenerKeyPad();
};
