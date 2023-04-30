#include "UICollageView.h"
#include "UICollegeScrollSingle.h"
#include "UICollegeWaitSingle.h"
#include "UICollegeMainSingle.h"
#include "UICollegeDetailsView.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Building/Building.Logic.h"
#include "Module/Building/Building.Read.h"
#include "Module/Science/Science.Read.h"
#include "Module/Science/Science.Ctrl.h"
#include "Module/Science/Science.Task.h"
#include "Module/Task/Task.Ctrl.h"
#include "Module/Task/WaitQueue.Ctrl.h"
#include "Module/Vip/ExaltedPrivilege.Ctrl.h"
#include "Module/UI/Part/Common/Frame/UICommonFramTitle.h"
#include "Module/UI/Part/Common/Box/UICommonEllipseBar.h"
#include "Module/Activity/LuckyBless/LuckyBless.Ctrl.h"
#include "Module/Activity/LuckyBless/LuckyBless.Type.h"

UICollageView *UICollageView::Create(){
  auto l_Panel = UICollageView::Create("UiParts/Panel/Building/View/College/collegeView.csb");
  return l_Panel;
}

void UICollageView::Ctor(){
  
  GBase::PlaySound("uicontrol", 47);
  _NodeTitle = GBase::DGetExtendChildFromCCSByName<UICommonFramTitle>(this, "Top_CCS_commonFramTitle_study");
  _NodeBall = GBase::DGetChildByName<Node *>(this, "CCS_collegeXFTBall_ball");
  _AnimationBall = dynamic_cast<Anim *>(_NodeBall->getActionByTag(_NodeBall->getTag()));
  _NodeLight = GBase::DGetChildByName<Node *>(this, "CCS_collegeXFTLight_light");
  _AnimationLight = dynamic_cast<Anim *>(_NodeLight->getActionByTag(_NodeLight->getTag()));
  _NodeBase = GBase::DGetChildByName<Node *>(this, "CCS_collegeXFTBase_base");
  _AnimationBase = dynamic_cast<Anim *>(_NodeBase->getActionByTag(_NodeBase->getTag()));
  _NodeCenter = GBase::DGetChildByName<Node *>(this, "CCS_collegeXFTCenter_center");
  _AnimationCenter = dynamic_cast<Anim *>(_NodeCenter->getActionByTag(_NodeCenter->getTag()));
  _NodeTechFront = GBase::DGetChildByName<Node *>(this, "Center_Node_Tech_Front");
  _NodeFront = GBase::DGetChildByName<Node *>(_NodeTechFront, "Node_Tech_Front");
  _TopNode = GBase::DGetChildByName<Node *>(this, "Top_Node");
  _LabelNotice = GBase::DGetChildByName<ui::Text *>(this, "Text_notice");
  _LabelNotice->setString(Translate::i18n("common_text_330"));
  _BottomNodeLucky = GBase::DGetChildByName<Node *>(this, "Bottom_Node_lucky");
  _BottomNodeLucky->setVisible(false);
  _LabelLcukyDes = GBase::DGetChildByName<ui::Text *>(this, "Text_luckyDes");
  _BottomNode = GBase::DGetChildByName<Node *>(this, "Bottom_Node");
  _NodeTimer = GBase::DGetChildByName<Node *>(this, "Node_timer");
  _NodeTimer->setVisible(false);
  _NodeTime = GBase::DGetChildByName<Node *>(_NodeTimer, "Node_time");
  _TimeBar = UICommonEllipseBar::Create();
  _TimeBar->SetRadius(280);
  _TimeBar->SetFrameAnimation();
  _TimeBar->setPosition(Vec2(0, 0));
  _NodeTime->addChild(_TimeBar);
  _TextTime = GBase::DGetChildByName<ui::Text *>(_NodeTimer, "Text_time");
  _CenterNodeTechInfo = GBase::DGetChildByName<Node *>(this, "Center_Node_techInfo");
  _CenterNodeTechInfo->setVisible(false);
  _LabelStudyName = GBase::DGetChildByName<ui::Text *>(_CenterNodeTechInfo, "Text_name");
  _ButtonDetail = GBase::DGetChildByName<ui::Button *>(_CenterNodeTechInfo, "Button_detail");
  _ButtonDetail->setTouchEnabled(true);
  _ButtonDetail->addTouchEventListener(CC_CALLBACK_2(UICollageView::BtnDetailClick, this));
  _CcsStudying = GBase::DGetExtendChildFromCCSByName<UICollegeScrollSingle>(this, "CCS_collegeScrollSingle_studying");
  _Node_Title = GBase::DGetChildByName<Node *>(this, "Node_title");
  _TextTitle = GBase::DGetChildByName<ui::Text *>(_Node_Title, "Text_title");
  _TextTitle->setString(Translate::i18n("Technology_text_01"));
  GBase::DToCenter(_Node_Title);
  _NodeRecommend_1 = GBase::DGetChildByName<Node *>(this, "Node_recommend_1");
  _NodeRecommend_2 = GBase::DGetChildByName<Node *>(this, "Node_recommend_2");
  _TextNoRecommend = GBase::DGetChildByName<ui::Text *>(this, "Text_noRecommend");
  _TextNoRecommend->setString(Translate::i18n("Technology_text_02"));
  _TextNoRecommend->setVisible(false);
  _CenterNodeTechInfo->setLocalZOrder(10);
  _IsPrivilege = ExaltedPrivilegeCtrl::Get()->CheckPrivilege(EExaltedPrivilege::TECHNOLOGY_QUEUE);
  if(_IsPrivilege){
    auto l_Node = UICollegeWaitSingle::Create();
    addChild(l_Node, 1);
    l_Node->setPosition(Vec2(GDisplay::Get()->cx, 0));
    _NodeWait = l_Node;
  } 

  SuitView();
  InitData();
}

