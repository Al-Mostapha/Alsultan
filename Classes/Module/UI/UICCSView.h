#pragma once 
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "UIBaseView.h"

class UICCSView
{
public :
  static  UIBaseView *Create(GString p_CCSFile = "", Size p_ViewSize = Size::ZERO);
  static  UIBaseView *Create(Node *p_CCSFile = nullptr, Size p_ViewSize = Size::ZERO);
};