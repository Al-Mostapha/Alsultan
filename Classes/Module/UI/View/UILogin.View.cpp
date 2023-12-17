#include "UILogin.View.h"
#include "Engine/Engine.h"
#include "Engine/Device.h"
#include "Base/Math/Math.Base.h"
#include "Base/Common/Common.City.h"
#include "Scene/Login/LoginScene.h"
#include "UILoginInput.h"
// #include "spine/SkeletonAnimation.h"
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#endif
#include "Module/Building/Building.Enum.h"
#include "Base/Common/Common.Teml.h"


UILoginView *UILoginView::Create()
{
  auto l_Panel = create();
  RBasePenelData l_Data;
  l_Data.FutureName = "loginView";
  l_Panel->InitPanel(CsbUiFilePath::LoginView, &l_Data);
  return l_Panel;
}

void UILoginView::AddSubViews(){
  m_AnimationLogo = CSLoader::createNode(CsbUiFilePath::AnimationLogo);
  m_CCSLogo = GBase::DGetChildByName<Node *>(_Panel, "CCS_animationLogo_logo");
  
  auto l_LogoAction = CSLoader::createTimeline(CsbUiFilePath::AnimationLogo);
  m_CCSLogo->addChild(m_AnimationLogo);
  m_AnimationLogo->runAction(l_LogoAction);
  l_LogoAction->gotoFrameAndPlay(0, true);

  n_SpriteAnimationLuotuo = GBase::DGetChildByName<Node *>(_Panel, "Node_luotuo");
  auto l_LoadingCamel = CSLoader::createNode(CsbUiFilePath::AnimationLoadingCamel);
  auto l_LoadingCamelAnimation = CSLoader::createTimeline(CsbUiFilePath::AnimationLoadingCamel);
  n_SpriteAnimationLuotuo->addChild(l_LoadingCamel);
  l_LoadingCamel->runAction(l_LoadingCamelAnimation);
  l_LoadingCamelAnimation->gotoFrameAndPlay(0, true);
  addChild(_Panel);
}

void UILoginView::Ctor()
{
  UIBasePanel::Ctor();
  AddSubViews();
  if(UserDefault::getInstance())
    UserDefault::getInstance()->setBoolForKey("System:RAMADAN_SWITCH~bool", GBase::GameDefs::Get()->RAMADAN_SWITCH);
  _IsHideCurrentSceneView = true;
  GBase::DGetDefaultLanguage();
  GBase::DSetDefaultLanguage();
  // userSDKManager.resetTimeInfo()
  // userSDKManager.registCallBackFunc()
  // userSDKManager.setChangeOrUpdatePasswordBlock()
  // notificationManager.registerNotification()
  // if device.platform == "android" then
  //   userSDKManager.logEvent(gSDKDef.TDonEvent.require_permssin_success, {})
  // end
  // criAdxAux.loadLanguageAcb()

  InitVars();
  InitView();
  SetInitCliper();
  InitUpdateInfo();
  SetMainSenceMsgListener();
  SetVersion2Top();
  InitSpineAnimation();
  m_TestArrayImages.clear();
  LoadBar(50);
  runAction(Sequence::create(
    DelayTime::create(1),
    CallFunc::create([this]{
      UpdateTime(0);
    }),
    nullptr
  ));
}

void UILoginView::InitVars(){
  GGlobal::Get()->Global_isLoginNeedLoading = false;
  GGlobal::Get()->GAME_LOGIN_FAIL_COUNT = 0;
  m_InitFinishCount = 0;
  m_ShowViewType = EScene::City;
}

void UILoginView::SetMainSenceMsgListener(){
  auto l_Scene = dynamic_cast<LoginScene*>(Director::getInstance()->getRunningScene());
  if(!l_Scene)
    return;
  l_Scene->OnMessageListener();
}


void UILoginView::InitROSView(){
  n_LoginInitBg = GBase::CreateSprite("SinglePicture/loginInitBg_ros.png");
  auto l_Display = GDisplay::Get();
  n_LoginInitBg->setPosition(Vec2(l_Display->cx, l_Display->rheight / 2 - (1386 - l_Display->rheight) * 0.2));
  n_NodeEvent->addChild(n_LoginInitBg);
  n_LoginInitBg->setLocalZOrder(-1);
  // n_LoginInitBg2 = GBase::CreateSprite("SinglePicture/loginInitBg2.png");
  // n_LoginInitBg2->setPosition(Vec2(l_Display->cx, l_Display->rheight / 2 - (1386 - l_Display->rheight) * 0.2));
  // if(n_NodeEvent) n_NodeEvent->addChild(n_LoginInitBg2);
  // n_LoginInitBg2->setLocalZOrder(0);
  // n_LoginInitBg2->setVisible(false);
  m_Logo = GBase::DGetChildByName<Node *>(_Panel, "Top_Node_logo");
  m_Logo->setLocalZOrder(9);
  m_CCSLogo = GBase::DGetChildByName<Node *>(_Panel, "CCS_animationLogo_logo");
  // m_AnimationLogo = static_cast<ActionTimeline *>(m_CCSLogo->getActionByTag(m_CCSLogo->getTag()));
  // m_AnimationLogo->gotoFrameAndPlay(0, true);
  if(l_Display->rheight < 960)
    m_Logo->setScale(0.6);
    m_BottomLoading = GBase::DGetChildByName<ui::LoadingBar *>(_Panel, "Bottom_Center_Node_loadingBar");
    m_BottomLoading->setLocalZOrder(3);
    //m_Logo->setPositionY(l_Display->height - 150);
    if(SDKManager::Get()->IsKo()){
    m_Logo->setVisible(false);
    // auto l_LogoTitle = GBase::CreateSprite("SinglePicture/logo_ko.png");
    // auto l_X = m_Logo->getPositionX();
    // auto l_Y = m_Logo->getPositionY();
    // m_Logo->getParent()->addChild(l_LogoTitle);
    // l_LogoTitle->setPosition(Vec2(l_X, l_Y - 50));
    // l_LogoTitle->setLocalZOrder(2);
  }
}

