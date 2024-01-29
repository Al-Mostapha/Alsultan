#include "UIBuildingCreateInfoPanel.h"
#include "UIBuildingCreateSingle.h"
#include "Include/IncludeGlobal.h"
#include "Base/Math/Math.Base.h"
#include "Base/Common/Timer.Mgr.h"
#include "Base/Common/Common.Msg.h"
#include "Base/Common/Common.Teml.h"
#include "Base/Common/Common.Box.h"
#include "Base/Common/Common.Func.h"
#include "Game/Common/GamePanel.Mgr.h"
#include "Base/Base.create.h"
#include "Base/Base.Geometry.h"
#include "UIBuildUnlockedSingleInfo.View.h"
#include "Module/Building/Building.Logic.h"
#include "Module/Building/IBuilding.h"
#include "Module/Activity/LuckyBless/LuckyBless.Ctrl.h"
#include "Module/Activity/WiseTutor/WiseTutor.Ctrl.h"
#include "Module/Building/Building.Read.h"
#include "Module/Science/Science.Read.h"
#include "Module/Army/Army.Read.h"
#include "Module/City/City.Func.h"
#include "Module/Effect/Effect.Ctrl.h"
#include "Module/City/City.Cell.h"
#include "Module/Item/Item.Ctrl.h"
#include "Module/UI/Panel/Building/Common/Builder/UIBuilderActivePop.View.h"
#include "Module/UI/Part/Common/Button/UICommonGoldNormalBtn.h"
#include "Module/UI/Part/Common/Resource/UIBuildCreateResBuy.h"
#include "Module/UI/MainUI/UICommonResourcesMenu.h"

float UIBuildingCreateInfoPanel::WELevelProMin = 25;
float UIBuildingCreateInfoPanel::WELevelProMax = 100;

int32 UIBuildingCreateInfoPanel::CAN_BUILD = 0;
int32 UIBuildingCreateInfoPanel::CANT_BY_BUILD = 1;
int32 UIBuildingCreateInfoPanel::CANT_BY_BUILDER = 2;
int32 UIBuildingCreateInfoPanel::CANT_BY_RES = 3;
int32 UIBuildingCreateInfoPanel::CANT_BY_TOOL = 4;
int32 UIBuildingCreateInfoPanel::NEED_BUY_BUILDER = 5;

UIBuildingCreateInfoPanel *UIBuildingCreateInfoPanel::Create(){
  auto l_Panel = Create("UiParts/Panel/Building/Common/buildCreateInfoPanel.csb");
  return l_Panel;
}

void UIBuildingCreateInfoPanel::Ctor(){
  //UIBasePanel::Ctor();
  BindBtnClose();
  // self.tableBuildInfo = {}
  // self.tableScrollSingles = {}
  InitWidget();
  SuitView();
}

void UIBuildingCreateInfoPanel::InitWidget(){
//  local bg = SoraDGetChildByName(self, "Image_bbg")
//  bg:setFillType(1)
  _NodeRescources = GBase::DGetExtendChildFromCCSByName<UICommonResourcesMenu>(this, "CCS_commonResourcesMenu_up");
  _NodeRescources->SetNeedScale(true);
  _LabelDes = GBase::DGetChildByName<ui::Text *>(this, "Text_des");
  _LabelNextLvlValue = GBase::DGetChildByName<ui::Text *>(this, "Text_nextLvValue");
  _LabelNextLvl = GBase::DGetChildByName<ui::Text *>(this, "Text_nextLv");
  _BtnUnlocked = GBase::DGetChildByName<ui::Button *>(this, "Button_unlocked");
  _BtnUnlocked->setVisible(false);
  _BtnUpNow = GBase::DGetExtendChildFromCCSByName<UICommonGoldNormalBtn>(this, "CCS_commonGoldNormalBtn_upNow");

  auto l_ParamInitData = UICommonGoldNormalBtn::RInitDataParm();
  _BtnUpNow->InitData(l_ParamInitData, UICommonGoldNormalBtn::EShowType::Gold);

  _BtnUp = GBase::DGetChildByName<ui::Button *>(this, "Button_up");
  _LabelNeed = GBase::DGetChildByName<ui::Text *>(this, "Text_need");
  _ImageR = GBase::DGetChildByName<ui::ImageView *>(this, "Image_r");
  _ImageL = GBase::DGetChildByName<ui::ImageView *>(this, "Image_l");
  _NodeNameBg = GBase::DGetChildByName<Node *>(this, "Node_nameBg");
  _LabelName = GBase::DGetChildByName<ui::Text *>(this, "Text_name");
  _NodeNeedTime = GBase::DGetChildByName<Node *>(this, "Node_needTime");
  _LabelUpTime = GBase::DGetChildByName<ui::Text *>(this, "Text_upTime");
  _CenterNode = GBase::DGetChildByName<Node *>(this, "Center_Node");
  _BottomNode = GBase::DGetChildByName<Node *>(this, "Bottom_Node");
  _ScrollUp = GBase::DGetChildByName<ui::ScrollView *>(this, "ScrollView_up");
  _ImgLight = GBase::DGetChildByName<ui::ImageView *>(this, "Image_light");
  _ImgFlag = GBase::DGetChildByName<ui::ImageView *>(this, "Sprite_flag");
  _ImgDesBg = GBase::DGetChildByName<ui::ImageView *>(this, "Image_desBg");
  _ImgTime = GBase::DGetChildByName<ui::ImageView *>(this, "Image_time");
  _ImgNameBg = GBase::DGetChildByName<ui::ImageView *>(this, "Image_nameBg");
  _LabelLuckyDay = GBase::DGetChildByName<ui::Text *>(this, "Text_luckyDay");
  _LabelLuckyDay->setVisible(false);
  _LabelFreeTip = GBase::DGetChildByName<ui::Text *>(this, "Text_freeTip");
  _LabelFreeTip->setVisible(false);
  _NodeWiseTutor = GBase::DGetChildByName<Node *>(this, "Node_WiseTutor");
  _TextWiseTime = GBase::DGetChildByName<ui::Text *>(_NodeWiseTutor, "Text_WiseTime");
  GBase::DSetTextWidthHeight(_TextWiseTime, {82, 24});
  _BtnWiseTutor = GBase::DGetChildByName<ui::Button *>(_NodeWiseTutor, "Button_WiseTutor");
  _BtnWiseTutor->addTouchEventListener(CC_CALLBACK_2(UIBuildingCreateInfoPanel::OnWiseTutorClick, this));
  //   self.nodeArtisanHouse = self.nodeWiseTutor:clone()
  //   self.nodeArtisanHouse:setVisible(false)
  //   self.nodeArtisanHouse:setName("Node_artisanHouse")
  //   self.nodeArtisanHouse:addTo(self.nodeWiseTutor:getParent())
  //   self.nodeArtisanHouse:setPositionX(self.nodeWiseTutor:getPositionX() - 100)
  //   self.nodeArtisanHouse:setPositionY(self.nodeWiseTutor:getPositionY())
  //   self.textArtisanTime = SoraDGetChildByName(self.nodeArtisanHouse, "Text_WiseTime")
  //   self.textArtisanTime:setName("Text_ArtisanTime")
  //   self.btnArtisanTutor = SoraDGetChildByName(self.nodeArtisanHouse, "Button_WiseTutor")
  //   self.btnArtisanTutor:setName("Button_ArtisanHouse")
  //   self.btnArtisanTutor:addTouchEventListener(handler(self, self.onArtisanHouseClick))
  //   local pic = SoraDGetChildByName(self.nodeArtisanHouse, "Image_WiseIcon")
  //   pic:loadTexture("icon_artisanhouse_9001368.png", ccui.TextureResType.plistType)
  //   pic:setScale(0.8)
  //   self.btnHelp = SoraDGetChildByName(self, "Button_help")
  _BtnHelp = GBase::DGetChildByName<ui::Button *>(this, "Button_help");
  _BtnHelp->setVisible(false);
  _NodeValue = GBase::DGetChildByName<Node *>(this, "Node_value");
  _LabelCurLvlValue = GBase::DGetChildByName<ui::Text *>(this, "Text_curLvValue");
  _IconWarCur = GBase::DGetChildByName<Sprite *>(this, "icon_warCur");
  _IconWarTo = GBase::DGetChildByName<Sprite *>(this, "icon_warTo");
  _LabelWarPro = GBase::DGetChildByName<ui::Text *>(this, "Text_warPro");
  _LabelWarPro->setString("0%");
  _NodeWar = GBase::DGetChildByName<Node *>(this, "Node_war");
  _ImgWarBg = GBase::DGetChildByName<ui::ImageView *>(this, "Image_warProBg");
  _ImgWarBg->setLocalZOrder(-1);
  _NodeProgressBar = GBase::DGetChildByName<Node *>(this, "Node_progressBar");
  _NodeEffect = GBase::DGetChildByName<Node *>(this, "Node_effect");
  _WarBarTo = GDisplay::Get()->NewProgressTimer("frame_jzjz_jdt2.png", ProgressTimer::Type::RADIAL);
  _WarBarTo->setScaleX(GBase::DFIsRA() ? -1.f : 1.f);
  _WarBarTo->setColor({152, 85, 26});
  _NodeProgressBar->addChild(_WarBarTo);
  _WarBarTo->setPercentage(WELevelProMin + 0.1f * (WELevelProMax - WELevelProMin));
  _WarBarCur = GDisplay::Get()->NewProgressTimer("frame_jzjz_jdt2.png", ProgressTimer::Type::RADIAL);
  _WarBarCur->setScaleX(GBase::DFIsRA() ? -1.f: 1.f);
  _NodeProgressBar->addChild(_WarBarCur);
  _WarBarCur->setPercentage(WELevelProMin);
  _EffectWar = WarLvBarEffect(_NodeEffect);
  _EffectWar->setVisible(false);
  _NodeWar->setVisible(false);
  _LabelCurLvlValue->setVisible(false);
  _IconWarCur->setVisible(false);
  _ImgLight->setVisible(false);
  _ImgLight->setLocalZOrder(1);
  GBase::DGetChildByName<ui::Text *>(this, "Text_nextLv")->setString(Translate::i18n("common_text_280"));
  _LabelNeed->setString(Translate::i18n("common_text_726"));
  _ImageR->setPositionX(_LabelNeed->getPositionX() + _LabelNeed->getContentSize().width/2 + 20);
  _ImageL->setPositionX(_LabelNeed->getPositionX() - _LabelNeed->getContentSize().width/2 - 20);
  _BtnUp->addTouchEventListener(CC_CALLBACK_2(UIBuildingCreateInfoPanel::BtnUpCallBack, this));
  _BtnUpNow->addTouchEventListener(CC_CALLBACK_2(UIBuildingCreateInfoPanel::BtnUpNowCallBack, this));
  _BtnUnlocked->addTouchEventListener(CC_CALLBACK_2(UIBuildingCreateInfoPanel::BtnUnlockedCallBack, this));
  _BtnHelp->addTouchEventListener(CC_CALLBACK_2(UIBuildingCreateInfoPanel::BtnHelpCallBack, this));
  _RadiantNode = AddRadiantDecreeBtn();
  UpdateRadiantDecreeBuff();
}

