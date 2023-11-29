#include "LoginScene.h"
#include "Base/Type/XMap.h"
#include "Base/Common/Cach/InstanceCach.Mgr.h"
#include "Base/Common/Fabric.h"
#include "Base/Common/Common.Msg.h"
#include "Base/Containers/Pair.h"
#include "Base/Device/Shack.Module.h"
#include "Base/Type/EventArg/Login.EvtArg.h"
#include "Module/Module.Mgr.h"
#include "Module/Army/Army.Read.h"
#include "Module/Building/Building.Func.h"
#include "Module/Building/Building.Read.h"
#include "Module/City/City.Ctrl.h"
#include "Module/CityResource/Resource.Read.h"
#include "Module/Common/Military/MilitaryRank.Ctrl.h"
#include "Module/Effect/Effect.Enum.h"
#include "Module/Effect/Include.h"
#include "Module/Equip/Equip.Read.h"
#include "Module/Guild/Alliance.Read.h"
#include "Module/Item/Include.h"
#include "Module/Item/Item.Read.h"
#include "Module/Player/Chapter/PlayerTask.Ctrl.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/Player/Player.Top.h"
#include "Module/Science/Science.Read.h"
#include "Module/UI/Common/Button/UICommonShareButton.h"
#include "Module/UI/Common/UICommonDressPreview.h"
#include "Module/UI/Common/UICommonItemShowBox.h"
#include "Module/UI/EventCenter/EventTemplate/PrinceGift/UIPrinceGiftBuffPreview.h"
#include "Module/UI/MainUI/UIMain.h"
#include "Module/UI/Panel/Login/UICommonMaintainView.h"
#include "Module/UI/Panel/Notice/SystemNotice/UISystemNotice.View.h"
#include "Module/UI/UIManger.h"
#include "Module/UI/View/UILogin.View.h"
#include "Module/World/WorldMap/View/WorldMap.ViewFactory.h"
#include "Module/World/WorldMap/WorldMap.Def.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/World/WorldMap/WorldMap.Util.h"
#include "Module/World/WorldWar/AtlantisWar/AtlantisWar.Util.h"
#include "Game/Init/Game.Top.h"


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

