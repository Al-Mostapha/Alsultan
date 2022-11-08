#include "UIBuildCreateScrollSingle.h"
#include "cocostudio/CocoStudio.h"
#include "Include/IncludeConfig.h"
#include "Include/IncludeBuildingFunc.h"


UIBuildCreateScrollSingle::UIBuildCreateScrollSingle(){
  
}

UIBuildCreateScrollSingle::~UIBuildCreateScrollSingle(){

}

void UIBuildCreateScrollSingle::InitPanel(){
  Node *panel = CSLoader::createNode(CsbUiFilePath::UIBuildCreateScrollSingle);
  if(!panel){
    cocos2d::log("UIBuildCreateScrollSingle::initPanel error No find %s", CsbUiFilePath::UIBuildCreateScrollSingle.c_str());
    return;
  }

  m_LabelName = GBase::GetChildByName<Label *>(panel, "Text_name");
  m_ImgLock = GBase::GetChildByName<ui::ImageView *>(panel, "Image_lock");
  m_ImgLock->setLocalZOrder(1);
  m_ImgIcon = nullptr;
  m_ShowPanel = GBase::GetChildByName<ui::Layout *>(panel, "Panel_transparent");
  m_ShowPanel->setSwallowTouches(false);
  addChild(panel);
}


void UIBuildCreateScrollSingle::initData(EBuilding p_BuildingType){
  if(m_ImgIcon){
    m_ImgIcon->removeFromParent();
    m_ImgIcon = nullptr;
  }
  RBuildingSpecs l_BuildingInfoUnit = BuildingStatic::getBuildingSpecs(p_BuildingType);
  m_LabelName->setString(Translate::i18n(l_BuildingInfoUnit.BuildingName.c_str()));
  if(!BuildingLib::isCanBuild(p_BuildingType))
    m_ImgLock->setVisible(false);
  else
    m_ImgLock->setVisible(true);
  m_ImgIcon = Sprite::createWithSpriteFrameName(l_BuildingInfoUnit.BuildingIcon.c_str());
  m_ImgIcon->setPosition(Vec2(170, 61));
  m_ImgIcon->setScale(110 / m_ImgIcon->getContentSize().width);
  m_ShowPanel->addChild(m_ImgIcon);
}