Node *UIBuildingCreateInfoPanel::AddRadiantDecreeBtn(){
  auto l_Node = GBase::DCreateCSBNode("UiParts/Parts/Common/Node/Node_buff.csb");
  l_Node->setName("Buff_radiantDecree");
  _BottomNode->addChild(l_Node);
  l_Node->setPosition({150, 550});
  _RadiantTime = GBase::DGetChildByName<ui::Text *>(this, "Text_1");
  _RadiantTime->setVisible(false);
  _RadiantBtn = GBase::DGetChildByName<ui::Button *>(this, "Button_1");
  l_Node->setVisible(false);
  _RadiantBtn->addTouchEventListener(CC_CALLBACK_2(UIBuildingCreateInfoPanel::BtnShowRadiantBuff, this));
  return nullptr;
}

void UIBuildingCreateInfoPanel::OnMessageListener(){

  GBase::DAddMessage(this, "MESSAGE_BUILDER_OPEN", CC_CALLBACK_1(UIBuildingCreateInfoPanel::ResUpdate, this));
  GBase::DAddMessage(this, "MESSAGE_RESOURCE_UPDATE", CC_CALLBACK_1(UIBuildingCreateInfoPanel::ResUpdate, this));
  GBase::DAddMessage(this, "MESSAGE_ITEM_COUNT_CHANGE_BAG_BACK", CC_CALLBACK_1(UIBuildingCreateInfoPanel::ResUpdate, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_BADGE_EXCHANGE_BACK", CC_CALLBACK_1(UIBuildingCreateInfoPanel::ResUpdate, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_LUCKY_DAY_UPDATE", CC_CALLBACK_1(UIBuildingCreateInfoPanel::UpdateLuckyBless, this));

  GBase::DAddMessage(this, "MESSAGE_SERVER_LUCKYBLESS_UPDATE", CC_CALLBACK_1(UIBuildingCreateInfoPanel::UpdateLuckyBless, this));
  GBase::DAddMessage(this, "MESSAGE_WISE_TUTOR_REFRESH", CC_CALLBACK_1(UIBuildingCreateInfoPanel::ResUpdate, this));
  GBase::DAddMessage(this, "MESSAGE_CHEAT_BUILD_SUCCESS", CC_CALLBACK_1(UIBuildingCreateInfoPanel::CloseLoading, this));
  GBase::DAddMessage(this, "MESSAGE_ARTISAN_HOUSE_REFRESH", CC_CALLBACK_1(UIBuildingCreateInfoPanel::ResUpdate, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", CC_CALLBACK_1(UIBuildingCreateInfoPanel::JudgeClose, this));
  GBase::DAddMessage(this, "MESSAGE_BUILD_INFO_UPGRADE", CC_CALLBACK_1(UIBuildingCreateInfoPanel::CloseByBuildLock, this));
  GBase::DAddMessage(this, "MESSAGE_SERVER_EVENTCENTER_COMMONEVENT_REFRESH", CC_CALLBACK_1(UIBuildingCreateInfoPanel::UpdateBuff, this));
  GBase::DAddMessage(this, "MESSAGE_MAINCITYVIEW_BUILD_QUEQUE_CALLBACK",[](EventCustom *p_Event){
  //   if self.tableBuildInfo and (data.bid ~= self.tableBuildInfo.buildID.bid or data.iid ~= self.tableBuildInfo.buildID.iid) then
  //     self:resUpdate()
  //   end
  });
}

void UIBuildingCreateInfoPanel::SuitView(){
  _NodeLeft = GBase::DGetChildByName<ui::Layout *>(this, "Center_Panel_left");
  _NodeTop = GBase::DGetChildByName<ui::Layout *>(this, "Top_Panel");
  _NodeBottom = GBase::DGetChildByName<ui::Layout *>(this, "Bottom_Panel");
  _NodeTop->setContentSize({640.0f, GDisplay::Get()->height - (_NodeLeft->getPositionY() + 0.5f * _NodeLeft->getContentSize().height)});
  _NodeBottom->setContentSize({640.f, _NodeLeft->getPositionY() - 0.5f * _NodeLeft->getContentSize().height});
  _CenterNode->setPositionY(std::max(450.0f, GDisplay::Get()->height / 2));
  _LabelWarPro->setPositionY(GDisplay::Get()->height < 960 ? 90 : 140);
}

void UIBuildingCreateInfoPanel::InitUpgradeData(IBuilding *p_Building){
  // local _iscanupgrade, retdata = buildLogic.isCanUpgrade(buildID.bid, buildID.iid)
  auto l_Pair = BuildingLogic::Get()->IsCanUpgrade(p_Building->GetBuildingIndex());
  bool l_Iscanupgrade = l_Pair.First;
  auto l_RetData = l_Pair.Second;
  if(l_RetData._Valid){
    _TableBuildInfo._BuildId._Bid = p_Building->GetBuildingId();
    _TableBuildInfo._BuildId._IID = p_Building->GetBuildingIndex();
    _TableBuildInfo._BuildData = l_RetData;
    _TableBuildInfo._BuildType._BuildIndex = p_Building->getParent()->getTag();
    _ViewType = EBuildingOperateType::Upgrade;
    UpdateLuckyBless();
    UpdateWiseTutorBuff();
    UpdateArtisanHouseBuff();
    UpdateView();
    InitUpgradeView();
  }
}

void UIBuildingCreateInfoPanel::InitBuildData(const RBuildCreateInfoInitData &pData){
  _TableBuildInfo._BuildId._Bid = pData._BuildId;
  _TableBuildInfo._BuildId._IID = pData._BuildType._BuildIndex;
  _TableBuildInfo._BuildType._BuildIndex = (int32)pData._BuildType._BuildIndex;
  _ViewType = EBuildingOperateType::Build;
  UpdateView();
  InitBuildView();
}

void UIBuildingCreateInfoPanel::UpdateLuckyBless(EventCustom *p_Event){
  auto l_LBEffect = LuckyBlessCtrl::Get()->GetCurEffectType();
  if(l_LBEffect == ELuckyBlessEffect::BuildingUpgrade 
    && _ViewType == EBuildingOperateType::Upgrade){
    if(_LuckyBlessTimer.empty()){
      OpenLuckyTime(0.f);
      _LuckyBlessTimer = GBase::DCreateTimer(this, CC_CALLBACK_1(UIBuildingCreateInfoPanel::OpenLuckyTime, this));
    }
    _LabelLuckyDay->setVisible(true);
    _LuckyBlessIsOpen = true;
    }else{
      if(!_RadiantDecreeIsOpen){
        //     for i, v in ipairs(self.tableScrollSingles) do
        //       v:luckBlessOpen(false)
        //     end
      }
      _LabelLuckyDay->setVisible(false);
      _LuckyBlessIsOpen = false;
    }
}

void UIBuildingCreateInfoPanel::UpdateWiseTutorBuff(){
  
  auto l_State = WiseTutorCtrl::Get()->GetStateInfo();
  if(l_State.First == EActivityState::Open){
    _WiseTutorIsOpen = WiseTutorCtrl::Get()->IsBuffEffect();
    _NodeWiseTutor->setVisible(true);
    _TextWiseTime->setVisible(_WiseTutorIsOpen);
    if(l_State.Second > 0 && _WiseTutorIsOpen){
      OpenWiseTutorTime(0);
      _WiseTutorTimer = GBase::DCreateTimer(this, CC_CALLBACK_1(UIBuildingCreateInfoPanel::OpenWiseTutorTime, this));
    }
    GBase::DSetGray(GBase::DGetChildByName<ui::ImageView *>(this, "Image_WiseIcon"), !_WiseTutorIsOpen);
  }else{
  //   for i, v in ipairs(self.tableScrollSingles) do
  //     v:luckBlessOpen(false)
  //   end
  //   self.nodeWiseTutor:setVisible(false)
  //   self.wiseTutorIsOpen = false
  }
  AdjustWiseArtisanBuffPos();
}

void UIBuildingCreateInfoPanel::OpenLuckyTime(float p_Dt){
  // local luckyData = luckyBlessCtrl:getLuckyData()
  // local leftTime = luckyBlessCtrl:getRealTime()
  // self.labelLuckyDay:setString(i18n("lucky_text_18", {
  //   num = string.format("%d%%", luckyData.discount / 10),
  //   time = SoraDConvertSecondToString(leftTime)
  // }))
  // if leftTime <= 0 or not self.luckyBlessIsOpen then
  //   SoraDManagerRemoveTimer(self, self.luckyBlessTimer)
  //   self.luckyBlessTimer = nil
  // end
}

void UIBuildingCreateInfoPanel::UpdateArtisanHouseBuff(){
  // local state, leftTime = artisanHouseCtrl:getStateInfo()
  // if state == gActivityState.OPEN then
  //   self.artisanHouseIsOpen = artisanHouseCtrl:isBuffEffect()
  //   self.nodeArtisanHouse:setVisible(true)
  //   self.textArtisanTime:setVisible(self.artisanHouseIsOpen)
  //   if leftTime > 0 and self.artisanHouseIsOpen then
  //     self:openArtisanHouseTime()
  //     self.artisanHouseTimer = SoradCreateTimer(self, handler(self, self.openArtisanHouseTime))
  //   end
  //   SoraDSetGray(SoraDGetChildByName(self.nodeArtisanHouse, "Image_WiseIcon"), not self.artisanHouseIsOpen)
  // else
  //   for i, v in ipairs(self.tableScrollSingles) do
  //     v:luckBlessOpen(false)
  //   end
  //   self.nodeArtisanHouse:setVisible(false)
  //   self.artisanHouseIsOpen = false
  // end
  // self:adjustWiseArtisanBuffPos()
}

void UIBuildingCreateInfoPanel::UpdateView(){
  
  auto l_IsVisible = _ViewType == EBuildingOperateType::Upgrade || _ViewType == EBuildingOperateType::UpgradeStar;
  _LabelNextLvlValue->setVisible(l_IsVisible);
  _LabelNextLvl->setVisible(l_IsVisible);
  _LabelDes->setVisible(!l_IsVisible);
  if(_LabelNextLvl->isVisible()){
    _ImgDesBg->setPositionY(-75);
    _ImgFlag->setContentSize({_ImgFlag->getContentSize().width, 292});
    _ImgDesBg->setContentSize({_ImgDesBg->getContentSize().width, 196});
    _LabelDes->setPositionY(-85);
  }else{
    _ImgDesBg->setPositionY(-25);
    _ImgFlag->setContentSize({_ImgFlag->getContentSize().width, 292});
    _ImgDesBg->setContentSize({_ImgDesBg->getContentSize().width, 246});
    _LabelDes->setPositionY(-35);
  }
  if(_ViewType != EBuildingOperateType::Unlock){
    _BtnUpNow->SetGoldText(GStringUtils::FormatK(_TableBuildInfo._BuildData._ImmediatelyGold));
    _LabelUpTime->setString(GBase::DConvertSecondToString(_TableBuildInfo._BuildData._CostTime));
    if(_NodeNeedTime){
      _NodeNeedTime->setVisible(true);
      GBase::DToCenter(_NodeNeedTime);
    }
    
    auto l_FreeTime = BuildingLogic::Get()->GetFreeSpeedUpTime();
    if(_ViewType == EBuildingOperateType::Upgrade){
      auto l_BuildingCell = CityCtrl::Get()->GetBuildingCell(_TableBuildInfo._BuildId._Bid,_TableBuildInfo._BuildId._IID);
      l_FreeTime = BuildingLogic::Get()->GetFreeSpeedUpTime(l_BuildingCell->_Info.buildingLvl);
    }
    _IsFree = l_FreeTime >= _TableBuildInfo._BuildData._CostTime;
    SetBtnUpNowState();
  }else{
    if(_NodeNeedTime)
      _NodeNeedTime->setVisible(false);
    else
      _LabelUpTime->setVisible(false);
    _BtnUpNow->setVisible(false);
    _ImgTime->setVisible(false);
    _BtnUp->setPositionX(320);
  }
  SetBuildBtnTouchEnable(true);
  InitScroll();
  SetSpecail();
}

void UIBuildingCreateInfoPanel::SetBtnUpNowState(){
  if(_ViewType == EBuildingOperateType::Upgrade || _ViewType == EBuildingOperateType::Build){
    if(_IsFree && _IsEnough){
      _BtnUpNow->SetGoldText(Translate::i18n("common_text_049"));
      float l_FreeTime = BuildingLogic::Get()->GetFreeSpeedUpTime();
      if(_ViewType == EBuildingOperateType::Upgrade){
        auto l_BuildingCell = CityCtrl::Get()->GetBuildingCellByIndex(_TableBuildInfo._BuildId._IID);
        l_FreeTime = BuildingLogic::Get()->GetFreeSpeedUpTime(l_BuildingCell->_Info.buildingLvl);
      }
      l_FreeTime = std::floor(l_FreeTime / 60);
      _LabelFreeTip->setString(Translate::i18n("common_text_3821",{{"time", std::to_string(l_FreeTime)}}));
      _LabelFreeTip->setVisible(true);
      //     if not SoraDIsGameGuide() and not self.haveFreeMild then
      //       self.haveFreeMild = true
      //       gModuleMgr.sharedMgr("mildGuideManager"):drawFingerToTarget(self.btnUpNow.Button_normal, {z = 2})
      //     end
    }else{
      if(_HaveFreeMild){
        //       gModuleMgr.sharedMgr("mildGuideManager"):clean()
        //       self.haveFreeMild = false
      }
      _LabelFreeTip->setVisible(false);
    }
  }
}

void UIBuildingCreateInfoPanel::InitUnlockView(){
  _LabelDes->setString(Translate::i18n("common_text_741"));
  _BtnUp->setTitleText(Translate::i18n("common_text_740"));
  _NodeNameBg->setVisible(false);
}

void UIBuildingCreateInfoPanel::InitBuildView(){
  if(_TableBuildInfo._BuildId._Bid == EBuilding::Miracle){
    _LabelDes->setString(BuildingRead::Get()->GetBrief(_TableBuildInfo._BuildId._Bid));
    GBase::DSendMessage(
      "MESSAGE_MAINCITYVIEW_ADD_BUILD_PREVIEW",
      &_TableBuildInfo._BuildId._IID);
  }else{
    _LabelDes->setString(BuildingRead::Get()->GetDes(_TableBuildInfo._BuildId._Bid));
  }
  _BtnUp->setTitleText(Translate::i18n("common_text_042"));
  _BtnUpNow->SetTitleStr(Translate::i18n("common_text_379"));
  _LabelName->setString(BuildingRead::Get()->GetName(_TableBuildInfo._BuildId._Bid));
  _NodeNameBg->setPositionY(260);
}

void UIBuildingCreateInfoPanel::RunActClose(){
  runAction(Sequence::create(
    DelayTime::create(0.01),
    CallFunc::create([this](){
      this->ClosePanel();
    }),
    nullptr
  ));
}

void UIBuildingCreateInfoPanel::InitUpgradeView(){
  
  auto l_BuildingCell = CityCtrl::Get()->GetBuildingCellByIndex(_TableBuildInfo._BuildId._IID);
  auto l_Ret = BuildingLogic::Get()->IsBuildWarLv(l_BuildingCell->_Info.buildingLvl);
  if(l_Ret._IsWar){
    auto l_IId = _TableBuildInfo._BuildId._IID;
    auto lBid = _TableBuildInfo._BuildId._Bid;
    if(BuildingLogic::Get()->BuildLvIsFull(lBid, l_IId) || BuildingLogic::Get()->IsBuildingUnlock(lBid, l_IId)){
      RunActClose();
      return;
    }
    _WarLvl = l_Ret._WarLvl;
    _WarCurPro = l_Ret._Progress;
    _WarToLvl = BuildingLogic::Get()->TransFormBuildLvToWarLv(l_BuildingCell->_Info.buildingLvl + 10);
    if(_ImgDesBg->getChildrenCount() > 0)
      _ImgDesBg->removeAllChildren();
    _BtnUnlocked->setVisible(false);
    InitWarView();
  } else {
    auto l_UpgradeDes = BuildingRead::Get()->GetUpgradeDes(_TableBuildInfo._BuildId._Bid);
    if(!l_UpgradeDes.empty()){
      _LabelDes->setVisible(true);
      _LabelDes->setString(l_UpgradeDes);
      ShowUnlockedInfo();
    }
    InitUpgradeDes(true);
    _LabelCurLvlValue->setString("");
    _LabelNextLvlValue->setColor(GDisplay::Get()->COLOR_WHITE);
    _IconWarCur->setVisible(false);
    _LabelNextLvlValue->setString(std::to_string(l_BuildingCell->_Info.buildingLvl + 1));
    _LabelName->setString(
      BuildingRead::Get()->GetName(_TableBuildInfo._BuildId._Bid) + "\n" 
      + Translate::i18n("common_text_420", {{"level", std::to_string(l_BuildingCell->_Info.buildingLvl)}})
      );
    _NodeNameBg->setPositionY(260);
    _NodeWar->setVisible(false);
    GBase::DToCenter(_NodeValue);
  }
  _BtnUp->setTitleText(Translate::i18n("common_text_055"));
  _BtnUpNow->SetTitleStr(Translate::i18n("common_text_378"));
}

void UIBuildingCreateInfoPanel::InitWarView(){
  // self.nodeWar:setVisible(true)
  // self.labelCurLvValue:setVisible(true)
  // self.icon_warCur:setVisible(self.warLv > 0)
  // self.btnHelp:setVisible(true)
  // local totalPro = WELevelProMax - WELevelProMin
  // if self.warLv > 0 then
  //   self.icon_warCur:setSpriteFrame(SoraDGetLvImg(self.warLv))
  // end
  // self.icon_warTo:setSpriteFrame(SoraDGetLvImg(self.warToLv))
  // self.labelName:setString(buildRead.getName(self.tableBuildInfo.buildID.bid))
  // self.nodeNameBg:setPositionY(-30)
  // self.labelDes:setVisible(true)
  // self.labelDes:setString(i18n("buildDes_upgrade_brief_301"))
  // self.labelCurLvValue:setString(tostring(self.warCurPro * 100) .. "%")
  // self.labelNextLvValue:setString(i18n("common_text_1952", {value = "10%"}))
  // self.labelNextLvValue:setColor(display.COLOR_GREEN)
  // self.labelCurLvValue:setPositionX(self.labelNextLvValue:getPositionX() + SoraDFSign(self.labelCurLvValue:getContentSize().width + 2))
  // SoraDToCenter(self.nodeValue)
  // local delay = 0.8
  // local starP = self.warBarCur:getPercentage()
  // local curP = self.warCurPro * totalPro + WELevelProMin
  // local toP = (self.warCurPro + 0.1) * totalPro + WELevelProMin
  // local perP = (curP - starP) / (60 * delay)
  // local _R = 14
  // if self.firstRunWar then
  //   self.firstRunWar = false
  //   self.effectWar:getChildByName("effect1"):resetSystem()
  //   self.effectWar:getChildByName("effect2"):resetSystem()
  //   self:stopAllActionsByTag(1)
  //   local warAction = cca.seq({
  //     cca.delay(0.3),
  //     cca.callFunc(function(...)
  //       if self.warTimer then
  //         SoraDManagerRemoveTimer(self, self.warTimer)
  //         self.warTimer = nil
  //       end
  //       self.warTimer = SoradCreateTimer(self, function(...)
  //         local realCurP = self.warBarCur:getPercentage()
  //         if perP > 0 and realCurP < curP or perP < 0 and realCurP > curP then
  //           self.warBarCur:setPercentage(self.warBarCur:getPercentage() + perP)
  //         end
  //         local angle = self.warBarCur:getPercentage()
  //         realCurP = self.warBarCur:getPercentage()
  //         self.effectWar:setVisible(true)
  //         local realAngle = angle - WELevelProMin
  //         if SoraDFIsRA() then
  //           self.effectWar:setPosition(cc.p(145, -85))
  //           local offset = -3.2 * realAngle / (-120 / _R) - _R
  //           if -3.2 * realAngle / (-120 / _R) == 0 then
  //             offset = 0
  //           end
  //           self.nodeEffect:setRotation(-3.2 * realAngle - offset)
  //         else
  //           self.effectWar:setPosition(cc.p(-145, -85))
  //           local offset = -3.2 * realAngle / (120 / _R) + _R
  //           if -3.2 * realAngle / (120 / _R) == 0 then
  //             offset = 0
  //           end
  //           self.nodeEffect:setRotation(3.2 * realAngle - offset)
  //         end
  //         if 0 < self.warCurPro or perP < 0 and self.warCurPro == 0 then
  //           self.labelWarPro:setString(tostring(math.floor(self.warCurPro * 100 * realCurP / curP)) .. "%")
  //         end
  //         local realToP = self.warBarTo:getPercentage()
  //         if perP > 0 and realToP < toP or perP < 0 and realToP > toP then
  //           self.warBarTo:setPercentage(self.warBarTo:getPercentage() + perP)
  //         end
  //         if perP == 0 or perP < 0 and self.warBarTo:getPercentage() <= toP and self.warBarCur:getPercentage() <= curP or perP > 0 and self.warBarTo:getPercentage() >= toP and self.warBarCur:getPercentage() >= curP then
  //           self.labelWarPro:setString(tostring(self.warCurPro * 100) .. "%")
  //           SoraDManagerRemoveTimer(self, self.warTimer)
  //           self.effectWar:getChildByName("effect1"):stopSystem()
  //           self.effectWar:getChildByName("effect2"):stopSystem()
  //           self.warTimer = nil
  //         end
  //       end, true)
  //     end)
  //   })
  //   warAction:setTag(1)
  //   self:runAction(warAction)
  // end
}

void UIBuildingCreateInfoPanel::ShowUnlockedInfo(){
  auto l_BuildingCell = CityCtrl::Get()->GetBuildingCellByIndex(_TableBuildInfo._BuildId._IID);
  auto l_NextUnloacked = BuildingRead::Get()->GetNextUnlockedInfo(_TableBuildInfo._BuildId._Bid, l_BuildingCell->_Info.buildingLvl);
  if(l_NextUnloacked._Valid){
    _LabelDes->setTextVerticalAlignment(TextVAlignment::TOP);
    if(l_NextUnloacked._unlockLvl == l_BuildingCell->_Info.buildingLvl + 1){
      _LabelDes->setString(Translate::i18n("common_text_1150"));
    }else{
      _LabelDes->setString(Translate::i18n("common_text_1151", {{"blv", std::to_string(l_NextUnloacked._unlockLvl)}}));
    }
    GString l_BtnImgName;
    auto l_posY = -190.f;
    auto l_Width = 106.f;
    if(l_NextUnloacked._Building != EBuilding::None){
      l_BtnImgName = BuildingRead::Get()->GetIcon(l_NextUnloacked._Building);
      _TableBuildInfo._BuildId._UnlockedId = static_cast<int32>(l_NextUnloacked._Building);
      l_Width = 140;
    }else if(l_NextUnloacked._Science != EScience::None){
      l_BtnImgName = ScienceRead::Get()->GetIcon(l_NextUnloacked._Science);
      _TableBuildInfo._BuildId._UnlockedId = static_cast<int32>(l_NextUnloacked._Science);
      l_Width = 140;
    } else if(l_NextUnloacked._Army != EArmy::None){
      l_BtnImgName = ArmyRead::Get()->GetIcon(l_NextUnloacked._Army);
      _TableBuildInfo._BuildId._UnlockedId = static_cast<int32>(l_NextUnloacked._Army);
      l_posY = -190;
    }
    _BtnUnlocked->setVisible(false);
    if(!l_BtnImgName.empty()){
      _BtnUnlocked->loadTextures(l_BtnImgName, l_BtnImgName, l_BtnImgName, Widget::TextureResType::PLIST);
      _BtnUnlocked->setScale(l_Width / _BtnUnlocked->getContentSize().height);
      _BtnUnlocked->setPositionY(l_posY);
      _BtnUnlocked->setVisible(true);
    }
  }else{
    _LabelDes->setTextVerticalAlignment(TextVAlignment::CENTER);
    _BtnUnlocked->setVisible(false);
  }
}

void UIBuildingCreateInfoPanel::SetFlagSizeDes(float p_TotalHeight, GVector<Node *> p_Nodes){
  _ImgFlag->setContentSize({212.f, std::max(292.f, p_TotalHeight + 160.f)});
  _ImgDesBg->setContentSize({176.f, std::max(196.f, p_TotalHeight + 60)});
  auto l_BeginY = _ImgDesBg->getContentSize().height;
  auto l_LabelH = 20.f;
  auto l_Line = 0;
  bool l_IsSameLine = false;
  for(auto iii = 0 ; iii < p_Nodes.size(); iii++){
    //TODO: if lua array start with 1 not 0 the 3 should be 4
    if(iii % 3 == 1){
      l_Line ++;
    } else if(!l_IsSameLine){
      l_Line ++;
      l_IsSameLine = true;
    }
    p_Nodes[iii]->setPosition({88.f, l_BeginY * l_Line});
    _ImgDesBg->addChild(p_Nodes[iii]);
  }
}

void UIBuildingCreateInfoPanel::InitUpgradeDes(bool p_UpDes, bool p_IsStar){
  
  _ImgDesBg->removeAllChildren();
  if(p_UpDes){
    _ImgFlag->setContentSize({212.f, 292.f});
    _ImgDesBg->setContentSize({176.f, 196.f});
    return;
  }
  
  auto l_TableUpData = BuildingRead::Get()->GetUpgradeInfoData(_TableBuildInfo._BuildId._IID, p_IsStar);
  auto l_LabelH = 20.f;
  auto l_TotalHeight = 0.f;
  GVector<Node *> l_LabelArray;
  for(auto v : l_TableUpData){
  auto l_LabelTitle = dynamic_cast<ui::Text *>(_LabelNextLvlValue->clone());
  l_LabelTitle->setFontSize(18);
  l_LabelTitle->setTextAreaSize({170.f, l_LabelH});
  auto l_LabelValue = dynamic_cast<ui::Text *>(_LabelCurLvlValue->clone());
  l_LabelValue->setFontSize(16);
  l_LabelValue->setTextAreaSize({170.f, l_LabelH});
  auto l_LabelPlusValue = dynamic_cast<ui::Text *>(_LabelNextLvlValue->clone());
  l_LabelPlusValue->setFontSize(16);
  l_LabelPlusValue->setTextAreaSize({170.f, l_LabelH});
  l_LabelTitle->setString(v._Title);
  l_LabelTitle->setAnchorPoint({.5f, 1.f});
  l_LabelTitle->setTextHorizontalAlignment(TextHAlignment::CENTER);
  l_LabelTitle->setColor({215, 195, 155});
  l_TotalHeight += l_LabelH;
  l_LabelArray.emplace_back(l_LabelTitle);
  l_LabelValue->setString(v._Value);
  l_LabelValue->setAnchorPoint({1.f, 1.f});
  l_LabelValue->setTextHorizontalAlignment(TextHAlignment::RIGHT);
  l_LabelValue->setColor({255, 255, 255});
  l_LabelArray.emplace_back(l_LabelValue);
  l_LabelPlusValue->setString(v._PlusValue);
  l_LabelPlusValue->setAnchorPoint({0.f, 1.f});
  l_LabelPlusValue->setTextHorizontalAlignment(TextHAlignment::LEFT);
  l_LabelPlusValue->setColor({0, 190, 30});
  l_TotalHeight += l_LabelH;
  l_LabelArray.emplace_back(l_LabelPlusValue);
  }
  SetFlagSizeDes(l_TotalHeight, l_LabelArray);
}

void UIBuildingCreateInfoPanel::InitUnlockData(ELockedArea p_Area){
  // local cityltCtrl = include("cityltCtrl")
  // local retCostRes = {
  //   _retCostRes = {},
  //   _retPreCond = {},
  //   _retCostTools = {},
  //   _buildQueueList = {},
  //   _retCostWEs = {}
  // }
  // local costres = cityltCtrl.getOpenGoundInfo(areaid, "costRes")
  // if costres then
  //   for i = 1, #costres / 2 do
  //     local _resid = costres[2 * i - 1]
  //     local _rescount = costres[2 * i]
  //     local _curcount = cityCtrl:getResCount(_resid)
  //     if _rescount > 0 then
  //       local _isreach = true
  //       if _rescount > _curcount then
  //         _isreach = false
  //       end
  //       table.insert(retCostRes._retCostRes, {
  //         resid = _resid,
  //         rescount = _rescount,
  //         curcount = _curcount,
  //         isreach = _isreach
  //       })
  //     end
  //   end
  // end
  // self.tableBuildInfo = {areaid = areaid, buildData = retCostRes}
  // self.viewType = BUILD_OPERATE_TYPE.UNLOCK
  // self:updateView()
  // self:initUnlockView()
  // if self.btnUp:isVisible() and SoraDIsGameGuide() == nil then
  //   local guideCtrl = gametop.playertop_:getModule("guideCtrl")
  //   guideCtrl:updateGuideModule(gGuideModule.AREA_UNLOCK)
  // end
}

GPair<bool, int32> UIBuildingCreateInfoPanel::ScreenQueueList(){
  auto _QListCount = _TableBuildInfo._BuildData._BuildingTaskQueue.size();
  if(_QListCount == 0)
    return GPair<bool, int32>(true, _QListCount);
  else if(_QListCount == 1){
    auto _Ret =BuildingLogic::Get()->GetIdleBuildQueue();
    if(_Ret.First != ETask::None){
      _TableBuildInfo._BuildData._BuildingTaskQueue.clear();
      return GPair<bool, int32>(true, 0);
    }
    return GPair<bool, int32>(true, _QListCount);
  }
  return GPair<bool, int32>(false, _QListCount);
}

void UIBuildingCreateInfoPanel::InitScroll(){
  //   local needNebulaTower = self.tableBuildInfo.buildData._retPreNebulaTower and 1 or 0
  auto _NeedNebulaTower  = 0;
  auto _NeedWECount = _TableBuildInfo._BuildData._CostItemWEs.size();
  auto _PreCondCount = _TableBuildInfo._BuildData._PreCond.size();
  auto _NeedToolCount = _TableBuildInfo._BuildData._CostItem.size();
  auto _QShowListCount = 0;
  auto _ISMet = 0;
  auto _IsReach = true;
  auto _Temp = ScreenQueueList();
  auto _IsFreeQ = _Temp.First;
  auto _QCount = _Temp.Second;
  if(!_IsFreeQ)
    _QShowListCount = _QCount;
  auto _retCostCount = _TableBuildInfo._BuildData._CostResource.size();
  auto _InfoCount = _PreCondCount + _NeedToolCount + _QShowListCount + _retCostCount + _NeedWECount ;
  auto _ScrollSize = _ScrollUp->getContentSize();
  _SingleH = _ScrollSize.height/5;
  if(_InfoCount > 5)
    _SingleH = _SingleH - _SingleH *.3/5;
  auto _ScrollH = std::max(_InfoCount * _SingleH, _ScrollSize.height);
  _ScrollUp->setInnerContainerSize({_ScrollSize.width, _ScrollH});
  for(auto iii = 0; iii < (int32)_TableBuildInfo._BuildData._CostResource.size(); iii++){
    auto v = _TableBuildInfo._BuildData._CostResource[iii];
    bool l_LuckyIsReach = false;
    auto l_WiseTutorIsReach = false;
    auto l_ArtisanHouseisReach = false;
    auto l_RadiantIsReach = false;
    auto l_SingleInfo =  UIBuildingCreateSingle::Create();
    auto l_Count = iii + _NeedNebulaTower + _NeedToolCount + _PreCondCount + _QShowListCount + _NeedWECount - 1;
    l_SingleInfo->setPosition({280.f, _ScrollH - (l_Count -1 ) * _SingleH});
    auto l_Param = UIBuildingCreateSingle::RBuildingCondData();
    l_Param._ResCount = v._ResCount;
    l_Param._Resid = v._ResId;
    l_Param._CurCount = v._CurCount;
    l_Param._IsNormal = true;
    l_SingleInfo->InitData(
      UIBuildingCreateSingle::EBuildingCondType::Res,
      l_Param
    );
    l_SingleInfo->SetBtnCallBack(CC_CALLBACK_1(UIBuildingCreateInfoPanel::ScrollSingleCallBack, this));
    l_SingleInfo->SetScroll(_ScrollUp);
    _ScrollUp->addChild(l_SingleInfo);
    _TableScrollSingles.push_back(l_SingleInfo);
    if(_LuckyBlessIsOpen)
      l_LuckyIsReach = true;
    if(_WiseTutorIsOpen)
      l_WiseTutorIsReach = l_SingleInfo->LuckBlessOpen(true);
    if(_ArtisanHouseIsOpen)
      l_ArtisanHouseisReach = l_SingleInfo->LuckBlessOpen(true);
    if(_RadiantDecreeIsOpen)
      l_RadiantIsReach = l_SingleInfo->RadiantBlessOpen(true);
    if(!l_SingleInfo->GetIsMet())
      _ISMet = false;
    if(!v._IsReach && !l_LuckyIsReach && !l_WiseTutorIsReach && !l_ArtisanHouseisReach && !l_RadiantIsReach){
      _BuildType = CANT_BY_RES;
      if(_ViewType == EBuildingOperateType::Unlock)
        _IsReach = false;
    }
  }
  _IsSpecialReach = true;
  for(int32 iii = 0; _TableBuildInfo._BuildData._CostItem.size(); iii++){
    auto v = _TableBuildInfo._BuildData._CostItem[iii];
    auto l_SingleInfo = UIBuildingCreateSingle::Create();
    auto l_Count = iii + _NeedNebulaTower  + _PreCondCount + _QShowListCount + _NeedWECount - 1;
    l_SingleInfo->setPosition({280.f, _ScrollH - (l_Count -1 ) * _SingleH});
    auto l_Param = UIBuildingCreateSingle::RBuildingCondData();
    l_Param._ItemCount = v._ItemCount;
    l_Param._CurCount = v._CurCount;
    l_Param._IdItem = v.idItem;
    l_SingleInfo->InitData(
      UIBuildingCreateSingle::EBuildingCondType::Tool,
      l_Param
    );

    l_SingleInfo->SetBtnCallBack(CC_CALLBACK_1(UIBuildingCreateInfoPanel::ScrollSingleCallBack, this));
    l_SingleInfo->SetScroll(_ScrollUp);
    _ScrollUp->addChild(l_SingleInfo);
    _TableScrollSingles.push_back(l_SingleInfo);
    if(!l_SingleInfo->GetIsMet())
      _ISMet = false;
    if(!v._IsReach){
      _IsSpecialReach = false;
      _BuildType = CANT_BY_TOOL;
    }
  }
  for(auto iii = 0 ; iii < _TableBuildInfo._BuildData._CostItemWEs.size(); iii++){
    auto v  = _TableBuildInfo._BuildData._CostItemWEs[iii];
    auto l_SingleInfo = UIBuildingCreateSingle::Create();
    auto l_Count = iii + _NeedNebulaTower  + _PreCondCount + _QShowListCount  - 1;
    l_SingleInfo->setPosition({280.f, _ScrollH - (l_Count -1 ) * _SingleH});
    auto l_Param = UIBuildingCreateSingle::RBuildingCondData();
    l_Param._ItemCount = v._ItemCount;
    l_Param._CurCount = v._CurCount;
    l_Param._IdItem = v.idItem;
    l_SingleInfo->InitData(
      UIBuildingCreateSingle::EBuildingCondType::We,
      l_Param
    );
    l_SingleInfo->SetBtnCallBack(CC_CALLBACK_1(UIBuildingCreateInfoPanel::ScrollSingleCallBack, this));
    l_SingleInfo->SetScroll(_ScrollUp);
    _ScrollUp->addChild(l_SingleInfo);
    _TableScrollSingles.push_back(l_SingleInfo);
    if(!l_SingleInfo->GetIsMet())
      _ISMet = false;
    if(!v._IsReach){
      _NeedWarBadgeBuy = v._ItemCount - v._CurCount;
      _NeedWarBadgeID = v.idItem;
      _IsSpecialReach = false;
      _BuildType = CANT_BY_TOOL;
    }
  }

  for(auto iii = 0; iii < _TableBuildInfo._BuildData._BuildingTaskQueue.size(); iii++){
    auto v  = _TableBuildInfo._BuildData._BuildingTaskQueue[iii];
    auto l_SingleInfo = UIBuildingCreateSingle::Create();
    auto l_Count = iii  - 1;
    l_SingleInfo->setPosition({280.f, _ScrollH - (l_Count -1 ) * _SingleH});
    auto l_Param = UIBuildingCreateSingle::RBuildingCondData();
    l_Param._QType = v.TaskType;
    l_Param._BLvl = v._BuildingLvl;
    l_Param._Data._Bid = v.BuildingType;
    l_Param._Data._Iid = v.BuildingIndex;
    l_Param._Data._Task = v;
    l_SingleInfo->InitData(
      UIBuildingCreateSingle::EBuildingCondType::Time,
      l_Param
    );
    l_SingleInfo->SetScroll(_ScrollUp);
    _ScrollUp->addChild(l_SingleInfo);
    _TableScrollSingles.push_back(l_SingleInfo);
    auto l_Queue = TaskCtrl::Get()->QueryQueue(ETask::charge_build_queue);
    if(!l_Queue)
      _BuildType = NEED_BUY_BUILDER;
    else 
      _BuildType = CANT_BY_BUILDER;
  }
//   if self.tableBuildInfo.buildData._retPreNebulaTower then
//     local singleInfo = SoraDCreatePanel("buildCreateSingle")
//     singleInfo:setPosition(cc.p(280, scrollH - (needNebulaTower + queueShowListCount) * self.singleH))
//     singleInfo:initData({
//       singleType = BUILD_CONDITION_TYPE_NEBULATOWER,
//       singleData = self.tableBuildInfo.buildData._retPreNebulaTower
//     })
//     singleInfo:setBtnCallBcak(handler(self, self.scrollSingleCallBack))
//     singleInfo:setScroll(self.scrollUp)
//     singleInfo:addTo(self.scrollUp)
//     if not singleInfo:getIsMet() then
//       isMet = false
//     end
//     table.insert(self.tableScrollSingles, singleInfo)
//     if not self.tableBuildInfo.buildData._retPreNebulaTower.isreach then
//       self.buildType = CANT_BY_BUILD
//       isreach = false
//       self.isSpecialReach = false
//     end
//   end
  for(auto iii = 0; iii < (int32)_TableBuildInfo._BuildData._CostBuilding.size(); iii++){
    auto v  = _TableBuildInfo._BuildData._CostBuilding[iii];
    auto l_SingleInfo = UIBuildingCreateSingle::Create();
    auto l_Count = iii  + _QShowListCount - 1;
    l_SingleInfo->setPosition({280.f, _ScrollH - (l_Count -1 ) * _SingleH});
    auto l_Param = UIBuildingCreateSingle::RBuildingCondData();
    l_Param._BLvl = v.lvlReq;
    l_Param._StarLvl = v._StarLvl;
    l_Param._Data._Bid = v.TypeReq;
    l_SingleInfo->InitData(
      UIBuildingCreateSingle::EBuildingCondType::Building,
      l_Param
    );
    l_SingleInfo->SetScroll(_ScrollUp);
    _ScrollUp->addChild(l_SingleInfo);
    _TableScrollSingles.push_back(l_SingleInfo);
    if(l_SingleInfo->GetIsMet())
      _ISMet = false;
    if(!v._IsReach){
      _IsReach = false;
      _IsSpecialReach = false;
      _BuildType = CANT_BY_BUILD;
      auto l_Lvl = MainCityFunctions::Get()->GetCastleLv();
      if(!_SpritHand && !_IsShowFinger && l_Lvl < GBase::Const::Get()->CastleLvl15){
        auto l_PosX = GBase::DFIsRA() ? -200.f : 200.f;
        auto l_Pos = Vec2(l_PosX + _ScrollUp->getPositionX(), _ScrollUp->getPositionY() - (iii + _QShowListCount - 1) * _SingleH - 25);
        ShowFingerClick(l_Pos);
      }
    }
  }
  _IsEnough = _ISMet;
  SetBtnUpNowState();
  SetBuildBtnTouchEnable(_IsReach);
  if(_ScrollH > _ScrollUp->getContentSize().height)
    _ScrollUp->setBounceEnabled(true);
}

void UIBuildingCreateInfoPanel::ShowFingerClick(Vec2 p_Pos){
  _SpritHand = GBase::DFingerAction(true, false, 5);
  _SpritHand->setPosition(p_Pos);
  _BottomNode->addChild(_SpritHand, 99);
  _IsShowFinger = true;
}

void UIBuildingCreateInfoPanel::LightBlink(int32 p_Index){
  if(_ViewType == EBuildingOperateType::UpgradeStar){
  //   if self.tableBuildInfo.buildData and #self.tableBuildInfo.buildData._buildStarQueueList == 2 then
  //     SoraDShowMsgTip(i18n("architectural_brilliance_level_tips"), "#icon_hourglass.png", self.btnUp)
  //   else
  //     SoraDShowMsgTip(i18n("Glory_text_22"), "#icon_hourglass.png", self.btnUp)
  //   end
  }else{
    GBase::DShowMsgTip(Translate::i18n("common_text_743"), "icon_hourglass.png", _BtnUp);
  }
  _ImgLight->stopAllActions();
  _ImgLight->setVisible(true);
  _ImgLight->setPositionY(_ScrollUp->getInnerContainerSize().height - (p_Index -.5) * _SingleH);
  _ImgLight->runAction(
    Sequence::create(
      FadeOut::create(.01f),
      FadeIn::create(0.3f),
      FadeOut::create(1),
      FadeIn::create(0.5f),
      FadeOut::create(1),
      nullptr
    )
  );
}

void UIBuildingCreateInfoPanel::ResBuyCallBack(){
  if(_ViewType == EBuildingOperateType::Build){
    Build(EOperateMode::GoldReplace);
  }else if(_ViewType == EBuildingOperateType::Upgrade){
    Upgrade(EOperateMode::GoldReplace);
  }
}

void UIBuildingCreateInfoPanel::BtnHelpCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  if(p_Touch == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    //   userSDKManager.showSingleFAQ(gSDKDef.FAQSingleType.WAR_LV)
  }
}

void UIBuildingCreateInfoPanel::BtnUnlockedCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  if(p_Touch == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    _TableBuildInfo._BuildId._UnlockedId;
    auto l_Panel = UIBuildUnlockedSingleInfoView::Create();
    l_Panel->InitData(_TableBuildInfo._BuildId._Bid, _TableBuildInfo._BuildId._UnlockedId);
    l_Panel->Show();
  }
}

void UIBuildingCreateInfoPanel::UpgradeFun(){
  if(_BuildType == CANT_BY_RES || _BuildType == CANT_BY_TOOL){
    if(_BuildType == CANT_BY_TOOL && !GBase::DEnoughWarBadge(_NeedWarBadgeBuy, _NeedWarBadgeID))
      return;
    else if(GBase::DIsGameGuide())
      ResBuyCallBack();
    else{
      auto l_ResBuyType = EResBuyViewType::Upgrade;
      if(_ViewType == EBuildingOperateType::Build)
        l_ResBuyType = EResBuyViewType::Build;

      GVector<RTableResNeedBuy> _TableResNeedBuy;
      
      for(auto iii = 0; iii < _TableBuildInfo._BuildData._CostResource.size(); iii++){
        auto v = _TableBuildInfo._BuildData._CostResource[iii];
        if(!v._IsReach){
          auto l_NeedBuyRes = v._ResCount - v._CurCount;
          auto l_CostResCount = v._ResCount;
          if(_LuckyBlessIsOpen){
            l_CostResCount = LuckyBlessCtrl::Get()->GetResult(v._ResCount);
            l_NeedBuyRes = GMath::Max(0, l_CostResCount - v._CurCount);
          }
          
          auto l_SubPercent = EffectCtrl::Get()->GetBuffEffect(EEffect::UPGRADE_CASTLE_COST_RES_REDUCE_FOR_POW);
          l_CostResCount = std::ceil(float(l_CostResCount)*(1.f - l_SubPercent / 1000));
          l_NeedBuyRes = GMath::Max(0.f, l_CostResCount - float(v._CurCount));
          auto l_Need = RTableResNeedBuy();
          l_Need._ResId = v._ResId;
          l_Need._ResCount = l_CostResCount - v._CurCount;
          if(l_NeedBuyRes > 0)
            _TableResNeedBuy.push_back(l_Need);
        }
      }
      
      for(size_t iii = 0; iii < _TableBuildInfo._BuildData._CostItem.size(); iii++){
        auto v = _TableBuildInfo._BuildData._CostItem[iii];
        auto l_Need = RTableResNeedBuy();
        l_Need._ItemId = v.idItem;
        l_Need._ResCount = v._ItemCount - v._CurCount;
        if(!v._IsReach){
          _TableResNeedBuy.push_back(l_Need);
        }
      }
      
      for(size_t iii = 0; iii < _TableBuildInfo._BuildData._CostItemWEs.size(); iii++){
        auto v = _TableBuildInfo._BuildData._CostItemWEs[iii];
        auto l_Need = RTableResNeedBuy();
        l_Need._ItemId = v.idItem;
        l_Need._ResCount = v._ItemCount - v._CurCount;
        if(!v._IsReach){
          _TableResNeedBuy.push_back(l_Need);
        }
      }
      
      //         local proxy = uiManager:getOrCreateProxy("CommonQuicklyadd")
      if(false /*proxy:checkNeedRes(tableResNeedBuy)*/){
       //           uiManager:show("CommonQuicklyadd")
      }else{
        auto l_Panel = UIBuildCreateResBuy::Create();
        l_Panel->InitData(
          _TableResNeedBuy,
          _TableBuildInfo._BuildData.resToGold + 
          _TableBuildInfo._BuildData.itemToGold +
          _TableBuildInfo._BuildData.WEToGold,
          l_ResBuyType
        );
        l_Panel->SetBuyResCallBack(CC_CALLBACK_0(UIBuildingCreateInfoPanel::ResBuyCallBack, this));
        l_Panel->Show();
      }
    }
  } else if(_BuildType == CANT_BY_BUILDER){
    LightBlink(1);
  } else if(_ViewType == EBuildingOperateType::Build){
    Build();
  } else if(_ViewType == EBuildingOperateType::Upgrade){
    Upgrade();
  } else if(_ViewType == EBuildingOperateType::Unlock) {
    CityCtrl::Get()->OpenGroundReq(_TableBuildInfo._AreaId);
    RDoOffestMoveParam p_Parm = RDoOffestMoveParam();
    p_Parm._OffsetType = EMainCityViewOffsetType::Recover;
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_OFFSET_BUILD", &p_Parm);
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_SHOW_LOCKAREA_REQ_LOADING", &_TableBuildInfo._AreaId);
  }
}

void UIBuildingCreateInfoPanel::BtnUpCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();

  if(_ViewType != EBuildingOperateType::Unlock){
    auto l_BuildingCell = CityCtrl::Get()->GetBuildingCellByIndex(_TableBuildInfo._BuildId._IID);
    if(l_BuildingCell && _TableBuildInfo._BuildId._Bid == EBuilding::Castle){
    //       if commonCheck.NEW_WEEK_CARD and tonumber(buildCell.info.lv) == CASTLE_LV15_LIMITED and rechargeActivityCtrl:checkHasbuyNewWeekcard() then
    //         SoraDShowMsgBox(i18n("new_weeklycard_tips_01"), i18n("common_text_204"), nil, function(type)
    //           if type == MSGBOX_CALLBACK_YES then
    //           end
    //         end)
    //         return
    //       end
    
    //       if commonCheck.CASTLE_LVUP_TIPS and tonumber(buildCell.info.lv) == CASTLE_LV7_LIMITED then
    //         SoraDShowMsgBox(i18n("common_text_928_ros"), i18n("common_text_204"), nil, function(type)
    //           if type == MSGBOX_CALLBACK_YES then
    //             upgradeFun()
    //           end
    //         end)
    //         return
    //       end
    //       if self.wiseTutorIsOpen and tonumber(buildCell.info.lv) == include("wiseTutorRead").getMaxEffectCastleLv() then
    //         SoraDShowMsgBox(i18n("Battle_Towers_37", {
    //           lv = buildLogic.getBuildLvStr(include("wiseTutorRead").getMaxEffectCastleLv())
    //         }), i18n("common_text_204"), nil, function(type)
    //           if type == MSGBOX_CALLBACK_YES then
    //             upgradeFun()
    //           end
    //         end)
    //         return
    //       elseif self.artisanHouseIsOpen and tonumber(buildCell.info.lv) == include("artisanHouseltCtrl").getMaxEffectCastleLv() then
    //         SoraDShowMsgBox(i18n("Battle_Towers_37", {
    //           lv = buildLogic.getBuildLvStr(include("artisanHouseltCtrl").getMaxEffectCastleLv())
    //         }), i18n("common_text_204"), nil, function(type)
    //           if type == MSGBOX_CALLBACK_YES then
    //             upgradeFun()
    //           end
    //         end)
    //         return
    //       end
    //       if tonumber(buildCell.info.lv) == CASTLE_LV5_LIMITED then
    //         SoraDShowMsgBox(i18n("common_text_928"), i18n("common_text_204"), nil, function(type)
    //           if type == MSGBOX_CALLBACK_YES then
    //             upgradeFun()
    //           end
    //         end)
    //       else
    //         upgradeFun()
                UpgradeFun();
    //       end
    } else {
      UpgradeFun();
    }
  }else{
    UpgradeFun();
  }
}

