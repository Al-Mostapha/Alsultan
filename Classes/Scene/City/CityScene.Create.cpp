#include "CityScene.Create.h"

void MainCityCreate::Ctor(){
  // self:setAnchorPoint(cc.p(0.5, 0.5))
  // self:setPosition(cc.p(display.cx, display.rcy))
  setContentSize(Director::getInstance()->getVisibleSize());
  setAnchorPoint(Vec2(0.5, 0.5));
  GBase::Display::Get()->cx = Director::getInstance()->getVisibleSize().width / 2;
  GBase::Display::Get()->rcy = -Director::getInstance()->getVisibleSize().height / 2;
  setPosition(GBase::Display::Get()->cx, GBase::Display::Get()->rcy);
  n_ContainerView     = CSLoader::createNode("Scene/City/mainCityViewInfo.csb");
  n_MainCityFarCsb    = CSLoader::createNode("Scene/City/mainCityView_info_far.csb");
  n_MainCityMiddleCsb = CSLoader::createNode("Scene/City/mainCityView_info_middle.csb");
  m_ViewScrollViewSize = Size(getContentSize().width, getContentSize().height - (m_HUITop + m_HUIBottom + GBase::Display::Get()->iPhoneXOffset));
  if(m_IsNeedFirstFight)
    m_ViewScrollViewSize = Size(getContentSize().width, getContentSize().height);
  m_ZoomMinOffsetX = m_ViewScrollViewSize.width - n_ContainerView->getContentSize().width;
  m_ZoomMinOffsetY = m_ViewScrollViewSize.height - n_ContainerView->getContentSize().height;
  n_ViewScrollView = Ext::ScrollView::create(m_ViewScrollViewSize);
  n_ViewScrollView->setContainer(n_ContainerView);

  n_BackPnode = ParallaxNode::create();
  n_BackPnode->setPosition(0, 0);
  n_FrontPnode = ParallaxNode::create();
  n_FrontPnode->setPosition(0, 0);
  n_ContainerView->addChild(n_BackPnode, -2);
  n_ContainerView->addChild(n_FrontPnode, -1);
  n_BackPnode->addChild(n_MainCityFarCsb, 2, Vec2(0.8, 1), Vec2(0, 0));
  auto l_Pos = Vec2(0, 0);
  // if SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //   pos = cc.p(0, 256)
  // end
  n_FrontPnode->addChild(n_MainCityMiddleCsb, 3, Vec2(1.1, 1), l_Pos);
  n_ViewScrollView->setMinScale(m_MinScale);
  n_ViewScrollView->setMaxScale(m_MaxScale);
  n_ViewScrollView->setZoomScale(m_NormalScale);
  n_ViewScrollView->setBounceable(false);
  // self.viewScrollView:setInertiaValue(self.inertia)
  m_ZoomScale = m_NormalScale;
  n_Touchlayer = ui::Layout::create();
  n_Touchlayer->setContentSize(n_ContainerView->getContentSize());
  n_Touchlayer->setTouchEnabled(true);
  n_Touchlayer->setSwallowTouches(false);
  n_ContainerView->addChild(n_Touchlayer, 2000);
  n_Touchlayer->addTouchEventListener(CC_CALLBACK_2(MainCityCreate::ViewOnClick, this));
  /** if param ~= nil then
      self.initOtherData = param
    end*/
  Director::getInstance()->setProjection(Director::Projection::_2D);
  if(!m_IsNeedFirstFight)
    n_ViewScrollView->setContentOffset(Vec2(GBase::Display::Get()->cx - 1650, GBase::Display::Get()->rcy - 1000));
}

void MainCityCreate::CreateGroupNode(ECityTargetGroupID p_GroupId, int32 p_ZOrder){
  Node *l_Node  = Node::create();
  if(m_CityGroupNode.find(p_GroupId) == m_CityGroupNode.end()){
    Vector<Node *> l_Vector;
    l_Vector.pushBack(l_Node);
    m_CityGroupNode[p_GroupId] = l_Vector;
  }else{
    m_CityGroupNode[p_GroupId].pushBack(l_Node); 
  }
  n_ContainerView->addChild(l_Node, p_ZOrder);
  
}

