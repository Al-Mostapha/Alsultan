#include "UIWheelScrollView.h"
#include "Module/Config/FilePath/MusicPath.Config.h"

UIWheelScrollView *UIWheelScrollView::Create(Size p_Size)
{
  auto l_View  = CreateBaseView(p_Size, false);
  l_View->setAnchorPoint(Vec2(0, 0));
  l_View->setSwallowTouches(false);
  return l_View;
}

void UIWheelScrollView::Ctor(){
  auto l_ViewSize = getContentSize();
  _ScrollView = ui::ScrollView::create();
  _ScrollView->setContentSize(l_ViewSize);
  _ScrollView->setBounceEnabled(true);
  _ScrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
  _ScrollView->setPosition(Vec2(0, 0));
  // self.scrollView:setListenAllScrollingEnabled(true)
  _ScrollView->setEnabled(true);
  addChild(_ScrollView, 1);
  _ScrollView->addEventListener(CC_CALLBACK_2(UIWheelScrollView::ScrollEventCallBack, this));
  _ScrollView->addTouchEventListener(CC_CALLBACK_2(UIWheelScrollView::ScrollTouchEventCallBack, this));
  GBase::DFTarget(_ScrollView);
}

void UIWheelScrollView::setInertiaValue(bool p_Inertia)
{
  _ScrollView->setInertiaScrollEnabled(p_Inertia);
}
void UIWheelScrollView::removeChildren() { _ScrollView->removeAllChildren(); }


void UIWheelScrollView::initData(GVector<Node *> p_Array, float p_PosX, float p_CellHeight, float p_CircleRadius, bool p_IsSound, bool p_IsIgnoreOpacity)
{
  
  _ItemArray = p_Array;
  _CellHeight = p_CellHeight;
  _OffsetPosX = p_PosX;
  _IgnoreOpacity = p_IsIgnoreOpacity;
  _CircleRadius = std::max(p_CircleRadius, _ScrollView->getContentSize().width);
  _TransparentOffset = std::floor(255 / (_ScrollView->getContentSize().height / p_CellHeight)) + 1;
  _IsSound = p_IsSound;
  auto l_ScrollH = _ItemArray.size() * _CellHeight + _ScrollView->getContentSize().height - _CellHeight;
  for(auto iii = 0; iii < _ItemArray.size(); iii++){
    auto l_TransparentPanel = GBase::DGetChildByName<ui::Widget *>(_ItemArray[iii], "Panel_transparent");
    if(l_TransparentPanel)
      l_TransparentPanel->setSwallowTouches(false);
    _ItemArray[iii]->setPosition(Vec2(_OffsetPosX, _CellHeight * iii + 0.5 * _ScrollView->getContentSize().height));
    _ScrollView->addChild(_ItemArray[iii], 1);
    GBase::DFTarget(_ItemArray[iii]);
    _ItemArray[iii]->setTag(iii);
  }
  _ScrollView->setInnerContainerSize(Size(_ScrollView->getContentSize().width, l_ScrollH));
  UpdateItems();
}

void UIWheelScrollView::selectedCellIndex(int p_CellIndex, float p_TimeInSec, bool p_Attenuated, float p_AttenuatedY)
{
  auto l_ScrollInner = _ScrollView->getInnerContainer();
  p_CellIndex = std::min(std::max(1, p_CellIndex), (int)m_WidgetArray.size());
  auto l_OffsetY = m_WidgetArray[p_CellIndex]->getPositionY() - 0.5 * _ScrollView->getContentSize().height + p_AttenuatedY;
  auto l_ScrollPercent = l_OffsetY == 0.0f ? 100.0f : 100.0f * (1 - l_OffsetY / (l_ScrollInner->getContentSize().height - _ScrollView->getContentSize().height));
  if (p_TimeInSec > 0.0f)
  {
    _ScrollView->scrollToPercentVertical(l_ScrollPercent, p_TimeInSec, p_Attenuated);
  }
  else
  {
    _ScrollView->jumpToPercentVertical(l_ScrollPercent);
    UpdateItems();
    pointCurSelectSingle(false);
  }
}