void UILoginView::InitKOHView(){
  auto l_KohPath = "SinglePicture/loginInitBg_koh.png";
  if(!GBase::GameDefs::Get()->RAMADAN_SWITCH)
    l_KohPath = "SinglePicture/loginInitBg_koh_pre.png";
  n_LoginInitBg = GBase::CreateSprite(l_KohPath);
  auto l_Display = GDisplay::Get();
  n_LoginInitBg->setPosition(Vec2(l_Display->cx, l_Display->rheight / 2 - (1386 - l_Display->rheight) * 0.2));
  n_LoginInitBg->setContentSize(Size(640, 1386));
  if(n_NodeEvent) n_NodeEvent->addChild(n_LoginInitBg);
  n_LoginInitBg->setLocalZOrder(-1);
  m_Logo = GBase::DGetChildByName<Node *>(_Panel, "Top_Node_logo");
  m_Logo->setLocalZOrder(9);
  if(l_Display->rheight < 960)
    m_Logo->setScale(0.6);
  if(!GBase::DFIsRA())
    m_Logo->setPositionY(l_Display->rheight - 90);
  else
    m_Logo->setPositionY(l_Display->rheight - 122);
  if(l_Display->rheight > 1136)
    m_Logo->setPositionY(l_Display->rheight - 180);
  m_BottomLoading = GBase::DGetChildByName<Node *>(_Panel, "Bottom_Center_Node_loadingBar");
  m_BottomLoading->setLocalZOrder(3);
}

void UILoginView::InitView(){
  _Panel->setContentSize(GDisplay::Get()->realSize);
  _Panel->setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->rcy));
  n_NodeEvent = GBase::DGetChildByName<Node *>(_Panel, "Node_event");
  n_NodeEvent->setLocalZOrder(-3);
  if(GBase::Const::Get()->IsArClient)
    InitKOHView();
  else
    InitROSView();
  n_TxtWarTips = GBase::DGetChildByName<Sprite *>(_Panel, "Center_pyramid");
  if(n_TxtWarTips){
    n_TxtWarTips->setLocalZOrder(3);
    n_TxtWarTips->setVisible(false);
  }
  m_NodeFix = GBase::DGetChildByName<Node *>(_Panel, "Top_Node_fix");
  if(m_NodeFix){
    m_NodeFix->setLocalZOrder(3);
    m_BtnUpdateFix = GBase::DGetChildByName<ui::Layout *>(_Panel, "Button_box");
    m_BtnUpdateFix->addTouchEventListener(CC_CALLBACK_2(UILoginView::OnClickUpdateFix, this));
    m_TxtUpdateFix = GBase::DGetChildByName<ui::Text *>(_Panel, "Text_update_fix");
    m_TxtUpdateFix->setString(Translate::i18n("download_first_description_013"));
    m_BtnUpdateFix->setContentSize(Size(m_TxtUpdateFix->getContentSize().width + 30, 30));
  }
}


void UILoginView::OnEnterOther(){
  GVector<GString> l_ImageArray = {
    "Resident/loginViewUI"
  };
  _Panel->LoadImages(l_ImageArray, CC_CALLBACK_0(UILoginView::FinishLoadImages, this));
}


void UILoginView::StartObbLoad(){
  SwitchNextLoading(ELoginRangeTbl::ObbUpdate);
  auto javaClassName2 = "org/cocos2dx/cpp/AppActivity";
  auto javaMethodName2 = "startOBBAction";
  auto javaMethodSig2 = "()V";
  #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
  JniMethodInfo t;
  if(JniHelper::getStaticMethodInfo(t, javaClassName2, javaMethodName2, javaMethodSig2)){
    t.env->CallStaticVoidMethod(t.classID, t.methodID);
    t.env->DeleteLocalRef(t.classID);
  }
  #endif
}


bool UILoginView::CheckObbExported(){
  auto l_Ret = true;
  auto l_JavaClassName2 = "org/cocos2dx/cpp/AppActivity";
  auto l_JavaMethodName2 = "expansionFilesExported";
  auto l_JavaMethodSig2 = "()Z";
  #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
  JniMethodInfo t;
  if(JniHelper::getStaticMethodInfo(t, l_JavaClassName2, l_JavaMethodName2, l_JavaMethodSig2)){
    l_Ret = t.env->CallStaticBooleanMethod(t.classID, t.methodID);
    t.env->DeleteLocalRef(t.classID);
  }
  #endif
  return l_Ret;
}

void UILoginView::StartValidateObb(){
  SwitchNextLoading(ELoginRangeTbl::ObbValidate);
}

