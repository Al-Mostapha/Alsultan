#include "UIBuildingTipPanel.h"
#include "UIBuildingTipButton.h"
#include "Module/Building/IBuilding.h"
#include "Module/Faction/Faction.Ctrl.h"
#include "Module/Building/Building.Lib.h"


float UIBuildingTipPanel::ACTION_TIME = 0.13f;
float UIBuildingTipPanel::TIME_DELAY_INIT = 0.001f;
int32 UIBuildingTipPanel::tag_act_init_view = 30000;
int32 UIBuildingTipPanel::tag_act_single_btn = 1000;
int32 UIBuildingTipPanel::tag_act_tip_show_end = 999;

UIBuildingTipPanel* UIBuildingTipPanel::Create()
{
  // auto l_TipPanel = Create("UiParts/Parts/Building/buildTip.csb");
  auto l_TipPanel = create();
  l_TipPanel->Ctor();
  return l_TipPanel;
}

void UIBuildingTipPanel::Ctor(){
  CreateUI();
}

void UIBuildingTipPanel::CreateUI(){
  _CircleFrameBg = GDisplay::Get()->NewSprite("frame_main_build_03.png");
  addChild(_CircleFrameBg);
  _CircleFrameBg->setPosition(0, -194);
  // local imgNameBg = ccui.ImageView:create()
  _BuildingNameFrame = ui::ImageView::create();
  // imgNameBg:loadTexture("title_main_build.png", ccui.TextureResType.plistType)
  _BuildingNameFrame->loadTexture("title_main_build.png", ui::Widget::TextureResType::PLIST);
  _BuildingNameFrame->setScale9Enabled(true);
  _BuildingNameFrame->setCapInsets(cocos2d::Rect(50, 26, 92, 4));
  _BuildingNameFrame->setContentSize(Size(192, 56));
  addChild(_BuildingNameFrame);
  // imgNameBg:setPosition(cc.p(0, 165))
  _BuildingNameFrame->setPosition(Vec2(0, 165));
  _LabelBuildName = ui::Text::create();
  _LabelBuildName->setFontSize(22);
  _LabelBuildName->setColor(Color3B(208, 181, 126));
  _LabelBuildName->setTextHorizontalAlignment(TextHAlignment::CENTER);
  _BuildingNameFrame->addChild(_LabelBuildName);
  _LabelBuildName->setAnchorPoint(Vec2(0.5, 0.5));
  _LabelBuildName->setPosition(Vec2(100, 28));
  // local starSingle = SoraDCreatePanel("masteryStarSingle")
  // starSingle:addTo(self.circleFrameBg)
  // starSingle:setPosition(cc.p(self.circleFrameBg:getContentSize().width / 2, 130))
  // starSingle:setVisible(false)
  // self.starSingle = starSingle
  // premiumStoreCtrl:sendOpenPage()
  // SoraDShowLoading(self)
}

void UIBuildingTipPanel::SetRelyBuildBtnId(int32 p_Tag){
  _RelyBuildBtnId = p_Tag;
}

void UIBuildingTipPanel::SetRelyBuildUId(int32 p_Tag){
  _RelyBuildUId = p_Tag;
}

void UIBuildingTipPanel::SetRelyBuildCfgId(EBuilding p_Building){
  _RelyBuildCfgId = p_Building;
}

void UIBuildingTipPanel::SetRelyBuildIid(EBuildingIndex p_Index){
  _RelyBuildIid = p_Index;
}

void UIBuildingTipPanel::SetRelyBuildEntity(IBuilding *p_Building){
  _RelyBuildEntity = p_Building;
}

