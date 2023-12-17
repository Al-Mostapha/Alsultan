#include "UIBuildingTipButton.h"
#include "Module/Building/IBuilding.h"
#include "Module/Faction/Faction.Ctrl.h"

UIBuildingTipButton *UIBuildingTipButton::Create(){
  auto l_Inst = UIBuildingTipButton::create();
  l_Inst->Ctor();
  return l_Inst;
}

void UIBuildingTipButton::Ctor(){
  _OpType = EBuildingTips::OpNone;
  _BuildEntity = nullptr;
  _IsActive = true;
  CreateUI();
}

void UIBuildingTipButton::CreateUI(){
  
  _Button = ui::Button::create();
  _Button->setTouchEnabled(true);
  _Button->loadTextures("frame_common_round.png", "frame_common_round.png", 
  "frame_common_round.png", TextureResType::PLIST);
  _Button->setContentSize(Size(110, 110));
  _Button->setPressedActionEnabled(true);
  addChild(_Button);

  _Icon = ui::ImageView::create();
  _Icon->ignoreContentAdaptWithSize(true);
  _Icon->setContentSize(Size(110, 110));
  _Icon->setPosition(Vec2(49, 49));
  _Icon->loadTexture("icon_building_levelup.png", TextureResType::PLIST);
  _Icon->setGlobalZOrder(10000);
  _Button->addChild(_Icon);

  _TextTopBg = GDisplay::Get()->NewNode();
  _Button->addChild(_TextTopBg);
  _TextTopBg->setPosition(Vec2(49, 110));
  
  auto l_ImgLeft = ui::ImageView::create();
  l_ImgLeft->loadTexture("frame_sheer_black_07.png", TextureResType::PLIST);
  l_ImgLeft->ignoreContentAdaptWithSize(false);
  l_ImgLeft->setContentSize(Size(49, 24));
  l_ImgLeft->setAnchorPoint(Vec2(1, 0.5));
  l_ImgLeft->setPosition(Vec2(0, 0));
  _TextTopBg->addChild(l_ImgLeft);

  auto l_ImgRight = ui::ImageView::create();
  l_ImgRight->loadTexture("frame_sheer_black_07.png", TextureResType::PLIST);
  l_ImgRight->ignoreContentAdaptWithSize(false);
  l_ImgRight->setContentSize(Size(49, 24));
  l_ImgRight->setAnchorPoint(Vec2(1, 0.5));
  l_ImgRight->setFlippedX(true);
  _TextTopBg->addChild(l_ImgRight);

  _IconSmall = GDisplay::Get()->NewSprite("icon_small_gold.png");
  _Button->addChild(_IconSmall);
  _IconSmall->setPosition(Vec2(17, 110));
  _IconSmall->setScale(0.85f);
  
  _TextMiddle = ui::Text::create();
  _TextMiddle->setFontSize(22);
  _TextMiddle->setColor(Color3B(215, 175, 20));
  _TextMiddle->setPosition(Vec2(49, 76));
  _TextMiddle->setTextHorizontalAlignment(TextHAlignment::CENTER);
  _TextMiddle->setTextVerticalAlignment(TextVAlignment::CENTER);
  _Button->addChild(_TextMiddle);
  
  _TextTop = ui::Text::create();
  _TextTop->setFontSize(22);
  _TextTop->setColor(Color3B(215, 175, 20));
  _TextTop->setPosition(Vec2(84, 110));
  _TextTop->setTextHorizontalAlignment(TextHAlignment::CENTER);
  _TextTop->setTextVerticalAlignment(TextVAlignment::CENTER);
  _Button->addChild(_TextTop);
  _TextBg = GDisplay::Get()->NewNode();
  _Button->addChild(_TextBg);
  _TextBg->setPosition({49, 1.5});
  
  _TextBgL = ui::ImageView::create();
  _TextBgL->loadTexture("frame_sheer_black_07.png", TextureResType::PLIST);
  _TextBgL->ignoreContentAdaptWithSize(false);
  _TextBgL->setContentSize({49, 24});
  _TextBgL->setAnchorPoint({1, 1});
  _TextBgL->setPosition({0, 12});
  _TextBg->addChild(_TextBgL);
  _TextBgR = ImageView::create();
  _TextBgR->loadTexture("frame_sheer_black_07.png", TextureResType::PLIST);
  
  _TextBgR->ignoreContentAdaptWithSize(false);
  _TextBgR->setContentSize({49, 24});
  _TextBgR->setAnchorPoint({1,1});
  _TextBgR->setPosition({0, 12});
  _TextBgR->setFlippedX(true);
  _TextBg->addChild(_TextBgR);

  _Text = ui::Text::create();
  _Text->setFontSize(21);
  _Text->setColor({220, 215, 180});
  _Text->setAnchorPoint({0.5, 1});
  _Text->setPosition({49, 12});
  _Text->setTextHorizontalAlignment(TextHAlignment::CENTER);
  _Text->setTextVerticalAlignment(TextVAlignment::TOP);
  _Button->addChild(_Text);
  
  _TextBottomBg = GDisplay::Get()->NewNode();
  _Button->addChild(_TextBottomBg);
  _TextBottomBg->setPosition({49, 27});
  
  auto l_ImgBtLeft = ui::ImageView::create();
  l_ImgBtLeft->loadTexture("frame_sheer_black_07.png", TextureResType::PLIST);
  l_ImgBtLeft->ignoreContentAdaptWithSize(false);
  l_ImgBtLeft->setContentSize({49, 24});
  l_ImgBtLeft->setAnchorPoint({1, 0.5});
  l_ImgBtLeft->setPosition({0, 0});
  _TextBottomBg->addChild(l_ImgBtLeft);
  
  auto l_ImgBtRight = ui::ImageView::create();
  l_ImgBtRight->loadTexture("frame_sheer_black_07.png", TextureResType::PLIST);
  l_ImgBtRight->ignoreContentAdaptWithSize(false);
  l_ImgBtRight->setContentSize({49, 24});
  l_ImgBtRight->setAnchorPoint({1, 0.5});
  l_ImgBtRight->setPosition({0, 0});
  l_ImgBtRight->setFlippedX(true);

  _TextBottomBg->addChild(l_ImgBtRight);
  _TextBottom = ui::Text::create();
  _TextBottom->setFontSize(22);
  _TextBottom->setColor({130, 210, 130});
  _TextBottom->setAnchorPoint({0.5, 0.5});
  _TextBottom->setPosition({53, 27});
  _TextBottom->setTextHorizontalAlignment(TextHAlignment::CENTER);
  _TextBottom->setTextVerticalAlignment(TextVAlignment::CENTER);
  _Button->addChild(_TextBottom);
}

