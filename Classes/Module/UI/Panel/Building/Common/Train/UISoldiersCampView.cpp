#include "UISoldiersCampView.h"
#include "spine/spine-cocos2dx.h"
#include "UISoldiersTrainScrollSingle.h"
#include "UISoldiersDetail.View.h"
#include "UIDissolveSoldiers.View.h"
#include "Module/Building/BuildingUnit/Base/IBuildingArmy.h"
#include "Module/Building/Building.Logic.h"
#include "Module/Army/Army.Ctrl.h"
#include "Module/Army/Army.Logic.h"
#include "Module/World/WorldMap/WorldMap.Define.h"
#include "Module/UI/Part/Common/Msg/UICommonHelpMsgBox.h"
#include "Module/Task/Task.Ctrl.h"
#include "Module/UI/Part/UIWheelScrollView.h"
#include "Module/UI/UI.Create.h"
#include "Module/UI/Part/Common/Resource/UIBuildCreateResBuySingle.h"
#include "Module/UI/Panel/Common/SpeedUp/UICommonSpeedUpByItemBox.h"
#include "Module/UI/Panel/Common/BuyRes/UITrainArmyLimit.View.h"
#include "Base/Common/Common.Func.h"
#include "Base/Common/Common.Box.h"
#include "Base/Common/Common.Msg.h"
#include "Base/Common/Panel.Manger.h"
#include "Base/Common/Common.Teml.h"
#include "Module/Army/Army.Read.h"
#include "Module/Army/Army.LtCtrl.h"
#include "Module/CityResource/Resource.Read.h"


UISoldiersCampView *UISoldiersCampView::Create(){
  auto l_Panel = UISoldiersCampView::Create("UiParts/Panel/Building/Common/Train/soldiersCampView.csb");
  return l_Panel;
}