void UIBuildingTipPanel::InitView(){
  // if self.circleFrameBg then
  //   self.circleFrameBg:setPosition(0, -self.circleRadius + 50 + self.circleOffsetY)
  // enif
  if(_CircleFrameBg)
    _CircleFrameBg->setPosition(0, -_CircleRadius + 50 + _CircleOffsetY);
  if(_BuildingNameFrame)
    _BuildingNameFrame->setScaleX(0.1f);
  RecycleAllBtns();
  stopAllActionsByTag(tag_act_tip_show_end);
  stopAllActionsByTag(tag_act_init_view);
  auto l_Seq = Sequence::create(
    DelayTime::create(TIME_DELAY_INIT),
    CallFunc::create([this](){
      DelayInitView();
    }),
    nullptr
  );
  l_Seq->setTag(tag_act_init_view);
  runAction(l_Seq);
}

void UIBuildingTipPanel::RecycleAllBtns(){}

void UIBuildingTipPanel::DelayInitView(){
  if(this->_RelyBuildCfgId == EBuilding::None)
    return;
  auto l_RelyBuildData = FactionCtrl::Get()->getCityBuildTipsInfo(_RelyBuildCfgId);
  _LabelBuildName->setString(Translate::i18n(l_RelyBuildData.BuildingName.c_str()));
  if(_LabelBuildName->getContentSize().width > 160){
    _BuildingNameFrame->setContentSize(Size(_LabelBuildName->getContentSize().width + 30, 56));
    _LabelBuildName->setPositionX(_BuildingNameFrame->getContentSize().width / 2);
  }
  // if nil == buildEntity then
  //   if relyBuildData.CityBuildingState == EnumCityBuildingStates.eCBS_Normal then
  //     local OpList = self:fillBtnOpList({}, relyBuildData.NormalOperateList)
  //     local buttonList = self:GetButtonArrayByOpList(OpList)
  //     self:RearrangeBtnByCircle(buttonList)
  //   end
  //   return
  // end
  auto l_IdBuilding = _RelyBuildEntity->GetBuildingId();
  auto l_BuildingIndex = _RelyBuildEntity->GetBuildingIndex();
  auto l_BuildType = BuildingLib::Get()->DGetBuildTypeByBid(l_IdBuilding);
  auto l_BuildingState = _RelyBuildEntity->GetState();
  if(l_BuildingState == EBuildingState::Building){
    if(!_RelyBuildEntity->GetBuildingQueue())
      l_BuildingState = EBuildingState::Normal;
  }else if(l_BuildingState == EBuildingState::Upgrading){
    if(!_RelyBuildEntity->GetBuildingQueue())
      l_BuildingState = EBuildingState::Normal;
  }else if(l_BuildingState == EBuildingState::Demolishing){
    if(!_RelyBuildEntity->GetBuildingQueue())
      l_BuildingState = EBuildingState::Normal;
  }
  if(l_IdBuilding == EBuilding::StarBraveStatue)
    _BuildingNameFrame->setPositionY(230);

  //   if buildState == BUILD_STATE.NORMAL then
  //   self.circleOffsetY = self.circleOffsetNormal
  //   if true == buildEntity:getIsTraining() then
  //     self.circleOffsetY = self.circleOffsetCooling
  //     operateType = "TrainingOperateList"
  //   else
  //     operateType = "NormalOperateList"
  //     if buildEntity and buildEntity:getBuildLv() >= CASTLE_MAXLV_NOWAR then
  //       OpList[BOP_NAME.BOP_UPGRADE] = false
  //       if cityltCtrl.isOpenWL(buildBid) and not buildLogic.buildLvIsFull(buildBid, iid) then
  //         OpList[BOP_NAME.BOP_WAR] = true
  //       end
  //       if not buildLogic.isBuildingUnlock(buildBid, iid) or buildLogic.buildLvIsFull(buildBid, iid) then
  //         OpList[BOP_NAME.BOP_WAR] = false
  //       end
  //     end
  //     if buildEntity and buildLogic.buildLvIsFull(buildBid, iid) then
  //       OpList[BOP_NAME.BOP_UPGRADE] = false
  //     end
  //   end
  //   local cityCtrl = gametop.playertop_:getModule("cityCtrl")
  //   local castleBcell = cityCtrl:getBuildCell(BUILDID.CASTLE, 0)
  //   if tonumber(buildBid) == 30001 then
  //     if tonumber(castleBcell.info.lv) >= CASTLE_MAXLV_NOWAR then
  //       OpList[BOP_NAME.BOP_BADGEBOURSE] = true
  //     end
  //     OpList[BOP_NAME.BOP_FRIEND] = true
  //     if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.EXOTIC_PAVILION_ACTIVITY) then
  //       OpList[BOP_NAME.BOP_FOREIGN_PAVILION] = true
  //     end
  //   end
  //   if tonumber(buildBid) == BUILDID.CASTLE then
  //     local privilegeGiftCtrl = gametop.playertop_:getModule("privilegeGiftCtrl")
  //     local ret = privilegeGiftCtrl:getCurCanBuyRechargeID()
  //     local starRet = privilegeGiftCtrl:getCurStarLvCanBuyRechargeID()
  //     if ret and next(ret) then
  //       OpList[BOP_NAME.BOP_CITY_GIFT] = true
  //     end
  //     if starRet and next(starRet) then
  //       OpList[BOP_NAME.BOP_CITY_GIFT] = true
  //     end
  //   end
  //   if tonumber(buildBid) == BUILDID.HERO_PRISON and IsArClient then
  //     OpList[BOP_NAME.BOP_MONUMENT] = true
  //   end
  //   local allianceMgr = gametop.playertop_:getModule("allianceMgr")
  //   local isJoinAllliance = allianceMgr:hasJoinAlliance()
  //   local depotBcell = cityCtrl:getBuildCell(BUILDID.DEPOT, 0)
  //   local conquestWarCtrl = gametop.playertop_:getModule("conquestWarCtrl")
  //   if tonumber(buildBid) == BUILDID.DEPOT and tonumber(depotBcell.info.lv) >= DEPOT_LV_ALLIANCE_TRRASURE and isJoinAllliance then
  //     OpList[BOP_NAME.BOP_ALLIANCE_TREASURE] = true
  //   end
  //   if tonumber(buildBid) == cityBuildConstDef.fixedBuildDef.ResurrectionHall then
  //     local lordInfoCtrl = gametop.playertop_:getModule("lordInfoCtrl")
  //     if lordInfoCtrl:getBaseInfo().isSrcKingdomWarEnabled then
  //       OpList[BOP_NAME.BOP_RESUSCITATE] = true
  //     end
  //   end
  //   if tonumber(buildBid) == cityBuildConstDef.fixedBuildDef.HuoChuang then
  //     OpList[BOP_NAME.BOP_PREMIUM_VIP_MALL] = true
  //   end
  //   if tonumber(buildBid) == BUILDID.HALL_OF_WAR and SoraDIsMilitaryFOpen() then
  //     OpList[BOP_NAME.BOP_MILITARY_FORTRESS] = true
  //   end
  //   if buildType == 1 then
  //     if buildBid == BUILDID.FARM or buildBid == BUILDID.SAWMILL or buildBid == BUILDID.IRON_MINE or buildBid == BUILDID.STEEL or buildBid == BUILDID.CRYSTAL_MINE then
  //       local boostToolNum = buildEntity:getBoostToolNum(buildBid)
  //       if boostToolNum > 0 and false == buildEntity:getHasBuff() then
  //         OpList.OpBoostByTool = true
  //       end
  //     elseif buildBid == BUILDID.HOSTPITAL and true == buildEntity:getIsTraining() and true == self:getHasAnySpeedUpTool() then
  //       OpList.OpSpeedUpByTool = true
  //     end
  //   elseif buildType == 0 and true == buildEntity:getIsTraining() and true == self:getHasAnySpeedUpTool() then
  //     OpList.OpSpeedUpByTool = true
  //   end
  // elseif buildState == BUILD_STATE.BUILDING then
  //   operateType = "CoolingOperateList"
  //   if true == self:getHasAnySpeedUpTool() then
  //     OpList.OpSpeedUpByTool = true
  //   end
  //   self.circleOffsetY = self.circleOffsetCooling
  //   local buttonList = self:GetButtonArrayByOpList(OpList)
  //   self:RearrangeBtnByCircle(buttonList)
  //   self.buttonList = buttonList
  // elseif buildState == BUILD_STATE.UPGRADEING then
  //   operateType = "CoolingOperateList"
  //   if true == self:getHasAnySpeedUpTool() then
  //     OpList.OpSpeedUpByTool = true
  //   end
  //   if tonumber(buildBid) == BUILDID.CASTLE then
  //     local privilegeGiftCtrl = gametop.playertop_:getModule("privilegeGiftCtrl")
  //     local ret = privilegeGiftCtrl:getCurCanBuyRechargeID()
  //     if ret and next(ret) then
  //       OpList[BOP_NAME.BOP_CITY_GIFT] = true
  //     end
  //   end
  //   if tonumber(buildBid) == BUILDID.DEPOT then
  //     local allianceMgr = gametop.playertop_:getModule("allianceMgr")
  //     local isJoinAllliance = allianceMgr:hasJoinAlliance()
  //     local depotBcell = cityCtrl:getBuildCell(BUILDID.DEPOT, 0)
  //     local conquestWarCtrl = gametop.playertop_:getModule("conquestWarCtrl")
  //     if tonumber(depotBcell.info.lv) >= DEPOT_LV_ALLIANCE_TRRASURE and isJoinAllliance then
  //       OpList[BOP_NAME.BOP_ALLIANCE_TREASURE] = true
  //     end
  //   end
  //   if tonumber(buildBid) == BUILDID.HALL_OF_WAR and SoraDIsMilitaryFOpen() then
  //     OpList[BOP_NAME.BOP_MILITARY_FORTRESS] = true
  //   end
  //   self.circleOffsetY = self.circleOffsetCooling
  // elseif buildState == BUILD_STATE.DEMOLISHING then
  //   operateType = "CoolingOperateList"
  //   if true == self:getHasAnySpeedUpTool() then
  //     OpList.OpSpeedUpByTool = true
  //   end
  //   self.circleOffsetY = self.circleOffsetCooling
  // else
  //   return
  // end
  // if tonumber(buildBid) == BUILDID.WALLS then
  //   local privilegeGiftCtrl = gametop.playertop_:getModule("privilegeGiftCtrl")
  //   local ret = privilegeGiftCtrl:getCurWallGiftRechargeID()
  //   if ret and next(ret) then
  //     OpList[BOP_NAME.BOP_CITY_LEVEL_GIFT] = true
  //   end
  // end
  // if not IsArClient and self:checkBuildMastery(buildBid, buildState) then
  //   OpList[BOP_NAME.BOP_MASTERY] = true
  // end
  // if tonumber(buildBid) == BUILDID.CARGO_SHIP and self:checkExclusiveVip() then
  //   OpList[BOP_NAME.BOP_EXCLUSIVE_VIP] = true
  // end
  // if tonumber(buildBid) == BUILDID.BLACK_SMITH then
  //   OpList[BOP_NAME.BOP_ARTIFACT] = commonCheck.ARTIFACT
  // end
  // if tonumber(buildBid) == BUILDID.MAGIC_LAMP then
  //   local breakQueue, classQueue, strengthQueue = buildEntity:getCoolingQueue()
  //   if breakQueue ~= nil then
  //     OpList[BOP_NAME.BOP_MAGICLAMP_BREAK] = true
  //   end
  //   if classQueue ~= nil then
  //     OpList[BOP_NAME.BOP_MAGICLAMP_CLASS] = true
  //   end
  //   if strengthQueue ~= nil then
  //     OpList[BOP_NAME.BOP_MAGICLAMP_STRENGTH] = true
  //   end
  // end
  // local guideCtrl = SoraDGetCtrl("guideCtrl")
  // if commonCheck.BUILD_STAR and (buildBid == BUILDID.CASTLE or not guideCtrl:isGuideNotCompleted(gGuideModule.CITY_STAR_LV)) then
  //   local isFullLv = buildLogic.buildStarLvIsFull(buildBid, iid)
  //   local isUnlock = buildLogic.isBuildingStarUnlock(buildBid, iid)
  //   local isOpenStar = cityltCtrl.isOpenStar(buildBid)
  //   local isEnoughLv = buildEntity:getBuildLv() >= CASTLE_LV90_LIMITED
  //   if tonumber(buildBid) == BUILDID.STAR_BRAVE_STATUE then
  //     isEnoughLv = true
  //   end
  //   print("==isOpenStar,isUnlock,isEnoughLv,isFullLv==", isOpenStar, isUnlock, isEnoughLv, isFullLv)
  //   if isOpenStar and isUnlock and isEnoughLv and not isFullLv then
  //     local buildStarState = tonumber(buildEntity:getBuildStarState())
  //     if buildStarState == BUILD_STAR_STATE.NORMAL then
  //       if tonumber(buildBid) == BUILDID.STAR_BRAVE_STATUE then
  //         OpList[BOP_NAME.BOP_STATUEBRAVE] = true
  //       else
  //         OpList[BOP_NAME.BOP_STARUPGRADE] = true
  //       end
  //     elseif buildStarState == BUILD_STAR_STATE.UPGRADEING then
  //       OpList[BOP_NAME.BOP_STARSPEEDUP] = true
  //     end
  //   end
  // end
  // if tonumber(buildBid) == BUILDID.STAR_BRAVE_STATUE then
  //   if not SoraDIsBrave8Level() then
  //     OpList[BOP_NAME.BOP_WARFRAMEFORG] = false
  //     OpList[BOP_NAME.BOP_WARFRAMESTOREROOM] = false
  //   end
  //   if operateType == "TrainingOperateList" then
  //     OpList[BOP_NAME.BOP_STATUEBRAVE] = false
  //     if buildRead.getQueueType(buildBid) == gQueueTypeDef.craft_study then
  //       OpList[BOP_NAME.BOP_WARFRAMEFORG] = false
  //     else
  //       OpList[BOP_NAME.BOP_PROCESSSTUDY] = false
  //     end
  //   elseif tonumber(buildEntity:getBuildStarState()) == BUILD_STAR_STATE.UPGRADEING then
  //     OpList[BOP_NAME.BOP_WARFRAMEFORG] = false
  //     OpList[BOP_NAME.BOP_PROCESSSTUDY] = false
  //   end
  // end
  auto l_OpList = FillBtnOpList(l_RelyBuildData.NormalOperateList);

  //   if buildState == BUILD_STATE.NORMAL then
  //   local bid = tonumber(buildBid)
  //   if worldMapDefine.isInWarForbidSoldier(true) then
  //     if bid == BUILDID.STABLES or bid == BUILDID.RANGE or bid == BUILDID.CHARIOT_PLANT or bid == BUILDID.BARRACKS or bid == BUILDID.FORTRESS or bid == BUILDID.ELITE_PALACE then
  //       OpList[BOP_NAME.BOP_SPEED_UP_BY_GOLD] = nil
  //       OpList[BOP_NAME.BOP_SPEED_UP_BY_TOOL] = nil
  //     elseif buildBid == BUILDID.MARKET then
  //       OpList[BOP_NAME.BOP_TRADE] = nil
  //     end
  //   elseif worldMapDefine.isInLegendLord() and buildBid == BUILDID.MARKET then
  //     OpList[BOP_NAME.BOP_TRADE] = nil
  //   end
  //   if worldMapDefine.isInRadiance() and buildBid == BUILDID.HOSTPITAL then
  //     OpList[BOP_NAME.BOP_SPEED_UP_BY_GOLD] = nil
  //   end
  //   if buildBid == BUILDID.EMBASSY and worldMapDefine.inInCrossWar() then
  //     OpList[BOP_NAME.BOP_INTETIOR] = nil
  //   end
  // end
  // OpList[BOP_NAME.BOP_METEOR_MAGIC] = nil
  
  // local buttonList = self:GetButtonArrayByOpList(OpList)
  auto l_ButtonList = GetButtonArrayByOpList(l_RelyBuildData.NormalOperateList);
  // self:RearrangeBtnByCircle(buttonList)
  RearrangeBtnByCircle(l_ButtonList);
  // self.buttonList = buttonList
}
GHashMap<EBuildingTips , RBuildingTipConfig> 
UIBuildingTipPanel::FillBtnOpList(GVector<EBuildingTips> p_TipsList){
  GHashMap<EBuildingTips , RBuildingTipConfig> l_OpList;
  for(auto l_OneTip : p_TipsList){
    l_OpList.emplace(
      l_OneTip, 
      FactionCtrl::Get()->GetBuildTipButtonCfgById(l_OneTip)
    );
  }
  return l_OpList;
  //   dump(source, "source", 10)
  // dump(baseCfg, "baseCfg", 10)
  // local nationCtrl = SoraDGetCtrl("factionCtrl")
  // local opList = {}
  // for _, v in ipairs(baseCfg) do
  //   if v ~= 0 then
  //     local info = nationCtrl:getBuildTipButtonCfgById(v)
  //     opList[info.OpName] = v
  //   end
  // end
  // local BTBED = require_data("build_tips_btn_enum_data")
  // for k, v in pairs(source) do
  //   if v then
  //     opList[k] = BTBED.data[k]
  //   else
  //     opList[k] = nil
  //   end
  // end
  // for k, v in pairs(opList) do
  //   local unlockLv = funUnlockRead.getLvByOpName(k)
  //   if unlockLv and unlockLv > SoraDGetCastleLv() then
  //     opList[k] = nil
  //   end
  // end
  // return opList
}