void UIBuildingCreateInfoPanel::BtnUpNowCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  if(p_Touch != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  if(_ViewType == EBuildingOperateType::Build){
    if(_IsFree && _IsEnough){
      Build(EOperateMode::FREE);
    }else{
      GBase::DShowBuyBox(
        RShowBuyBoxParam(
          Translate::i18n("common_text_744", {{"name", BuildingRead::Get()->GetName(_TableBuildInfo._BuildId._Bid)}}),
          _TableBuildInfo._BuildData._ImmediatelyGold, Translate::i18n("common_text_379")
        ),
        CC_CALLBACK_1(UIBuildingCreateInfoPanel::BuildNow, this)
      );
    }
  }else if(_ViewType == EBuildingOperateType::Upgrade){
    //     local buildCell = cityCtrl:getBuildCell(self.tableBuildInfo.buildID.bid, self.tableBuildInfo.buildID.iid)
    auto l_BuildingCell = CityCtrl::Get()->GetBuildingCellByIndex(_TableBuildInfo._BuildId._IID);
    if(l_BuildingCell && _TableBuildInfo._BuildId._Bid == EBuilding::Castle){
      GString l_Des = "";
      if(l_BuildingCell->_Info.buildingLvl == GBase::Const::Get()->CastleLvl5){
        l_Des = Translate::i18n("common_text_928");
      } else if(_WiseTutorIsOpen /*and tonumber(buildCell.info.lv) == include("wiseTutorRead").getMaxEffectCastleLv()*/ ){
      //         des = i18n("Battle_Towers_37", {
      //           lv = buildLogic.getBuildLvStr(include("wiseTutorRead").getMaxEffectCastleLv())
      //         })
      }else if(_ArtisanHouseIsOpen /*and tonumber(buildCell.info.lv) == include("artisanHouseltCtrl").getMaxEffectCastleLv() */){
      //         des = i18n("Battle_Towers_37", {
      //           lv = buildLogic.getBuildLvStr(include("artisanHouseltCtrl").getMaxEffectCastleLv())
      //         })
      }
      if(l_Des != ""){
        GBase::DShowMsgBox(
          l_Des, Translate::i18n("common_text_204"), "", 
          [this](EMsgBoxCallBack p_Type){
              //           if type == MSGBOX_CALLBACK_YES then
              if(p_Type != EMsgBoxCallBack::Yes)
                return;
              if(_IsFree && _IsEnough)
                this->Upgrade(EOperateMode::FREE);
              else if(GBase::Const::Get()->IS_FIRST_TIME_COST_GOLD_BUILDING)
                GBase::DShowBuyBox(
                  RShowBuyBoxParam(
                    Translate::i18n("common_text_745", {{"name", BuildingRead::Get()->GetName(_TableBuildInfo._BuildId._Bid)}}),
                    _TableBuildInfo._BuildData._ImmediatelyGold, Translate::i18n("common_text_378")
                  ),
                  CC_CALLBACK_1(UIBuildingCreateInfoPanel::UpgradeNow, this)
                 // , nil, nil, nil, nil, nil, i18n("build_gold_lvup_tips_name"), IS_SELECT_LOGIN_NOTICE, true
                );
              else 
                this->UpgradeNow(EMsgBoxCallBack::Yes);
          }
        );
        return;
      }
    }
    if(_IsFree && _IsEnough){
      Upgrade(EOperateMode::FREE);
    }else if(GBase::Const::Get()->IS_FIRST_TIME_COST_GOLD_BUILDING){
      GBase::DShowBuyBox(
        RShowBuyBoxParam(
          Translate::i18n("common_text_745", {{"name", BuildingRead::Get()->GetName(_TableBuildInfo._BuildId._Bid)}}),
          _TableBuildInfo._BuildData._ImmediatelyGold, Translate::i18n("common_text_378")
        ),
        CC_CALLBACK_1(UIBuildingCreateInfoPanel::UpgradeNow, this)
      );
    }else{
      UpgradeNow(EMsgBoxCallBack::Yes);
    }
  }
}

