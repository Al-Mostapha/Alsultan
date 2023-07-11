#include "UIMain.h"
#include "UIMainTop.h"
#include "UIMainBottom.h"
#include "UIPandectView.h"
#include "Base/Common/Common.Enum.h"
#include "Base/Common/Common.Teml.h"
#include "Base/Common/Common.Msg.h"
#include "Module/Activity/LoginGift.Ctrl.h"
#include "Game/Interior/Interior.Ctrl.h"
#include "Module/Activity/StarRhapsody/StarRhapsody.Ctrl.h"
#include "Module/Activity/SpiritualGift.Ctrl.h"
#include "Common/ClientEvent.Manger.h"
#include "Module/Player/Skill/LordSkill.Enum.h"
#include "Scene/Login/LoginScene.h"
#include "Module/UI/Panel/Lord/Skill/UICommonUseSkill.h"
#include "Module/Effect/EffectMainUITop.h"
#include "Base/Containers/HashMap.h"
#include "Module/UI/Common/Message/UIMsgNotice.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/Player/Chapter/PlayerTask.Ctrl.h"
#include "Engine/Engine.h"


UIMain::UIMain()
{
}

UIMain::~UIMain()
{
}

void UIMain::Ctor()
{
  UIBaseView::Ctor();
  setPositionX(GDisplay::Get()->rcx);
  _CurrentViewType = EScene::City;
  _TopArea = UIMainTop::Create();

  _TopArea->setAnchorPoint(Vec2(0, 1));
  _TopArea->setPosition(Vec2(0, getContentSize().height));
  addChild(_TopArea, 10);
  _PandectView = UIPandectView::Create();
  _PandectView->setAnchorPoint(Vec2(0, 0.5));
  _PandectView->setPosition(GBase::DFPoint(GDisplay::Get()->width - 139, getContentSize().height / 2, GDisplay::Get()->width));
  addChild(_PandectView, 20);
  _BottomArea = UIMainBottom::Create();
  _BottomArea->setAnchorPoint(Vec2(0, 0));
  _BottomArea->setPosition(Vec2(0, 0));
  addChild(_BottomArea, 10);
  BindTest();
}

void UIMain::BindTest()
{
  auto l_ButtonCheat = GBase::DGetChildByName<ui::Button *>(this, "Button_cheat");
  auto l_ButtonTest = GBase::DGetChildByName<ui::Button *>(this, "Button_test");

  if(GDevice::Get()->Platform() == EPlatform::Mac || SDKManager::Get()->IsBeta() || SDKManager::Get()->IsGameDevelop())
  {
    auto l_CreateButton = [this](Vec2 Pos){
      auto l_Button = ui::Button::create();
      l_Button->loadTextures("btn_green_small_01.png", "", "", ui::Widget::TextureResType::PLIST);
      l_Button->setPosition(Pos);
      l_Button->ignoreContentAdaptWithSize(false);
      l_Button->setContentSize(Size(110, 36));
      l_Button->setTitleFontSize(20);
      this->addChild(l_Button, 99);
      return l_Button;
    };
    l_ButtonCheat = l_ButtonCheat ? l_ButtonCheat : l_CreateButton(Vec2(200, GDisplay::Get()->height - 110));
    if(l_ButtonCheat)
    {
      l_ButtonCheat->addTouchEventListener(CC_CALLBACK_2(UIMain::ButtonCheatSendClick, this));
      l_ButtonCheat->setTitleText("cheat");
      l_ButtonCheat->setVisible(true);
    }
    l_ButtonTest = l_ButtonTest ? l_ButtonTest : l_CreateButton(Vec2(440, GDisplay::Get()->height - 110));
    if(l_ButtonTest)
    {
      l_ButtonTest->addTouchEventListener(CC_CALLBACK_2(UIMain::ButtonCheatSendClick, this));
      l_ButtonTest->setTitleText("secret");
      l_ButtonTest->setVisible(true);
    }
  }else{
    if(l_ButtonTest)
      l_ButtonTest->setVisible(false);
    if(l_ButtonCheat)
      l_ButtonCheat->setVisible(false);
  }
}