void MainCityCreate::InitCityGroupNode(){
  CreateGroupNode(ECityTargetGroupID::GROUP_HALLTOP, ECityTargetZOrder::Get()->bg);
  CreateGroupNode(ECityTargetGroupID::GROUP_WALL, ECityTargetZOrder::Get()->wall);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_BG, ECityTargetZOrder::Get()->castle_bg);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_B_ACT, ECityTargetZOrder::Get()->castle_b_act);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_B_EFFECT, ECityTargetZOrder::Get()->castle_b_effect);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE, ECityTargetZOrder::Get()->castle_skin);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_DH, ECityTargetZOrder::Get()->castle_dh);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_EXTRA, ECityTargetZOrder::Get()->castle_extra);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_TOP_ACT, ECityTargetZOrder::Get()->castle_top_act);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_TOP_EFFECT, ECityTargetZOrder::Get()->castle_top_effect);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_ANIMATION, ECityTargetZOrder::Get()->castle_animation);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_OTHER, ECityTargetZOrder::Get()->castle_other);
  CreateGroupNode(ECityTargetGroupID::GROUP_NIGHT_COMMON, ECityTargetZOrder::Get()->night_common);
  CreateGroupNode(ECityTargetGroupID::GROUP_NIGHT_BUILD, ECityTargetZOrder::Get()->night_wall);
  CreateGroupNode(ECityTargetGroupID::GROUP_BUILD_SHOW_NAME_BG, ECityTargetZOrder::Get()->show_nameBg);
  CreateGroupNode(ECityTargetGroupID::GROUP_BUILD_SHOW_NAME, ECityTargetZOrder::Get()->show_name);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_NIGHT_SKIN, ECityTargetZOrder::Get()->castle_night_skin);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_NIGHT_ACT, ECityTargetZOrder::Get()->castle_night_act);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_NIGHT_B_EFFECT, ECityTargetZOrder::Get()->castle_night_b_effect);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_NIGHT_DH, ECityTargetZOrder::Get()->castle_night_dh);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_NIGHT_TOP_ACT, ECityTargetZOrder::Get()->castle_night_top_act);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_NIGHT_TOP_EFFECT, ECityTargetZOrder::Get()->castle_night_top_effect);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_NIGHT_ANIMATION, ECityTargetZOrder::Get()->castle_night_animation);
  CreateGroupNode(ECityTargetGroupID::GROUP_CASTLE_NIGHT_EXTRA, ECityTargetZOrder::Get()->castle_night_extra);
  CreateGroupNode(ECityTargetGroupID::GROUP_OTHER, ECityTargetZOrder::Get()->other);
}

void MainCityCreate::ViewOnClick(Ref* p_Ref, ui::Widget::TouchEventType p_Type){

}