void UISoldiersCampView::Ctor(){
  BindBtnClose();
  _NodeCenter = GBase::DGetChildByName<Node *>(this, "Center_Node");
  GBase::DGetChildByName<Sprite *>(this, "Sprite_return")->setLocalZOrder(1);
  _NodeArmyBase = GBase::DGetChildByName<Node *>(this, "Node_armyBase");
  _NodeStarArmy = GBase::DGetChildByName<Node *>(this, "Node_starArmy");
  _ImgSoldier = GBase::DGetChildByName<ui::ImageView *>(this, "Image_army");
  _ImgSoldier->ignoreContentAdaptWithSize(true);
  _SoldierOriPos = _ImgSoldier->getPosition();
  _BtnPromote =  GBase::DGetChildByName<ui::Button *>(this, "Image_army");
  _BtnPromote->setLocalZOrder(1);
  _BtnPromote->setTitleText(Translate::i18n("arms_promotion_btn_01"));
  _BtnPromote->setBright(false);
  _BtnPromote->setVisible(false);
  _NodeEliteSoldier = GBase::DGetChildByName<Node *>(this, "Node_Spine_elite");
  _NodeEliteSoldier->setVisible(false);
  _NodeOwn = GBase::DGetChildByName<Node *>(this, "Node_own");
  _NodeOwn->setLocalZOrder(1);
  _NodeHave = GBase::DGetChildByName<Node *>(_NodeOwn, "Node_have");
  _BtnDissolve = GBase::DGetChildByName<ui::Button *>(_NodeHave, "Button_dissolve");
  _IsWarForbid = WorldMapDefine::Get()->IsInWarForbidSoldier(true);
  if(_IsWarForbid)
    _BtnDissolve->setBright(false);
  _LabelHave = GBase::DGetChildByName<ui::Text *>(this, "Text_have");
   GBase::DGetChildByName<ui::ImageView *>(this, "Image_have")->setTouchEnabled(true);
  _NodeTrap = GBase::DGetChildByName<Node *>(this, "Node_trap");
  _NodeTrap->setLocalZOrder(1);
  _NodeTrap->setVisible(false);
  _NodeTrapInfo = GBase::DGetChildByName<Node *>(this, "Node_trapInfo");
  _BtnTrap = GBase::DGetChildByName<ui::Button *>(this, "Button_trap");
  _BtnTrap->setVisible(false);
  _LabelTrap = GBase::DGetChildByName<ui::Text *>(this, "Text_trap");
  GBase::DGetChildByName<ui::ImageView *>(this, "Image_trapBg")->setTouchEnabled(true);
  _NodeResources = GBase::DGetExtendChildFromCCSByName<UICommonResourcesMenu>(this, "CCS_commonResourcesMenu_up");
  _NodeResources->SetNeedScale(true);
  _LabelLuckyDay = GBase::DGetChildByName<ui::Text *>(this, "Text_luckyDay");
  _LabelLuckyDay->setVisible(false);
  _NodeElite = GBase::DGetChildByName<Node *>(this, "Node_elite");
  _NodeElite->setLocalZOrder(1);
  _NodeElite->setVisible(false);
  _NodeEliteInfo = GBase::DGetChildByName<Node *>(this, "Node_eliteInfo");
  _BtnElite = GBase::DGetChildByName<ui::Button *>(this, "Button_elite");
  _LabelElite = GBase::DGetChildByName<ui::Text *>(this, "Text_elite");
  _NodeBaseInfo = GBase::DGetChildByName<Node *>(this, "Node_baseInfo");
  _NodeBaseInfo->setLocalZOrder(1);
  _BtnInfo = GBase::DGetChildByName<ui::Button *>(_NodeBaseInfo, "Button_info");
  _NodeAttack = GBase::DGetChildByName<Node *>(_NodeBaseInfo, "Node_attack");
  _LoadingBarAttack = GBase::DGetChildByName<ui::LoadingBar *>(_NodeAttack, "LoadingBar_attack");
  _TableLoadingBar.push_back(_LoadingBarAttack);
  _TextAttack = GBase::DGetChildByName<ui::Text *>(_NodeAttack, "Text_attack");
  _TableLabelTitle.push_back(_TextAttack);
  auto l_TextAttackValue = GBase::DGetChildByName<ui::Text *>(_NodeAttack, "Text_attack_value");
  _TableLabelValues.push_back(l_TextAttackValue);
  auto l_TextAttackValueAdd = GBase::DGetChildByName<ui::Text *>(_NodeAttack, "Text_attack_value_add");
  _TableLabelAddValues.push_back(l_TextAttackValueAdd);
  auto l_NodeDefend = GBase::DGetChildByName<Node *>(_NodeBaseInfo, "Node_defend");
  auto l_LoadingBarDefend = GBase::DGetChildByName<ui::LoadingBar *>(l_NodeDefend, "LoadingBar_defend");
  _TableLoadingBar.push_back(l_LoadingBarDefend);
  auto l_TextDefend = GBase::DGetChildByName<ui::Text *>(l_NodeDefend, "Text_defend");
  _TableLabelTitle.push_back(l_TextDefend);
  auto l_TextDefendValue = GBase::DGetChildByName<ui::Text *>(l_NodeDefend, "Text_defend_value");
  _TableLabelValues.push_back(l_TextDefendValue);
  auto l_TextDefendValueAdd = GBase::DGetChildByName<ui::Text *>(l_NodeDefend, "Text_defend_value_add");
  _TableLabelAddValues.push_back(l_TextDefendValueAdd);
  auto l_NodeBlood = GBase::DGetChildByName<Node *>(_NodeBaseInfo, "Node_blood");
  auto l_LoadingBarBlood = GBase::DGetChildByName<ui::LoadingBar *>(l_NodeBlood, "LoadingBar_blood");
  _TableLoadingBar.push_back(l_LoadingBarBlood);
  auto l_TextBlood = GBase::DGetChildByName<ui::Text *>(l_NodeBlood, "Text_blood");
  _TableLabelTitle.push_back(l_TextBlood);
  auto l_TextBloodValue = GBase::DGetChildByName<ui::Text *>(l_NodeBlood, "Text_blood_value");
  _TableLabelValues.push_back(l_TextBloodValue);
  auto l_TextBloodValueAdd = GBase::DGetChildByName<ui::Text *>(l_NodeBlood, "Text_blood_value_add");
  _TableLabelAddValues.push_back(l_TextBloodValueAdd);
  // SoraDGetChildByName(self, "Image_bbg"):setFillType(1)
  _ImgLine = GBase::DGetChildByName<ui::ImageView *>(this, "Image_line");
  _NodeTrain = GBase::DGetChildByName<Node *>(this, "Node_train");
  _NodeTrainInfo = GBase::DGetChildByName<Node *>(_NodeTrain, "Node_trainInfo");
  _NodeSlider = GBase::DGetExtendChildFromCCSByName<UICommonSlider>(_NodeTrainInfo, "CCS_commonSlider_slider");
  _NodeSlider->SetMask(this);
  _BtnTrainNow = GBase::DGetExtendChildFromCCSByName<UICommonGoldNormalBtn>(_NodeTrainInfo, "CCS_commonGoldNormalBtn_trainNow");
  _BtnTrainNow->InitData({}, UICommonGoldNormalBtn::EShowType::Gold);
  _NodeTrainBtn = GBase::DGetChildByName<Node *>(_NodeTrainInfo, "Node_trainBtn");
  _BtnTrain = GBase::DGetChildByName<ui::Button *>(_NodeTrainBtn, "Button_train");
  _NodeTrainTime = GBase::DGetChildByName<Node *>(_NodeTrainBtn, "Node_trainTime");
  _LabelTrainTime = GBase::DGetChildByName<ui::Text *>(_NodeTrainTime, "Text_trainTime");
  _LabelEliteNotice = GBase::DGetChildByName<ui::Text *>(_NodeTrainBtn, "Text_eliteNotice");
  _LabelEliteNotice->setString(Translate::i18n("common_text_3231"));
  _NodeToolInfo = GBase::DGetChildByName<Node *>(_NodeTrainInfo, "Node_tool_info");
  _NodeToolInfo->setVisible(false);
  _LabelToolLeftTimes = GBase::DGetChildByName<ui::Text *>(_NodeToolInfo, "Text_toolLeftTimes");
  _LabelToolAddValue = GBase::DGetChildByName<ui::Text *>(_NodeToolInfo, "Text_toolAddValue");
  _BtnTip = GBase::DGetChildByName<ui::Button *>(_NodeToolInfo, "Button_tip");
  _BtnTool = GBase::DGetChildByName<ui::Button *>(_NodeTrainInfo, "Button_tool");
  _BtnTool->setVisible(false);
  _NodeUnTrain = GBase::DGetChildByName<Node *>(_NodeTrain, "Node_untrain");
  _BtnJump = GBase::DGetChildByName<ui::Button *>(_NodeUnTrain, "Button_jump");
  _LabelDes = GBase::DGetChildByName<ui::Text *>(_NodeTrain, "Text_des");
  _BtnJump->setTitleText(Translate::i18n("common_text_477"));
  _NodeTrainQueue = GBase::DGetChildByName<Node *>(this, "Node_trainQueue");
  _LabelName = GBase::DGetChildByName<ui::Text *>(_NodeTrainQueue, "Text_name");
  _BtnSpeedUp = GBase::DGetExtendChildFromCCSByName<UICommonGoldNormalBtn>(_NodeTrainQueue, "CCS_commonGoldNormalBtn_speedUp");
  UICommonGoldNormalBtn::RInitDataParm l_Parm;
  l_Parm._Title = Translate::i18n("common_text_018");
  _BtnSpeedUp->InitData(l_Parm, UICommonGoldNormalBtn::EShowType::Gold);
  _BtnSpeedUpTool = GBase::DGetChildByName<ui::Button *>(_NodeTrainQueue, "Button_speedUpTool");
  _LabelSpeedUpTool = GBase::DGetChildByName<ui::Text *>(_BtnSpeedUpTool, "Text_speedUpTool");
  _LabelSpeedUpTool->setString(Translate::i18n("common_text_018"));
  _NodeBar = GBase::DGetExtendChildFromCCSByName<UICommonProgressBar>(_NodeTrainQueue, "CCS_commonProgressBar_speedUp");
  _LoadingBarChild = GBase::DGetChildByName<ui::LoadingBar *>(_NodeBar, "LoadingBar_progress");
  _LabelSpeedUpTime = GBase::DGetChildByName<ui::Text *>(_NodeBar, "Text_speedUpTime");
  _TipLayout = GBase::DGetChildByName<ui::Layout *>(this, "Panel_tip");
  _TipLayout->setSwallowTouches(false);
  _LabelTip1 = GBase::DGetChildByName<ui::Text *>(_TipLayout, "Text_tip1");
  _LabelTip2 = GBase::DGetChildByName<ui::Text *>(_TipLayout, "Text_tip2");
  _BtnWear = GBase::DGetChildByName<ui::Button *>(this, "Button_Wear");
  _BtnWear->setTitleText(Translate::i18n("Soldiers_armor_text_26"));
  _BtnWear->addTouchEventListener(CC_CALLBACK_2(UISoldiersCampView::BtnWearClickCallBack, this));
  _NodeSkill = GBase::DGetChildByName<Node *>(this, "Node_skill");
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

void UISoldiersCampView::InitData(EBuildingIndex p_Index, IBuilding *p_Building, ETrainType p_TrainType){

  _TableCurSoldier._Bid = p_Building->GetBuildingId();
  _TableCurSoldier._Type = p_TrainType;
  _TableCurSoldier._Index = p_Index;
  _BuildEntity = p_Building;
  InitResSingle();
  auto l_TrainedArmy = ArmyCtrl::Get()->GetTrainArmy(_TableCurSoldier._Bid);
  if(l_TrainedArmy != EArmy::None)
    ArmyCtrl::Get()->GetTrainArmyReq(_TableCurSoldier._Bid);
  
  auto l_CurIndex = 0;
  auto l_TableSoldierList = ArmyLogic::Get()->GetCanTrainList(_TableCurSoldier._Bid);
  _TableSoldierList = l_TableSoldierList.First;
  l_CurIndex = l_TableSoldierList.Second;
  if(l_CurIndex == -1){
    if(!_TrainSoldiersLog.Contains(p_Building->GetBuildingId())){
      _CurIndex = l_CurIndex;
      auto l_TempTrainSolLog = RTrainSoldiersLog();
      l_TempTrainSolLog._MaxArmyId = _TableSoldierList[_CurIndex]._ArmyId;
      l_TempTrainSolLog._TrainArmyId = _TableSoldierList[_CurIndex]._ArmyId;
      _TrainSoldiersLog[p_Building->GetBuildingId()] = l_TempTrainSolLog;
    }else{
      auto l_NewTrainArmyId = _TableSoldierList[l_CurIndex]._ArmyId;
      if(l_NewTrainArmyId != _TrainSoldiersLog[p_Building->GetBuildingId()]._MaxArmyId){
        _CurIndex = l_CurIndex;
        _TrainSoldiersLog[p_Building->GetBuildingId()]._MaxArmyId = l_NewTrainArmyId;
      }else{
        auto l_LastTrainArmyId = _TrainSoldiersLog[p_Building->GetBuildingId()]._TrainArmyId;
        for(auto i = 0; i < _TableSoldierList.size(); ++i){
          if(_TableSoldierList[i]._ArmyId == l_LastTrainArmyId){
            _CurIndex = i;
            break;
          }
        }
        if(!_CurIndex)
          _CurIndex = l_CurIndex;
      }
    }
  }else{
    if(!_TrainSoldiersLog.Contains(p_Building->GetBuildingId())){
      auto l_TempTrainSolLog = RTrainSoldiersLog();
      l_TempTrainSolLog._MaxArmyId = _TableSoldierList[_CurIndex]._ArmyId;
      l_TempTrainSolLog._TrainArmyId = _TableSoldierList[_CurIndex]._ArmyId;
      _TrainSoldiersLog[p_Building->GetBuildingId()] = l_TempTrainSolLog;
    }
  }

  _TrainQueue = TaskCtrl::Get()->QueryQueue(BuildingRead::Get()->GetQueueType(p_Building->GetBuildingId()));
  if(_TableCurSoldier._Type == ETrainType::Soldiers){
    _BtnTrain->setTitleText(Translate::i18n("common_text_061"));
    _BtnTrainNow->SetTitleStr(Translate::i18n("common_text_317"));
  }else{
    _BtnTrain->setTitleText(Translate::i18n("common_text_042"));
    _BtnTrainNow->SetTitleStr(Translate::i18n("common_text_379"));
  }
  if(_TrainQueue)
    IsTraining(true);
  else
    IsTraining(false);
  if(!_SelectWheel){
    CreateWheelScrollView();
    _SelectWheel->setVisible(false);
    runAction(Sequence::create(CallFunc::create([this](){
      _SelectWheel->UnfoldAction(0.3f);
      _SelectWheel->setVisible(true);
    }), nullptr));
  }
}

void UISoldiersCampView::InitResSingle(){
  
  auto l_CanUseRes = 0;
  l_CanUseRes += GBase::DResIsLock(EResource::Food) ? 1 : 0;
  l_CanUseRes += GBase::DResIsLock(EResource::Wood) ? 1 : 0;
  l_CanUseRes += GBase::DResIsLock(EResource::Iron) ? 1 : 0;
  l_CanUseRes += GBase::DResIsLock(EResource::Mithril) ? 1 : 0;
  l_CanUseRes += GBase::DResIsLock(EResource::Crystal) ? 1 : 0;

  auto l_StartX = 480.0f;
  auto l_SingleW = 106.67f;
  if(_TableCurSoldier._Bid == EBuilding::ElitePalace){
    l_CanUseRes += 1;
    l_StartX += 53.335f;
    _NodeTrainBtn->setPositionX(GBase::DFSign(320.0f));
  }
  for(auto iii = 0; iii < l_CanUseRes; ++iii){
    UIBuildCreateResBuySingle *l_Single = nullptr;
    if(_TableResSingle.size() > iii){
      l_Single = _TableResSingle[iii];
    }else{
      l_Single = UIBuildCreateResBuySingle::Create();
      _NodeTrainInfo->addChild(l_Single);
      _TableResSingle.push_back(l_Single);
    }
    l_Single->setPosition(Vec2(l_StartX - l_SingleW * (iii), _LuckyBlessIsOpen ? 210.0f : 200.0f));
    GBase::DFTarget(l_Single);
  }
  UpdateResSingleAlign(l_CanUseRes);
}

void UISoldiersCampView::IsTraining(bool p_Is){
  // self.nodeTrainQueue:setVisible(isTrain)
  // self.nodeTrain:setVisible(not isTrain)
  // if isTrain then
  //   self:updateSpeedUpTool()
  //   self.imgLine:setPositionY(180)
  //   self.labelName:setString(armyDes.getName(self.trianQueue.data.armyid))
  //   self.timer = SoradCreateTimer(self, handler(self, self.openTimeUp))
  //   self:openTimeUp()
  // else
  //   self.imgLine:setPositionY(100)
  //   self.labelName:setString("")
  //   if self.timer then
  //     SoraDManagerRemoveTimer(self, self.timer)
  //     self.timer = nil
  //   end
  // end
}

void UISoldiersCampView::UpdateResSingleAlign(int32 p_Num){
  auto l_StartX = 480.0f;
  auto l_SingleW = 106.67f;
  if(p_Num > 4)
    l_StartX += 53.335f;
  for (auto iii  = 0; iii < p_Num; iii++){
    auto l_Single = _TableResSingle[iii];
    if(l_Single){
      l_Single->setPosition(Vec2(l_StartX - l_SingleW * (iii), _LuckyBlessIsOpen ? 210.0f : 200.0f));
      GBase::DFTarget(l_Single);
    }
  }
}


void UISoldiersCampView::CreateWheelScrollView(){
  _SoldierArray.clear();
  // local armyData = gModuleMgr.sharedMgr("mildGuideManager"):getVariate(self.__cname)
  // if armyData and armyData.bid == self.tableCurSoldier.bid and armyData.lv and armyData.lv <= #self.tableSoldierList then
  //   self.curIndex = armyData.lv
  // end
  for(auto i = 0; i < _TableSoldierList.size(); ++i){
    auto l_Item = UISoldiersTrainScrollSingle::Create();
    _SoldierArray.push_back(l_Item);
  }
  auto l_Size =  Size(500.f, std::max(600.f, Director::getInstance()->getVisibleSize().height - 270));
  _SelectWheel = UICreate::Get()->DCreateWheelScrollView(_SoldierArray,l_Size , 130, 450, 0, true);
  if(_SelectWheel){
    _SelectWheel->SetItemSelectedListener([this](int32 p_Index, Node *p_Node){
      this->WheelScrollBack(_TableSoldierList[p_Index]);
    });
    _SelectWheel->setPosition(Vec2(0, std::min(-165.f, 270 - _NodeCenter->getPositionY())));
    _NodeCenter->addChild(_SelectWheel, 0);
    _SelectWheel->selectedCellIndex(_CurIndex);
    _SelectWheel->setInertiaValue(0.1f);
    GBase::DFTarget(_SelectWheel);
  }
}

void UISoldiersCampView::TrainSoldierSlider(float p_Value){
  _TableCurSoldier._ArmyCount = p_Value;
  UpdateTrainNode(nullptr);
}

void UISoldiersCampView::UpdateView(EventCustom *p_Event){

  static EArmy l_ArmyId ;
  l_ArmyId = _TableCurSoldier._ArmyData._ArmyId;
  auto l_ModelType = ArmyRead::Get()->GetModelType(l_ArmyId);
  auto l_Alv = ArmyLogic::Get()->GetArmyLV(l_ArmyId);

  if(ArmyLtCtrl::Get()->GetSoldierType(l_ArmyId) == ESoldierType::Elite){
    //     local spine, scale = eliteSoldiersDef.getSpineByModelType(modelType, alv)
    //     if spine then
    //       self.imgSoldier:setVisible(false)
    //       self.node_eliteSoldier:setVisible(false)
    //       self.node_eliteSoldier:removeAllChildren()
    //       self.node_eliteSoldier:setScale(scale)
    //       spine:addTo(self.node_eliteSoldier)
    //       spine:setAnimation(0, "animation", true)
    //       self:runAction(cca.seq({
    //         cca.delay(0.05),
    //         cca.callFunc(function()
    //           self.node_eliteSoldier:setVisible(true)
    //           self:soldierEnterAct(spine, scale)
    //         end)
    //       }))
    //     else
    //       self.node_eliteSoldier:setVisible(false)
    //       self.imgSoldier:loadTexture(armyDes.getPortrait(self.tableCurSoldier.armyData.armyid), ccui.TextureResType.plistType)
    //       self.imgSoldier:setVisible(true)
    //       self:soldierEnterAct(self.imgSoldier, 0.9)
    //     end
  }else if(ArmyLogic::Get()->IsStarArmy(l_ArmyId) && _TableCurSoldier._ArmyData._IsCanTrain){
    if(!_NodeEffect){
      _NodeEffect = GBase::DCreateAnimation("UiParts/Animation/Army/animationArmyStarBase.csb").First;
      //     local et_Par_1 = SoraDGetChildByName(self.node_effect, "et_Par_1")
      //     if et_Par_1 then
      //       et_Par_1:setAutoCull(false)
      //     end
      //     local et_Par_2 = SoraDGetChildByName(self.node_effect, "et_Par_2")
      //     if et_Par_2 then
      //       et_Par_2:setAutoCull(false)
      //     end
      _NodeStarArmy->addChild(_NodeEffect);
    }else{
      _NodeEffect->setVisible(true);
    }
    auto l_Spine = ArmyRead::Get()->GetSpecialArmyCfg(l_ArmyId, true);
    if(l_Spine._SpineAnim){
      _ImgSoldier->setVisible(false);
      _NodeEliteSoldier->setVisible(true);
      if(!_NodeEliteSoldier->getUserData()/*self.node_eliteSoldier.armyID and self.node_eliteSoldier.armyID ~= self.tableCurSoldier.armyData.armyid or not self.node_eliteSoldier.armyID*/){
        _NodeEliteSoldier->setVisible(false);
        _NodeEliteSoldier->removeAllChildren();
        _NodeEliteSoldier->setScale(l_Spine._Scale.x, l_Spine._Scale.y);
      _NodeEliteSoldier->addChild(l_Spine._SpineAnim);
      l_Spine._SpineAnim->setAnimation(0, "animation", true);
        runAction(
          Sequence::create(
            DelayTime::create(0.05f), 
            CallFunc::create([=](){
              _NodeEliteSoldier->setVisible(true);
              SoldierEnterAct(_NodeEliteSoldier, l_Spine._Scale.x);
              _NodeEliteSoldier->setUserData((void*)l_ArmyId);
        }), nullptr));
      }
    }else{
      _ImgSoldier->setVisible(true);
      _ImgSoldier->loadTexture(ArmyRead::Get()->GetPortrait(l_ArmyId), TextureResType::PLIST);
      SoldierEnterAct(_ImgSoldier, 0.9f);
      _NodeEliteSoldier->setVisible(false);
    }
  }else{
    _ImgSoldier->setVisible(true);
    _ImgSoldier->loadTexture(ArmyRead::Get()->GetPortrait(l_ArmyId), TextureResType::PLIST);
    SoldierEnterAct(_ImgSoldier, 0.9f);
    _NodeEliteSoldier->setVisible(false);
    if(_NodeEffect){
      _NodeEffect->setVisible(false);
    }
  }

  if(_TableCurSoldier._Type == ETrainType::Soldiers){
    UpdateSoldiersView();
    _NodeTrap->setVisible(false);
    SoldierEnterAct(_ImgSoldier, 0.9f);
    //   local config = armyDes.getArmySuitConfig(self.tableCurSoldier.bid, alv)
    //   if config then
    //     local isBzt = SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE
    //     self.imgSoldier:setScale(isBzt and config.scale_bzt or config.scale)
    //     local offset = isBzt and config.offset_bzt or config.offset
    //     self.imgSoldier:setPosition(self.soldierOriPos.x + offset.x, self.soldierOriPos.y + offset.y)
    //   end
  }else{
    UpdateTrapView();
    _NodeTrap->setVisible(true);
    _NodeArmyBase->setPosition(_TrapBasePos);
    _ImgSoldier->setPosition(_TrapPos);
    SoldierEnterAct(_ImgSoldier, 0.9f, true);
  }
  UpdateLabelHave();
  if(_TableCurSoldier._ArmyData._IsCanTrain){
    if(ArmyLtCtrl::Get()->IsWarframeArmyID(_TableCurSoldier._ArmyData._ArmyId)){
      ResetWarframeSlider();
    }else{
      if(_TableCurSoldier._Bid == EBuilding::ElitePalace){
        _BtnTrainNow->setVisible(false);
        _NodeElite->setVisible(true);
      }else{
        _BtnTrainNow->setVisible(true);
      }
      UpdateToolTrainInfo();
      InitSlider(p_Event);
      _NodeTrainBtn->setVisible(true);
      _BtnWear->setVisible(false);
    }
    //   self.imgSoldier:getVirtualRenderer():setState(0)
  }else{
    auto l_NeedLv = std::to_string(ArmyLtCtrl::Get()->GetArmyInfo(_TableCurSoldier._ArmyData._ArmyId).barrackLevel);
    auto l_WarLvl = BuildingLogic::Get()->TransFormBuildLvToWarLv(GStringUtils::ToNumber(l_NeedLv));
    if(l_WarLvl >= GBase::Const::Get()->CastleMinWarLvl){
      l_NeedLv = Translate::i18n("common_text_1948", {{"lv", std::to_string(l_WarLvl)}});
    }
    auto l_NeedStarLv = std::to_string(ArmyLtCtrl::Get()->GetArmyInfo(_TableCurSoldier._ArmyData._ArmyId).starlv);
    if(ArmyLtCtrl::Get()->IsWarframeArmyID(_TableCurSoldier._ArmyData._ArmyId)){
      _LabelDes->setString(Translate::i18n("Soldiers_armor_text_17", {{"var", "8"}}));
    }else if(_TableCurSoldier._ArmyData._IsStarArmy){
      _LabelDes->setString(Translate::i18n("soldier_text_01", 
        {
          {"name", BuildingRead::Get()->GetName(_TableCurSoldier._Bid)}, 
          {"lv", l_NeedStarLv}
        }
      ));
    }else{
      _LabelDes->setString(Translate::i18n("common_text_327", 
        {
          {"name", BuildingRead::Get()->GetName(_TableCurSoldier._Bid)}, 
          {"lv", l_NeedLv}
        }
      ));
    }
    //   self.imgSoldier:getVirtualRenderer():setState(1)
  }
  InitSkill();
  SetBaseInfo();
  
  _NodeTrainInfo->setVisible(_TableCurSoldier._ArmyData._IsCanTrain);
  _NodeUnTrain->setVisible(!_TableCurSoldier._ArmyData._IsCanTrain);
  _ImgLine->setVisible(_TableCurSoldier._ArmyData._IsCanTrain);
  _BtnJump->setVisible(true);
  if(ArmyCtrl::Get()->IsCanWearWarframe(_TableCurSoldier._ArmyData._ArmyId))
    _BtnPromote->setTitleText(Translate::i18n("Soldiers_armor_text_26"));
  else 
    _BtnPromote->setTitleText(Translate::i18n("arms_promotion_btn_01"));
    
  if(ArmyLtCtrl::Get()->IsWarframeArmyID(l_ArmyId)/* and not commonCheck.WARFRAME_WEAR */){
    _NodeTrainInfo->setVisible(false);
    _NodeUnTrain->setVisible(true);
    _ImgLine->setVisible(false);
    _LabelDes->setString(Translate::i18n("common_text_413"));
    _BtnJump->setVisible(false);
  }
  UpdatePromoteIcon();
}

void UISoldiersCampView::SoldierEnterAct(Node *p_Target, float p_ToScale,bool p_IsTrap){
  if(_IsOpen){
    _IsOpen = false;
    p_Target->setScale(p_ToScale + 0.2f);
    if(p_IsTrap){
      auto l_Seq = Sequence::create(
        MoveBy::create(5.0f, Vec2(0.0f, 20.0f)),
        MoveBy::create(5.0f, Vec2(0.0f, -20.0f)),
        nullptr
      );
      p_Target->runAction(RepeatForever::create(l_Seq));
    }
    p_Target->runAction(ScaleTo::create(0.3f, p_ToScale, p_ToScale));
    _NodeArmyBase->stopAllActions();
    _NodeArmyBase->setScale(1.1f);
    _NodeArmyBase->runAction(ScaleTo::create(0.3f, 1.0f));
  }
}

void UISoldiersCampView::UpdatePromoteIcon(){
  
  _TableSoldierList = ArmyLogic::Get()->GetCanTrainList(_TableCurSoldier._Bid).First;
  for(auto iii = 0; iii < (int32)_SoldierArray.size(); iii++){
    auto v = dynamic_cast<UISoldiersTrainScrollSingle*>(_SoldierArray[iii]);
    v->InitData(_TableSoldierList[iii], _TableCurSoldier._Type);
  }
  _BtnPromote->setPositionY(_NodeTrap->getPositionY() + 38);
  if(!_NodeTrap->isVisible() && !_NodeElite->isVisible()){
    _BtnPromote->setPositionY(_NodeTrap->getPositionY());
  }
  auto l_IsCanPromote = ArmyCtrl::Get()->IsCanPromote(_TableCurSoldier._ArmyData._ArmyId);
  auto l_PromoteQueue = TaskCtrl::Get()->QueryQueue(ETask::PromptArmy);
  _BtnPromote->setVisible(l_IsCanPromote || ArmyCtrl::Get()->IsCanWearWarframe(_TableCurSoldier._ArmyData._ArmyId));
  auto l_Ret = true;
  if(l_PromoteQueue || _IsWarForbid){
    l_Ret = false;
  }
  _BtnPromote->setEnabled(l_Ret);
}

void UISoldiersCampView::InitSkill(){
  _TableSkill._Data = ArmyRead::Get()->GetSkill(_TableCurSoldier._ArmyData._ArmyId);
  auto l_SkillCount = _TableSkill._Data.size();
  for(auto i = 0; i < _TableSkill._Node.size(); i++){
    _TableSkill._Node[i]->setVisible(false);
  }
  for(auto i = 0; i < l_SkillCount; i++){
    _TableSkill._Node[i]->InitData(_TableSkill._Data[i]);
    _TableSkill._Node[i]->setVisible(true);
  }
}

int32 UISoldiersCampView::GetMaxCampCount(){
  
  if(_Timer || !_TableCurSoldier._ArmyData._IsCanTrain)
    return 0;
  
  auto l_ResTrain = 0;
  auto l_Ret = ArmyLogic::Get()->IsCanTrain(_TableCurSoldier._Bid, _TableCurSoldier._ArmyData._ArmyId);
  auto l_RetData = ArmyLogic::Get()->GetTrainResCost(_TableCurSoldier._Bid, _TableCurSoldier._ArmyData._ArmyId);
  for(auto l_OneRes : l_RetData._CostRes){
    if(l_OneRes._ResCount > 0){
      if(l_ResTrain == 0){
        l_ResTrain = std::max(1, (int32)std::floor(l_OneRes._CurCount / l_OneRes._ResCount));
      }else{
        l_ResTrain = std::min(l_ResTrain, (int32)std::floor(l_OneRes._CurCount / l_OneRes._ResCount));
      }
    }
  }
  
  auto l_CanTrain = 0;
  if(_TableCurSoldier._Type == ETrainType::Soldiers){
    if(_TableCurSoldier._Bid == EBuilding::ElitePalace){
      auto l_EliteTrain = 0;
      if(l_RetData._CostElitePointInfo._Valid){
        auto l_CostElitePointInfo = l_RetData._CostElitePointInfo;
        l_EliteTrain = std::floor(l_CostElitePointInfo._CurrentElitePoint / l_CostElitePointInfo._CostElitePoint);
      }
      l_CanTrain = std::min(ArmyLogic::Get()->GetMaxTrainCount(_TableCurSoldier._Bid)._Total, l_EliteTrain);
    }else{
      l_CanTrain = ArmyLogic::Get()->GetMaxTrainCount(_TableCurSoldier._Bid)._Total;
    }
  }else{
    l_CanTrain = std::min(l_ResTrain, ArmyLogic::Get()->GetMaxTrapBuildCount(_TableCurSoldier._ArmyData._ArmyId));
  }
  return l_CanTrain;
}

void UISoldiersCampView::InitSlider( EventCustom *p_Event ){
  
  auto l_CanTrain = 0;
  if(_TableCurSoldier._Type == ETrainType::Soldiers){
    l_CanTrain = ArmyLogic::Get()->GetMaxTrainCount(_TableCurSoldier._Bid)._Total;
    auto l_IsCanTrain = true;
    if(_TableCurSoldier._Bid == EBuilding::ElitePalace){
      l_IsCanTrain = l_CanTrain > 0;
    }
    auto l_Enable = l_IsCanTrain && !_IsWarForbid;
    _BtnTrain->setEnabled(l_Enable);
    _BtnTrainNow->setEnabled(l_Enable);
    _NodeTrainTime->setVisible(l_Enable);
    _LabelEliteNotice->setVisible(!l_IsCanTrain);
  }else{
    l_CanTrain = ArmyLogic::Get()->GetMaxTrapBuildCount(_TableCurSoldier._ArmyData._ArmyId);
    auto l_IsCanTrain = l_CanTrain > 0 && !_IsWarForbid;
    _BtnTrain->setBright(l_IsCanTrain);
    _BtnTrainNow->setBright(l_IsCanTrain);
  }
  
  auto l_CurCanValue = GetMaxCampCount();
  if(_TableCurSoldier._ArmyCount > 0){
    l_CurCanValue = std::max(l_CurCanValue, _TableCurSoldier._ArmyCount);
  }

  UICommonSlider::RInitDataParam l_Param ;
  l_Param._MaxValue = l_CanTrain;
  l_Param._MinValue = 1;
  l_Param._CurValue = p_Event ? _NodeSlider->GetSliderCurValue() : l_CurCanValue;
  _NodeSlider->InitData(l_Param);
}

void UISoldiersCampView::UpdateTip(){
  _LabelTip1->setString(ArmyRead::Get()->GetTip(_TableCurSoldier._ArmyData._ArmyId));
  _LabelTip2->setString(ArmyRead::Get()->GetTip(_TableCurSoldier._ArmyData._ArmyId));

  auto l_OffsetX = 50;
  auto l_LableW = _LabelTip1->getContentSize().width + std::max((float)l_OffsetX, 640 - 2 * _LabelTip1->getContentSize().width - l_OffsetX);
  auto l_Dt = l_LableW / 120;
  _LabelTip1->stopAllActions();
  _LabelTip2->stopAllActions();
  _LabelTip1->setPositionX(GBase::DFPosX(640 - l_OffsetX, _LabelTip1));
  _LabelTip2->setPositionX(GBase::DFPosX(640 - l_LableW - l_OffsetX, _LabelTip2));
  l_OffsetX = _LabelTip2->getPositionX() - _LabelTip1->getPositionX();
  _LabelTip1->runAction(
    RepeatForever::create(
      Sequence::create(
        MoveBy::create(l_Dt, Vec2(GBase::DFSign(l_LableW), 0)),
        CallFunc::create([=](){
          _LabelTip1->setPositionX(_LabelTip2->getPositionX() + l_OffsetX);
        }),
        MoveBy::create(l_Dt, Vec2(GBase::DFSign(l_LableW), 0)),
        nullptr
      )
    )
  );
  
  _LabelTip2->runAction(
    RepeatForever::create(
      Sequence::create(
        MoveBy::create(2 * l_Dt, Vec2(GBase::DFSign(2 * l_LableW), 0)),
        CallFunc::create([=](){
          _LabelTip2->setPositionX(_LabelTip1->getPositionX() + l_OffsetX);
        }),
        nullptr
      )
    )
  );
}

void UISoldiersCampView::WheelScrollBack(RCanTrainArmy p_Soldier){
  _TableCurSoldier._ArmyData = p_Soldier;
  if(_SoundHandler != -1){
    GAudioEngine::Get()->StopEffect(_SoundHandler);
    _SoundHandler = -1;
  }
  _SoundHandler = GBase::PlaySound("checkedSoldier", (int32)_TableCurSoldier._ArmyData._ArmyId % 1000);
  UpdateView(nullptr);
  if(_TipLayout->isVisible()){
    UpdateTip();
  }
}

void UISoldiersCampView::BtnInfoClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    ShowInfoNode();
  }
}

