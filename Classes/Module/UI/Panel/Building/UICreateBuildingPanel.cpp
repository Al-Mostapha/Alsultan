#include "UICreateBuildingPanel.h"
#include "cocostudio/CocoStudio.h"
#include "Include/IncludeConfig.h"
#include "Include/IncludeBuildingFunc.h"
#include "Module/UI/Panel/Building/UIBuildCreateScrollSingle.h"
#include "Module/UI/Part/UIWheelScrollView.h"
#include "Module/UI/UI.Create.h"
#include "Base/Base.Geometry.h"
#include "Base/Common/Common.Teml.h"


UICreateBuildingPanel::UICreateBuildingPanel(){
  
}

UICreateBuildingPanel::~UICreateBuildingPanel(){

}

void UICreateBuildingPanel::InitPanel(){
  Node *panel = CSLoader::createNode(CsbUiFilePath::UIPanelCreatBuilding);
  if(!panel){
    cocos2d::log("UICreateBuildingPanel::initPanel error No find %s", CsbUiFilePath::UIPanelCreatBuilding.c_str());
    return;
  }
  
  m_LabelDes   = GBase::DGetChildByName<Label*>(panel, "Text_des");
  m_LabelCount = GBase::DGetChildByName<Label*>(panel,"Text_count");
  m_LabelNeed  = GBase::DGetChildByName<Label*>(panel,"Text_need");
  m_LabelName  = GBase::DGetChildByName<Label*>(panel,"Text_name");
  m_BackGround = GBase::DGetChildByName<ui::ImageView *>(panel,"Image_bbg");
  m_BtnBuild   = GBase::DGetChildByName<ui::Button *>(panel,"Button_build");
  m_NodeLeft   = GBase::DGetChildByName<ui::Layout *>(panel,"Center_Panel_left");
  m_NodeRight  = GBase::DGetChildByName<ui::Layout *>(panel,"Center_Panel_right");
  m_NodeTop    = GBase::DGetChildByName<ui::Layout *>(panel,"Top_Panel");
  m_NodeBottom = GBase::DGetChildByName<ui::Layout *>(panel,"Bottom_Panel");
  m_NodeCenter = GBase::DGetChildByName<Node *>(panel,"Center_Node");
  m_LabelCount->setVisible(false);  
  m_LabelNeed->setVisible(false); 
  
  m_BackGround->setScale9Enabled(false);
  
  m_BtnBuild->setTitleText(Translate::i18n("common_text_042"));
  m_BtnBuild->addTouchEventListener([this](Ref *pSender, ui::Widget::TouchEventType type){
    if(type == ui::Widget::TouchEventType::ENDED){
      cocos2d::log("UICreateBuildingPanel::initPanel build");
    }
  });

  m_NodeTop->setContentSize(Size(640, Director::getInstance()->getVisibleSize().height - (m_NodeLeft->getPositionY() + 0.5 * m_NodeLeft->getContentSize().height)));
  m_NodeBottom->setContentSize(Size(640, m_NodeLeft->getPositionY() - 0.5 * m_NodeLeft->getContentSize().height));
  m_NodeLeft->setOpacity(0);
  m_NodeRight->setOpacity(0);
  m_NodeTop->setOpacity(0);
  m_NodeBottom->setOpacity(0);
  m_LabelDes->setOpacity(0);
  m_LabelCount->setOpacity(0);
  m_LabelNeed->setOpacity(0);
  addChild(panel);
}

