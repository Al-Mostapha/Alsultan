#pragma once
#include "Include/IncludeBase.h"
#include "Include/IncludeEngine.h"
#include "Module/UI/UIElment.h"
#include "Module/UI/Types/UIWheelScrollViewArgs.h"

class UICreate
{
private:
  /* data */
public:
  UICreate(/* args */);
  ~UICreate();
  static class UIWheelScrollView *wheelScrollView(UIWheelScrollViewArgs& p_WheelScrollViewArgs);
};