void UISoldiersCampView::ShowInfoNode(){
  auto l_Panel = UISoldiersDetailView::Create();
  l_Panel->InitData(_TableCurSoldier);
  l_Panel->Show();
}

void UISoldiersCampView::BtnSpeedUpClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type == Widget::TouchEventType::ENDED){
    GBase::PlaySound();
    GBase::DShowSpeedUpBox(
      _TrainQueue, CC_CALLBACK_1(UISoldiersCampView::SpeedUpCallBack, this),
      Translate::i18n("common_text_765"));
  }
}

void UISoldiersCampView::SpeedUpCallBack(EMsgBoxCallBack p_CallBack){
  if(p_CallBack == EMsgBoxCallBack::SpeedUp){
    IsTraining(false);
  }
}



void UISoldiersCampView::BtnSpeedUpToolClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  
  auto l_QueueType = _TrainQueue->GetQueueType();
  GBase::PlaySound();
  auto l_Panel = UICommonSpeedUpByItemBox::Create();
  l_Panel->InitData(l_QueueType, CC_CALLBACK_1(UISoldiersCampView::SpeedUpToolCallBack, this));
  l_Panel->Show();
}

void UISoldiersCampView::SpeedUpToolCallBack(EMsgBoxCallBack p_CallBack){
  if(p_CallBack == EMsgBoxCallBack::SpeedUp)
    GBase::DShowLoading(this);
}