void MainCityCreate::CreateBatchNodes(){
  n_BatchNodeOuterTiles = GBase::Display::NewNode();
  n_BatchNodeOuterTiles->setPosition(0, 0);
  n_ContainerView->addChild(n_BatchNodeOuterTiles, 69);
  n_BatchNodeOuterBuilds = GBase::Display::NewNode();
  n_BatchNodeOuterBuilds->setPosition(0, 0);
  n_ContainerView->addChild(n_BatchNodeOuterBuilds, 70);
  n_BatchNodeOuterBuildNpc = GBase::Display::NewNode();
  n_BatchNodeOuterBuildNpc->setPosition(0, 0);
  n_ContainerView->addChild(n_BatchNodeOuterBuildNpc, 71);
  n_BatchNodeOuterBuildCommon = GBase::Display::NewNode();
  n_BatchNodeOuterBuildCommon->setPosition(0, 0);
  n_ContainerView->addChild(n_BatchNodeOuterBuildCommon, 72);
  n_BatchNodeKipchaks = GBase::Display::NewNode();
  n_BatchNodeKipchaks->setPosition(0, 0);
  n_ContainerView->addChild(n_BatchNodeKipchaks, 73);
  m_TblBatchNodesOuter["mainCityOuter"]     = n_BatchNodeOuterBuilds;
  m_TblBatchNodesOuter["mainCityNpc"]       = n_BatchNodeOuterBuildNpc;
  m_TblBatchNodesOuter["mainCityCommon"]    = n_BatchNodeOuterBuildCommon;
  m_TblBatchNodesOuter["mainCityKipchaks"]  = n_BatchNodeKipchaks;
  n_BatchNodeTopTip = GBase::Display::NewNode();
  n_BatchNodeTopTip->setPosition(0, 0);
  n_ContainerView->addChild(n_BatchNodeTopTip, 402);
  m_TblBatchNodesTopTip["default"] = n_BatchNodeTopTip;
  n_BatchNodeCityOthers = GBase::Display::NewNode();
  n_BatchNodeCityOthers->setPosition(0, 0);
  n_ContainerView->addChild(n_BatchNodeCityOthers, 1);
  n_BatchNodeCityEffect = GBase::Display::NewNode();
  n_BatchNodeCityEffect->setPosition(0, 0);
  n_ContainerView->addChild(n_BatchNodeCityEffect, 2);
  n_BatchNodeSoldierGuards = GBase::Display::NewNode();
  n_ContainerView->addChild(n_BatchNodeSoldierGuards);
  n_BatchNodeSoldierGuards->setLocalZOrder(ECityTargetZOrder::Get()->soldiers);
  n_BatchNodeSoldierGuards->setPosition(0, 0);
  // if SoraDGetFactionType() == FACTION_TYPE.FACTION_BYZANTINE then
  //   self.batchNodeSoldierGuards:setPosition(cc.p(100, -10))
  // end
  n_BatchNodeNpc = GBase::Display::NewNode();
  n_BatchNodeNpc->setPosition(0, 0);
  n_ContainerView->addChild(n_BatchNodeNpc);
  n_BatchNodeNpc->setLocalZOrder(ECityTargetZOrder::Get()->banyungong);
  n_BatchNodeXiyiNpc = GBase::Display::NewNode();
  n_ContainerView->addChild(n_BatchNodeXiyiNpc);
  n_BatchNodeXiyiNpc->setLocalZOrder(ECityTargetZOrder::Get()->banyungong);
  n_BatchNodeXiyiNpc->setPosition(0, 0);
  n_BatchNodeCollect = GBase::Display::NewNode();
  if(n_BatchNodeCollect){
    n_BatchNodeCollect->removeAllChildrenWithCleanup(true);
    n_BatchNodeCollect->stopAllActions();
    n_BatchNodeCollect->removeFromParentAndCleanup(true);
    n_BatchNodeCollect = nullptr;
  }
  if(n_BatchNodeCollect == nullptr){
    n_BatchNodeCollect = GBase::Display::NewNode();
    Director::getInstance()->getRunningScene()->addChild(n_BatchNodeCollect, 1000);
    n_BatchNodeCollect->setPosition(0, 0);
    n_BatchNodeCollect->setName("mainCityView_batchNode_collect");
  }
}

