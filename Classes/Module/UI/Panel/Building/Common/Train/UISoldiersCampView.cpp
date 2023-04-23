#include "UISoldiersCampView.h"
#include "Module/Building/IBuilding.h"
#include "Module/Army/Army.Ctrl.h"
#include "Module/Army/Army.Logic.h"
#include "Module/World/WorldMap/WorldMap.Define.h"

UISoldiersCampView *UISoldiersCampView::Create(){
  auto l_Panel = UISoldiersCampView::Create("UiParts/Panel/Building/Common/Train/soldiersCampView.csb");
  return l_Panel;
}

void UISoldiersCampView::Ctor(){
  BindBtnClose();
  _NodeCenter = GBase::GetChildByName<Node *>(this, "Center_Node");
  GBase::GetChildByName<Sprite *>(this, "Sprite_return")->setLocalZOrder(1);
  _NodeArmyBase = GBase::GetChildByName<Node *>(this, "Node_armyBase");
  _NodeStarArmy = GBase::GetChildByName<Node *>(this, "Node_starArmy");
  _ImgSoldier = GBase::GetChildByName<ui::ImageView *>(this, "Image_army");
  _ImgSoldier->ignoreContentAdaptWithSize(true);
  _SoldierOriPos = _ImgSoldier->getPosition();
  _BtnPromote =  GBase::GetChildByName<ui::Button *>(this, "Image_army");
  _BtnPromote->setLocalZOrder(1);
  _BtnPromote->setTitleText(Translate::i18n("arms_promotion_btn_01"));
  _BtnPromote->setBright(false);
  _BtnPromote->setVisible(false);
  _NodeEliteSoldier = GBase::GetChildByName<Node *>(this, "Node_Spine_elite");
  _NodeEliteSoldier->setVisible(false);
  _NodeOwn = GBase::GetChildByName<Node *>(this, "Node_own");
  _NodeOwn->setLocalZOrder(1);
  _NodeHave = GBase::GetChildByName<Node *>(_NodeOwn, "Node_have");
  _BtnDissolve = GBase::GetChildByName<ui::Button *>(_NodeHave, "Button_dissolve");
  _IsWarForbid = WorldMapDefine::Get()->IsInWarForbidSoldier(true);
  if(_IsWarForbid)
    _BtnDissolve->setBright(false);
  _LabelHave = GBase::GetChildByName<ui::Text *>(this, "Text_have");
   GBase::GetChildByName<ui::ImageView *>(this, "Image_have")->setTouchEnabled(true);
  _NodeTrap = GBase::GetChildByName<Node *>(this, "Node_trap");
  _NodeTrap->setLocalZOrder(1);
  _NodeTrap->setVisible(false);
  _NodeTrapInfo = GBase::GetChildByName<Node *>(this, "Node_trapInfo");
  _BtnTrap = GBase::GetChildByName<ui::Button *>(this, "Button_trap");
  _BtnTrap->setVisible(false);
  _LabelTrap = GBase::GetChildByName<ui::Text *>(this, "Text_trap");
  GBase::GetChildByName<ui::ImageView *>(this, "Image_trapBg")->setTouchEnabled(true);
  _NodeResources = GBase::DGetExtendChildFromCCSByName<UICommonResourcesMenu>(this, "CCS_commonResourcesMenu_up");
  _NodeResources->SetNeedScale(true);
  _LabelLuckyDay = GBase::GetChildByName<ui::Text *>(this, "Text_luckyDay");
  _LabelLuckyDay->setVisible(false);
  _NodeElite = GBase::GetChildByName<Node *>(this, "Node_elite");
  _NodeElite->setLocalZOrder(1);
  _NodeElite->setVisible(false);
  _NodeEliteInfo = GBase::GetChildByName<Node *>(this, "Node_eliteInfo");
  _BtnElite = GBase::GetChildByName<ui::Button *>(this, "Button_elite");
  _LabelElite = GBase::GetChildByName<ui::Text *>(this, "Text_elite");
  _NodeBaseInfo = GBase::GetChildByName<Node *>(this, "Node_baseInfo");
  _NodeBaseInfo->setLocalZOrder(1);
  _BtnInfo = GBase::GetChildByName<ui::Button *>(_NodeBaseInfo, "Button_info");
  _NodeAttack = GBase::GetChildByName<Node *>(_NodeBaseInfo, "Node_attack");
  _LoadingBarAttack = GBase::GetChildByName<ui::LoadingBar *>(_NodeAttack, "LoadingBar_attack");
  _TableLoadingBar.push_back(_LoadingBarAttack);
  _TextAttack = GBase::GetChildByName<ui::Text *>(_NodeAttack, "Text_attack");
  _TableLabelTitle.push_back(_TextAttack);
  auto l_TextAttackValue = GBase::GetChildByName<ui::Text *>(_NodeAttack, "Text_attack_value");
  _TableLabelValues.push_back(l_TextAttackValue);
  auto l_TextAttackValueAdd = GBase::GetChildByName<ui::Text *>(_NodeAttack, "Text_attack_value_add");
  _TableLabelAddValues.push_back(l_TextAttackValueAdd);
  auto l_NodeDefend = GBase::GetChildByName<Node *>(_NodeBaseInfo, "Node_defend");
  auto l_LoadingBarDefend = GBase::GetChildByName<ui::LoadingBar *>(l_NodeDefend, "LoadingBar_defend");
  _TableLoadingBar.push_back(l_LoadingBarDefend);
  auto l_TextDefend = GBase::GetChildByName<ui::Text *>(l_NodeDefend, "Text_defend");
  _TableLabelTitle.push_back(l_TextDefend);
  auto l_TextDefendValue = GBase::GetChildByName<ui::Text *>(l_NodeDefend, "Text_defend_value");
  _TableLabelValues.push_back(l_TextDefendValue);
  auto l_TextDefendValueAdd = GBase::GetChildByName<ui::Text *>(l_NodeDefend, "Text_defend_value_add");
  _TableLabelAddValues.push_back(l_TextDefendValueAdd);
  auto l_NodeBlood = GBase::GetChildByName<Node *>(_NodeBaseInfo, "Node_blood");
  auto l_LoadingBarBlood = GBase::GetChildByName<ui::LoadingBar *>(l_NodeBlood, "LoadingBar_blood");
  _TableLoadingBar.push_back(l_LoadingBarBlood);
  auto l_TextBlood = GBase::GetChildByName<ui::Text *>(l_NodeBlood, "Text_blood");
  _TableLabelTitle.push_back(l_TextBlood);
  auto l_TextBloodValue = GBase::GetChildByName<ui::Text *>(l_NodeBlood, "Text_blood_value");
  _TableLabelValues.push_back(l_TextBloodValue);
  auto l_TextBloodValueAdd = GBase::GetChildByName<ui::Text *>(l_NodeBlood, "Text_blood_value_add");
  _TableLabelAddValues.push_back(l_TextBloodValueAdd);
  // SoraDGetChildByName(self, "Image_bbg"):setFillType(1)
  _ImgLine = GBase::GetChildByName<ui::ImageView *>(this, "Image_line");
  _NodeTrain = GBase::GetChildByName<Node *>(this, "Node_train");
  _NodeTrainInfo = GBase::GetChildByName<Node *>(_NodeTrain, "Node_trainInfo");
  _NodeSlider = GBase::DGetExtendChildFromCCSByName<UICommonSlider>(_NodeTrainInfo, "CCS_commonSlider_slider");
  _NodeSlider->SetMask(this);
  _BtnTrainNow = GBase::DGetExtendChildFromCCSByName<UICommonGoldNormalBtn>(_NodeTrainInfo, "CCS_commonGoldNormalBtn_trainNow");
  _BtnTrainNow->InitData({}, UICommonGoldNormalBtn::EShowType::Gold);
  _NodeTrainBtn = GBase::GetChildByName<Node *>(_NodeTrainInfo, "Node_trainBtn");
  _BtnTrain = GBase::GetChildByName<ui::Button *>(_NodeTrainBtn, "Button_train");
  _NodeTrainTime = GBase::GetChildByName<Node *>(_NodeTrainBtn, "Node_trainTime");
  _LabelTrainTime = GBase::GetChildByName<ui::Text *>(_NodeTrainTime, "Text_trainTime");
  _LabelEliteNotice = GBase::GetChildByName<ui::Text *>(_NodeTrainBtn, "Text_eliteNotice");
  _LabelEliteNotice->setString(Translate::i18n("common_text_3231"));
  _NodeToolInfo = GBase::GetChildByName<Node *>(_NodeTrainInfo, "Node_tool_info");
  _NodeToolInfo->setVisible(false);
  _LabelToolLeftTimes = GBase::GetChildByName<ui::Text *>(_NodeToolInfo, "Text_toolLeftTimes");
  _LabelToolAddValue = GBase::GetChildByName<ui::Text *>(_NodeToolInfo, "Text_toolAddValue");
  _BtnTip = GBase::GetChildByName<ui::Button *>(_NodeToolInfo, "Button_tip");
  _BtnTool = GBase::GetChildByName<ui::Button *>(_NodeTrainInfo, "Button_tool");
  _BtnTool->setVisible(false);
  _NodeUnTrain = GBase::GetChildByName<Node *>(_NodeTrain, "Node_untrain");
  _BtnJump = GBase::GetChildByName<ui::Button *>(_NodeUnTrain, "Button_jump");
  _LabelDes = GBase::GetChildByName<ui::Text *>(_NodeTrain, "Text_des");
  _BtnJump->setTitleText(Translate::i18n("common_text_477"));
  _NodeTrainQueue = GBase::GetChildByName<Node *>(this, "Node_trainQueue");
  _LabelName = GBase::GetChildByName<ui::Text *>(_NodeTrainQueue, "Text_name");
  _BtnSpeedUp = GBase::DGetExtendChildFromCCSByName<UICommonGoldNormalBtn>(_NodeTrainQueue, "CCS_commonGoldNormalBtn_speedUp");
  UICommonGoldNormalBtn::RInitDataParm l_Parm;
  l_Parm._Title = Translate::i18n("common_text_018");
  _BtnSpeedUp->InitData(l_Parm, UICommonGoldNormalBtn::EShowType::Gold);
  _BtnSpeedUpTool = GBase::GetChildByName<ui::Button *>(_NodeTrainQueue, "Button_speedUpTool");
  _LabelSpeedUpTool = GBase::GetChildByName<ui::Text *>(_BtnSpeedUpTool, "Text_speedUpTool");
  _LabelSpeedUpTool->setString(Translate::i18n("common_text_018"));
  _NodeBar = GBase::DGetExtendChildFromCCSByName<UICommonProgressBar>(_NodeTrainQueue, "CCS_commonProgressBar_speedUp");
  _LoadingBarChild = GBase::GetChildByName<ui::LoadingBar *>(_NodeBar, "LoadingBar_progress");
  _LabelSpeedUpTime = GBase::GetChildByName<ui::Text *>(_NodeBar, "Text_speedUpTime");
  _TipLayout = GBase::GetChildByName<ui::Layout *>(this, "Panel_tip");
  _TipLayout->setSwallowTouches(false);
  _LabelTip1 = GBase::GetChildByName<ui::Text *>(_TipLayout, "Text_tip1");
  _LabelTip2 = GBase::GetChildByName<ui::Text *>(_TipLayout, "Text_tip2");
  _BtnWear = GBase::GetChildByName<ui::Button *>(this, "Button_Wear");
  _BtnWear->setTitleText(Translate::i18n("Soldiers_armor_text_26"));
  _BtnWear->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnWearClickCallBack, this));
  _NodeSkill = GBase::GetChildByName<Node *>(this, "Node_skill");
  for (int i = 1; i <= 4; ++i)
  {
    auto l_NodeName = "CCS_soldierSkillSingle_" + std::to_string(i);
    auto l_SkillSingle = GBase::DGetExtendChildFromCCSByName<UISoldierSkillSingle>(_NodeSkill, l_NodeName.c_str());
    _TableSkill._Node.push_back(l_SkillSingle);
  }

  _BtnElite->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnEliteClickCallBack, this));
  _BtnTrain->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnTrainClickCallBack, this));
  _BtnTrainNow->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnTrainNowClickCallBack, this));
  _BtnSpeedUp->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnSpeedUpClickCallBack, this));
  _BtnSpeedUpTool->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnSpeedUpToolClickCallBack, this));
  _BtnInfo->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnInfoClickCallBack, this));
  _BtnDissolve->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnDissolveClickCallBack, this));
  _BtnTool->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnToolClickCallBack, this));
  _BtnTrap->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnTrapMsgClickCallBack, this));
  _BtnTip->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnTipClickCallBack, this));
  _BtnPromote->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnPromoteClickCallBack, this));
  _BtnJump->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnJumpClickCallBack, this));
  _NodeSlider->SetSliderCallBack(CC_CALLBACK_1(UISoldiersCampView::TrainSoldierSlider, this));

  if(GDisplay::Get()->height  < 960)
  {
    _NodeBaseInfo->setPositionY(0);
    _NodeOwn->setPositionY(-90);
    _NodeTrap->setPositionY(-50);
    _NodeElite->setPositionY(-50);
    _NodeArmyBase->setPositionY(-80);
    _ImgSoldier->setPositionY(-110);
    _SoldierOriPos.y = _ImgSoldier->getPositionY();
    _NodeEliteSoldier->setPositionY(-80);
    _NodeSkill->setPositionY(305);
  }
  else
  {
    _NodeBaseInfo->setPositionY(GDisplay::Get()->height / 2 - 130);
  }
  _TrapPos = Vec2(_ImgSoldier->getPositionX() - 10, _ImgSoldier->getPositionY() + 100);
  _TrapBasePos = Vec2(_NodeArmyBase->getPositionX(), _NodeArmyBase->getPositionY() + 40);
  UpdateLuckyBless();
  // self.trainSoldiersLog = SoraDConfigGet("Game:SoldiersCampView:trainSoldiersLog~table", {byUID = true})
  // if not self.trainSoldiersLog then
  //   self.trainSoldiersLog = {}
  // end
}