void UIMain::OnEnterOther(){
  // self.eventForegroundID = app:addEventListener(app.APP_ENTER_FOREGROUND_EVENT, handler(self, self.onEnterForeground))
  // self.eventBackgroundID = app:addEventListener(app.APP_ENTER_BACKGROUND_EVENT, handler(self, self.onEnterBackground))
  //Application::getInstance()->
}

void UIMain::OnExitOther(){
  // print("mainUIBase out")
  // app:removeEventListener(self.eventForegroundID)
  // app:removeEventListener(self.eventBackgroundID)
}

void UIMain::OnMessageListener(){
  GBase::DAddMessage(this, "MESSAGE_MAIN_UI_HIDDLE", CC_CALLBACK_1(UIMain::SetMainUIHiddle, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_LOGINFINSH", CC_CALLBACK_1(UIMain::ReLoginFinish, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_ONSHOW", CC_CALLBACK_1(UIMain::ChangeMainScene, this));
  GBase::DAddMessage(this, "MESSAGE_TRIGGER_SKILLS", CC_CALLBACK_1(UIMain::LordSkillEffect, this));
  GBase::DAddMessage(this, "MESSAGE_CUMUACTIVITY_REWARD", CC_CALLBACK_1(UIMain::MsgNoticeCumuReward, this));
  GBase::DAddMessage(this, "MESSAGE_EVALUATION_NOTIFY", CC_CALLBACK_1(UIMain::ShowEveluationView, this));
  GBase::DAddMessage(this, "MESSAGE_HALLOWEEN_ACTION", CC_CALLBACK_1(UIMain::ShowHalloweenActionView, this));
  GBase::DAddMessage(this, "MESSAGE_MAIN_STYLE_UPDATE", CC_CALLBACK_1(UIMain::UpdateStyle, this));
  GBase::DAddMessage(this, "MESSAGE_MAIN_AGREEMENT_BOX", CC_CALLBACK_1(UIMain::ShowAgreementBox, this));
  GBase::DAddMessage(this, "MESSAGE_MAINCITY_CASTLE_GIFT_POP_MSG", CC_CALLBACK_1(UIMain::MsgCastleGift, this));
  GBase::DAddMessage(this, "MESSAGE_MAINCITYVIEW_CASTLE_LEVELUP", CC_CALLBACK_1(UIMain::CastleLevelUp, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_KINGSORDER", CC_CALLBACK_1(UIMain::RefreshEventModule, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_ROMANSOUL_EVENTREFRESH", CC_CALLBACK_1(UIMain::RefreshEventModule, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", CC_CALLBACK_1(UIMain::RefreshEventModule, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_DEVICERANK_REFRESH", CC_CALLBACK_1(UIMain::RefreshEventModule, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_KINGDOMBATTLE_REFRESH", CC_CALLBACK_1(UIMain::RefreshEventModule, this));
  GBase::DAddMessage(this, "MESSAGE_MAINSCEN_NEWDAY", CC_CALLBACK_1(UIMain::NewDayReset, this));
  GBase::DAddMessage(this, "MESSAGE_NEW_PLAYER_QUEST_UPDATE", CC_CALLBACK_1(UIMain::NewChapterTaskOpen, this));
}

void UIMain::SetMainUIHiddle(EventCustom *p_Event){
  if(p_Event->getUserData()){
    auto l_IsHiddle = *static_cast<bool*>(p_Event->getUserData());
    this->setVisible(!l_IsHiddle);
  }else{
    this->setVisible(true);
  }

  
}

void UIMain::ButtonCheatSendClick(Ref *Sender,  ui::Widget::TouchEventType p_Type){

  if(p_Type == ui::Widget::TouchEventType::ENDED)
  {
    //   SoraDCreatePanel("cheatView"):show()
    // auto l_CheatView = CheatView::Create();
    // l_CheatView->Show();
  }
}

void UIMain::ButtonTestSendClick(Ref *Sender,  ui::Widget::TouchEventType p_Type){
  if(p_Type == ui::Widget::TouchEventType::ENDED)
  {
    //   package.loaded["app.game.clientFilter.shenmiButton"] = nil
    //   include("shenmiButton").new()
  }
}

void UIMain::ListenerKeyPad(){
  // local currentScene = display.getRunningScene()
  // if not currentScene then
  //   return
  // end
  // currentScene:listenerKeyPad()
}

void UIMain::OnEnterForeground(){
  // if not self.__cname then
  //   return
  // end
  // if not gIsGameInFrontOrBack then
  //   print("\232\191\155\229\133\165\229\137\141\229\143\176")
  //   gIsGameInFrontOrBack = true
  //   local isNeedRefreshGame = true
  //   print("\229\137\141\229\143\176:isNeedRefreshGame = ", isNeedRefreshGame)
  //   if isNeedRefreshGame then
  //     notificationManager.removeAllNotification()
  //     linkCtrl:onInvChange(GOTO_FOREG_GROUD)
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINSCEN_GOTO_FOREG_BACK_GROUD",
  //       groudType = GOTO_FOREG_GROUD
  //     })
  //   end
  //   paymentManager.onEnterForeground()
  //   deepLinking.getUrlAndRun()
  //   VoiceChatSDKManager:getInstance():enableAudio()
  //   userSDKManager.onEnterForegroundEvent()
  //   multiClientInitialize.judgeUserIsOnline2CallSDK2Push()
  // end
}

void UIMain::OnEnterBackground(){
  // if not self.__cname then
  //   return
  // end
  // if gIsGameInFrontOrBack then
  //   print("\232\191\155\229\133\165\229\144\142\229\143\176")
  //   gIsGameInFrontOrBack = false
  //   local isNeedRefreshGame = true
  //   print("\229\144\142\229\143\176:isNeedRefreshGame = ", isNeedRefreshGame)
  //   if isNeedRefreshGame then
  //     local noticeModule = include("noticeModule")
  //     noticeModule.addNotice()
  //     linkCtrl:onInvChange(GOTO_BACK_GROUD)
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINSCEN_GOTO_FOREG_BACK_GROUD",
  //       groudType = GOTO_BACK_GROUD
  //     })
  //   end
  //   VoiceChatSDKManager:getInstance():disableAudio()
  // end
}

void UIMain::NewDayReset(EventCustom *p_Event){
  LoginGiftCtrl::Get()->ResetLoginDays();
  StarRhapsodyCtrl::Get()->ResetResetTimes();
  SpiritualGiftCtrl::Get()->ResetDrawCount();
  InteriorCtrl::Get()->ResetLoginDays();
}

void UIMain::NewChapterTaskOpen(EventCustom *p_Event){
  if(p_Event->getUserData()){
    auto l_IsUpdate = *static_cast<bool*>(p_Event->getUserData());
    if(l_IsUpdate){
      GBase::DNewChapterOpen(true);
    }
  //   local mildGuideManager = gModuleMgr.sharedMgr("mildGuideManager")
  //   mildGuideManager:starMildByNewPlayerQuestID(gNewPLayerTaskType.TO_GET_CASTLE_LV2)      
  }
}

void UIMain::ReLoginFinish(EventCustom *p_Event){
  RefreshEventModule(p_Event);
}

void UIMain::RefreshEventModule(EventCustom *p_Event){
  if(p_Event->getUserData()){
    auto l_ActivityIds = *static_cast<GVector<int32>*>(p_Event->getUserData());
    for(auto l_OneId : l_ActivityIds){
      ClientEventManger::Get()->GetEventStateInfo(l_OneId);
    }
    if(l_ActivityIds.empty())
      ClientEventManger::Get()->GetEventStateInfo();
  }else{
    ClientEventManger::Get()->GetEventStateInfo();
  }
  GBase::DSendMessage("MESSAGE_UI_EVENTCENTER_REFRESHISNEW");
}

void UIMain::ChangeMainScene(EventCustom *p_Event){
  if(!p_Event->getUserData())
    return;
    
  auto lScene = *static_cast<RShowMainCityView*>(p_Event->getUserData());
  if(lScene.ViewType == EScene::None || lScene.ViewType == _CurrentViewType)
    return;
  _PandectView->setVisible(lScene.ViewType == EScene::City);
  _CurrentViewType = lScene.ViewType;
}

void UIMain::ShowHalloweenActionView(EventCustom *p_Event){
  if(!p_Event->getUserData())
    return;
  // local panel = SoraDSearchPanelFromManagerByName("halloweenActionView")
  // if panel == nil then
  //   panel = SoraDCreatePanel("halloweenActionView")
  //   panel:show()
  // end
  // panel:initData(false, data.data, data.isAFK)
}

void UIMain::CastleLevelUp(EventCustom *p_Event){
  // SoraDShowCastleUnlockView()
  GBase::DShowCastleUnlockView();
  // local curLevel = SoraDGetCastleLv()
  auto l_CurLevel = GBase::DGetCastleLv();
  // advertiseCollect.TriggerEvent(gSDKDef.TDonEvent.advertise_castle_level, curLevel)
  // if curLevel == CASTLE_LV2_LIMITED then
  //   include("cityBuildFunction"):checkCrazyTrio()
  // end
}

void UIMain::MsgCastleGift(EventCustom *p_Event){
  GBase::DShowCastleUPView();
}

void UIMain::ShowEveluationView(EventCustom *p_Event){
  if(!p_Event->getUserData())
    return;
  auto l_Data = *static_cast<bool*>(p_Event->getUserData());
  GBase::DShowRateStarView();
}

void UIMain::LordSkillEffect(EventCustom *p_Event){
  auto l_Scene = dynamic_cast<LoginScene *>(Director::getInstance()->getRunningScene());
  auto l_SkillId = *static_cast<int32*>(p_Event->getUserData());
  auto l_LordSkill = static_cast<ELordSkill>(l_SkillId);
  if( l_LordSkill == ELordSkill::BackAtonce){
    if(l_Scene){
      auto l_CurrentView = l_Scene->CurrentSceneShowView();
      if(GBase::IEquals(l_CurrentView->GetViewName(), GString("worldMapView"))){

      }else{
        static RShowMainCityView s_Data;
        s_Data.isFromLogin = true;
        s_Data.ViewType = EScene::World;
        GBase::DSendMessage("MESSAGE_MAINSCEN_ONSHOW", &s_Data);
      }
    }
  }else if(l_LordSkill == ELordSkill::FullHP){
    std::unique_ptr<int32> l_Style(new int(2));
    GBase::DSendMessage("MESSAGE_WORLD_MAP_DISPATCH_ARMY", l_Style.get());
  }else if(l_LordSkill == ELordSkill::Harvest || l_LordSkill == ELordSkill::TrapAction){
  //   local currentView = currentScene:currentSceneShowView()
    if(l_Scene){
      auto l_CurrentView = l_Scene->CurrentSceneShowView();
      if(GBase::IEquals(l_CurrentView->GetViewName(), GString("worldMapView"))){

//        auto l_CurrentScene = std::make_unique<EScene>(EScene::City);
//        GBase::DSendMessage("MESSAGE_MAINSCEN_ONSHOW", l_CurrentScene.get());
      }else{
        GBase::DSendMessage("MESSAGE_MAINCITYVIEW_LORD_SKILL_EFFECT"/*,data = data*/);
      }
    }
  }else if(l_LordSkill == ELordSkill::Rescue || l_LordSkill == ELordSkill::CollectProtect || l_LordSkill == ELordSkill::FastMarch){
    auto l_Panel = UICommonUseSkill::Create();
    l_Panel->InitData(l_LordSkill);
    l_Panel->InitPanel();
    l_Panel->Show();
  }else if(l_LordSkill == ELordSkill::TransRes){
    EffectMainUITop::Get()->LordSkillTransresEffect();
  }
}


void UIMain::MsgNoticeCumuReward(EventCustom *p_Event){
  if(!p_Event->getUserData())
    return;
  auto l_Data = *static_cast<GHashMap<GString, int32>*>(p_Event->getUserData());
  auto l_Total = l_Data.Contains("total") ? l_Data["total"] : 0;
  auto l_Type = l_Data.Contains("nType") ? l_Data["nType"] : 0;
  if(l_Type && l_Total > 0){
    GString l_NoticeId;
    if(l_Type % 2 == 1)
      l_NoticeId = "common_text_1884";
    else
      l_NoticeId = "common_text_1885";
    if(!l_NoticeId.empty()){
      auto l_Notice = UIMsgNotice::Create();  
      l_Notice->InitPanel();
      auto l_Sequance = Sequence::create(
        DelayTime::create(1), 
        CallFunc::create([&](){
          auto l_Data = GHashMap<GString, GString>();
          l_Data.insert(std::make_pair(GString("total"), std::to_string(l_Total)));
          l_Notice->Notice(l_NoticeId.c_str(), l_Data, ENoticeIcon::Reward);
      }), nullptr);
      runAction(l_Sequance);
    }
  }
}

void UIMain::ShowAgreementBox(EventCustom *p_Event){
  auto l_IsPop = LordInfoCtrl::Get()->GetUserAgreementPop();
  auto l_ShowPush = static_cast<bool*>(p_Event->getUserData());
  if(l_ShowPush == nullptr && l_IsPop && isVisible() && GBase::DCurrentTopPanelFromManager() == nullptr){
  //   SoraDAddPopupWindow(function()
  //     SoraDCreatePanel("commonAgreementBox"):show()
  //   end, uiDequeTypeTab.AGREEMENT)
  //   userSDKManager.onGuideEvent(2801)
  }else if(
    *l_ShowPush && isVisible() && 
    GDevice::Get()->Platform() == EPlatform::IOS &&
    GBase::DIsGameGuide() == false && GBase::DCurrentTopPanelFromManager() == nullptr
    && (PlayerTaskCtrl::Get()->GetCurChapterID() > 4103100 || PlayerTaskCtrl::Get()->GetCurChapterID() == 0)
    ){
      auto l_BoxType = SDKManager::Get()->GetPushNotificationState();
      if(l_BoxType != 1){
        auto l_ConfigTime = GBase::DConfigGet<int32>("Game:IOSNoticePush:saveTime~integer");
        auto l_NowTime = GServiceFunction::Get()->SystemTime();
        if(l_ConfigTime == 0 || std::abs(l_NowTime - l_ConfigTime) >= 604800){
          auto l_Msg = Translate::i18n("common_text_3836");
          auto l_Btn = Translate::i18n("common_text_477");
          if(l_BoxType == 3){
            l_Msg = Translate::i18n("common_text_3837");
            l_Btn = Translate::i18n("common_text_204");
          }
          GBase::DShowMsgBox(l_Msg, l_Btn, Translate::i18n("common_text_185"), [=](EMsgBoxCallBack p_Res){
            GBase::DConfigSet("Game:IOSNoticePush:saveTime~integer", GServiceFunction::Get()->SystemTime());
            if(p_Res == EMsgBoxCallBack::Yes && l_BoxType != 3){
              if(l_BoxType == 0){
                SDKManager::Get()->SetSDKNoticeEnable();
              }else if(l_BoxType == 2){
                SDKManager::Get()->GotoSettingPushNotification();
              }
            }
          }/**, {canNotClose = true}*/);
        }
      }
  }
}

void UIMain::UpdateStyle(EventCustom *p_Event){

}

GVector<UIBaseView*> UIMain::GetCheckViewList(){
  auto l_ViewList = GVector<UIBaseView*>();
  //TODO: Add View
  if(_TopArea)
    l_ViewList.push_back(_TopArea);
  if(_PandectView)
    l_ViewList.push_back(_PandectView);
  if(_BottomArea)  
    l_ViewList.push_back(_BottomArea);
  return l_ViewList;
}