void UIBuildingCreateInfoPanel::OnWiseTutorClick(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   uiManager:show("wiseTutorBuffPop")
  // end
}

void UIBuildingCreateInfoPanel::OnArtisanHouseClick(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  // if type == ccui.TouchEventType.ended then
  //   SoraDPlaySound()
  //   local state, _ = artisanHouseCtrl:getStateInfo()
  //   if state then
  //     local param = {
  //       title = i18n("activity_name_9001399"),
  //       goHandle = function()
  //         uiManager:show("ArtisanHouseMain")
  //       end,
  //       actltCtrl = include("artisanHouseltCtrl")
  //     }
  //     uiManager:show("ArisanHouseBuffPop", param)
  //   else
  //     SoraDShowMsgTip("common_text_2486")
  //   end
  // end
}

void UIBuildingCreateInfoPanel::Build(EOperateMode p_Mode){
  
  auto l_Bid = _TableBuildInfo._BuildId._Bid;
  auto l_Index = _TableBuildInfo._BuildId._IID;
  auto l_Data = _TableBuildInfo._BuildData;
  auto l_Ret = BuildingLogic::Get()->Build(l_Index, p_Mode, l_Data, l_Bid);
  if(l_Ret == EErrDef::Err_None){
    static GPair<EBuilding, EBuildingIndex> l_NewBuild(l_Bid, l_Index);
    l_NewBuild.First = l_Bid;
    l_NewBuild.Second = l_Index;
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_CREATE_BUILD", &l_NewBuild);
    CityCtrl::Get()->AddBuildingReq(l_Index, l_Bid, p_Mode);
    if(l_Bid == EBuilding::MarchingTent && !GBase::DIsGameGuide() ){
      //     local gametop = gModuleMgr.getObject("gametop")
      //     local guideCtrl = gametop.playertop_:getModule("guideCtrl")
      //     guideCtrl:CompleteGuideStep(12001)
    }
    GBase::DRemoveAllPrePanelFromManager(this);
  } else if(l_Ret == EErrDef::Err_CHARGE_QUEUE_TIME_NOT_REACH || _BuildType == NEED_BUY_BUILDER){
    auto l_Q = CityCtrl::Get()->GetCurCity()->QueryQueue(ETask::charge_build_queue);
    //   local monthData = rechargeActivityCtrl:getMonthActivityList() or {}
    uint32 l_ItemId = 500501;
    auto l_ItemCount = ItemCtrl::Get()->GetItemCount(l_ItemId);
    if(l_Q){
      //     local remainTime = queue.timerNode.timer:getRemainTime()
      //     if remainTime >= self.tableBuildInfo.buildData._costtime then
      //       self:upgrade(_mode)
      //     else
      //       local buildchargequeue = cityCtrl:getCurCity():queryQueue(gQueueTypeDef.charge_build_queue)
      //       local leftTime = buildchargequeue and buildchargequeue.timerNode.timer:getRemainTime() or 0
      //       local needCount = math.ceil((remainTime - leftTime) / 172800)
      //       if next(monthData) then
      //         if itemCount > 0 then
      //           local msg = i18n("building_worker_text_05")
      //           local panel = SoraDCreatePanel("builderActivePopView")
      //           panel:initData(1, msg, remainTime)
      //           panel:show()
      //         else
      //           local msg = i18n("building_worker_text_06", {
      //             var1 = gConstValue.OPEN_BUILD_CHARGE_QUEUE_GOLD * needCount,
      //             var2 = BUILDER_WORK_TIME * needCount
      //           })
      //           local panel = SoraDCreatePanel("builderActivePopView")
      //           panel:initData(2, msg, remainTime)
      //           panel:show()
      //         end
      //       elseif itemCount > 0 then
      //         local msg = i18n("building_worker_text_07")
      //         local panel = SoraDCreatePanel("builderActivePopView")
      //         panel:initData(3, msg, remainTime)
      //         panel:show()
      //       else
      //         local msg = i18n("building_worker_text_08", {
      //           var = gConstValue.OPEN_BUILD_CHARGE_QUEUE_GOLD * needCount
      //         })
      //         local panel = SoraDCreatePanel("builderActivePopView")
      //         panel:initData(4, msg, remainTime)
      //         panel:show()
      //       end
      //     end
    } else if(false /*next(monthData)*/){
      if(l_ItemCount > 0){
        auto l_Msg = Translate::i18n("building_worker_text_01");
        auto l_Panel = UIBuilderActivePopView::Create();
        l_Panel->InitData(1, l_Msg);
        l_Panel->Show();
      }else{
        auto l_Msg = Translate::i18n("building_worker_text_02", {
          {"var1", std::to_string(GBase::ConstValue::Get()->OPEN_BUILD_CHARGE_QUEUE_GOLD)},
          {"var2", std::to_string(GBase::Const::Get()->BUILDER_WORK_TIME)},
        });
        auto l_Panel = UIBuilderActivePopView::Create();
        l_Panel->InitData(2, l_Msg);
        l_Panel->Show();
      }
    } else if(l_ItemCount > 0){
      auto l_Msg = Translate::i18n("building_worker_text_03");
      auto l_Panel = UIBuilderActivePopView::Create();
      l_Panel->InitData(3, l_Msg);
      l_Panel->Show();
    }else{
      auto l_Msg = Translate::i18n("building_worker_text_02", {
        {"var1", std::to_string(GBase::ConstValue::Get()->OPEN_BUILD_CHARGE_QUEUE_GOLD)},
        {"var2", std::to_string(GBase::Const::Get()->BUILDER_WORK_TIME)},
      });
      auto l_Panel = UIBuilderActivePopView::Create();
      l_Panel->InitData(4, l_Msg);
      l_Panel->Show();
    }
  } else if(l_Ret == EErrDef::Err_QUEUE_BUSY){
    LightBlink(1);
  }
}