void UICollageView::OnMessageListener(){
  // SoraDAddMessage(self, "MESSAGE_UPDATE_TECHNOLOGY", handler(self, self.initData))
  // SoraDAddMessage(self, "MESSAGE_SERVER_LUCKYBLESS_UPDATE", handler(self, self.updateLuckyBless))
  // SoraDAddMessage(self, "MESSAGE_TECHNOLOGY_WAITQUEUE", handler(self, self.refreshWaitQueue))
}

void UICollageView::SuitView(){
  auto l_SizeImageBase = GBase::DGetChildByName<ui::ImageView *>(this, "Size_Image_base");
  l_SizeImageBase->setContentSize(Size(640.f, std::max(350.f, GDisplay::Get()->height - 610.f)));
  _CenterNodeTechInfo->setPositionY(GDisplay::Get()->height < 960 ? GDisplay::Get()->cy - 220 : GDisplay::Get()->cy - 230);
  if(_IsPrivilege && GDisplay::Get()->height < 960){
    _CenterNodeTechInfo->setPositionY(_CenterNodeTechInfo->getPositionY() + 25);
    _TextTime->setPositionY(_TextTime->getPositionY() + 25);
  }
  if(GDevice::Get()->IsIphoneXMode()){
    _CenterNodeTechInfo->setPositionY(GDisplay::Get()->cy - 300);
    _TextTime->setPositionY(_TextTime->getPositionY() - 10);
  }
}

