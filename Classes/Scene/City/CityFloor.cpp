#include "CityFloor.h"
#include "CityScene.Const.h"
#include "CityScene.Enum.h"
#include "CityScene.View.h"
#include "Module/City/City.Ctrl.h"
#include "Module/City/CitySceneEffect.h"
#include "Module/City/City.Func.h"
#include "Module/Building/IBuilding.h"
#include "Module/City/CityBuilding/CityBuilding.Mgr.h"
#include "Module/Building/BuildingLib/Wall.Ctrl.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Game/Init/Game.Top.h"
#include "Base/Common/Common.Teml.h"
#include "Module/Player/Player.Top.h"
#include "Module/Faction/Faction.Ctrl.h"
#include "Module/Building/Building.Lib.h"
#include "Module/City/CityBuilding/CityBuilding.Create.h"
#include "Module/Building/BuildingUnit/BuildingIEmbassy.h"


void CityFloor::Ctor() {
  auto l_MainCityBg = CSLoader::createNode("UiParts/Scene/City/mainCityViewBG.csb");
  _ContainerView = CSLoader::createNode("UiParts/Scene/City/mainCityViewInfo.csb");
  _MainCityFarCsb = CSLoader::createNode("UiParts/Scene/City/mainCityView_info_far.csb");
  _MainCityMiddleCsb = CSLoader::createNode("UiParts/Scene/City/mainCityView_info_middle.csb");
  _BackPnode = ParallaxNode::create();
  _ViewScrollView = Ext::ScrollView::create(_ViewScrollSize);
  _FrontPnode = ParallaxNode::create();

  _ZoomMinOffsetX = _ViewScrollSize.width - _ContainerView->getContentSize().width;
  _ZoomMinOffsetY = _ViewScrollSize.height - _ContainerView->getContentSize().height;
  _ViewScrollView->setContainer(_ContainerView);
  _BackPnode->setPosition(0, 0);
  _FrontPnode->setPosition(0, 0);
  _ContainerView->addChild(_BackPnode, -2);
  _ContainerView->addChild(_FrontPnode, -1);
  _BackPnode->addChild(_MainCityFarCsb, 2, Vec2(0.8f, 1.0f), Vec2(0, 0));
  _FrontPnode->addChild(_MainCityMiddleCsb, 3, Vec2(1.1f, 1.0f), Vec2(0, 0));
  _ViewScrollView->setMinScale(_MinScale);
  _ViewScrollView->setMaxScale(_MaxScale);
  _ViewScrollView->setZoomScale(_NormalScale);
  _ViewScrollView->setBounceable(false);
  _ViewScrollView->setIgnoreAnchorPointForPosition(false);
  _ViewScrollView->setAnchorPoint(Vec2(0.5, 0.5));
  _ViewScrollView->setPosition(Vec2(GDisplay::Get()->width / 2, GDisplay::Get()->rheight / 2));
  _ViewScrollView->setScale(GDisplay::Get()->height / _ViewScrollSize.height);
  _ViewScrollView->setClippingToBounds(false);
  GBase::DGetChildByName<Node*>(_ContainerView, "CCS_mainCityViewBG_bg")->addChild(l_MainCityBg);
  // m_ZoomScale = m_NormalScale;
  _Touchlayer = ui::Layout::create();
  _Touchlayer->setContentSize(_ContainerView->getContentSize());
  _Touchlayer->setTouchEnabled(true);
  _Touchlayer->setSwallowTouches(false);
  _ContainerView->addChild(_Touchlayer, 2000);
  _Touchlayer->addTouchEventListener(CC_CALLBACK_2(CityFloor::ViewOnClick, this));
  CreateBatchNodes();
  InitBufferNodeArray();
  InitBuild();
  // MainCityFunctions::Get()->ReArrangeZorder(_MainCityView);
  InitMainCityPos();
  Director::getInstance()->setProjection(Director::Projection::_2D);

  // if (!_MainCityView->m_IsNeedFirstFight)
  //   _MainCityView->_ViewScrollView->setContentOffset(Vec2(GDisplay::Get()->cx - 1650,
  //   GDisplay::Get()->rcy - 1000));
}

void CityFloor::CreateBatchNodes() {
  _BatchNodeOuterTiles = GDisplay::NewNode();
  _BatchNodeOuterTiles->setPosition(0, 0);
  _ContainerView->addChild(_BatchNodeOuterTiles, 69);
  _BatchNodeOuterBuilds = GDisplay::NewNode();
  _BatchNodeOuterBuilds->setPosition(0, 0);
  _ContainerView->addChild(_BatchNodeOuterBuilds, 70);
  _BatchNodeOuterBuildNpc = GDisplay::NewNode();
  _BatchNodeOuterBuildNpc->setPosition(0, 0);
  _ContainerView->addChild(_BatchNodeOuterBuildNpc, 71);
  _BatchNodeOuterBuildCommon = GDisplay::NewNode();
  _BatchNodeOuterBuildCommon->setPosition(0, 0);
  _ContainerView->addChild(_BatchNodeOuterBuildCommon, 72);
  _BatchNodeKipchaks = GDisplay::NewNode();
  _BatchNodeKipchaks->setPosition(0, 0);
  _ContainerView->addChild(_BatchNodeKipchaks, 73);
  _TblBatchNodesOuter.MainCityOuter = _BatchNodeOuterBuilds;
  _TblBatchNodesOuter.MainCityNpc = _BatchNodeOuterBuildNpc;
  _TblBatchNodesOuter.MainCityCommon = _BatchNodeOuterBuildCommon;
  _TblBatchNodesOuter.MainCityKipchaks = _BatchNodeKipchaks;
  _BatchNodeTopTip = GDisplay::NewNode();
  _BatchNodeTopTip->setPosition(0, 0);
  _ContainerView->addChild(_BatchNodeTopTip, 402);
  _TblBatchNodesTopTip["default"] = _BatchNodeTopTip;
  _BatchNodeCityOthers = GDisplay::NewNode();
  _BatchNodeCityOthers->setPosition(0, 0);
  _ContainerView->addChild(_BatchNodeCityOthers, 1);
  _BatchNodeCityEffect = GDisplay::NewNode();
  _BatchNodeCityEffect->setPosition(0, 0);
  _ContainerView->addChild(_BatchNodeCityEffect, 2);
  _BatchNodeSoldierGuards = GDisplay::NewNode();
  _ContainerView->addChild(_BatchNodeSoldierGuards);
  _BatchNodeSoldierGuards->setLocalZOrder(ECityTargetZOrder::Get()->soldiers);
  _BatchNodeSoldierGuards->setPosition(0, 0);
  // if SoraDGetFactionType() == FACTIO_TYPE.FACTIO_BYZANTINE then
  //   self.batchNodeSoldierGuards:setPosition(cc.p(100, -10))
  // end
  _BatchNodeNpc = GDisplay::NewNode();
  _BatchNodeNpc->setPosition(0, 0);
  _ContainerView->addChild(_BatchNodeNpc);
  _BatchNodeNpc->setLocalZOrder(ECityTargetZOrder::Get()->banyungong);
  _BatchNodeXiyiNpc = GDisplay::NewNode();
  _ContainerView->addChild(_BatchNodeXiyiNpc);
  _BatchNodeXiyiNpc->setLocalZOrder(ECityTargetZOrder::Get()->banyungong);
  _BatchNodeXiyiNpc->setPosition(0, 0);
  _BatchNodeCollect = GDisplay::NewNode();
  if (_BatchNodeCollect) {
    _BatchNodeCollect->removeAllChildrenWithCleanup(true);
    _BatchNodeCollect->stopAllActions();
    _BatchNodeCollect->removeFromParentAndCleanup(true);
    _BatchNodeCollect = nullptr;
  }
  if (_BatchNodeCollect == nullptr) {
    _BatchNodeCollect = GDisplay::NewNode();
    Director::getInstance()->getRunningScene()->addChild(_BatchNodeCollect, 1000);
    _BatchNodeCollect->setPosition(0, 0);
    _BatchNodeCollect->setName("mainCityView_batchNode_collect");
  }
}