void UIBuildingCreateInfoPanel::BuildNow(EMsgBoxCallBack p_Call){
  if(p_Call != EMsgBoxCallBack::Yes)
    return;
  if(!GBase::DEnoughGold(_TableBuildInfo._BuildData._ImmediatelyGold))
    return;
  if(!GBase::DEnoughWarBadge(_NeedWarBadgeBuy, _NeedWarBadgeID))
    return;
  Build(EOperateMode::Immediately);
}

void UIBuildingCreateInfoPanel::Upgrade(EOperateMode p_Mode){
  auto l_Bid = _TableBuildInfo._BuildId._Bid;
  auto l_Iid = _TableBuildInfo._BuildId._IID;
  auto l_Data = _TableBuildInfo._BuildData;
  auto l_Index = _TableBuildInfo._BuildType._BuildIndex;
  auto l_BuildingEntity = _TableBuildInfo._BuildId._BuildEntity;

  if(l_BuildingEntity && !l_BuildingEntity->CheckCanTrainOrUpgrade())
    return;
  auto l_Ret = BuildingLogic::Get()->Upgrade(l_Iid, p_Mode, l_Data, false, l_Bid);
  if(l_Ret == EErrDef::Err_None){
    GBase::DShowLoading(_BtnUpNow)->setPosition({0, 0});
    auto l_IsResBuild = BuildingLogic::Get()->GetOutBuildIsResBuild(l_Bid);
    if(l_IsResBuild && (l_BuildingEntity->GetHarvestState() == EHarvestState::Much || l_BuildingEntity->GetHarvestState() == EHarvestState::Some))
      l_BuildingEntity->HarvestRes();
    static GPair<EBuilding, EBuildingIndex> l_MsgData (l_Bid, l_Iid);
    l_MsgData.First = l_Bid;
    l_MsgData.Second = l_Iid;
    GBase::DSendMessage("MESSAGE_BUILD_UPGRADE", &l_MsgData);
    CityCtrl::Get()->UpgradeBuildReq(l_Iid, l_Bid, p_Mode);
    auto l_IsFullLv = BuildingLogic::Get()->BuildLvIsFull(l_Bid, l_Iid);
    if((p_Mode == EOperateMode::Immediately || p_Mode == EOperateMode::FREE) && !l_IsFullLv){
    GBase::DRemoveAllPrePanelFromManager(this, true);
      _FirstRunWar = true;
      InitUpgradeData(_TableBuildInfo._BuildId._BuildEntity);
      ReloadScroll(true);
    }else{
      GBase::DRemoveAllPrePanelFromManager(this);
    }
  } else if(l_Ret == EErrDef::Err_CHARGE_QUEUE_TIME_NOT_REACH || _BuildType == NEED_BUY_BUILDER){
    auto l_Q = CityCtrl::Get()->GetCurCity()->QueryQueue(ETask::charge_build_queue);
    //   local monthData = rechargeActivityCtrl:getMonthActivityList() or {}
    auto l_ItemId = 500501;
    auto l_ItemCount = ItemCtrl::Get()->GetItemCount(l_ItemId);
    if(l_Q){
      auto l_RemainTime = l_Q->GetRemainTime();
      //     local remainTime = queue.timerNode.timer:getRemainTime()
      if(l_RemainTime >= _TableBuildInfo._BuildData._CostTime){
        Upgrade(p_Mode);
      } else if(false /* next(monthData) */){
        if(l_ItemCount > 0){
          auto l_Msg = Translate::i18n("building_worker_text_05");
          auto l_Panel = UIBuilderActivePopView::Create();
          l_Panel->InitData(1, l_Msg, l_RemainTime);
          l_Panel->Show();
        }else{
          auto l_Msg = Translate::i18n("building_worker_text_06", {
            {"var1", std::to_string(GBase::ConstValue::Get()->OPEN_BUILD_CHARGE_QUEUE_GOLD)},
            {"var2", std::to_string(GBase::Const::Get()->BUILDER_WORK_TIME)}
          });
          auto l_Panel = UIBuilderActivePopView::Create();
          l_Panel->InitData(2, l_Msg, l_RemainTime);
          l_Panel->Show();
        }
      }else if(l_ItemCount > 0){
        auto l_Msg = Translate::i18n("building_worker_text_07");
        auto l_Panel = UIBuilderActivePopView::Create();
        l_Panel->InitData(3, l_Msg, l_RemainTime);
        l_Panel->Show();
      }else{
        auto l_Msg = Translate::i18n("building_worker_text_08", {
          {"var", std::to_string(GBase::ConstValue::Get()->OPEN_BUILD_CHARGE_QUEUE_GOLD)}
        });
        auto l_Panel = UIBuilderActivePopView::Create();
        l_Panel->InitData(4, l_Msg, l_RemainTime);
        l_Panel->Show();
      }
    } else if(false /*next(monthData) */){
      if(l_ItemCount > 0){
        auto l_Msg = Translate::i18n("building_worker_text_01");
        auto l_Panel = UIBuilderActivePopView::Create();
        l_Panel->InitData(1, l_Msg);
        l_Panel->Show();
      }else{
        auto l_Msg = Translate::i18n("building_worker_text_02", {
          {"var1", std::to_string(GBase::ConstValue::Get()->OPEN_BUILD_CHARGE_QUEUE_GOLD)},
          {"var2", std::to_string(GBase::Const::Get()->BUILDER_WORK_TIME)}
        });
        auto l_Panel = UIBuilderActivePopView::Create();
        l_Panel->InitData(2, l_Msg);
        l_Panel->Show();
      }
    } else if(l_ItemCount > 0){
      auto l_Msg = Translate::i18n("building_worker_text_03");
      auto l_Panel = UIBuilderActivePopView::Create();
      l_Panel->InitData(3, l_Msg);
      l_Panel->Show();
    }else{
      auto l_Msg = Translate::i18n("building_worker_text_02", {
        {"var1", std::to_string(GBase::ConstValue::Get()->OPEN_BUILD_CHARGE_QUEUE_GOLD)},
        {"var2", std::to_string(GBase::Const::Get()->BUILDER_WORK_TIME)}
      });
      auto l_Panel = UIBuilderActivePopView::Create();
      l_Panel->InitData(4, l_Msg);
      l_Panel->Show();
    }
  } else if(l_Ret == EErrDef::Err_QUEUE_BUSY){
    LightBlink(1);
  }
}


