#include "UIWheelScrollView.h"

void UIWheelScrollView::setInertiaValue(bool p_Inertia)
{
  m_ScrollView->setInertiaScrollEnabled(p_Inertia);
}
void UIWheelScrollView::removeChildren() { m_ScrollView->removeAllChildren(); }

UIWheelScrollView::UIWheelScrollView()
{
  m_ScrollView = ui::ScrollView::create();
  
}
UIWheelScrollView::~UIWheelScrollView() {}
bool UIWheelScrollView::init(){
  UIElment::init();
  return true;
}
void UIWheelScrollView::initData(const UIWheelScrollViewArgs& p_WheelScrollViewArgs)
{
  m_ScrollView->setContentSize(p_WheelScrollViewArgs.m_Size);
  m_ScrollView->setBounceEnabled(true);
  m_ScrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
  m_ScrollView->setPosition(Vec2(0, 0));
  // self.scrollView:setListenAllScrollingEnabled(true)
  addChild(m_ScrollView, 1);
  m_ScrollView->addEventListener(CC_CALLBACK_2(UIWheelScrollView::scrollEventCallBack, this));
  m_ScrollView->addTouchEventListener(CC_CALLBACK_2(UIWheelScrollView::scrollTouchEventCallBack, this));


  m_WidgetArray = p_WheelScrollViewArgs.m_WidgetArray;
  m_CellHeight  = p_WheelScrollViewArgs.m_CellHeight;
  m_OffsetPosX  = p_WheelScrollViewArgs.m_OffsetPosX;
  m_IgnoreOpacity = p_WheelScrollViewArgs.m_IgnoreOpacity;
  m_CircleRadius = std::max(p_WheelScrollViewArgs.m_CircleRadius, m_ScrollView->getContentSize().width);
  m_TransparentOffset = std::floor(255 / (m_ScrollView->getContentSize().width / m_CellHeight)) + 1;
  m_IsSound = p_WheelScrollViewArgs.m_IsSound;
  float l_ScrollHeight = m_WidgetArray.size() * m_CellHeight + m_ScrollView->getContentSize().height - m_CellHeight;

  for (uint32 i = 0; i < m_WidgetArray.size(); i++)
  {
    ui::Widget *oneWidget = m_WidgetArray[i];
    ui::Widget *l_TransPanel = GBase::getChildByName<ui::Widget *>(oneWidget, "Panel_transparent");
    if (l_TransPanel)
      l_TransPanel->setSwallowTouches(false);
    oneWidget->setPosition(Vec2(m_OffsetPosX, m_CellHeight * (i - 1) + 0.5 * m_ScrollView->getContentSize().height));
    m_ScrollView->addChild(oneWidget, 1);
    oneWidget->setTag(i);
    // SoraDFTarget(oneWidget)=
  }
  m_ScrollView->setInnerContainerSize(Size(m_ScrollView->getContentSize().width, l_ScrollHeight));
  updateItems();
}

void UIWheelScrollView::selectedCellIndex(int p_CellIndex, float p_TimeInSec, bool p_Attenuated, float p_AttenuatedY)
{
  auto l_ScrollInner = m_ScrollView->getInnerContainer();
  p_CellIndex = std::min(std::max(1, p_CellIndex), (int)m_WidgetArray.size());
  auto l_OffsetY = m_WidgetArray[p_CellIndex]->getPositionY() - 0.5 * m_ScrollView->getContentSize().height + p_AttenuatedY;
  auto l_ScrollPercent = l_OffsetY == 0.0f ? 100.0f : 100.0f * (1 - l_OffsetY / (l_ScrollInner->getContentSize().height - m_ScrollView->getContentSize().height));
  if (p_TimeInSec > 0.0f)
  {
    m_ScrollView->scrollToPercentVertical(l_ScrollPercent, p_TimeInSec, p_Attenuated);
  }
  else
  {
    m_ScrollView->jumpToPercentVertical(l_ScrollPercent);
    updateItems();
    pointCurSelectSingle(false);
  }
}