void UISoldiersCampView::InitData(EBuildingIndex p_Index, IBuilding *p_Building, EArmy p_ArmyType){
  // self.tableCurSoldier.bid = bid
  _TableCurSoldier._Bid = p_Building->GetBuildingId();
  // self.tableCurSoldier.type = type
  _TableCurSoldier._Type = p_ArmyType;
  // self.tableCurSoldier.index = index
  _TableCurSoldier._Index = p_Index;
  // self.buildEntity = buildEntity
  _BuildEntity = p_Building;
  // self:iniResSingle()
  InitResSingle();
  // local trainedArmy = armyCtrl:getTrainArmy(self.tableCurSoldier.bid)
  auto l_TrainedArmy = ArmyCtrl::Get()->GetTrainArmy(_TableCurSoldier._Bid);
  // if trainedArmy ~= nil then
  //   armyCtrl:getTrainArmyReq(self.tableCurSoldier.bid)
  // end
  if(l_TrainedArmy != EArmy::None)
  {
    ArmyCtrl::Get()->GetTrainArmyReq(_TableCurSoldier._Bid);
  }
  
  auto l_CurIndex = 0;
  auto l_TableSoldierList = ArmyLogic::Get()->GetCanTrainList(_TableCurSoldier._Bid);
  _TableSoldierList = l_TableSoldierList.First;
  l_CurIndex = l_TableSoldierList.Second;
  if(l_CurIndex == -1){
   //   local trainLog = self.trainSoldiersLog[tostring(bid)]
    //   if not trainLog then
    //     self.curIndex = curIndex
    //     self.trainSoldiersLog[tostring(bid)] = {
    //       maxArmyId = self.tableSoldierList[curIndex].armyid,
    //       trainArmyId = self.tableSoldierList[curIndex].armyid
    //     }
    //   else
    //     local newTrainArmyId = self.tableSoldierList[curIndex].armyid
    //     if newTrainArmyId ~= trainLog.maxArmyId then
    //       self.curIndex = curIndex
    //       trainLog.maxArmyId = newTrainArmyId
    //     else
    //       local lastTrainArmyId = trainLog.trainArmyId
    //       for i, v in ipairs(self.tableSoldierList) do
    //         if v.armyid == lastTrainArmyId then
    //           self.curIndex = i
    //           break
    //         end
    //       end
    //       if not self.curIndex then
    //         self.curIndex = curIndex
    //       end
    //     end
    //   end
  }else{
    //   local trainLog = self.trainSoldiersLog[tostring(bid)]
    //   if not trainLog then
    //     self.trainSoldiersLog[tostring(bid)] = {
    //       maxArmyId = self.tableSoldierList[curIndex].armyid,
    //       trainArmyId = self.tableSoldierList[curIndex].armyid
    //     }
    //   end
  }
  // self.trianQueue = queueCtrl:queryQueue(buildRead.getQueueType(self.tableCurSoldier.bid))
  // if self.tableCurSoldier.type == TRAIN_TYPE.SOLDIERS then
  //   self.btnTrain:setTitleText(i18n("common_text_061"))
  //   self.btnTrainNow:setTitleStr(i18n("common_text_317"))
  // else
  //   self.btnTrain:setTitleText(i18n("common_text_042"))
  //   self.btnTrainNow:setTitleStr(i18n("common_text_379"))
  // end
  // if self.trianQueue then
  //   self:isTraining(true)
  // else
  //   self:isTraining(false)
  // end
  // if self.selectWheel == nil then
  //   self:createWheelScrollView()
  //   self.selectWheel:setVisible(false)
  //   self:runAction(cca.seq({
  //     cca.callFunc(function(...)
  //       self.selectWheel:unfoldAction(0.3)
  //       self.selectWheel:setVisible(true)
  //     end)
  //   }))
  // end
}

void UISoldiersCampView::InitWidget(){

}