void UIBuildingTipButton::InitWithData(EBuildingTips p_Tip, IBuilding *p_Building){
  // if nil == data or nil == data.opType then
  //   return
  // end
  if(p_Tip == EBuildingTips::OpNone)
    return;
  auto l_NationCtrl = FactionCtrl::Get();
  _OpType = p_Tip;
  auto l_OpData = l_NationCtrl->GetBuildTipButtonCfgById(p_Tip);
  _BuildEntity = p_Building;
  // self.handler = data.handler
  // local iconFile = self.opType.PicFile
  auto l_IconFile = l_OpData.PicFile;
  // local bid = tonumber(self.buildEntity:getBuildBid())
  auto l_BID = _BuildEntity->GetBuildingId();
  if(p_Tip == EBuildingTips::OpBoostByTool){
    if(l_BID == EBuilding::Farm)
      l_IconFile = "icon_building_up_food.png";
    else if(l_BID == EBuilding::LumberMill)
      l_IconFile = "icon_building_up_wood.png";
    else if(l_BID == EBuilding::IronMine)
      l_IconFile = "icon_building_up_iron.png";
    else if(l_BID == EBuilding::SilverMine)
      l_IconFile = "icon_building_up_silver.png";
    else if(l_BID == EBuilding::CrystalMine)
      l_IconFile = "icon_building_up_crystal.png";
  } else if(p_Tip == EBuildingTips::OpCollect){
    if(l_BID == EBuilding::Farm)
      l_IconFile = "icon_middle_food.png";
    else if(l_BID == EBuilding::LumberMill)
      l_IconFile = "icon_middle_wood.png";
    else if(l_BID == EBuilding::IronMine)
      l_IconFile = "icon_middle_iron.png";
    else if(l_BID == EBuilding::SilverMine)
      l_IconFile = "icon_middle_silver.png";
    else if(l_BID == EBuilding::CrystalMine)
      l_IconFile = "icon_middle_crystal.png";
  } else if(p_Tip == EBuildingTips::OpPetExchange){
    l_IconFile = "icon_pet_exchange_enter.png";
  }

  //_Icon->loadTexture(l_IconFile, TextureResType::PLIST);
  // self.icon:ignoreContentAdaptWithSize(true)
  _Icon->ignoreContentAdaptWithSize(true);
  _Text->ignoreContentAdaptWithSize(true);
  _Text->setTextAreaSize({0, 0});
  // self.text:setString(i18n(self.opType.Desc))
  _Text->setString(Translate::i18n(l_OpData.Desc.c_str()));
  // if bid == BUILDID.STAR_BRAVE_STATUE and self.opType.OpName == BOP_NAME.BOP_STARSPEEDUP then
  //   self.text:setString(i18n("common_text_018"))
  // end
  if(l_BID == EBuilding::StarBraveStatue && p_Tip == EBuildingTips::OpStarSpeedUp)
    _Text->setString(Translate::i18n("common_text_018"));
  _TextBottom->setVisible(false);
  _TextBottomBg->setVisible(false);
  _TextTop->setVisible(false);
  _TextTopBg->setVisible(false);
  _IconSmall->setVisible(false);
  _TextMiddle->setVisible(false);
  if(_RedPoint)
    _RedPoint->setVisible(false);

  if(p_Tip == EBuildingTips::OpDiscuss)
    ShowLowGuideEffect();
  else if(p_Tip == EBuildingTips::OpSupport){
    //   if userSDKManager.sdkMessageCount and 0 < userSDKManager.sdkMessageCount.serviceCount then
    ShowPremiumVipEffect();
    //   end
  } else if(p_Tip == EBuildingTips::OpForeignPavilion){
    //   if clientEventMgr.judgeIsOpen(gActivityTimeActivityID.EXOTIC_PAVILION_ACTIVITY) and not SoraDGetCtrl("exoticPavilionCtrl"):getIsGetDailyReward() and SoraDGetCastleLv() >= CASTLE_LV4_LIMITED then
    //     self:showPavilionEffect()
    //   end
  } else if(p_Tip == EBuildingTips::OpSpeedUpByGold){
    _TextMiddle->setVisible(true);
    _TextMiddle->setPosition({49,_TextMiddle->getPositionY() + 5 });
    BeginTime();
  } else if(p_Tip == EBuildingTips::OpSpeedUpByTool || p_Tip == EBuildingTips::OpStarSpeedUp){
    _Icon->setFlippedX(!GBase::DFIsRA());
    //   local backpackCtrl = gametop.playertop_:getModule("backpackCtrl")
    //   local tableItemData = backpackCtrl:getSpeedUpItemList(gAbbrSpeedUpType.BUILD_UPGRADE)
    //   if #tableItemData > 0 then
    //     self:showLowGuideEffect()
          ShowLowGuideEffect();
    //   end
  }else if(p_Tip == EBuildingTips::OpPyramid)
    BeginTime();
  else if(p_Tip == EBuildingTips::OpCollect)
    BeginTime();
  else if(p_Tip == EBuildingTips::OpBoost){
    if(_BuildEntity->GetHasBuff())
      BeginTime();
    else 
      UpdateBoostGold();
  } else if(p_Tip == EBuildingTips::OpBoostByTool){
    UpdateBoostTool();
  } else if(p_Tip == EBuildingTips::OpWarGem){
    UpdateTime();
  } else if(p_Tip == EBuildingTips::OpArtifact){
    UpdateTime();
  } else if(p_Tip ==  EBuildingTips::OpResuscitate){
    BeginTime();
  } else if(p_Tip == EBuildingTips::OpPremiumVipMall){
    //   local clickPremiumVipMall = SoraDConfigGet("Game:MainCityView:clickPremiumVipMallBtn~integer", {byUID = true})
    //   if clickPremiumVipMall == 0 or not serviceFunctions.isSameDay(clickPremiumVipMall) then
    //     self:showPremiumVipEffect()
            ShowPremiumVipEffect();
    //   end
  } else if(p_Tip == EBuildingTips::OpPetExchange){
    //   local clickPetExchange = SoraDConfigGet("Game:MainCityView:clickPetExchangeBtn~integer", {byUID = true})
    //   if clickPetExchange == 0 or not serviceFunctions.isSameDay(clickPetExchange) then
    //     local backpackCtrl = gametop.playertop_:getModule("backpackCtrl")
    //     local ret = backpackCtrl:getPetPointItemList()
    //     if ret and #ret > 0 then
    //       self:showLowGuideEffect()
    //     else
    //       self:hideLowGuideEffect(false)
    //     end
    //   else
    //     self:hideLowGuideEffect(false)
    //   end
  } else if(p_Tip == EBuildingTips::OpCityGift /*|| p_Tip == EBuildingTips::BOP_CITY_LEVEL_GIFT*/){
    UpdateCastleGift();
  } else if(p_Tip == EBuildingTips::OpFriend){
  //   local contactCtrl = gametop.playertop_:getModule("contactCtrl")
  //   local inviteMap = contactCtrl:getRecvInviteMap()
  //   if next(inviteMap) then
  //     if not self.redPoint then
  //       self.redPoint = display.newSprite("#common_mail_hongdian.png")
  //       self.redPoint:setPosition(25, 25)
  //       self.redPoint:addTo(self, 5)
  //     else
  //       self.redPoint:setVisible(true)
  //     end
  //   elseif self.redPoint then
  //     self.redPoint:setVisible(false)
  //   end
  } else if(p_Tip == EBuildingTips::OpUpgrade || p_Tip == EBuildingTips::OpWar){
    if(_BuildEntity && _BuildEntity->_IsCanUpgrade)
      ShowLowGuideEffect();
  } else if(p_Tip == EBuildingTips::OpStarUpgrade && _BuildEntity &&_BuildEntity->_IsCanUpgradeStar){
    ShowLowGuideEffect();
  }

  _Button->addTouchEventListener(CC_CALLBACK_2(UIBuildingTipButton::BtnClickCallBack, this));
  if(_Text->getContentSize().width > 180)
    _Text->setScale(0.8f);
  else
    _Text->setScale(1);
  if(_Text->getContentSize().width > 120)
    GBase::DGetAutoHeightLabel(_Text, 120);
  _TextBgL->setScaleY(_Text->getContentSize().height * _Text->getScaleY() / 24);
  _TextBgR->setScaleY(_Text->getContentSize().height * _Text->getScaleY() / 24);
  if(l_OpData.scale > 0)
    _Icon->setScale(l_OpData.scale);
  _Icon->setPosition( _Icon->getPosition() + l_OpData.offset );
}
