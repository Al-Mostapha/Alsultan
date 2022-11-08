#include "LoginScene.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Effect/Effect.Enum.h"
#include "Module/Effect/Include.h"
#include "Module/Item/Include.h"
#include "Module/UI/Common/Button/UICommonShareButton.h"
#include "Module/UI/Common/UICommonDressPreview.h"
#include "Module/UI/Common/UICommonItemShowBox.h"
#include "Module/UI/EventCenter/EventTemplate/PrinceGift/UIPrinceGiftBuffPreview.h"
#include "Module/UI/UIManger.h"
#include "Module/UI/View/UILogin.View.h"
#include "Module/UI/MainUI/UIMain.h"

// on "init" you need to initialize your instance
bool LoginScene::init() {
  if (!LoginScene::init()) {
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

  // self:startGame()

  // self:onMessageListener()
  // if device.platform == "mac" then
  //   self:listenerKeyPad_imgui()
  // end
}

void LoginScene::StartGame() { InitData(); }

void LoginScene::InitData() {
  CreatePanelView();
  CreateLoginView();
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
  if (m_PanelView) m_PanelView->removeFromParent();
  m_PanelView = ui::Layout::create();
  Director::getInstance()->getRunningScene()->addChild(m_PanelView, 5);
}

void LoginScene::CleanPanelView() {
  UIManger::Get()->CloseAllUI();
  for (auto l_OneChild : m_PanelView->getChildren()) {
    if (l_OneChild->getName() != "commonSystemMsgBox") l_OneChild->removeFromParent();
  }
}

void LoginScene::CreateLoginView(EScene p_Type, EKingdomClass p_Kingdom) {
  //   showViewType = showViewType or VIEW_TYPE_CITY
  if (p_Type == EScene::None) p_Type = EScene::City;
  stopAllActions();
  runAction(Sequence::create(DelayTime::create(0.016666666666666666),
                              CallFunc::create([=]() {
                                GAudioEngine::Get()->Init();
                                 // self:loginSettingRun()
                                GAudioEngine::Get()->StopMusic();
                                GAudioEngine::Get()->PlayMusic("loading", true);
                                GAudioEngine::Get()->SetMusicVolume(0.5f);
                              }),
                              nullptr));
  if (m_LoginView) {
    m_LoginView->removeFromParent();
    m_LoginView = nullptr;
  }
  auto l_LoginView = UILoginView::Create();
  l_LoginView->SetKingdomClass(p_Kingdom);
  l_LoginView->SetShowViewType(p_Type);
  addChild(l_LoginView, 4);
  m_LoginView = l_LoginView;
  GBase::DCloseSwitcherView();
  // ShackModule.unload()
  ReleaseMainView();
}

bool LoginScene::RemoveLoginView() {
  //   local ret = false
  auto l_Ret = false;
  // if self.loginView then
  if (m_LoginView) {
    m_LoginView->removeFromParent();
    m_LoginView = nullptr;
    l_Ret = true;
    if (m_IphoneXTop) {
      //  self.iphoneXTop:setVisible(device.isIphoneXMode())
      m_IphoneXTop->setVisible(Application::getInstance()->getTargetPlatform() == Application::Platform::OS_IPHONE);
    }
    if (m_IphoneXBottom) {
      //  self.iphoneXBottom:setVisible(device.isIphoneXMode())
      m_IphoneXBottom->setVisible(Application::getInstance()->getTargetPlatform() == Application::Platform::OS_IPHONE);
    }
  }
  return l_Ret;
}

void LoginScene::LuaWillReload() {
  // VoiceChatSDKManager:getInstance():leaveChannel()
}

void LoginScene::UpdateShareButton(EventCustom* p_Event) {
  if (GBase::CommonCheck::Get()->ScreenShoot)
    if (m_ShareBtn) m_ShareBtn->setVisible(false);
  if (p_Event && m_ShareBtn && p_Event->getUserData() != nullptr) {
    m_ShareBtn->setVisible((bool)p_Event->getUserData());
  } else {
    auto l_IsShow = GBase::DConfigGet<int32>("Game:GameOptionsView:showShareBtn~integer", true);
    if (l_IsShow == 0) {
      if (CityCtrl::Get()->GetBuildingMaxLv(EBuilding::Castle) >= 10) {
        GBase::DConfigSet<int32>("Game:GameOptionsView:showShareBtn~integer", 1, true);
        l_IsShow = 1;
      }
    }
    if (l_IsShow == 1 && m_ShareBtn == nullptr) {
      m_ShareBtn = UICommonShareButton::create();
      m_ShareBtn->InitPanel();
      m_ShareBtn->setPosition(Vec2(0, 0));
      addChild(m_ShareBtn, 8);
    } else if (l_IsShow != 1 && m_ShareBtn) {
      m_ShareBtn->removeFromParent();
      m_ShareBtn = nullptr;
    }
  }
}

void LoginScene::UpdateCommonIconTip(RCommonIconData p_IconData) {
  auto l_Id = p_IconData.id;
  auto l_Num = p_IconData.num;
  auto l_Pos = p_IconData.Pos;
  auto l_CustomName = p_IconData.CustomName;
  auto l_CustomTip = p_IconData.CustomTip;
  //   local commonTip = display.getRunningScene():getChildByName("commonItemTips")
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

void LoginScene::UpdateVoiceButton(){
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

void LoginScene::UpdateVoiceInviteButton(){
  // local info = redata.redata
  // local voiceInviteBtn = SoraDCreatePanel("voiceChatInviteButton")
  // voiceInviteBtn:initData(info)
  // voiceInviteBtn:setPosition(50, display.height / 2)
  // self:addChild(voiceInviteBtn, 10)
}

void LoginScene::ShowIphoneX(){
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

void LoginScene::CreatMainView(EScene p_Type){
  InitLoginSuccess();
  ReleaseMainView();
  m_CurrentShowView = nullptr;
  // userSDKManager.timeInfo.t_mainui.tbegin = SoraDGetSocketTime()
  m_MainUIView = UIMain::Create();
  m_MainUIView->InitPanel();
  m_MainUIView->setSwallowTouches(false);
  addChild(m_MainUIView, 2);
  // userSDKManager.timeInfo.t_mainui.tend = SoraDGetSocketTime()
}


void LoginScene::ReleaseMainView(){
}

void LoginScene::InitLoginSuccess(){
  
}