void UIBuildingCreateInfoPanel::UpgradeNow(EMsgBoxCallBack p_Call){
  if(p_Call != EMsgBoxCallBack::Yes)
    return;
  if(!GBase::DEnoughGold(_TableBuildInfo._BuildData._ImmediatelyGold))
    return;
  if(!GBase::DEnoughWarBadge(_NeedWarBadgeBuy, _NeedWarBadgeID))
    return;
  Upgrade(EOperateMode::Immediately);
}

Node *UIBuildingCreateInfoPanel::WarLvBarEffect(Node *p_Target){

  RCreatEffctParam l_Part_1;
  RCreatEffctParam l_Part_2;
  RCreatEffctParam l_Part_3;

  l_Part_1._PList = "et_battlelv01_01.plist";
  l_Part_1._Pos = {6.14f, 17.77f};
  l_Part_1._Scale = {1.72f, 1.72f};
  l_Part_1._Rotate = 20.77f;
  l_Part_1._Name = "effect1";
  l_Part_1._PosType = ParticleSystem::PositionType::FREE;
  l_Part_1._TpScale = 1;

  l_Part_2._PList = "et_battlelv01_02.plist";
  l_Part_2._Pos = { 0.73f, 4.96f};
  l_Part_2._Scale = {0.76f, 0.76f};
  l_Part_2._Rotate = 30.27f;
  l_Part_2._Name = "effect2";
  l_Part_2._PosType = ParticleSystem::PositionType::FREE;
  l_Part_2._TpScale = 1;

  l_Part_3._PList = "et_battlelv01_03.plist";
  l_Part_3._Pos = {0, 0};
  l_Part_3._Scale = {0.675f, 0.675f};
  l_Part_3._Rotate = 38.5f;

  auto l_ENode = GBase::DCreateEffectNode({l_Part_1, l_Part_2, l_Part_3});
  l_ENode->setPosition({0, 0});
  if(p_Target)
    p_Target->addChild(l_ENode);
  return l_ENode;
}