void UILoginView::ValidateObbSuccess(){
  auto l_FileInstance = FileUtils::getInstance();
  // if(l_FileInstance->initAppExpansionPackage()){
  //   l_FileInstance->initAppExpansionPackage();
  // }
  FinishRange(ELoginRangeTbl::ObbValidate);
  _Panel->runAction(Sequence::create(
    DelayTime::create(0.0f),
    CallFunc::create([this](){
      StartCheckUpdate();
    }),
    nullptr));
}

void UILoginView::FinishLoadImages(){
  if(GDevice::Get()->Platform() == EPlatform::Android){
    if(!CheckObbExported()){
      StartObbLoad();
    }else{
      auto l_FileInstance = FileUtils::getInstance();
      //   if fileInstance.initAppExpansionPackage then
      //     fileInstance:initAppExpansionPackage()
      //   end
      StartPatchUpdate();
    }
  }else if(GDevice::Get()->Platform() == EPlatform::IOS){
    WaitForAttGranted();
  }else{
    StartPatchUpdate();
  }
}

void UILoginView::WaitForAttGranted(){
  // print("onAttGrantedComplete")
  // local ok, ret = luaoc.callStaticMethod("UserSDKManager", "isWaitAttGranted", nil)
  // print("isWaitAttGranted back", ok, ret)
  // if ok and not ret then
  //   self:onAttGrantedComplete()
  // else
  //   SoraDAddMessage(self, "MESSAGE_IOS_ATT_GRANTED_FIN", handler(self, self.onAttGrantedComplete))
  // end
}

void UILoginView::OnAttGrantedComplete(){
  GBase::DRemoveMessageFromTargetByName(_Panel, "MESSAGE_IOS_ATT_GRANTED_FIN");
  StartPatchUpdate();
}

void UILoginView::StartPatchUpdate(){
  SwitchNextLoading(ELoginRangeTbl::GameUpdate);
  Start2CheckVersion();
  SetKingdomClassTips();
}

void UILoginView::OnReceiveObbMsg(EventCustom *p_Event){
  //   local info = data.data
  // if info.msgCode == "UpdateProgress" then
  //   print("info.msgCode UpdateProgress")
  //   self:loadBar(1 + tonumber(info.progressRate) / 100 * 99)
  // elseif info.msgCode == "startDownloadObb" then
  //   userSDKManager.logEvent(gSDKDef.TDonEvent.start_obb_download, {})
  //   self:switchNextLoading(gLoginRangeTbl.obbUpdate)
  // elseif info.msgCode == "exportObbStart" then
  //   userSDKManager.logEvent(gSDKDef.TDonEvent.start_obb_export, {})
  //   self:switchNextLoading(gLoginRangeTbl.obbValidate)
  // elseif info.msgCode == "exportObbSuccess" then
  //   userSDKManager.logEvent(gSDKDef.TDonEvent.export_obb_success, {})
  //   self:validateObbSuccess()
  // elseif info.msgCode == "exportObbFail" then
  //   userSDKManager.logEvent(gSDKDef.TDonEvent.export_obb_fail, {})
  //   if not self.obbMsgBox then
  //     self.obbMsgBox = SoraDShowMsgBox(i18n("login_text_14"), i18n("common_text_054"), nil, function(exitType)
  //       self.obbMsgBox = nil
  //       self:startObbLoad()
  //     end, {canNotClose = true})
  //   end
  // elseif info.msgCode == "downloadSuccess" then
  //   userSDKManager.logEvent(gSDKDef.TDonEvent.download_obb_success, {})
  // elseif info.msgCode == "validataObbError" then
  //   userSDKManager.logEvent(gSDKDef.TDonEvent.validata_obb_error, {
  //     errCode = info.errorCode
  //   })
  // elseif info.msgCode == "validataObbSuccess" then
  //   userSDKManager.logEvent(gSDKDef.TDonEvent.validata_obb_success, {})
  // elseif info.msgCode == "DownloadError" then
  //   userSDKManager.logEvent(gSDKDef.TDonEvent.download_obb_error, {
  //     errCode = info.errorCode
  //   })
  //   print("info.msgCode compare error")
  //   if not self.obbMsgBox then
  //     self.obbMsgBox = SoraDShowMsgBox(i18n("login_text_14"), i18n("common_text_054"), nil, function(exitType)
  //       self.obbMsgBox = nil
  //       self:startObbLoad()
  //     end, {canNotClose = true})
  //   end
  // end
}

void UILoginView::InitUpdateInfo(){
  // self.isUpdateReload = false
  // if capi_update_getIsUpdateReload then
  //   self.isUpdateReload = capi_update_getIsUpdateReload()
  // end
  // GAME_VERSION = "99.99.001"
  // if capi_update_setPath then
  //   GAME_VERSION = require("app.game.updateModule.updateModule"):getInstance():getVersion()
  // end
  // SoraDAddMessage(self, "MESSAGE_UPDATE_SUCCESS", handler(self, self.updateSucess))
  // SoraDAddMessage(self, "MESSAGE_UPDATE_DOWNLOADPROGRESS", handler(self, self.onDownloadProgress))
  // SoraDAddMessage(self, "MESSAGE_PRE_DOWNLOAD_LOGIN_PROGRESS", handler(self, self.onPreDownloadProgress))
  // SoraDAddMessage(self, "MESSAGE_PRE_DOWNLOAD_LOGIN_PROGRESS_UNZIP", handler(self, self.onPreDownloadProgressUNZip))
  // SoraDAddMessage(self, "MESSAGE_RECEIVE_OBB_MSG", handler(self, self.onReceiveObbMsg))
}