GVector<UIBuildingTipButton *>
UIBuildingTipPanel::GetButtonArrayByOpList(GVector<EBuildingTips> p_TipsList){
  GVector<UIBuildingTipButton *> l_ArrButtonList;
  // local arrOpList = {}
  // for k, v in pairs(opList) do
  //   table.insert(arrOpList, {OpName = k, btnId = v})
  // end
  // table.sort(arrOpList, function(lhs, rhs)
  //   local nationCtrl = SoraDGetCtrl("factionCtrl")
  //   local lhsData = nationCtrl:getBuildTipButtonCfgById(lhs.btnId)
  //   local rhsData = nationCtrl:getBuildTipButtonCfgById(rhs.btnId)
  //   if SoraDFIsRA() then
  //     return lhsData.OpSortIndex > rhsData.OpSortIndex
  //   else
  //     return lhsData.OpSortIndex < rhsData.OpSortIndex
  //   end
  // end)
  for(auto l_OneTip : p_TipsList){
    l_ArrButtonList.emplace_back(CreateButtonByOpType(l_OneTip));
  }
  //   for k, v in pairs(arrOpList) do
  //   local config = op_config[v.OpName] or op_config.undefined
  //   arrButtonList[#arrButtonList + 1] = self:createButtonByOpType({
  //     opType = v,
  //     buildEntity = self:getBuildEntity(),
  //     handler = config.handler
  //   })
  // end
  // return arrButtonList
  return l_ArrButtonList;
}

