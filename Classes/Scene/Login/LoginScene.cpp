#include "LoginScene.h"
#include "Base/Common/Fabric.h"
#include "Base/Common/Cach/InstanceCach.Mgr.h"
#include "Base/Device/Shack.Module.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Effect/Effect.Enum.h"
#include "Module/Effect/Include.h"
#include "Module/Item/Include.h"
#include "Module/Player/Player.Top.h"
#include "Module/UI/Common/Button/UICommonShareButton.h"
#include "Module/UI/Common/UICommonDressPreview.h"
#include "Module/UI/Common/UICommonItemShowBox.h"
#include "Module/UI/EventCenter/EventTemplate/PrinceGift/UIPrinceGiftBuffPreview.h"
#include "Module/UI/UIManger.h"
#include "Module/UI/View/UILogin.View.h"
#include "Module/UI/MainUI/UIMain.h"
#include "Module/World/WorldMap/WorldMap.Def.h"
#include "Module/World/WorldMap/WorldMap.Util.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldWar/AtlantisWar/AtlantisWar.Util.h"
#include "Module/Common/Military/MilitaryRank.Ctrl.h"
#include "Module/UI/Panel/Notice/SystemNotice/UISystemNotice.View.h"



// on "init" you need to initialize your instance
bool LoginScene::init() {
  if (!Scene::init()) {
    return false;
  }
  return true;
}

void LoginScene::onEnter() {
  Scene::onEnter();
  if (SDKManager::Get()->IsBeta() || SDKManager::Get()->IsGameService()) {
    // PocoManager::Get()->InitServer(15004);
  }
  auto l_DeviceDPI = Device::getDPI();
  cocos2d::log("deviceDPI: %f", l_DeviceDPI);
  GBase::DGetDefaultLanguage();
  StartGame();
  OnMessageListener();
  // if device.platform == "mac" then
  //   self:listenerKeyPad_imgui()
  // end
}

void LoginScene::onExit() {
  Scene::onExit();
  GBase::DRemoveMessageByTarget(this);
}