void CityFloor::InitBufferNodeArray() {
  auto l_AllChildren = _ContainerView->getChildren();
  for (auto i = 0; i < l_AllChildren.size(); i++) {
    auto l_Child = l_AllChildren.at(i);
    auto l_ChildName = l_Child->getName();
    AddToBufferNodeArrayByName(l_ChildName.c_str(), l_Child);
  }
  // for (auto i = 0; i < 18; i++) {
  //   auto l_bg_hallName = StringUtils::format("BG_hall__%02d_2", i);
  //   // TODO: Check for type of node on cocos studio
  //   auto l_bghallItem = dynamic_cast<Sprite*>(GetBufferNodeByName(l_bg_hallName.c_str()));
  //   if (l_bghallItem) {
  //     auto l_texture = l_bghallItem->getTexture();
  //     if (l_texture->hasMipmaps()) {
  //       // TODO: Check if the name is right
  //       Texture2D::TexParams l_texParams;  //= {GL_LINEAR_MIPMAP_NEAREST, GL_LINEAR_MIPMAP_NEAREST, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE};
  //       l_texParams.magFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
  //       l_texParams.minFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
  //       l_texParams.sAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
  //       l_texParams.tAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
  //       l_texture->setTexParameters(l_texParams);
  //     } else {
  //       Texture2D::TexParams l_texParams;
  //       l_texParams.magFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
  //       l_texParams.minFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
  //       l_texParams.sAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
  //       l_texParams.tAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
  //       l_texture->setTexParameters(l_texParams);
  //     }
  //   }
  // }
  auto l_NewCityBgNode = GetBufferNodeByName("CCS_mainCityViewBG_bg")->getChildren().at(0);
  // if (l_NewCityBgNode) {
  //   auto l_ArrChild = l_NewCityBgNode->getChildren();
  //   for (auto i = 0; i < l_ArrChild.size(); i++) {
  //     auto l_OneChild = dynamic_cast<Sprite*>(l_ArrChild.at(i));
  //     auto l_texture = l_OneChild->getTexture();
  //     if (l_texture->hasMipmaps()) {
  //       Texture2D::TexParams l_texParams;  //= {GL_LINEAR_MIPMAP_NEAREST, GL_LINEAR_MIPMAP_NEAREST, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE};
  //       l_texParams.magFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
  //       l_texParams.minFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
  //       l_texParams.sAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
  //       l_texParams.tAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
  //       l_texture->setTexParameters(l_texParams);
  //     } else {
  //       Texture2D::TexParams l_texParams;
  //       l_texParams.magFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
  //       l_texParams.minFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
  //       l_texParams.sAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
  //       l_texParams.tAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
  //       l_texture->setTexParameters(l_texParams);
  //     }
  //   }
  // }
}