void UICollageView::InitData(){
  auto l_BuildCell = CityCtrl::Get()->GetBuildCellList(_Bid);
  int32 l_Blv = 1; //TODO:: Should be removed this is to bypass that collage not here
  if(l_BuildCell.size() > 0)
    l_Blv = l_BuildCell[0]._Info.buildingLvl;
  auto l_WarLv = BuildingLogic::Get()->TransFormBuildLvToWarLv(l_Blv);
  if(l_WarLv > 0){
    _TextTitle->setString(Translate::i18n("common_text_1957", {
      {"build", BuildingRead::Get()->GetName(_Bid)},
      {"lv", std::to_string(l_WarLv)}
    }));
  }else{
    _NodeTitle->SetTitle(Translate::i18n("common_text_334", {
      {"name", BuildingRead::Get()->GetName(_Bid)},
      {"lv", std::to_string(std::min(l_Blv, GBase::Const::Get()->CASTLE_MAX_WARLV))}
    }));
  }
  auto l_r = 240;
  auto l_posY = 120;
  auto l_scale = 1;
  if(GDisplay::Get()->height < 960){
    l_r = 180;
    l_posY = 100;
    l_scale = 0.8;
  }else if(GDisplay::Get()->height == 960){
    l_r = 220;
    l_posY = 100;
  }
  GVector<EScienceType> l_CollegeKey = {
    EScienceType::Resource,
    EScienceType::CityDevelop,
    EScienceType::Hero,
    EScienceType::Anchor,
    EScienceType::Military,
    EScienceType::Special,
    EScienceType::AdvancedMilitary,
    EScienceType::Soldier,
    EScienceType::Leader
  };
  auto l_angle = 360 / l_CollegeKey.size();
  _NodeFront->setPositionY(l_posY);
  auto III = 1;
  for(auto l_OneSc : l_CollegeKey){
    if(!_TableBtn.Contains(l_OneSc)){
      _TableBtn[l_OneSc] = UICollegeMainSingle::Create();
      _NodeFront->addChild(_TableBtn[l_OneSc]);
      _TableBtn[l_OneSc]->setScale(l_scale);
      auto l_rad = GMath::Rad(l_angle * III - l_angle * 3 / 2);
      if(GBase::DFIsRA())
        l_rad = GMath::Rad(360 - l_angle * III + l_angle * 3 / 2);
      auto l_posX = l_r * GMath::Sin(l_rad);
      auto l_posY = l_r * GMath::Cos(l_rad);
      _TableBtn[l_OneSc]->setPosition(Vec2(l_posX, l_posY));
      III++;
    }
    _TableBtn[l_OneSc]->InitData(l_OneSc);
  }
  InitRecommendData();
  if(_Timer){
    GBase::DManagerRemoveTimer(_Timer);
    _Timer = nullptr;
  }
  auto l_Ret = ScienceCtrl::Get()->StudyingTechnology();
  _TableStuding = l_Ret.First;
  _StudyingType = l_Ret.Second;
  TopStudyShow(_StudyingType != EScienceType::None);
  UpdateLuckyBless(nullptr);
  ShowAction(_StudyingType != EScienceType::None);
}

void UICollageView::SetRecommendInfo(Node *p_Node, RScienceLvlSpecs p_Info){
  auto l_CCSTech = GBase::DGetExtendChildFromCCSByName<UICollegeScrollSingle>(p_Node, "CCS_collegeScrollSingle_tech");
  auto l_TextTypeName = GBase::DGetChildByName<ui::Text *>(p_Node, "Text_typeName");
  auto l_TextPowerAdd = GBase::DGetChildByName<ui::Text *>(p_Node, "Text_powerAdd");
  auto l_TextTechName = GBase::DGetChildByName<ui::Text *>(p_Node, "Text_techName");
  auto l_ButtonStudy = GBase::DGetChildByName<ui::Button *>(p_Node, "Button_study");
  l_ButtonStudy->setTitleText(Translate::i18n("common_text_062"));
  l_ButtonStudy->addTouchEventListener(CC_CALLBACK_2(UICollageView::BtnStudyClickCallBack, this));
  auto l_Tid = new EScienceID;
  *l_Tid = p_Info.idScience;
  l_ButtonStudy->setUserData((void *)l_Tid);
  auto l_TypeData = ScienceRead::Get()->GetTypeTitleIcon(ScienceRead::Get()->GetType(p_Info.idScience));
  l_TextTypeName->setString(l_TypeData._Title);
  l_TextTypeName->setColor(l_TypeData._Color);
  l_TextTechName->setString(ScienceRead::Get()->GetName(p_Info.idScience));
  auto l_AddFighting = ScienceRead::Get()->GetFight(p_Info.idScience, p_Info.lvl + 1) - ScienceRead::Get()->GetFight(p_Info.idScience, p_Info.lvl);
  l_TextPowerAdd->setString(Translate::i18n("common_text_128", {
    {"power", std::to_string(l_AddFighting)}
  }));
  l_CCSTech->InitData(p_Info.idScience, ScienceRead::Get()->GetType(p_Info.idScience));
  l_CCSTech->HideName();
}