void UISoldiersCampView::BtnEliteClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  RStyleFormat _Format;
  _Format._Float = GBase::DFLabelR();
  GBase::DShowHelpMsgTip(Translate::i18n("common_text_3233"), _Format);
}

void UISoldiersCampView::BtnTrainClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  auto l_Button = dynamic_cast<Button*>(p_Sender);
  CCAssert(l_Button, "UISoldiersCampView::BtnTrainClickCallBack");
  if(!l_Button->isBright()){
    if(_IsWarForbid){
      WorldMapDefine::Get()->ShowWarTips();
      return;
    }
    if(_TableCurSoldier._Type == ETrainType::Soldiers)
      GBase::DShowMsgTip(Translate::i18n("common_text_3232"));
    //     else
    //       gModuleMgr.sharedMgr("mildGuideManager"):drawFingerToTarget(self.btnTrap, {})
    //     end
  } else if(_TableCurSoldier._NeedElite){
    GBase::DShowMsgTip(Translate::i18n("common_text_3230"),
     GString(ResourceRead::Get()->GetIcon(EResource::ElitePoint)));
  }else if(_TableCurSoldier._NeedRes){
    if(GBase::DIsGameGuide())
      ResBuyCallBack();
    else
      ShowResBuyView();
  }else{
    CheckIsMaxSingleAdd(EOperateMode::Normal);
  }
}