void CityFloor::InitOriginBuild() {
  // Gate
  auto l_BtnBuildChengmeng = dynamic_cast<ui::Layout *>(GetBufferNodeByName("build_1053"));
  if (l_BtnBuildChengmeng) {
    l_BtnBuildChengmeng->setSwallowTouches(false);
    l_BtnBuildChengmeng->addTouchEventListener(
            [this, l_BtnBuildChengmeng](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { 
              BuildButtonCallFun(l_BtnBuildChengmeng, p_Ref, p_Touch); 
            });
  }
  // LeftArrowTower
  auto l_BtnBuildJiantaL = dynamic_cast<ui::Layout *>(GetBufferNodeByName("build_1052"));
  if (l_BtnBuildJiantaL) {
    l_BtnBuildJiantaL->addTouchEventListener(
            [this, l_BtnBuildJiantaL](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { BuildButtonCallFun(l_BtnBuildJiantaL, p_Ref, p_Touch); });
  }

  // RightArrowTower
  auto l_BtnBuildJiantaR = dynamic_cast<ui::Layout *>(GetBufferNodeByName("build_1054"));
  if (l_BtnBuildJiantaR) {
    l_BtnBuildJiantaR->addTouchEventListener(
            [this, l_BtnBuildJiantaR](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { BuildButtonCallFun(l_BtnBuildJiantaR, p_Ref, p_Touch); });
  }
  // watchtower
  auto l_BtnBuildWatchtower = dynamic_cast<ui::Layout *>(GetBufferNodeByName("build_1055"));
  if (l_BtnBuildWatchtower) {
    l_BtnBuildWatchtower->setSwallowTouches(false);
    l_BtnBuildWatchtower->addTouchEventListener([this, l_BtnBuildWatchtower](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) {
      BuildButtonCallFun(l_BtnBuildWatchtower, p_Ref, p_Touch);
    });
  }
}

void CityFloor::InitBuild() {
  InitOriginBuild();
  for (auto ii = 1050; ii <= 1067; ii++) {
    auto l_BuildName = "build_" + std::to_string(ii);
    auto l_BuildBtn = dynamic_cast<ui::Layout *>(GetBufferNodeByName(l_BuildName.c_str()));
    if (l_BuildBtn) {
      l_BuildBtn->setSwallowTouches(false);
      l_BuildBtn->setTag(ii);
      l_BuildBtn->addTouchEventListener([=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { BuildButtonCallFun(l_BuildBtn, p_Ref, p_Touch); });
    }
  }
  auto l_BtnBuildChengmeng = GetBufferNodeByName("build_1053");
  auto l_Build_cq_item = dynamic_cast<ui::Layout *>(GetBufferNodeByName("Button_Cq"));
  if (l_Build_cq_item) {
    l_Build_cq_item->setSwallowTouches(false);
    l_Build_cq_item->addTouchEventListener(
            [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { BuildButtonCallFun(l_Build_cq_item, p_Ref, p_Touch); });
  }
  for (auto iii = 1100; iii <= 1134; iii++) {
    auto l_BuildName = "build_" + std::to_string(iii);
    auto l_BuildBtn = dynamic_cast<ui::Layout *>(GetBufferNodeByName(l_BuildName.c_str()));
    if (l_BuildBtn) {
      l_BuildBtn->setSwallowTouches(false);
      l_BuildBtn->setTag(iii);
      l_BuildBtn->addTouchEventListener([=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { BuildButtonCallFun(l_BuildBtn, p_Ref, p_Touch); });
    }
  }
  for (auto iii = 1; iii <= 10; iii++) {
    auto l_BuildName = "kipchaks_" + std::to_string(iii);
    auto l_BuildBtn = dynamic_cast<ui::Layout *>(GetBufferNodeByName(l_BuildName.c_str()));
    if (l_BuildBtn) {
      l_BuildBtn->setVisible(true);
      l_BuildBtn->setSwallowTouches(false);
      l_BuildBtn->setTag(iii);
      l_BuildBtn->addTouchEventListener([=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { KipchaksButtonCallFun(l_BuildBtn, p_Ref, p_Touch); });
    }
  }
  KipchaksUpdate();
  // Army
  auto l_ButtonMilitaryInfo = GBase::DGetChildByName<ui::Layout*>(_ContainerView, "Button_MilitaryInfo");
  if (l_ButtonMilitaryInfo) {
    l_ButtonMilitaryInfo->setSwallowTouches(false);
    l_ButtonMilitaryInfo->addTouchEventListener(
            [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { OtherBuildButtonCallFun(l_ButtonMilitaryInfo, p_Ref, p_Touch); });
    _ButtonMilitaryInfo = l_ButtonMilitaryInfo;
  }
  auto l_ButtonMerchante = GBase::DGetChildByName<ui::Layout*>(_ContainerView, "Button_Merchante");
  if (l_ButtonMerchante) {
    l_ButtonMerchante->setSwallowTouches(false);
    l_ButtonMerchante->addTouchEventListener(
            [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { OtherBuildButtonCallFun(l_ButtonMerchante, p_Ref, p_Touch); });
    _ButtonMerchante = l_ButtonMerchante;
    GBase::DShowNameOnTouchEven(_ButtonMerchante, GPair<GString, Vec2>::Make(Translate::i18n("common_text_441"), Vec2(80, 0)));
  }
  auto l_ButtonActivity = GBase::DGetChildByName<ui::Layout*>(_ContainerView, "Button_Activity");
  if (l_ButtonActivity) {
    l_ButtonActivity->setSwallowTouches(false);
    l_ButtonActivity->addTouchEventListener(
            [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { OtherBuildButtonCallFun(l_ButtonActivity, p_Ref, p_Touch); });
    _ButtonActivity = l_ButtonActivity;
  }
  auto l_ButtonEpicBattle = GBase::DGetChildByName<ui::Layout*>(_ContainerView, "build_30006");
  if (l_ButtonEpicBattle) _ButtonEpicBattle = l_ButtonEpicBattle;
  auto l_ButtonMonument = GBase::DGetChildByName<ui::Layout*>(_ContainerView, "build_30007");
  if (l_ButtonMonument) _ButtonMonument = l_ButtonMonument;
  auto l_ButtonPyramidBattle = GBase::DGetChildByName<ui::Layout*>(_ContainerView, "build_20008");
  if (l_ButtonPyramidBattle) {
    l_ButtonPyramidBattle->setTouchEnabled(true);
    l_ButtonPyramidBattle->addTouchEventListener(
            [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { OtherBuildButtonCallFun(l_ButtonPyramidBattle, p_Ref, p_Touch); });
    l_ButtonPyramidBattle->setSwallowTouches(false);
    _ButtonPyramidBattle = l_ButtonPyramidBattle;
  }
  auto l_ButtonLion = GBase::DGetChildByName<ui::Layout*>(_ContainerView, "Button_lion");
  if (l_ButtonLion) {
    l_ButtonLion->setSwallowTouches(false);
    l_ButtonLion->addTouchEventListener(
            [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { OtherBuildButtonCallFun(l_ButtonLion, p_Ref, p_Touch); });
    _ButtonLion = l_ButtonLion;
    auto l_BGLion = GetBufferNodeByName("BG_lion");
    GBase::DShowNameOnTouchEven(l_BGLion, GPair<GString, Vec2>::Make(Translate::i18n("common_text_4068"), Vec2(60, 60)));
    //_CityView->getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITY_LION_MSG");
  }
  auto l_ButtonMaTou = GBase::DGetChildByName<ui::Layout*>(_ContainerView, "Button_MaTou");
  if (l_ButtonMaTou) {
    l_ButtonMaTou->setTouchEnabled(true);
    l_ButtonMaTou->setSwallowTouches(false);
    l_ButtonMaTou->addTouchEventListener(
            [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { OtherBuildButtonCallFun(l_ButtonMaTou, p_Ref, p_Touch); });
    _ButtonMaTou = l_ButtonMaTou;
    _ButtonMaTou->setTag(GCity::Const::Get()->Gangkou);
  }
  auto l_ButtonConquer = GBase::DGetChildByName<ui::Layout*>(_ContainerView, "Button_conquer");
  if (l_ButtonConquer) {
    l_ButtonConquer->setTouchEnabled(true);
    l_ButtonConquer->setSwallowTouches(false);
    l_ButtonConquer->addTouchEventListener(
            [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { OtherBuildButtonCallFun(l_ButtonConquer, p_Ref, p_Touch); });
    _ButtonConquer = l_ButtonConquer;
    _ButtonConquer->setTag(GCity::Const::Get()->ConquerGate);
  }
  auto l_ButtonBulletInBoard = GBase::DGetChildByName<ui::Layout*>(_ContainerView, "Button_bulletin_board");
  if (l_ButtonBulletInBoard) {
    l_ButtonBulletInBoard->setTouchEnabled(false);
    l_ButtonBulletInBoard->setSwallowTouches(false);
    l_ButtonBulletInBoard->addTouchEventListener(
            [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { OtherBuildButtonCallFun(l_ButtonBulletInBoard, p_Ref, p_Touch); });
    _ButtonBulletInBoard = l_ButtonBulletInBoard;
    _ButtonBulletInBoard->setTag(GCity::Const::Get()->BulletInBoard);
  }
  for (auto i = 30001; i <= 30008; i++) {
    auto l_BuildName = StringUtils::format("build_%d", i);
    auto l_BuildButton = dynamic_cast<ui::Layout *>(GetBufferNodeByName(l_BuildName.c_str()));
    if (l_BuildButton) {
      l_BuildButton->setSwallowTouches(false);
      l_BuildButton->setTag(i);
      l_BuildButton->addTouchEventListener(
              [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { BuildButtonCallFun(l_BuildButton, p_Ref, p_Touch); });
    }
    if (i == GCity::Const::Get()->LeisureCenter)
      _ButtonLeisureCenter = l_BuildButton;
    else if (i == GCity::Const::Get()->HuoChuang)
      _ButtonHuoChuang = l_BuildButton;
    else if (i == GCity::Const::Get()->index_PetCenter)
      _ButtonPetCenter = l_BuildButton;
    else if (i == GCity::Const::Get()->index_ResurrectionHall)
      _ButtonResurrectionHall = l_BuildButton;
    else if (i == GCity::Const::Get()->index_ServiceCenter)
      _ButtonServiceCenter = l_BuildButton;
    else if (i == GCity::Const::Get()->index_EpicBattle)
      _ButtonEpicBattle = l_BuildButton;
  }
  for (auto i = 1200; i <= 1205; i++) {
    auto l_BuildName = StringUtils::format("build_%d", i);
    auto l_BuildButton = dynamic_cast<ui::Layout *>(GetBufferNodeByName(l_BuildName.c_str()));
    if (l_BuildButton) {
      l_BuildButton->setSwallowTouches(false);
      l_BuildButton->setTag(i);
      l_BuildButton->addTouchEventListener(
              [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { BuildButtonCallFun(l_BuildButton, p_Ref, p_Touch); });
    }
  }
  for (auto i = 1151; i <= 1152; i++) {
    auto l_BuildName = StringUtils::format("build_%d", i);
    auto l_BuildButton = dynamic_cast<ui::Layout *>(GetBufferNodeByName(l_BuildName.c_str()));
    if (l_BuildButton) {
      l_BuildButton->setSwallowTouches(false);
      l_BuildButton->setTag(i);
      l_BuildButton->addTouchEventListener(
              [=](Ref* p_Ref, ui::Widget::TouchEventType p_Touch) { BuildButtonCallFun(l_BuildButton, p_Ref, p_Touch); });
    }
  }
  auto l_BuildNameHuoChuang = StringUtils::format("build_%d", GCity::Const::Get()->index_HuoChuang);
  _BtnHuoChuang = dynamic_cast<ui::Layout *>(GetBufferNodeByName(l_BuildNameHuoChuang.c_str()));
  auto l_BuildNamePetCenter = StringUtils::format("build_%d", GCity::Const::Get()->index_PetCenter);
  _BtnPetCenter = dynamic_cast<ui::Layout *>(GetBufferNodeByName(l_BuildNamePetCenter.c_str()));
}

void CityFloor::InitMainCityPos() {
  // if self.isNeedFirstFight == true then
  //   local Button_Chengbao = self:getBufferNodeByName("build_1050")
  //   local posX = Button_Chengbao:getPositionX()
  //   local posY = Button_Chengbao:getPositionY() + 500
  //   local retPos = self:getContainerOffsetWhenPosPoint(cc.p(posX, posY), cc.p(display.width / 2, display.rheight / 2), false, true)
  //   print("\233\154\144\232\151\143UI---------")
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAIN_UI_HIDDLE",
  //     isHiddle = true
  //   })
  //   self.viewScrollView:setContentOffset(retPos)
  //   cityBuildFunction:setIsFirstLogin(false)
  //   return
  // end
  // local hasCargo = cityBuildFunction:getHasCargo()
  // local hasWuzi = cityBuildFunction:getHasWuzi()
  // local retPos = self:getDefaultMainCityPos()
  // local isLogin = false
  // local preScale = self.defaultScale
  // retPos, isLogin = cityBuildFunction:getCurrentMainCityPos(retPos)
  // self.isLogin = isLogin
  // if self.isLogin then
  //   print("\233\154\144\232\151\143UI---------")
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAIN_UI_HIDDLE",
  //     isHiddle = true
  //   })
  // end
  // if hasCargo then
  //   if self.isLogin then
  //     self:setZoomScale(self.normalScale, false)
  //     retPos = self:getDefaultMainCityMantouPos()
  //     self.viewScrollView:setContentOffset(retPos)
  //     return
  //   else
  //     retPos = self:getDefaultMainCityPos()
  //     retPos, isLogin, preScale = cityBuildFunction:getCurrentMainCityPos(retPos)
  //     retPos = cityBuildFunction:getTransformedPos(retPos, preScale, self.defaultScale)
  //     self:setZoomScale(self.defaultScale, false)
  //     self.viewScrollView:setContentOffset(retPos)
  //   end
  // elseif hasWuzi then
  //   if self.isLogin then
  //     self:setZoomScale(self.normalScale, false)
  //     retPos = self:getDefaultMainCityHuochuangPos()
  //     self.viewScrollView:setContentOffset(retPos)
  //     return
  //   else
  //     retPos = self:getDefaultMainCityPos()
  //     retPos, isLogin, preScale = cityBuildFunction:getCurrentMainCityPos(retPos)
  //     retPos = cityBuildFunction:getTransformedPos(retPos, preScale, self.defaultScale)
  //     self:setZoomScale(self.defaultScale, false)
  //     self.viewScrollView:setContentOffset(retPos)
  //   end
  // elseif self.isLogin then
  //   retPos = self:getDefaultMainCityPos()
  //   cityBuildFunction:getCurrentMainCityPos(retPos)
  //   self:setZoomScale(self.normalScale, false)
  //   retPos = self:getDefaultMainCityPos()
  //   self.viewScrollView:setContentOffset(retPos)
  //   return
  // else
  //   retPos = self:getDefaultMainCityPos()
  auto l_RetPos = GetDefaultMainCityPos();
  //   retPos, isLogin, preScale = cityBuildFunction:getCurrentMainCityPos(retPos)
  //   retPos = cityBuildFunction:getTransformedPos(retPos, preScale, self.defaultScale)
  //   self:setZoomScale(self.defaultScale, false)
  //   self.viewScrollView:setContentOffset(retPos)
  // n_MainCityView->n_ViewScrollView->setContentOffset(l_RetPos);
  _ViewScrollView->setContentOffset(l_RetPos);
  //   return
  // end
}

void CityFloor::InitWithBuildData() {
  auto l_ATLeft = CityCtrl::Get()->GetBuildingCellByIndex(EBuildingIndex::ArrowTowerL);
  auto l_Gate = CityCtrl::Get()->GetBuildingCellByIndex(EBuildingIndex::WallGate);
  auto l_ATRight = CityCtrl::Get()->GetBuildingCellByIndex(EBuildingIndex::ArrowTowerR);
  auto l_WatchTower = CityCtrl::Get()->GetBuildingCellByIndex(EBuildingIndex::WatchTower);
  AddBuilding(l_ATLeft->GetBuildingIndex(), l_ATLeft->GetBuildingId());
  AddBuilding(l_Gate->GetBuildingIndex(), l_Gate->GetBuildingId());
  AddBuilding(l_ATRight->GetBuildingIndex(), l_ATRight->GetBuildingId());
  AddBuilding(l_WatchTower->GetBuildingIndex(), l_WatchTower->GetBuildingId());
  EffectMainCityView::Get()->UpdateCommunityView(_CityView);
  EffectMainCityView::Get()->UpdateStarBraveStatueView(_CityView);
  //CityBuildingSpritePool::Get()->Init();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_WALL_EFFECT");
  _CityView->SetMainCityEnabled(false);
  auto l_ActDelay = DelayTime::create(0.1f);
  auto l_CallFunc = CallFunc::create([this]() { 
    this->CreateInnerCityBuilds(); 
    this->CreateOuterCityBuilds();
    CityBuildingMgr::Get()->InitWithData(_CityView);
    this->DelayInitWithBuildData();
  });
  _CityView->runAction(Sequence::create(l_ActDelay, l_CallFunc, nullptr));
}


void CityFloor::CreateInnerCityBuilds() {
  auto l_BuildList = CityCtrl::Get()->GetBuildList();
  for (auto l_Build : l_BuildList) {
    if (l_Build.second.GetBuildingIndex() == EBuildingIndex::ArrowTowerL || l_Build.second.GetBuildingIndex() == EBuildingIndex::WallGate ||
        l_Build.second.GetBuildingIndex() == EBuildingIndex::ArrowTowerR || l_Build.second.GetBuildingIndex() == EBuildingIndex::WatchTower)
      continue;
    auto l_BuildingIndex = static_cast<int32>(l_Build.second.GetBuildingIndex());
    if (l_BuildingIndex >= 1100) continue;
    auto l_CellIndexName = StringUtils::format("build_%d", l_BuildingIndex);
    auto l_BuildBtn = _CityView->GetBufferNodeByName(l_CellIndexName.c_str());
    if (!l_BuildBtn) continue;
    // The Building is Inserted on node wich called "buildName"
    auto l_BuildEntity = l_BuildBtn->getChildByName<IBuilding *>("buildName");
    if (!l_BuildEntity)
      AddBuilding(l_Build.second.GetBuildingIndex(), l_Build.second.GetBuildingId());
    else {
      l_BuildBtn->setCascadeOpacityEnabled(false);
      l_BuildBtn->setOpacity(0);
      l_BuildEntity->InitWithBuildCell(&l_Build.second);
    }
  }
  // CreateOuterCityBuilds();
}

void CityFloor::CreateOuterCityBuilds() {
  auto l_BuildList = CityCtrl::Get()->GetBuildList();
  for (auto l_Build : l_BuildList) {
    auto l_BuildingIndex = static_cast<int32>(l_Build.second.GetBuildingIndex());
    if (l_BuildingIndex < 1100) continue;
    auto l_CellIndexName = StringUtils::format("build_%d", l_BuildingIndex);
    auto l_BuildBtn = _CityView->GetBufferNodeByName(l_CellIndexName.c_str());
    if (!l_BuildBtn) continue;
    // The Building is Inserted on node wich called "buildName"
    auto l_BuildEntity = l_BuildBtn->getChildByName<IBuilding *>("buildName");
    if (!l_BuildEntity)
      AddBuilding(l_Build.second.GetBuildingIndex(), l_Build.second.GetBuildingId());
    else {
      l_BuildBtn->setCascadeOpacityEnabled(false);
      l_BuildBtn->setOpacity(0);
      l_BuildEntity->InitWithBuildCell(&l_Build.second);
    }
  }
  // auto l_Delay = DelayTime::create(0.016666666666666666f);
  // auto l_CallFunc = CallFunc::create([this]() { this->DelayInitWithBuildData(); });
  // _CityView->runAction(Sequence::create(l_Delay, l_CallFunc, nullptr));
  EffectMainCityView::addHarvestEffect();
}

void CityFloor::InitWithHuoChuangData() {
  // local self = mainCity
  // local isCanReceive = loginRewardCtrl:getCanReceive()
  // if isCanReceive then
  //   self:addBuildEffect(cityBuildConstDef.OtherBuildDef.HuoChuang)
  // else
  //   self:removeBuildEffect(cityBuildConstDef.OtherBuildDef.HuoChuang)
  // end
  // effectMainCityView.addBuildTopTipHuochuang(self)
}

void CityFloor::InitMatouData() {
  // local self = mainCity
  // local onlineRewardData = timeRewardCtrl:getTimeRewardData()
  // self.isCanGetReward = 1
  // self.rewardCount = 0
  // self.rewardOnline = {}
  // self.isAllReceive = 0
  // if onlineRewardData then
  //   self.isCanGetReward = onlineRewardData.isReceive
  //   self.rewardCount = onlineRewardData.sequence
  //   self.rewardOnline = onlineRewardData.reward
  //   self.isAllReceive = onlineRewardData.isAllReceive or 0
  // end
  // if self.isCanGetReward == 2 then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_DELETE_MATOU_TIP"
  //   })
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_ADD_BUILD_EFFECT",
  //     buildIndex = cityBuildConstDef.OtherBuildDef.Gangkou
  //   })
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_ADD_BUILD_TOP_TIP",
  //     buildIndex = cityBuildConstDef.OtherBuildDef.Gangkou
  //   })
  // else
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_TOP_TIP",
  //     buildIndex = cityBuildConstDef.OtherBuildDef.Gangkou
  //   })
  //   if self.isAllReceive == 1 then
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_DELETE_MATOU_TIP"
  //     })
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_REMOVE_BUILD_EFFECT",
  //       buildIndex = cityBuildConstDef.OtherBuildDef.Gangkou
  //     })
  //   elseif onlineRewardData then
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_ADD_BUILD_EFFECT",
  //       buildIndex = cityBuildConstDef.OtherBuildDef.Gangkou
  //     })
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_ADD_MATOU_TIP"
  //     })
  //   end
  // end
}


void CityFloor::DelayInitWithBuildData() {
  // local self = mainCity
  // userSDKManager.timeInfo.t_maincity.tend = SoraDGetSocketTime()
  // userSDKManager.timeInfo.t_maincityp.tbegin = SoraDGetSocketTime()

  // mainCityFunctions.updateLockArea(self)
  MainCityFunctions::Get()->UpdateLockArea(_CityView);
  _CityView->UpdateBuildTiles();

  // if SoraDIsGameGuide() == nil then
  //   self:autoUpdateViewScrollViewPos()
  //   self:setZoomScale(self.defaultScale, false)
  if (!GBase::DIsGameGuide()) {
    _CityView->AutoUpdateViewScrollViewPos();
    _CityView->SetZoomScale(_DefaultScale, false);
    //   guideCtrl:updateNewGuide()
    //   if SoraDGetCastleLv() >= CASTLE_LV3_LIMITED and not guideCtrl:updateGuideModule(gGuideModule.OVERVIEW) and not
    //   SoraDCurrentTopPanelFromManager() then
    //     print("\232\167\166\229\143\145\230\128\187\232\167\136\229\188\149\229\175\188")
    //   end
    //   if SoraDGetCastleLv() >= CASTLE_LV7_LIMITED then
    //     local beginStep = guideCtrl:getStepByGuideModule(gGuideModule.NEW_EPIC_WAR)
    //     print("beginStep==========", beginStep)
    //     if beginStep == 73001 and not guideCtrl:updateGuideModule(gGuideModule.NEW_EPIC_WAR) and not SoraDCurrentTopPanelFromManager() then
    //       print("\232\167\166\229\143\145\229\143\178\232\175\151\228\185\139\230\136\152\229\188\149\229\175\188")
    //     end
    //   end
  } else {
    _CityView->AutoUpdateViewScrollViewPos();
    _CityView->SetZoomScale(_DefaultScale, false);
  }
  _CityView->LoadSoldiers();
  _CityView->m_TimeHandler = GBase::DCreateTimer(_CityView, CC_CALLBACK_1(MainCityView::UpdateTime, _CityView ));
  _CityView->m_TimeHandlerPerFrame =
          GBase::DCreateTimer(_CityView,CC_CALLBACK_1(MainCityView::UpdateTimePerFrame, _CityView ));
  _CityView->UpdateTimePerFrame(Director::getInstance()->getDeltaTime());
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_WALL_VIEW");
  auto l_Build = _CityView->GetBufferNodeByName("build_" + static_cast<int32>(EBuildingIndex::WallGate));
  if (l_Build) {
    auto l_BuildEntity = l_Build->getChildByName<IBuilding*>("buildName");
    if (l_BuildEntity) {
      // auto l_ViewModelWall = l_BuildEntity->GetViewModel();
      GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_TURRET_OFFSET", l_BuildEntity);
    }
  }
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_WALL_EFFECT");
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_HOSPTIAL_VIEW");
  GBase::DSendMessage("MESSAGE_QUEST_NOTICE_RECOMMEND_UPDATE");
  EffectMainCityView::showEagle();

  // cityHorseCtrl:sendInit()

  InitPlayerLevelOffLine();
  if (GBase::DIsGameGuide()) {
    //   if self.initOtherData ~= nil then
    //     local otherData = self.initOtherData
    //     local bDealed = mainCityCreate.dealWithInitData(self, otherData)
    //     if bDealed == false then
    //       self:autoUpdateMainCityPos()
    //     end
    //   else
    //     self:autoUpdateMainCityPos()
    //     if self.isLogin and not wallsCtrl:isDestruction() and SoraDIsGameGuide() == nil and not SoraDJumpToBuyGift() then
    //       local isDebug = false
    //       if isDebug then
    //         cityBuildFunction:checkPopUpWindow()
    //       elseif xpcall(function()
    //         cityBuildFunction:checkPopUpWindow()
    //       end, function()
    //         print(debug.traceback())
    //       end) then
    //       else
    //         print("cityBuildFunction:checkPopUpWindow
    //         \229\188\130\229\184\184\228\186\134\239\188\140\232\175\183\229\164\132\231\144\134-------@ct")
    //       end
    //     end
    //   end
  } else {
    _CityView->SetMainCityEnabled(true);
  }
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_BUILD_TIP_BOX");
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_MERCHANT_VIEW");
  GBase::DSendMessage("MESSAGE_WALLS_NOTIFY_SUCCESS");
  if (WallCtrl::Get()->IsDestruction()) GBase::DSendMessage("MESSAGE_WALLS_DEFENCE_DESTROY");
  if (_CityView->m_IsLogin) {
    auto l_ActDelay = DelayTime::create(0.15);
    std::unique_ptr<bool> l_IsHiddle(new bool(false));
    auto l_CallFunc = CallFunc::create([&]() { GBase::DSendMessage("MESSAGE_MAIN_UI_HIDDLE", l_IsHiddle.get()); });
    auto l_Seq = Sequence::create(l_ActDelay, l_CallFunc, nullptr);
    _CityView->runAction(l_Seq);
  }
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_CLOSE_FIRST_FIGHT");
  if (GBase::DGetFactionType() == EFactionType::Normal) {
    auto l_BuildFirst = _CityView->GetBufferNodeByName("city_First_build_castle");
    if (l_BuildFirst) l_BuildFirst->setVisible(false);
  }
  EffectMainCityView::addWaveEffect();
  EffectMainCityView::addSoldierGuard();
  EffectMainCityView::addHarborWorker();
  EffectMainCityView::addActivityCentetNpc();
  EffectMainCityView::addCastleGateNpc();
  EffectMainCityView::showXiyiAnimation();
  EffectMainCityView::addConquerGateAnimation();
  GBase::DSendMessage("MESSAGE_SERVER_UPDATE_IDLE_GUIDE");
  _CityView->RefreshCastleSkin(true);
  CheckCastleGift();
  CheckEndlessTreasure();
  CheckAllianceTreasure();
  CheckFriend();
  CheckEpicWar();
  CheckPromoteArmy();
  CheckMastery();
  _CityView->InitVisibleArea();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_PET_SHOW");
  // userSDKManager.timeInfo.t_maincityp.tend = SoraDGetSocketTime()
  // userSDKManager.timeInfo.t_total.tend = SoraDGetSocketTime()
  if (GBase::DIsGameGuide()) {
    //   local npcTipClient = include("npcTipClient")
    //   npcTipClient:cleanTipInfo()
    //   if npcTipClient:hasTip() then
    //     print("-------\228\186\167\231\148\159\228\186\134npc\230\153\186\232\131\189\230\143\144\231\164\186-----------")
    //     local tipInfo = npcTipClient:getOrCreateTipInfo()
    //     if tipInfo.bid ~= 0 or tipInfo.bIndex ~= 0 then
    //       npcTipClient:setTopTipOn(true)
    //       SoraDSendMessage({
    //         msg = "MESSAGE_MAINCITYVIEW_ADD_NPC_TOP_TIP",
    //         bid = tipInfo.bid,
    //         bIndex = tipInfo.bIndex
    //       })
    //     end
  }
  GBase::DCloseSwitcherView();
  auto l_IsNeedHideAutoTrans = false;

  // if device.platform == "ios" then
  //   local iOSVersion = userSDKManager.getDeviceOSVersion()
  //   iOSVersion = iOSVersion and string.match(iOSVersion, "%d+.%d+")
  //   if iOSVersion and tonumber(iOSVersion) < 8.4 then
  //     isNeedHideAutoTrans = true
  //   end
  // end
  // if isNeedHideAutoTrans then
  //   local settingCtrl = gametop.playertop_:getModule("settingCtrl")
  //   print("\230\163\128\230\181\139\229\136\1768.4\228\187\165\228\184\139ios\231\179\187\231\187\159\239\188\140\229\188\128\229\144\175\232\135\170\229\138\168\231\191\187\232\175\145&\230\137\128\230\156\137\231\154\132\232\135\170\229\138\168\231\191\187\232\175\145")
  //   settingCtrl:setAutoTranslateSwitchOn()
  //   local checkList = {}
  //   for k, v in pairs(settingCtrl:getTLList()) do
  //     checkList[k] = true
  //   end
  //   dump(checkList, "checkList")
  //   settingCtrl:setTranslateLanguage(checkList)
  // end
  // userSDKManager.h5Preload()
}

// void CityFloor::ShowFirstEnter() {
//   // userSDKManager.logEvent(gSDKDef.TDonEvent.game_cg_play_complete, {})
//   // local self = mainCity
//   // self:hideAllRamadanEffectNode()
//   // for i = 1, 4 do
//   //   local cqName = "Sprite_Cq_" .. i
//   //   local spriteCqItem = self:getBufferNodeByName(cqName)
//   //   if spriteCqItem then
//   //     spriteCqItem:setVisible(false)
//   //   end
//   // end
//   // local spriteJiantachengduoR = self:getBufferNodeByName("Sprite_Jiantachengduo_R")
//   // local spriteJiantachengduoL = self:getBufferNodeByName("Sprite_Jiantachengduo_L")
//   // if spriteJiantachengduoR then
//   //   spriteJiantachengduoR:setVisible(false)
//   // end
//   // if spriteJiantachengduoL then
//   //   spriteJiantachengduoL:setVisible(false)
//   // end
//   // self.isSkipClick = false
//   // local lang = SoraDGetDefaultLanguage()
//   // local btnRes = SoraDGetImageNameByLang("res/video/icon_xsyd_%s.png", {"ar", "en"})
//   // local csbNode = display.getRunningScene()
//   // local data = {
//   //   videoFile = "cg/gameCG.mp4",
//   //   onCompleteFun = function(_video)
//   //     if self.isSkipClick then
//   //       userSDKManager.logEvent(gSDKDef.TDonEvent.game_cg_play_complete, {jump = 3021010})
//   //     end
//   //     SoraDGetCtrl("guideCtrl"):setSkipFirstFight(true)
//   //     SoraDSendMessage({
//   //       msg = "MESSAGE_SERVER_GUIDE_STEP_END",
//   //       step = 1007
//   //     })
//   //     SoraDSendMessage({
//   //       msg = "MESSAGE_MAINCITYVIEW_FIRST_FIGHT_END"
//   //     })
//   //   end,
//   //   onPanelClick = function(_video)
//   //     if not _video.isAddBtn then
//   //       _video:addSkipButton(" ", false, btnRes, true)
//   //     end
//   //   end,
//   //   onStopfunc = function(_video)
//   //     print("==onStopfunc==")
//   //   end,
//   //   onSkipfunc = function(_video)
//   //     self.isSkipClick = true
//   //   end,
//   //   needRemove = true,
//   //   displaySize = cc.size(640, 1386)
//   // }
//   // local videoPlayer = SoraDCreateVideoPlayerSingle(data)
//   // if videoPlayer then
//   //   videoPlayer:play()
//   //   videoPlayer:setContentSize(cc.size(640, 1386))
//   //   do
//   //     local lang = SoraDGetDefaultLanguage()
//   //     local btnRes = SoraDGetImageNameByLang("res/video/icon_xsyd_%s.png", {"ar", "en"})
//   //     SoraDCallOnNextFrame(videoPlayer, function()
//   //       if not videoPlayer.isAddBtn then
//   //         videoPlayer:addSkipButton(" ", false, btnRes, true)
//   //       end
//   //     end, 0.5)
//   //   end
//   // end
// }

void CityFloor::CheckCastleGift() {
  // local privilegeGiftCtrl = gametop.playertop_:getModule("privilegeGiftCtrl")
  // local gift = privilegeGiftCtrl:getCurCanBuyRechargeID() or {}
  // local starGift = not privilegeGiftCtrl:getCurStarLvCanBuyRechargeID() and {}
  // local isShow = false
  // if next(gift) or next(starGift) then
  //   isShow = true
  // end
  // local clickTime = SoraDConfigGet("Game:MainCityView:castleGiftTipTime~integer", {byUID = true})
  // if (clickTime == 0 or not serviceFunctions.isSameDay(clickTime)) and isShow then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_MAINCITYVIEW_ADD_CASTLE_GIFT_TOP_TIP"
  //   })
  // end
}

void CityFloor::CheckEndlessTreasure() { GBase::DSendMessage("MESSAGE_MAINCITYVIEW_ADD_ENDLESSTREASURE_TOP_TIP"); }

void CityFloor::CheckAllianceTreasure() { GBase::DSendMessage("MESSAGE_MAINCITYVIEW_ADD_WAREHOUSE_GIFT_TOP_TIP"); }

void CityFloor::CheckFriend() { GBase::DSendMessage("MESSAGE_SERVER_FRIEND_UPDATE_TIP"); }

void CityFloor::CheckEpicWar() { GBase::DSendMessage("MESSAGE_MAINCITYVIEW_ADD_EPICWAR_TOP_TIP"); }

void CityFloor::CheckPromoteArmy() {
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_ADD_PROMOTE_TOP_TIP");
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_FLAG_COOLING_PANEL");
}

void CityFloor::CheckMastery() {
  if (!GBase::Const::Get()->IsArClient) {
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_MASTERY_VIEW");
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_MASTERY_COOLING_PANEL");
    GBase::DSendMessage("MESSAGE_UPDATE_MASTERY_TOP_TIP");
  }
}

bool CityFloor::InitPlayerLevelOffLine() {
  // local self = mainCity
  GBase::DSendMessage("MESSAGE_MAIN_AGREEMENT_BOX");
  auto l_IsShow = false;
  auto l_IsPop = LordInfoCtrl::Get()->GetLordUpgradePopStatus();
  if (l_IsPop) {
    GBase::DSendMessage("MESSAGE_LORDINFO_UPGRADE_LEVEL");
    l_IsShow = true;
  }

  // local remainsTeamCtrl = gametop.playertop_:getModule("remainsTeamCtrl")
  // if remainsTeamCtrl:isHasInvitedInfo() then
  //   SoraDSendMessage({
  //     msg = "MESSAGE_SERVER_REMAINS_TEAM_INVITED_INFO"
  //   })
  //   isShow = true
  // end
  if (CityCtrl::Get()->GetCastleUpgradePopStatus()) {
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_CASTLE_LEVELUP");
    l_IsShow = true;
  }
  return l_IsShow;
}


IBuilding *CityFloor::AddBuilding(EBuildingIndex p_Index, EBuilding p_IdBuilding){
  static int32 l_BaseUid = 100000000;
  p_Index = EBuildingIndex::Build_1060;
  //   local self = mainCity
  // local buildButton = self:getBufferNodeByName("build_" .. buildBtnId)
  auto l_BuildingPlaceName = GString("build_") + std::to_string(static_cast<int32>(p_Index));
  auto l_BuildingPlace = GetBufferNodeByName(l_BuildingPlaceName.c_str());
  if(l_BuildingPlace){

    auto l_CityCtrl = CityCtrl::Get();
    auto l_BuildPos = l_BuildingPlace->getPosition();
    auto l_BuildType = BuildingLib::Get()->DGetBuildTypeByIndex(p_Index);
    auto l_BuildCell = l_CityCtrl->GetBuildingCellByIndex(p_Index);
    if(l_BuildType == EBuildingPlace::Outer)
      _CityView->DelBuildTile(l_BuildingPlace);
    auto l_BuildEntityExist = l_BuildingPlace->getChildByName<IBuilding *>("buildName");
    if(l_BuildEntityExist){
      if(l_BuildCell){
        l_BuildEntityExist->SetBuildingIndex(p_Index);
        l_BuildEntityExist->InitWithBuildCell(l_BuildCell);
      }else{
        l_BuildEntityExist->SetBuildingIndex(p_Index);
      }
      return l_BuildEntityExist;
    }
    
    IBuilding *l_BuildContentNode;
    if(l_BuildType == EBuildingPlace::Inner)
      l_BuildContentNode = CityBuildingCreate::Get()->CreateBuild(p_IdBuilding);
    else 
      l_BuildContentNode = CityBuildingCreate::Get()->CreateBuild(p_IdBuilding, _BatchNodeOuterBuilds, l_BuildPos);
    l_BuildingPlace->addChild(l_BuildContentNode, 1);
    l_BuildContentNode->setName("buildName");
    l_BuildContentNode->setTag(l_BaseUid++);
    l_BuildContentNode->setIgnoreAnchorPointForPosition(false);
    l_BuildContentNode->setAnchorPoint(Vec2(0.5, 0.5));
    l_BuildContentNode->setPosition(l_BuildingPlace->getContentSize()/2);
    if(l_BuildCell){
      l_BuildContentNode->SetBuildingIndex(p_Index);
      l_BuildContentNode->InitWithBuildCell(l_BuildCell);
    }else{
      l_BuildContentNode->SetBuildingIndex(p_Index);
    }
    return l_BuildContentNode;
  }else{
    CCLOG("Cannot Fing Building Place of %d", static_cast<int32>(p_Index));
  }
  return nullptr;
}