void UICreateBuildingPanel::SetBuildingTypeAndData(EBuilding p_BuildingType, int32 p_BuildingIndex){
  m_BuildableList = BuildingLib::getCanBuildList(p_BuildingType);
  if(m_SelectWheel == nullptr){
    CreateWheelScrollView();
    m_SelectWheel->setVisible(false);
    runAction(
      Sequence::create(
        CallFunc::create( [this](){
          this->m_BtnBuild->setScale(0.1);
          this->m_NodeLeft->runAction( FadeIn::create(0.5));
          this->m_NodeRight->runAction(FadeIn::create(0.5));
          this->m_NodeTop->runAction(FadeIn::create(0.5));
          this->m_NodeBottom->runAction(FadeIn::create(0.5));
          this->m_LabelDes->runAction(FadeIn::create(0.5));
          this->m_LabelCount->runAction(FadeIn::create(0.5));
          this->m_LabelNeed->runAction(FadeIn::create(0.5));
          this->m_BtnBuild->runAction(Sequence::create(
            ScaleTo::create(0.3, 1.2),
            ScaleTo::create(0.1, 1.0),
            nullptr
          ));
        }),
        DelayTime::create(0.4),
        CallFunc::create([this](){
          this->m_SelectWheel->UnfoldAction(0.5);
          this->m_SelectWheel->setVisible(true);
        }),
        DelayTime::create(0.6),
        // this is Guid
        /**cca.callFunc(function(...)
            local guideStep = SoraDIsGameGuide()
            if guideStep then
              if guideStep == 2003 then
                print("\232\181\176\230\150\176\230\137\139\229\188\149\229\175\188\230\173\165\233\170\164 \229\187\186\231\173\145\229\187\186\233\128\160")
                SoraDSendMessage({
                  msg = "MESSAGE_SERVER_GUIDE_STEP_ON",
                  step = 2004
                })
              elseif guideStep == 2013 then
                SoraDSendMessage({
                  msg = "MESSAGE_SERVER_GUIDE_STEP_ON",
                  step = 2014
                })
              end
            end
            if GLOBAL_BUILD_PRE_BID then
              self:selectWheelByBid(GLOBAL_BUILD_PRE_BID)
              GLOBAL_BUILD_PRE_BID = nil
            end
          end)*/
        nullptr
      )// Sequance::Create
    ); // runAction
  }
}

// createButtonCallFun

void UICreateBuildingPanel::UpdateView(){

  m_LabelDes->setString(Translate::i18n(m_CurrentBuilding.BuildingBrief));
  m_LabelCount->setVisible(m_CurrentBuilding.bType == 1);
  m_LabelNeed->setVisible(!m_CurrentBuilding.isCanBuild);
  m_LabelName->setString(Translate::i18n(m_CurrentBuilding.BuildingName));
  m_BtnBuild->setTouchEnabled(m_CurrentBuilding.isCanBuild);
  m_BtnBuild->setBright(m_CurrentBuilding.isCanBuild);

  bool l_ISCanBuild  = BuildingLib::isCanBuild(m_CurrentBuilding.buildingType);
  if(!m_CurrentBuilding.isCanBuild){
    m_LabelNeed->setString("");
  }

  auto l_IsCanBuild = BuildingLogic::Get()->IsCanBuild(m_CurrentBuilding.buildingType);
  m_CostBuildingUpgrade = l_IsCanBuild.Second;

  if(!m_CurrentBuilding.isCanBuild){
    m_LabelNeed->setString(Translate::i18n("common_text_763", {
      {"name", BuildingStatic::getBuildingSpecs(m_CostBuildingUpgrade._CostBuilding[0].TypeReq).BuildingName},
      {"lvl",  std::to_string(m_CostBuildingUpgrade._CostBuilding[0].lvlReq)},
    }));
  }

  if(m_CurrentBuilding.bType == 1){
    m_LabelCount->setString(Translate::i18n("common_text_739", {
      {"cur", std::to_string(BuildingCtrl::Get()->getBuildingCount(m_CurrentBuilding.buildingType))},
      {"max",  std::to_string(m_CurrentBuilding.maxCount)},
    }));
  }

  if(m_CurrentBuilding.index == 0)
    return;
  auto l_Index = m_CurrentBuilding.index;
  auto l_BuildingType = m_CurrentBuilding.buildingType;
/*
  SoraDSendMessage({
    msg = "MESSAGE_MAINCITYVIEW_ADD_BUILD_PREVIEW",
    index = index,
    bid = bid
  })*/
}

void UICreateBuildingPanel::WheelScrollBack(const RBuildingSpecs& p_BuildingInfoUnit, size_t p_Index){
  m_CurrentIndex = p_Index;
  m_CurrentBuilding = p_BuildingInfoUnit;
  UpdateView();
}

void UICreateBuildingPanel::SelectWheelByBuildingType(EBuilding p_BuildingType){
  if(!m_SelectWheel)
    return;
  
  auto l_CurIndex = 1;
  for(int l_I = 0; l_I < m_BuildableList.size(); l_I++){
    if(p_BuildingType == m_BuildableList[l_I].buildingType){
      l_CurIndex = l_I;
    }
  }
  m_SelectWheel->selectedCellIndex(l_CurIndex);
  m_CurrentBuilding = m_BuildableList[l_CurIndex];
  m_CurrentIndex = l_CurIndex;
}

