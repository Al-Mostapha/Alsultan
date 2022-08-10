#include "UICreateBuildingPanel.h"
#include "cocostudio/CocoStudio.h"
#include "Include/IncludeConfig.h"
#include "Include/IncludeBuildingBase.h"


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
 
  m_LabelDes   = static_cast<Label*>(GBase::getChildByName(panel, "Text_des"));
  m_LabelCount = static_cast<Label*>(GBase::getChildByName(panel,"Text_count"));
  m_LabelNeed  = static_cast<Label*>(GBase::getChildByName(panel,"Text_need"));
  m_LabelName  = static_cast<Label*>(GBase::getChildByName(panel,"Text_name"));
  m_BackGround = static_cast<ui::ImageView *> (GBase::getChildByName(panel,"Image_bbg"));
  m_BtnBuild   = static_cast<ui::Button *>    (GBase::getChildByName(panel,"Button_build"));
  m_NodeLeft   = static_cast<ui::Layout *>    (GBase::getChildByName(panel,"Center_Panel_left"));
  m_NodeRight  = static_cast<ui::Layout *>    (GBase::getChildByName(panel,"Center_Panel_right"));
  m_NodeTop    = static_cast<ui::Layout *>    (GBase::getChildByName(panel,"Top_Panel"));
  m_NodeBottom = static_cast<ui::Layout *>    (GBase::getChildByName(panel,"Bottom_Panel"));
  m_NodeCenter = GBase::getChildByName(panel,"Center_Node");
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

void UICreateBuildingPanel::setBuildingTypeAndData(EBuildingType p_BuildingType, int32 p_BuildingIndex){

}