void UILoginView::Start2CheckVersion(){
  // self:loadBar(1)
  LoadBar(1);
  // require("app.includes.requireFiles")
  if(GDevice::Get()->Platform() == EPlatform::Mac || m_IsUpdateReload || GDevice::Get()->IsForTest()){
    UpdateSucess();
  }else{
    bool l_Is64bit = false;
    if(GDevice::Get()->Platform() == EPlatform::Android){
      l_Is64bit = GDevice::Get()->Is64Bit();
    }
    //   print("is bit 64 ", tostring(is64bit))
    //   userSDKManager.logEvent(gSDKDef.TDonEvent.star_game, {is64bit = is64bit})
    //   require("app.game.updateModule.updateModule"):getInstance():checkVersion()
    //   userSDKManager.logEvent(gSDKDef.TDonEvent.star_check_innerVer, {})
  }
}

void UILoginView::UpdateSucess(){
  FinishRange(ELoginRangeTbl::GameUpdate);
  SetVersion2Top();
  m_InitFinishCount += 1;
  Sequence::create(
    DelayTime::create(0), 
    CallFunc::create([this](){
      StartGame();
  }), nullptr);
}


void UILoginView::OnDownloadProgress(EventCustom *p_Event){
  if(!p_Event->getUserData())
    return;
  auto l_Precent = (*(float*)p_Event->getUserData());
  LoadBar(1 + l_Precent / 100 * 99);
}

void UILoginView::OnPreDownloadProgress(EventCustom *p_Event){
  if(!p_Event->getUserData())
    return;
  auto l_Downloaded = (EvArDownlodProgress*)p_Event->getUserData();
  if(!l_Downloaded)
    return;
  auto l_Total = l_Downloaded->m_Total;
  auto l_DownloadedSize = l_Downloaded->m_Downloaded;
  if(!l_Total || !l_DownloadedSize || !(l_Total > 0))
    return;
  float l_Perscent = l_DownloadedSize / l_Total * 100;
  float l_Cur = 1 + l_Perscent / 100 * 99;
  LoadBar(l_Cur);
  if(l_Cur > 0){
    auto l_StrDownload = GMath::DConvertNumberWithUnit(l_DownloadedSize);
    auto l_StrTotal = GMath::DConvertNumberWithUnit(l_Total);
    n_TxtNoteTip->setString(
      Translate::i18n(
        "download_first_description_03", {
          {"var1", l_StrDownload},
          {"var2", l_StrTotal}
        }));
  }
}

void UILoginView::OnPreDownloadProgressUNZip(EventCustom *p_Event){
 if(!p_Event->getUserData())
    return;
  auto l_Downloaded = (EvArDownlodProgress*)p_Event->getUserData();
  if(!l_Downloaded)
    return;
  auto l_Total = l_Downloaded->m_Total;
  auto l_DownloadedSize = l_Downloaded->m_Downloaded;
  if(!l_Total || !l_DownloadedSize || !(l_Total > 0))
    return;
  float l_Perscent = l_DownloadedSize / l_Total * 100;
  float l_Cur = 1 + l_Perscent / 100 * 99;
  LoadBar(l_Cur);
  if(l_Cur > 0){
    auto l_StrDownload = GMath::DConvertNumberWithUnit(l_DownloadedSize);
    auto l_StrTotal = GMath::DConvertNumberWithUnit(l_Total);
    n_TxtNoteTip->setString(
      Translate::i18n(
        "download_first_description_016", {
          {"var1", l_StrDownload},
          {"var2", l_StrTotal}
        }));
  }
}

void UILoginView::SetVersion2Top(){
  m_VersionLabel = GBase::DGetChildByName<ui::Text *>(_Panel, "Text_version");
  m_VersionLabel->setLocalZOrder(5);
  m_VersionLabel->setString(GBase::GameDefs::Get()->GAME_VERSION);
  m_VersionLabel->setVisible(true);
  m_VersionLabel->setColor(GBase::Const::Get()->IsArClient ? Color3B(0, 0, 0) : Color3B(255, 255, 255));
  m_VersionLabel->setPosition(Vec2(GDisplay::Get()->width - 20, GDisplay::Get()->rheight - 20));
  if(!GBase::DFIsRA()){
    m_VersionLabel->setAnchorPoint(Vec2(0, 1));
    m_VersionLabel->setPositionX(20);
  }
  if(m_NodeFix){
    if(!GBase::DFIsRA()){
      m_NodeFix->setPosition(Vec2(GDisplay::Get()->width - 40, GDisplay::Get()->rheight - 32));
    }else{
      m_NodeFix->setPosition(Vec2(40, GDisplay::Get()->rheight - 32));
    }
  }
}

void UILoginView::LoadCommonImages(){
  m_LoadImageFinish = false;
  SwitchNextLoading(ELoginRangeTbl::LoadImages);
  // if not SoraDHDResManager.isInit then
  //   SoraDInitHDResManager()
  // end
  LoadBar(1);
  int l_LoadImageIndex = 0;
  auto l_ImageList = GBase::GameDefs::Get()->CommonArrayImagesPath;
  for(auto l_OneImagePath :  l_ImageList){
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile(l_OneImagePath);
    l_LoadImageIndex++;
    LoadBar(1 + l_LoadImageIndex / l_ImageList.size() * 99);
    if(l_LoadImageIndex >= l_ImageList.size()){
      FinishRange(ELoginRangeTbl::LoadImages);
      m_InitFinishCount += 1;
      static bool l_FirstEnterLoginRange = false;
      if(!l_FirstEnterLoginRange){
        SwitchNextLoading(ELoginRangeTbl::ConnectServer);
        l_FirstEnterLoginRange = true;
      }
      m_LoadImageFinish = true;
    }
  }
  
}