void MainCityCreate::CreateFightBatchNodes(){
  if(!n_BatchNodeFightBullet){
    n_BatchNodeFightBullet = GBase::Display::NewNode();
    n_ContainerView->addChild(n_BatchNodeFightBullet, 50);
  }
  if(!n_BatchNodeFightBuilds){
    n_BatchNodeFightBuilds = GBase::Display::NewNode();
    n_ContainerView->addChild(n_BatchNodeFightBuilds, 20);
  }
  if(!n_BatchNodeFightBuildWalls){
    n_BatchNodeFightBuildWalls = GBase::Display::NewNode();
    n_ContainerView->addChild(n_BatchNodeFightBuildWalls, 30);
  }
  if(!n_BatchNodeFightSoldiers){
    n_BatchNodeFightSoldiers = GBase::Display::NewNode();
    n_ContainerView->addChild(n_BatchNodeFightSoldiers, 45);
  }
  if(!n_EffectFightNode){
    n_EffectFightNode = GBase::Display::NewNode();
    n_ContainerView->addChild(n_EffectFightNode, 55);
  }
}

void MainCityCreate::InitOriginBuild(){
  //Gate
  auto  l_BtnBuildChengmeng = GetBufferNodeByName("build_1053");
  if(l_BtnBuildChengmeng){
    l_BtnBuildChengmeng->setSwallowTouches(false);
    l_BtnBuildChengmeng->addTouchEventListener([this, l_BtnBuildChengmeng](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      BuildButtonCallFun(l_BtnBuildChengmeng, p_Ref, p_Touch);
    });
  }
  // LeftArrowTower
  auto  l_BtnBuildJiantaL = GetBufferNodeByName("build_1052");
  if(l_BtnBuildJiantaL){
    l_BtnBuildJiantaL->addTouchEventListener([this, l_BtnBuildJiantaL](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      BuildButtonCallFun(l_BtnBuildJiantaL, p_Ref, p_Touch);
    });
  }

  // RightArrowTower
  auto l_BtnBuildJiantaR = GetBufferNodeByName("build_1054");
  if(l_BtnBuildJiantaR){
    l_BtnBuildJiantaR->addTouchEventListener([this, l_BtnBuildJiantaR](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      BuildButtonCallFun(l_BtnBuildJiantaR, p_Ref, p_Touch);
    });
  }
  // watchtower
  auto l_BtnBuildWatchtower = GetBufferNodeByName("build_1055");
  if(l_BtnBuildWatchtower){
    l_BtnBuildWatchtower->setSwallowTouches(false);
    l_BtnBuildWatchtower->addTouchEventListener([this, l_BtnBuildWatchtower](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      BuildButtonCallFun(l_BtnBuildWatchtower, p_Ref, p_Touch);
    });
  }
}