void LoginScene::OnMessageListener(){
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_GOTO_FOREG_BACK_GROUD", CC_CALLBACK_1(LoginScene::GotoForeBackGroud, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_ONSHOW", CC_CALLBACK_1(LoginScene::ShowView, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_HIDE_SCENEVIEW_MAINUI", CC_CALLBACK_1(LoginScene::HideCurrentSceneViewAndMainUI, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LOGINSUCCESS", CC_CALLBACK_1(LoginScene::CreatMainView, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LOGINFINSH", CC_CALLBACK_1(LoginScene::LoginFinsh, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LOGINFAIL", CC_CALLBACK_1(LoginScene::ServerSocketLoginFail, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LOGINAGAIN", CC_CALLBACK_1(LoginScene::ServerSocketLoginAgain, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LOGINAGAIN_QUICK", CC_CALLBACK_1(LoginScene::ServerSocketLoginAgain_Quick, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_SOCKET_KICKOUT", CC_CALLBACK_1(LoginScene::ServerSocketKickOut, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_MESSAGEINFO", CC_CALLBACK_1(LoginScene::ShowServerMessageInfo, this));
  GBase::DAddMessage(this, "MESSAGE_LORDINFO_UPGRADE_LEVEL", CC_CALLBACK_1(LoginScene::MsgLordLevelUpView, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_GUIDE_START_BY_STEP", CC_CALLBACK_1(LoginScene::GameGuideStart, this));
  GBase::DAddMessage(this, "MESSAGE_MAIN_SCENE_IPHONEX", CC_CALLBACK_1(LoginScene::ShowIphoneX, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LUA_WILL_RELOAD", CC_CALLBACK_1(LoginScene::LuaWillReload, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_OPTION_SHARE_BTN_UPDATE", CC_CALLBACK_1(LoginScene::UpdateShareButton, this));
  GBase::DAddMessage(this, "MESSAGE_MAINCITYVIEW_BUILD_QUEQUE_CALLBACK", CC_CALLBACK_1(LoginScene::BuildQuequeCallback, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_COMMON_ICON_TIP", CC_CALLBACK_1(LoginScene::UpdateCommonIconTip, this));
  GBase::DAddMessage(this, "MESSAGE_VOICECHAT_SPEAKSTYLE_REFRESH", CC_CALLBACK_1(LoginScene::UpdateVoiceButton, this));
  GBase::DAddMessage(this, "MESSAGE_VOICECHAT_SERVER_NOTICE_INVITEMSG", CC_CALLBACK_1(LoginScene::UpdateVoiceInviteButton, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_GUIDE_END", CC_CALLBACK_1(LoginScene::ServerGuideEnd, this));

}

void LoginScene::BuildQuequeCallback(EventCustom *p_Event) {
  if(!p_Event) 
    return;
  auto l_Data = p_Event->getUserData();
  if(!l_Data) 
    return;
  auto l_BuildingId = static_cast<EBuilding *>(l_Data);
  if(!l_BuildingId) 
    return;
  if(*l_BuildingId == EBuilding::Castle)
    UpdateShareButton(nullptr);
}


void LoginScene::ServerGuideEnd(EventCustom *p_Event){
  //   self.gameGuideView = nil
  //   if data.needUpdate then
  //     local gametop = gModuleMgr.getObject("gametop")
  //     local guideCtrl = gametop.playertop_:getModule("guideCtrl")
  //     local step = guideCtrl:updateNewGuide()
  //     print("step=========", step)
  //     if not step then
  //       local newPlayerTaskCtrl = gametop.playertop_:getModule("newPlayerTaskCtrl")
  //       if newPlayerTaskCtrl:getCurChapterID() > 4103000 then
  //         SoraDSendMessage({
  //           msg = "MESSAGE_MAIN_AGREEMENT_BOX"
  //         })
  //       end
  //       local remainsTeamCtrl = gametop.playertop_:getModule("remainsTeamCtrl")
  //       if remainsTeamCtrl:isHasInvitedInfo() then
  //         SoraDSendMessage({
  //           msg = "MESSAGE_SERVER_REMAINS_TEAM_INVITED_INFO"
  //         })
  //       end
  //       SoraDSendMessage({
  //         msg = "MESSAGE_SERVER_PYRAMIDBATTLE_GUIDECLOSEPOPEXPLAIN"
  //       })
  //     end
  //   end
}

void LoginScene::StartGame() { 
  InitData(); 
}

void LoginScene::InitData() {
  CreatePanelView();
  CreateLoginView();
}

void LoginScene::LoginFinsh(EventCustom *p_Event){
  GBase::DCloseLoading(nullptr);
}

void LoginScene::CleanPanelView() {
  UIManger::Get()->CloseAllUI();
  for (auto l_OneChild : n_PanelView->getChildren()) {
    if (l_OneChild->getName() != "commonSystemMsgBox") l_OneChild->removeFromParent();
  }
}

void LoginScene::CreatePanelView() {
  // local function initGRoot(groot, zorder)
  //   if groot then
  //     groot:removeFromParent()
  //   end
  //   groot = fgui.GRoot:create(self, zorder)
  //   groot:retain()
  //   groot:setName("GRoot")
  //   local container = groot:getContainer()
  //   container:setName("GRootDisplayObject")
  //   container:setPosition(0, 0)
  //   return groot
  // end
  // self.groot_normal = initGRoot(self.groot_normal, 5)
  // self.panelView = self.groot_normal:getContainer()
  if (n_PanelView) n_PanelView->removeFromParent();
  n_PanelView = ui::Layout::create();
  Director::getInstance()->getRunningScene()->addChild(n_PanelView, 5);
}



void LoginScene::CreateLoginView(EScene p_Type, EKingdomClassType p_Kingdom) {
  if (p_Type == EScene::None) p_Type = EScene::City;
  stopAllActions();
  runAction(
    Sequence::create(
      DelayTime::create(0.0167),
      CallFunc::create([=]() {
        GAudioEngine::Get()->Init();
        LoginSettingRun();
        GAudioEngine::Get()->StopMusic();
        GAudioEngine::Get()->PlayMusic("loading", true);
        GAudioEngine::Get()->SetMusicVolume(0.5f);
      }),
      nullptr));
  if (n_LoginView) {
    n_LoginView->removeFromParent();
    n_LoginView = nullptr;
  }
  auto l_LoginView = UILoginView::Create();
  l_LoginView->SetKingdomClass(p_Kingdom);
  l_LoginView->SetShowViewType(p_Type);

  addChild(l_LoginView, 4);
  n_LoginView = l_LoginView;
  GBase::DCloseSwitcherView();
  ShackModule::Get()->Unload();
  ReleaseMainView();
}

bool LoginScene::RemoveLoginView() {
  auto l_Ret = false;
  if (n_LoginView) {
    n_LoginView->removeFromParent();
    n_LoginView = nullptr;
    l_Ret = true;
    if (n_IphoneXTop) {
      n_IphoneXTop->setVisible(GDevice::Get()->IsIphoneXMode());
    }
    if (n_IphoneXBottom) {
      n_IphoneXBottom->setVisible(GDevice::Get()->IsIphoneXMode());
    }
  }
  return l_Ret;
}

void LoginScene::LuaWillReload(EventCustom *p_Event) {
  // VoiceChatSDKManager:getInstance():leaveChannel()
}

void LoginScene::UpdateShareButton(EventCustom* p_Event) {
  if (GBase::CommonCheck::Get()->ScreenShoot)
    if (n_ShareBtn) n_ShareBtn->setVisible(false);
  if (p_Event && n_ShareBtn && p_Event->getUserData() != nullptr) {
    n_ShareBtn->setVisible((bool)p_Event->getUserData());
  } else {
    auto l_IsShow = GBase::DConfigGet<int32>("Game:GameOptionsView:showShareBtn~integer", true);
    if (l_IsShow == 0) {
      if (CityCtrl::Get()->GetBuildingMaxLv(EBuilding::Castle) >= 10) {
        GBase::DConfigSet<int32>("Game:GameOptionsView:showShareBtn~integer", 1, true);
        l_IsShow = 1;
      }
    }
    if (l_IsShow == 1 && n_ShareBtn == nullptr) {
      n_ShareBtn = UICommonShareButton::create();
      n_ShareBtn->InitPanel();
      n_ShareBtn->setPosition(Vec2(0, 0));
      addChild(n_ShareBtn, 8);
    } else if (l_IsShow != 1 && n_ShareBtn) {
      n_ShareBtn->removeFromParent();
      n_ShareBtn = nullptr;
    }
  }
}

void LoginScene::UpdateCommonIconTip(EventCustom *p_Event) {
  if(!p_Event || !p_Event->getUserData()) return;
  auto p_IconData = static_cast<RCommonIconData *>(p_Event->getUserData());
  if(!p_IconData) return;
  auto l_Id = p_IconData->id;
  auto l_Num = p_IconData->num;
  auto l_Pos = p_IconData->Pos;
  auto l_CustomName = p_IconData->CustomName;
  auto l_CustomTip = p_IconData->CustomTip;
  auto l_CommonTip = Director::getInstance()->getRunningScene()->getChildByName<UICommonItemTips*>("commonItemTips");
  if (!l_Id && !l_CustomTip)
    if (l_CommonTip) l_CommonTip->setVisible(false);

  //   pos.y = fgui.GRoot:getInstance():getSize().height - pos.y
  //   local ret, show, isShow = backpackltCtrl:getRandomGiftShowItems(id)
  auto l_Ret = ItemCtrl::Get()->GetRandomGiftShowItems(l_Id);
  if (l_Ret.size() > 0 && ItemCtrl::Get()->HasDesc(l_Id)) {
    auto l_Panel = UICommonItemShowBox::Create();
    l_Panel->InitPanel();
    l_Panel->InitData(l_Id);
    l_Panel->Show();
    return;
  }
  if (ItemCtrl::Get()->IsSkinShow(l_Id)) {
    auto l_Panel = UICommonDressPreview::Create();
    l_Panel->InitPanel();
    l_Panel->InitData(l_Id);
    l_Panel->Show();
    return;
  }
  if (l_Id == static_cast<int32>(EEffect::LEV_29_INSTANT_BUILD_SPEED_BOOST)) {
    auto l_Panel = UIPrinceGiftBuffPreview::Create();
    l_Panel->InitPanel();
    l_Panel->Show();
    return;
  }

  if (l_CommonTip && m_CommonTipRA != GBase::DFIsRA()) {
    l_CommonTip->removeFromParent();
    l_CommonTip = nullptr;
  }
  if (!l_CommonTip) {
    m_CommonTipRA = GBase::DFIsRA();
    l_CommonTip = UICommonItemTips::Create();
    l_CommonTip->InitPanel();
    l_CommonTip->setName("commonItemTips");
    Director::getInstance()->getRunningScene()->addChild(l_CommonTip, 9999);
  } else {
    l_CommonTip->setVisible(true);
  }

  auto l_SType = GServiceFunction::Get()->GetIDType(l_Id);
  if (l_CustomTip) {
    l_CommonTip->CustomData(l_CustomName.c_str());
  } else if (l_SType != EIDType::Item && EffectDecRead::Get()->IsBuff(l_Id)) {
    l_CommonTip->SetBuffInfo(l_Id, l_Num);
  } else {
    l_CommonTip->InitData(l_Id, l_Num);
  }
  auto l_Height = 0;
  auto l_Parent = GRoot::Get();

  //   if parent then
  if (l_Parent) {
    l_Height = l_Parent->GetSize().height;
    auto l_ContainerSize = l_Parent->GetSize();
    auto l_Size = l_CommonTip->GetBgSize();
    if (GBase::DFIsRA()) {
      l_Pos.x += l_Size.width / 2;
      if (0 > l_Pos.x - l_Size.width) {
        l_Pos.x = l_Size.width;
      } else if (l_Pos.x > l_ContainerSize.width) {
        l_Pos.x = l_ContainerSize.width;
      }
    } else {
      l_Pos.x -= l_Size.width / 2;
      if (0 > l_Pos.x) {
        l_Pos.x = 0;
      } else if (l_Pos.x + l_Size.width > l_ContainerSize.width) {
        l_Pos.x = l_ContainerSize.width - l_Size.width;
      }
    }
    //     pos.y = math.max(math.min(pos.y + size.height, height), size.height)
    auto l_MinH = std::min(l_Pos.y + l_Size.height, (float)l_Height);
    l_Pos.y = std::max(l_MinH, l_Size.height);
  }
  l_CommonTip->setPosition(l_Pos);
}

void LoginScene::UpdateVoiceButton(EventCustom *p_Event){
  // if VoiceChatSDKManager:getInstance().voiceState == gVoiceState.inRoom then
  //   if not self.voiceBtn then
  //     self.voiceBtn = SoraDCreatePanel("voiceChatFloatButton")
  //     self.voiceBtn:setPosition(0, 0)
  //     self:addChild(self.voiceBtn, 9)
  //   end
  // elseif self.voiceBtn then
  //   self.voiceBtn:removeFromParent()
  //   self.voiceBtn = nil
  // end
}

void LoginScene::UpdateVoiceInviteButton(EventCustom *p_Event){
  // local info = redata.redata
  // local voiceInviteBtn = SoraDCreatePanel("voiceChatInviteButton")
  // voiceInviteBtn:initData(info)
  // voiceInviteBtn:setPosition(50, display.height / 2)
  // self:addChild(voiceInviteBtn, 10)
}

void LoginScene::ShowIphoneX(EventCustom *p_Event){
  // if data.isShow then
  //   if self.iphoneXTop then
  //     self.iphoneXTop:setVisible(device.isIphoneXMode())
  //   end
  //   if self.iphoneXBottom then
  //     self.iphoneXBottom:setVisible(device.isIphoneXMode())
  //   end
  // else
  //   if self.iphoneXTop then
  //     self.iphoneXTop:setVisible(false)
  //   end
  //   if self.iphoneXBottom then
  //     self.iphoneXBottom:setVisible(false)
  //   end
  // end
}

void LoginScene::CreateWorldResourceMap(){
  // if self.worldResourceMap then
  //   self.worldResourceMap:removeFromParent(true)
  //   self.worldResourceMap = nil
  // end
  // self.worldResourceMap = include("worldResourceMap").new()
  // self.worldResourceMap:setName("worldResourceMap")
  // self:addChild(self.worldResourceMap, 3)
  // return self.worldResourceMap
}

void LoginScene::CreatMainView(EventCustom *p_Event){
  InitLoginSuccess();
  ReleaseMainView();
  m_CurrentShowView = nullptr;
  // userSDKManager.timeInfo.t_mainui.tbegin = SoraDGetSocketTime()
  n_MainUIView = UIMain::Create();
  n_MainUIView->InitPanel();
  n_MainUIView->setSwallowTouches(false);
  addChild(n_MainUIView, 2);
  // userSDKManager.timeInfo.t_mainui.tend = SoraDGetSocketTime()
  n_WorldResourceMap = nullptr;
  n_SystemNoticeView = UISystemNoticeView::Create();
  addChild(n_SystemNoticeView, 6);
  if(n_IphoneXTop){
    n_IphoneXTop->removeFromParent();
    n_IphoneXTop = nullptr;
  }
  n_IphoneXTop = UIIphoneXTop::Create();
  n_IphoneXTop->setAnchorPoint(Vec2(0.5, 1));
  n_IphoneXTop->setVisible(false);
  auto l_Display = GDisplay::Get();
  n_IphoneXTop->setPosition(Vec2(l_Display->cx, l_Display->height + l_Display->iPhoneXOffset));
  addChild(n_IphoneXTop, 6);
  if(n_IphoneXBottom) n_IphoneXBottom->removeFromParent();
  n_IphoneXBottom = UIIphoneXBottom::Create();
  n_IphoneXBottom->setAnchorPoint(Vec2(0.5, 0));
  n_IphoneXBottom->setPosition(Vec2(l_Display->cx, 0));
  n_IphoneXBottom->setVisible(false);
  addChild(n_IphoneXBottom, 6);
  if(GDevice::Get()->IsIphoneXMode()){
    // if device.isIpadMode() then
    //   self.padIndex = 1
    //   self.padSpirteL = display.newSprite("#frame_ipad_biankuang_L.png")
    //   self.padSpirteL:setPosition(32, 0)
    //   self.padSpirteL:setAnchorPoint(cc.p(0.5, 0))
    //   self:addChild(self.padSpirteL, 6)
    //   self.padSpirteR = display.newSprite("#frame_ipad_biankuang_R.png")
    //   self.padSpirteR:setPosition(display.realSize.width - 32, 0)
    //   self.padSpirteR:setAnchorPoint(cc.p(0.5, 0))
    //   self:addChild(self.padSpirteR, 6)
    // end
  }
  UpdateShareButton(nullptr);
  UpdateVoiceButton(nullptr); 
  auto l_ShowViewType = EScene::City;
  if(p_Event->getUserData())
    l_ShowViewType = *(EScene*)p_Event->getUserData();
  auto l_Data = std::make_unique<RShowView>();
  l_Data->isFromLogin = true;
  l_Data->ViewType = l_ShowViewType;
  GBase::DSendMessage("MESSAGE_MAINSCEN_ONSHOW", l_Data.get());
}


void LoginScene::ReleaseMainView(){
  // userSDKManager.need2CallBackEventList = {}
  m_IsHideMainUICount = 0;
  m_IsHideCurrentSceneViewCount = 0;
  GBase::DCloseLoading(this);
  if (m_CurrentShowView) {
    m_CurrentShowView->removeFromParent();
    m_CurrentShowView = nullptr;
  }
  if (n_MainUIView) {
    n_MainUIView->removeFromParent();
    n_MainUIView = nullptr;
  }
  if(UIManger::Get()->IsShow("mainUI")){
    UIManger::Get()->Close("mainUI");
  }
  if(n_WorldResourceMap){
    n_WorldResourceMap->removeFromParent();
    n_WorldResourceMap = nullptr;
  }
  CleanPanelView();
  if(n_IphoneXTop){
    n_IphoneXTop->removeFromParent();
    n_IphoneXTop = nullptr;
  }
  if(n_IphoneXBottom){
    n_IphoneXBottom->removeFromParent();
    n_IphoneXBottom = nullptr;
  }
  if(n_ShareBtn){
    n_ShareBtn->removeFromParent();
    n_ShareBtn = nullptr;
  }
  if(n_VoiceBtn){
    n_VoiceBtn->removeFromParent();
    n_VoiceBtn = nullptr;
  }
  if(n_SystemNoticeView){
    n_SystemNoticeView->removeFromParent();
    n_SystemNoticeView = nullptr;
  }
  InstanceCachManger::Get()->ClearCache();
  for(auto l_Warnning : n_WarnningList){
    l_Warnning->removeFromParent();
  }
  n_WarnningList.clear();
  GBase::DClearItemAwards();
}

void LoginScene::SwitcherView(RShowView * p_Data){
  if(!p_Data) return;
  if(m_CurrentShowView){
    if(m_CurrentViewType == p_Data->ViewType)
      m_CurrentShowView->m_Panel->m_FreeImagesOnExit = false;
    if(p_Data->isFactionSwitch)
      m_CurrentShowView->m_Panel->m_FreeImagesOnExit = true;
    m_CurrentShowView->removeFromParentAndCleanup(true);
    m_CurrentShowView = nullptr;
  //     criAdxAux.freeAudio()
  //     imageManager.switchScene()
  }
  if(p_Data->OtherData.kingdomID)
    WorldMapDefine::Get()->CurrentMapKindomID = p_Data->OtherData.kingdomID;
  else
    WorldMapDefine::Get()->CurrentMapKindomID = PlayerTop::Get()->GetMapID();
  AtlantisWarUtil::Get()->RemoveWorldMapAtlantisWarInfo();
  //   local showView
  //   AudioEngine.stopMusic()
  if(p_Data->ViewType == EScene::City){
    if(n_FaceToDistanceNode)
      n_FaceToDistanceNode->setVisible(false);
    if(n_LoginView){
    //   userSDKManager.logEvent(gSDKDef.TDonEvent.star_enter_city, {})
    //   local isSupport = gl.isSupportsASTC()
    //   userSDKManager.logEvent(gSDKDef.TDonEvent.check_astc_support, {support = isSupport})
    //   userSDKManager.getAdvertisingStrategy()
    }
    // showView = include("mainCityView").new(otherData)

    // showView:setName("mainCityView")
    // local guideCtrl = SoraDGetCtrl("guideCtrl")
    // if guideCtrl:getCurMainCityGuideStep() ~= nil then
    //   AudioEngine.playMusic(getAudioFileNameByPlatform("worldMap", "BGM"), true)
    // else
    //   AudioEngine.playMusic(getAudioFileNameByPlatform("mainCity", "BGM"), true)
    // end
  }
  //   if data.viewType == VIEW_TYPE_CITY then

  //   elseif data.viewType == VIEW_TYPE_MAP then
  //     showView = include("worldMapViewFactory").new(otherData)
  //     showView:setName("worldMapView")
  //     AudioEngine.playMusic(getAudioFileNameByPlatform("worldMap", "BGM"), true)
  //   end
  //   self:addChild(showView, 1)
  //   self.currentViewType = data.viewType
  //   self.currentShowView = showView
  //   self.switcherViewIng = false
  //   if self:currentMainUI() then
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINSCEN_MAINUITOP_EVENT_REFRESH"
  //     })
  //   end
}

void LoginScene::ShowView(EventCustom *p_Event){
  // local isJudgeCurScene = data.isJudgeCurScene or false
  if(!p_Event->getUserData()) return;
  auto l_Data = static_cast<RShowView *>(p_Event->getUserData());
  if(l_Data->isJudgeCurScene && l_Data->ViewType == m_CurrentViewType) return;
  if(l_Data->ViewType == EScene::None) return;
  // worldMapDefine.currentMapKindomID = nil
  WorldMapDefine::Get()->CurrentMapKindomID = 0;
  // local function switcherView()

  // end
  // util.resetCSDCatch()
  // if isFromLogin then
  //   switcherView()
  //   if data.viewType == VIEW_TYPE_MAP then
  //     local cityBuildFunction = include("cityBuildFunction")
  //     cityBuildFunction:setIsFirstLogin(false)
  //   end
  // elseif not self.switcherViewIng then
  //   self.switcherViewIng = true
  //   SoraDShowSwitcherView(data.otherData)
  //   transition.execute(self, nil, {
  //     delay = 1,
  //     onComplete = function()
  //       switcherView()
  //     end
  //   })
  // else
  //   print("\230\173\163\229\156\168\229\136\135\230\141\162\229\156\186\230\153\175\228\184\173ing")
  //   self:stopAllActions()
  //   switcherView()
  // end
}

void LoginScene::InitLoginSuccess(){
  WorldMapDef::Get()->DoSwitchToAnchor();
  GFabric::Get()->ReportDeviceInfoChange();
  WorldMapUtil::Get()->ResetConfig();
  MilitaryRankCtrl::Get()->SendMarshalLoginTip();
}