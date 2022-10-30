#include "CityScene.Create.h"
#include "CityScene.Move.h"
#include "CityScene.ABMManager.h"
#include "Module/City/City.Ctrl.h"
#include "Module/Building/IBuilding.h"
#include "Module/City/CityBuilding/CityBuildingSpritePool.h"
#include "Module/City/CityBuilding/CityBuilding.Mgr.h"
#include "Module/City/City.Func.h"
#include "Module/City/CitySceneEffect.h"
#include "Module/Player/LordInfo.Ctrl.h"
#include "Module/Building/BuildingLib/Wall.Ctrl.h"


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
    ShowFirstEnter();
    return;
  }
  UpdatePeriod();
  InitWithBuildData();
  InitWithHuoChuangData();
  InitMatouData();
  InitCelebrateGift();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_PYRAMID_BATTLE_MSG");
  MsgUpdateLion();
  MainCityBuildingMove::Get()->Init(this);
  MainCityABMManager::Get()->Init(this);
}

void MainCityCreate::ShowFirstEnter(){
  // userSDKManager.logEvent(gSDKDef.TDonEvent.game_cg_play_complete, {})
  // local self = mainCity
  // self:hideAllRamadanEffectNode()
  // for i = 1, 4 do
  //   local cqName = "Sprite_Cq_" .. i
  //   local spriteCqItem = self:getBufferNodeByName(cqName)
  //   if spriteCqItem then
  //     spriteCqItem:setVisible(false)
  //   end
  // end
  // local spriteJiantachengduoR = self:getBufferNodeByName("Sprite_Jiantachengduo_R")
  // local spriteJiantachengduoL = self:getBufferNodeByName("Sprite_Jiantachengduo_L")
  // if spriteJiantachengduoR then
  //   spriteJiantachengduoR:setVisible(false)
  // end
  // if spriteJiantachengduoL then
  //   spriteJiantachengduoL:setVisible(false)
  // end
  // self.isSkipClick = false
  // local lang = SoraDGetDefaultLanguage()
  // local btnRes = SoraDGetImageNameByLang("res/video/icon_xsyd_%s.png", {"ar", "en"})
  // local csbNode = display.getRunningScene()
  // local data = {
  //   videoFile = "cg/gameCG.mp4",
  //   onCompleteFun = function(_video)
  //     if self.isSkipClick then
  //       userSDKManager.logEvent(gSDKDef.TDonEvent.game_cg_play_complete, {jump = 3021010})
  //     end
  //     SoraDGetCtrl("guideCtrl"):setSkipFirstFight(true)
  //     SoraDSendMessage({
  //       msg = "MESSAGE_SERVER_GUIDE_STEP_END",
  //       step = 1007
  //     })
  //     SoraDSendMessage({
  //       msg = "MESSAGE_MAINCITYVIEW_FIRST_FIGHT_END"
  //     })
  //   end,
  //   onPanelClick = function(_video)
  //     if not _video.isAddBtn then
  //       _video:addSkipButton(" ", false, btnRes, true)
  //     end
  //   end,
  //   onStopfunc = function(_video)
  //     print("==onStopfunc==")
  //   end,
  //   onSkipfunc = function(_video)
  //     self.isSkipClick = true
  //   end,
  //   needRemove = true,
  //   displaySize = cc.size(640, 1386)
  // }
  // local videoPlayer = SoraDCreateVideoPlayerSingle(data)
  // if videoPlayer then
  //   videoPlayer:play()
  //   videoPlayer:setContentSize(cc.size(640, 1386))
  //   do
  //     local lang = SoraDGetDefaultLanguage()
  //     local btnRes = SoraDGetImageNameByLang("res/video/icon_xsyd_%s.png", {"ar", "en"})
  //     SoraDCallOnNextFrame(videoPlayer, function()
  //       if not videoPlayer.isAddBtn then
  //         videoPlayer:addSkipButton(" ", false, btnRes, true)
  //       end
  //     end, 0.5)
  //   end
  // end
}