void LoginScene::OnMessageListener() {
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
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_COMMON_ICON_TIP", CC_CALLBACK_1(LoginScene::UpdateCommonIconTip, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_POWER_UPDATE", CC_CALLBACK_1(LoginScene::UpdatePower, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_EXP_UPDATE", CC_CALLBACK_1(LoginScene::UpdateEXP, this));
}

void LoginScene::BuildQuequeCallback(EventCustom* p_Event) {
  if (!p_Event) return;
  auto l_Data = p_Event->getUserData();
  if (!l_Data) return;
  auto l_BuildingId = static_cast<EBuilding*>(l_Data);
  if (!l_BuildingId) return;
  if (*l_BuildingId == EBuilding::Castle) UpdateShareButton(nullptr);
}

void LoginScene::ServerGuideEnd(EventCustom* p_Event) {
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

void LoginScene::StartGame() { InitData(); }

void LoginScene::InitData() {
  GModuleMgr::Get()->Init();
  GModuleMgr::Get()->GetGameTop()->StartGame();
  CreatePanelView();
  CreateLoginView();
}

void LoginScene::LoginFinsh(EventCustom* p_Event) { GBase::DCloseLoading(nullptr); }

void LoginScene::CleanPanelView() {
  UIManger::Get()->CloseAllUI();
  for (auto l_OneChild : _PanelView->getChildren()) {
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
  if (_PanelView) _PanelView->removeFromParent();
  _PanelView = ui::Layout::create();
  Director::getInstance()->getRunningScene()->addChild(_PanelView, 5);
}

void LoginScene::CreateLoginView(EScene p_Type, EKingdomClassType p_Kingdom) {
  if (p_Type == EScene::None) p_Type = EScene::City;
  stopAllActions();
  runAction(
    Sequence::create(
      DelayTime::create(0.0167f),
        CallFunc::create([=]() {
          GAudioEngine::Get()->Init();
          LoginSettingRun();
          GAudioEngine::Get()->StopMusic();
          GAudioEngine::Get()->PlayMusic("loading", true);
          GAudioEngine::Get()->SetMusicVolume(0.5f);
        }),
      nullptr
    )
  );
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

void LoginScene::LuaWillReload(EventCustom* p_Event) {
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

void LoginScene::UpdatePower(EventCustom* p_Event) {
  if (!p_Event) return;
  if (!p_Event->getUserData()) return;
  auto l_Power = static_cast<RUpdatePowerEvtArg*>(p_Event->getUserData());
  m_OriPower = l_Power->OriPower;
  if (GuideCtrl::Get()->GetCurMainCityGuideStep() != nullptr && l_Power->CurPower - m_OriPower > 500) return;
  GBase::DDelayCallOnce(
          "mainUI_lordPowerChange",
          [=](float p_Delta) {
            GBase::DSendMessage("MESSAGE_MAINUI_POWER_UPDATE");
            GBase::DShowPowerChange(*l_Power, false);
            std::unique_ptr<bool> l_ShowPush(new bool(true));
            // advertiseCollect.TriggerEvent(gSDKDef.TDonEvent.advertise_fight_point, l_Power->CurPower);
            GBase::DSendMessage("MESSAGE_MAIN_AGREEMENT_BOX", l_ShowPush.get());
            m_OriPower = 0;
          },
          0.8f);
}

void LoginScene::UpdateEXP(EventCustom* p_Event) {
  if (!p_Event) return;
  if (!p_Event->getUserData()) return;

  GBase::DDelayCallOnce(
          "mainUI_lordEXPChange", [=](float p_Delta) { GBase::DShowEXPChange(*static_cast<int32*>(p_Event->getUserData())); }, 0.5f);
}

void LoginScene::UpdateCommonIconTip(EventCustom* p_Event) {
  if (!p_Event || !p_Event->getUserData()) return;
  auto p_IconData = static_cast<RCommonIconData*>(p_Event->getUserData());
  if (!p_IconData) return;
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

void LoginScene::UpdateVoiceButton(EventCustom* p_Event) {
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

void LoginScene::UpdateVoiceInviteButton(EventCustom* p_Event) {
  // local info = redata.redata
  // local voiceInviteBtn = SoraDCreatePanel("voiceChatInviteButton")
  // voiceInviteBtn:initData(info)
  // voiceInviteBtn:setPosition(50, display.height / 2)
  // self:addChild(voiceInviteBtn, 10)
}

void LoginScene::ShowIphoneX(EventCustom* p_Event) {
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

UIWorldResourceMap* LoginScene::CreateWorldResourceMap() {
  if (n_WorldResourceMap) {
    n_WorldResourceMap->removeFromParent();
    n_WorldResourceMap = nullptr;
  }
  n_WorldResourceMap = UIWorldResourceMap::Create();
  n_WorldResourceMap->setName("worldResourceMap");
  addChild(n_WorldResourceMap, 3);
  return n_WorldResourceMap;
}

void LoginScene::CreatMainView(EventCustom* p_Event) {
  InitLoginSuccess();
  ReleaseMainView();
  n_CurrentShowView = nullptr;
  // userSDKManager.timeInfo.t_mainui.tbegin = SoraDGetSocketTime()
  n_MainUIView = UIMain::Create();
  n_MainUIView->setSwallowTouches(false);
  addChild(n_MainUIView, 2);
  // userSDKManager.timeInfo.t_mainui.tend = SoraDGetSocketTime()
  n_WorldResourceMap = nullptr;
  n_SystemNoticeView = UISystemNoticeView::Create();
  addChild(n_SystemNoticeView, 6);
  if (n_IphoneXTop) {
    n_IphoneXTop->removeFromParent();
    n_IphoneXTop = nullptr;
  }
  n_IphoneXTop = UIIphoneXTop::Create();
  n_IphoneXTop->setAnchorPoint(Vec2(0.5, 1));
  n_IphoneXTop->setVisible(false);
  auto l_Display = GDisplay::Get();
  n_IphoneXTop->setPosition(Vec2(l_Display->cx, l_Display->height + l_Display->iPhoneXOffset));
  addChild(n_IphoneXTop, 6);
  if (n_IphoneXBottom) n_IphoneXBottom->removeFromParent();
  n_IphoneXBottom = UIIphoneXBottom::Create();
  n_IphoneXBottom->setAnchorPoint(Vec2(0.5, 0));
  n_IphoneXBottom->setPosition(Vec2(l_Display->cx, 0));
  n_IphoneXBottom->setVisible(false);
  addChild(n_IphoneXBottom, 6);
  if (GDevice::Get()->IsIphoneXMode()) {
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
  if (p_Event->getUserData()) l_ShowViewType = *(EScene*)p_Event->getUserData();
  static RShowMainCityView l_Data;
  l_Data.isFromLogin = true;
  l_Data.ViewType = l_ShowViewType;
  GBase::DSendMessage("MESSAGE_MAINSCEN_ONSHOW", &l_Data);
}

void LoginScene::ReleaseMainView() {
  // userSDKManager.need2CallBackEventList = {}
  m_IsHideMainUICount = 0;
  m_IsHideCurrentSceneViewCount = 0;
  GBase::DCloseLoading(this);
  if (n_CurrentShowView) {
    n_CurrentShowView->removeFromParent();
    n_CurrentShowView = nullptr;
  }
  if (n_MainUIView) {
    n_MainUIView->removeFromParent();
    n_MainUIView = nullptr;
  }
  if (UIManger::Get()->IsShow("mainUI")) {
    UIManger::Get()->Close("mainUI");
  }
  if (n_WorldResourceMap) {
    n_WorldResourceMap->removeFromParent();
    n_WorldResourceMap = nullptr;
  }
  CleanPanelView();
  if (n_IphoneXTop) {
    n_IphoneXTop->removeFromParent();
    n_IphoneXTop = nullptr;
  }
  if (n_IphoneXBottom) {
    n_IphoneXBottom->removeFromParent();
    n_IphoneXBottom = nullptr;
  }
  if (n_ShareBtn) {
    n_ShareBtn->removeFromParent();
    n_ShareBtn = nullptr;
  }
  if (n_VoiceBtn) {
    n_VoiceBtn->removeFromParent();
    n_VoiceBtn = nullptr;
  }
  if (n_SystemNoticeView) {
    n_SystemNoticeView->removeFromParent();
    n_SystemNoticeView = nullptr;
  }
  InstanceCachManger::Get()->ClearCache();
  for (auto l_Warnning : n_WarnningList) {
    l_Warnning->removeFromParent();
  }
  n_WarnningList.clear();
  GBase::DClearItemAwards();
}

void LoginScene::SwitcherView(RShowMainCityView* p_Data) {
  if (!p_Data) return;
  if (n_CurrentShowView) {
    if (m_CurrentViewType == p_Data->ViewType) n_CurrentShowView->m_FreeImagesOnExit = false;
    if (p_Data->isFactionSwitch) n_CurrentShowView->m_FreeImagesOnExit = true;
    n_CurrentShowView->removeFromParentAndCleanup(true);
    n_CurrentShowView = nullptr;
    //     criAdxAux.freeAudio()
    //     imageManager.switchScene()
  }
  if (p_Data->OtherData.kingdomID)
    WorldMapDefine::Get()->CurrentMapKindomID = p_Data->OtherData.kingdomID;
  else
    WorldMapDefine::Get()->CurrentMapKindomID = PlayerTop::Get()->GetMapID();
  AtlantisWarUtil::Get()->RemoveWorldMapAtlantisWarInfo();
  GAudioEngine::Get()->StopMusic();
  UIBaseView* l_ShowView = nullptr;
  if (p_Data->ViewType == EScene::City) {
    if (n_FaceToDistanceNode) n_FaceToDistanceNode->setVisible(false);
    if (n_LoginView) {
      //   userSDKManager.logEvent(gSDKDef.TDonEvent.star_enter_city, {})
      //   local isSupport = gl.isSupportsASTC()
      //   userSDKManager.logEvent(gSDKDef.TDonEvent.check_astc_support, {support = isSupport})
      //   userSDKManager.getAdvertisingStrategy()
    }
    l_ShowView = MainCityView::Create(p_Data->OtherData);
    l_ShowView->setName("mainCityView");
    if (GuideCtrl::Get()->GetCurMainCityGuideStep() != nullptr) {
      GAudioEngine::Get()->PlayMusic("worldMap", true);
    } else {
      GAudioEngine::Get()->PlayMusic("mainCity", true);
    }
  } else if (p_Data->ViewType == EScene::World) {
    l_ShowView = WorldMapViewFactory::Get()->Create(p_Data->OtherData);
    l_ShowView->setName("worldMapView");
    GAudioEngine::Get()->PlayMusic("worldMap", true);
  }
  addChild(l_ShowView, 1);
  m_CurrentViewType = p_Data->ViewType;
  n_CurrentShowView = l_ShowView;
  m_SwitcherViewIng = false;
  if (CurrentMainUI()) {
    GBase::DSendMessage("MESSAGE_MAINSCEN_MAINUITOP_EVENT_REFRESH");
  }
}

UIBaseView* LoginScene::CurrentMainUI() {
  if (UIManger::Get()->GetProxy("mainUI")) return UIManger::Get()->GetProxy("mainUI");
  return nullptr;
}

void LoginScene::ShowView(EventCustom* p_Event) {
  //Show View for MainScene
  if (!p_Event->getUserData()) return;
  auto l_Data = static_cast<RShowMainCityView*>(p_Event->getUserData());
  if (l_Data->isJudgeCurScene && l_Data->ViewType == m_CurrentViewType) return;
  if (l_Data->ViewType == EScene::None) return;
  WorldMapDefine::Get()->CurrentMapKindomID = 0;
  GUtil::Get()->ResetCSDCatch();

  if (l_Data->isFromLogin) {
    SwitcherView(l_Data);
    if (l_Data->ViewType == EScene::World) CityBuildFunction::Get()->SetIsFirstLogin(false);
  } else if (!m_SwitcherViewIng) {
    m_SwitcherViewIng = true;
    GBase::DShowSwitcherView(l_Data->OtherData);
    auto l_Seq = Sequence::create(DelayTime::create(0.1f), CallFunc::create([=]() { SwitcherView(l_Data); }), nullptr);
  } else {
    stopAllActions();
    SwitcherView(l_Data);
  }
}

void LoginScene::ServerSocketLoginFail(EventCustom* p_Event) {
  if (!p_Event->getUserData()) return;
  auto l_FailType = "loginFail";
  auto l_HaveCancelBtn = true;
  auto l_ShowMsg = Translate::i18n("common_text_1122");
  // local eventFunc = _G.SoraDStartLoginServerAndCheckVersion
  auto l_IsShowDefaultMsgBox = true;
  auto l_IsCheckHasMaintenance = false;
  auto l_Data = static_cast<RLoginFailEvtArg*>(p_Event->getUserData());
  auto l_EventFunc = &GBase::DStartLoginServerAndCheckVersion;
  if (l_Data->Type == ELoginFailType::Client) {
    //   userSDKManager.logEvent(gSDKDef.TDonEvent.login_fail_client, {})
    l_FailType = "networkTimeout";
    l_HaveCancelBtn = false;
    l_ShowMsg = Translate::i18n("common_text_795");
    l_IsCheckHasMaintenance = true;
  } else if (l_Data->Type == ELoginFailType::Server) {
    //   userSDKManager.logEvent(gSDKDef.TDonEvent.login_fail_server, {})
    l_FailType = "serverMaintenance";
    l_HaveCancelBtn = false;
    l_IsShowDefaultMsgBox = false;
    l_ShowMsg = Translate::i18n("common_text_939");
    if (n_LoginView) {
      if (GDevice::Get()->IsForTest()) {
        l_IsShowDefaultMsgBox = true;
      } else {
        auto l_Panel = GBase::DSearchPanelFromManagerByName("commonMaintainView");
        auto l_PrePanel = dynamic_cast<UICommonMaintainView*>(l_Panel);
        if (l_PrePanel)
          l_PrePanel->InitData(l_Data->ServerTime || GOS::Get()->GetTime());
        else
          GBase::DPostCheckMaintain(l_Data->KingdomId, l_Data->ServerTime);
      }
    }
  } else if (l_Data->Type == ELoginFailType::Version) {
    l_FailType = "serverLimitVersion";
    l_HaveCancelBtn = false;
    l_ShowMsg = Translate::i18n("common_text_899");
  } else if (l_Data->Type == ELoginFailType::StartLogin) {
    //   userSDKManager.logEvent(gSDKDef.TDonEvent.login_fail_start_login, {})
    l_FailType = "loginTimeout";
    l_HaveCancelBtn = true;
    l_ShowMsg = Translate::i18n("common_text_1122");
    l_IsCheckHasMaintenance = true;
  } else if (l_Data->Type == ELoginFailType::GetUserInfo) {
    //   userSDKManager.logEvent(gSDKDef.TDonEvent.login_fail_get_user_info, {})
    l_FailType = "getUserInfoFail";
    l_HaveCancelBtn = true;
    l_ShowMsg = Translate::i18n("common_text_1123");
  } else if (l_Data->Type == ELoginFailType::SdkTokenError) {
    //   userSDKManager.logEvent(gSDKDef.TDonEvent.login_fail_sdk_token_error, {})
    l_FailType = "sdkTokenError";
    l_HaveCancelBtn = true;
    l_ShowMsg = Translate::i18n("common_text_3764");
    l_EventFunc = []() { GBase::DShowLoginView(); };
  }
  if (l_IsCheckHasMaintenance && n_LoginView && !GDevice::Get()->IsForTest()) {
    auto l_Panel = GBase::DSearchPanelFromManagerByName("commonMaintainView");
    auto l_PrePanel = dynamic_cast<UICommonMaintainView*>(l_Panel);
    if (l_PrePanel) return;
  }
  if (l_IsShowDefaultMsgBox) {
    auto l_Panel = GBase::DShowLoginFailBox(l_FailType, l_ShowMsg, l_HaveCancelBtn, [=]() { l_EventFunc(); });
    l_Panel->setName("SocketFailedMsgBox");
  }
}

void LoginScene::ServerSocketLoginAgain_Quick(EventCustom* p_Event) {
  // SoraDSendMessage({
  //   msg = "MESSAGE_SERVER_CLOSE_GUIDE"
  // })
  // VoiceChatSDKManager:getInstance():leaveChannel()
  // SoraDReloginReleaseManagerData()
  // SoraDCloseLoading()
  // Global_isLoginNeedLoading = true
  // print("-----\229\191\171\233\128\159\230\150\173\231\186\191\233\135\141\231\153\187-----")
  // SoraDRemoveAllPanelFromManager()
  // self:cleanPanelView()
  // SoraDStartGetLoginData()
}

void LoginScene::ServerSocketLoginAgain(EventCustom* p_Event) {
  //   print("sldkfjksljflksdjf")
  // local loginAgainFunc = function()
  //   Global_isLoginNeedLoading = true
  //   print("-----\230\150\173\231\186\191\233\135\141\232\191\158------")
  //   print("-----\229\133\179\233\151\173\230\137\128\230\156\137\231\149\140\233\157\162-----")
  //   SoraDCleanPopupWindowManager()
  //   SoraDRemoveAllPanelFromManager()
  //   if device.platform ~= "mac" then
  //     print("-----\230\150\173\231\186\191\233\135\141\232\191\158\231\131\173\230\155\180\230\163\128\230\159\165-----")
  //     require("app.game.updateModule.updateModule"):getInstance():disconnectedCheckVersion()
  //   end
  //   SoraDStartLoginServer()
  // end
  // SoraDSendMessage({
  //   msg = "MESSAGE_SERVER_CLOSE_GUIDE"
  // })
  // SoraDSendMessage({
  //   msg = "MESSAGE_PRINCE_GIFT_GUIDE_REFRESH",
  //   isRelogin = true
  // })
  // VoiceChatSDKManager:getInstance():leaveChannel()
  // SoraDReloginReleaseManagerData()
  // SoraDCloseLoading()
  // if self.isComeFromBackGroud then
  //   loginAgainFunc()
  // else
  //   userSDKManager.logEvent(gSDKDef.TDonEvent.login_fail_again, {
  //     loginagainTag = data.loginagainTag
  //   })
  //   local msgBoxPanel = SoraDShowMsgBox(i18n("common_text_1030"), i18n("common_text_204"), nil, function(callType)
  //     if callType == MSGBOX_CALLBACK_YES then
  //       print("sldkfjksljflksdjf22222")
  //       loginAgainFunc()
  //     end
  //   end)
  //   msgBoxPanel.enableTouchCloseSelf = true
  //   msgBoxPanel:setName("SocketFailedMsgBox")
  // end
}

void LoginScene::HideCurrentSceneViewAndMainUI(EventCustom* p_Event) {
  auto l_GuideCtrl = GuideCtrl::Get();
  if (l_GuideCtrl->GetCurMainCityGuideStep() != nullptr) return;
  if (p_Event->getUserData() == nullptr) return;
  auto l_HideData = static_cast<RHideMainUIEvtArg*>(p_Event->getUserData());
  if (l_HideData->isHideCurrentSceneView != ENullBool::Null) {
    if (l_HideData->isHideCurrentSceneView == ENullBool::True) {
      ++m_IsHideCurrentSceneViewCount;
    } else {
      m_IsHideCurrentSceneViewCount = std::max(0, m_IsHideCurrentSceneViewCount - 1);
    }
    if (n_CurrentShowView) {
      n_CurrentShowView->setVisible(m_IsHideCurrentSceneViewCount == 0);
      std::unique_ptr<RShowViewHidedEvtArg> l_EventData(new RShowViewHidedEvtArg());

      l_EventData->View = n_CurrentShowView;
      l_EventData->isVisible = m_IsHideCurrentSceneViewCount == 0;
      GBase::DSendMessage("MESSAGE_MAINSCEN_CURRENT_SHOWVIEW_HIDED", l_EventData.get());
    }
  }

  if (CurrentMainUI() && l_HideData->isHideMainUI != ENullBool::Null) {
    if (l_HideData->isHideMainUI == ENullBool::True)
      ++m_IsHideMainUICount;
    else
      m_IsHideMainUICount = std::max(0, m_IsHideMainUICount - 1);
    if (n_MainUIView) n_MainUIView->setVisible(m_IsHideMainUICount == 0);
    std::unique_ptr<bool> l_IsHiddle(new bool(m_IsHideMainUICount != 0));
    GBase::DSendMessage("MESSAGE_MAIN_UI_HIDDLE", l_IsHiddle.get());
    auto l_GuideCtrl = GuideCtrl::Get();
    auto l_NewPlayerTaskCtrl = PlayerTaskCtrl::Get();
    if (CurrentMainUI()->isVisible() && GBase::DIsGameGuide() &&
        (l_NewPlayerTaskCtrl->GetCurChapterID() > 4103000 || l_NewPlayerTaskCtrl->GetCurChapterID() == 0))
      GBase::DSendMessage("MESSAGE_MAIN_AGREEMENT_BOX");

    if (CurrentMainUI()->isVisible()) GBase::DSendMessage("MESSAGE_SERVER_EVENT_COMMON_RED_POINT_REFRESH");
  }
}

void LoginScene::ShowServerMessageInfo(EventCustom* p_Event) {
  if (p_Event->getUserData() == nullptr) return;

  auto l_EventData = static_cast<RServerMessageInfo*>(p_Event->getUserData());
  // local messageID = data.messageID
  auto l_MessageID = l_EventData->messageID;
  const char* l_IconSprite;
  auto l_IconData = l_EventData->IconData;
  auto l_TransParm = GMap<GString, GString>();
  // if iconData then
  if (l_EventData->IconData.IconType == ENoticeIcon::Build) {
    l_IconSprite = BuildingRead::Get()->GetIcon(static_cast<EBuilding>(l_IconData.iconID)).c_str();
    l_TransParm["buildID"] = BuildingRead::Get()->GetName(l_EventData->Param.BuildID);

  } else if (l_EventData->IconData.IconType == ENoticeIcon::Item) {
    l_IconSprite = ItemRead::Get()->GetIcon(l_IconData.iconID).c_str();
    l_TransParm["itemID"] = ItemRead::Get()->GetName(l_IconData.iconID);

  } else if (l_EventData->IconData.IconType == ENoticeIcon::Solider) {
    l_IconSprite = ArmyRead::Get()->GetIcon(static_cast<EArmy>(l_IconData.iconID));
    l_TransParm["soliderID"] = ArmyRead::Get()->GetName(l_IconData.iconID);

  } else if (l_EventData->IconData.IconType == ENoticeIcon::Resource) {
    l_IconSprite = ResourceRead::Get()->GetIcon(static_cast<EResource>(l_IconData.iconID));
    l_TransParm["resourceID"] = ResourceRead::Get()->GetName(l_IconData.iconID);

  } else if (l_EventData->IconData.IconType == ENoticeIcon::Tech) {
    ScienceRead::Get()->GetIcon(static_cast<EScience>(l_IconData.iconID));
    if (ScienceRead::Get()->IsScience(l_EventData->Param.TechID)) l_TransParm["techID"] = ScienceRead::Get()->GetName(l_EventData->Param.TechID);
    if (AllianceRead::Get()->IsScience(l_EventData->Param.TechID)) l_TransParm["techID"] = AllianceRead::Get()->GetScienceName(l_EventData->Param.TechID);

  } else if (l_EventData->IconData.IconType == ENoticeIcon::Army) {
    l_IconSprite = "icon_fight_expedition.png";
  } else if (l_EventData->IconData.IconType == ENoticeIcon::Reward) {
    l_IconSprite = "icon_equip_box2.png";
  } else if (l_EventData->IconData.IconType == ENoticeIcon::Normal) {
    l_IconSprite = l_EventData->IconData.iconName;
  }

  if (l_EventData->Param.equipID != 0) {
    auto l_EquipName = EquipRead::Get()->GetName(l_EventData->Param.equipID);
    if (l_EquipName != "") l_TransParm["equipID"] = l_EquipName;
  }

  if (l_EventData->Param.languageID != 0) {
    if (AllianceRead::Get()->GetLanguageName(l_EventData->Param.languageID) != "")
      l_TransParm["languageID"] = AllianceRead::Get()->GetLanguageName(l_EventData->Param.languageID);
  }
  auto l_LanguageString = Translate::i18n(std::to_string(l_MessageID).c_str(), l_TransParm);
  GBase::DShowMsgTip(l_LanguageString, l_IconSprite);
}

void LoginScene::MsgLordLevelUpView(EventCustom* p_Event) {
  if (LordInfoCtrl::Get()->GetLordUpgradePopStatus()) {
    GBase::DShowLordUPView();
  }
}

void LoginScene::GotoForeBackGroud(EventCustom* p_Event) {
  // local schedulerTime = require(cc.PACKAGE_NAME .. ".scheduler")
  // local function callFunc()
  //   self.isComeFromBackGroud = false
  //   if self.foreBackGroudTimer then
  //     SoraDManagerRemoveTimer(self, self.foreBackGroudTimer)
  //     self.foreBackGroudTimer = nil
  //     print("mainscene:isComeFromBackGroud,false")
  //   end
  // end
  // local groudType = data.groudType
  // if groudType == GOTO_FOREG_GROUD then
  //   print("mainscene:foreGroud")
  //   self.isComeFromBackGroud = true
  //   self.foreBackGroudTimer = SoraDCreateDelayTimer(self, callFunc, 10)
  //   userSDKManager.getAdvertisingStrategy()
  // elseif groudType == GOTO_BACK_GROUD then
  //   print("mainscene:backGroud")
  //   callFunc()
  // end
}

void LoginScene::ListenerKeyPad() {
  // if self.listenerLayer then
  //   return
  // end
  // local closeClientViewCfg = {
  //   ForeignPShootGamePanel = 1,
  //   LinkLinkViewPanel = 1,
  //   RoadRoughViewPanel = 1,
  //   TowerDefendPanel = 1,
  //   SoldierRushMapPanel = 1,
  //   SoldierRushLosePanel = 1
  // }
  // self.listenerLayer = display.newLayer()
  // self.listenerLayer:addTo(self)
  // self.listenerLayer:setKeypadEnabled(true)
  // local isCmdMode = false
  // self.listenerLayer:addNodeEventListener(cc.KEYPAD_EVENT, function(event)
  //   if DEBUG > 0 and device.platform == "mac" then
  //     print("event.code = ", event.code, ", KeyCodeKey = ", cc.KeyCodeKey[event.code + 1])
  //     if cc.KeyCode.KEY_ENTER == event.code or cc.KeyCode.KEY_KP_ENTER == event.code or cc.KeyCode.KEY_DPAD_CENTER == event.code then
  //       print("app:callReloadLua4Dev")
  //       app:callReloadLua4Dev()
  //     elseif cc.KeyCode.KEY_GRAVE == event.code then
  //       app:returnToMainScene4Dev()
  //     elseif event.code == cc.KeyCode.KEY_CTRL then
  //       isCmdMode = true
  //       print("cmd mode on")
  //     elseif event.code == cc.KeyCode.KEY_ALT then
  //       isCmdMode = false
  //       print("cmd mode off")
  //     elseif event.code == cc.KeyCode.KEY_C then
  //       SoraDCreatePanel("cheatView"):show()
  //     elseif event.code == cc.KeyCode.KEY_S then
  //       package.loaded["app.game.clientFilter.shenmiButton"] = nil
  //       include("shenmiButton").new()
  //     elseif isCmdMode then
  //       self:runTestScript(event.code)
  //     end
  //   end
  //   if SoraDIsGameGuide() then
  //     return
  //   end
  //   if event.key == "back" then
  //     local topPanel = SoraDCurrentTopPanelFromManager()
  //     dump(topPanel, " ==========topPanel")
  //     if topPanel then
  //       if topPanel.__cname == "legendMView" or topPanel.__cname == "allianceHuntPopView" then
  //         topPanel:goBack(topPanel.closeButton, ccui.TouchEventType.ended)
  //       elseif topPanel.__cname == "commonAgreementBox" or topPanel.__cname == "commonNormalAgreementBox" then
  //         topPanel:closeConfirm()
  //       elseif topPanel.__cname == "chapterTaskShowView" then
  //         if userSDKManager.isKO() then
  //           topPanel:closeView(topPanel.closeButton, ccui.TouchEventType.ended)
  //         end
  //       elseif topPanel.__cname == "commonPromptBox" and topPanel:getName() == "SocketFailedMsgBox" then
  //         topPanel:exitView(MSGBOX_CALLBACK_YES)
  //       elseif topPanel.__cname == "commonSystemMsgBox" and topPanel.style == topPanel.showType.download then
  //         print("\229\188\186\230\155\180\230\161\134\239\188\140\228\184\141\229\129\154\229\164\132\231\144\134")
  //       elseif topPanel.__cname == "lordLevelUpView" then
  //         topPanel:closeView(topPanel.closeButton, ccui.TouchEventType.ended)
  //       elseif closeClientViewCfg[topPanel.__cname] then
  //         topPanel:onClickClose()
  //       elseif topPanel.isCantCloseByReturn then
  //         print("\228\184\141\229\129\154\229\164\132\231\144\134", topPanel.__cname)
  //       else
  //         topPanel:close(topPanel.closeButton, ccui.TouchEventType.ended)
  //       end
  //     else
  //       local showMsg = i18n("notice_0169")
  //       SoraDShowMsgBox(showMsg, i18n("common_text_204"), i18n("heroDes_text_07"), function(callType)
  //         if callType == MSGBOX_CALLBACK_YES then
  //           print("\231\130\185\229\135\187\231\161\174\229\174\154")
  //           local noticeModule = include("noticeModule")
  //           noticeModule.addNotice()
  //           app:exit()
  //         end
  //       end)
  //     end
  //   elseif event.key == "menu" then
  //     print("\231\130\185\229\135\187\232\143\156\229\141\149\230\140\137\233\146\174")
  //   end
  // end)
}

GVector<UIBaseView*> LoginScene::GetCheckViewList() {
  // local viewList = {}
  auto l_ViewList = GVector<UIBaseView*>();
  if (CurrentMainUI()) {
    l_ViewList.push_back(CurrentMainUI());
    auto l_MainUI = dynamic_cast<UIMain*>(CurrentMainUI());
    auto p_MainuiViewList = l_MainUI->GetCheckViewList();
    for (auto p_View : p_MainuiViewList) {
      l_ViewList.push_back(p_View);
    }
  }
  l_ViewList.push_back(n_SystemNoticeView);
  if (n_CurrentShowView) l_ViewList.push_back(n_CurrentShowView);
  if (n_WorldResourceMap) l_ViewList.push_back(n_WorldResourceMap);

  return l_ViewList;
}

void LoginScene::InitLoginSuccess() {
  WorldMapDef::Get()->DoSwitchToAnchor();
  GFabric::Get()->ReportDeviceInfoChange();
  WorldMapUtil::Get()->ResetConfig();
  MilitaryRankCtrl::Get()->SendMarshalLoginTip();
}