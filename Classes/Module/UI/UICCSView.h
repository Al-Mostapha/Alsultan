#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "UIBaseView.h"

#define CreateUICCSView(__TYPE__)\
static __TYPE__ *Create(GString p_CCSFile, Size p_ViewSize = Size::ZERO)\
{\
  if(p_CCSFile.empty())\
    return nullptr;\
  auto l_View = CSLoader::createNode(p_CCSFile);\
  if(p_ViewSize.height  <=  0 || p_ViewSize.width <= 0)\
    p_ViewSize = l_View->getContentSize();\
  __TYPE__ *l_BaseView = __TYPE__::CreateBaseView(p_ViewSize, false);\
  l_View->setName("ccsView");\
  l_BaseView->addChild(l_View, 1);\
  return l_BaseView;\
}


class UICCSView
{
public :
  static  UIBaseView *Create(GString p_CCSFile = "", Size p_ViewSize = Size::ZERO);
  static  UIBaseView *Create(Node *p_CCSFile = nullptr, Size p_ViewSize = Size::ZERO);
};