void UICollageView::InitRecommendData(){
  _RecommendData = ScienceCtrl::Get()->GetRecommendTech();
  _TextNoRecommend->setVisible(_RecommendData.size() == 0);
  if(_RecommendData.size() == 2){
    _NodeRecommend_1->setVisible(true);
    _NodeRecommend_2->setVisible(true);
    SetRecommendInfo(_NodeRecommend_1, _RecommendData[0]);
    SetRecommendInfo(_NodeRecommend_2, _RecommendData[1]);
  } else if(_RecommendData.size() == 1){
    _NodeRecommend_1->setVisible(true);
    SetRecommendInfo(_NodeRecommend_1, _RecommendData[0]);
    _NodeRecommend_2->setVisible(false);
  }else{
    _NodeRecommend_1->setVisible(false);
    _NodeRecommend_2->setVisible(false);
  }
}

void  UICollageView::UpdateLuckyBless(EventCustom *p_Event){
  
  auto l_CurEffect = LuckyBlessCtrl::Get()->GetCurEffectType();
  if(l_CurEffect == ELuckyBlessEffect::TechnologyResearch){
    _BottomNodeLucky->setVisible(true);
    if(_IsPrivilege)
      _BottomNodeLucky->setPositionY(_StudyingType != EScienceType::None ? -120 : 0);
    else
      _BottomNodeLucky->setPositionY(_StudyingType != EScienceType::None ? -170 : 0);
    if(_LuckyBlessTimer == nullptr){
      OpenLuckyTime(0);
      _LuckyBlessTimer = GBase::DCreateTimer(this, CC_CALLBACK_1(UICollageView::OpenLuckyTime, this));
    }
  }else{
    if(_LuckyBlessTimer){
      GBase::DManagerRemoveTimer(_LuckyBlessTimer);
      _LuckyBlessTimer = nullptr;
    }
    _BottomNodeLucky->setVisible(false);
  }
}

void UICollageView::OpenLuckyTime(float p_Dt){
  auto l_LuckyData = LuckyBlessCtrl::Get()->GetLuckyData();
  auto l_LeftTime = LuckyBlessCtrl::Get()->GetRealTime().First;
  _LabelLcukyDes->setString(Translate::i18n("lucky_text_19", {
    {"num", std::to_string(l_LuckyData._Discount / 10)},
    {"time", GBase::DConvertSecondToString(l_LeftTime)}
  }));
}

void UICollageView::ShowAction(bool p_IsStudying){
  
  GBase::DMixtureGLONE(GBase::DGetChildByName<Sprite *>(_NodeLight, "dh_xueyuanyjf_1"));
  GBase::DMixtureGLONE(GBase::DGetChildByName<Sprite *>(_NodeLight, "dh_xueyuanyjf_2"));
  GBase::DMixtureGLONE(GBase::DGetChildByName<Sprite *>(_NodeLight, "dh_xueyuanyjf_shader"));
  _AnimationBall->gotoFrameAndPlay(0, p_IsStudying);

  if(_IsEnter){
    _AnimationLight->gotoFrameAndPlay(0, true);
    GBase::DGetChildByName<Node *>(_NodeBall, "xuanzhuantai_normal")->setVisible(!p_IsStudying);
    GBase::DGetChildByName<Node *>(_NodeBall, "xuanzhuantai_studying")->setVisible(p_IsStudying);
    _NodeBall->runAction(MoveTo::create(0.5333333333333333, Vec2(0, 240)));
    _NodeLight->runAction(MoveTo::create(0.5333333333333333, Vec2(0, 240)));
    _AnimationBall->gotoFrameAndPlay(0, false);
    _AnimationLight->gotoFrameAndPlay(0, false);
    SetMainSingleEffect(p_IsStudying);
    for(auto l_Item : _TableBtn){
      auto l_Pos = l_Item.second->getPosition();
      l_Item.second->setPosition({0, 0});
      l_Item.second->RunFadeInAct(l_Pos.x, l_Pos.y);
    }
    _IsEnter = false;
    OnEnterGuide();
  }else{
    SetMainSingleEffect(p_IsStudying);
    GBase::DGetChildByName<Node *>(_NodeBall, "xuanzhuantai_normal")->setVisible(!p_IsStudying);
    GBase::DGetChildByName<Node *>(_NodeBall, "xuanzhuantai_studying")->setVisible(p_IsStudying);
  }
}

