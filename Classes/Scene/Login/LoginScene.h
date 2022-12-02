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
#include "Scene/City/CityScene.View.h"
#include "Game/Guide/Guide.Ctrl.h"



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
  UIBasePanel *n_SystemNoticeView = nullptr;
  UIPanelBase *n_ShareBtn = nullptr;
  UIBasePanel *n_VoiceBtn = nullptr;
  UIPanelBase *n_MainUIView = nullptr;
  bool m_CommonTipRA = false;
  UIBaseView *n_CurrentShowView = nullptr;
  UIBasePanel *n_WorldResourceMap = nullptr;
  GVector<ui::ImageView *> n_WarnningList;
  UIWorldMapFaceToDistance *n_FaceToDistanceNode = nullptr;
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
  void CreateWorldResourceMap();
  void RemoveWorldResourceMap();
  void InitLoginSuccess();
  void OnMessageListener();
  UIBaseView *CurrentSceneShowView(){ return n_CurrentShowView; }
  
  static LoginScene *Create(){return LoginScene::create();}
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_GOTO_FOREG_BACK_GROUD", handler(self, self.gotoForeBackGroud))
  void GotoForeBackGroud(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_ONSHOW", handler(self, self.showView))
  void ShowView(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_HIDE_SCENEVIEW_MAINUI", handler(self, self.hideCurrentSceneViewAndMainUI))
  void HideCurrentSceneViewAndMainUI(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_LOGINSUCCESS", handler(self, self.creatMainView))
  void CreatMainView(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_LOGINFINSH", handler(self, self.loginFinsh))
  void LoginFinsh(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_LOGINFAIL", handler(self, self.serverSocketLoginFail))
  void ServerSocketLoginFail(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_LOGINAGAIN", handler(self, self.serverSocketLoginAgain))
  void ServerSocketLoginAgain(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_LOGINAGAIN_QUICK", handler(self, self.serverSocketLoginAgain_Quick))
  void ServerSocketLoginAgain_Quick(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_SOCKET_KICKOUT", handler(self, self.serverSocketKickOut))
  void ServerSocketKickOut(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_MESSAGEINFO", handler(self, self.showServerMessageInfo))
  void ShowServerMessageInfo(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_LORDINFO_UPGRADE_LEVEL", handler(self, self.msgLordLevelUpView))
  void MsgLordLevelUpView(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_SERVER_GUIDE_START_BY_STEP", handler(self, self.gameGuideStart))
  void GameGuideStart(EventCustom *p_Event){}
  // SoraDAddMessage(self, "MESSAGE_MAIN_SCENE_IPHONEX", handler(self, self.showIphoneX))
  void ShowIphoneX(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_LUA_WILL_RELOAD", handler(self, self.luaWillReload))
  void LuaWillReload(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_SERVER_OPTION_SHARE_BTN_UPDATE", handler(self, self.updateShareButton))
  void UpdateShareButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_VOICECHAT_SPEAKSTYLE_REFRESH", handler(self, self.updateVoiceButton))
  void UpdateVoiceButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_VOICECHAT_SERVER_NOTICE_INVITEMSG", handler(self, self.updateVoiceInviteButton))
  void UpdateVoiceInviteButton(EventCustom *p_Event);
  // SoraDAddMessage(self, "MESSAGE_MAINSCEN_COMMON_ICON_TIP", handler(self, self.updateCommonIconTip))
  void UpdateCommonIconTip(EventCustom *p_Event);
  void BuildQuequeCallback(EventCustom *p_Event);
  void ServerGuideEnd(EventCustom *p_Event);
  void LoginSettingRun(){}
  UIBaseView *CurrentMainUI();
};