void MainCityCreate::InitBuild(){
  InitOriginBuild();
  for(auto ii = 1050; ii <= 1067; ii++){
    auto l_BuildName = "build_" + std::to_string(ii);
    auto l_BuildBtn = GetBufferNodeByName(l_BuildName.c_str());
    if(l_BuildBtn){
      l_BuildBtn->setSwallowTouches(false);
      l_BuildBtn->setTag(ii);
      l_BuildBtn->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
        BuildButtonCallFun(l_BuildBtn, p_Ref, p_Touch);
      });
    }
  }
  auto l_BtnBuildChengmeng = GetBufferNodeByName("build_1053");
  auto l_Build_cq_item = GetBufferNodeByName("Button_Cq");
  if(l_Build_cq_item){
    l_Build_cq_item->setSwallowTouches(false);
    l_Build_cq_item->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      BuildButtonCallFun(l_Build_cq_item, p_Ref, p_Touch);
    });
  }
  for(auto iii = 1100; iii <=  1134 ; iii++ ){
    auto l_BuildName = "build_" + std::to_string(iii);
    auto l_BuildBtn = GetBufferNodeByName(l_BuildName.c_str());
    if(l_BuildBtn){
      l_BuildBtn->setSwallowTouches(false);
      l_BuildBtn->setTag(iii);
      l_BuildBtn->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
        BuildButtonCallFun(l_BuildBtn, p_Ref, p_Touch);
      });
    }
  }
  for(auto iii = 1; iii <=  10 ; iii++ ){
    auto l_BuildName = "kipchaks_" + std::to_string(iii);
    auto l_BuildBtn = GetBufferNodeByName(l_BuildName.c_str());
    if(l_BuildBtn){
      l_BuildBtn->setVisible(true);
      l_BuildBtn->setSwallowTouches(false);
      l_BuildBtn->setTag(iii);
      l_BuildBtn->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
        KipchaksButtonCallFun(l_BuildBtn, p_Ref, p_Touch);
      });
    }
  }
  KipchaksUpdate();
  // Army
  auto l_ButtonMilitaryInfo = GBase::getChildByName<ui::Layout *>(n_ContainerView, "Button_MilitaryInfo");
  if(l_ButtonMilitaryInfo){
    l_ButtonMilitaryInfo->setSwallowTouches(false);
    l_ButtonMilitaryInfo->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      OtherBuildButtonCallFun(l_ButtonMilitaryInfo, p_Ref, p_Touch);
    });
    n_ButtonMilitaryInfo = l_ButtonMilitaryInfo;
  }
  auto l_ButtonMerchante = GBase::getChildByName<ui::Layout *>(n_ContainerView, "Button_Merchante");
  if(l_ButtonMerchante){
    l_ButtonMerchante->setSwallowTouches(false);
    l_ButtonMerchante->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      OtherBuildButtonCallFun(l_ButtonMerchante, p_Ref, p_Touch);
    });
    n_ButtonMerchante = l_ButtonMerchante;
    GBase::DShowNameOnTouchEven(n_ButtonMerchante, GPair<GString, Vec2>::Make(
      Translate::i18n("common_text_441"), Vec2(80, 0)
    ));
  }
  auto l_ButtonActivity = GBase::getChildByName<ui::Layout *>(n_ContainerView, "Button_Activity");
  if(l_ButtonActivity){
    l_ButtonActivity->setSwallowTouches(false);
    l_ButtonActivity->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      OtherBuildButtonCallFun(l_ButtonActivity, p_Ref, p_Touch);
    });
    n_ButtonActivity = l_ButtonActivity;
  }
  auto l_ButtonEpicBattle = GBase::getChildByName<ui::Layout *>(n_ContainerView, "build_30006");
  if(l_ButtonEpicBattle)
    n_ButtonEpicBattle = l_ButtonEpicBattle;
  auto l_ButtonMonument = GBase::getChildByName<ui::Layout *>(n_ContainerView, "build_30007");
  if(l_ButtonMonument)
    n_ButtonMonument = l_ButtonMonument;
  auto l_ButtonPyramidBattle = GBase::getChildByName<ui::Layout *>(n_ContainerView, "build_20008");
  if(l_ButtonPyramidBattle){
    l_ButtonPyramidBattle->setTouchEnabled(true);
    l_ButtonPyramidBattle->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      OtherBuildButtonCallFun(l_ButtonPyramidBattle, p_Ref, p_Touch);
    });
    l_ButtonPyramidBattle->setSwallowTouches(false);
    n_ButtonPyramidBattle = l_ButtonPyramidBattle;
  }
  auto l_ButtonLion =  GBase::getChildByName<ui::Layout *>(n_ContainerView, "Button_lion");
  if(l_ButtonLion){
    l_ButtonLion->setSwallowTouches(false);
    l_ButtonLion->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      OtherBuildButtonCallFun(l_ButtonLion, p_Ref, p_Touch);
    });
    n_ButtonLion = l_ButtonLion;
    auto l_BGLion = GetBufferNodeByName("BG_lion"); 
    GBase::DShowNameOnTouchEven(l_BGLion, GPair<GString, Vec2>::Make(
      Translate::i18n("common_text_4068"),
      Vec2(60, 60)
    ));
    getEventDispatcher()->dispatchCustomEvent("MESSAGE_MAINCITY_LION_MSG");
  }
  auto l_ButtonMaTou = GBase::getChildByName<ui::Layout *>(n_ContainerView, "Button_MaTou");
  if(l_ButtonMaTou){
    l_ButtonMaTou->setTouchEnabled(true);
    l_ButtonMaTou->setSwallowTouches(false);
    l_ButtonMaTou->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      OtherBuildButtonCallFun(l_ButtonMaTou, p_Ref, p_Touch);
    });
    n_ButtonMaTou = l_ButtonMaTou;
    n_ButtonMaTou->setTag(
      GCity::
      Const::
      Get()->Gangkou);
  }
  auto l_ButtonConquer = GBase::getChildByName<ui::Layout *>(n_ContainerView, "Button_conquer");
  if(l_ButtonConquer){
    l_ButtonConquer->setTouchEnabled(true);
    l_ButtonConquer->setSwallowTouches(false);
    l_ButtonConquer->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      OtherBuildButtonCallFun(l_ButtonConquer, p_Ref, p_Touch);
    });
    n_ButtonConquer = l_ButtonConquer;
    n_ButtonConquer->setTag(GCity::Const::Get()->ConquerGate);
  }
  auto l_ButtonBulletInBoard = GBase::getChildByName<ui::Layout *>(n_ContainerView, "Button_bulletin_board");
  if(l_ButtonBulletInBoard){
    l_ButtonBulletInBoard->setTouchEnabled(false);
    l_ButtonBulletInBoard->setSwallowTouches(false);
    l_ButtonBulletInBoard->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
      OtherBuildButtonCallFun(l_ButtonBulletInBoard, p_Ref, p_Touch);
    });
    n_ButtonBulletInBoard = l_ButtonBulletInBoard;
    n_ButtonBulletInBoard->setTag(GCity::Const::Get()->BulletInBoard);
  }
  for(auto i = 30001 ; i <= 30008; i ++){
    auto l_BuildName = StringUtils::format("build_%d", i);
    auto l_BuildButton = GetBufferNodeByName(l_BuildName.c_str());
    if(l_BuildButton){
      l_BuildButton->setSwallowTouches(false);
      l_BuildButton->setTag(i);
      l_BuildButton->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
        BuildButtonCallFun(l_BuildButton, p_Ref, p_Touch);
      });
    }
    if(i == GCity::Const::Get()->LeisureCenter)
      n_ButtonLeisureCenter = l_BuildButton;
    else if(i == GCity::Const::Get()->HuoChuang)
      n_ButtonHuoChuang = l_BuildButton;
    else if(i == GCity::Const::Get()->index_PetCenter)
      n_ButtonPetCenter = l_BuildButton;
    else if(i == GCity::Const::Get()->index_ResurrectionHall)
      n_ButtonResurrectionHall = l_BuildButton;
    else if(i == GCity::Const::Get()->index_ServiceCenter)
      n_ButtonServiceCenter = l_BuildButton;
    else if(i == GCity::Const::Get()->index_EpicBattle)
      n_ButtonEpicBattle = l_BuildButton;
    
  }
  for(auto i = 1200; i <= 1205; i++){
    auto l_BuildName = StringUtils::format("build_%d", i);
    auto l_BuildButton = GetBufferNodeByName(l_BuildName.c_str());
    if(l_BuildButton){
      l_BuildButton->setSwallowTouches(false);
      l_BuildButton->setTag(i);
      l_BuildButton->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
        BuildButtonCallFun(l_BuildButton, p_Ref, p_Touch);
      });
    }
  }
  for(auto i = 1151; i <= 1152; i++){
    auto l_BuildName = StringUtils::format("build_%d", i);
    auto l_BuildButton = GetBufferNodeByName(l_BuildName.c_str());
    if(l_BuildButton){
      l_BuildButton->setSwallowTouches(false);
      l_BuildButton->setTag(i);
      l_BuildButton->addTouchEventListener([=](Ref * p_Ref, ui::Widget::TouchEventType p_Touch){
        BuildButtonCallFun(l_BuildButton, p_Ref, p_Touch);
      });
    }
  }
  auto l_BuildNameHuoChuang = StringUtils::format("build_%d", GCity::Const::Get()->index_HuoChuang);
  n_BtnHuoChuang = GetBufferNodeByName(l_BuildNameHuoChuang.c_str());
  auto l_BuildNamePetCenter = StringUtils::format("build_%d", GCity::Const::Get()->index_PetCenter);
  n_BtnPetCenter = GetBufferNodeByName(l_BuildNamePetCenter.c_str());
}

