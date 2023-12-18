#include "UIMailScroll.View.h"
#include "Base/Common/Timer.Mgr.h"
#include "Base/Common/Common.Teml.h"

UIMailScrollView* UIMailScrollView::Create()
{
  auto l_Panel = Create("UiParts/MainUi/Mail/mailScrollView.csb");
  return l_Panel;
}

void UIMailScrollView::Ctor()
{
  UIBaseView::Ctor();
  _ScrollView = GBase::DGetChildByName<ui::ScrollView *>(this, "Size_scrollView");
  _ScrollView->addEventListener(CC_CALLBACK_2(UIMailScrollView::ScrollEventCallBack, this));
  _LabelNotice = GBase::DGetChildByName<ui::Text *>(this, "Text_notice");
  _LabelNotice->setPositionY(13);
  _LabelNotice->setVisible(false);
  _LoadingSprite = GDisplay::Get()->NewSprite("SinglePicture/loading1.png");
  _LoadingSprite->setScale(25 / _LoadingSprite->getContentSize().width);
  _LoadingSprite->setAnchorPoint(Vec2(0.5, 0.5));
  _LoadingSprite->setPositionY(_LabelNotice->getPositionY() + _LabelNotice->getContentSize().height / 2);
  _LoadingSprite->setVisible(false);
  _ScrollView->addChild(_LoadingSprite, 1, "loadingSprite");
  _TimeHandler = GBase::DCreateTimer(this, CC_CALLBACK_1(UIMailScrollView::TurnJumpRedPointBy6Second, this));
}

void UIMailScrollView::InitData()
{

}