void UILoginView::LoadAudios(){
  // if device.platform == "android" then
  //   for _, data in pairs(gSoundPreload) do
  //     for k, v in pairs(data) do
  //       if v ~= "" then
  //         AudioEngine.preloadEffect(getAudioFileNameByPlatform(v, "Sound"))
  //       end
  //     end
  //   end
  // end
}

void UILoginView::StartGame(){
  LoadCommonImages();
  LoadAudios();
  // gModuleMgr.init()
  StartTimer();
  CheckMaintainInfo();
  // paymentManager.switchBullets()
  // deepLinking.init()
  if(GDevice::Get()->Platform() == EPlatform::Mac || GDevice::Get()->IsForTest()){
    auto l_InputNode = UILoginInput::Create();
    l_InputNode->SetModel(1);
    l_InputNode->setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy));
    _Panel->addChild(l_InputNode, 99);
  }else if(SDKManager::Get()->IsBeta() || SDKManager::Get()->IsGameDevelop()){
    auto l_InputNode = UILoginInput::Create();
    l_InputNode->SetModel(1);
    l_InputNode->setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy));
    _Panel->addChild(l_InputNode, 99);
  }else if(SDKManager::Get()->IsGameService()){
    auto l_InputNode = UILoginInput::Create();
    l_InputNode->SetModel(3);
    l_InputNode->setPosition(Vec2(GDisplay::Get()->cx, GDisplay::Get()->cy));
    _Panel->addChild(l_InputNode, 99);
  }else{
    //   userSDKManager.checkIsEmulator(function(...) userSDKManager.login("")
    //   end, function(...) userSDKManager.login("")  end)
  }
}

void UILoginView::EnterGame(){
  // paymentManager.init()
  // paymentManager.loadProducts()
  // local fConfig = SoraDConfigGet("Game:GetCrashlytics:track~table", {byUID = true})
  // if fConfig.isAgree or userSDKManager.isBeta() or userSDKManager.isGameDevelop() then
  //   userSDKManager.setFabricEnable(true)
  // end
  // local gametop = gModuleMgr.getObject("gametop")
  // local kindomID = gametop.playertop_:getKingdomID() or 0
  // SoraDConfigSet("Game:LoginView:setKingdomID~integer", kindomID)
  ResetSearchMonsterRecord();
  ResetIceHuntingRecord();
  SetStarBuildMiracleLv();
  // local noticeCtrl = gametop.playertop_:getModule("noticeCtrl")
  // noticeCtrl:setLanguage(GameLanguageCopy)
  // notificationManager.removeAllNotification()
  // paymentManager.start2PostGameServer4FinishTransaction()
  // clientEventMgr.initialize()
  // clientEventMgr.getEventStateInfo()
  // local showViewType = self.showViewType
  // local worldMapDefine = include("worldMapDefine")
  // if worldMapDefine.isInWar() or worldMapDefine.isSwitchAnchorMode() then
  //   showViewType = VIEW_TYPE_MAP
  // end
//  auto l_Showtype = new EScene(static_cast<int32>(EScene::City));
//  GBase::DSendMessage("MESSAGE_MAINSCEN_LOGINSUCCESS", l_Showtype);
}

void UILoginView::ResetIceHuntingRecord(){
  auto l_Result = GBase::DConfigGet<GString>("Game:worldMapView:iceHuntingLVRange~string", true);
  if(l_Result && l_Result.value() == "none"){
    l_Result = "1,1";
  }
  GBase::DConfigSet<GString>("Game:worldMapView:iceHuntingLVRange~string", l_Result.value(), true);
}

void UILoginView::ResetSearchMonsterRecord(){
  GBase::DConfigSet<int32>("Game:worldMapView:ResourceType~integer", 0);
  GBase::DConfigSet<int32>("Game:worldMapView:ResourceLV~integer", 0);
  auto l_Result = GBase::DConfigGet<GString>("Game:worldMapView:monsterLVRange~string", true);
  if(l_Result == "none"){
  l_Result = GBase::DConfigGet<GString>("Game:worldMapView:monsterLVRange~string", true);
    if(l_Result != "none"){
      GBase::DConfigSet("Game:worldMapView:monsterLVRange~string", l_Result, true);
    }
  //   local gametop = gModuleMgr.getObject("gametop")
  //   local kingdomMapCtrl = gametop.playertop_:getModule("kingdomMapCtrl")
  //   local min, max = tonumber(kingdomMapCtrl:getMaxCanKillLevel()), tonumber(kingdomMapCtrl:getMaxCanKillLevel())
  //   SoraDConfigSet("Game:worldMapView:monsterLVRange~string", min .. "," .. max, {byUID = true})
  }
  GBase::DConfigSet<bool>("Game:heroMSkillFeedView:refresh~bool", false, true);
  GBase::DConfigSet("Game:getTogetherView:first~bool", true, true);
}