void UISoldiersCampView::CheckIsMaxSingleAdd(EOperateMode p_OperateMode){
  auto l_ToolAddInfo = ArmyCtrl::Get()->GetSingleAddInfo();
  auto l_CountInfo = ArmyLogic::Get()->GetMaxTrainCount(_TableCurSoldier._Bid);
  auto  l_TotalCount = _TableCurSoldier._Type == ETrainType::Soldiers ? l_CountInfo._Total : ArmyLogic::Get()->GetMaxTrapBuildCount(_TableCurSoldier._ArmyData._ArmyId);
  auto l_Count = _NodeSlider->GetSliderCurValue();
  if(
    l_TotalCount > l_Count && l_Count > l_CountInfo._Base  &&
    l_ToolAddInfo._ItemCount > 0 && l_ToolAddInfo._AddCount > 0){
    GBase::DShowMsgBox(
      Translate::i18n("parliament_text_138"),
      Translate::i18n("common_text_204"),
      Translate::i18n("common_text_185"),
      [this, p_OperateMode](EMsgBoxCallBack p_CallBack){
        if(p_CallBack == EMsgBoxCallBack::Yes)
          TrainArmySent(p_OperateMode);
      }
    );
  }else{
    TrainArmySent(p_OperateMode);
  }
}

void UISoldiersCampView::ResBuyCallBack(){
  CheckIsMaxSingleAdd(EOperateMode::GoldReplace);
}