void UIWheelScrollView::scrollTouchEventCallBack(Ref *p_Sender, ui::Widget::TouchEventType p_Type)
{
  
  if (p_Type == ui::Widget::TouchEventType::ENDED)
  {
    if (m_SingleIsMoved)
    {
      m_SingleIsMoved = false;
      return;
    }
    auto l_ScrollInner = m_ScrollView->getInnerContainer();
    auto l_OffsetY = -l_ScrollInner->getPositionY();
    auto l_CenterY = l_OffsetY + 0.5 * m_ScrollView->getContentSize().height;
    auto l_CurrentIndex = pointCurSelectSingle(true);

    if (l_CurrentIndex > 1 && l_ScrollInner->convertToNodeSpace(
            static_cast<ui::Widget *>(p_Sender)->getTouchBeganPosition()
          ).y <= l_CenterY - 50 * m_CellHeight)
    {
      m_IsScrollToIndex = -1;
      m_ScrollView->setTouchEnabled(false);
      setTouchDetection(0.3);
    }
    else if (l_CurrentIndex < m_WidgetArray.size() && l_ScrollInner->convertToNodeSpace(
        static_cast<ui::Widget *>(p_Sender)->getTouchBeganPosition()
      ).y >= l_CenterY + 50 * m_CellHeight)
    {
      m_IsScrollToIndex = 1;
      m_ScrollView->setTouchEnabled(false);
      setTouchDetection(0.3);
    }


    if(m_IsScrollToIndex)
    {
      selectedCellIndex(l_CurrentIndex + m_IsScrollToIndex, 0.1, true, m_IsScrollToIndex * 20);
      m_IsScrollToIndex = false;
    }
  }
  else if(p_Type == ui::Widget::TouchEventType::MOVED)
  {
    auto l_TouchBeganPoint = static_cast<ui::Widget *>(p_Sender)->getTouchBeganPosition();
    auto l_TouchmovePoint = static_cast<ui::Widget *>(p_Sender)->getTouchMovePosition();
    auto distance = l_TouchBeganPoint.getDistance(l_TouchmovePoint);
    if(distance > TOUCH_MOVED_ERROR_VALUE)
    {
      m_SingleIsMoved = true;
    }
  }
  else if(p_Type == ui::Widget::TouchEventType::CANCELED)
  {
    m_SingleIsMoved = false;
  }
}

void UIWheelScrollView::setTouchDetection(float p_Delay)
{
  runAction(
    Sequence::create(
      DelayTime::create(p_Delay),
      CallFunc::create(
        [this](){
          if (!m_ScrollView->isTouchEnabled())
            m_ScrollView->setTouchEnabled(true); 
        }),
        nullptr));
}

/*function wheelScrollView:scrollEventCallBack(target, event)
  self:updateItems()
  if event == ccui.ScrollviewEventType.scrollingEnd then
   
  end
end*/

void UIWheelScrollView::scrollEventCallBack(Ref *p_Sender, ui::ScrollView::EventType p_Type)
{
  this->updateItems();
  if (p_Type == ui::ScrollView::EventType::SCROLLING_ENDED)
  {
    if (m_IsScrollEnd)
    {
      m_IsScrollEnd = false;
      pointCurSelectSingle(false);
      if (!m_ScrollView->isTouchEnabled())
        m_ScrollView->setTouchEnabled(true);
    }
    else
    {
      bounceSingle();
      if (!m_ScrollView->isTouchEnabled())
        m_ScrollView->setTouchEnabled(true);
    }
  }
}


int UIWheelScrollView::pointCurSelectSingle(bool p_UpdateCurI)
{
  auto l_ScrollInner = m_ScrollView->getInnerContainer();
  auto l_OffsetY = -l_ScrollInner->getPositionY();
  auto l_CenterY = l_OffsetY + 0.5 * m_ScrollView->getContentSize().height;
  auto l_MinOffsetY = 0.0f;
  ui::Widget *l_MinPoint;
  uint32 l_MinI = 1;
  for (uint32 i = 0; i < m_WidgetArray.size(); i++)
  {
    float l_Y = m_WidgetArray[i]->getPositionY() - l_CenterY;
    if (std::abs(l_MinOffsetY) > std::abs(l_Y) || i == 1)
    {
      l_MinOffsetY = l_Y;
      l_MinPoint = m_WidgetArray[i];
      l_MinI = i;
    }
  }
  if (m_SelectedItemListener && m_CurrentIndex != l_MinI)
  {
    if (m_CurrentIndex != -1 && !p_UpdateCurI && m_IsSound)
    {
      GBase::playSound(GBase::getSoundPath(MusicConfig::MusicPath::city_click));
    }
    if (!p_UpdateCurI)
    {
      m_CurrentIndex = l_MinI;
      // m_ItemSelectedListener ;
    }
  }

  return l_MinI;
}