void UILoginView::SetStarBuildMiracleLv(){
  auto l_BidLv = GBase::DGetBuildStarLv(EBuilding::Miracle);
  auto l_CurStarLv = GBase::DConfigGet<int32>("Game:warGemView:starLv~integer", true);
  if(l_CurStarLv == -1){
    GBase::DConfigSet<int32>("Game:warGemView:starLv~integer", l_BidLv.First, true);
  }
}

void UILoginView::LoginSuccess(){
  m_IsServerReturn = true;
  FinishRange(ELoginRangeTbl::ConnectServer);
  StopTimer();
  auto l_Seq = Sequence::create(
    DelayTime::create(0), 
    CallFunc::create([this](){
      EnterGame();
    }), nullptr);
    _Panel->runAction(l_Seq);
}

void UILoginView::CheckMaintainInfo(){
  GBase::DPostCheckMaintain();
}

void UILoginView::StartTimer(){
  StopTimer();
  m_TimerKey = GBase::DCreateTimer(_Panel, CC_CALLBACK_1(UILoginView::UpdateTime, this));
  GBase::DManagerRemoveTimer(m_TimerKey);
}

void UILoginView::StopTimer(){
  if(!m_TimerKey.empty()){
    GBase::DManagerRemoveTimer(m_TimerKey);
    m_TimerKey = "";
  }
}

void UILoginView::UpdateTime(float p_Delta){
  // local gametop = gModuleMgr.getObject("gametop")
  // local playertop_ = gametop.playertop_
  // if playertop_ then
  //   local isdataready = playertop_:IsInitDataReady()
  //   if isdataready == true and self.initFinishCount >= 2 then
  //     self.initFinishCount = 0
    LoginSuccess();
  //   elseif isdataready == false and self.initFinishCount >= 2 then
  //   elseif isdataready and self.initFinishCount == 1 then
  //     dump(self.testArrayImages, "self.testArrayImages", 10)
  //   end
  // end
}

void UILoginView::LoadWhenTheRightRange(ELoginRangeTbl p_Range, float p_Cur){
  if(GetLoadRangeID() == p_Range){
    LoadBar(p_Cur);
  }else{
    if(m_LoginRangeState.Contains(p_Range))
      m_LoginRangeState[p_Range].ready = p_Cur;
  }
}

void UILoginView::SwitchNextLoading(ELoginRangeTbl p_Range){
  static bool l_InitLoadingRange = false;
  if(l_InitLoadingRange){
    RLoginRangeState l_ObbUpdate;
    RLoginRangeState l_ObbValidate;
    RLoginRangeState l_GameUpdate;
    RLoginRangeState l_LoadImages;
    RLoginRangeState l_ConnectServer;
    l_ObbUpdate.ready = 0;
    l_ObbUpdate.StartLang = Translate::i18n("common_text_3853");
    l_ObbUpdate.LoadLang = Translate::i18n("common_text_3853");
    l_ObbUpdate.DoneLang = Translate::i18n("login_text_12");
    l_ObbValidate.ready = 0;
    l_ObbValidate.StartLang = Translate::i18n("login_text_13");
    l_ObbValidate.LoadLang = Translate::i18n("login_text_13");
    l_ObbValidate.DoneLang = Translate::i18n("login_text_15");
    l_GameUpdate.ready = 0;
    l_GameUpdate.StartLang = Translate::i18n("login_text_1");
    l_GameUpdate.LoadLang = Translate::i18n("login_text_2");
    l_GameUpdate.DoneLang = Translate::i18n("login_text_3");
    l_LoadImages.ready = 0;
    l_LoadImages.StartLang = Translate::i18n("login_text_4");
    l_LoadImages.LoadLang = Translate::i18n("login_text_5");
    l_LoadImages.DoneLang = Translate::i18n("login_text_6");
    l_ConnectServer.ready = 0;
    l_ConnectServer.StartLang = Translate::i18n("login_text_7");
    l_ConnectServer.LoadLang = Translate::i18n("login_text_8");
    l_ConnectServer.DoneLang = Translate::i18n("login_text_9");
    m_LoginRangeState[ELoginRangeTbl::ObbUpdate] = l_ObbUpdate;
    m_LoginRangeState[ELoginRangeTbl::ObbValidate] = l_ObbValidate;
    m_LoginRangeState[ELoginRangeTbl::GameUpdate] = l_GameUpdate;
    m_LoginRangeState[ELoginRangeTbl::LoadImages] = l_LoadImages;
    m_LoginRangeState[ELoginRangeTbl::ConnectServer] = l_ConnectServer;
    m_CurLoadingRange = ELoginRangeTbl::GameUpdate;
    l_InitLoadingRange = true;
  }else{
    m_CurLoadingRange = p_Range;
  }
  LoadBar(m_LoginRangeState[m_CurLoadingRange].ready);
  if(0 >= m_LoginRangeState[m_CurLoadingRange].ready){
    LoadBar(0);
    n_TxtNoteTip->setString(m_LoginRangeState[m_CurLoadingRange].StartLang);
  }else{
    n_TxtNoteTip->setString(m_LoginRangeState[m_CurLoadingRange].LoadLang);
  }
}

void UILoginView::FinishRange(ELoginRangeTbl p_Range){
  LoadBar(100);
  if(m_LoginRangeState.Contains(p_Range))
    n_TxtNoteTip->setString(m_LoginRangeState[p_Range].DoneLang);
}

ELoginRangeTbl UILoginView::GetLoadRangeID(){
  return m_CurLoadingRange;
}