void UICollageView::TopStudyShow(bool p_IsStudy){
  _BottomNode->setVisible(!p_IsStudy);
  _NodeTimer->setVisible(p_IsStudy);
  _CenterNodeTechInfo->setVisible(p_IsStudy);
  if(p_IsStudy){
    auto l_Queue = TaskCtrl::Get()->QueryQueue(ETask::TechnologyUpgradeQ);
    _CcsStudying->InitData(_TableStuding._TechnologyID);
    _CcsStudying->HideNameLv();
    _CcsStudying->SetTimeVisble(false);
    _LabelStudyName->setString(ScienceRead::Get()->GetName(_TableStuding._TechnologyID));
    OpenTimeUp(0);
    _Timer = GBase::DCreateTimer(this, CC_CALLBACK_1(UICollageView::OpenTimeUp, this));
  }

  RefreshWaitQueue(nullptr);
  if(_NodeWait){
    _NodeWait->setVisible(p_IsStudy);
  }
}

void UICollageView::SetMainSingleEffect(bool p_Visible){
  for(auto l_Item : _TableBtn){
    l_Item.second->SetEffectVisible(p_Visible && l_Item.second->_Type == _StudyingType);
  }
}

void UICollageView::OpenTimeUp(float p_Dt){
  auto l_LeftTime = _Queue->GetRemainTime();
  auto l_TotalTime = _Queue->GetTotalTime();
  _TextTime->setString(GBase::DConvertSecondToString(l_LeftTime));
  _TimeBar->SetPercent((l_TotalTime - l_LeftTime) * 100 / l_TotalTime);
  if(l_LeftTime <= 0){
    GBase::DManagerRemoveTimer(_Timer);
    _Timer = nullptr;
    TopStudyShow(false);
  }
}


void UICollageView::BtnStudyClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != ui::Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  auto l_Btn = dynamic_cast<ui::Button *>(p_Sender);
  CCAssert(l_Btn, "l_Btn is nullptr");
  CCAssert(l_Btn->getUserData(), "l_Btn is not find");
  auto l_Science = (EScienceID *)l_Btn->getUserData();
  auto l_ScienceType = ScienceRead::Get()->GetType(*l_Science);
  auto l_Panel = UICollegeDetailsView::Create();
  l_Panel->InitData(*l_Science, l_ScienceType);
  l_Panel->Show();
  delete l_Science;
}

void UICollageView::BtnDetailClick(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != ui::Widget::TouchEventType::ENDED)
    return;
  auto l_Panel = UICollegeDetailsView::Create();
  l_Panel->InitData(_TableStuding._TechnologyID);
  l_Panel->Show();
}

void UICollageView::RefreshWaitQueue(EventCustom *p_Event){
  if(!_NodeWait)
    return;
  auto l_WaitQuque = WaitQueueCtrl::Get()->GetWaitQueueData(ETask::TechnologyUpgradeQ)->As<ScienceTask>();
  if(l_WaitQuque)
    _NodeWait->InitData(l_WaitQuque->_TechnologyID);
  else 
    _NodeWait->SetStateFree();
}

void UICollageView::OnEnterGuide(){
  // local guideCtrl = gametop.playertop_:getModule("guideCtrl")
  // guideCtrl:updateGuideModule(gGuideModule.TECH_GUIDE)
}