void UISoldiersCampView::TrainImmediately(){
  if(GBase::DEnoughGold(_TrainGold))
    CheckIsMaxSingleAdd(EOperateMode::Immediately);
}

void UISoldiersCampView::BtnTrainNowClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  auto l_Btn = dynamic_cast<Button*>(p_Sender);
  GBase::PlaySound();
  if(_TableCurSoldier._Type == ETrainType::Soldiers){
    if(!l_Btn->isBright()){
      if(_IsWarForbid)
        WorldMapDefine::Get()->ShowWarTips();
    }else{
      //           local dailyRemindManager = include("dailyRemindManager")
      //           local ctype = dailyRemindManager.REMIND_TYPE.soldiersCampView_soldier
      //           if dailyRemindManager.checkNeedRemind(ctype) then
      //             SoraDShowBuyBox(i18n("common_text_3166"), self.trainGold, self.btnTrainNow:getTitleStr(), function(callback)
      //               if callback == MSGBOX_CALLBACK_YES then
      //                 dailyRemindManager.addRemindToManager(ctype)
      //                 trainImmediately()
      //               end
      //             end)
      //           else
      //             trainImmediately()
        TrainImmediately();
      //           end
    }
  }else if(!l_Btn->isBright()){
    if(_IsWarForbid)
      WorldMapDefine::Get()->ShowWarTips();
    else {
      //         gModuleMgr.sharedMgr("mildGuideManager"):drawFingerToTarget(self.btnTrap, {})
    }
  }else{
  //         local dailyRemindManager = include("dailyRemindManager")
  //         local ctype = dailyRemindManager.REMIND_TYPE.soldiersCampView_trap
  //         if dailyRemindManager.checkNeedRemind(ctype) then
  //           SoraDShowBuyBox(i18n("common_text_4308"), self.trainGold, self.btnTrainNow:getTitleStr(), function(callback)
  //             if callback == MSGBOX_CALLBACK_YES then
  //               dailyRemindManager.addRemindToManager(ctype)
  //               trainImmediately()
  //             end
  //           end)
  //         else
  //           trainImmediately()
    TrainImmediately();
  //         end
  }
}