void UIWheelScrollView::ScrollTouchEventCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type)
{
  
  if (p_Type == ui::Widget::TouchEventType::ENDED)
  {
    if (_SingleIsMoved)
    {
      _SingleIsMoved = false;
      return;
    }
    auto l_ScrollInner = _ScrollView->getInnerContainer();
    auto l_OffsetY = -l_ScrollInner->getPositionY();
    auto l_CenterY = l_OffsetY + 0.5 * _ScrollView->getContentSize().height;
    auto l_CurrentIndex = pointCurSelectSingle(true);

    if (l_CurrentIndex > 1 && l_ScrollInner->convertToNodeSpace(
            static_cast<ui::Widget *>(p_Sender)->getTouchBeganPosition()
          ).y <= l_CenterY - 50 * _CellHeight)
    {
      _IsScrollToIndex = -1;
      _ScrollView->setTouchEnabled(false);
      SetTouchDetection(0.3);
    }
    else if (l_CurrentIndex < m_WidgetArray.size() && l_ScrollInner->convertToNodeSpace(
        static_cast<ui::Widget *>(p_Sender)->getTouchBeganPosition()
      ).y >= l_CenterY + 50 * _CellHeight)
    {
      _IsScrollToIndex = 1;
      _ScrollView->setTouchEnabled(false);
      SetTouchDetection(0.3);
    }


    if(_IsScrollToIndex)
    {
      selectedCellIndex(l_CurrentIndex + _IsScrollToIndex, 0.1, true, _IsScrollToIndex * 20);
      _IsScrollToIndex = false;
    }
  }
  else if(p_Type == ui::Widget::TouchEventType::MOVED)
  {
    auto l_TouchBeganPoint = static_cast<ui::Widget *>(p_Sender)->getTouchBeganPosition();
    auto l_TouchmovePoint = static_cast<ui::Widget *>(p_Sender)->getTouchMovePosition();
    auto distance = l_TouchBeganPoint.getDistance(l_TouchmovePoint);
    if(distance > TOUCH_MOVED_ERROR_VALUE)
    {
      _SingleIsMoved = true;
    }
  }
  else if(p_Type == ui::Widget::TouchEventType::CANCELED)
  {
    _SingleIsMoved = false;
  }
}

void UIWheelScrollView::SetTouchDetection(float p_Delay)
{
  runAction(
    Sequence::create(
      DelayTime::create(p_Delay),
      CallFunc::create(
        [this](){
          if (!_ScrollView->isTouchEnabled())
            _ScrollView->setTouchEnabled(true); 
        }),
        nullptr));
}


int UIWheelScrollView::pointCurSelectSingle(bool p_UpdateCurI)
{
  auto l_ScrollInner = _ScrollView->getInnerContainer();
  auto l_OffsetY = -l_ScrollInner->getPositionY();
  auto l_CenterY = l_OffsetY + 0.5 * _ScrollView->getContentSize().height;
  auto l_MinOffsetY = 0.0f;
  Node *l_MinPoint;
  uint32 l_MinI = 1;
  for (uint32 i = 0; i < _ItemArray.size(); i++)
  {
    float l_Y = _ItemArray[i]->getPositionY() - l_CenterY;
    if (std::abs(l_MinOffsetY) > std::abs(l_Y) || i == 1)
    {
      l_MinOffsetY = l_Y;
      l_MinPoint = _ItemArray[i];
      l_MinI = i;
    }
  }
  if (_ItemSelectedListener && _CurrentIndex != l_MinI)
  {
    if (_CurrentIndex != -1 && !p_UpdateCurI && _IsSound)
    {
      GBase::PlaySound(GBase::getSoundPath(MusicConfig::MusicPath::city_click));
    }
    if (!p_UpdateCurI)
    {
      _CurrentIndex = l_MinI;
      _ItemSelectedListener(_CurrentIndex, l_MinPoint);
    }
  }
  return l_MinI;
}

void UIWheelScrollView::bounceSingle(){
  
  auto l_ScrollInner = _ScrollView->getInnerContainer();
  auto l_OffsetY = -l_ScrollInner->getPositionY();
  auto l_CenterY = l_OffsetY + 0.5 * _ScrollView->getContentSize().height;
  auto l_MinOffsetY = 0.0f;
  for(uint32 i = 0; i < _ItemArray.size(); i++)
  {
    float l_Y = _ItemArray[i]->getPositionY() - l_CenterY;
    if (std::abs(l_MinOffsetY) > std::abs(l_Y) || i == 1)
    {
      l_MinOffsetY = l_Y;
    }
  }
  l_OffsetY = l_OffsetY + l_MinOffsetY;
  float l_ScrollPercent = l_OffsetY == 0 ? 100 : 100 * (1 - l_OffsetY / (l_ScrollInner->getContentSize().height - _ScrollView->getContentSize().height));
  if (_IsBounceEnd)
  {
    l_ScrollPercent = l_ScrollPercent <= 50 ? 0 : (l_ScrollPercent > 50 ? 100 : 50);
    _IsBounceEnd = false;
  }
  if(l_ScrollPercent <= 0)
  {
    _ScrollView->scrollToTop(0.2, false);
  }
  else if(l_ScrollPercent >= 100)
  {
    _ScrollView->scrollToBottom(0.2, false);
  }
  else
  {
    _ScrollView->scrollToPercentVertical(l_ScrollPercent, 0.2, true);
  }
  _IsScrollEnd = true;
}

