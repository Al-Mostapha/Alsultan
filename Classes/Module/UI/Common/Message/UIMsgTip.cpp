#include "UIMsgTip.h"
#include "Base/Common/Common.Teml.h"

void UIMsgTip::InitPanel(){

  Node *panel = CSLoader::createNode(CsbUiFilePath::UIMsgTipPanel);
  if(!panel){
    cocos2d::log("UIMsgTipPanel::InitPanel error No find %s", CsbUiFilePath::UIMsgTipPanel.c_str());
    return;
  }
  m_ViewName  = "commonPromptTip";
  m_MaxHeight = 80.0f;
  m_ImageIconBg = GBase::DGetChildByName<Sprite *>(panel, "Image_IconBg");
  m_TextMessage = GBase::DGetChildByName<ui::Text *>(panel, "Text_message");
  m_ImageBgL = GBase::DGetChildByName<ui::ImageView *>(panel, "Image_bg_1");
  m_ImageBgR = GBase::DGetChildByName<ui::ImageView *>(panel, "Image_bg_1");
  if(m_ImageIconBg)
    m_ImageIconBg->setVisible(false);
  _Panel->addChild(panel, 1);
  addChild(_Panel);
  //_Panel = panel;
}

void UIMsgTip::ShowTip( GString p_Message, Node *p_Icon ){

  CCAssert(_Panel, "No Panel set");
  if(!_Panel){
    Logger::Log("UIMsgTip Panel Not Found", ELogLvl::Error, true);
    return;
  }

  _Panel->setScaleY(0.1f);
  m_MaxHeight = 120;

  float l_ShowY = GDisplay::Get()->cy + 40.0f;
  if(p_Icon){
    auto l_Offest = Vec2(0, 0);
    m_ImageIconBg->setVisible(true);
    auto l_IconBgSize = m_ImageIconBg->getContentSize();
    p_Icon->setAnchorPoint(Vec2(0.5, 0.5));
    p_Icon->setPosition(l_IconBgSize.width / 2 + l_Offest.x, l_IconBgSize.height / 2 + l_Offest.y);
    m_ImageIconBg->addChild(p_Icon, 1);
    m_MaxHeight = 80;
  }
  m_TextMessage->setString(p_Message);
  float l_Height = GBase::DGetAutoHeightLabel(m_TextMessage, 450.0f);
  m_TextMessage->setTextVerticalAlignment(TextVAlignment::CENTER);
  float l_DeltaHeight = 0;
  if(l_Height +20 > 50 && l_Height <= m_MaxHeight){
    l_DeltaHeight = l_Height + 20 - 50;
    addHeight(l_DeltaHeight);
  }else if(l_Height > m_MaxHeight){
    l_Height = m_MaxHeight;
    GBase::DSetTextWidthHeight(m_TextMessage, Size(450, l_Height));
    m_TextMessage->setTextVerticalAlignment(TextVAlignment::CENTER);
    l_DeltaHeight = l_Height - 50;
    addHeight(l_DeltaHeight);
  }
  _Panel->runAction(
    Sequence::create(
      ScaleTo::create(0.3, 1, 1, 1),
      DelayTime::create(2.8),
      ScaleTo::create(0.2, 1, 0.1, 1),
      CallFunc::create([this](){
        this->_Panel->removeFromParentAndCleanup(true);
      }),
      nullptr
    )
  );
  _Panel->setPositionY(l_ShowY);
}

void UIMsgTip::addHeight(float p_DeltaHeight){
  m_ImageBgL->setContentSize(Size(m_ImageBgL->getContentSize().width, m_ImageBgL->getContentSize().height + p_DeltaHeight + 4));
  m_ImageBgR->setContentSize(Size(m_ImageBgR->getContentSize().width, m_ImageBgR->getContentSize().height + p_DeltaHeight + 4));
  m_DeltaHeight = p_DeltaHeight;
}

UIMsgTip *UIMsgTip::Create(){
  return create();
}

void UIMsgTip::Show(){
  auto l_Order = 0;
  Scene *l_Scene = Director::getInstance()->getRunningScene();
  auto l_PrePromptTip = l_Scene->getChildByName(m_ViewName);
  auto l_PreOrder = l_PrePromptTip ? l_PrePromptTip->getLocalZOrder() : 0;
  if(l_PrePromptTip){
    auto l_Height = 100;//l_PrePromptTip->getViewHeight();
    auto l_PosY = l_PrePromptTip->getPositionY() + l_Height + 5;
    if(l_PosY > GDisplay::Get()->cy + 230)
      return;
    _Panel->setPositionY(l_PosY);
    l_PrePromptTip->setName(m_ViewName + "prefix");
  }else{
    l_PrePromptTip->removeAllChildrenWithCleanup(true);
  }
  setName(m_ViewName);
  l_Scene->addChild(this, 200);
}