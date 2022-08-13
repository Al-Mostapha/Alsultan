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
  GVector<UIBuildCreateScrollSingle *> l_ScrollViews;
  for(EBuildingType l_BuildingType : BuildingStatic::BuildableList){
    UIBuildCreateScrollSingle *l_ScrollSingle = UIBuildCreateScrollSingle::create();
    l_ScrollSingle->initPanel();
    l_ScrollSingle->initData(l_BuildingType);
    l_ScrollViews.push_back(l_ScrollSingle);
  }

  /*

  local curChapterID = newPlayerTaskCtrl:getCurChapterID()
  for i, v in ipairs(self.tableBuildList) do
    if (curbid and curbid == v.bid or v.bid == BUILDID.MILITARY_TENT) and (curbid == BUILDID.MILITARY_TENT or not newPlayerTaskCtrl:isTaskFinish(4103203) and v.bid == BUILDID.MILITARY_TENT and curChapterID == 4103200) then
      self.tableCurIndex = i
      self.selectWheel:selectedCellIndex(self.tableCurIndex)
      mildGuideManager:starMildByNewPlayerQuestID(gNewPLayerTaskType.TO_BUILD_MILITARY_TENT)
    end
  end
  self.itemArray = itemArray*/
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
 // auto l_BuildableList = BuildingStatic::BUildi;
}



