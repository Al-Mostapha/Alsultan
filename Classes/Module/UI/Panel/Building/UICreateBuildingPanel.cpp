#include "UICreateBuildingPanel.h"
#include "cocostudio/CocoStudio.h"
#include "Include/IncludeConfig.h"
#include "Include/IncludeBuildingBase.h"
#include "Module/UI/Panel/Building/UIBuildCreateScrollSingle.h"


UICreateBuildingPanel::UICreateBuildingPanel(){
  
}

UICreateBuildingPanel::~UICreateBuildingPanel(){

}

void UICreateBuildingPanel::initPanel(){
  Node *panel = CSLoader::createNode(CsbUiFilePath::UIPanelCreatBuilding);
  if(!panel){
    cocos2d::log("UICreateBuildingPanel::initPanel error No find %s", CsbUiFilePath::UIPanelCreatBuilding.c_str());
    return;
  }
 
  m_LabelDes   = GBase::getChildByName<Label*>(panel, "Text_des");
  m_LabelCount = GBase::getChildByName<Label*>(panel,"Text_count");
  m_LabelNeed  = GBase::getChildByName<Label*>(panel,"Text_need");
  m_LabelName  = GBase::getChildByName<Label*>(panel,"Text_name");
  m_BackGround = GBase::getChildByName<ui::ImageView *>(panel,"Image_bbg");
  m_BtnBuild   = GBase::getChildByName<ui::Button *>(panel,"Button_build");
  m_NodeLeft   = GBase::getChildByName<ui::Layout *>(panel,"Center_Panel_left");
  m_NodeRight  = GBase::getChildByName<ui::Layout *>(panel,"Center_Panel_right");
  m_NodeTop    = GBase::getChildByName<ui::Layout *>(panel,"Top_Panel");
  m_NodeBottom = GBase::getChildByName<ui::Layout *>(panel,"Bottom_Panel");
  m_NodeCenter = GBase::getChildByName<Node *>(panel,"Center_Node");
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

void UICreateBuildingPanel::createWheelScrollView(){
  /*

  if #itemArray <= 0 then
    return
  end
  if self.selectWheel then
    self.selectWheel:removeFromParent()
    self.selectWheel = nil
  end
  self.selectWheel = SoraDCreateWheelScrollView(itemArray, cc.size(500, math.max(600, display.height - 270)), 130, 450)
  if self.selectWheel then
    self.selectWheel:setItemSelectedListener(function(index)
      self:wheelScrollBack(self.tableBuildList[index], index)
    end)
    self.nodeCenter:addChild(self.selectWheel, 0)
    self.selectWheel:setPosition(cc.p(0, math.min(-165, 270 - self.nodeCenter:getPositionY())))
    self.selectWheel:selectedCellIndex(math.min(self.tableCurIndex, #itemArray))
    self.selectWheel:setInertiaValue(0.1)
    SoraDFTarget(self.selectWheel)
  end
  local curChapterID = newPlayerTaskCtrl:getCurChapterID()
  for i, v in ipairs(self.tableBuildList) do
    if (curbid and curbid == v.bid or v.bid == BUILDID.MILITARY_TENT) and (curbid == BUILDID.MILITARY_TENT or not newPlayerTaskCtrl:isTaskFinish(4103203) and v.bid == BUILDID.MILITARY_TENT and curChapterID == 4103200) then
      self.tableCurIndex = i
      self.selectWheel:selectedCellIndex(self.tableCurIndex)
      mildGuideManager:starMildByNewPlayerQuestID(gNewPLayerTaskType.TO_BUILD_MILITARY_TENT)
    end
  end
  self.itemArray = itemArray*/
  /* for i, v in ipairs(self.tableBuildList) do
    local item = SoraDCreatePanel("buildCreateScrollSingle")
    item:initData(v)
    table.insert(itemArray, item)
    if curbid and curbid == v.bid then
      self.tableCurIndex = i
      if curbid == BUILDID.MILITARY_TENT then
        local guideCtrl = gametop.playertop_:getModule("guideCtrl")
        if guideCtrl:isGuideNotCompleted(gGuideModule.BUILD_BUILDING) then
        end
      end
    end
  end*/
 
  GVector<UIBuildCreateScrollSingle *> l_ScrollViews;
  for(auto l_BuildingUnit : m_BuildableList){
    UIBuildCreateScrollSingle *l_ScrollSingle = UIBuildCreateScrollSingle::create();
    l_ScrollSingle->initPanel();
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

    
  // self.selectWheel = SoraDCreateWheelScrollView(itemArray, cc.size(500, math.max(600, display.height - 270)), 130, 450)
  // if self.selectWheel then
  //   self.selectWheel:setItemSelectedListener(function(index)
  //     self:wheelScrollBack(self.tableBuildList[index], index)
  //   end)
  //   self.nodeCenter:addChild(self.selectWheel, 0)
  //   self.selectWheel:setPosition(cc.p(0, math.min(-165, 270 - self.nodeCenter:getPositionY())))
  //   self.selectWheel:selectedCellIndex(math.min(self.tableCurIndex, #itemArray))
  //   self.selectWheel:setInertiaValue(0.1)
  //   SoraDFTarget(self.selectWheel)
  // end
 // m_SelectWheel = 
}

void UICreateBuildingPanel::setBuildingTypeAndData(EBuildingType p_BuildingType, int32 p_BuildingIndex){
  m_BuildableList = BuildingLib::getCanBuildList(p_BuildingType);

 /*if self.selectWheel == nil then
    self:createWheelScrollView()
    self.selectWheel:setVisible(false)
    self:runAction(cca.seq({
      cca.callFunc(function(...)
        self.btnBuild:setScale(0.1)
        self.nodeLeft:runAction(cca.fadeIn(0.5))
        self.nodeRight:runAction(cca.fadeIn(0.5))
        self.nodeTop:runAction(cca.fadeIn(0.5))
        self.nodeBottom:runAction(cca.fadeIn(0.5))
        self.labelDes:runAction(cca.fadeIn(0.5))
        self.labelCount:runAction(cca.fadeIn(0.5))
        self.labelNeed:runAction(cca.fadeIn(0.5))
        self.btnBuild:runAction(cca.seq({
          cca.scaleTo(0.3, 1.2),
          cca.scaleTo(0.1, 1)
        }))
      end),
      cca.delay(0.4),
      cca.callFunc(function(...)
        self.selectWheel:unfoldAction(0.5)
        self.selectWheel:setVisible(true)
      end),
      cca.delay(0.6),
      cca.callFunc(function(...)
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
      end)
    }))
  end*/
}



