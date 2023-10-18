#include "UIBuildCreateScrollSingle.h"
#include "cocostudio/CocoStudio.h"
#include "Include/IncludeConfig.h"
#include "Include/IncludeBuildingFunc.h"
#include "Base/Common/Common.Teml.h"


UIBuildCreateScrollSingle *UIBuildCreateScrollSingle::Create(){
  return Create(CsbUiFilePath::UIBuildCreateScrollSingle);
}


void UIBuildCreateScrollSingle::Ctor(){

  m_LabelName = GBase::DGetChildByName<ui::Text *>(this, "Text_name");
  m_ImgLock = GBase::DGetChildByName<ui::ImageView *>(this, "Image_lock");
  m_ImgLock->setLocalZOrder(1);
  m_ImgIcon = nullptr;
  m_ShowPanel = GBase::DGetChildByName<ui::Layout *>(this, "Panel_transparent");
  m_ShowPanel->setSwallowTouches(false);
}


void UIBuildCreateScrollSingle::initData(EBuilding p_BuildingType){
  if(m_ImgIcon){
    m_ImgIcon->removeFromParent();
    m_ImgIcon = nullptr;
  }
  RBuildingSpecs l_BuildingInfoUnit = BuildingStatic::getBuildingSpecs(p_BuildingType);
  m_LabelName->setString(Translate::i18n(l_BuildingInfoUnit.BuildingName));
  if(!BuildingLib::isCanBuild(p_BuildingType))
    m_ImgLock->setVisible(false);
  else
    m_ImgLock->setVisible(true);
  m_ImgIcon = Sprite::createWithSpriteFrameName(l_BuildingInfoUnit.BuildingIcon);
  m_ImgIcon->setPosition(Vec2(170, 61));
  m_ImgIcon->setScale(110 / m_ImgIcon->getContentSize().width);
  m_ShowPanel->addChild(m_ImgIcon);
}
