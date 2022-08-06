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
  m_LabelDes   = panel->getChildByName<Label*>("Text_des");
  m_LabelCount = panel->getChildByName<Label*>("Text_count");
  m_LabelNeed  = panel->getChildByName<Label*>("Text_need");
  m_LabelName  = panel->getChildByName<Label*>("Text_name");
  m_NodeCenter = panel->getChildByName("Center_Node");
  m_LabelCount->setVisible(false);  
  m_LabelNeed->setVisible(false); 
  m_BackGround = panel->getChildByName<ui::ImageView *>("Image_bbg");
  m_BackGround->setScale9Enabled(false);
  m_BtnBuild = panel->getChildByName<ui::Button *>("Button_build");
  m_BtnBuild->setTitleText(Translate::i18n("common_text_042"));
  m_BtnBuild->addTouchEventListener([this](Ref *pSender, ui::Widget::TouchEventType type){
    if(type == ui::Widget::TouchEventType::ENDED){
      cocos2d::log("UICreateBuildingPanel::initPanel build");
    }
  });
  m_NodeLeft   = panel->getChildByName<ui::Layout *>("Center_Panel_left");
  m_NodeRight  = panel->getChildByName<ui::Layout *>("Center_Panel_right");
  m_NodeTop    = panel->getChildByName<ui::Layout *>("Top_Panel");
  m_NodeBottom = panel->getChildByName<ui::Layout *>("Bottom_Panel");
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