void UILoginView::LoadBar(float p_Cur){
  n_TxtPercent->setString(GBase::DFValueSuit(std::to_string(p_Cur), "%"));
  SetPercent(p_Cur);
  if(p_Cur > 0)
    n_TxtNoteTip->setString(m_LoginRangeState[m_CurLoadingRange].LoadLang);
}

void UILoginView::AutoLoadingBar(float  p_EPercent, float p_Frame){
  if(m_LoadImageFinish){
      GString l_ActionLoading;
      auto l_StopTimer = CallFunc::create([this, &l_ActionLoading](){
        if(!l_ActionLoading.empty()){
          GBase::DManagerRemoveTimer(l_ActionLoading);
          l_ActionLoading = "";
        }
        StopTimer();
      });
      m_IsServerReturn = false;
      StopTimer();
      l_ActionLoading = GBase::DCreateTimer(_Panel, [this, p_EPercent](float p_Delta){
        if(this->m_IsServerReturn || GetPercent() > p_EPercent){
          this->StopTimer();
          return;
        }else if(GetPercent() <= p_EPercent){
          this->LoadBar(GetPercent() + p_Delta);
        }
      }, true);
  }
}

float UILoginView::GetPercent(){
  return n_MaskPregress->getContentSize().width / n_ProgressbarBase->getContentSize().width * 100;
}

void UILoginView::SetPercent(float p_Percent){
  n_MaskPregress->setContentSize(Size(n_ProgressbarBase->getContentSize().width * p_Percent / 100, 35));
  n_ProgressPoint->setPositionX(n_ProgressbarBase->getContentSize().width / 2 - n_ProgressbarBase->getContentSize().width * p_Percent / 100);
  n_SpriteAnimationLuotuo->setPositionX(n_ProgressbarBase->getContentSize().width - n_ProgressbarBase->getContentSize().width * p_Percent / 100);
  LoadingBarEffect(p_Percent);
  // SoraDFTarget(self.progressPoint, nil, true)

}

void UILoginView::SetInitCliper(){
  n_TxtPercent = GBase::DGetChildByName<ui::Text *>(_Panel, "Text_percent");
  n_TxtNoteTip = GBase::DGetChildByName<ui::Text *>(_Panel, "Text_loginNote");
  n_ProgressbarLogin = GBase::DGetChildByName<Sprite *>(_Panel, "progressbar_login_2");
  n_MaskPregress = GBase::DGetChildByName<ui::Layout *>(_Panel, "Panel_progress");
  n_MaskPregress->setFlippedX(true);
  n_ProgressPoint = GBase::DGetChildByName<Sprite *>(_Panel, "Sprite_point");
  n_ProgressbarBase = GBase::DGetChildByName<Sprite *>(_Panel, "progressbar_login_base_1");

  //n_AnimationLotuo = static_cast<ActionTimeline *>(n_SpriteAnimationLuotuo->getActionByTag(n_SpriteAnimationLuotuo->getTag()));
  //n_AnimationLotuo->gotoFrameAndPlay(0, true);
  n_MaskPregress->setPositionX(-n_ProgressbarBase->getContentSize().width / 2);
  n_MaskPregress->setScaleX(-1);
  if(GBase::DFIsRA()){
  //   SoraDFTarget(self.progressPoint, nil, true)
    n_MaskPregress->setPositionX(-n_ProgressbarBase->getContentSize().width / 2);
    n_MaskPregress->setScaleX(-1);
  }
  n_TxtPercent->setString("0%");
  // SoraDFTarget(self.progressbar_login, nil, true)
  GVector<Vec2> l_Points = {
    {0, 0}, {0, 0}, {0, 20}, {0, 20}
  };
  RPolygonProps l_Params;
  l_Params.borderWidth = 1;
  auto l_ShapNode = GDisplay::Get()->NewPolygon(l_Points, l_Params);
  n_CliperNode = ClippingNode::create();
  n_CliperNode->setStencil(l_ShapNode);
  n_CliperNode->setInverted(false);
  n_Loading = ParticleSystemQuad::create("Particle/et_kaichangdutiao_01.plist");
  n_Loading->setPosition(Vec2(n_ProgressbarBase->getContentSize().width / 2, 8));
  n_Loading->setPositionType(ParticleSystem::PositionType::FREE);
  n_CliperNode->addChild(n_Loading);
  n_CliperNode->setAnchorPoint(Vec2(1, 0.5));
  n_CliperNode->setPosition(n_ProgressbarBase->getContentSize().width, 10);
  n_CliperNode->setScaleX(-1);
  n_ProgressbarLogin->addChild(n_CliperNode);
}

