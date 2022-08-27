#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Module/UI/UIElment.h"


class UIWheelScrollView;
class UIWheelScrollViewArgs;

class UICreate
{
private:
  /* data */
public:
  UICreate();
  ~UICreate();
  static UIWheelScrollView *wheelScrollView(UIWheelScrollViewArgs& p_WheelScrollViewArgs);
};