void UICreateBuildingPanel::CreateWheelScrollView(){

  GVector<UIBuildCreateScrollSingle *> l_ScrollViews;
  for(auto l_BuildingUnit : m_BuildableList){
    UIBuildCreateScrollSingle *l_ScrollSingle = UIBuildCreateScrollSingle::create();
    l_ScrollSingle->InitPanel();
    l_ScrollSingle->initData(l_BuildingUnit.buildingType);
    l_ScrollViews.push_back(l_ScrollSingle);
  }
  if(l_ScrollViews.size() <= 0){
    return;
  }
  if(m_SelectWheel){
    m_SelectWheel->removeFromParent();
    m_SelectWheel = nullptr;
  }
  UIWheelScrollViewArgs l_WheelScrollViewArgs;
  l_WheelScrollViewArgs.m_WidgetArray = *(GVector<ui::Widget *> *) &l_ScrollViews; 
  auto l_Size = Size(500, std::max(600.0f, Director::getInstance()->getVisibleSize().height - 270));
  l_WheelScrollViewArgs.m_CellHeight = 130;
  l_WheelScrollViewArgs.m_CircleRadius = 450;
  m_SelectWheel =  UICreate::Get()->DCreateWheelScrollView(
    *(GVector<Node *> *) &l_ScrollViews, l_Size, 130.f, 450.f
  );
  if(m_SelectWheel){
    m_SelectWheel->SetItemSelectedListener([this](size_t p_Index, Node *p_Node){
      WheelScrollBack(m_BuildableList[p_Index], p_Index);
    });

    m_NodeCenter->addChild(m_SelectWheel, 0);
    m_SelectWheel->setPosition(Vec2(0, std::min(-165.0f, 270.0f - m_NodeCenter->getPosition().y)));
    m_SelectWheel->selectedCellIndex(std::min(m_CurrentIndex, (int)l_ScrollViews.size()));
    m_SelectWheel->setInertiaValue(0.1);
    GBase::DFTarget(m_SelectWheel);
  }
  /*  This is Guide */
  // local curChapterID = newPlayerTaskCtrl:getCurChapterID()
  // for i, v in ipairs(self.tableBuildList) do
  //   if (curbid and curbid == v.bid or v.bid == BUILDID.MILITARY_TENT) and (curbid == BUILDID.MILITARY_TENT or not newPlayerTaskCtrl:isTaskFinish(4103203) and v.bid == BUILDID.MILITARY_TENT and curChapterID == 4103200) then
  //     self.tableCurIndex = i
  //     self.selectWheel:selectedCellIndex(self.tableCurIndex)
  //     mildGuideManager:starMildByNewPlayerQuestID(gNewPLayerTaskType.TO_BUILD_MILITARY_TENT)
  //   end
  // end

}

void UICreateBuildingPanel::ClickEffect(Node *p_Target){
  auto l_PartNode = BaseCreate::createParticle("et_dianji_display.plist", Vec2(), Vec2(), 0.0f);
  l_PartNode->setName("particle_click_node");
  l_PartNode->setPosition(p_Target->getContentSize().width / 2 -30, p_Target->getContentSize().height / 2 - 30);
  p_Target->addChild(l_PartNode, -1);
}

void UICreateBuildingPanel::CreateWheelAction(){

  auto l_GuideNode = m_NodeCenter->getChildByName("wheelGuideEffectNode");
  if(!l_GuideNode)
    return;
  auto l_SpriteHand =l_GuideNode->getChildByName("spriteHand");
  if(!l_SpriteHand)
    return;
  /*if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(185, 345, -10) then
    end
    if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(185, 205, -10) then
    end
    if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(180, 135, -10) then
    end*/
  auto l_HandAction = Sequence::create(
    CallFunc::create([&](){
      /*if not (self.tableCurBuild.bid <= BUILDID.SAWMILL) or not SoraDFPoint(265, 395, -10) then
        end*/
      l_SpriteHand->setVisible(true);
      //spriteHand:setPosition((SoraDFPoint(180, 135, -10)))
      l_SpriteHand->setPosition(180, 135);
    }),
    FadeIn::create(0.2f),
    ScaleTo::create(0.2, 1.2),
    ScaleTo::create(0.2, 1.0),
    DelayTime::create(0.5),
    BezierTo::create(1.0, {
      GBase::DFPoint(185, 205, -10),
      GBase::DFPoint(185, 345, -10),
      GBase::DFPoint(265, 395, -10)
    }),
    DelayTime::create(0.5),
    FadeOut::create(0.5),
    CallFunc::create([&](){
      l_SpriteHand->setVisible(false);
    }),
    DelayTime::create(0.5),
    CallFunc::create([this](){
      this->CreateWheelAction();
    }),
    nullptr
  );
  l_SpriteHand->runAction(l_HandAction);
}