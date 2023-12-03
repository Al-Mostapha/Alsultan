#pragma once
#include "Base/BaseTypeDef.h"
#include "Base/Type/XVector.h"
#include "Include/IncludeEngine.h"

class UIWheelScrollView;


class UICreate
{
private:

public:
  static UICreate *Get();
  UIWheelScrollView *DCreateWheelScrollView(
    GVector<Node *>p_ItemArray,  Size p_ViewSize, float p_CellHeight, 
    float p_CircleRadius = 0, float p_PosX = 0, bool p_IsSound = true, bool p_IsIgnoreOpacity = false
  );
};