void UIWheelScrollView::bounceSingle(){
  
  auto l_ScrollInner = m_ScrollView->getInnerContainer();
  auto l_OffsetY = -l_ScrollInner->getPositionY();
  auto l_CenterY = l_OffsetY + 0.5 * m_ScrollView->getContentSize().height;
  auto l_MinOffsetY = 0.0f;
  for(uint32 i = 0; i < m_WidgetArray.size(); i++)
  {
    float l_Y = m_WidgetArray[i]->getPositionY() - l_CenterY;
    if (std::abs(l_MinOffsetY) > std::abs(l_Y) || i == 1)
    {
      l_MinOffsetY = l_Y;
    }
  }
  l_OffsetY = l_OffsetY + l_MinOffsetY;
  float l_ScrollPercent = l_OffsetY == 0 ? 100 : 100 * (1 - l_OffsetY / (l_ScrollInner->getContentSize().height - m_ScrollView->getContentSize().height));
  if (m_IsBounceEnd)
  {
    l_ScrollPercent = l_ScrollPercent <= 50 ? 0 : (l_ScrollPercent > 50 ? 100 : 50);
    m_IsBounceEnd = false;
  }
  if(l_ScrollPercent <= 0)
  {
    m_ScrollView->scrollToTop(0.2, false);
  }
  else if(l_ScrollPercent >= 100)
  {
    m_ScrollView->scrollToBottom(0.2, false);
  }
  else
  {
    m_ScrollView->scrollToPercentVertical(l_ScrollPercent, 0.2, true);
  }
  m_IsScrollEnd = true;
}

void UIWheelScrollView::updateItems()
{
  auto l_ScrollInner = m_ScrollView->getInnerContainer();
  auto l_OffsetY = -l_ScrollInner->getPositionY();
  auto l_CenterY = l_OffsetY + 0.5 * m_ScrollView->getContentSize().height;
  for (uint32 i = 0; i < m_WidgetArray.size(); i++)
  {
    auto l_y = std::abs(m_WidgetArray[i]->getPositionY() - l_CenterY);
    auto l_ItemOpacity = 255 * (1 - l_y / (0.5 * m_ScrollView->getContentSize().height));
    if (l_ItemOpacity <= 0)
      l_ItemOpacity = 0;
    else
    {
      auto l_x = std::sqrt(m_CircleRadius * m_CircleRadius - l_y * l_y);
      l_x = m_OffsetPosX + (m_CircleRadius - l_x);
      m_WidgetArray[i]->setPositionX(l_x);
    }
    if (!m_IgnoreOpacity)
      m_WidgetArray[i]->setOpacity(l_ItemOpacity);
    auto l_TransparentPanel = GBase::getChildByName<Node *>(m_WidgetArray[i], "Panel_transparent");
    if (l_TransparentPanel)
    {
      if (!m_IgnoreOpacity)
        l_TransparentPanel->setOpacity(l_ItemOpacity);
      auto l_ItemScale = 0.3 * l_ItemOpacity / 255 + 0.7;
      l_TransparentPanel->setScale(l_ItemScale);
    }
  }
}

void UIWheelScrollView::unfoldAction(float p_delay){

  if(m_CurrentIndex == -123456789)
    return;
  runAction(
    Sequence::create(
      CallFunc::create([this](){
        this->m_ScrollView->setTouchEnabled(false);
      }),
      DelayTime::create(p_delay),
      CallFunc::create([this](){
        this->m_ScrollView->setTouchEnabled(true);
      }),
      nullptr
    )
  );
  int l_ShowCount = 1;
  GVector<Vec2> l_OldPos;
  for(int i = 0; i < m_WidgetArray.size(); i++)
  {
    if (i < m_CurrentIndex && m_WidgetArray[i]->getOpacity() > 0)
    {
      l_ShowCount = m_CurrentIndex - i;
    }
    else if (i > m_CurrentIndex && m_WidgetArray[i]->getOpacity() > 0)
    {
      l_ShowCount = std::max(i - m_CurrentIndex, l_ShowCount);
    }
    m_WidgetArray[i]->setLocalZOrder(i > m_CurrentIndex ? m_CurrentIndex - i : i);
    l_OldPos.push_back(m_WidgetArray[i]->getPosition());
    m_WidgetArray[i]->setVisible(i == m_CurrentIndex || m_WidgetArray[i]->getOpacity() == 0);
  }
  float l_Delay = p_delay / (l_ShowCount + 1);
  for(int i =0; i < m_WidgetArray.size(); i++){
    if(m_WidgetArray[i]->getOpacity() > 0 && i != m_CurrentIndex){
      m_WidgetArray[i]->runAction(
        Sequence::create(
          DelayTime::create(l_Delay * std::abs(i - m_CurrentIndex)),
          CallFunc::create([this, i](){
            m_WidgetArray[i]->setVisible(true);
          }),
          MoveTo::create(l_Delay, m_WidgetArray[i]->getPosition()),
          nullptr
        )
      );
      if(i > m_CurrentIndex){
        m_WidgetArray[i]->setPosition(l_OldPos[i - 1]);
      }
      else{
        m_WidgetArray[i]->setPosition(l_OldPos[i + 1]);
      }
    }
    else if(i == m_CurrentIndex){
      m_WidgetArray[i]->setScaleY(0.1);
      m_WidgetArray[i]->runAction(
        ScaleTo::create(l_Delay, 1)
      );
    }
  }
}