void MainCityCreate::InitBufferNodeArray(){
  auto l_AllChildren = n_ContainerView->getChildren();
  for(auto i = 0; i < l_AllChildren.size(); i++){
    auto l_Child = l_AllChildren.at(i);
    auto l_ChildName = l_Child->getName();
    AddToBufferNodeArrayByName(l_ChildName.c_str(), l_Child);
  }
  for(auto i = 0; i < 18; i++){
    auto l_bg_hallName = StringUtils::format("BG_hall__%02d_2", i);
    //TODO: Check for type of node on cocos studio
    auto l_bghallItem = dynamic_cast<Sprite *>(GetBufferNodeByName(l_bg_hallName.c_str()));
    if(l_bghallItem){
      auto l_texture = l_bghallItem->getTexture();
      if(l_texture->hasMipmaps()){
        //TODO: Check if the name is right
        Texture2D::TexParams l_texParams ;//= {GL_LINEAR_MIPMAP_NEAREST, GL_LINEAR_MIPMAP_NEAREST, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE};
        l_texParams.magFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
        l_texParams.minFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
        l_texParams.sAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
        l_texParams.tAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
        l_texture->setTexParameters(l_texParams);
      }
      else {
        Texture2D::TexParams l_texParams ;
        l_texParams.magFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
        l_texParams.minFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
        l_texParams.sAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
        l_texParams.tAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
        l_texture->setTexParameters(l_texParams);
      }
    }
  }
  auto l_NewCityBgNode = GetBufferNodeByName("CCS_mainCityViewBG_bg");
  if(l_NewCityBgNode){
    auto l_ArrChild = l_NewCityBgNode->getChildren();
    for(auto i = 0; i < l_ArrChild.size(); i++){
      auto l_OneChild = static_cast<Sprite *>(l_ArrChild.at(i));
      auto l_texture = l_OneChild->getTexture();
        if(l_texture->hasMipmaps()){
        Texture2D::TexParams l_texParams ;//= {GL_LINEAR_MIPMAP_NEAREST, GL_LINEAR_MIPMAP_NEAREST, GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE};
        l_texParams.magFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
        l_texParams.minFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
        l_texParams.sAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
        l_texParams.tAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
        l_texture->setTexParameters(l_texParams);
      }
      else {
        Texture2D::TexParams l_texParams ;
        l_texParams.magFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
        l_texParams.minFilter = backend::SamplerFilter::LINEAR_MIPMAP_NEAREST;
        l_texParams.sAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
        l_texParams.tAddressMode = backend::SamplerAddressMode::CLAMP_TO_EDGE;
        l_texture->setTexParameters(l_texParams);
      }
    }
  }
}

void MainCityCreate::InitAfterCreate(){
  if(m_IsNeedFirstFight){

  }
  // if self.isNeedFirstFight == true then
  //   mainCityCreate.showFirstEnter(self)
  //   return
  // end
  // self:updatePeriod()
  // mainCityCreate.initWithBuildData(self)
  // mainCityCreate.initWithHuoChuangData(self)
  // mainCityCreate.initMatouData(self)
  // self:initCelebrateGift()
  // SoraDSendMessage({
  //   msg = "MESSAGE_MAINCITYVIEW_PYRAMID_BATTLE_MSG"
  // })
  // self:msgUpdateLion()
  // mainCityBuildingMove:init(self)
  // mainCityABMManager:init(self)
}