void UIBuildingCreateInfoPanel::CloseLoading(EventCustom *p_Event){
  GBase::DCloseLoading(_BtnUpNow);
}

void UIBuildingCreateInfoPanel::OnExitPanel(){
  // if self.viewType == BUILD_OPERATE_TYPE.BUILD then
  //   print("self.curBuildIndex", self.curBuildIndex)
  //   local cityBuildConstDef = include("cityBuildConstDef")
  //   if self.tableBuildInfo.buildType.buildIndex == cityBuildConstDef.buildIndexDef.index_Miracle then
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_PREVIEW",
  //       index = self.tableBuildInfo.buildType.buildIndex
  //     })
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_OFFSET_BUILD",
  //       offsetType = MAINCITYVIEW_OFFSET_TYPE_RECOVER
  //     })
  //   elseif self.isFromCreate then
  //   elseif self.curBuildIndex and self.curBuildIndex ~= 1050 then
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_OFFSET_BUILD",
  //       offsetType = MAINCITYVIEW_OFFSET_TYPE_BUILD,
  //       buildIndex = self.curBuildIndex,
  //       scale = 0.9,
  //       skip = true
  //     })
  //   else
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_OFFSET_BUILD",
  //       offsetType = MAINCITYVIEW_OFFSET_TYPE_RECOVER
  //     })
  //   end
  // else
  //   print("self.isSkip===", self.isSkip, self.curBuildIndex)
  //   if self.isSkip and self.curBuildIndex then
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_OFFSET_BUILD",
  //       noScaleDuration = self.noScaleDuration,
  //       noOffsetDuration = self.noOffsetDuration,
  //       offsetType = MAINCITYVIEW_OFFSET_TYPE_BUILD,
  //       buildIndex = self.curBuildIndex,
  //       scale = 0.9,
  //       skip = true
  //     })
  //   else
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_OFFSET_BUILD",
  //       offsetType = MAINCITYVIEW_OFFSET_TYPE_RECOVER
  //     })
  //   end
  // end
}