void UILoginView::SpineAction(){
  auto l_CenterNode = GBase::DGetChildByName<Node *>(_Panel, "Center_Node_Spine");
  l_CenterNode->setLocalZOrder(2);
  l_CenterNode->setPositionY(GDisplay::Get()->rcy);
  if(GBase::Const::Get()->IsArClient){
    if(GBase::GameDefs::Get()->RAMADAN_SWITCH){
      //local criSprite = cc.criSprite.createCriSprite("sp_xndrjm_001.usm", false, true, nil)
      //criSprite:setBlendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA)
      //criSprite:setPosition(0, -(1386 - display.rheight) * 0.2)
      //criSprite:addTo(centerNode)
    }else{
    //     local criSprite = cc.criSprite.createCriSprite("2021loading.usm", false, true, nil)
    //     criSprite:setBlendFunc(gl.SRC_ALPHA, gl.ONE_MINUS_SRC_ALPHA)
    //     criSprite:setPosition(0, -(1386 - display.rheight) * 0.2)
    //     criSprite:addTo(centerNode)
    }
  }else{
    auto l_Display = GDisplay::Get();
    float l_CPosY = l_Display->rheight/2  - (1386 - l_Display->rheight) * 0.2f;
    l_CenterNode->setPosition(Vec2(l_Display->cx, l_CPosY));
    auto l_EtBg = GBase::DCreateAnimationEx("animationLoginBX", nullptr, true, 0.7f);
      n_NodeEvent->addChild(l_EtBg.First, 1);
    l_EtBg.First->setPosition(Vec2(320, l_CPosY));
    auto l_EtLz = GBase::DCreateAnimation("animationLoginBXLZ");
    l_CenterNode->addChild(l_EtLz.First, 1);
    l_EtLz.First->setPosition(Vec2(0, 5));
    // static auto *l_SpineMan = spine::SkeletonAnimation::createWithFile("commonLogin/denglujiemian.skel", "commonLogin/denglujiemian.atlas", 1);
    // l_SpineMan->setPosition(Vec2(5, -l_Display->rheight / 2 - 215 * (1386 - l_Display->rheight) / 426));
    // l_SpineMan->setVisible(false);
    // l_CenterNode->addChild(l_SpineMan);
    // AddEffectLogin();
    // auto l_Seq = Sequence::create(
    //   CallFunc::create([=](){
    //     n_LoginInitBg2->setVisible(true);
    //     n_LoginInitBg->setVisible(false);
    //     l_SpineMan->setVisible(true);
    //     l_SpineMan->setAnimation(0, "animation", true);
    //   }),
    //   nullptr
    // );
    // _Panel->runAction(l_Seq);
  }
}

void UILoginView::InitSpineAnimation(){
  auto l_Seq = Sequence::create(
    DelayTime::create(0),
    CallFunc::create([=](){
      SpineAction();
    }),
    nullptr
  );
  _Panel->runAction(l_Seq);
}

void UILoginView::LoadingBarEffect(float p_Percent){
  GVector<Vec2> l_Points = {
    {0, 0},
    {
      n_ProgressbarBase->getContentSize().width * p_Percent / 100,
      0
    },
    {
      n_ProgressbarBase->getContentSize().width * p_Percent / 100,
      20
    },
    {0, 20}
  };
  RPolygonProps l_Params;
  l_Params.borderWidth = 1;
  auto l_ShapNode = GDisplay::Get()->NewPolygon(l_Points, l_Params);
  n_CliperNode->setStencil(l_ShapNode);
}

void UILoginView::SetKingdomClass(EKingdomClassType p_KingdomClass){
  m_KingdomClass = p_KingdomClass;
}

void UILoginView::SetKingdomClassTips(){
  if(n_TxtWarTips)
    return;
 auto l_StrTips = WorldMapWarDef::Get()->GetKingdomClassTips(m_KingdomClass);
  if(!l_StrTips.empty() || GDevice::Get()->IsForTest()){
    auto l_Tips = GBase::DGetChildByName<ui::Text *>(n_TxtWarTips, "Text_tips");
    l_Tips->setString(Translate::i18n(l_StrTips.c_str()));
    GBase::DSetTextWidthHeight(l_Tips, Size(550, 50));
    n_TxtWarTips->setVisible(true);
  }else{
    n_TxtWarTips->setVisible(false);
  }
}

void UILoginView::AddEffectLogin(){
  //   if not self.effectLogin then
  //   local _shader = require("app.game.loginView.Shader_loginView_shader")
  //   local _meshData = require("app.game.loginView.Shader_loginView_meshData")
  //   local _param = require("app.game.loginView.Shader_loginView_shaderCfg")
  //   local createData = {
  //     meshData = _meshData,
  //     size = cc.size(0, 111),
  //     shader = {
  //       vertBytes = _shader.vertBytes,
  //       fragBytes = _shader.fragBytes
  //     },
  //     param = _param.param,
  //     pos = cc.p(320, 1050),
  //     scale = {x = 0.41600000000000004, y = 0.4498}
  //   }
  //   local meshNode = SoraDCreateMeshNode(createData.meshData, createData.size, createData.shader, createData.param)
  //   meshNode:setPosition(cc.p(createData.pos))
  //   meshNode:setScale(createData.scale.x, createData.scale.y)
  //   meshNode:setBlendFunc(gl.ONE, gl.ONE)
  //   meshNode:addTo(self.loginInitBg2, 99)
  //   self.effectLogin = meshNode
      n_EtStar = ParticleSystemQuad::create("Particle/et_Particle_dljm_001.plist");
      n_EtStar->setScaleX(1.4234f);
      n_EtStar->setScaleY(4.5);
      n_EtStar->setRotation(-109.33f);
      n_EtStar->setPosition(Vec2(501.17f, GDisplay::Get()->rheight + 100));
      _Panel->addChild(n_EtStar, 1);
  // end

  
}


void UILoginView::SetShowViewType(EScene p_Type){
  m_ShowViewType = p_Type;
}

void UILoginView::OnClickUpdateFix(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  // if event == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   require("app.game.updateModule.updateModule"):getInstance():fixUpdateData()
  // end
}