void UISoldiersCampView::TrainArmySent(EOperateMode p_OperateMode){
  auto l_Bid = _TableCurSoldier._Bid;
  auto l_Aid = _TableCurSoldier._ArmyData._ArmyId;
  auto l_Count = _TableCurSoldier._ArmyCount;
  auto l_TotalCount = ArmyCtrl::Get()->GetArmyCount(l_Aid, EArmyOpType::All);
  if(l_TotalCount >= GBase::ConstValue::Get()->MaxArmy){
    GBase::DShowMsgTip(Translate::i18n("complement_tips_06"));
    return;
  }
  auto l_Building = dynamic_cast<IBuildingArmy*>(_BuildEntity);
  if(l_Building && !_BuildEntity->CheckCanTrainOrUpgrade())
    return;
  if(l_Building)
    l_Building->SetIsWaitTraining(true);
  RTrainSoldiersLog l_TrainLog ;
  if(_TrainSoldiersLog.Contains(l_Bid))
    _TrainSoldiersLog[l_Bid]._TrainArmyId = l_Aid;
  // SoraDConfigSet("Game:SoldiersCampView:trainSoldiersLog~table", self.trainSoldiersLog, {byUID = true})
  ArmyCtrl::Get()->TrainArmyReq(l_Building->GetBuildingIndex(), l_Aid, l_Count, p_OperateMode);
  if(GBase::DIsGameGuide())
    this->RemoveSelf();
  else if(p_OperateMode == EOperateMode::Immediately)
    GBase::DShowLoading(_BtnTrainNow)->setPosition(Vec2::ZERO);
}

void UISoldiersCampView::Close(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  RemoveSelf();
}

void UISoldiersCampView::BtnTrapMsgClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  GBase::DShowHelpMsgTip(Translate::i18n("common_text_328"));
}

void UISoldiersCampView::BtnDissolveClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  if(_IsWarForbid){
    WorldMapDefine::Get()->ShowWarTips();
    return;
  }

  if(_TableCurSoldier._Type == ETrainType::Soldiers){
    auto l_Bid = ArmyRead::Get()->GetBuildID(_TableCurSoldier._ArmyData._ArmyId);
    auto l_SoldierListPair = ArmyLogic::Get()->GetCanTrainList(l_Bid);
    auto l_SoldierList = l_SoldierListPair.First;
    auto l_CurIndex = l_SoldierListPair.Second;
    auto l_CurLvl = ArmyLogic::Get()->GetArmyLV(_TableCurSoldier._ArmyData._ArmyId);
    auto l_MaxLvl = ArmyLogic::Get()->GetArmyLV(l_SoldierList[l_CurIndex]._ArmyId);
    if(l_MaxLvl <= l_CurLvl + 1){
      GBase::DShowMsgBox(Translate::i18n("common_text_2564"), Translate::i18n("common_text_204"));
      return;
    }
  }
  auto l_Panel = UIDissolveSoldiersView::Create();
  l_Panel->InitData(_TableCurSoldier._ArmyData._ArmyId, _TableCurSoldier._Type);
  l_Panel->Show();
}

void UISoldiersCampView::BtnToolClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  auto l_Panel = UITrainArmyLimitView::Create();
  l_Panel->InitData(EItemType::SINGLE_TRAIN_ADD_COUNT);
  l_Panel->Show();
}

void UISoldiersCampView::BtnTipClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  GBase::DShowHelpMsgTip(Translate::i18n("common_text_4353"));
}

void UISoldiersCampView::BtnJumpClickCallBack(Ref *p_Sender, Widget::TouchEventType p_Type){
  GBase::PlaySound();
  if(ArmyLtCtrl::Get()->IsWarframeArmyID( _TableCurSoldier._ArmyData._ArmyId)){
    //     gModuleMgr.sharedMgr("mildGuideManager"):starMildByNewPlayerQuestID(gNewPLayerTaskType.TO_BUILD_STATUE_BRAVE, {
    //       key = "OpWarframeForg"
    //     })
  }else{
    auto l_NeedLv = ArmyLtCtrl::Get()->GetArmyInfo(_TableCurSoldier._ArmyData._ArmyId).barrackLevel;
    if(_TableCurSoldier._ArmyData._IsStarArmy)
      l_NeedLv = ArmyLtCtrl::Get()->GetArmyInfo(_TableCurSoldier._ArmyData._ArmyId).starlv;
    //     gModuleMgr.sharedMgr("mildGuideManager"):starToUpgrade({
    //       bid = self.tableCurSoldier.bid,
    //       lv = needlv
    //     })
  }
  GPanelManger::Get()->DRemoveAllPanelFromManager();
}

void UISoldiersCampView::BtnPromoteClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  if(_IsWarForbid){
    WorldMapDefine::Get()->ShowWarTips();
  }else{
    auto l_PromoteQ = TaskCtrl::Get()->QueryQueue(ETask::PromptArmy);
    if(!l_PromoteQ){
      if(ArmyCtrl::Get()->IsCanWearWarframe(_TableCurSoldier._ArmyData._ArmyId)){
      auto l_ArmyType = ArmyLtCtrl::Get()->GetArmyInfo(_TableCurSoldier._ArmyData._ArmyId).armyType;
      auto l_Ret = ArmyCtrl::Get()->GetWarframeInfo(_TableCurSoldier._Bid);
      auto l_Lv = l_Ret[l_ArmyType].First;
      auto l_ArmyId = l_Ret[l_ArmyType].Second;
      _SelectWheel->selectedCellIndex((int32)l_ArmyId % 100);
      }else{
      //         local mildGuideManager = gModuleMgr.sharedMgr("mildGuideManager")
      //         mildGuideManager:starMildByNewPlayerQuestID(gNewPLayerTaskType.TROOP_FLAG, {})
      //         SoraDRemoveAllPanelFromManager()
      }
    }else{
      GBase::DShowMsgTip(Translate::i18n("arms_promotion_text_02"));
    }
  }
}

void UISoldiersCampView::BtnWearClickCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type){
  if(p_Type != Widget::TouchEventType::ENDED)
    return;
  GBase::PlaySound();
  if(WorldMapDefine::Get()->IsInWarForbidSoldier())
    return;
  auto l_ChooseNum = _TableCurSoldier._ArmyCount;
  //   local armyid = armorSystemCtrl:getArmyIdByArmorId(self.armorId)
  EArmy l_ArmyId;
  if(l_ChooseNum > ArmyCtrl::Get()->GetArmyCount(l_ArmyId, EArmyOpType::All)){
    auto l_BuildId = EBuilding::Barrack; //local buildID = armyltCtrl.getArmyAttrAndSp(armyid, ARMY_ATTR.BARRACK_ID) ;
    GBase::DShowMsgBox(
      Translate::i18n("Soldiers_armor_text_35",  {{"name", ArmyRead::Get()->GetName(l_ArmyId)}}),
      Translate::i18n("common_text_204"), "", [this](EMsgBoxCallBack p_CallType){
        if(p_CallType == EMsgBoxCallBack::Yes){
          _SelectWheel->selectedCellIndex(12);
        }
      });
  } 
  //   elseif armorSystemCtrl:getArmorNumByID(self.armorId) == 0 or chooseNum > armorSystemCtrl:getArmorNumByID(self.armorId) then
  //     local msgBoxPanel = SoraDShowMsgBox(i18n("Soldiers_armor_text_36", {
  //       name = i18n(armorSystemRead:getProperty(self.armorId, "name"))
  //     }), i18n("common_text_204"), nil, function(callType)
  //       if callType == MSGBOX_CALLBACK_YES then
  //         local mildGuideManager = gModuleMgr.sharedMgr("mildGuideManager")
  //         mildGuideManager:starMildByNewPlayerQuestID(gNewPLayerTaskType.TO_BUILD_STATUE_BRAVE, {
  //           key = "OpWarframeForg"
  //         })
  //         SoraDRemoveAllPrePanelFromManager(self)
  //       end
  //     end)
  //   else
  else{
  //     armorSystemCtrl:reqArmorSystemWearArmor({
  //       num = chooseNum,
  //       armorId = self.armorId,
  //       level = 12
  //     })
  }
}