void MainCityCreate::UpdatePeriod(){

}


void MainCityCreate::InitWithHuoChuangData(){
  // local self = mainCity
  // local isCanReceive = loginRewardCtrl:getCanReceive()
  // if isCanReceive then
  //   self:addBuildEffect(cityBuildConstDef.OtherBuildDef.HuoChuang)
  // else
  //   self:removeBuildEffect(cityBuildConstDef.OtherBuildDef.HuoChuang)
  // end
  // effectMainCityView.addBuildTopTipHuochuang(self)
}

void MainCityCreate::InitMatouData(){
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

void MainCityCreate::CreateInnerCityBuilds(){
  auto l_BuildList = CityCtrl::Get()->GetBuildList();
  for (auto l_Build : l_BuildList){
    if(!l_Build)
      continue;
    if(l_Build->GetBuildingIndex() == EBuildingIndex::ArrowTowerL ||
        l_Build->GetBuildingIndex() == EBuildingIndex::WallGate ||
        l_Build->GetBuildingIndex() == EBuildingIndex::ArrowTowerR ||
        l_Build->GetBuildingIndex() == EBuildingIndex::WatchTower)
      continue;
    auto l_BuildingIndex = static_cast<int32>(l_Build->GetBuildingIndex());
    if(l_BuildingIndex >= 1100)
      continue;
    auto l_CellIndexName = StringUtils::format("build_%d", l_BuildingIndex);
    auto l_BuildBtn = GetBufferNodeByName(l_CellIndexName.c_str());
    if(!l_BuildBtn)
      continue;
      // The Building is Inserted on node wich called "buildName"
    auto l_BuildEntity = l_BuildBtn->getChildByName<IBuilding *>("buildName");
    if(!l_BuildEntity)
      AddBuild(l_Build->GetBuildingIndex(), l_Build->GetBuildingId());
    else{
      l_BuildBtn->setCascadeOpacityEnabled(false);
      l_BuildBtn->setOpacity(0);
      l_BuildEntity->InitWithBuildCell(l_Build);
    }
  }
  CreateOuterCityBuilds();
}

void MainCityCreate::CreateOuterCityBuilds(){
  auto l_BuildList = CityCtrl::Get()->GetBuildList();
  for (auto l_Build : l_BuildList){
    if(!l_Build)
      continue;
    auto l_BuildingIndex = static_cast<int32>(l_Build->GetBuildingIndex());
    if(l_BuildingIndex < 1100)
      continue;
    auto l_CellIndexName = StringUtils::format("build_%d", l_BuildingIndex);
    auto l_BuildBtn = GetBufferNodeByName(l_CellIndexName.c_str());
    if(!l_BuildBtn)
      continue;
      // The Building is Inserted on node wich called "buildName"
    auto l_BuildEntity = l_BuildBtn->getChildByName<IBuilding *>("buildName");
    if(!l_BuildEntity)
      AddBuild(l_Build->GetBuildingIndex(), l_Build->GetBuildingId());
    else{
      l_BuildBtn->setCascadeOpacityEnabled(false);
      l_BuildBtn->setOpacity(0);
      l_BuildEntity->InitWithBuildCell(l_Build);
    }
  }
  CityBuildingMgr::Get()->InitWithData(this);
  auto l_Delay = DelayTime::create(0.016666666666666666f);
  auto l_CallFunc = CallFunc::create([this](){
    this->DelayInitWithBuildData();
  });
  runAction(Sequence::create(l_Delay, l_CallFunc, nullptr));
  // effectMainCityView.addHarvestEffect(self)
}

void MainCityCreate::DelayInitWithBuildData(){
  // local self = mainCity
  // userSDKManager.timeInfo.t_maincity.tend = SoraDGetSocketTime()
  // userSDKManager.timeInfo.t_maincityp.tbegin = SoraDGetSocketTime()

  // mainCityFunctions.updateLockArea(self)
  MainCityFunctions::Get()->UpdateLockArea(this);
  UpdateBuildTiles();

  // if SoraDIsGameGuide() == nil then
  //   self:autoUpdateViewScrollViewPos()
  //   self:setZoomScale(self.defaultScale, false)
  if(!GBase::DIsGameGuide()){
    AutoUpdateViewScrollViewPos();
    SetZoomScale(m_DefaultScale, false);
    //   guideCtrl:updateNewGuide()
    //   if SoraDGetCastleLv() >= CASTLE_LV3_LIMITED and not guideCtrl:updateGuideModule(gGuideModule.OVERVIEW) and not SoraDCurrentTopPanelFromManager() then
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
    AutoUpdateViewScrollViewPos();
    SetZoomScale(m_DefaultScale, false);
  }
  LoadSoldiers();
  m_TimeHandler = GBase::DCreateTimer(this, std::bind(&MainCityView::UpdateTime, this, std::placeholders::_1));
  m_TimeHandlerPerFrame = GBase::DCreateTimer(this, std::bind(&MainCityView::UpdateTimePerFrame, this, std::placeholders::_1));
  UpdateTimePerFrame(Director::getInstance()->getDeltaTime());
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_WALL_VIEW");
  auto l_Build = GetBufferNodeByName("build_" + static_cast<int32>(EBuildingIndex::WallGate));
  if(l_Build){
    auto l_BuildEntity = l_Build->getChildByName<IBuilding *>("buildName");
    if(l_BuildEntity){
     // auto l_ViewModelWall = l_BuildEntity->GetViewModel();
     GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_TURRET_OFFSET", l_BuildEntity);
    }
      
  }
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_WALL_EFFECT");
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_HOSPTIAL_VIEW");
  GBase::DSendMessage("MESSAGE_QUEST_NOTICE_RECOMMEND_UPDATE");
  CitySceneEffect::showEagle();

  // cityHorseCtrl:sendInit()

  InitPlayerLevelOffLine();
  if(GBase::DIsGameGuide()){
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
    //         print("cityBuildFunction:checkPopUpWindow \229\188\130\229\184\184\228\186\134\239\188\140\232\175\183\229\164\132\231\144\134-------@ct")
    //       end
    //     end
    //   end
  }else{
    SetMainCityEnabled(true);
  }
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_BUILD_TIP_BOX");
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_MERCHANT_VIEW");
  GBase::DSendMessage("MESSAGE_WALLS_NOTIFY_SUCCESS");
  if(WallCtrl::Get()->IsDestruction())
    GBase::DSendMessage("MESSAGE_WALLS_DEFENCE_DESTROY");
  if(m_IsLogin){
    auto l_ActDelay = DelayTime::create(0.15);
    std::unique_ptr<bool> l_IsHiddle(new bool(false));
    auto l_CallFunc = CallFunc::create([&](){
      GBase::DSendMessage("MESSAGE_MAIN_UI_HIDDLE", l_IsHiddle.get());
    });
    auto l_Seq = Sequence::create(l_ActDelay, l_CallFunc, nullptr);
    runAction(l_Seq);
  }
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_CLOSE_FIRST_FIGHT");
  if(GBase::DGetFactionType() == EFactionType::Normal){
    auto l_BuildFirst = GetBufferNodeByName("city_First_build_castle");
    if(l_BuildFirst)
      l_BuildFirst->setVisible(false);
  }
  CitySceneEffect::addWaveEffect();
  CitySceneEffect::addSoldierGuard();
  CitySceneEffect::addHarborWorker();
  CitySceneEffect::addActivityCentetNpc();
  CitySceneEffect::addCastleGateNpc();
  CitySceneEffect::showXiyiAnimation();
  CitySceneEffect::addConquerGateAnimation();
  GBase::DSendMessage("MESSAGE_SERVER_UPDATE_IDLE_GUIDE");
  RefreshCastleSkin(true);
  CheckCastleGift();
  CheckEndlessTreasure();
  CheckAllianceTreasure();
  CheckFriend();
  CheckEpicWar();
  CheckPromoteArmy();
  CheckMastery();
  InitVisibleArea();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_PET_SHOW");
  // userSDKManager.timeInfo.t_maincityp.tend = SoraDGetSocketTime()
  // userSDKManager.timeInfo.t_total.tend = SoraDGetSocketTime()
  if(GBase::DIsGameGuide()){
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

void MainCityCreate::CheckCastleGift(){
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

void MainCityCreate::CheckEndlessTreasure(){
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_ADD_ENDLESSTREASURE_TOP_TIP");
}

void MainCityCreate::CheckAllianceTreasure(){
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_ADD_WAREHOUSE_GIFT_TOP_TIP");
}

void MainCityCreate::CheckFriend(){
  GBase::DSendMessage("MESSAGE_SERVER_FRIEND_UPDATE_TIP");
}

void MainCityCreate::CheckEpicWar(){
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_ADD_EPICWAR_TOP_TIP");
}

void MainCityCreate::CheckPromoteArmy(){
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_ADD_PROMOTE_TOP_TIP");
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_FLAG_COOLING_PANEL");
}

void MainCityCreate::CheckMastery(){
  if(!GBase::Const::Get()->IsArClient){
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_MASTERY_VIEW");
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_MASTERY_COOLING_PANEL");
    GBase::DSendMessage("MESSAGE_UPDATE_MASTERY_TOP_TIP");
  }
}

bool MainCityCreate::InitPlayerLevelOffLine(){
  // local self = mainCity
  GBase::DSendMessage("MESSAGE_MAIN_AGREEMENT_BOX");
  auto l_IsShow = false;
  auto l_IsPop = LordInfoCtrl::Get()->GetLordUpgradePopStatus();
  if (l_IsPop ) {
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
  if(CityCtrl::Get()->GetCastleUpgradePopStatus()){
    GBase::DSendMessage("MESSAGE_MAINCITYVIEW_CASTLE_LEVELUP");
    l_IsShow = true;
  }
  return l_IsShow;
}

void MainCityCreate::InitWithBuildData(){
  auto l_ATLeft     = CityCtrl::Get()->GetBuildingCellByIndex(EBuildingIndex::ArrowTowerL);
  auto l_Gate       = CityCtrl::Get()->GetBuildingCellByIndex(EBuildingIndex::WallGate);
  auto l_ATRight    = CityCtrl::Get()->GetBuildingCellByIndex(EBuildingIndex::ArrowTowerR);
  auto l_WatchTower = CityCtrl::Get()->GetBuildingCellByIndex(EBuildingIndex::WatchTower);
  AddBuild(l_ATLeft->GetBuildingIndex(), l_ATLeft->GetBuildingId());
  AddBuild(l_Gate->GetBuildingIndex(), l_Gate->GetBuildingId());
  AddBuild(l_ATRight->GetBuildingIndex(), l_ATRight->GetBuildingId());
  AddBuild(l_WatchTower->GetBuildingIndex(), l_WatchTower->GetBuildingId());
  // effectMainCityView.updateCommunityView(self)
  // effectMainCityView.updateStarBraveStatueView(self)
  CityBuildingSpritePool::Get()->Init();
  GBase::DSendMessage("MESSAGE_MAINCITYVIEW_UPDATE_WALL_EFFECT");
  SetMainCityEnabled(false);
  auto l_ActDelay = DelayTime::create(0.1f);
  auto l_CallFunc = CallFunc::create([this](){
    this->CreateInnerCityBuilds();
  });
  runAction(Sequence::create(l_ActDelay, l_CallFunc, nullptr));
}