void UIBuildingCreateInfoPanel::SetSpecail(){
  // if self.tableBuildInfo.buildID and self.tableBuildInfo.buildID.bid == BUILDID.NEBULA_PALACE then
  //   self:setBuildBtnTouchEnable(self.isSpecialReach)
  //   self.labelFreeTip:setVisible(not self.isSpecialReach or self.isFree and self.isEnough)
  //   self.labelFreeTip:setColor(not self.isSpecialReach and cc.c3b(255, 0, 0) or cc.c3b(255, 200, 100))
  //   if not self.isSpecialReach then
  //     self.labelFreeTip:setString(i18n("nebula_war_text_0176"))
  //   end
  //   self.labelDes:setVisible(true)
  //   local buildMoreInfoRead = include("buildMoreInfoRead")
  //   local tableUpData = buildMoreInfoRead.getUpgradeInfoData(self.tableBuildInfo.buildID.bid, self.tableBuildInfo.buildID.iid)
  //   self.labelDes:setString(i18n("nebula_war_text_0162"))
  // end
}

void UIBuildingCreateInfoPanel::BtnShowRadiantBuff(Ref *p_Sender, ui::Widget::TouchEventType p_Touch){
  // local state, _ = radiantDecreeCtrl:getStateInfo()
  // if state then
  //   local param = {
  //     title = i18n("activity_name_9001442"),
  //     goHandle = function()
  //       uiManager:show("RadiantDecreeMain")
  //     end,
  //     actltCtrl = include("radiantDecreeRead")
  //   }
  //   uiManager:show("RadiantDecreeBuffPop", param)
  // else
  //   SoraDShowMsgTip("common_text_2486")
  // end
}

void UIBuildingCreateInfoPanel::UpdateRadiantDecreeBuff(){
  // local state, leftTime = radiantDecreeCtrl:getStateInfo()
  // if state == gActivityState.OPEN then
  //   self.radiantDecreeIsOpen = false and radiantDecreeCtrl:isBuffEffect()
  //   self.radiantNode:setVisible(self.radiantDecreeIsOpen)
  //   self.radiantTime:setVisible(self.radiantDecreeIsOpen)
  //   local state = wiseTutorCtrl:getStateInfo()
  //   local lang = SoraDGetDefaultLanguage()
  //   if state == gActivityState.OPEN then
  //     if lang == "ar" then
  //       self.radiantNode:setPositionX(self.nodeWiseTutor:getPositionX() - 100)
  //     else
  //       self.radiantNode:setPositionX(self.nodeWiseTutor:getPositionX() + 100)
  //     end
  //   elseif lang == "ar" then
  //     self.radiantNode:setPositionX(self.nodeWiseTutor:getPositionX() - 30)
  //   else
  //     self.radiantNode:setPositionX(self.nodeWiseTutor:getPositionX() + 30)
  //   end
  //   self.radiantNode:setPositionY(self.nodeWiseTutor:getPositionY())
  //   if leftTime > 0 and self.radiantDecreeIsOpen then
  //     self:openRadiantDecreeTime()
  //     self.radiantDecreeTimer = SoradCreateTimer(self, handler(self, self.openRadiantDecreeTime))
  //   end
  //   SoraDSetGray(SoraDGetChildByName(self.radiantNode, "Image_radiant"), not self.radiantDecreeIsOpen)
  // else
  //   if not self.luckyBlessIsOpen then
  //     for i, v in ipairs(self.tableScrollSingles) do
  //       v:radiantBlessOpen(false)
  //     end
  //   end
  //   self.radiantNode:setVisible(false)
  //   self.radiantDecreeIsOpen = false
  // end
}

void UIBuildingCreateInfoPanel::OpenRadiantDecreeTime(float dt){
  // local state, leftTime = radiantDecreeCtrl:getStateInfo()
  // if state == gActivityState.CLOSE or not self.radiantDecreeIsOpen then
  //   SoraDManagerRemoveTimer(self, self.radiantDecreeTimer)
  //   self.radiantDecreeTimer = nil
  //   self.radiantNode:setVisible(false)
  //   self:resUpdate()
  // else
  //   self.radiantTime:setString(SoraDConvertSecondToString(leftTime))
  // end
}

void UIBuildingCreateInfoPanel::UpdateBuff(EventCustom *p_Event){
  // self:updateRadiantDecreeBuff()
}