void UISoldiersCampView::RemoveSelf(){
  if(!_IsRun)
    return;
  _IsRun = false;
  GBase::DManagerRemoveTimer(_Timer);
  _Timer = nullptr;
  removeFromParent();
}


void UISoldiersCampView::OnExitPanel(){
  if(_NeedHiddleMainScene){
    //   local hideData = {isHideCurrentSceneView = true, isHideMainUI = true}
    //   SoraDHideCurrentSceneViewAndMainUI(hideData)
  }
  
  // for k, v in pairs(self.tableLoadingBar) do
  //   if v.loadingBarTimer then
  //     SoraDManagerRemoveTimer(v, v.loadingBarTimer)
  //     v.loadingBarTimer = nil
  //   end
  // end
}

void UISoldiersCampView::AddTrapEffectByArmyType(EArmy p_ArmyId){
  auto l_ArmyType = ArmyLogic::Get()->GetArmyTypeByID(p_ArmyId);
  auto l_TrapLevel = (int32)p_ArmyId % 10;
  if(_ImgSoldier->getChildByName("parNode_trap"))
    _ImgSoldier->removeChildByName("parNode_trap");
  GHashMap<ESoldierType, GHashMap<int32, RCreatEffctParam>> l_Config;
  l_Config[ESoldierType::TRAP_WOOD] = GHashMap<int32, RCreatEffctParam>();
  l_Config[ESoldierType::TRAP_WOOD][1] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_WOOD][1]._PList = "et_gunmu_display_01.plist";
  l_Config[ESoldierType::TRAP_WOOD][1]._Scale = {1, 1};
  l_Config[ESoldierType::TRAP_WOOD][1]._Pos = {0, -65};

  l_Config[ESoldierType::TRAP_WOOD][2] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_WOOD][2]._PList = "et_gunmu_display_01.plist";
  l_Config[ESoldierType::TRAP_WOOD][2]._Scale = {1.5f, 1.5f};
  l_Config[ESoldierType::TRAP_WOOD][2]._Pos = {0, -60};

  l_Config[ESoldierType::TRAP_WOOD][3] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_WOOD][3]._PList = "et_gunmu_display_01.plist";
  l_Config[ESoldierType::TRAP_WOOD][3]._Scale = {2.f, 1.6f};
  l_Config[ESoldierType::TRAP_WOOD][3]._Pos = {0, -65};

  l_Config[ESoldierType::TRAP_WOOD][4] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_WOOD][4]._PList = "et_gunmu_display_01.plist";
  l_Config[ESoldierType::TRAP_WOOD][4]._Scale = {2.f, 2.f};
  l_Config[ESoldierType::TRAP_WOOD][4]._Pos = {-20, -45};

  l_Config[ESoldierType::TRAP_WOOD][5] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_WOOD][5]._PList = "et_gunmu_display_01.plist";
  l_Config[ESoldierType::TRAP_WOOD][5]._Scale = {2.3f, 2.3f};
  l_Config[ESoldierType::TRAP_WOOD][5]._Pos = {0, -40};


  l_Config[ESoldierType::TRAP_ARROW][1] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_ARROW][1]._PList = "et_huojian_display_01.plist";
  l_Config[ESoldierType::TRAP_ARROW][1]._Scale = {1.f, 1.f};
  l_Config[ESoldierType::TRAP_ARROW][1]._Pos = {58, -30};

  l_Config[ESoldierType::TRAP_ARROW][2] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_ARROW][2]._PList = "et_huojian_display_01.plist";
  l_Config[ESoldierType::TRAP_ARROW][2]._Scale = {1.2f, 1.2f};
  l_Config[ESoldierType::TRAP_ARROW][2]._Pos = {50, -30};

  l_Config[ESoldierType::TRAP_ARROW][3] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_ARROW][3]._PList = "et_huojian_display_01.plist";
  l_Config[ESoldierType::TRAP_ARROW][3]._Scale = {1.5f, 1.5f};
  l_Config[ESoldierType::TRAP_ARROW][3]._Pos = {50, -32};

  l_Config[ESoldierType::TRAP_ARROW][4] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_ARROW][4]._PList = "et_huojian_display_01.plist";
  l_Config[ESoldierType::TRAP_ARROW][4]._Scale = {1.8f, 1.8f};
  l_Config[ESoldierType::TRAP_ARROW][4]._Pos = {50, -40};

  l_Config[ESoldierType::TRAP_ARROW][5] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_ARROW][5]._PList = "et_huojian_display_01.plist";
  l_Config[ESoldierType::TRAP_ARROW][5]._Scale = {2.f, 2.f};
  l_Config[ESoldierType::TRAP_ARROW][5]._Pos = {50, -40};


  l_Config[ESoldierType::TRAP_STONE][1] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_STONE][1]._PList = "et_luoshi_display_01.plist";
  l_Config[ESoldierType::TRAP_STONE][1]._Scale = {1.8f, 1.f};
  l_Config[ESoldierType::TRAP_STONE][1]._Pos = {-10, -85};

  l_Config[ESoldierType::TRAP_STONE][2] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_STONE][2]._PList = "et_luoshi_display_01.plist";
  l_Config[ESoldierType::TRAP_STONE][2]._Scale = {2.f, 1.5f};
  l_Config[ESoldierType::TRAP_STONE][2]._Pos = {0, -75};

  l_Config[ESoldierType::TRAP_STONE][3] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_STONE][3]._PList = "et_luoshi_display_01.plist";
  l_Config[ESoldierType::TRAP_STONE][3]._Scale = {2.f, 2.f};
  l_Config[ESoldierType::TRAP_STONE][3]._Pos = {0, -60};

  l_Config[ESoldierType::TRAP_STONE][4] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_STONE][4]._PList = "et_luoshi_display_01.plist";
  l_Config[ESoldierType::TRAP_STONE][4]._Scale = {2.5f, 2.f};
  l_Config[ESoldierType::TRAP_STONE][4]._Pos = {-10, -55};

  l_Config[ESoldierType::TRAP_STONE][5] = RCreatEffctParam();
  l_Config[ESoldierType::TRAP_STONE][5]._PList = "et_luoshi_display_01.plist";
  l_Config[ESoldierType::TRAP_STONE][5]._Scale = {3.f, 2.f};
  l_Config[ESoldierType::TRAP_STONE][5]._Pos = {0, -60};

  if(l_Config.Contains(l_ArmyType)){
    auto l_Vec = GVector<RCreatEffctParam>();
    if(l_Config[l_ArmyType].Contains(l_TrapLevel))
      l_Vec.push_back(l_Config[l_ArmyType][l_TrapLevel]);
    auto l_PerNode =GBase::DCreateEffectNode(l_Vec);
    l_PerNode->setPosition({this->getContentSize().width / 2, this->getContentSize().height / 2});
    l_PerNode->setName("parNode_trap");
    _ImgSoldier->addChild(l_PerNode, 2);
    
  }
}

void UISoldiersCampView::UpdateLabelHave(){
  auto l_ArmyCount = ArmyCtrl::Get()->GetArmyCount(_TableCurSoldier._ArmyData._ArmyId, EArmyOpType::All);
  _LabelHave->setString(
    Translate::i18n("common_text_531", {
      {"num", GStringUtils::FormatK(l_ArmyCount)}
    })
  );
  GBase::DToCenter(_NodeHave);
}

void UISoldiersCampView::InitWidget(){

}
