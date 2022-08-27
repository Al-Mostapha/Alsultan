#include "UI.Create.h"
#include "Module/UI/Part/UIWheelScrollView.h"
#include "Module/UI/Types/UIWheelScrollViewArgs.h"
#include "../../Include/IncludeEngine.h"

UICreate::UICreate(){
  cocos2d::log("ddddddddddddddddd");
}

UICreate::~UICreate() {
  cocos2d::log("ddddddddddddddddd");
}

UIWheelScrollView *UICreate::wheelScrollView(UIWheelScrollViewArgs& p_WheelScrollViewArgs){
  UIWheelScrollView *l_ScrollView = UIWheelScrollView::create();
  l_ScrollView->initData(p_WheelScrollViewArgs);
  if(!p_WheelScrollViewArgs.m_CircleRadius)
    p_WheelScrollViewArgs.m_CircleRadius = p_WheelScrollViewArgs.m_Size.width;
  return l_ScrollView;
  
}