UIBuildingTipButton *UIBuildingTipPanel::CreateButtonByOpType(EBuildingTips p_Tip){
  //   local buildTipButtonNode
  // if #self.tbBtnNotUse > 0 then
  //   buildTipButtonNode = table.remove(self.tbBtnNotUse, #self.tbBtnNotUse)
  // else
  //   local buildTipButton = include("buildTipButton")
  //   buildTipButtonNode = buildTipButton.new(getCCSPath("buildTipButton"))
  //   buildTipButtonNode:addTo(self, 1)
  // end
  // buildTipButtonNode:initWithData(opType)
  // table.insert(self.tbBtnInuse, buildTipButtonNode)
  // return buildTipButtonNode
  auto l_buildTipButtonNode = UIBuildingTipButton::Create();
  addChild(l_buildTipButtonNode, 1);
  l_buildTipButtonNode->InitWithData(p_Tip, _RelyBuildEntity);
  return l_buildTipButtonNode;
}

void UIBuildingTipPanel::RearrangeBtnByCircle(GVector<UIBuildingTipButton *> p_BtnList){
  auto l_NumberOfBtns = (int32) p_BtnList.size();
  auto l_Sep = 6;
  if(l_NumberOfBtns >= 4)
    l_Sep = 7;
  auto l_DeltaAngle = 180 / l_Sep;
  auto l_DeltaAngleRadius = CC_DEGREES_TO_RADIANS(l_DeltaAngle);
  auto l_BeginAngleRadius = -M_PI + (M_PI - l_DeltaAngleRadius * (l_NumberOfBtns - 1)) / 2;

  for(int32  i = 1; i <= l_NumberOfBtns ;i++){
    float l_ItemAngleRad = l_BeginAngleRadius + (i -1) * l_DeltaAngleRadius;
    float l_XPosBegin = std::cos(l_ItemAngleRad) * _CircleRadius / 2;
    float l_yPosBegin = std::sin(l_ItemAngleRad) * _CircleRadius / 2 + _CircleOffsetY;
    float l_XPosEnd = std::cos(l_ItemAngleRad) * _CircleRadius;
    float l_YPosEnd = std::sin(l_ItemAngleRad) * _CircleRadius + _CircleOffsetY;
    p_BtnList[i - 1]->setPosition({l_XPosBegin, l_yPosBegin});
    p_BtnList[i - 1]->setScale(0.5);
    p_BtnList[i - 1]->setLocalZOrder(l_NumberOfBtns - i + 1);
    auto l_ScaleAction = ScaleTo::create(ACTION_TIME, 1);
    auto l_MoveToAction = MoveTo::create(ACTION_TIME, {l_XPosEnd, l_YPosEnd});
    auto l_SpawnAction = Spawn::create(
      l_MoveToAction, l_ScaleAction, nullptr
    );
    l_SpawnAction->setTag(tag_act_single_btn);
    p_BtnList[i - 1]->stopAllActionsByTag(tag_act_single_btn);
    p_BtnList[i - 1]->runAction(l_SpawnAction);
    p_BtnList[i - 1]->setVisible(true);
  }
  
  if(_CircleFrameBg){
    _CircleFrameBg->stopAllActions();
    _CircleFrameBg->setPosition({0, -_CircleRadius + 50 + _CircleOffsetY});
    _CircleFrameBg->runAction(MoveBy::create(ACTION_TIME, {0, -30}));
  }

  if(_BuildingNameFrame){
    _BuildingNameFrame->stopAllActions();
    _BuildingNameFrame->setScaleX(0.1f);
    _BuildingNameFrame->runAction(ScaleTo::create(ACTION_TIME, 1));
  }
  
  stopAllActionsByTag(tag_act_tip_show_end);
  auto l_Delay = DelayTime::create(ACTION_TIME + 0.02f);
  auto l_CallFun = CallFunc::create([](){
      //   self:buildTipShowEnd()
  });
  auto l_SeqAct = Sequence::create(
    l_Delay, l_CallFun, nullptr
  );

  l_SeqAct->setTag(tag_act_tip_show_end);
  runAction(l_SeqAct);
  auto l_Mid = std::ceil((float)l_NumberOfBtns/2.f);
  if(l_Mid > 1){
    for(int32 iii = 1; iii <= l_NumberOfBtns; iii++){
      p_BtnList[iii - 1]->setLocalZOrder(l_NumberOfBtns - std::abs(iii - l_Mid));
    }
  }
}