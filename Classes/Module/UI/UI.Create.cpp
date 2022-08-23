#include "UI.Create.h"
#include "Module/UI/Part/UIWheelScrollView.h"

UIWheelScrollView *UICreate::wheelScrollView(UIWheelScrollViewArgs& p_WheelScrollViewArgs){
  UIWheelScrollView *l_ScrollView = UIWheelScrollView::create();
  l_ScrollView->initData(p_WheelScrollViewArgs);
  if(!p_WheelScrollViewArgs.m_CircleRadius)
    p_WheelScrollViewArgs.m_CircleRadius = p_WheelScrollViewArgs.m_Size.width;
  return l_ScrollView;
  
}