void UIWheelScrollView::UpdateItems()
{
  auto l_ScrollInner = _ScrollView->getInnerContainer();
  auto l_OffsetY = -l_ScrollInner->getPositionY();
  auto l_CenterY = l_OffsetY + 0.5 * _ScrollView->getContentSize().height;
  for (uint32 i = 0; i < _ItemArray.size(); i++)
  {
    auto l_y = std::abs(_ItemArray[i]->getPositionY() - l_CenterY);
    auto l_ItemOpacity = 255 * (1 - l_y / (0.5 * _ScrollView->getContentSize().height));
    if (l_ItemOpacity <= 0)
      l_ItemOpacity = 0;
    else
    {
      auto l_x = std::sqrt(_CircleRadius * _CircleRadius - l_y * l_y);
      l_x = _OffsetPosX + (_CircleRadius - l_x);
      _ItemArray[i]->setPositionX(l_x);
    }
    if (!_IgnoreOpacity)
      _ItemArray[i]->setOpacity(l_ItemOpacity);
    auto l_TransparentPanel = GBase::DGetChildByName<Node *>(_ItemArray[i], "Panel_transparent");
    if (l_TransparentPanel)
    {
      if (!_IgnoreOpacity)
        l_TransparentPanel->setOpacity(l_ItemOpacity);
      auto l_ItemScale = 0.3 * l_ItemOpacity / 255 + 0.7;
      l_TransparentPanel->setScale(l_ItemScale);
    }
  }
}

void UIWheelScrollView::UnfoldAction(float p_delay){

  if(_CurrentIndex == -1)
    return;
  runAction(
    Sequence::create(
      CallFunc::create([this](){
        this->_ScrollView->setTouchEnabled(false);
      }),
      DelayTime::create(p_delay),
      CallFunc::create([this](){
        this->_ScrollView->setTouchEnabled(true);
      }),
      nullptr
    )
  );
  int l_ShowCount = 1;
  GVector<Vec2> l_OldPos;
  for(int i = 0; i < _ItemArray.size(); i++)
  {
    if (i < _CurrentIndex && _ItemArray[i]->getOpacity() > 0)
    {
      l_ShowCount = _CurrentIndex - i;
    }
    else if (i > _CurrentIndex && _ItemArray[i]->getOpacity() > 0)
    {
      l_ShowCount = std::max(i - _CurrentIndex, l_ShowCount);
    }
    _ItemArray[i]->setLocalZOrder(i > _CurrentIndex ? _CurrentIndex - i : i);
    l_OldPos.push_back(_ItemArray[i]->getPosition());
    _ItemArray[i]->setVisible(i == _CurrentIndex || _ItemArray[i]->getOpacity() == 0);
  }
  float l_Delay = p_delay / (l_ShowCount + 1);
  for(int i =0; i < _ItemArray.size(); i++){
    if(_ItemArray[i]->getOpacity() > 0 && i != _CurrentIndex){
      _ItemArray[i]->runAction(
        Sequence::create(
          DelayTime::create(l_Delay * std::abs(i - _CurrentIndex)),
          CallFunc::create([this, i](){
            _ItemArray[i]->setVisible(true);
          }),
          MoveTo::create(l_Delay, _ItemArray[i]->getPosition()),
          nullptr
        )
      );
      if(i > _CurrentIndex){
        _ItemArray[i]->setPosition(l_OldPos[i - 1]);
      }
      else{
        _ItemArray[i]->setPosition(l_OldPos[i + 1]);
      }
    }
    else if(i == _CurrentIndex){
      _ItemArray[i]->setScaleY(0.1);
      _ItemArray[i]->runAction(
        ScaleTo::create(l_Delay, 1)
      );
    }
  }
}






